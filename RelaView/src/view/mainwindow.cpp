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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "setpropertiescommand.h"
#include "setpropertycommand.h"
#include "datamanager.h"
#include "matrixelement.h"
#include "toggleelementcommand.h"
#include "editrelationname.h"
#include "preferences.h"
#include "abstractproperty.h"
#include "relationdata.h"
#include "propertieswidget.h"
#include "abstractproperty.h"
//#include "pixmapmatrix.h"
#include "newrelationdialog.h"
#include "abstractoperation.h"
#include "unaryoperation.h"
#include "binaryoperation.h"
#include "binaryoperationdialog.h"
#include "errorlogwidget.h"
#include "modificationfactory.h"
#include "binaryoperationcommand.h"
#include "unaryoperationcommand.h"
#include "domainchooserdialog.h"
#include "sequenceconverter.h"
#include "newdomaindialog.h"
#include "swapdialog.h"

#include <QAction>
#include <QFileDialog>
#include <QUndoStack>
#include <QString>
#include <QDockWidget>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QSettings>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
//#include <QGLWidget>
#include <QPixmap>
#include <QImageWriter>
#include <QMenuBar>
#include <QSignalMapper>
#include <QCloseEvent>
#include <QDebug>
#include <QTransform>

//#---------------------------------------------------------------------------#
//#------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------#
//#---------------------------------------------------------------------------#
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug("MainWindow Constructor");
    ui->setupUi(this);

    this->initMainWindow();
    this->readSettings();
}


MainWindow::~MainWindow()
{
    MainWindow::removeWindow(this);
     qDebug("MainWindow Destructor");
    delete ui;
}



//#---------------------------------------------------------------------------#
//#------- STATIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
void MainWindow::newWindowWithRelation(RelationData *relData)
{

    //get positon of the latest window
    QList<MainWindow*>& wi = MainWindow::windows();
    MainWindow* other = 0;
    MainWindow* l = MainWindow::lastWindow();


    for (int i = 0; i < wi.size(); i++){
        if (wi.at(i)->isUntitled()){
            other = wi.at(i);
            break;
        }
    }


    if (other == 0){
        other = new MainWindow();
        other->show();
    }

    other->calculateSize();
    other->move(l->x()+40, l->y()+40);
    other->setRelation(relData);
    other->show();
}

MainWindow* MainWindow::lastWindow()
{
    QList<MainWindow*>& wi = MainWindow::windows();

    if (wi.isEmpty())
        return new MainWindow();
    else
        return wi.last();
}


//#---------------------------------------------------------------------------#
//#------- PUBLIC ------------------------------------------------------------#
//#---------------------------------------------------------------------------#
void MainWindow::setRelation(RelationData* rel)
{
    RelationData* old = this->m_relationData;

    if (rel){
        this->m_relationData = rel;
        this->m_relationData->setParent(this);
        this->m_propertiesWidget->setRelationData(rel); //maybe signal
        //connections
        connect(this->m_relationData, SIGNAL(relationNameChanged()),
                this, SLOT(relationNameChanged()));
        connect(this->m_relationData, SIGNAL(relationChanged()),
                this, SLOT(relationChanged()));

        this->m_sequenceConverter = new SequenceConverter(rel->width(), rel->height(), this);
        connect(this->m_sequenceConverter, SIGNAL(sequenceChanged()),
                this, SLOT(relationChanged()));

        this->m_isUntitled = false;
        this->drawRelation();
        this->enableButtons();

        //if old realtion is exist delete it
        if (old)
            delete old;
    }
}

const RelationData* MainWindow::relation() const
{
    return this->m_relationData;
}


bool MainWindow::isRelationData() const
{
    return (this->m_relationData != 0) ? true : false;
}


void MainWindow::calculateSize() const
{
    this->layout()->invalidate();
}


void MainWindow::statusBarMessage(const QString &s)
{
    ui->statusBar->showMessage(s ,2000);
}




//#---------------------------------------------------------------------------#
//#------- PROTECTED ---------------------------------------------------------#
//#---------------------------------------------------------------------------#
void MainWindow::closeEvent(QCloseEvent* qce)
{
    if (this->shouldBeSaved()){
        writeSettings();
        qce->accept();
    }else{
        qce->ignore();
    }
}


void MainWindow::resizeEvent(QResizeEvent *)
{
    this->writeSettings();
}



