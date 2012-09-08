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

#ifndef SEQUENCECONVERTER_H
#define SEQUENCECONVERTER_H

#include <QObject>


class RelationData;

class SequenceConverter : public QObject
{
    Q_OBJECT

public:
    //Constructor / Destructor
    explicit SequenceConverter(const uint width, const uint height, QObject *parent = 0);
    ~SequenceConverter();
    //member functions
    const QVector<uint>& rowSequence() const;
    const QVector<uint>& columnSequence() const;
    uint projectedX(const uint x) const;
    uint projectedY(const uint y) const;
    void setRowSequence(const QVector<uint> &v);
    void setColumnSequence(const QVector<uint> &v);
    void switchRows(const uint row1, const uint row2);
    void switchColumns(const uint column2, const uint column1);
    void resetSequence();

    
signals:
    void sequenceChanged() const;

public slots:

private:
    QVector<uint> *m_rowSequence;
    QVector<uint> *m_columnSequence;
    
};

#endif // SEQUENCECONVERTER_H
