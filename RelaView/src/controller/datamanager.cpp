/*
 * Copyright (C) 2012 Andreas Schmitz.
 *
 * This file is part of RelaView.
 *
 * RelaView is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RelaView is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with RelaView; see the file COPYING.LESSER. If not,
 * see <http://www.gnu.org/licenses/>.
 *
 * This Software uses the LGPL version Qt Library 4.8.1, and performs
 * operations by dynamically linking to the Qt library.
 * You can obtain the Qt library from <http://qt.nokia.com>.
 */

#include "datamanager.h"

#include "relationchooserdialog.h"
#include "domaindata.h"
#include "mainwindow.h"
#include "relationdata.h"
#include "errorlogwidget.h"

extern "C"
{
#include "fileloader.h"
}

#include <QApplication>
#include <QString>
#include <QStringList>
#include <QProgressDialog>
#include <QMessageBox>
#include <QSpacerItem>
#include <QGridLayout>
#include <QErrorMessage>

//#---------------------------------------------------------------------------#
//#------- STATIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
void DataManager::openRelaFixFiles(MainWindow *window, const QStringList* files)
{
    Q_CHECK_PTR(files);
    Q_CHECK_PTR(window);

    if (files->isEmpty())
        return;


    QApplication::setOverrideCursor(Qt::WaitCursor);
    QProgressDialog dialog(QObject::tr("Parsing RelaFix Code"),
                           QObject::tr("Abort"), 0, files->count(), window);
    dialog.setWindowModality(Qt::WindowModal);

    for (int i = 0; i < files->count(); i++){
        QString s = files->at(i);
        //Filecheck
        /*
        QUrl url(s);
        if (!url.isLocalFile()){
            qDebug("Url is no file");
            files->removeOne(s);
            continue;
        }*/

        //set actual progress state
        dialog.setValue(i);
        if (dialog.wasCanceled()) {
            //delete all relations and return
            while (!DataManager::loadingList().isEmpty())
                delete DataManager::loadingList().takeFirst();
            QApplication::restoreOverrideCursor();
            return;
        }
        if (parseFile(2, s.toStdString().c_str())){
           //Error handling here
           return;
        }
    }

    dialog.setValue(files->count());
    QApplication::restoreOverrideCursor();

    //Show RelaFix error messages
    DataManager::showErrors();

    //relation chooser
    RelationChooserDialog::performUserChoice(window);

    //From here on there are only relations in the list
    //which where selected by the user
    int windowCount = 1;
    while (!DataManager::loadingList().isEmpty()){
        RelationData* relData = DataManager::loadingList().takeFirst();
        if (window->isUntitled()){
            window->setRelation(relData);
        }else{
            MainWindow::newWindowWithRelation(relData);
            windowCount++;
        }
    }

}



/**
 */
void DataManager::openRelaFixFile(MainWindow* window, const QString& filename)
{
    QStringList list;
    list.append(filename);
    DataManager::openRelaFixFiles(window, &list);
}


void DataManager::appendError(const QString &s)
{
    DataManager::errors().append(s);
}


DomainData* DataManager::domainForString(const QString &s)
{
    QList<DomainData*> domains = DataManager::domains();
    for (int i = 0; i < domains.size(); i++){
        if (domains.at(i)->name() == s)
            return domains.at(i);
    }

    return 0;
}


void DataManager::showErrors()
{
    if (DataManager::errors().isEmpty())
        return;

    QString err = "";
    QStringList& errList = DataManager::errors();
    QListIterator<QString> iter(errList);

    while (iter.hasNext())
        err.append(iter.next());

    DataManager::errors().clear();

    QStringList splitList = err.split("\n");

    while (!splitList.isEmpty()){
        QString tmp = splitList.takeFirst();
        if (!tmp.isEmpty())
            ErrorLogWidget::instance().addMessage("RelaFix error: " + tmp);
    }
}


//#---------------------------------------------------------------------------#
//#------- EXTERN "C" FUNCTIONS ----------------------------------------------#
//#---------------------------------------------------------------------------#
void createRelation(RF_RELATION* c_relation)
{
    QList<RelationData*>& rel = DataManager::loadingList();
    RelationData* relation = new RelationData(c_relation);

    QString name = relation->name();
    int i = 0;
    int j = 1;
    while (i < rel.count()){
        if (relation->name() == rel.at(i)->name()){
            relation->setName(QString(name+ "%1").arg(j));
            i = 0;
            j++;
        }else{
            i++;
        }
    }
    DataManager::loadingList().append(relation);

    createDomain(c_relation->domain_1);
    createDomain(c_relation->domain_2);
}



void createDomain(RF_DOMAIN *c_domain)
{
    //Add domains to list
    DomainData* domain = new DomainData(c_domain);
    QList<DomainData* >& dom = DataManager::domains();

    bool error = false;
    for (int i = 0; i < dom.size(); i++)
        if (*dom.at(i) == *domain)
            error = true;

    if (!error)
        dom.append(domain);
    else
        delete domain;

}


void appendError(char* str)
{
    DataManager::appendError(str);
}
