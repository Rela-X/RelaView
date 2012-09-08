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

#ifndef ABSTRACTMODIFICATION_H
#define ABSTRACTMODIFICATION_H

#include <QObject>

class AbstractModification : public QObject
{
    Q_OBJECT
public:
    enum ModificationType{
        Property, //e.g. asymmetrich, reflexive, ...
        Operation //e.g. bottom, id, concatenation, ...
    };
    //member functions
    QString name() const{ return this->m_name;}
    QString displayText() const{ return this->m_displayText;}
    ModificationType modType() const{ return this->m_modType;}

protected:
    //Constructor / Destructor
    explicit AbstractModification(const QString &name, const QString &displayText,
                                  QObject *parent = 0);
    //functions
    //members
    QString m_name;
    QString m_displayText;
    ModificationType m_modType;
    
};

#endif // ABSTRACTMODIFICATION_H
