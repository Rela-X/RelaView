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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QApplication>

QT_FORWARD_DECLARE_CLASS(QUndoStack)
QT_FORWARD_DECLARE_CLASS(QGraphicsScene)
QT_FORWARD_DECLARE_CLASS(QSignalMapper)
QT_FORWARD_DECLARE_CLASS(QColor)
QT_FORWARD_DECLARE_CLASS(QGraphicsLineItem)
class PropertiesWidget;
class RelationData;
class MatrixElement;
class EditRelationName;
class EditNameCommand;
class AbstractProperty;
class SequenceConverter;

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    //Constructor / Destructor
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //static functions
    static void newWindowWithRelation(RelationData* relData);
    static MainWindow* lastWindow();
    static QList<MainWindow* >& windows(){
        static QList<MainWindow* > window;
        return window;
    }
    static void removeWindow(MainWindow* w)
    {
        MainWindow::windows().removeOne(w);
        if (MainWindow::windows().size() == 0){
            QApplication::closeAllWindows();
            QApplication::exit();
        }
    }

    //Member functions
    void setRelation(RelationData* rel);
    const RelationData* relation() const;
    bool isRelationData() const;
    void calculateSize() const;
    bool isUntitled() const{ return this->m_isUntitled;}
    void statusBarMessage(const QString &s);
    //friend classes
    friend class EditRelationName;
    friend class EditNameCommand;

protected:
    void closeEvent(QCloseEvent *qce);
    void resizeEvent(QResizeEvent *qre);

private slots:
    void aboutBox();
    void open();
    void duplicate();
    void newRelation();
    void newDomain();
    void editName();
    bool saveRelation();
    void saveDomain();
    void exportAs();
    void exit();
    void print();
    void preferences();
    void propertiesList();
    void errorLog();
    void relationNameChanged();
    void relationChanged();
    void elementColorChanged(QColor color);
    void borderColorChanged(QColor color);
    void diagonalLineChanged(bool state);
    void handlePropertyConflict();
    void zoomIn();
    void zoomOut();
    void fitToScreen();
    void equivalentSort();
    void resetOrder();
    void drawerVisibilityChanged(bool isVisible);
    void elementMousePress(MatrixElement* ele);
    void elementHoverEnter(MatrixElement* ele);
    void modifyFlagChanged(bool clean);
    void setRelationProperty(const QString& name);
    void executeOperation(const QString& name);
    void updateButtons();
    void on_actionShow_GLMatrix_triggered();

signals:
    void triggerPropertyButton(const QString& name);
    void triggerOperationButton(const QString& name);

private:
    //Functions
    void init();
    void initMembers();
    void setupMenubar();
    void configure();
    void drawRelation();
    void resizeRelation();
    void setLabel(QString relation, QString domain1, QString domain2);
    void enableButtons();
    bool shouldBeSaved();
    void readSettings();
    void writeSettings();
    void equSortColumn(RelationData* rel, int column);
    void equSortRow(RelationData* rel, int row);

    //Member variables
    //Ui
    Ui::MainWindow *ui;
    QGraphicsScene* m_graphicsScene;
    PropertiesWidget *m_propertiesWidget;
    QDockWidget* m_drawer;
    QList<MatrixElement*> m_elements;
    //Actions
    QSignalMapper *m_propertyMapper;
    QSignalMapper* m_operationMapper;
    QAction* m_editNameAction;
    //View / Sequence / Sorting
    SequenceConverter *m_sequenceConverter;
    //Data
    RelationData* m_relationData;
    QUndoStack* m_stack;
    bool m_isUntitled;
    //Matrix Items
    QGraphicsLineItem* m_diagonal;

};

#endif // MAINWINDOW_H
