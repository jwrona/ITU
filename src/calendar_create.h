#ifndef CALENDAR_CREATE_H
#define CALENDAR_CREATE_H

#include <QDialog>
#include "gcal_api.h"
#include "lcal_api.h"

namespace Ui {
class calendar_create;
}

class calendar_create : public QDialog
{
    Q_OBJECT

public:
    explicit calendar_create(QWidget *parent = 0);
    ~calendar_create();

    gcal_api *dialog_gapi;
    local_calendar *dialog_lapi;
    bool local_checked;
    void set_bool(bool local_checked);


signals:
    void refresh();

public slots:
    void send();

private slots:
    void on_summary_lineEdit_textChanged(const QString &arg1);

    void on_create_pushButton_clicked();

private:
    Ui::calendar_create *ui;
};


#endif // CALENDAR_CREATE_H
