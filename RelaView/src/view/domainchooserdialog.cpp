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

#include "domainchooserdialog.h"
#include "ui_domainchooserdialog.h"

#include "mainwindow.h"
#include "datamanager.h"
#include "domaindata.h"

#include <QDebug>
#include <QMessageBox>
#include <QSettings>
#include <QDir>
#include <QFile>
#include <QFileDialog>

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
DomainChooserDialog::DomainChooserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DomainChooserDialog)
{
    ui->setupUi(this);
    this->initialise();
}

DomainChooserDialog::~DomainChooserDialog()
{
    delete ui;
}

//#---------------------------------------------------------------------------#
//#------- STATIC PUBLIC -----------------------------------------------------#
//#---------------------------------------------------------------------------#
void DomainChooserDialog::performUserChoice(MainWindow* w)
{
    DomainChooserDialog chooser(w);
    chooser.setWindowModality(Qt::WindowModal);

    if (chooser.exec() == QDialog::Rejected)
        return;

    QList<DomainData*> domainsToSave;


    for (int i = 0; i < chooser.ui->listWidget->count(); i++){
        QListWidgetItem* item = chooser.ui->listWidget->item(i);

        if (item->checkState() == Qt::Checked){
            DomainData* domain = DataManager::domainForString(item->text());
            if (domain != 0)
                domainsToSave.append(domain);
        }
    }

    if (domainsToSave.isEmpty())
        return;
    else
        chooser.saveDomains(domainsToSave, w);
}


//#---------------------------------------------------------------------------#
//#------- VIRTUAL PUBLIC SLOTS ----------------------------------------------#
//#---------------------------------------------------------------------------#
void DomainChooserDialog::accept()
{
    bool accept = false;

    for (int i = 0; i < ui->listWidget->count(); i++){
        QListWidgetItem* item = ui->listWidget->item(i);
        if (item->checkState() == Qt::Checked){
            accept = true;
            break;
        }
    }

    if (accept){
        QDialog::accept();
    }else{
        QMessageBox msg(this);
        msg.setWindowModality(Qt::WindowModal);
        msg.setText(tr("No domain selected!"));
        msg.setIcon(QMessageBox::Warning);
        msg.setInformativeText(tr("Please select at least one domain from the list."));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();

    }
}


//#---------------------------------------------------------------------------#
//#------- PRIVATE SLOTS -----------------------------------------------------#
//#---------------------------------------------------------------------------#
void DomainChooserDialog::setAllWidgetsChecked(bool b)
{
    QListWidgetItem* item;
    for (int i = 0; i < ui->listWidget->count(); i++){
        item = ui->listWidget->item(i);
        if (b)
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);
    }
}

//#---------------------------------------------------------------------------#
//#------- PRIVATE -----------------------------------------------------------#
//#---------------------------------------------------------------------------#
void DomainChooserDialog::initialise()
{
    connect(ui->checkAll, SIGNAL(toggled(bool)), this, SLOT(setAllWidgetsChecked(bool)));

    QList<DomainData*>& domains = DataManager::domains();

    for (int i = 0; i < domains.size(); i++){
        QListWidgetItem* qlwi;
        qlwi = new QListWidgetItem(domains.at(i)->name(), ui->listWidget);
        qlwi->setFlags((qlwi->flags()|Qt::ItemIsUserCheckable));
        qlwi->setCheckState(Qt::Unchecked);
    }
}

void DomainChooserDialog::saveDomains(QList<DomainData*>& list, MainWindow *w)
{
    QSettings settings;
    QString savePath = settings.value("MainWindow/lastSavePath", QDir::homePath()).toString();
    QString filepath = QFileDialog::getSaveFileName(this,
                                                    tr("Save Domain(s)..."),
                                                    savePath,
                                                    tr("Files (*.rfc)"));

    if (filepath.isEmpty())
        return;

    QFile file(filepath);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox msg(this);
        msg.setWindowModality(Qt::WindowModal);
        msg.setText(tr("Warning"));
        msg.setIcon(QMessageBox::Warning);
        msg.setInformativeText(tr("Error while exporting domains:\n%1.").arg(file.errorString()));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();

        file.close();
        return;
    }


    //generate domain(s)
    QString domains;
    QString makeVisibile;
    for (int j = 0; j < list.size(); j++){
        QString domainElements;
        unsigned int domainCount = list.at(j)->count();
        for (unsigned int i = 0; i < domainCount-1; i++){
            domainElements.append(QString("%1, ").arg(list.at(j)->element(i)));
        }
        domainElements.append(QString("%1").arg(list.at(j)->element(domainCount-1)));

        domains.append(QString("DOMAIN %1 AS {%2};\n").
                arg(list.at(j)->name()).
                arg(domainElements));

        makeVisibile.append(QString("%1;\n").arg(list.at(j)->name()));
    }


    QTextStream output(&file);
    output << domains << "\n" << makeVisibile;

    w->statusBarMessage(tr("File saved"));

    //save last save path to settings
    QDir dir(filepath);
    settings.setValue("MainWindow/lastSavePath", dir.absolutePath());
}
