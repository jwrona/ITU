#ifndef CALENDARUI_H
#define CALENDARUI_H

#include <Qt>
#include <QDeclarativeView>
#include <QDebug>
#include <QGraphicsObject>
#include <QSize>
#include <QMouseEvent>
#include <QDate>
#include <QWidget>
#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QDeclarativeComponent>
#include <QDeclarativeItem>

#include "interval_picker.h"

#include <string>
#include <iostream>

#ifdef Q_OS_WIN32
    #include <windows.h>
#endif /* Q_OS_WIN32 */


class CalendarUi : public QDeclarativeView
{
    Q_OBJECT

public:
    CalendarUi(QWidget *parent = 0);
    ~CalendarUi();

    QMenu *trayIconMenu;
    QSystemTrayIcon* systray;
    QAction *edit_calendarsAction;
    QAction *change_intervalAction;

    QActionGroup* layout_view;
    QAction *setWeekLayoutAction;
    QAction *setMonthLayoutAction;

    QAction *resize_moveAction;
    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *maximizeAction;
    QAction *quitAction;
    QAction *showAction;

    interval_picker *int_picker;

    QJsonDocument str_to_json_doc (QString str);
    QString settings_template();
    QString open_file (QString filename);
    void save_file (QString filename, QString content);
    bool week;
    bool first;
    void getEventList();
    QList<QJsonObject> events;
    QList<QJsonObject> eventsOfDate(QString start_date);
    QList<QJsonObject> eventsOfTime(QString date_time);
    QDate actdate;

public slots:
    void change_interval();
    void send_to_back();
    void showMaximizedWin();
    void restore();
    void resize_relocate(bool changeable);

    void setWeekLayout();
    void setMonthLayout();
    void setLayout();


protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPoint dragPosition;
};

#endif // CALENDARUI_H
