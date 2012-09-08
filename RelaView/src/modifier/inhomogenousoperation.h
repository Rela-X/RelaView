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

#ifndef INHOMOGENOUSOPERATION_H
#define INHOMOGENOUSOPERATION_H

#include "abstractoperation.h"

extern "C"{
#include "defines.h"
}

class DomainData;
class RelationData;

class InhomogenousOperation : public AbstractOperation
{
    Q_OBJECT
public:
    explicit InhomogenousOperation(RF_RELATION* (*operation)(RF_DOMAIN*, RF_DOMAIN*, RF_ERROR*),
                                   const QString &name, const QString &displayText,
                                   QObject *parent = 0);
    int executeOperation(RelationData* relation,
                         const DomainData* domain1,
                         const DomainData* domain2) const;

signals:
    
public slots:

private:
    RF_RELATION* (*m_operation)(RF_DOMAIN*, RF_DOMAIN*, RF_ERROR*);
};

#endif // INHOMOGENOUSOPERATION_H
