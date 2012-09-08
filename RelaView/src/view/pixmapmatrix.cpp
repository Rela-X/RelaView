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

#include "pixmapmatrix.h"

#include "relationdata.h"

#include <QPainter>
#include <QPaintEvent>
#include <QColor>
#include <QPixmap>
#include <QPixmapCache>
#include <QUuid>


//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
PixmapMatrix::PixmapMatrix(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    this->setAutoFillBackground(false);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->m_cacheId = QUuid::createUuid().toString();
    qDebug("pixmap cache id:%s", this->m_cacheId.toStdString().c_str());

    //QPixmapCache::setCacheLimit(50); //in kB
}


PixmapMatrix::~PixmapMatrix()
{
}


//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
void PixmapMatrix::setRelation(RelationData* relation)
{
    if (relation){
        this->m_relation = relation;
        heightCount =  relation->height();
        widthCount = relation->width();
        this->updateRelation();
    }
}


void PixmapMatrix::updateRelation()
{
    QPixmapCache::remove(this->m_cacheId);
    this->update();
}


//#---------------------------------------------------------------------------#
//#------- PROTECTED ---------------------------------------------------------#
//#---------------------------------------------------------------------------#
void PixmapMatrix::paintEvent(QPaintEvent *event)
{
    if (!this->m_relation)
        return;


    QPixmap pixmap;
    if (!QPixmapCache::find(this->m_cacheId, &pixmap)) {
        pixmap = generatePixmap();
        QPixmapCache::insert(this->m_cacheId, pixmap);
    }



    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(event->rect(), pixmap);
    painter.end();
}


QSize PixmapMatrix::sizeHint() const
{
    return QSize(300, 300);
}

void PixmapMatrix::mousePressEvent(QMouseEvent *)
{
    //calculate clicked pixel


    QPixmapCache::remove(this->m_cacheId);
    this->update();
}


void PixmapMatrix::mouseMoveEvent(QMouseEvent *)
{

}




//#---------------------------------------------------------------------------#
//#------- PRIVATE -----------------------------------------------------------#
//#---------------------------------------------------------------------------#
QPixmap PixmapMatrix::generatePixmap()
{
    qDebug("generate Pixmap");
    //init
    int width = this->width();
    int height = this->height();

    QPainter painter;
    QPixmap pixmap(width, height);
    painter.begin(&pixmap);
    //painter.setRenderHint(QPainter::Antialiasing);


    //fill
    painter.fillRect(0,0,width, height, QBrush(Qt::white));

    QPen visiblePen = QPen();
    visiblePen.setColor(Qt::black);
    visiblePen.setStyle(Qt::SolidLine);

    QPen invisiblePen = QPen();
    invisiblePen.setColor(Qt::lightGray);
    invisiblePen.setStyle(Qt::SolidLine);

    //use event->rect() for the part of the matrix which has to be redrawn


    qreal hdiff = (qreal) height / (qreal) heightCount;
    qreal wdiff = (qreal) width / (qreal) widthCount;

    //Adds the rects to the scene
    for (int i = 0; i < widthCount; i++){
        for (int j = 0; j < heightCount; ++j) {
            if (this->m_relation->tableBit(i, j) == 1){
                 painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
                 painter.setPen(visiblePen);
             }else{
                 painter.setPen(invisiblePen);
                 painter.setBrush(QBrush(Qt::NoBrush));
             }
            painter.drawRect(QRectF(i*wdiff, j*hdiff, wdiff, hdiff));
        }
    }
    if (this->m_relation->propertyType() == AbstractProperty::homogeneous){
        painter.setPen(QPen(Qt::red));
        painter.drawLine(0, 0, width, height);
    }

    painter.end();

    return pixmap;
}