//#---------------------------------------------------------------------------#
//#-------- PRIVATE SLOTS ----------------------------------------------------#
//#---------------------------------------------------------------------------#
void MainWindow::aboutBox()
{
    QMessageBox about(this);
    about.setStandardButtons(QMessageBox::Close);
    about.setTextFormat(Qt::RichText);
    QString text = QString("<h1>RelaView</h1> \
            <p style='font-weight:normal;font-size:14pt'>Version %1 (%3)</p> \
            <p style='font-weight:normal;font-size:11pt'>RelaView is an open-source cross-platform \
            relation viewer developed by Andreas Schmitz in the context of his bachelor thesis in 2012.\
            RelaView is published under the GNU Lesser General Public License Version 3 (LGPL).</p> \
            <p style='font-weight:normal;font-size:11pt'>RelaView dynamically links to unmodified Qt Library %2. The Qt Library is licensed \
            under the LGPL 2.1 with Nokia Qt LGPL exception 1.1. You can obtain the Qt library from http://qt.nokia.com. </p> \
            <p style='font-weight:normal;font-size:11pt'>RelaView uses the RelaFix library developed by Peter Berger.<p> \
            <p style='font-weight:normal;font-size:9pt'>RelaView Copyright (C) 2012 Andreas Schmitz.<br> \
            RelaFix Copyright (C) 2011-2012 Peter Berger.<br> \
            Qt Library Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies)</p>")
            .arg(QApplication::applicationVersion())
            .arg(QString(qVersion()))
            .arg(BUILDDATE);

    about.setText(text);
    QSpacerItem* horizontalSpacer = new QSpacerItem(600,
                                                    0,
                                                    QSizePolicy::Minimum,
                                                    QSizePolicy::Expanding);
    QGridLayout* layout = static_cast<QGridLayout*>(about.layout());
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());

    QPixmap icon(":/img/icon.png");
    about.setIconPixmap(icon.scaled(QSize(180,180), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    about.exec();
}




void MainWindow::open()
{
    // SHEETS for QFileDialog
    // Is outcommented due to a bug in QT. More infos under:
    // https://bugreports.qt-project.org/browse/QTBUG-21142?page=com.googlecode.jira-suite-utilities:transitions-summary-tabpanel
/*
    QFileDialog dialog(this);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setNameFilter(tr("RelaFix File (*.rfc)"));
    dialog.setViewMode(QFileDialog::List); //Alternative: QFileDialog::Detail
    dialog.setDirectory(QDir::homePath());


    QStringList files;
    if (dialog.exec() == QFileDialog::Accepted){
        files = dialog.selectedFiles();
        //files.first() because only one file is selectable
        QString filename = files.first();
        qDebug("filename: %s", filename.toStdString().c_str());
        DataManager::getInstance().openRelaFixFile(this, filename);
    }
*/
    QSettings settings;
    QString openPath = settings.value("MainWindow/lastOpenPath", QDir::homePath()).toString();
    QStringList filenames = QFileDialog::getOpenFileNames(
                this,
                tr("Open File"),
                openPath,
                tr("RelaFix File (*.rfc)"));

    if(filenames.isEmpty())
        return;

    QDir dir(filenames.first());
    settings.setValue("MainWindow/lastOpenPath", dir.absolutePath());

    DataManager::openRelaFixFiles(this, &filenames);
}


void MainWindow::duplicate()
{
    MainWindow::newWindowWithRelation(this->m_relationData->cloneRelation());
}


void MainWindow::newRelation()
{
    NewRelationDialog::performNewRelation();
}



void MainWindow::newDomain()
{
    NewDomainDialog::performNewDomain();
}



void MainWindow::editName()
{
    if (this->m_relationData)
        EditRelationName::edit(this);
}


bool MainWindow::saveRelation()
{
    if (!this->m_relationData)
        return true;

    QSettings settings;
    QString savePath = settings.value("MainWindow/lastSavePath", QDir::homePath()).toString();
    QString filepath = QFileDialog::getSaveFileName(this,
                                                    tr("Save as..."),
                                                    savePath,
                                                    tr("Files (*.rfc)"));

    if (filepath.isEmpty())
        return false;

    QFile file(filepath);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,
                             tr("Warning"),
                             tr("Error while exporting relation %1:\n%2.")
                             .arg(this->m_relationData->name()).arg(file.errorString()));
        file.close();
        return false;
    }


    //generate domain(s)
    QString domain1Elements;
    unsigned int domain1Value = this->m_relationData->domain1Count();
    unsigned int domain2Value = this->m_relationData->domain2Count();
    for (unsigned int i = 0; i < domain1Value-1; i++){
        domain1Elements.append(QString("%1, ")
                               .arg(this->m_relationData->domain1Element(i)));
    }
    domain1Elements.append(QString("%1")
                           .arg(this->m_relationData->domain1Element(domain1Value-1)));

    QString domainString = QString("DOMAIN %1 AS {%2};\n").
            arg(this->m_relationData->domain1Name()).
            arg(domain1Elements);

    //second domain if not homogeneous!
    if (this->m_relationData->domain1Name() != this->m_relationData->domain2Name()){
        QString domain2Elements;
        for (unsigned int i = 0; i < domain2Value-1; i++){
            domain2Elements.append(QString("%1, ").arg(this->m_relationData->domain2Element(i)));
        }
        domain2Elements.append(QString("%1").arg(this->m_relationData->domain2Element(domain2Value-1)));

        QString domainAppend = QString("DOMAIN %1 AS {%2};\n").
                    arg(this->m_relationData->domain2Name()).
                    arg(domain2Elements);
        domainString.append(QString(domainAppend));
    }

    //Generates the relation table
    QString relationTable = "\t";
    for (unsigned int i = 0; i < domain2Value; i++){
        relationTable.append(QString("%1 ").arg(this->m_relationData->domain2Element(i)));
    }
    relationTable.append(",\n");

    for (unsigned int i = 0; i < domain1Value; i++){
        relationTable.append(QString("%1:\t").arg(this->m_relationData->domain1Element(i)));
        for (unsigned int j = 0; j < domain2Value; j++){
            relationTable.append(QString("%1 ").arg(this->m_relationData->tableBit(j,i)));
        }
        relationTable.append(",\n");
    }
    int toRemove = relationTable.lastIndexOf(",");
    relationTable.remove(toRemove-1, relationTable.length());


    QString relation = QString("RELATION %1: %2 -> %3 AS TABLE(\n%4);\n")
            .arg(m_relationData->name())
            .arg(m_relationData->domain1Name())
            .arg(m_relationData->domain2Name())
            .arg(relationTable);


    QString makeVisibile = QString("%1;")
            .arg(m_relationData->name());

    QTextStream output(&file);
    output << domainString << relation << makeVisibile;

    file.close();
    //Undow stack cleanState which emits cleanChanged().
    //Connect this signal to a member function which alters the flag
    this->m_stack->setClean();
    this->setWindowModified(false);
    ui->statusBar->showMessage(tr("File saved"),2000);

    //save last save path to settings
    QDir dir(filepath);
    settings.setValue("MainWindow/lastSavePath", dir.absolutePath());

    return true;
}


