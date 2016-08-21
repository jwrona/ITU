#-------------------------------------------------
#
# Project created by QtCreator 2013-11-29T19:37:01
#
#-------------------------------------------------

QT += core gui widgets webkit webkitwidgets declarative

TARGET = electronic_calendar
TEMPLATE = app


DESTDIR = $$PWD

SOURCES += main.cpp\
        mainwindow.cpp \
    oauth2.cpp \
    gcal_api.cpp \
    calendar_create.cpp \
    calendar_edit.cpp \
    event_create.cpp \
    event_edit.cpp \
    login_dialog.cpp \
    lcal_api.cpp \
    calendar_ui.cpp \
    interval_picker.cpp

HEADERS  += mainwindow.h \
    oauth2.h \
    gcal_api.h \
    calendar_create.h \
    calendar_edit.h \
    event_create.h \
    event_edit.h \
    login_dialog.h \
    lcal_api.h \
    calendar_ui.h \
    interval_picker.h

FORMS    += mainwindow.ui \
    calendar_create.ui \
    calendar_edit.ui \
    event_create.ui \
    event_edit.ui \
    login_dialog.ui \
    interval_picker.ui

OTHER_FILES += \
    tray_icon.png \
    ui_week.qml \
    ui_month.qml
