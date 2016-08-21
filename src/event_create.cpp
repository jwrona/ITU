#include "event_create.h"
#include "ui_event_create.h"

event_create::event_create(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::event_create)
{
    ui->setupUi(this);

    setWindowTitle("Event create");

    ui->calendar_id_lineEdit->hide();

    dialog_gapi = new gcal_api();
    dialog_gapi->getAccessTokenFromFile();
    ui->start_dateEdit->setDate(QDate::currentDate());
    ui->end_dateEdit->setDate(QDate::currentDate());
    ui->start_timeEdit->setTime(QTime::currentTime());
    ui->end_timeEdit->setTime(QTime::currentTime());
    setFixedSize(size());
    ui->create_pushButton->setEnabled(false);
    dialog_lapi = new local_calendar();


    connect(dialog_gapi, SIGNAL(eventsReady()), this, SLOT(send()));
}

event_create::~event_create()
{
    delete ui;
}

void event_create::set_ID(QString id)
{
    ui->calendar_id_lineEdit->setText(id);
    ui->summary_lineEdit->clear();
    ui->description_lineEdit->clear();
    ui->location_lineEdit->clear();
    ui->start_dateEdit->setDate(QDate::currentDate());
    ui->end_dateEdit->setDate(QDate::currentDate());
    ui->start_timeEdit->setTime(QTime::currentTime());
    ui->end_timeEdit->setTime(QTime::currentTime());
}

void event_create::on_create_pushButton_clicked()
{
    QString new_cal_json;

    new_cal_json = QString("{\n") +
                   QString("\"end\": {\n") +
                   QString("\"dateTime\": \"" + ui->end_dateEdit->text() + "T" + ui->end_timeEdit->text() + ":00Z" +"\"\n},\n") +
                   QString("\"start\": {\n") +
                   QString("\"dateTime\": \"" + ui->start_dateEdit->text() + "T" + ui->start_timeEdit->text() + ":00Z" + "\"\n},\n") +
                   QString("\"location\": \"" + ui->location_lineEdit->text() + "\",\n") +
                   QString("\"description\": \"" + ui->description_lineEdit->text() + "\",\n") +
                   QString("\"summary\": \"" + ui->summary_lineEdit->text() + "\"\n") +
                   QString("}");

    ui->create_pushButton->setEnabled(true);
    if(local_checked)
    {
        dialog_lapi->create_event(ui->calendar_id_lineEdit->text(), new_cal_json);
    }
    else
    {
        dialog_gapi->create_event(dialog_gapi->access_token, ui->calendar_id_lineEdit->text(), new_cal_json);
    }

    this->close();

}

void event_create::send()
{
    emit refresh();
}

void event_create::on_summary_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->create_pushButton->setEnabled(false);
    }
    else
    {
        ui->create_pushButton->setEnabled(true);
    }
}

void event_create::on_start_dateEdit_dateChanged()
{
    QDate start = QDate::fromString(ui->start_dateEdit->text(), "yyyy-MM-dd");
    QDate end = QDate::fromString(ui->end_dateEdit->text(), "yyyy-MM-dd");

    if(end < start)
    {
        ui->create_pushButton->setEnabled(false);
    }
    else
    {
        ui->create_pushButton->setEnabled(true);
    }
}

void event_create::on_end_dateEdit_dateChanged()
{
    QDate start = QDate::fromString(ui->start_dateEdit->text(), "yyyy-MM-dd");
    QDate end = QDate::fromString(ui->end_dateEdit->text(), "yyyy-MM-dd");

    if(end < start)
    {
        ui->create_pushButton->setEnabled(false);
    }
    else
    {
        ui->create_pushButton->setEnabled(true);
    }
}
