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

#include "toggleelementcommand.h"

#include "relationdata.h"


//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
ToggleElementCommand::ToggleElementCommand(RelationData* relData, unsigned int x,
                                           unsigned int y, QUndoCommand* parent) :
    QUndoCommand(parent), m_x(x), m_y(y)
{
    this->m_relationData = relData;
    this->m_oldBit = this->m_relationData->tableBit(x, y);
}

ToggleElementCommand::~ToggleElementCommand()
{
    qDebug("ToggleElementCommand Destructor");
}




//#---------------------------------------------------------------------------#
//#------- PUBLIC VIRTUAL ----------------------------------------------------#
//#---------------------------------------------------------------------------#
bool ToggleElementCommand::mergeWith(const QUndoCommand *)
{
    return false;
}


void ToggleElementCommand::undo()
{
    if (m_oldBit == 0)
        this->m_relationData->setTableBit(this->m_x,this->m_y,0);
    else
        this->m_relationData->setTableBit(this->m_x,this->m_y,1);
}

void ToggleElementCommand::redo()
{
    if (m_oldBit == 0)
        this->m_relationData->setTableBit(this->m_x,this->m_y,1);
    else
        this->m_relationData->setTableBit(this->m_x,this->m_y,0);
}
