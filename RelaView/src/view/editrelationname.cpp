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

#include "editrelationname.h"
#include "ui_editrelationname.h"

#include "mainwindow.h"
#include "relationdata.h"
#include "editnamecommand.h"

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
EditRelationName::EditRelationName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditRelationName)
{
    ui->setupUi(this);
    this->initialise();
}


EditRelationName::~EditRelationName()
{
    delete ui;
}


//#---------------------------------------------------------------------------#
//#------- STATIC PUBLIC -----------------------------------------------------#
//#---------------------------------------------------------------------------#
void EditRelationName::edit(MainWindow* window)
{
    EditRelationName ern(window);
    ern.setWindowModality(Qt::WindowModal);
    ern.ui->nameEdit->setText(window->relation()->name());

    if (ern.exec() == QDialog::Rejected)
        return;


    QString newName = ern.ui->nameEdit->text();
    QString oldName = window->m_relationData->name();
    if (newName != oldName)
        window->m_stack->push(new EditNameCommand(window->m_relationData, newName));
}


//#---------------------------------------------------------------------------#
//#------- VIRTUAL PUBLIC SLOTS ----------------------------------------------#
//#---------------------------------------------------------------------------#
void EditRelationName::accept()
{
    bool error = false;

    if (ui->nameEdit->text().isEmpty()){
        ui->nameAlert->setVisible(true);
        error = true;
    }else{
      ui->nameAlert->setVisible(false);
    }


    if (error)
        return;
    else
        QDialog::accept();
}



//#---------------------------------------------------------------------------#
//#------- PRIVATE -----------------------------------------------------------#
//#---------------------------------------------------------------------------#
void EditRelationName::initialise()
{
    QStyle* style = QApplication::style();
    QIcon icon = style->standardIcon(QStyle::SP_MessageBoxWarning);
    ui->nameAlert->setPixmap(icon.pixmap(20,20));

    QRegExp rx("([A-Za-z\\d\\_]*\\,){100}");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->nameEdit->setValidator(validator);

    ui->nameAlert->setVisible(false);
}
