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

#ifndef DATAMANAGER_H
#define DATAMANAGER_H


#include <QList>
#include <QStringList>

class RelationData;
class DomainData;
class MainWindow;

extern "C"
{
#include "defines.h"
}

extern "C" void createRelation(RF_RELATION* c_relation);
extern "C" void createDomain(RF_DOMAIN* c_domain);
extern "C" void appendError(char* str);


class DataManager
{
public:
    static void openRelaFixFiles(MainWindow *window, const QStringList* files);
    static void openRelaFixFile(MainWindow* window, const QString &file);
    static void appendError(const QString &s);
    static DomainData* domainForString(const QString &s);
    static void showErrors();

    static QList<RelationData*>& loadingList(){
        static QList<RelationData*> m_relData;
        return m_relData;
    }
    static QList<DomainData*>& domains(){
        static QList<DomainData*> m_domain_list;
        return m_domain_list;
    }

    static QStringList& errors(){
        static QStringList m_errors;
        return m_errors;
    }


private:
    //no instance allowed. static only
    DataManager();
    ~DataManager();
};



#endif // DATAMANAGER_H
