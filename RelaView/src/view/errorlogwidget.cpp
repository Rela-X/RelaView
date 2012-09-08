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

#include "errorlogwidget.h"
#include "ui_errorlogwidget.h"

#include <QListWidgetItem>
#include <QSettings>

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
ErrorLogWidget::ErrorLogWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorLogWidget)
{
    ui->setupUi(this);

    //settings
    QSettings settings;
    bool state = settings.value("ErrorLog/automaticOpening", false).toBool();
    ui->checkBox->setChecked(state);
    connect(ui->checkBox, SIGNAL(stateChanged(int)), this, SLOT(writeSettings()));

    //Close shortcut
    QAction* close = new QAction(this);
    close->setShortcut(QKeySequence::Close);
    this->addAction(close);
    connect(close, SIGNAL(triggered()), this, SLOT(hide()));
}

ErrorLogWidget::~ErrorLogWidget()
{
    delete ui;
}


//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
void ErrorLogWidget::addMessage(const QString& string)
{
    QListWidgetItem* item = new QListWidgetItem(string);
    item->setToolTip(string);
    ui->listWidget->addItem(item);

    if (!ui->checkBox->isChecked()){
        this->show();
    }
}


//#---------------------------------------------------------------------------#
//#------- PRIVATE SLOTS -----------------------------------------------------#
//#---------------------------------------------------------------------------#
void ErrorLogWidget::clearLog()
{
    ui->listWidget->clear();
}

void ErrorLogWidget::writeSettings()
{
    QSettings settings;
    settings.setValue("ErrorLog/automaticOpening", ui->checkBox->isChecked());
}
