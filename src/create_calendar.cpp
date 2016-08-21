#include "create_calendar.h"
#include "ui_create_calendar.h"

create_calendar::create_calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::create_calendar)
{
    ui->setupUi(this);

    lol = new gcal_api();
    lol->getAccessTokenFromFile();
    local_cal = new local_calendar();
    ui->create->setEnabled(false);
}

create_calendar::~create_calendar()
{
    delete ui;
}

void create_calendar::on_create_clicked()
{
    QString new_cal_json;
    new_cal_json = QString("{\n") +
            QString("\"summary\": \"" + ui->summary->text() + "\",\n") +
            QString("\"description\": \"" + ui->description->text() + "\",\n") +
            QString("\"location\": \"" + ui->location->text() + "\",\n") +
            QString("\"kind\": \"calendar#calendar\"\n") +
            QString("}");


    if(local_checked)
    {
        local_cal->create_calendar(new_cal_json);
    }
    else
    {
        lol->create_calendar(lol->access_token, new_cal_json);
    }


    this->close();
}

void create_calendar::on_summary_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->create->setEnabled(false);
    }
    else
    {
        ui->create->setEnabled(true);
    }
}
