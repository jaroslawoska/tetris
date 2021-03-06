TEMPLATE = app

QT += quick qml

CONFIG += qmltypes
QML_IMPORT_NAME = tetris
QML_IMPORT_MAJOR_VERSION = 1

SOURCES += \
    canva.cpp \
    main.cpp \
    tetrismodel.cpp \
    tetromino.cpp

RESOURCES += \
    tetris.qml

target.path = $$[QT_INSTALL_EXAMPLES]/quick/tableview/tetris
INSTALLS += target

HEADERS += \
    canva.h \
    tetrismodel.h \
    tetromino.h

DISTFILES += \
    tetris.qml

