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

#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>

class MainWindow;
QT_FORWARD_DECLARE_CLASS(QColor)

namespace Ui {
class Preferences;
}

class Preferences : public QDialog
{
    Q_OBJECT
    
public:
    explicit Preferences(QWidget *parent = 0);
    ~Preferences();
    void showPreferences();
    //static
    static Preferences& instance()
    {
        static Preferences m_pref;
        return m_pref;
    }

private:
    Ui::Preferences *ui;
    QColor m_elementColor;
    QColor m_borderColor;
    //functions
    void loadSettings();

signals:
    void elementColorChanged(QColor color);
    void borderColorChanged(QColor color);
    void diagonalLineChanged(bool state);

private slots:
    void on_checkBox_stateChanged(int arg1);
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_reset_clicked();
};

#endif // PREFERENCES_H
