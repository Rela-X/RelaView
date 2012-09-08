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

#include "modificationfactory.h"

#include "abstractmodification.h"
#include "abstractoperation.h"
#include "abstractproperty.h"
#include "genericproperty.h"
#include "binaryoperation.h"
#include "unaryoperation.h"
#include "homogenousoperation.h"
#include "inhomogenousoperation.h"

#include <QString>

extern "C"{
#include "relation.h"
}


//#---------------------------------------------------------------------------#
//#------- MODIFICATION IDENTIFIER -------------------------------------------#
//#---------------------------------------------------------------------------#
const int ModificationFactory::ANTISYMMETRIC = 0;
const int ModificationFactory::ASYMMETRIC = 1;
const int ModificationFactory::TRANSITIVE = 2;
const int ModificationFactory::SYMMETRIC = 3;
const int ModificationFactory::IRREFLEXIVE = 4;
const int ModificationFactory::REFLEXIVE = 5;
const int ModificationFactory::EQUIVALENT = 6;
const int ModificationFactory::DIFUNCTIONAL = 7;
const int ModificationFactory::PREORDER = 8;
const int ModificationFactory::POSET = 9;
const int ModificationFactory::COMPLEMENT = 10;
const int ModificationFactory::CONVERSE = 11;
const int ModificationFactory::BOTTOM = 12;
const int ModificationFactory::ID = 13;
const int ModificationFactory::TOP = 14;
const int ModificationFactory::FULL = 15;
const int ModificationFactory::EMPTY = 16;
const int ModificationFactory::CONCATENATION = 17;
const int ModificationFactory::INTERSECTION = 18;
const int ModificationFactory::UNION = 19;


//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
ModificationFactory::ModificationFactory(QObject *parent) :
    QObject(parent)
{
    this->initialise();
}


ModificationFactory::~ModificationFactory()
{
    while (!this->m_property->isEmpty())
        delete this->m_property->takeFirst();
    delete this->m_property;
    while (!this->m_operation->isEmpty())
        delete this->m_operation->takeFirst();
    delete this->m_operation;
    delete this->m_opId;
    delete this->m_propId;
}

//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
const QList<AbstractProperty*>& ModificationFactory::properties() const
{
    return *this->m_property;
}

const QList<AbstractOperation*>& ModificationFactory::operations() const
{
    return *this->m_operation;
}


AbstractModification* ModificationFactory::modifierForId(int id) const
{
    AbstractModification *prop = propertyForId(id);

    if (prop == 0)
        return operationForId(id);
    else
        return 0;
}

AbstractProperty* ModificationFactory::propertyForId(int id) const
{
    return this->m_propId->value(id, 0);
}

AbstractOperation* ModificationFactory::operationForId(int id) const
{
    return this->m_opId->value(id, 0);
}


AbstractModification* ModificationFactory::modifierForName(const QString& name) const
{
    AbstractModification *prop = propertyForName(name);

    if (prop == 0)
        return operationForName(name);
    else
        return 0;
}


AbstractProperty* ModificationFactory::propertyForName(const QString& name) const
{
    for (int i = 0; i < this->m_property->count(); i++){
        AbstractProperty* mod = this->m_property->at(i);
        if (mod->name() == name)
            return mod;
    }
    return 0;
}

AbstractOperation* ModificationFactory::operationForName(const QString& name) const
{
    for (int i = 0; i < this->m_operation->count(); i++){
        AbstractOperation* mod = this->m_operation->at(i);
        if (mod->name() == name)
            return mod;
    }
    return 0;
}

//#---------------------------------------------------------------------------#
//#------- PRIVATE -----------------------------------------------------------#
//#---------------------------------------------------------------------------#
void ModificationFactory::initialise()
{
    this->m_property = new QList<AbstractProperty*>();
    this->m_operation = new QList<AbstractOperation*>();
    this->m_propId = new QHash<int, AbstractProperty*>();
    this->m_opId = new QHash<int, AbstractOperation*>();
    this->initProperties();
    this->initOperations();
}

