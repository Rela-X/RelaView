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

#ifndef PIXMAPMATRIX_H
#define PIXMAPMATRIX_H

#include <QGLWidget>

class RelationData;
QT_FORWARD_DECLARE_CLASS(QPixmap)

class PixmapMatrix : public QGLWidget
{
    Q_OBJECT
public:
    explicit PixmapMatrix(QWidget *parent = 0);
    ~PixmapMatrix();
    void setRelation(RelationData* relation);
    
protected:
    void paintEvent(QPaintEvent *);
    virtual QSize sizeHint() const;
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);

private slots:
    void updateRelation();

private:
    QString m_cacheId;
    QPixmap generatePixmap();
    RelationData* m_relation;
    int heightCount;
    int widthCount;
};

#endif // PIXMAPMATRIX_H
