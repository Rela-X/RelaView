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

#include "preferences.h"
#include "ui_preferences.h"

#include "mainwindow.h"

#include <QColor>
#include <QSettings>
#include <QColorDialog>

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);
    this->loadSettings();
}

Preferences::~Preferences()
{
    delete ui;
}


//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
void Preferences::showPreferences()
{
    this->exec();
}


//#---------------------------------------------------------------------------#
//#------- PRIVATE -----------------------------------------------------------#
//#---------------------------------------------------------------------------#
void Preferences::loadSettings()
{
    QSettings settings;
    settings.beginGroup("MainWindow");
    ui->checkBox->setChecked(settings.value("diagonal", true).toBool());
    this->m_elementColor = settings.value("elementColor", QColor(Qt::black)).value<QColor>();
    this->m_borderColor = settings.value("borderColor", QColor(Qt::black)).value<QColor>();
    settings.endGroup();
}


//#---------------------------------------------------------------------------#
//#------- PRIVATE SLOTS -----------------------------------------------------#
//#---------------------------------------------------------------------------#
void Preferences::on_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)

    QSettings settings;
    settings.setValue("MainWindow/diagonal", ui->checkBox->isChecked());

    emit diagonalLineChanged(ui->checkBox->isChecked());
}


void Preferences::on_toolButton_clicked()
{
    QColor old = this->m_elementColor;
    this->m_elementColor = QColorDialog::getColor(old, this);

    if(old == this->m_elementColor)
        return;

    QSettings settings;
    settings.setValue("MainWindow/elementColor", this->m_elementColor);
    emit elementColorChanged(this->m_elementColor);
}


void Preferences::on_toolButton_2_clicked()
{
    QColor old = this->m_borderColor;
    this->m_borderColor = QColorDialog::getColor(old, this);

    if(old == this->m_borderColor)
        return;

    QSettings settings;
    settings.setValue("MainWindow/borderColor", this->m_borderColor);
    emit borderColorChanged(this->m_borderColor);
}

void Preferences::on_reset_clicked()
{
    this->m_elementColor = QColor(Qt::black);
    this->m_borderColor = QColor(Qt::black);
    ui->checkBox->setChecked(true);

    QSettings settings;
    settings.setValue("MainWindow/elementColor", this->m_elementColor);
    settings.setValue("MainWindow/borderColor", this->m_borderColor);
    settings.setValue("MainWindow/diagonal", ui->checkBox->isChecked());

    emit diagonalLineChanged(ui->checkBox->isChecked());
    emit elementColorChanged(this->m_elementColor);
    emit borderColorChanged(this->m_borderColor);
}
