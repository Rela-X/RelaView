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

#include "relationdata.h"


extern "C"
{
#include "relation.h"
#include "table.h"
#include "tools.h"
#include "domain.h"
}

#include <QMutex>


//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
RelationData::RelationData(QObject *parent) : QObject(parent)
{
    qDebug("RelationData Constructor");
    this->m_relation = 0;
    this->m_redrawAllowed = true;
}

RelationData::RelationData(RF_RELATION* rel, QObject *parent) : QObject(parent)
{
    qDebug("RelationData Constructor");
    this->m_relation = 0;
    this->m_relation = rf_relation_copy(rel);
    //due to the uniqueness of relation names relafix does not copie
    //the relation name itself; so a manual copy is necessary
    if(!this->m_relation->name){
        this->m_relation->name = rf_string_copy(rel->name);
    }
    this->m_redrawAllowed = true;
}


RelationData::~RelationData()
{
    qDebug("RelationData Destrcutor");
    if (this->m_relation)
        rf_relation_destroy(this->m_relation);
}


//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
RelationData* RelationData::cloneRelation() const
{
    //manual hard copy
    return new RelationData(this->m_relation);
}

void RelationData::importRelation(const RelationData* rel)
{
    this->importRelation(rel->relaFixRelation());
}


void RelationData::importRelation(const RF_RELATION* rel)
{
    if (!rel)
        return;

    if (this->m_relation)
        rf_relation_destroy(this->m_relation);


    this->m_relation = rf_relation_copy((RF_RELATION*) rel);
    //due to the uniqueness of relation names relafix does not copie
    //the relation name itself when using rf_relation_copy
    //so a manual copy is necessary
    if(!this->m_relation->name){
       this->m_relation->name = rf_string_copy(rel->name);
    }

    if (this->m_redrawAllowed)
        emit relationChanged();
}


RF_RELATION* RelationData::relaFixRelation() const
{
    if (this->m_relation)
        return this->m_relation;
    else
        return 0;
}



unsigned int RelationData::height() const
{
    if (!this->m_relation)
        return 0;

    return this->m_relation->table->height;
}

unsigned int RelationData::width() const
{
    if (!this->m_relation)
        return 0;

    return this->m_relation->table->width;
}

int RelationData::tableBit(unsigned int x, unsigned int y) const
{
    if (!this->m_relation)
        return 0;

    return rf_table_get_bit(this->m_relation->table, x, y);
}


QString RelationData::name() const
{
    if (!this->m_relation)
        return "";

    return this->m_relation->name;
}

QString RelationData::domain1Name() const
{
    if (!this->m_relation)
        return "";

    return this->m_relation->domain_1->name;
}

QString RelationData::domain2Name() const
{
    if (!this->m_relation)
        return "";

    return this->m_relation->domain_2->name;
}

QString RelationData::domain1Element(int pos) const
{
    if (!this->m_relation)
        return "";

    RF_ELEMENT* element = rf_domain_get_element_by_position(this->m_relation->domain_1, pos);

    if (element->type == RF_ET_NAME){
        return (char* )element->data;
    }else if (element->type == RF_ET_DOMAIN || element->type == RF_ET_GLOBAL_DOMAIN){
        RF_DOMAIN* domain = (RF_DOMAIN*) element->data;
        return domain->name;
    }

    return "";
}

QString RelationData::domain2Element(int pos) const
{
    if (!this->m_relation)
        return "";

    RF_ELEMENT* element = rf_domain_get_element_by_position(this->m_relation->domain_2, pos);

    if (element->type == RF_ET_NAME){
        return (char* )element->data;
    }else if (element->type == RF_ET_DOMAIN || element->type == RF_ET_GLOBAL_DOMAIN){
        RF_DOMAIN* domain = (RF_DOMAIN*) element->data;
        return domain->name;
    }

    return "";
}

unsigned int RelationData::domain1Count() const
{
    if (!this->m_relation)
        return 0;

    return this->m_relation->domain_1->elements->count;
}

unsigned int RelationData::domain2Count() const
{
    if (!this->m_relation)
        return 0;

    return this->m_relation->domain_2->elements->count;
}



AbstractProperty::PropertyType RelationData::propertyType() const
{
    if (!this->m_relation)
        return AbstractProperty::inhomogeneous;

    if (this->domain1Name() == this->domain2Name())
        return AbstractProperty::homogeneous;
    else
        return AbstractProperty::inhomogeneous;
}



void RelationData::emitRelationChanged() const
{
    if (!this->m_relation)
        return;

    if(this->m_redrawAllowed)
        emit relationChanged();
}


bool RelationData::setTableBit(unsigned int x, unsigned int y, int b)
{
    if (!this->m_relation)
        return false;

    if (!rf_table_set_bit(this->m_relation->table, x, y, b)){
        if(this->m_redrawAllowed)
            emit relationChanged();
        return true;
    }else{
        return false;
    }
}


void RelationData::setName(const QString &name)
{
    if (!this->m_relation)
        return;

    if (this->m_relation->name){
        free(this->m_relation->name);
    }

    char *c_name = (char *) name.toStdString().c_str();
    this->m_relation->name = rf_string_copy(c_name);

    //relation changed
    emit relationNameChanged();
}
