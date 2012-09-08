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

#ifndef RELATIONDATA_H
#define RELATIONDATA_H

#include <QObject>

extern "C"
{
#include "defines.h"
}

#include "abstractproperty.h"


/**
  * Represents a Relation and serves as a wrapper for
  * the RelaFix Library functions
  */
class RelationData : public QObject
{
    Q_OBJECT

public:
    //Constructor
    RelationData(QObject *parent = 0);
    RelationData(RF_RELATION* rel,QObject *parent = 0);
    ~RelationData();
    //data management
    RelationData*       cloneRelation() const;
    RF_RELATION*        relaFixRelation() const;
    void                importRelation(const RelationData* relData);
    void                importRelation(const RF_RELATION* relData);
    //Member functions - Getter
    unsigned int        height() const;
    unsigned int        width() const;
    int                 tableBit(unsigned int x, unsigned int y) const;
    QString             name() const;
    QString             domain1Name() const;
    QString             domain2Name() const;
    QString             domain1Element(int pos) const;
    QString             domain2Element(int pos) const;
    unsigned int        domain1Count() const;
    unsigned int        domain2Count() const;
    AbstractProperty::PropertyType propertyType() const;
    void                emitRelationChanged() const;
    void                pauseRelationRedrawing(){ this->m_redrawAllowed = false;}
    void                resumeRelationRedrawing(){ this->m_redrawAllowed = true;}
    //Setter
    bool                setTableBit(unsigned int x, unsigned int y, int b);
    void                setName(const QString &name);


signals:
    void                relationChanged() const;
    void                relationNameChanged() const;

public slots:

    
private:
     //Member data
    RF_RELATION* m_relation;
    bool m_isModified;
    bool m_redrawAllowed;

};

#endif // RELATIONDATA_H
