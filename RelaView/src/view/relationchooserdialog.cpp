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

#include "relationchooserdialog.h"
#include "ui_relationchooserdialog.h"

#include "relationdata.h"
#include "mainwindow.h"
#include "datamanager.h"

#include <QListIterator>

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
RelationChooserDialog::RelationChooserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RelationChooserDialog)
{
    ui->setupUi(this);
    connect(ui->checkAll, SIGNAL(toggled(bool)),
            this, SLOT(setAllWidgetsChecked(bool)));
}

RelationChooserDialog::~RelationChooserDialog()
{
    delete ui;
}


//#---------------------------------------------------------------------------#
//#------- STATIC PUBLIC -----------------------------------------------------#
//#---------------------------------------------------------------------------#
void RelationChooserDialog::performUserChoice(MainWindow* window)
{

    //Don't open Dialog if there is only one relation in the loaded file
    if (DataManager::loadingList().count() < 2){
        return;
    }

    RelationChooserDialog rcd(window);
    rcd.setWindowModality(Qt::WindowModal);

    rcd.setupChooser();

    if (rcd.exec() == QDialog::Rejected){
        while (!DataManager::loadingList().isEmpty())
            delete DataManager::loadingList().takeFirst();
        return;
    }

    rcd.clearUnselectedRelations();
}


//#---------------------------------------------------------------------------#
//#------- PRIVATE SLOTS -----------------------------------------------------#
//#---------------------------------------------------------------------------#
void RelationChooserDialog::setAllWidgetsChecked(bool b)
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
void RelationChooserDialog::setupChooser()
{
    QListIterator<RelationData*> iterator(DataManager::loadingList());
    while (iterator.hasNext()){
        QString name = iterator.next()->name();
        generateWidgetItem(name);
    }
}




//removes the items that are not checked from the list
//and delete them
void RelationChooserDialog::clearUnselectedRelations()
{
    QListWidgetItem* item;
    RelationData* data;

    for (int i = 0; i < ui->listWidget->count(); i++){
        item = ui->listWidget->item(i);
        if (item->checkState() == Qt::Unchecked){

            qDebug("relation %s is unchecked", item->text().toStdString().c_str());
            QListIterator<RelationData*> iterator(DataManager::loadingList());
            while (iterator.hasNext()){
                data = iterator.next();
                if (item->text() == data->name()){
                    if (DataManager::loadingList().removeOne(data)){
                        qDebug("remove relation:%s from list",
                               data->name().toStdString().c_str());
                        delete data;
                        data = 0;
                    }
                }

            }
        }

    }
}



void RelationChooserDialog::generateWidgetItem(QString& name)
{
    QListWidgetItem* qlwi;
    qlwi = new QListWidgetItem(name, ui->listWidget);
    qlwi->setFlags((qlwi->flags()|Qt::ItemIsUserCheckable));
    qlwi->setCheckState(Qt::Unchecked);
}
