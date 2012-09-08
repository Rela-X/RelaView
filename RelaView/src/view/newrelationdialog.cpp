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

#include "newrelationdialog.h"
#include "ui_newrelationdialog.h"

#include "datamanager.h"
#include "domaindata.h"
#include "mainwindow.h"
#include "relationdata.h"
#include "modificationfactory.h"
#include "abstractoperation.h"
#include "inhomogenousoperation.h"
#include "homogenousoperation.h"

extern "C"{
#include "defines.h"
#include "relation.h"
}

#include <QMessageBox>


//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
NewRelationDialog::NewRelationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewRelationDialog)
{
    ui->setupUi(this);
    this->initialise();
}

NewRelationDialog::~NewRelationDialog()
{
    qDebug("NewRelationDialog Destructor");
    delete ui;
}

//#---------------------------------------------------------------------------#
//#------- PUBLIC STATIC -----------------------------------------------------#
//#---------------------------------------------------------------------------#
void NewRelationDialog::performNewRelation()
{
    NewRelationDialog props;
    int ret = props.exec();

    if (ret != QDialog::Accepted)
        return;


    DomainData* d1 = 0, *d2 = 0;
    QList<DomainData* > dom = DataManager::domains();

    for (int i = 0; i < dom.size(); i++){
        if (props.ui->comboBox->currentText() == dom.at(i)->name())
            d1 = dom.at(i);

        if (props.ui->comboBox_2->currentText() == dom.at(i)->name())
            d2 = dom.at(i);
    }

    if (d1 == 0 || d2 == 0)
        return;

    AbstractOperation* operation;
    int error = 0;
    RelationData* newRelation = new RelationData();
    QString currentText = props.ui->stateBox->currentText();
    operation = ModificationFactory::instance().operationForName(currentText);


    if (operation->operationType() == AbstractOperation::newInhomogenous){
        InhomogenousOperation* inop = qobject_cast<InhomogenousOperation*>(operation);
        if (inop)
            error = inop->executeOperation(newRelation, d1, d2);

    }else if(operation->operationType() == AbstractOperation::newHomogenous){
        HomogenousOperation* hoop = qobject_cast<HomogenousOperation*>(operation);
        if (hoop)
            error = hoop->executeOperation(newRelation, d1);
    }

    if (error == 0){
        delete newRelation;
        return;
    }

    newRelation->setName(props.ui->relationName->text());
    MainWindow::newWindowWithRelation(newRelation);

}


//#---------------------------------------------------------------------------#
//#------- VIRTUAL PUBLIC SLOTS ----------------------------------------------#
//#---------------------------------------------------------------------------#
void NewRelationDialog::accept()
{
    bool error = false;

    if (ui->relationName->text().isEmpty()){
        ui->alert_relationName->setVisible(true);
        error = true;
    }else{
      ui->alert_relationName->setVisible(false);
    }


    if (ui->comboBox->currentIndex() == -1){
        ui->alert_cb->setVisible(true);
        error = true;
    }else{
        ui->alert_cb->setVisible(false);
    }

    if (ui->comboBox_2->currentIndex() == -1){
        ui->alert_cb2->setVisible(true);
        error = true;
    }else{
        ui->alert_cb2->setVisible(false);
    }


    if (error)
        return;
    else
        QDialog::accept();
}


//#---------------------------------------------------------------------------#
//#------- PRIVATE -----------------------------------------------------------#
//#---------------------------------------------------------------------------#
void NewRelationDialog::initialise()
{
    QList<DomainData* > dom = DataManager::domains();

    for (int i = 0; i < dom.size(); i++){
        ui->comboBox->addItem(dom.at(i)->name());
        ui->comboBox_2->addItem(dom.at(i)->name());
    }

    QRegExp rx("([A-Za-z\\d\\_]*\\,){100}");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->relationName->setValidator(validator);

    QStyle* style = QApplication::style();
    QIcon icon = style->standardIcon(QStyle::SP_MessageBoxWarning);
    ui->alert_relationName->setPixmap(icon.pixmap(20,20));
    ui->alert_cb->setPixmap(icon.pixmap(20,20));
    ui->alert_cb2->setPixmap(icon.pixmap(20,20));

    ui->alert_relationName->setVisible(false);
    ui->alert_cb->setVisible(false);
    ui->alert_cb2->setVisible(false);

    this->updateStateBox();
}


void NewRelationDialog::updateStateBox()
{
    //remember selected item
    QString selected = ui->stateBox->currentText();

    ui->stateBox->clear();
    foreach (AbstractOperation* operation, ModificationFactory::instance().operations()){
        if (operation->operationType() == AbstractOperation::newInhomogenous
                || operation->operationType() == AbstractOperation::newHomogenous){

            if (ui->checkBox->isChecked())
                ui->stateBox->addItem(operation->name());
            else //only operations which are compatible to inhomogenous relations e.g. full, empty
                if (operation->operationType() == AbstractOperation::newInhomogenous)
                    ui->stateBox->addItem(operation->name());
        }
    }

    //Set former item if still in stateBox
    int i = ui->stateBox->findText(selected);
    i = (i == -1) ? 0 : i;
    ui->stateBox->setCurrentIndex(i);
}

//#---------------------------------------------------------------------------#
//#------- PRIVATE SLOTS -----------------------------------------------------#
//#---------------------------------------------------------------------------#
void NewRelationDialog::refreshUiState()
{
    ui->comboBox_2->setEnabled(!ui->checkBox->isChecked());
    if (ui->checkBox->isChecked())
        ui->comboBox_2->setCurrentIndex(ui->comboBox->currentIndex());

    this->updateStateBox();
}
