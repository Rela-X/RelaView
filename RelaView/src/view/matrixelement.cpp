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

#include "matrixelement.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
MatrixElement::MatrixElement(unsigned int x, unsigned int y,
                             qreal w, qreal h,
                             const QPen& pen, const QBrush& brush) :
    QGraphicsRectItem(x*w,y*h,w,h)
{
    this->m_x = x;
    this->m_y = y;
    this->setPen(pen);
    this->setBrush(brush);
    this->setAcceptHoverEvents(true);
}

MatrixElement::~MatrixElement()
{
}


//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
void MatrixElement::setElementVisible()
{
    //this->setFlag(QGraphicsItem::ItemHasNoContents, false);
    this->setOpacity(1.0);
}

/**
 *  the item stays clickable but appears to be invisible
 */
void MatrixElement::setElementInvisible()
{
    //this->setFlag(QGraphicsItem::ItemHasNoContents, true);
    this->setOpacity(0.001);
}

unsigned int MatrixElement::xCoord()
{
    return this->m_x;
}

unsigned int MatrixElement::yCoord()
{
    return this->m_y;
}


void MatrixElement::setSize(qreal width, qreal height)
{
    this->setRect(this->xCoord()*width, this->yCoord()*height, width, height);
}


//#---------------------------------------------------------------------------#
//#------- PROTECTED ---------------------------------------------------------#
//#---------------------------------------------------------------------------#
void MatrixElement::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit this->elementMousePress(this);
    event->accept();

}

void MatrixElement::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
    emit this->elementHoverEnter(this);
    event->accept();
}
