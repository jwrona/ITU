#include "calendar_ui.h"
#include "mainwindow.h"



CalendarUi::CalendarUi(QWidget *parent)
    : QDeclarativeView(parent)
{

        QIcon icon("tray_icon.png");
        setWindowIcon(icon);


        QFile file("data/settings.json");

        week = true;
        actdate = QDate::currentDate();

        if(!file.exists())
        {
            save_file(QString("settings.json"), settings_template());
        }
        else
        {
            first = true;
            QString json;
            json = open_file("settings.json");

            QJsonDocument json_doc = QJsonDocument::fromJson (json.toUtf8 ());
            QVariant var = json_doc.toVariant();

            int x = var.toMap()["position"].toMap()["x"].toInt();
            int y = var.toMap()["position"].toMap()["y"].toInt();
            int width = var.toMap()["size"].toMap()["width"].toInt();
            int height = var.toMap()["size"].toMap()["height"].toInt();

            actdate = QDate::fromString(var.toMap()["actdate"].toString(),"yyyy-MM-dd");

            if(var.toMap()["view"].toString() == "week")
            {
                week = true;
                setWeekLayout();
            }
            else
            {
                week = false;
                setMonthLayout();
            }

            resize(width, height);
            move(x, y);
            first = false;
         }


        getEventList();

        setResizeMode(QDeclarativeView::SizeRootObjectToView);
        setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint | Qt::WindowTransparentForInput | Qt::WindowDoesNotAcceptFocus);
        setStyleSheet("background:transparent;");

        MainWindow *edit_calendars = new MainWindow();

        /////////////////////////////.
        ///

        int_picker = new interval_picker();
        QObject::connect (int_picker, SIGNAL(accepted()), this, SLOT(change_interval()));

        ///
        /////////////////////////////.



        /////////////////////////////
        //// tray - START
        edit_calendarsAction = new QAction("Calendar Editor", edit_calendars);
        change_intervalAction = new QAction("Set Displayed Date...", int_picker);


        setWeekLayoutAction = new QAction("Week View", this);
        setWeekLayoutAction->setCheckable(true);
        setMonthLayoutAction = new QAction("Month View", this);
        setMonthLayoutAction->setCheckable(true);

        layout_view = new QActionGroup(this);
        layout_view->addAction(setWeekLayoutAction);
        layout_view->addAction(setMonthLayoutAction);
        layout_view->setExclusive(true);

        setWeekLayoutAction->setChecked(week);
        setMonthLayoutAction->setChecked(!week);

        maximizeAction = new QAction("Fullscreen", this);
        restoreAction = new QAction("Default Size and Position", this);
        resize_moveAction = new QAction("Change Size and Position...", this);
        resize_moveAction->setCheckable(true);

        showAction = new QAction("Show", this);
        minimizeAction = new QAction("Hide", this);
        quitAction = new QAction("Quit", this);

        QObject::connect (edit_calendarsAction, SIGNAL(triggered()), edit_calendars, SLOT(show()));
        QObject::connect (change_intervalAction, SIGNAL(triggered()), int_picker, SLOT(show()));


        QObject::connect (edit_calendars, SIGNAL(closed()), this, SLOT(setLayout()));
        QObject::connect (setWeekLayoutAction, SIGNAL(triggered()), this, SLOT(setWeekLayout()));
        QObject::connect (setMonthLayoutAction, SIGNAL(triggered()), this, SLOT(setMonthLayout()));

        QObject::connect (resize_moveAction, SIGNAL(triggered(bool)), this, SLOT(resize_relocate(bool)));

        QObject::connect (showAction, SIGNAL(triggered()), this, SLOT(show()));
        QObject::connect (showAction, SIGNAL(triggered()), this, SLOT(send_to_back()));

        QObject::connect (minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

        QObject::connect (maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximizedWin()));
        QObject::connect (maximizeAction, SIGNAL(triggered()), this, SLOT(send_to_back()));

        QObject::connect (restoreAction, SIGNAL(triggered()), this, SLOT(restore()));
        QObject::connect (restoreAction, SIGNAL(triggered()), this, SLOT(send_to_back()));

        QObject::connect (quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

        trayIconMenu = new QMenu();
        trayIconMenu->setStyleSheet("background:solid;");

        trayIconMenu->addAction (edit_calendarsAction);

        trayIconMenu->addSeparator();

        trayIconMenu->addAction (change_intervalAction);

        trayIconMenu->addSeparator();

        trayIconMenu->addAction (setWeekLayoutAction);
        trayIconMenu->addAction (setMonthLayoutAction);

        trayIconMenu->addSeparator();

        QMenu* sizeMenu = new QMenu(QString("Set Size"), this);
        sizeMenu->setStyleSheet("background:solid;");
        sizeMenu->addAction (restoreAction);
        sizeMenu->addAction (maximizeAction);
        sizeMenu->addAction (resize_moveAction);
        trayIconMenu->addMenu(sizeMenu);

        trayIconMenu->addSeparator();

        trayIconMenu->addAction (showAction);
        trayIconMenu->addAction (minimizeAction);

        trayIconMenu->addSeparator();

        trayIconMenu->addAction (quitAction);

        systray = new QSystemTrayIcon(this);
        systray->setIcon(icon);
        systray->setContextMenu (trayIconMenu);
        systray->show();
        //// tray - END
        /////////////////////////////
        ///
}

