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

#include "setpropertycommand.h"

#include "modificationfactory.h"
#include "relationdata.h"
#include "abstractproperty.h"

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
SetPropertyCommand::SetPropertyCommand(RelationData* original, const QString& name,
                                       const bool value, QUndoCommand* parent) :
    QUndoCommand(parent), m_clone(original->cloneRelation()), m_id(name), m_value(value)
{
    this->m_original = original;
}

SetPropertyCommand::~SetPropertyCommand()
{
    qDebug("SetPropertyCommand Destructor");
    delete m_clone;
    m_clone = 0;
}


//#---------------------------------------------------------------------------#
//#------- PUBLIC VIRTUAL ----------------------------------------------------#
//#---------------------------------------------------------------------------#
bool SetPropertyCommand::mergeWith(const QUndoCommand *)
{
    return false;
}


void SetPropertyCommand::undo()
{
    this->m_original->importRelation(m_clone);
}

void SetPropertyCommand::redo()
{
    const AbstractProperty* p = ModificationFactory::instance().propertyForName(this->m_id);
    p->setRelationProperty(this->m_original, this->m_value);
}
