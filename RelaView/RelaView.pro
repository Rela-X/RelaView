#-------------------------------------------------
#
# Project created by QtCreator 2012-05-13T17:22:00
#
#-------------------------------------------------

QT       += core gui printsupport #opengl


TARGET = RelaView
TEMPLATE = app


#release:DEFINES += DQT_NO_DEBUG
#release:DEFINES += QT_NO_DEBUG_OUTPUT


win32{
    TODAY = $$system(echo %date%)
    RV_TMP = '\\"$${TODAY}\\"'
    DEFINES += BUILDDATE=\"$${RV_TMP}\"
}else{ #macx, linux-*
    DEFINES += BUILDDATE=\\\"$$system(date '+%x')\\\"
}


SOURCES  += src/main.cpp \
    src/rvapplication.cpp \
    src/controller/fileloader.c \
    src/controller/datamanager.cpp \
    src/model/relationdata.cpp \
    src/model/domaindata.cpp \
    src/view/mainwindow.cpp \
    src/view/propertieswidget.cpp \
    src/view/matrixelement.cpp \
    src/view/relationchooserdialog.cpp \
    src/view/matrixview.cpp \
    src/view/editrelationname.cpp \
    src/view/preferences.cpp \
    src/undocommands/setpropertycommand.cpp \
    src/undocommands/editnamecommand.cpp \
    src/undocommands/toggleelementcommand.cpp \
    src/modifier/abstractproperty.cpp \
    src/modifier/genericproperty.cpp \
    src/undocommands/setpropertiescommand.cpp \
    #src/view/pixmapmatrix.cpp \
    src/view/newrelationdialog.cpp \
    src/view/binaryoperationdialog.cpp \
    src/modifier/abstractoperation.cpp \
    src/modifier/unaryoperation.cpp \
    src/modifier/homogenousoperation.cpp \
    src/modifier/inhomogenousoperation.cpp \
    src/modifier/binaryoperation.cpp \
    src/view/errorlogwidget.cpp \
    src/modifier/abstractmodification.cpp \
    src/controller/modificationfactory.cpp \
    src/undocommands/binaryoperationcommand.cpp \
    src/undocommands/unaryoperationcommand.cpp \
    src/view/domainchooserdialog.cpp \
    src/controller/sequenceconverter.cpp \
    src/view/newdomaindialog.cpp \
    src/view/swapdialog.cpp


INCLUDEPATH += src/
INCLUDEPATH += src/modifier/
INCLUDEPATH += src/undocommands/
INCLUDEPATH += src/controller/
INCLUDEPATH += src/model/
INCLUDEPATH += src/view/
HEADERS  += src/rvapplication.h \
    src/controller/fileloader.h \
    src/controller/datamanager.h \
    src/model/relationdata.h \
    src/model/domaindata.h \
    src/view/mainwindow.h \
    src/view/propertieswidget.h \
    src/view/matrixelement.h \
    src/view/relationchooserdialog.h \
    src/view/matrixview.h \
    src/view/editrelationname.h \
    src/view/preferences.h \
    src/undocommands/setpropertycommand.h \
    src/undocommands/editnamecommand.h \
    src/undocommands/toggleelementcommand.h \
    src/modifier/abstractproperty.h \
    src/modifier/genericproperty.h \
    src/modifier/abstractmodification.h \
    src/controller/modificationfactory.h \
    src/undocommands/setpropertiescommand.h \
    #src/view/pixmapmatrix.h \
    src/view/newrelationdialog.h \
    src/view/binaryoperationdialog.h \
    src/modifier/abstractoperation.h \
    src/modifier/unaryoperation.h \
    src/modifier/homogenousoperation.h \
    src/modifier/inhomogenousoperation.h \
    src/modifier/binaryoperation.h \
    src/view/errorlogwidget.h \
    src/undocommands/binaryoperationcommand.h \
    src/undocommands/unaryoperationcommand.h \
    src/view/domainchooserdialog.h \
    src/controller/sequenceconverter.h \
    src/view/newdomaindialog.h \
    src/view/swapdialog.h

FORMS    += forms/mainwindow.ui \
    forms/propertieswidget.ui \
    forms/relationchooserdialog.ui \
    forms/editrelationname.ui \
    forms/preferences.ui \
    forms/newrelationdialog.ui \
    forms/binaryoperationdialog.ui \
    forms/errorlogwidget.ui \
    forms/domainchooserdialog.ui \
    forms/newdomaindialog.ui \
    forms/swapdialog.ui


TRANSLATIONS =  recources/RelaView_en.ts \
                recources/RelaView_de.ts



INCLUDEPATH += ../RelaFix/inc

CONFIG(debug){
    DEPENDPATH += ../RelaFix/build/debug
    LIBS += -L../RelaFix/build/debug/ -lrflib
    PRE_TARGETDEPS += ../RelaFix/build/debug/librflib.a
    message("using debug rflib")
}else{
    DEPENDPATH += ../RelaFix/build/release
    LIBS += -L../RelaFix/build/release/ -lrflib
    PRE_TARGETDEPS += ../RelaFix/build/release/librflib.a
    message("using release rflib")
}



CONFIG(debug, debug|release){
    DESTDIR = build/debug
    OBJECTS_DIR = $${DESTDIR}/obj
    MOC_DIR = $${DESTDIR}/moc
    RCC_DIR = $${DESTDIR}/rcc
    UI_DIR = $${DESTDIR}/ui
}else{
    DESTDIR = build/release
    OBJECTS_DIR = $${DESTDIR}/obj
    MOC_DIR = $${DESTDIR}/moc
    RCC_DIR = $${DESTDIR}/rcc
    UI_DIR = $${DESTDIR}/ui
}



macx: ICON = recources/icon.icns
win32: RC_FILE = recources/icon.rc

RESOURCES += \
    recources/recources.qrc

QMAKE_INFO_PLIST = recources/Info.plist
OTHER_FILES += \
    recources/Info.plist
