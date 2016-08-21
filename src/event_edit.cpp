#include "event_edit.h"
#include "ui_event_edit.h"

event_edit::event_edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::event_edit)
{
    ui->setupUi(this);

    setFixedSize(size());
    setWindowTitle("Event edit");
    ui->update_pushButton->setEnabled(false);
    ui->calendar_id_lineEdit->hide();
}

event_edit::~event_edit()
{
    delete ui;
}

void event_edit::set_ID(gcal_api *g_api, QString id_calendar, QString id_event)
{
    ui->calendar_id_lineEdit->setText(id_calendar);
    dialog_gapi = g_api;
    event_id = id_event;
    calendar_id = id_calendar;
    show_json();
}

void event_edit::set_ID(local_calendar *local_cal, QString id_calendar, QString id_event)
{
    ui->calendar_id_lineEdit->setText(id_calendar);
    dialog_lapi = local_cal;
    event_id = id_event;
    calendar_id = id_calendar;
    show_json();
}

void event_edit::show_json()
{
    QString json = dialog_gapi->open_file(calendar_id + ".json");
    QJsonDocument json_doc = dialog_gapi->str_to_json_doc(json);
    QVariant var = json_doc.toVariant();
    QVariant data;
    QString str;
    QDate converted;
    QTime converted1;

    for(int i = 0; i < var.toMap()["items"].toList().size(); i++) {
      data = var.toMap()["items"].toList()[i].toMap()["id"];

      if(data == event_id) {
        ui->summary_lineEdit->setText(var.toMap()["items"].toList()[i].toMap()["summary"].toString());
        ui->description_lineEdit->setText(var.toMap()["items"].toList()[i].toMap()["description"].toString());
        ui->location_lineEdit->setText(var.toMap()["items"].toList()[i].toMap()["location"].toString());

        str = var.toMap()["items"].toList()[i].toMap()["start"].toMap()["dateTime"].toString().left(10);
        converted = QDate::fromString(str, "yyyy-MM-dd");
        ui->start_dateEdit->setDate(converted);

        str = (var.toMap()["items"].toList()[i].toMap()["end"].toMap()["dateTime"].toString().left(10));
        converted = QDate::fromString(str, "yyyy-MM-dd");
        ui->end_dateEdit->setDate(converted);

        str = var.toMap()["items"].toList()[i].toMap()["start"].toMap()["dateTime"].toString().mid(11,8);
        converted1 = QTime::fromString(str, "hh:mm:ss");
        ui->start_timeEdit->setTime(converted1);

        str = var.toMap()["items"].toList()[i].toMap()["end"].toMap()["dateTime"].toString().mid(11,8);
        converted1 = QTime::fromString(str, "hh:mm:ss");
        ui->end_timeEdit->setTime(converted1);

        break;
      }
    }
}

void event_edit::on_update_pushButton_clicked()
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

    if(local_checked)
    {
        dialog_lapi->update_event(ui->calendar_id_lineEdit->text(), event_id, new_cal_json);
    }
    else
    {
        dialog_gapi->edit_event(dialog_gapi->access_token, ui->calendar_id_lineEdit->text(), event_id, new_cal_json);
    }
    this->close();
}

void event_edit::on_summary_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->update_pushButton->setEnabled(false);
    }
    else
    {
        ui->update_pushButton->setEnabled(true);
    }
}

void event_edit::on_start_dateEdit_dateChanged()
{
    QDate start = QDate::fromString(ui->start_dateEdit->text(), "yyyy-MM-dd");
    QDate end = QDate::fromString(ui->end_dateEdit->text(), "yyyy-MM-dd");

    if(end < start)
    {
        ui->update_pushButton->setEnabled(false);
    }
    else
    {
        ui->update_pushButton->setEnabled(true);
    }
}


void event_edit::on_end_dateEdit_dateChanged()
{
    QDate start = QDate::fromString(ui->start_dateEdit->text(), "yyyy-MM-dd");
    QDate end = QDate::fromString(ui->end_dateEdit->text(), "yyyy-MM-dd");

    if(end < start)
    {
        ui->update_pushButton->setEnabled(false);
    }
    else
    {
        ui->update_pushButton->setEnabled(true);
    }
}
