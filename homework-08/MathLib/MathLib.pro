

TEMPLATE = lib
CONFIG += staticlib

CONFIG -= qt

TARGET = MathLib
DESTDIR = $$PWD/../lib
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MathLib.cpp

HEADERS += \
    MathLib.h

# Default rules for deployment.
#unix {
#    target.path = $$[QT_INSTALL_PLUGINS]/generic
#}
win32 {
#    TARGET = $$join(TARGET,,,_windows)
    DEFINES += WINDOWS_PLATFORM
    DEFINES += _CRT_SECURE_NO_WARNINGS
}
#Конфігурації Debug/Release
CONFIG(debug, debug|release) {
    TARGET = $$join(TARGET,,,d)
    DEFINES += DEBUG_BUILD
} else {
    DEFINES += RELEASE_BUILD
    DEFINES += QT_NO_DEBUG_OUTPUT
}
# Додаткові налаштування компілятора
QMAKE_CXXFLAGS += -std=c++14

!isEmpty(target.path): INSTALLS += target