void MainWindow::saveDomain()
{
    DomainChooserDialog::performUserChoice(this);
}


void MainWindow::exportAs()
{
    if (!this->m_relationData)
        return;

    //All writable formats
    QString fileFormats = "(";
    for (int i = 0; i < QImageWriter::supportedImageFormats().count(); i++) {
            fileFormats += "*.";
            fileFormats += QString(QImageWriter::supportedImageFormats().at(i)).toLower();
            fileFormats += " ";
    }
    fileFormats += ")";

    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Export Image"),
                                                    QDir::homePath(),
                                                    tr("Images (*.png *.jpg *.tiff *.bmp)"));

    if (filename.isEmpty())
        return;

    QFile file(filename);
    if (!file.open(QFile::WriteOnly)){
        QMessageBox msg(this);
        msg.setWindowModality(Qt::WindowModal);
        msg.setText(tr("Image Export failed!"));
        msg.setIcon(QMessageBox::Warning);
        msg.setInformativeText(tr("File not writeable!"));
        msg.exec();
        return;
    }

    //Prepare pixmap render everything and save as file
    int width = ui->graphicsView->sceneRect().width();
    int height = ui->graphicsView->sceneRect().height();
    QPixmap pixmap(width, height);
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);
    painter.setPen(Qt::white);
    painter.setBackground(Qt::SolidPattern);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    ui->graphicsView->scene()->render(&painter);

    painter.end();
    pixmap.save(filename);
}


void MainWindow::exit()
{
    if (shouldBeSaved()){
        QApplication::closeAllWindows();
        QApplication::exit();
    }
}


void MainWindow::print()
{
    QPrinter printer;
     if (QPrintDialog(&printer,this).exec() == QDialog::Accepted) {
         QPainter painter(&printer);
         const QFont normalFont = painter.font();
         QFont headline(normalFont);
         headline.setPointSize(20);
         painter.setFont(headline);
         painter.drawText(QRect(0,0,printer.width(),30), this->m_relationData->name());
         painter.setFont(normalFont);
         unsigned int i = 0;
         unsigned int xOffset = 0;
         unsigned int yOffset = 30;

         foreach (AbstractProperty* p, ModificationFactory::instance().properties()){
             if (!p->isRelationProperty(this->m_relationData))
                 continue;
             painter.drawText(QRect(xOffset, 30+yOffset, 300, 30),p->name());
             yOffset += 15;
             i++;
             if (i%6 == 0){
                 xOffset += 150;
                 yOffset = 30;
             }
         }
         if (i != 0)
             painter.drawText(QRect(0,40, 300, 30), tr("Properties:"));

         int y = (i < 6) ? ((i*20)+50) : 170;
         this->m_graphicsScene->render(&painter, QRect(0,y, printer.width(), printer.height()));
     }
}


void MainWindow::preferences()
{
    Preferences::instance().showPreferences();
}


