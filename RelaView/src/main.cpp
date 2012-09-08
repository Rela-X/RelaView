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


#include <QMessageBox>
#include <QTranslator>
#include <QLibraryInfo>
#include <QLocale>

#include "rvapplication.h"
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QT_REQUIRE_VERSION(argc, argv, "4.8.0");
    RVApplication a(argc, argv);


    //Translator
    //here is a bug with system().name() It does not return
    //the right location. Instead system().uiLanguages() should be used
    //But this doesn't work with qtTranslator.load();
    //A Bug report was opened under:
    //https://bugreports.qt-project.org/browse/QTBUG-25973?page=com.atlassian.jira.plugin.system.issuetabpanels:all-tabpanel
    //Hook up qt translator
    QTranslator qtTranslator;
    QString qString = QLocale::system().uiLanguages().first();
    if (qtTranslator.load(":/lang/qt_"+qString)){
        a.installTranslator(&qtTranslator);
        qDebug("qt_%s Translation successfully loaded",qString.toStdString().c_str());
    }else{
        qDebug("Error while loading Qt translation: %s. Switching to en", qString.toStdString().c_str());
    }

    //App translator
    QTranslator appTranslator;
    if (appTranslator.load(":/lang/RelaView_" + qString)){ //change to automatic locatisation
        qDebug("RelaView_%s Translation successfully loaded",qString.toStdString().c_str());
        a.installTranslator(&appTranslator);
    }else{
        qDebug("Error while loading RelaView translation: %s", qString.toStdString().c_str());
    }



    MainWindow* w = new MainWindow();
    w->show();

    //Argument handling
    if (argc > 1){
        for (int i = 1; i < argc; i++){
            a.loadFromFile(argv[i]);
        }
    }

    return a.exec();
}

