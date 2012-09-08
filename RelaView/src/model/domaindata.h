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

#ifndef DOMAINDATA_H
#define DOMAINDATA_H

#include <QObject>

extern "C"{
#include "defines.h"
}

class DomainData : public QObject
{
    Q_OBJECT
public:
    //Constructor/Destructor
    DomainData(RF_DOMAIN* domain, QObject *parent = 0);
    DomainData(const QString &name, const QStringList &list, QObject *parent = 0);
    ~DomainData();
    //functions
    RF_DOMAIN* relaFixDomain() const;
    QString name() const;
    int count() const;
    QString element(int pos) const;
    //operators
    bool operator== (const DomainData &d1) const;
signals:

public slots:

private:
    //member variables
    RF_DOMAIN* m_domain;
    bool m_userCreated;
};

#endif // DOMAINDATA_H
