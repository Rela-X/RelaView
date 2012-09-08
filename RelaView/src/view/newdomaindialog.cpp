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

#include "newdomaindialog.h"
#include "ui_newdomaindialog.h"

#include "datamanager.h"
#include "domaindata.h"

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
NewDomainDialog::NewDomainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDomainDialog)
{
    ui->setupUi(this);
    this->initialise();
}

NewDomainDialog::~NewDomainDialog()
{
    delete ui;
}


//#---------------------------------------------------------------------------#
//#------- PUBLIC STATIC -----------------------------------------------------#
//#---------------------------------------------------------------------------#
void NewDomainDialog::performNewDomain()
{
    NewDomainDialog domains;
    int ret = domains.exec();

    if (ret != QDialog::Accepted)
        return;

    if (domains.ui->radioButtonText->isChecked())
        domains.createDomainByText();
    else if (domains.ui->radioButtonSpin->isChecked())
        domains.createDomainByNumbers();
    else
        return;

}


//#---------------------------------------------------------------------------#
//#------- VIRTUAL PUBLIC SLOTS ----------------------------------------------#
//#---------------------------------------------------------------------------#
void NewDomainDialog::accept()
{
    bool error = false;



    if (ui->domainEdit->text().isEmpty()){
        ui->domainAlert->setVisible(true);
        error = true;
    }else{
        ui->domainAlert->setVisible(false);
        ui->domainAlert->setToolTip("");
    }

    QList<DomainData* > &list = DataManager::domains();
    for (int i = 0; i < list.size(); i++){
        if (ui->domainEdit->text() == list.at(i)->name()){
            ui->domainAlert->setVisible(true);
            ui->domainAlert->setToolTip(tr("domain name already in use"));
            error = true;
            break;
        }
    }

    if (ui->radioButtonText->isChecked() &&
            ui->elementsEdit->text().isEmpty()){
        ui->elementsAlert->setVisible(true);
        error = true;
    }else{
      ui->elementsAlert->setVisible(false);
    }



    if (error)
        return;
    else
        QDialog::accept();
}


//#---------------------------------------------------------------------------#
//#------- PRIVATE -----------------------------------------------------------#
//#---------------------------------------------------------------------------#
void NewDomainDialog::initialise()
{

    QStyle* style = QApplication::style();
    QIcon icon = style->standardIcon(QStyle::SP_MessageBoxWarning);
    ui->domainAlert->setPixmap(icon.pixmap(20,20));
    ui->elementsAlert->setPixmap(icon.pixmap(20,20));

    ui->domainAlert->setVisible(false);
    ui->elementsAlert->setVisible(false);

    QRegExp rx("([A-Za-z\\d\\_]*\\,){100}");
    QValidator *validator_element = new QRegExpValidator(rx, this);
    QValidator *validator_name = new QRegExpValidator(rx, this);
    ui->elementsEdit->setValidator(validator_element);
    ui->domainEdit->setValidator(validator_name);
}


void NewDomainDialog::createDomainByText()
{
    QString elements = ui->elementsEdit->text();
    QStringList list = elements.split(",", QString::SkipEmptyParts);

    DomainData *domain = new DomainData(ui->domainEdit->text(), list);
    DataManager::domains().append(domain);
}


void NewDomainDialog::createDomainByNumbers()
{
    QStringList list;

    for (int i = 0; i < ui->spinBox->value(); i++){
        list.append(QString("%1").arg(i));
    }

    DomainData *domain = new DomainData(ui->domainEdit->text(), list);
    DataManager::domains().append(domain);
}
