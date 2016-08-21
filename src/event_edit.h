#ifndef EVENT_EDIT_H
#define EVENT_EDIT_H

#include <QDialog>
#include <QTextStream>
#include <QDate>
#include <QTime>

#include "gcal_api.h"
#include "lcal_api.h"

namespace Ui {
class event_edit;
}

class event_edit : public QDialog
{
    Q_OBJECT

public:
    explicit event_edit(QWidget *parent = 0);
    ~event_edit();

    void set_ID(gcal_api *g_api, QString id_calendar, QString id_event);
    void set_ID(local_calendar *local_cal, QString id_calendar, QString id_event);
    void show_json();
    QString event_id;
    QString calendar_id;

    gcal_api *dialog_gapi;
    local_calendar *dialog_lapi;
    bool local_checked;

private slots:
    void on_update_pushButton_clicked();

    void on_summary_lineEdit_textChanged(const QString &arg1);

    void on_start_dateEdit_dateChanged();

    void on_end_dateEdit_dateChanged();

private:
    Ui::event_edit *ui;
};

#endif // EVENT_EDIT_H
