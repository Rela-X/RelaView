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

#include "binaryoperationdialog.h"
#include "ui_binaryoperationdialog.h"

#include "relationdata.h"
#include "mainwindow.h"

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
BinaryOperationDialog::BinaryOperationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BinaryOperationDialog)
{
    ui->setupUi(this);
    this->initialise();
}

BinaryOperationDialog::~BinaryOperationDialog()
{
    delete ui;
}



//#---------------------------------------------------------------------------#
//#------- PUBLIC STATIC -----------------------------------------------------#
//#---------------------------------------------------------------------------#
const RelationData* BinaryOperationDialog::performOperationWith(MainWindow* window)
{
    BinaryOperationDialog bin(window);
    bin.setWindowModality(Qt::WindowModal);

    if (bin.exec() != QDialog::Accepted)
        return 0;


    QList<MainWindow*>& windows = MainWindow::windows();


    foreach (MainWindow* w, windows){
        if (w->isRelationData()){
            if (bin.ui->comboBox->currentText() == w->relation()->name())
                return w->relation();
        }else{
            continue;
        }
    }
    return 0;

}



//#---------------------------------------------------------------------------#
//#------- PRIVATE -----------------------------------------------------------#
//#---------------------------------------------------------------------------#
void BinaryOperationDialog::initialise()
{
    QList<MainWindow*>& windows = MainWindow::windows();

    foreach (MainWindow* w, windows){
        if (w->isRelationData())
            ui->comboBox->addItem(w->relation()->name());
    }
}
