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

#ifndef MATRIXVIEW_H
#define MATRIXVIEW_H

#include <QGraphicsView>

QT_FORWARD_DECLARE_CLASS(QGestureEvent)
QT_FORWARD_DECLARE_CLASS(QDropEvent)
QT_FORWARD_DECLARE_CLASS(QDragEnterEvent)
QT_FORWARD_DECLARE_CLASS(QDragMoveEvent)
QT_FORWARD_DECLARE_CLASS(QDragLeaveEvent)
QT_FORWARD_DECLARE_CLASS(QPinchGesture)


class MatrixView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit MatrixView(QWidget *parent = 0);

protected:
    bool event(QEvent *event);
    bool gestureEvent(QGestureEvent *event);
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);

private:
    void pinchTriggered(QPinchGesture *gesture);


signals:
    
public slots:
    

};

#endif // MATRIXVIEW_H
