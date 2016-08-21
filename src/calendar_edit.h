#ifndef CALENDAR_EDIT_H
#define CALENDAR_EDIT_H

#include <QDialog>
#include "gcal_api.h"
#include "lcal_api.h"

namespace Ui {
class calendar_edit;
}

class calendar_edit : public QDialog
{
    Q_OBJECT

public:
    explicit calendar_edit(QWidget *parent = 0);
    ~calendar_edit();


    gcal_api *dialog_gapi;
    local_calendar *dialog_lapi;
    bool local_checked;
    Ui::calendar_edit *ui;

private:

public slots:
    void set_ID(gcal_api *g_api, QString id);
    void set_ID(local_calendar *local_cal, QString id);
    void show_json();

private slots:

    void on_summary_lineEdit_textChanged(const QString &arg1);
    void on_update_pushButton_clicked();
};

#endif // CALENDAR_EDIT_H
