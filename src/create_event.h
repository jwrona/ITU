#ifndef CREATE_EVENT_H
#define CREATE_EVENT_H

#include <QDialog>
#include "gcal_api.h"
#include "local_calendar.h"

namespace Ui {
class create_event;
}

class create_event : public QDialog
{
    Q_OBJECT

public:
    explicit create_event(QWidget *parent = 0);
    ~create_event();


private:
    Ui::create_event *ui;
};

#endif // CREATE_EVENT_H
