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

#include "domaindata.h"

extern "C"
{
#include "domain.h"
#include "list.h"
#include "tools.h"
}

#include <QStringList>

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
DomainData::DomainData(RF_DOMAIN* domain, QObject *parent) :
    QObject(parent)
{
    this->m_domain = domain;
    this->m_userCreated = false;
}

DomainData::DomainData(const QString &name, const QStringList &elements, QObject *parent):
    QObject(parent)
{
    this->m_userCreated = true;
    char *c_name = rf_string_copy((char *) name.toStdString().c_str());
    this->m_domain = rf_domain_create(c_name);

    RF_LIST *list = rf_list_create();

    RF_ELEMENT *element;
    char *c_elestr;
    for (int i = 0; i < elements.size(); i++){
        c_elestr = rf_string_copy((char *) elements.at(i).toStdString().c_str());
        element = rf_element_create(RF_ET_NAME, c_elestr);
        rf_list_append(list, element);
    }

    rf_domain_set_list(this->m_domain, list);
}

DomainData::~DomainData()
{
    if (this->m_userCreated)
        rf_domain_destroy(this->m_domain);
}

//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
RF_DOMAIN* DomainData::relaFixDomain() const
{
    return this->m_domain;
}


QString DomainData::name() const
{
    return QString(this->m_domain->name);
}

int DomainData::count() const
{
    return rf_domain_get_element_count(this->m_domain);
}

QString DomainData::element(int pos) const
{
    RF_ELEMENT* element = rf_domain_get_element_by_position(this->m_domain, pos);

    if (element->type == RF_ET_NAME){
        return (char* )element->data;
    }else if (element->type == RF_ET_DOMAIN || element->type == RF_ET_GLOBAL_DOMAIN){
        RF_DOMAIN* domain = (RF_DOMAIN*) element->data;
        return domain->name;
    }

    return "";
}


//#---------------------------------------------------------------------------#
//#------- OPERATOR ----------------------------------------------------------#
//#---------------------------------------------------------------------------#
bool DomainData::operator== (const DomainData &d1) const
{
    if (strcmp(this->m_domain->name, d1.m_domain->name) == 0)
        return true;
    else
        return false;
}
