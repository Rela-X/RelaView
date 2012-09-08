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

#ifndef UNARYOPERATIONCOMMAND_H
#define UNARYOPERATIONCOMMAND_H

#include <QUndoCommand>

class RelationData;
class UnaryOperation;

class UnaryOperationCommand : public QUndoCommand
{
public:
    enum{ idNumber = 4228};
    //Constructor / Destructor
    UnaryOperationCommand(const UnaryOperation* operation,
                          RelationData* relation);
    ~UnaryOperationCommand();
    //Member functions
    bool mergeWith(const QUndoCommand *other);
    void undo();
    void redo();
    int id() const{ return idNumber;}


private:
    const UnaryOperation* m_operation;
    RelationData *m_relation;
    RelationData* m_clone;
};

#endif // UNARYOPERATIONCOMMAND_H
