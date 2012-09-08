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

#include "unaryoperationcommand.h"

#include "relationdata.h"
#include "unaryoperation.h"


//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
UnaryOperationCommand::UnaryOperationCommand(const UnaryOperation* operation,
                                             RelationData* relation):
    m_operation(operation)
{
    this->m_relation = relation;
    this->m_clone = relation->cloneRelation();
}

UnaryOperationCommand::~UnaryOperationCommand()
{
    qDebug("UnaryOperationCommand Destructor");
    delete this->m_clone;
}

//#---------------------------------------------------------------------------#
//#------- PUBLIC VIRTUAL ----------------------------------------------------#
//#---------------------------------------------------------------------------#
bool UnaryOperationCommand::mergeWith(const QUndoCommand *)
{
    return false;
}


void UnaryOperationCommand::undo()
{
    this->m_relation->importRelation(this->m_clone);
}

void UnaryOperationCommand::redo()
{
    this->m_operation->executeOperation(this->m_relation);
}
