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

#include "setpropertiescommand.h"

#include "modificationfactory.h"
#include "relationdata.h"
#include "abstractproperty.h"

#include <QStringList>

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
SetPropertiesCommand::SetPropertiesCommand(RelationData* relation, const QStringList list,
                                         const bool value, unsigned int x,
                                         unsigned int y, QUndoCommand* parent) :
    QUndoCommand(parent), m_list(list), m_clone(relation->cloneRelation()),
    m_value(value), m_x(x), m_y(y)
{
    this->m_original = relation;

}

SetPropertiesCommand::~SetPropertiesCommand()
{
    qDebug("SetPropertiesCommand Destructor");
    delete m_clone;
    m_clone = 0;
}


//#---------------------------------------------------------------------------#
//#------- PUBLIC VIRTUAL ----------------------------------------------------#
//#---------------------------------------------------------------------------#
bool SetPropertiesCommand::mergeWith(const QUndoCommand *)
{
    return false;
}


void SetPropertiesCommand::undo()
{
    this->m_original->importRelation(m_clone);

}

void SetPropertiesCommand::redo()
{
    this->m_original->pauseRelationRedrawing();
    int toggleBit = (m_original->tableBit(m_x, m_y) == 1) ? 0 : 1;
    this->m_original->setTableBit(this->m_x, this->m_y, toggleBit);

    //set properties
    for (int i = 0; i < this->m_list.count(); i++){
        const AbstractProperty* p = ModificationFactory::instance().propertyForName(this->m_list.at(i));
        if(!p->isRelationProperty(this->m_original))
            p->setRelationProperty(this->m_original, this->m_value);
    }
    this->m_original->resumeRelationRedrawing();
    this->m_original->emitRelationChanged();
}
