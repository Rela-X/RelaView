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

#ifndef PROPERTIESWIDGET_H
#define PROPERTIESWIDGET_H

#include <QWidget>

QT_FORWARD_DECLARE_CLASS(QListWidgetItem)
class RelationData;
class AbstractProperty;

namespace Ui {
class PropertiesWidget;
}

class PropertiesWidget : public QWidget
{
    Q_OBJECT
    
public:
    //Constructor
    explicit PropertiesWidget(QWidget *parent = 0);
    ~PropertiesWidget();
    //Methods
    void setRelationData(RelationData* relationData);
    int checkedCount() const;
    QStringList checkedList() const;

private slots:
    void refreshProperty();

signals:
    void checkStateChanged();

private:
    //Methods
    void    init();
    void    generateWidgetItem(AbstractProperty* s);
    void    setWidgetItemFlags(AbstractProperty* prop, QListWidgetItem* qlwi);
    //Data member
    Ui::PropertiesWidget *ui;
    QPalette palette;
    RelationData* m_relationData;
};

#endif // PROPERTIESWIDGET_H
