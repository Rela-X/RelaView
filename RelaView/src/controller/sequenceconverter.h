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
    explicit SequenceConverter(const int width, const int height, QObject *parent = 0);
    ~SequenceConverter();
    //member functions
    const QVector<int>& rowSequence() const;
    const QVector<int>& columnSequence() const;
    int projectedX(const int x) const;
    int projectedY(const int y) const;
    void setRowSequence(const QVector<int> &v);
    void setColumnSequence(const QVector<int> &v);
    void switchRows(const int row1, const int row2);
    void switchColumns(const int column2, const int column1);
    void resetSequence();

    
signals:
    void sequenceChanged() const;

public slots:

private:
    QVector<int> *m_rowSequence;
    QVector<int> *m_columnSequence;
    
};

#endif // SEQUENCECONVERTER_H
