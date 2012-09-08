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

#include "genericproperty.h"

#include "relationdata.h"

extern "C"{
#include "relation.h"
}

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
GenericProperty::GenericProperty(int (*isProperty)(RF_RELATION*),
                           int (*setProperty)(RF_RELATION*, RF_BOOL),
                           const QString &name, const QString &displayText,
                           PropertyType type, QObject *parent) :
    AbstractProperty(name, displayText, parent)

{
    this->m_setProperty_1 = 0;
    this->m_setProperty_2 = setProperty;
    this->m_isProperty = isProperty;
    this->m_type = type;
}

GenericProperty::GenericProperty(int (*isProperty)(RF_RELATION*),
                           int (*setProperty)(RF_RELATION*),
                           const QString &name, const QString &displayText,
                           PropertyType type, QObject *parent):
    AbstractProperty(name, displayText, parent)
{
    this->m_setProperty_1 = setProperty;
    this->m_setProperty_2 = 0;
    this->m_isProperty = isProperty;
    this->m_type = type;
}

//#---------------------------------------------------------------------------#
//#------- PUBLIC VIRTUAL ----------------------------------------------------#
//#---------------------------------------------------------------------------#
bool GenericProperty::isRelationProperty(const RelationData* relation) const
{
    if ((m_isProperty != 0) && (relation->relaFixRelation()))
        return  ((*m_isProperty)(relation->relaFixRelation()) == 1) ? true : false;
    else
        return false;
}

int GenericProperty::setRelationProperty(RelationData* relation, bool fill) const
{
    int ret;
    if (m_setProperty_1 != 0)
        ret = (*m_setProperty_1)(relation->relaFixRelation());
    else if (m_setProperty_2 != 0)
        ret = (*m_setProperty_2)(relation->relaFixRelation(), fill);
    else
        return 0;

    relation->emitRelationChanged();
    return ret;
}
