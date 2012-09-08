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

#ifndef MATRIXELEMENT_H
#define MATRIXELEMENT_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>

class MatrixElement : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    //Constructor / Destructor
    MatrixElement(unsigned int x, unsigned int y, qreal w, qreal h, const QPen& pen = QPen(), const QBrush& brush = QBrush());
    ~MatrixElement();
    //Member functions
    void setElementVisible();
    void setElementInvisible();
    unsigned int xCoord();
    unsigned int yCoord();
    void setSize(qreal width, qreal heigth);

signals:
    void elementMousePress(MatrixElement* ele);
    void elementHoverEnter(MatrixElement* ele);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);

public slots:
    
private:
    unsigned int m_x;
    unsigned int m_y;
};

#endif // MATRIXELEMENT_H
