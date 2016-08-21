#include "interval_picker.h"
#include "ui_interval_picker.h"

interval_picker::interval_picker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interval_picker)
{
    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
    ui->setupUi(this);

    QIcon icon("tray_icon.png");
    setWindowIcon(icon);
    setWindowTitle("Select date");
    setFixedSize(size());
    ui->calendarWidget->setSelectedDate(QDate::currentDate().addDays(1-QDate::currentDate().dayOfWeek()));
    ui->calendarWidget->setFocus();
    ui->calendarWidget->hasFocus();
}

interval_picker::~interval_picker()
{
    delete ui;
}

void interval_picker::on_buttonBox_accepted()
{
    this->setResult(QDialog::Accepted);
}

QDate interval_picker::get_actdate()
{
    return ui->calendarWidget->selectedDate();
}

void interval_picker::on_calendarWidget_selectionChanged()
{
    if (ui->calendarWidget->selectedDate().dayOfWeek() != 1)
    {
       ui->calendarWidget->setSelectedDate(ui->calendarWidget->selectedDate().addDays(1-ui->calendarWidget->selectedDate().dayOfWeek()));
    }

    ui->week_label->setText(QString::number(ui->calendarWidget->selectedDate().weekNumber())+QString(". ")+QString::number(ui->calendarWidget->selectedDate().year()) );
    ui->month_label->setText(QDate::longMonthName(ui->calendarWidget->selectedDate().month())+QString(", ")+QString::number(ui->calendarWidget->selectedDate().year()));
    ui->calendarWidget->setFocus();
}

void interval_picker::on_prev_week_clicked()
{
    ui->calendarWidget->setSelectedDate(ui->calendarWidget->selectedDate().addDays(-7));
    ui->calendarWidget->setFocus();
}

void interval_picker::on_next_week_clicked()
{
    ui->calendarWidget->setSelectedDate(ui->calendarWidget->selectedDate().addDays(+7));
    ui->calendarWidget->setFocus();
}

void interval_picker::on_actual_week_clicked()
{
    ui->calendarWidget->setSelectedDate(QDate::currentDate().addDays(1-QDate::currentDate().dayOfWeek()));
    ui->calendarWidget->setFocus();
}

void interval_picker::on_prew_month_clicked()
{
    ui->calendarWidget->setSelectedDate(ui->calendarWidget->selectedDate().addMonths(-1));
    ui->calendarWidget->setFocus();
}

void interval_picker::on_next_month_clicked()
{
    ui->calendarWidget->setSelectedDate(ui->calendarWidget->selectedDate().addMonths(+1));
    ui->calendarWidget->setFocus();
}