void MainWindow::propertiesList()
{
    if (!m_drawer->isVisible()){
        ui->actionToggle_Properties->setText(tr("Hide Properties"));
        m_drawer->show();
    }else{
        ui->actionToggle_Properties->setText(tr("Show Properties"));
        m_drawer->hide();
    }
}

void MainWindow::errorLog()
{
    ErrorLogWidget& log = ErrorLogWidget::instance();
    if (log.isVisible())
        log.hide();
    else
        log.show();
}


/**
  * will be triggered by RelationData if the relation changes
  */
void MainWindow::relationNameChanged()
{
    this->setWindowTitle(this->m_relationData->name());
    this->setLabel(this->m_relationData->name(),
                   this->m_relationData->domain1Name(),
                   this->m_relationData->domain2Name());
}


/** Redraws the relation after somethin has changed.
 *  Uses the sequenceConverter to convert the coordinates if they
 *  were changed by a sorting algorithm or the user
 * @brief MainWindow::relationChanged
 */
void MainWindow::relationChanged()
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < m_elements.count(); i++){
        MatrixElement* ele = m_elements.at(i);
        x = m_sequenceConverter->projectedX(ele->xCoord());
        y = m_sequenceConverter->projectedY(ele->yCoord());

        ele->setToolTip(QString("(%1, %2)")
                        .arg(this->m_relationData->domain1Element(y))
                        .arg(this->m_relationData->domain2Element(x)));


        int bit = m_relationData->tableBit(x, y);
        if (bit == 1)
            ele->setElementVisible();
        else if (bit == 0)
            ele->setElementInvisible();
    }
    this->updateButtons();
    ui->graphicsView->viewport()->update();
}


void MainWindow::elementColorChanged(QColor color)
{
    if (!this->m_relationData)
        return;

    qDebug("element color changed");

    QList<QGraphicsItem*> list = ui->graphicsView->scene()->items();

    QGraphicsItem* item;
    MatrixElement* ele;

    QListIterator<QGraphicsItem*> iter(list);
    while (iter.hasNext()){
        item = iter.next();
        ele = dynamic_cast<MatrixElement*>(item);

        if(ele)
            ele->setBrush(QBrush(color));

    }
}

void MainWindow::borderColorChanged(QColor color)
{
    if (!this->m_relationData)
        return;

    qDebug("element color changed");

    QList<QGraphicsItem*> list = ui->graphicsView->scene()->items();

    QGraphicsItem* item;
    MatrixElement* ele;

    QListIterator<QGraphicsItem*> iter(list);
    while (iter.hasNext()){
        item = iter.next();
        ele = dynamic_cast<MatrixElement*>(item);

        if(ele)
            ele->setPen(QPen(color));

    }
}


void MainWindow::diagonalLineChanged(bool state)
{
    if (!this->m_relationData || !this->m_diagonal)
        return;

    if (this->m_relationData->height() != this->m_relationData->width())
        return;

    qDebug("DiagonalLineChanged");
    this->m_diagonal->setVisible(state);
}


void MainWindow::handlePropertyConflict()
{
    QString err = this->m_relationData->name() + ": " +
            tr("Properties are in conflict with each other.");
    ui->statusBar->showMessage(err);
    ErrorLogWidget::instance().addMessage(err);
}



void MainWindow::zoomIn()
{
    ui->graphicsView->scale(1.2, 1.2);
}

void MainWindow::zoomOut()
{
    ui->graphicsView->scale(1/1.2, 1/1.2);
}



void MainWindow::fitToScreen()
{
    if (!this->m_relationData){
        qDebug("Can't fitToScreen. No relation loaded!");
        return;
    }

    qreal sX = ui->graphicsView->viewport()->rect().width() / this->m_graphicsScene->width();
    qreal sY = ui->graphicsView->viewport()->rect().height() /  this->m_graphicsScene->height();

    ui->graphicsView->resetTransform();
    ui->graphicsView->scale(sX, sY);

}


void MainWindow::equivalentSort()
{
    const AbstractProperty* equ = ModificationFactory::instance().
            propertyForId(ModificationFactory::EQUIVALENT);

    if (equ == 0)
        return;

    if (equ->isRelationProperty(this->m_relationData)){

        //init values
        int height = this->m_relationData->height();
        int dia = 0;

        this->m_relationData->pauseRelationRedrawing();
        //run along the diagonal
        while (dia < height){
            equSortColumn(this->m_relationData, dia);
            equSortRow(this->m_relationData, dia);
            dia++;
        }
        this->m_relationData->resumeRelationRedrawing();
        this->m_relationData->emitRelationChanged();
    }
}


void MainWindow::swap()
{
    qDebug() << "MainWindow swap";
    SwapDialog::swap(this);
}


void MainWindow::resetOrder()
{
    this->m_sequenceConverter->resetSequence();
}


