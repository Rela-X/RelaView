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

#include "matrixview.h"

#include "mainwindow.h"
#include "datamanager.h"

#include <QMimeData>
#include <QUrl>
#include <QFileInfo>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QPinchGesture>

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
MatrixView::MatrixView(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setAcceptDrops(true);
    this->grabGesture(Qt::PinchGesture);
}


//#---------------------------------------------------------------------------#
//#------- PROTECTED ---------------------------------------------------------#
//#---------------------------------------------------------------------------#
bool MatrixView::event(QEvent *event)
{
    if (event->type() == QEvent::Gesture){
        qDebug("Gesture Event");
        return gestureEvent(static_cast<QGestureEvent*>(event));
    }
    return QGraphicsView::event(event);
}


bool MatrixView::gestureEvent(QGestureEvent *event)
{
    if (QGesture *pinch = event->gesture(Qt::PinchGesture))
        pinchTriggered(static_cast<QPinchGesture *>(pinch));
    return true;
}


/**
  *   Look for his Parent MainWindow and passes them the urls
  */
void MatrixView::dropEvent(QDropEvent *event)
{
    const QMimeData *mime =  event->mimeData();
    QStringList files;

    //if mimeData has no urls return
    if (mime->hasUrls()){
        QList<QUrl> urls = mime->urls();
        QListIterator<QUrl> iter(urls);
        while (iter.hasNext()){

            QUrl url = iter.next();
            //Check for url
            if (url.isLocalFile()){
                QFileInfo file(url.toLocalFile());
                if (file.isFile() && file.isReadable() && file.suffix() == "rfc"){
                    files.append(url.toLocalFile());
                }
            }
        }
     }

    //No .rfc files?
    if (files.isEmpty()){
        event->ignore();
        return;
    }


    MainWindow* w = dynamic_cast<MainWindow*>(this->window());
    if (w){
        event->accept();
         DataManager::openRelaFixFiles(w, &files);
         return;
    }else{
        qDebug("dropEvent ignored because dynamic_cast failed!");
        event->ignore();
    }
}


/**
  *   Checks if the dragged data contains a .rfc File
  *   Accepts the event if the file(s) are readable, and have the extension .rfc
  *   Ingores the event otherwise
  */
void MatrixView::dragEnterEvent(QDragEnterEvent *event)
{
    const QMimeData *mime =  event->mimeData();
    if (mime->hasUrls()){
        QList<QUrl> urls = mime->urls();
        QListIterator<QUrl> iter(urls);
        while (iter.hasNext()){

            QUrl url = iter.next();
            //Check for url
            if (url.isLocalFile()){
                QFileInfo file(url.toLocalFile());
                if (file.isFile() && file.isReadable() && file.suffix() == "rfc"){
                    //accept if at least one file is a RelaFixCode File
                    event->accept();
                    return;
                }
            }
        }
     }else{
        event->ignore();
    }
}

void MatrixView::dragMoveEvent(QDragMoveEvent *event)
{
        event->acceptProposedAction();
}

void MatrixView::dragLeaveEvent(QDragLeaveEvent *event)
{
        event->accept();
}


//#---------------------------------------------------------------------------#
//#------- PRIVATE -----------------------------------------------------------#
//#---------------------------------------------------------------------------#
void MatrixView::pinchTriggered(QPinchGesture *gesture)
{
    qDebug("pinch gesture");
    if (gesture->changeFlags()& QPinchGesture::ScaleFactorChanged){
        if (gesture->scaleFactor() > gesture->lastScaleFactor())
            this->scale(1.04, 1.04);
        else if (gesture->scaleFactor() < gesture->lastScaleFactor())
            this->scale(1/1.04, 1/1.04);
    }
}
