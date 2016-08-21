#include "calendar_edit.h"
#include "ui_calendar_edit.h"

calendar_edit::calendar_edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calendar_edit)
{
    ui->setupUi(this);

    setWindowTitle("Calendar edit");
    setFixedSize(size());
    ui->calendar_id_lineEdit->hide();
}

calendar_edit::~calendar_edit()
{
    delete ui;
}

void  calendar_edit::set_ID(gcal_api *g_api, QString id) {
 ui->calendar_id_lineEdit->setText(id);
 dialog_gapi = g_api;
 show_json();
}

void  calendar_edit::set_ID(local_calendar *local_cal, QString id) {
 ui->calendar_id_lineEdit->setText(id);
 dialog_lapi = local_cal;
 show_json();
}

void calendar_edit::show_json() {

   QString json;
   if(local_checked)
   {
       json = dialog_gapi->open_file("local_calendar_list.json");
   }
   else
   {
      json = dialog_gapi->open_file("calendar_list.json");
   }

 QJsonDocument json_doc = dialog_gapi->str_to_json_doc(json);
 QVariant var = json_doc.toVariant();
 QVariant data;

 for(int i = 0; i < var.toMap()["items"].toList().size(); ++i) {
   data = var.toMap()["items"].toList()[i].toMap()["id"];

   if(data == ui->calendar_id_lineEdit->text()) {
     ui->summary_lineEdit->setText(var.toMap()["items"].toList()[i].toMap()["summary"].toString());
     ui->description_lineEdit->setText(var.toMap()["items"].toList()[i].toMap()["description"].toString());
     ui->location_lineEdit->setText(var.toMap()["items"].toList()[i].toMap()["location"].toString());
     break;
   }
 }
}

void calendar_edit::on_summary_lineEdit_textChanged(const QString &arg1)
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

void calendar_edit::on_update_pushButton_clicked()
{
    QString new_cal_json;
    new_cal_json = QString("{\n") +
                   QString("\"summary\": \"" + ui->summary_lineEdit->text() + "\",\n") +
                   QString("\"description\": \"" + ui->description_lineEdit->text() + "\",\n") +
                   QString("\"location\": \"" + ui->location_lineEdit->text() + "\",\n") +
                   QString("\"kind\": \"calendar#calendar\"\n") +
                   QString("}");

    if(local_checked)
    {
        dialog_lapi->update_calendar(ui->calendar_id_lineEdit->text(), new_cal_json);
    }
    else
    {
        dialog_gapi->edit_calendar(dialog_gapi->access_token, ui->calendar_id_lineEdit->text(), new_cal_json);
    }
    this->close();
}