CalendarUi::~CalendarUi()
{

}

void CalendarUi::change_interval()
{
    actdate = int_picker->get_actdate();

    if (week)
    {
        setWeekLayout();
    }
    else
    {
        setMonthLayout();
    }
    save_file(QString("settings.json"), settings_template());
}

QJsonDocument CalendarUi::str_to_json_doc (QString str)
{
  return QJsonDocument::fromJson (str.toUtf8 ());
}

QString CalendarUi::settings_template()
{
    QString settings_json;
    QString view;
    if(week)
    {
        view = QString("week");
    }
    else
    {
        view = QString("month");
    }

    settings_json = QString("{\n") +
                    QString("\"position\": {\n") +
                    QString("\"x\": " + QString::number(x()) + ",\n") +
                    QString("\"y\": " + QString::number(y()) + "\n},\n") +
                    QString("\"size\": {\n") +
                    QString("\"width\": " + QString::number(width()) + ",\n") +
                    QString("\"height\": " + QString::number(height()) + "\n},\n") +
                    QString("\"view\": \"" + view +  "\",\n") +
                    QString("\"actdate\": \"" + actdate.toString(Qt::ISODate) +  "\"\n") +
                    QString("}");
    return QString(QJsonDocument::fromJson(settings_json.toUtf8 ()).toJson());
}

//// open file
QString CalendarUi::open_file (QString filename)
{

  QString tmp;
  QFile file;
  file.setFileName ("data/" + filename);
  qDebug () << file.fileName ();
//  qDebug () << file.open (QIODevice::ReadOnly | QIODevice::Text);
  file.open (QIODevice::ReadOnly | QIODevice::Text);
  tmp = file.readAll ();
  file.close();
  return tmp;
}

//// save file
void CalendarUi::save_file (QString filename, QString content)
{
  if (!QDir ("data").exists ())
  {
    QDir ().mkdir ("data");
  }

  QFile file ("data/" + filename);
  file.open (QIODevice::WriteOnly | QIODevice::Text);
  QTextStream out (&file);
  out << content;
  file.close ();
}

void CalendarUi::send_to_back()
{
    #ifdef Q_OS_WIN32
    HWND top_handle;
    top_handle = GetForegroundWindow();
    SetForegroundWindow(top_handle);

    HWND focus_handle;
    focus_handle = GetFocus();
    SetFocus(focus_handle);

    HWND my_handle;
    my_handle = (HWND)winId();
    SetWindowPos(my_handle, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOACTIVATE);
    #endif /* Q_OS_WIN32 */
}

void CalendarUi::showMaximizedWin()
{
    #ifdef Q_OS_WIN32
    RECT rectangle;
    SystemParametersInfo(SPI_GETWORKAREA, 0, &rectangle ,0);
    move(rectangle.left, rectangle.top);
    resize(rectangle.right, rectangle.bottom);
    setLayout();
    show();
    #endif /* Q_OS_WIN32 */
}

void CalendarUi::restore()
{
    #ifdef Q_OS_WIN32
    RECT rectangle;
    SystemParametersInfo(SPI_GETWORKAREA, 0, &rectangle ,0);
    move(rectangle.right*0.125, rectangle.bottom*0.125);
    resize(rectangle.right*0.75, rectangle.bottom*0.75);
    setLayout();
    show();
    send_to_back();
    #endif /* Q_OS_WIN32 */
}