void ModificationFactory::initProperties()
{
    AbstractProperty* property;

    property = new GenericProperty(&rf_relation_is_antisymmetric,
                                   &rf_relation_gain_antisymmetric,
                                   tr("antisymmetric"), tr("Set Antisymmetric"),
                                   AbstractProperty::homogeneous);
    this->m_propId->insert(ANTISYMMETRIC, property);
    this->m_property->append(property);

    property = new GenericProperty(&rf_relation_is_asymmetric,
                                   &rf_relation_gain_asymmetric,
                                   tr("asymmetric"), tr("Set Asymmetric"),
                                   AbstractProperty::homogeneous);
    this->m_propId->insert(ASYMMETRIC, property);
    this->m_property->append(property);

    property = new GenericProperty(&rf_relation_is_transitive,
                                   &rf_relation_gain_transitive,
                                   tr("transitive"), tr("Set Transitive"),
                                   AbstractProperty::homogeneous);
    this->m_propId->insert(TRANSITIVE, property);
    this->m_property->append(property);

    property = new GenericProperty(&rf_relation_is_symmetric,
                                   &rf_relation_gain_symmetric,
                                   tr("symmetric"), tr("Set Symmetric"),
                                   AbstractProperty::homogeneous);
    this->m_propId->insert(SYMMETRIC, property);
    this->m_property->append(property);

    property = new GenericProperty(&rf_relation_is_irreflexive,
                                   &rf_relation_gain_irreflexive,
                                   tr("irreflexive"), tr("Set Irreflexive"),
                                   AbstractProperty::homogeneous);
    this->m_propId->insert(IRREFLEXIVE, property);
    this->m_property->append(property);

    property = new GenericProperty(&rf_relation_is_reflexive,
                                   &rf_relation_gain_reflexive,
                                   tr("reflexive"), tr("Set Reflexive"),
                                   AbstractProperty::homogeneous);
    this->m_propId->insert(REFLEXIVE, property);
    this->m_property->append(property);

    property = new GenericProperty(&rf_relation_is_equivalent,
                                   &rf_relation_gain_equivalent,
                                   tr("equivalent"), tr("Set Equivalent"),
                                   AbstractProperty::homogeneous);
    this->m_propId->insert(EQUIVALENT, property);
    this->m_property->append(property);

    property = new GenericProperty(&rf_relation_is_difunctional,
                                   &rf_relation_gain_difunctional,
                                   tr("difunctional"), tr("Set Difunctional"),
                                   AbstractProperty::homogeneous);
    this->m_propId->insert(DIFUNCTIONAL, property);
    this->m_property->append(property);


    property = new GenericProperty(&rf_relation_is_preorder,
                                   &rf_relation_gain_preorder,
                                   tr("preorder"), tr("Set Preorder"),
                                   AbstractProperty::homogeneous);
    this->m_propId->insert(PREORDER, property);
    this->m_property->append(property);

    property = new GenericProperty(&rf_relation_is_poset,
                                   &rf_relation_gain_poset,
                                   tr("poset"), tr("Set Poset"),
                                   AbstractProperty::homogeneous);
    this->m_propId->insert(POSET, property);
    this->m_property->append(property);
}


void ModificationFactory::initOperations()
{
    AbstractOperation* operation;

    operation = new UnaryOperation(&rf_relation_create_complement,
                                   tr("complement"), tr("Set Complement"));
    this->m_operation->append(operation);

    operation = new UnaryOperation(&rf_relation_create_converse,
                                   tr("converse"), tr("Set Converse"));
    this->m_operation->append(operation);

    operation = new HomogenousOperation(&rf_relation_create_bottom,
                                        tr("bottom"), tr("bottom relation"));
    this->m_operation->append(operation);

    operation = new HomogenousOperation(&rf_relation_create_id,
                                        tr("id"), tr("id relation"));
    this->m_operation->append(operation);

    operation = new HomogenousOperation(&rf_relation_create_top,
                                        tr("top"), tr("top relation"));
    this->m_operation->append(operation);

    operation = new InhomogenousOperation(&rf_relation_create_full,
                                          tr("full"), tr("full relation"));
    this->m_operation->append(operation);

    operation = new InhomogenousOperation(&rf_relation_create_empty,
                                          tr("empty"), tr("empty relation"));
    this->m_operation->append(operation);

    operation = new BinaryOperation(&rf_relation_create_concatenation,
                                    tr("concatenation"), tr("Concatenate..."));
    this->m_operation->append(operation);

    operation = new BinaryOperation(&rf_relation_create_intersection,
                                    tr("intersection"), tr("Intersect..."));
    this->m_operation->append(operation);

    operation = new BinaryOperation(&rf_relation_create_union,
                                    tr("union"), tr("Unite..."));
    this->m_operation->append(operation);
}
