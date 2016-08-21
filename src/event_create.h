#ifndef EVENT_CREATE_H
#define EVENT_CREATE_H

#include <QDialog>
#include <QTextStream>
#include <QDate>
#include <QTime>

#include "gcal_api.h"
#include "lcal_api.h"


namespace Ui {
class event_create;
}

class event_create : public QDialog
{
    Q_OBJECT

public:
    explicit event_create(QWidget *parent = 0);
    ~event_create();

    gcal_api *dialog_gapi;
    local_calendar *dialog_lapi;
    bool local_checked;

    void set_ID(QString id);

signals:
    void refresh();

public slots:
    void send();

private slots:
   void on_create_pushButton_clicked();

   void on_summary_lineEdit_textChanged(const QString &arg1);

   void on_start_dateEdit_dateChanged();

   void on_end_dateEdit_dateChanged();

private:
    Ui::event_create *ui;
};

#endif // EVENT_CREATE_H
