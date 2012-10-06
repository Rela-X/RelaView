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

#include "propertieswidget.h"
#include "ui_propertieswidget.h"

#include "abstractproperty.h"
#include "modificationfactory.h"
#include "relationdata.h"

#include <QListWidgetItem>


//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
PropertiesWidget::PropertiesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertiesWidget)
{
    //qDebug("PropertiesWidget Constructor");
    ui->setupUi(this);

    this->initPropWidget();
}


PropertiesWidget::~PropertiesWidget()
{
    //qDebug("PropertiesWidget Destructor");
    delete ui;
    ui = 0;
}




//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
void PropertiesWidget::setRelationData(RelationData* relData)
{
    if (relData){
        this->m_relationData = relData;

        //clear all widget items (for safety)
        ui->listWidget->clear();

        //Generates all needed propertie WidgetItems
        connect(this->m_relationData, SIGNAL(relationChanged()),
                this, SLOT(refreshProperty()));

        //homogeneous or inhomogeneous
        if (this->m_relationData->propertyType() == AbstractProperty::homogeneous)
            new QListWidgetItem(tr("homogeneous"), ui->listWidget);
        else if(this->m_relationData->propertyType() == AbstractProperty::inhomogeneous)
            new QListWidgetItem(tr("inhomogeneous"), ui->listWidget);


        foreach (AbstractProperty* p, ModificationFactory::instance().properties()){
            if (p->propertyType() == this->m_relationData->propertyType())
                this->generateWidgetItem(p);
        }

        connect(ui->listWidget, SIGNAL(itemChanged(QListWidgetItem*)),
                this, SIGNAL(checkStateChanged()));
    }
}


int PropertiesWidget::checkedCount() const
{
    int count = 0;
    for (int i = 0; i < ui->listWidget->count(); i++)
        if (ui->listWidget->item(i)->checkState() == Qt::Checked)
            count++;
    return count;
}


QStringList PropertiesWidget::checkedList() const
{
    QStringList list;
    for (int i = 0; i < ui->listWidget->count(); i++){
        QListWidgetItem* item = ui->listWidget->item(i);
        if (item->checkState() == Qt::Checked)
            list.append(item->text());
    }
    return list;
}

//#---------------------------------------------------------------------------#
//#------- PRIVATE SLOTS -----------------------------------------------------#
//#---------------------------------------------------------------------------#
void PropertiesWidget::refreshProperty()
{
    foreach (AbstractProperty* p, ModificationFactory::instance().properties()){
        QList<QListWidgetItem*> tmp = ui->listWidget->findItems(p->name(),Qt::MatchFixedString);
        QListIterator<QListWidgetItem*> iter(tmp);
        while (iter.hasNext()){
            QListWidgetItem* item = iter.next();
            this->setWidgetItemFlags(p, item);
            //qDebug("Property:%s changed is now %s",item->text().toStdString().c_str(), (value)?"true":"false");
        }
    }

}



//#---------------------------------------------------------------------------#
//#------- PRIVATE -----------------------------------------------------------#
//#---------------------------------------------------------------------------#
void PropertiesWidget::initPropWidget()
{
    //removes the Properties headline if not on osx
    //Non osx operation systems have an titlebar over the dockWidget
    //so the label is not necessary
#ifndef Q_WS_MAC
    this->layout()->removeWidget(ui->label);
#endif
}


void PropertiesWidget::generateWidgetItem(AbstractProperty* prop)
{
    QListWidgetItem* qlwi;
    qlwi = new QListWidgetItem(prop->name(), ui->listWidget);
    this->setWidgetItemFlags(prop, qlwi);
}

//responsible for setting widget items flags in relaview
void PropertiesWidget::setWidgetItemFlags(AbstractProperty* prop, QListWidgetItem* qlwi)
{
    qlwi->setFlags(Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
    if (prop->isRelationProperty(this->m_relationData)){
        qlwi->setBackgroundColor(palette.highlight().color());
    }else{
        qlwi->setBackgroundColor(palette.base().color());
    }
    if (!(qlwi->checkState() == Qt::Checked))
        qlwi->setCheckState(Qt::Unchecked);
}
