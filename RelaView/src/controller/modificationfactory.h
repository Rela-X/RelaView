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

#ifndef MODIFICATIONFACTORY_H
#define MODIFICATIONFACTORY_H

#include <QObject>

class AbstractModification;
class AbstractOperation;
class AbstractProperty;

#include <QHash>

class ModificationFactory : public QObject
{
    Q_OBJECT

public:
    static const ModificationFactory& instance()
    {
        static ModificationFactory factory;
        return factory;
    }
    const QList<AbstractProperty*>& properties() const;
    const QList<AbstractOperation*>& operations() const;
    AbstractModification* modifierForId(int id) const;
    AbstractProperty* propertyForId(int id) const;
    AbstractOperation* operationForId(int id) const;
    AbstractModification* modifierForName(const QString& id) const;
    AbstractProperty* propertyForName(const QString& name) const;
    AbstractOperation* operationForName(const QString& name) const;
    //for identification of a modificiation within the code
    static const int ANTISYMMETRIC;
    static const int ASYMMETRIC;
    static const int TRANSITIVE;
    static const int SYMMETRIC;
    static const int IRREFLEXIVE;
    static const int REFLEXIVE;
    static const int EQUIVALENT;
    static const int DIFUNCTIONAL;
    static const int PREORDER;
    static const int POSET;
    static const int COMPLEMENT;
    static const int CONVERSE;
    static const int BOTTOM;
    static const int ID;
    static const int TOP;
    static const int FULL;
    static const int EMPTY;
    static const int CONCATENATION;
    static const int INTERSECTION;
    static const int UNION;

private:
    //member functions
    void initialise();
    void initProperties();
    void initOperations();
    //constructor / destrcutor
    explicit ModificationFactory(QObject *parent = 0);
    ~ModificationFactory();
    //member variables
    QList<AbstractProperty*>* m_property;
    QList<AbstractOperation*>* m_operation;
    QHash<int, AbstractProperty*>* m_propId;
    QHash<int, AbstractOperation*>* m_opId;
    
};

#endif // MODIFICATIONFACTORY_H
