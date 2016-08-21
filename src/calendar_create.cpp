#include "calendar_create.h"
#include "ui_calendar_create.h"

calendar_create::calendar_create(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calendar_create)
{
    ui->setupUi(this);

    setWindowTitle("Calendar create");

    dialog_gapi = new gcal_api();
    dialog_gapi->getAccessTokenFromFile();
    dialog_lapi = new local_calendar();
    ui->create_pushButton->setEnabled(false);
    setFixedSize(size());
    connect(dialog_gapi, SIGNAL(calendarListReady()), this, SLOT(send()));
}

calendar_create::~calendar_create()
{
    delete ui;
}

void calendar_create::set_bool(bool local_checked)
{
    this->local_checked = local_checked;
    ui->summary_lineEdit->clear();
    ui->description_lineEdit->clear();
    ui->location_lineEdit->clear();
}

void calendar_create::on_summary_lineEdit_textChanged(const QString &arg1)
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

void calendar_create::on_create_pushButton_clicked()
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
        dialog_lapi->create_calendar(new_cal_json);
    }
    else
    {
        dialog_gapi->create_calendar(dialog_gapi->access_token, new_cal_json);
    }


    this->close();
}

void calendar_create::send()
{
    emit refresh();
}
