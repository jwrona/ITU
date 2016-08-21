/********************************************************************************
** Form generated from reading UI file 'event_create.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENT_CREATE_H
#define UI_EVENT_CREATE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_event_create
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLineEdit *summary_lineEdit;
    QLineEdit *calendar_id_lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QGridLayout *gridLayout;
    QTimeEdit *start_timeEdit;
    QDateEdit *start_dateEdit;
    QLabel *label_6;
    QGridLayout *gridLayout_2;
    QDateEdit *end_dateEdit;
    QTimeEdit *end_timeEdit;
    QLabel *label_5;
    QLineEdit *location_lineEdit;
    QLineEdit *description_lineEdit;
    QPushButton *create_pushButton;

    void setupUi(QDialog *event_create)
    {
        if (event_create->objectName().isEmpty())
            event_create->setObjectName(QStringLiteral("event_create"));
        event_create->resize(654, 384);
        event_create->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        layoutWidget = new QWidget(event_create);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 631, 361));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        summary_lineEdit = new QLineEdit(layoutWidget);
        summary_lineEdit->setObjectName(QStringLiteral("summary_lineEdit"));

        gridLayout_3->addWidget(summary_lineEdit, 2, 0, 1, 1);

        calendar_id_lineEdit = new QLineEdit(layoutWidget);
        calendar_id_lineEdit->setObjectName(QStringLiteral("calendar_id_lineEdit"));

        gridLayout_3->addWidget(calendar_id_lineEdit, 0, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 5, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        start_timeEdit = new QTimeEdit(layoutWidget);
        start_timeEdit->setObjectName(QStringLiteral("start_timeEdit"));
        start_timeEdit->setWrapping(false);
        start_timeEdit->setCalendarPopup(true);

        gridLayout->addWidget(start_timeEdit, 0, 1, 1, 1);

        start_dateEdit = new QDateEdit(layoutWidget);
        start_dateEdit->setObjectName(QStringLiteral("start_dateEdit"));
        start_dateEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        start_dateEdit->setCurrentSection(QDateTimeEdit::YearSection);
        start_dateEdit->setCalendarPopup(true);
        start_dateEdit->setCurrentSectionIndex(0);
        start_dateEdit->setTimeSpec(Qt::LocalTime);

        gridLayout->addWidget(start_dateEdit, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 4, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 9, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        end_dateEdit = new QDateEdit(layoutWidget);
        end_dateEdit->setObjectName(QStringLiteral("end_dateEdit"));
        end_dateEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        end_dateEdit->setCurrentSection(QDateTimeEdit::YearSection);
        end_dateEdit->setDisplayFormat(QStringLiteral("yyyy-MM-dd"));
        end_dateEdit->setCalendarPopup(true);
        end_dateEdit->setTimeSpec(Qt::LocalTime);

        gridLayout_2->addWidget(end_dateEdit, 0, 0, 1, 1);

        end_timeEdit = new QTimeEdit(layoutWidget);
        end_timeEdit->setObjectName(QStringLiteral("end_timeEdit"));

        gridLayout_2->addWidget(end_timeEdit, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 6, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 7, 0, 1, 1);

        location_lineEdit = new QLineEdit(layoutWidget);
        location_lineEdit->setObjectName(QStringLiteral("location_lineEdit"));

        gridLayout_3->addWidget(location_lineEdit, 8, 0, 1, 1);

        description_lineEdit = new QLineEdit(layoutWidget);
        description_lineEdit->setObjectName(QStringLiteral("description_lineEdit"));

        gridLayout_3->addWidget(description_lineEdit, 10, 0, 1, 1);

        create_pushButton = new QPushButton(layoutWidget);
        create_pushButton->setObjectName(QStringLiteral("create_pushButton"));

        gridLayout_3->addWidget(create_pushButton, 11, 0, 1, 1);


        retranslateUi(event_create);

        QMetaObject::connectSlotsByName(event_create);
    } // setupUi

    void retranslateUi(QDialog *event_create)
    {
        event_create->setWindowTitle(QApplication::translate("event_create", "Dialog", 0));
        label_2->setText(QApplication::translate("event_create", "* Summary:", 0));
        label_3->setText(QApplication::translate("event_create", "* Start (yyy-mm-dd) :", 0));
        label_4->setText(QApplication::translate("event_create", "* End (yyy-mm-dd) :", 0));
        start_timeEdit->setDisplayFormat(QApplication::translate("event_create", "HH:mm", 0));
        start_dateEdit->setSpecialValueText(QString());
        start_dateEdit->setDisplayFormat(QApplication::translate("event_create", "yyyy-MM-dd", 0));
        label_6->setText(QApplication::translate("event_create", "Description:", 0));
        end_dateEdit->setSpecialValueText(QString());
        end_timeEdit->setDisplayFormat(QApplication::translate("event_create", "HH:mm", 0));
        label_5->setText(QApplication::translate("event_create", "Location:", 0));
        location_lineEdit->setText(QString());
        description_lineEdit->setText(QString());
        create_pushButton->setText(QApplication::translate("event_create", "Create event", 0));
    } // retranslateUi

};

namespace Ui {
    class event_create: public Ui_event_create {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENT_CREATE_H
