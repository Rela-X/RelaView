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

#include "rvapplication.h"

#include "datamanager.h"
#include "mainwindow.h"

#include <QFileOpenEvent>
#include <QEvent>

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR -------------------------------------------------------#
//#---------------------------------------------------------------------------#
RVApplication::RVApplication(int &argc, char **argv) :
    QApplication(argc, argv)
{
    //this->setGraphicsSystem("raster");
    //Init for QSettings
    this->setOrganizationDomain("fnordlab.de");
    this->setOrganizationName("Fnordlab");
    this->setApplicationName("RelaView");
    this->setApplicationVersion("1.0");
}



//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
void RVApplication::loadFromFile(const QString &file) const
{
    //get positon of the latest window
    MainWindow* w = MainWindow::lastWindow();

    DataManager::openRelaFixFile(w,file);
    qDebug("File:%s",file.toStdString().c_str());
}


//#---------------------------------------------------------------------------#
//#------- PROTECTED ---------------------------------------------------------#
//#---------------------------------------------------------------------------#
bool RVApplication::event(QEvent *e)
{
    bool eaten;
    switch (e->type()) {
    case QEvent::FileOpen:
    {
        qDebug("FileOpen event");
        QString file = static_cast<QFileOpenEvent *>(e)->file();
        this->loadFromFile(file);

        eaten = true;
        break;
    }
    default:
        eaten = QApplication::event(e);
        break;
    }
    return eaten;
}
