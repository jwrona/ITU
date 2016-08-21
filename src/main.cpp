#include "calendar_ui.h"

#include <QApplication>

#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    CalendarUi cal_ui;
    cal_ui.show();
    cal_ui.send_to_back();

    return a.exec();
}
