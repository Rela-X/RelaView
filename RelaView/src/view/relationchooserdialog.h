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

#ifndef RELATIONCHOOSERDIALOG_H
#define RELATIONCHOOSERDIALOG_H

#include <QDialog>

class MainWindow;

namespace Ui {
class RelationChooserDialog;
}

class RelationChooserDialog : public QDialog
{
    Q_OBJECT
    
public:
    //Constructor / Destructor
    explicit RelationChooserDialog(QWidget *parent = 0);
    ~RelationChooserDialog();
    //static function
    static void performUserChoice(MainWindow* window);

private slots:
    void setAllWidgetsChecked(bool);

private:
    //Functions
    void setupChooser();
    void clearUnselectedRelations();
    void generateWidgetItem(QString& name);
    //Member Variables
    Ui::RelationChooserDialog *ui;
};

#endif // RELATIONCHOOSERDIALOG_H
