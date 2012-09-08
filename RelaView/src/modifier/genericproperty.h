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

#ifndef GENERICPROPERTY_H
#define GENERICPROPERTY_H

#include "abstractproperty.h"

extern "C"{
#include "defines.h"
}
class RelationData;

class GenericProperty : public AbstractProperty
{
    Q_OBJECT
public:
    explicit GenericProperty(int (*isProperty)(RF_RELATION*),
                          int (*setProperty)(RF_RELATION*, RF_BOOL),
                          const QString &name, const QString &buttonText,
                          PropertyType propertyType, QObject *parent = 0);
    explicit GenericProperty(int (*isProperty)(RF_RELATION*),
                          int (*setProperty)(RF_RELATION*),
                          const QString &name, const QString &buttonText,
                          PropertyType propertyType, QObject *parent = 0);
    virtual bool isRelationProperty(const RelationData* relation) const;
    virtual int setRelationProperty(RelationData* relation, bool fill = true) const;

signals:
    
public slots:

private:
    int (*m_setProperty_2)(RF_RELATION*, RF_BOOL);
    int (*m_setProperty_1)(RF_RELATION*);
    int (*m_isProperty)(RF_RELATION*);
    
};

#endif // GENERICPROPERTY_H
