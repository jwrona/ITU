/********************************************************************************
** Form generated from reading UI file 'interval_picker.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERVAL_PICKER_H
#define UI_INTERVAL_PICKER_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interval_picker
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *week_label;
    QPushButton *prev_week;
    QPushButton *next_week;
    QPushButton *actual_week;
    QLabel *label_5;
    QLabel *month_label;
    QPushButton *prew_month;
    QPushButton *next_month;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *interval_picker)
    {
        if (interval_picker->objectName().isEmpty())
            interval_picker->setObjectName(QStringLiteral("interval_picker"));
        interval_picker->setWindowModality(Qt::NonModal);
        interval_picker->resize(493, 360);
        interval_picker->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        buttonBox = new QDialogButtonBox(interval_picker);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 310, 471, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        widget = new QWidget(interval_picker);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 471, 281));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(65, 25));
        QFont font;
        font.setPointSize(10);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        week_label = new QLabel(widget);
        week_label->setObjectName(QStringLiteral("week_label"));
        week_label->setMaximumSize(QSize(228, 25));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        week_label->setFont(font1);

        gridLayout->addWidget(week_label, 0, 1, 1, 1);

        prev_week = new QPushButton(widget);
        prev_week->setObjectName(QStringLiteral("prev_week"));
        prev_week->setMaximumSize(QSize(37, 23));

        gridLayout->addWidget(prev_week, 0, 2, 1, 1);

        next_week = new QPushButton(widget);
        next_week->setObjectName(QStringLiteral("next_week"));
        next_week->setMaximumSize(QSize(37, 23));

        gridLayout->addWidget(next_week, 0, 3, 1, 1);

        actual_week = new QPushButton(widget);
        actual_week->setObjectName(QStringLiteral("actual_week"));
        actual_week->setMaximumSize(QSize(81, 23));

        gridLayout->addWidget(actual_week, 0, 4, 2, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(65, 25));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        month_label = new QLabel(widget);
        month_label->setObjectName(QStringLiteral("month_label"));
        month_label->setMaximumSize(QSize(228, 25));
        month_label->setFont(font1);
        month_label->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(month_label, 1, 1, 1, 1);

        prew_month = new QPushButton(widget);
        prew_month->setObjectName(QStringLiteral("prew_month"));
        prew_month->setMaximumSize(QSize(37, 23));

        gridLayout->addWidget(prew_month, 1, 2, 1, 1);

        next_month = new QPushButton(widget);
        next_month->setObjectName(QStringLiteral("next_month"));
        next_month->setMaximumSize(QSize(37, 23));

        gridLayout->addWidget(next_month, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        calendarWidget = new QCalendarWidget(widget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        calendarWidget->setInputMethodHints(Qt::ImhNone);
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(true);
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);
        calendarWidget->setDateEditAcceptDelay(1000);

        gridLayout_2->addWidget(calendarWidget, 0, 0, 1, 1);

        buttonBox->raise();
        calendarWidget->raise();
        label_4->raise();
        label_5->raise();
        prev_week->raise();
        next_week->raise();
        actual_week->raise();
        prew_month->raise();
        next_month->raise();
        actual_week->raise();
        actual_week->raise();
        next_week->raise();
        prev_week->raise();
        next_month->raise();
        prew_month->raise();
        actual_week->raise();
        week_label->raise();
        month_label->raise();
        label_4->raise();
        label_5->raise();

        retranslateUi(interval_picker);
        QObject::connect(buttonBox, SIGNAL(accepted()), interval_picker, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), interval_picker, SLOT(reject()));

        QMetaObject::connectSlotsByName(interval_picker);
    } // setupUi

    void retranslateUi(QDialog *interval_picker)
    {
        interval_picker->setWindowTitle(QApplication::translate("interval_picker", "Dialog", 0));
        label_4->setText(QApplication::translate("interval_picker", "Week:", 0));
        week_label->setText(QString());
        prev_week->setText(QApplication::translate("interval_picker", "<<", 0));
        next_week->setText(QApplication::translate("interval_picker", ">>", 0));
        actual_week->setText(QApplication::translate("interval_picker", "Current Week", 0));
        label_5->setText(QApplication::translate("interval_picker", "Month:", 0));
        month_label->setText(QString());
        prew_month->setText(QApplication::translate("interval_picker", "<<", 0));
        next_month->setText(QApplication::translate("interval_picker", ">>", 0));
    } // retranslateUi

};

namespace Ui {
    class interval_picker: public Ui_interval_picker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERVAL_PICKER_H
