#ifndef CREATE_CALENDAR_H
#define CREATE_CALENDAR_H

#include <QDialog>
#include "gcal_api.h"
#include "local_calendar.h"

namespace Ui {
class create_calendar;
}

class create_calendar : public QDialog
{
    Q_OBJECT

public:
    explicit create_calendar(QWidget *parent = 0);
    ~create_calendar();

    gcal_api *lol;
    local_calendar *local_cal;

    bool local_checked;

private:
    Ui::create_calendar *ui;

public slots:
    void on_create_clicked();
    void on_summary_textChanged(const QString &arg1);
};

#endif // CREATE_CALENDAR_H