void MainWindow::drawerVisibilityChanged(bool isVisible)
{
    if (isVisible)
        ui->actionToggle_Properties->setText(tr("Hide Properties"));
    else
        ui->actionToggle_Properties->setText(tr("Show Properties"));
}




/** Reaction to the click on a Matrixelement.
 *  Uses the sequenceConverter to get the right coordinates
 *  in the case they were rearranged by a sorting algorithm
 *  or the user
 * @brief MainWindow::elementMousePress
 * @param ele
 */
void MainWindow::elementMousePress(MatrixElement* ele)
{
    int x = this->m_sequenceConverter->projectedX(ele->xCoord());
    int y = this->m_sequenceConverter->projectedY(ele->yCoord());

    if (this->m_propertiesWidget->checkedCount() > 0){

        RelationData* clone = this->m_relationData->cloneRelation();
        QStringList list = this->m_propertiesWidget->checkedList();

        bool fill = (this->m_relationData->tableBit(x, y)) ? false : true;

        //test for conflict
        //click on matrix
        int toggleBit = (clone->tableBit(x, y) == 1) ? 0 : 1;
        clone->setTableBit(x, y, toggleBit);

        //set properties
        for (int i = 0; i < list.count(); i++){
            const AbstractProperty* p = ModificationFactory::instance().
                    propertyForName(list.at(i));
            if(!p->isRelationProperty(clone))
                p->setRelationProperty(clone, fill);
        }

        //test for conflicts
        bool conflict = false;
        for (int i = 0; i < list.count(); i++){
            const AbstractProperty* p = ModificationFactory::instance().
                    propertyForName(list.at(i));
            if(!p->isRelationProperty(clone))
                conflict = true;
        }
        //tidy up
        delete clone;
        clone = 0;

        if (conflict)
            this->handlePropertyConflict();
        else
            m_stack->push(new SetPropertiesCommand(this->m_relationData, list,
                                              fill, x, y));
    }else{
        m_stack->push(new ToggleElementCommand(this->m_relationData, x, y));
    }
}


/** Displays the element the mouse hovers over.
 *  Uses the sequenceConverter to get the right coordinates
 *  in the case they were rearranged by a sorting algorithm
 *  or the user
 * @brief MainWindow::elementHoverEnter
 * @param ele
 */
void MainWindow::elementHoverEnter(MatrixElement* ele)
{
    uint x = this->m_sequenceConverter->projectedX(ele->xCoord());
    uint y = this->m_sequenceConverter->projectedY(ele->yCoord());

    ui->statusBar->showMessage(QString("Element:%1 %2")
                               .arg(this->m_relationData->domain1Element(y))
                               .arg(this->m_relationData->domain2Element(x)), 3000);
}



void MainWindow::modifyFlagChanged(bool clean)
{
    //qDebug("clean stated changed %s", (clean)? "true" : "false");
    this->setWindowModified(!clean);
}


void MainWindow::setRelationProperty(const QString& name)
{
    qDebug("setRelationProperty:%s", name.toStdString().c_str());
    const AbstractProperty* p = ModificationFactory::instance().propertyForName(name);
    if(p)
        m_stack->push(new SetPropertyCommand(this->m_relationData,
                                             p->name(),
                                             ui->actionFill->isChecked()));
}


void MainWindow::executeOperation(const QString& name)
{
    qDebug("execute Operation:%s", name.toStdString().c_str());
    AbstractOperation* op = ModificationFactory::instance().operationForName(name);

    UnaryOperation* un = qobject_cast<UnaryOperation*>(op);
    if (un){
        this->m_stack->push(new UnaryOperationCommand(un, this->m_relationData));
        return;
    }

    BinaryOperation* bi = qobject_cast<BinaryOperation*>(op);
    if(bi){
        const RelationData* rel2 = BinaryOperationDialog::performOperationWith(this);
        if (rel2 != 0)
            this->m_stack->push(new BinaryOperationCommand(bi, this->m_relationData, rel2));
        return;
    }

}


void MainWindow::updateButtons()
{
    if (!this->m_relationData)
        return;

    AbstractProperty* equ = ModificationFactory::instance().propertyForId(ModificationFactory::EQUIVALENT);
    if (equ != 0){
        if (equ->isRelationProperty(this->m_relationData)){
            ui->actionEquivalent_Sort->setEnabled(true);
        }else{
            ui->actionEquivalent_Sort->setEnabled(false);
        }
    }



    foreach (AbstractProperty* p, ModificationFactory::instance().properties()){
        const QObjectList& list = ui->menuProperties->children();
        foreach (QObject* o, list){
            if (o->objectName() == p->name()){
                QAction* a = qobject_cast<QAction*>(o);

                if (!p->isRelationProperty(this->m_relationData)){ //property not fulfilled

                    if (this->m_relationData->propertyType() == AbstractProperty::homogeneous){
                        //homogenous activate all
                        a->setEnabled(true);
                    } else if(this->m_relationData->propertyType() == p->propertyType()){
                        //inhomogenous only if the type is inhomogenous
                        a->setEnabled(true);
                    }else{
                        a->setEnabled(false);
                    }
                }else{
                    a->setEnabled(false);
                }
            }
        }
    }

}