void CalendarUi::resize_relocate(bool changeable)
{
    if (changeable)
    {
        #ifdef Q_OS_WIN32
        RECT rectangle;
        SystemParametersInfo(SPI_GETWORKAREA, 0, &rectangle ,0);
        move(rectangle.right*0.125, rectangle.bottom*0.125);
        resize(rectangle.right*0.75, rectangle.bottom*0.75);
        #endif /* Q_OS_WIN32 */
        setWindowFlags(Qt::Tool | Qt::WindowStaysOnBottomHint | Qt::CustomizeWindowHint);
        setStyleSheet("background:transparent;");
        setCursor(Qt::OpenHandCursor);
        setAttribute(Qt::WA_NoBackground);
        setAttribute(Qt::WA_NoSystemBackground);
        setAttribute(Qt::WA_TranslucentBackground);
        setWindowOpacity(0.5);
        show();
        send_to_back();

    }
    else
    {
        setResizeMode(QDeclarativeView::SizeRootObjectToView);
        setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint | Qt::WindowTransparentForInput | Qt::WindowDoesNotAcceptFocus);
        setStyleSheet("background:transparent;");

        unsetCursor();
        setAttribute(Qt::WA_NoSystemBackground, false);
        setWindowOpacity(1);
        show();
        send_to_back();
    }

    //////////////////////////////////
    ///
    save_file(QString("settings.json"), settings_template());
    //////////////////////////////////
}

void CalendarUi::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
        setCursor(Qt::ClosedHandCursor);
    } else if (event->buttons() & Qt::RightButton) {
        emit(resize_moveAction->triggered(false));
        resize_moveAction->setChecked(false);
    }
}

void CalendarUi::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void CalendarUi::mouseReleaseEvent(QMouseEvent *event)
{
    unsetCursor();
    setCursor(Qt::OpenHandCursor);
    event->accept();
}

void CalendarUi::setLayout()
{
    if (week)
    {
        setWeekLayout();
    }
    else
    {
        setMonthLayout();
    }
}

void CalendarUi::setWeekLayout()
{
    QSize tmp = size();
    setSource(QUrl::fromLocalFile("ui_week.qml"));
    resize(tmp);

    week = true;
    if(!first)
    {
        save_file(QString("settings.json"), settings_template());
    }

    ////////////////////////////////////////////////////////////aa


    QObject *obj = this->rootObject();
    QList<QJsonObject> e_list;
    getEventList();


    QDateTime t1;
    QDate d2 = actdate.addDays(1-actdate.dayOfWeek());

    t1.fromString(d2.toString("yyyy-MM-dd"),"yyyy-MM-dd");

    QObject *cell;
    QObject *header_cell;

    header_cell = obj->findChild<QObject*>(QString("week_num"));
    header_cell->setProperty("week_num", QString("# ")+QString::number(d2.weekNumber()));

    for (int day = 1; day <= 7 ; ++day) {

        header_cell = obj->findChild<QObject*>(QString("header_")+QString::number(day));
        if (header_cell)
        {
            if (d2 == QDate::currentDate()) {
                header_cell->setProperty("color", "#FF0000");
            }
        }

        for (int hour = 0; hour <= 23; ++hour )
        {

            e_list.clear();
            e_list = eventsOfTime(d2.toString("yyyy-MM-dd")+QString(" ")+QString::number(hour)+QString(":00:00"));
            if (e_list.count() > 0)
            {
                cell = obj->findChild<QObject*>(QString::number(hour+1) + QString(":") + QString::number(day));

                if (cell)
                {
                    qDebug() << cell->children()[0]->setProperty("text", e_list.at(0).value("summary").toString());
                    qDebug() << cell->setProperty("color", "#FF00FF");

                    qDebug() << cell->dynamicPropertyNames();
                    //qDebug() << cell->metaObject()->;

                    //qDebug() << e_list.at(0).value("end").toObject().value("dateTime").toString().remove(0, 11).left(2);
//                    qDebug() << cell->setProperty("end_hour", 22);
                }
            }
        }
        d2 = d2.addDays(1);
    }
}

