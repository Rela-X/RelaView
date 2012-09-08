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

#include "unaryoperation.h"

#include "relationdata.h"
#include "errorlogwidget.h"

extern "C"{
#include "relation.h"
#include "tools.h"
}

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
UnaryOperation::UnaryOperation(RF_RELATION* (*operation)(RF_RELATION*, RF_ERROR*),
                               const QString &name, const QString &buttonText,
                               QObject *parent):
    AbstractOperation(name, buttonText, parent)
{
    this->m_operation = operation;
    this->m_type = AbstractOperation::unary;
}


//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
int UnaryOperation::executeOperation(RelationData* relation) const
{
    RF_ERROR error;
    RF_RELATION* newRelation = (*this->m_operation)(relation->relaFixRelation(), &error);


    if (newRelation == 0){
        ErrorLogWidget::instance().addMessage(error.string);
        return 0;
    }

    //due to the free(name) call in rf_relation_destroy
    char *c_name = (char *) relation->name().toStdString().c_str();
    newRelation->name = rf_string_copy(c_name);


    relation->importRelation(newRelation);
    rf_relation_destroy(newRelation);

    return 1;
}