void MainWindow::on_actionShow_GLMatrix_triggered()
{
    if (!this->m_relationData)
        return;

    //PixmapMatrix* matrix = new PixmapMatrix();
    //matrix->setRelation(this->m_relationData);
    //matrix->show();

}


//#---------------------------------------------------------------------------#
//#------- PRIVATE -----------------------------------------------------------#
//#---------------------------------------------------------------------------#
void MainWindow::initMainWindow()
{
    this->initMembers();
    this->setupMenubar();
    this->configure();
}


void MainWindow::initMembers()
{
    //open properties panel in a drawer (osx) / a new window (win/linux)
    //due to a problem with Qt::Drawer with windows 7
#ifdef Q_WS_MAC
    m_drawer = new QDockWidget(tr("Properties"), this, Qt::Drawer);
#else
    m_drawer = new QDockWidget(tr("Properties"), this);
#endif
    m_propertiesWidget = new PropertiesWidget(m_drawer);
    this->m_graphicsScene = new QGraphicsScene(ui->graphicsView);
    this->m_stack = new QUndoStack(this);
    ui->graphicsView->setScene(m_graphicsScene);

    //object names for save/restore State
    this->m_propertiesWidget->setObjectName("propertieWidget");
    this->m_graphicsScene->setObjectName("graphicsScene");
    this->m_drawer->setObjectName("drawer");

    this->m_propertyMapper = new QSignalMapper(this);
    this->m_operationMapper = new QSignalMapper(this);

    this->m_relationData = 0;
    this->m_isUntitled = true;
}


void MainWindow::setupMenubar()
{
    QAction* action;
    action = m_stack->createUndoAction(this, tr("&Undo"));
    action->setShortcut(QKeySequence::Undo);
    ui->menuEdit->addAction(action);

    action = m_stack->createRedoAction(this, tr("&Redo"));
    action->setShortcut(QKeySequence::Redo);
    ui->menuEdit->addAction(action);

    ui->menuEdit->addSeparator();

    this->m_editNameAction = ui->menuEdit->addAction(tr("Edit Name"));
    this->m_editNameAction->setEnabled(false);
    connect(this->m_editNameAction, SIGNAL(triggered()), this, SLOT(editName()));

    //other shortucts
    ui->actionOpen->setShortcut(QKeySequence::Open);
    ui->actionMatrix_Fit_to_Screen->setShortcut(Qt::CTRL+Qt::Key_0);

    //create property buttons and signalmapping
    foreach (AbstractProperty* p, ModificationFactory::instance().properties()){
        QAction* button = new QAction(ui->menuProperties);
        button->setObjectName(p->name());
        button->setText(p->displayText());
        button->setEnabled(false);
        connect(button, SIGNAL(triggered()), this->m_propertyMapper, SLOT(map()));
        this->m_propertyMapper->setMapping(button, p->name());
        ui->menuProperties->addAction(button);
    }

    connect(this->m_propertyMapper, SIGNAL(mapped(const QString &)),
            this, SIGNAL(triggerPropertyButton(const QString&)));

    connect(this, SIGNAL(triggerPropertyButton(QString)),
            this, SLOT(setRelationProperty(QString)));


    //Same thing for relation buttons
    QList<AbstractOperation::OperationType> types;
    types.append(AbstractOperation::unary);
    types.append(AbstractOperation::binary);

    for (int i = 0; i < types.size(); i++){
        foreach (AbstractOperation* o, ModificationFactory::instance().operations()){
            if (o->operationType() != types.at(i))
                continue;
            QAction* button = new QAction(ui->menuRelation);
            button->setObjectName(o->name());
            button->setText(o->displayText());
            button->setEnabled(false);
            connect(button, SIGNAL(triggered()), this->m_operationMapper, SLOT(map()));
            this->m_operationMapper->setMapping(button, o->name());
            ui->menuRelation->addAction(button);
        }
        if (i < types.size()-1)
            ui->menuRelation->addSeparator();
    }

    connect(this->m_operationMapper, SIGNAL(mapped(const QString &)),
            this, SIGNAL(triggerOperationButton(const QString&)));

    connect(this, SIGNAL(triggerOperationButton(QString)),
            this, SLOT(executeOperation(QString)));
}



