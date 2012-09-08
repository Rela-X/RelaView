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

#ifndef ERRORLOGWIDGET_H
#define ERRORLOGWIDGET_H

#include <QWidget>

namespace Ui {
class ErrorLogWidget;
}

QT_FORWARD_DECLARE_CLASS(QStringList)

class ErrorLogWidget : public QWidget
{
    Q_OBJECT
    
public:
    //static
    static ErrorLogWidget& instance()
    {
        static ErrorLogWidget m_errlog;
        return m_errlog;
    }
    //functions
    void addMessage(const QString& log);

private slots:
    void clearLog();
    void writeSettings();

    
private:
    //Constructor / Destructor
    explicit ErrorLogWidget(QWidget *parent = 0);
    ~ErrorLogWidget();
    //member vars
    Ui::ErrorLogWidget *ui;
};

#endif // ERRORLOGWIDGET_H