void CalendarUi::setMonthLayout()
{
    QSize tmp = size();
    setSource(QUrl::fromLocalFile("ui_month.qml"));
    resize(tmp);

    week = false;
    if(!first)
    {
        save_file(QString("settings.json"), settings_template());
    }

    ////////////////////////////////////////////////////////////aa


    QObject *obj = this->rootObject();
    QObject *event;
    QList<QJsonObject> e_list;
    getEventList();


    QDate d1 = actdate;
    QDate d2 = QDate ( d1.year(), d1.month(), 1);
    QObject *cell;
    QObject *week_cell;
    int row = 1;

    for (int var = 1; var <= d1.daysInMonth() ; ++var) {


        //QString::number(row);

        cell = obj->findChild<QObject*>(QString::number(row)+QString(":")+QString::number(d2.dayOfWeek()-1));
        if (cell)
        {
            if (d2 == QDate::currentDate()) {
                cell->setProperty("color", "#FF0000");
            }
            else {
                cell->setProperty("color", "#AA0000");
            }

           cell->setProperty("txt", QString::number(d2.day()));

            e_list = eventsOfDate(d2.toString("yyyy-MM-dd"));
            for (int i = 0; i < (e_list.count() <= 4 ? e_list.count() : 4); ++i)
            {
                event = obj->findChild<QObject*>(QString::number(row)+QString(":")+QString::number(d2.dayOfWeek())+QString(":")+QString::number(i+1));
                if (event)
                {
                    event->setProperty("color", "white");
                    event->setProperty("event_text", e_list.at(i).value("summary").toString());
                }
            }
        }

        week_cell = obj->findChild<QObject*>(QString("week_num")+QString::number(row));
        week_cell->setProperty("week_num", QString::number(d2.weekNumber()));

        if (d2.dayOfWeek() == 7)
        {
            row++;
        }
        d2 = d2.addDays(1);
    }
}

void CalendarUi::getEventList()
{
    events.clear();

    QString calendar_list;
    QString event_list;
    QString id;

    calendar_list = open_file("local_calendar_list.json");
    QJsonDocument calendar_list_doc = QJsonDocument::fromJson (calendar_list.toUtf8 ());
    QJsonArray cal_arr = calendar_list_doc.object ().value ("items").toArray ();

    for (int i = 0; i != cal_arr.size (); i++)
    {
        id = cal_arr.at (i).toObject ().value ("id").toString ();
        event_list = open_file(id + ".json");
        QJsonDocument event_list_doc = QJsonDocument::fromJson (event_list.toUtf8 ());
        QJsonArray event_arr = event_list_doc.object ().value ("items").toArray ();

        for(int j = 0; j != event_arr.size(); j++)
        {
              events.append(event_arr.at(j).toObject());
//            qDebug() << event_arr.at(j).toObject().value("start").toObject().value("dateTime").toString() << event_arr.at(j).toObject().value("end").toObject().value("dateTime").toString();
        }
    }
}


QList<QJsonObject> CalendarUi::eventsOfDate(QString start_date)
{
    QList<QJsonObject> events_of_date;

    QDate in_start = QDate::fromString(start_date, "yyyy-MM-dd");

    for(int i = 0; i != events.size(); i++)
    {
        QDate event_start = QDate::fromString(events.at(i).value("start").toObject().value("dateTime").toString().left(10), "yyyy-MM-dd");
        QDate event_end = QDate::fromString(events.at(i).value("end").toObject().value("dateTime").toString().left(10), "yyyy-MM-dd");

        if(in_start >= event_start &&  in_start <= event_end)
        {
            events_of_date.append(events.at(i));
        }
    }
    return events_of_date;
}

QList<QJsonObject> CalendarUi::eventsOfTime(QString date_time)
{
    QList<QJsonObject> events_of_time;
    QList<QJsonObject> events_of_date;

    QDateTime in = QDateTime::fromString(date_time, "yyyy-MM-dd hh:mm:ss");
    QString date = in.date().toString("yyyy-MM-dd");
    events_of_date = eventsOfDate(date);

    for(int i = 0; i != events_of_date.size(); i++)
    {
        QTime event_start = QTime::fromString(events.at(i).value("start").toObject().value("dateTime").toString().remove(0, 11).left(2), "hh");
        QTime event_end = QTime::fromString(events.at(i).value("end").toObject().value("dateTime").toString().remove(0, 11).left(2), "hh");


        if(
           in.time().hour() == event_start.hour()
           //in.time().hour() >= event_start.hour()
           //&& in.time().hour() <= event_end.hour()
        )
        {
            events_of_time.append(events_of_date.at(i));
        }
    }
    return events_of_time;
}