void MainWindow::configure()
{
    //Look and Feel
    QMainWindow::setUnifiedTitleAndToolBarOnMac(true);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setAcceptDrops(true);

    //standard text
    this->setLabel(tr("Relation"), tr("Domain"), tr("Domain"));

    //Size policy for resizing

    //Init properties widget and drawer
    m_drawer->setAllowedAreas(Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);
    this->addDockWidget(Qt::RightDockWidgetArea,m_drawer);
    m_drawer->setWidget(m_propertiesWidget);
    m_drawer->hide();
    //connect it to the MainWindow
    connect(m_drawer, SIGNAL(visibilityChanged(bool)),
            this, SLOT(drawerVisibilityChanged(bool)));
    connect(m_propertiesWidget, SIGNAL(checkStateChanged()),
            this, SLOT(updateButtons()));

    //connect mainwindow to preferences
    Preferences& pref = Preferences::instance();
    connect(&pref, SIGNAL(elementColorChanged(QColor)), this, SLOT(elementColorChanged(QColor)));
    connect(&pref, SIGNAL(borderColorChanged(QColor)), this, SLOT(borderColorChanged(QColor)));
    connect(&pref, SIGNAL(diagonalLineChanged(bool)), this, SLOT(diagonalLineChanged(bool)));

    //Tooblar
    ui->toolBar->setFixedHeight(22);

    //GraphicsView
    //ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    //ui->graphicsView->setViewport(new QGLWidget());
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate); //try other update modes

    //connect stack
    connect(this->m_stack, SIGNAL(cleanChanged(bool)), this, SLOT(modifyFlagChanged(bool)));

    //add to MainWindow list
    MainWindow::windows().append(this);
}


/** Generates the MatrixElements and adds them to the MatrixView
 *  Never call yourself. Should only be called once within setRelation(*)
 * @brief MainWindow::drawRelation
 */
void MainWindow::drawRelation()
{
    if (!this->m_relationData)
        return;

    Q_CHECK_PTR(this->m_relationData);


    //set the relation and domain names
    this->setWindowTitle(this->m_relationData->name());
    this->setLabel(this->m_relationData->name(),
                   this->m_relationData->domain1Name(),
                   this->m_relationData->domain2Name());


    //maybe only clear on new load and otherwise translate / resize the elements
    this->m_graphicsScene->clear();


    QGraphicsView* gv = ui->graphicsView;
    int width = gv->viewport()->width();
    int height = gv->viewport()->height();
    QSettings settings;
    QColor elementColor = settings.value("MainWindow/elementColor", QColor(Qt::black)).value<QColor>();
    QColor borderColor = settings.value("MainWindow/borderColor", QColor(Qt::black)).value<QColor>();


    this->m_graphicsScene->setSceneRect(0, 0, width, height);


    int heightCount =  this->m_relationData->height();
    int widthCount = this->m_relationData->width();


    double hdiff = (double) height / (double) heightCount;
    double wdiff = (double) width / (double) widthCount;


    //paints the raster
    double y = hdiff;
    for (int i = 1; i <= heightCount-1; i++){
        this->m_graphicsScene->addLine(0,y, width, y, QPen(Qt::lightGray));
        y += hdiff;

    }
    double x = wdiff;
    for (int i = 1; i <= widthCount-1; i++){
        this->m_graphicsScene->addLine(x,0, x, height, QPen(Qt::lightGray));
        x += wdiff;
    }


    //Adds the rects to the scene
    for (unsigned int i = 0; i < this->m_relationData->width(); i++){
        for (unsigned int j = 0; j < this->m_relationData->height(); ++j) {

            MatrixElement* ele = new MatrixElement(i,
                                                   j,
                                                   wdiff,
                                                   hdiff,
                                                   QPen(borderColor),
                                                   QBrush(elementColor));
            ele->setFlag(QGraphicsItem::ItemIgnoresParentOpacity); //into MatrixElement
            ele->setToolTip(QString("(%1, %2)")
                            .arg(this->m_relationData->domain1Element(j))
                            .arg(this->m_relationData->domain2Element(i)));


            if (m_relationData->tableBit(i, j)){
                ele->setElementVisible();
                gv->scene()->addItem(ele);
            }else{
                ele->setElementInvisible();
                gv->scene()->addItem(ele);
            }

            connect(ele,SIGNAL(elementMousePress(MatrixElement*)),
                    this, SLOT(elementMousePress(MatrixElement*)), Qt::DirectConnection);
            connect(ele,SIGNAL(elementHoverEnter(MatrixElement*)),
                    this, SLOT(elementHoverEnter(MatrixElement*)), Qt::DirectConnection);
            m_elements.append(ele);
        }
    }

    //red line
    if (heightCount == widthCount){
        this->m_diagonal = this->m_graphicsScene->addLine(0,0,width,height, QPen(QColor(255,0,0,124)));
        this->m_diagonal->setVisible(settings.value("MainWindow/diagonal", true).toBool());
    }


    ui->statusBar->showMessage(tr("Relation loaded"), 2000);
}




