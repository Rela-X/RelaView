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

#include "sequenceconverter.h"

#include "relationdata.h"

#include <QVector>

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
SequenceConverter::SequenceConverter(const int width, const int height, QObject *parent) :
    QObject(parent)
{
    this->m_columnSequence = new QVector<int>(width);
    this->m_rowSequence = new QVector<int>(height);

    this->resetSequence();
}

SequenceConverter::~SequenceConverter()
{
    delete this->m_rowSequence;
    delete this->m_columnSequence;
    this->m_rowSequence = 0;
    this->m_columnSequence = 0;
    qDebug("SequenceConverter Destructor");
}


//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
const QVector<int>& SequenceConverter::rowSequence() const
{
    return *this->m_rowSequence;
}

const QVector<int>& SequenceConverter::columnSequence() const
{
    return *this->m_columnSequence;
}


int SequenceConverter::projectedX(const int x) const
{
    if (x >= this->m_columnSequence->size())
        return 0;

    return (*m_columnSequence)[x];
}


int SequenceConverter::projectedY(const int y) const
{
    if (y >= this->m_rowSequence->size())
        return 0;

    return (*m_rowSequence)[y];
}


void SequenceConverter::setRowSequence(const QVector<int> &v)
{
    if (this->m_rowSequence->size() != v.size())
        return;

    for (int i = 0; i < v.size(); i++)
        if (v.at(i) >= this->m_rowSequence->size())
            return;

    for (int i = 0; i < this->m_rowSequence->size(); i++)
        (*m_rowSequence)[i] = v[i];

    emit sequenceChanged();
}


void SequenceConverter::setColumnSequence(const QVector<int> &v)
{
    if (this->m_columnSequence->size() != v.size())
        return;

    for (int i = 0; i < v.size(); i++)
        if (v.at(i) >= this->m_columnSequence->size())
            return;

    for (int i = 0; i < this->m_columnSequence->size(); i++)
        (*m_columnSequence)[i] = v[i];

    emit sequenceChanged();
}


void SequenceConverter::switchRows(const int row1, const int row2)
{
    if (row1 >= this->m_rowSequence->size()
            || row2 >= this->m_rowSequence->size())
        return;

    int tmp = m_rowSequence->at(row1);
    (*m_rowSequence)[row1] = m_rowSequence->at(row2);
    (*m_rowSequence)[row2] = tmp;

    emit sequenceChanged();
}


void SequenceConverter::switchColumns(const int column1, const int column2)
{
    if (column1 >= this->m_columnSequence->size()
            || column2 >= this->m_columnSequence->size())
        return;

    int tmp = m_columnSequence->at(column1);
    (*m_columnSequence)[column1] = m_columnSequence->at(column2);
    (*m_columnSequence)[column2] = tmp;

    emit sequenceChanged();
}


void SequenceConverter::resetSequence()
{
    for (int i = 0; i < m_rowSequence->size(); i++)
        (*m_rowSequence)[i] = i;

    for (int i = 0; i < m_columnSequence->size(); i++)
        (*m_columnSequence)[i] = i;

    emit sequenceChanged();
}


