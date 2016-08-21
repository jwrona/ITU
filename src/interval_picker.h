#ifndef INTERVAL_PICKER_H
#define INTERVAL_PICKER_H

#include <QDialog>
#include <QDate>

namespace Ui {
class interval_picker;
}

class interval_picker : public QDialog
{
    Q_OBJECT

public:
    explicit interval_picker(QWidget *parent = 0);
    ~interval_picker();

    QDate get_actdate();

private slots:
    void on_buttonBox_accepted();

    void on_calendarWidget_selectionChanged();

    void on_prev_week_clicked();

    void on_next_week_clicked();

    void on_actual_week_clicked();

    void on_prew_month_clicked();

    void on_next_month_clicked();

private:
    Ui::interval_picker *ui;
};

#endif // INTERVAL_PICKER_H
