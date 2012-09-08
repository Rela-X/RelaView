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

#ifndef ABSTRACTPROPERTY_H
#define ABSTRACTPROPERTY_H

#include "abstractmodification.h"

class RelationData;

class AbstractProperty : public AbstractModification
{   
    Q_OBJECT

public:
    enum PropertyType
    {
        homogeneous, inhomogeneous
    };
    PropertyType propertyType() const{ return this->m_type;}
    virtual bool isRelationProperty(const RelationData* relation) const = 0;
    virtual int setRelationProperty(RelationData* relation, bool fill = true) const = 0;

protected:
    explicit AbstractProperty(const QString &name,
                              const QString &displayText,
                              QObject *parent = 0);
    PropertyType m_type;

};

#endif // ABSTRACTPROPERTY_H