void MainWindow::setLabel(QString relation, QString domain1, QString domain2)
{
    ui->relationName->setText(relation + " " + QString(QChar(0x2286))
                              + " " + domain1 + " "
                              + QString(QChar(0x00D7)) + " " + domain2);
    ui->relationName->setToolTip(relation + " " + QString(QChar(0x2286))
                                 + " " + domain1 + " "
                                 + QString(QChar(0x00D7)) + " " + domain2);
}



void MainWindow::enableButtons()
{
    ui->actionDuplicate->setEnabled(true);
    ui->actionSave_as->setEnabled(true);
    ui->actionExport_as->setEnabled(true);
    ui->actionPrint->setEnabled(true);

    this->m_editNameAction->setEnabled(true);

    ui->actionMatrix_Fit_to_Screen->setEnabled(true);
    ui->actionMatrix_Zoom_In->setEnabled(true);
    ui->actionMatrix_Zoom_Out->setEnabled(true);
    ui->actionReset_Sorting->setEnabled(true);
    ui->actionSwap->setEnabled(true);

    ui->actionFill->setEnabled(true);

    //relation buttons
    foreach (AbstractOperation* operation, ModificationFactory::instance().operations()){
        const QObjectList& list = ui->menuRelation->children();
        foreach (QObject* oobject, list){
            if (oobject->objectName() == operation->name()){
                QAction* action = qobject_cast<QAction*>(oobject);
                if (action)
                    action->setEnabled(true);
            }
        }
    }

    this->updateButtons();
}



bool MainWindow::shouldBeSaved()
{
    if (this->isWindowModified()) {
        QMessageBox msg(this);
        msg.setWindowModality(Qt::WindowModal);
        msg.setText(tr("Do you want to save the changes you made in the relation %1")
                    .arg(this->m_relationData->name()));
        msg.setIcon(QMessageBox::Warning);
        msg.setInformativeText(tr("Your changes will be lost if you don't save them."));
        msg.setStandardButtons(QMessageBox::Save | QMessageBox::Discard
                      | QMessageBox::Cancel);
        msg.setDefaultButton(QMessageBox::Save);
        int ret = msg.exec();

        if (ret == QMessageBox::Save)
            return this->saveRelation();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}


void MainWindow::readSettings()
{
    QSettings settings;
    settings.beginGroup("MainWindow");
    ui->actionFill->setChecked(settings.value("fillChecked", true).toBool());
    this->restoreGeometry(settings.value("geometry").toByteArray());
    this->restoreState(settings.value("windowState").toByteArray());
    settings.endGroup();
}


void MainWindow::writeSettings()
{
    QSettings settings;
    settings.beginGroup("MainWindow");
    settings.setValue("fillChecked", ui->actionFill->isChecked());
    settings.setValue("geometry", this->saveGeometry());
    settings.setValue("windowState", this->saveState());
    settings.endGroup();
}



/**
 * Reorders the columns of a euqivalent relation
 * @brief MainWindow::equSortColumn
 * @param column
 */
void MainWindow::equSortColumn(RelationData* rel, int column)
{
    int height = rel->height();
    int diagonalStart = column;
    int run = column;
    int bit = 0;
    int firstNullpos = -1; //first line with a 0 bit in column

    while (run < height){ //visit all rows
        int x = this->m_sequenceConverter->projectedX(diagonalStart);
        int y = this->m_sequenceConverter->projectedY(run);
        bit = rel->tableBit(x, y);

        //initates firstNullpos with the first line with a 0 bit in column
        if ((bit == 0) && (firstNullpos == -1)){
            firstNullpos = run;
        }

        // looking for a line with a 1 bit
        if (bit == 1 && firstNullpos != -1){
            this->m_sequenceConverter->switchRows(firstNullpos, run);
            firstNullpos++;
        }

        run++;
    }
}


/**
 * Reorders the rows of a euqivalent relation
 * @brief MainWindow::equSortRow
 * @param row
 */
void MainWindow::equSortRow(RelationData* rel, int row)
{
    int width = rel->width();
    int diagonalStart = row;
    int run = row;
    int bit = 0;
    int firstNullpos = -1; //first line with a 0 bit in row


    while (run < width){ //visit all columns
        int x = this->m_sequenceConverter->projectedX(run);
        int y = this->m_sequenceConverter->projectedY(diagonalStart);
        bit = rel->tableBit(x, y);

        //initates firstNullpos with the first line with a 0 bit in row
        if ((bit == 0) && (firstNullpos == -1)){
            firstNullpos = run;
        }

        // looking for a line with a 1 bit
        if (bit == 1 && firstNullpos != -1){
            this->m_sequenceConverter->switchColumns(firstNullpos, run);
            firstNullpos++;
        }

        run++;
    }
}


