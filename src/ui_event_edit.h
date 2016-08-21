/********************************************************************************
** Form generated from reading UI file 'event_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENT_EDIT_H
#define UI_EVENT_EDIT_H

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

class Ui_event_edit
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QGridLayout *gridLayout;
    QDateEdit *start_dateEdit;
    QTimeEdit *start_timeEdit;
    QGridLayout *gridLayout_2;
    QDateEdit *end_dateEdit;
    QTimeEdit *end_timeEdit;
    QLabel *label_5;
    QLabel *label_2;
    QLineEdit *summary_lineEdit;
    QLineEdit *calendar_id_lineEdit;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *description_lineEdit;
    QLineEdit *location_lineEdit;
    QPushButton *update_pushButton;

    void setupUi(QDialog *event_edit)
    {
        if (event_edit->objectName().isEmpty())
            event_edit->setObjectName(QStringLiteral("event_edit"));
        event_edit->resize(662, 351);
        event_edit->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        layoutWidget = new QWidget(event_edit);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 641, 331));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 5, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        start_dateEdit = new QDateEdit(layoutWidget);
        start_dateEdit->setObjectName(QStringLiteral("start_dateEdit"));
        start_dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(start_dateEdit, 0, 0, 1, 1);

        start_timeEdit = new QTimeEdit(layoutWidget);
        start_timeEdit->setObjectName(QStringLiteral("start_timeEdit"));

        gridLayout->addWidget(start_timeEdit, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 4, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        end_dateEdit = new QDateEdit(layoutWidget);
        end_dateEdit->setObjectName(QStringLiteral("end_dateEdit"));
        end_dateEdit->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        end_dateEdit->setCalendarPopup(true);
        end_dateEdit->setTimeSpec(Qt::UTC);

        gridLayout_2->addWidget(end_dateEdit, 0, 0, 1, 1);

        end_timeEdit = new QTimeEdit(layoutWidget);
        end_timeEdit->setObjectName(QStringLiteral("end_timeEdit"));

        gridLayout_2->addWidget(end_timeEdit, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 6, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 7, 0, 1, 1);

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

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 9, 0, 1, 1);

        description_lineEdit = new QLineEdit(layoutWidget);
        description_lineEdit->setObjectName(QStringLiteral("description_lineEdit"));

        gridLayout_3->addWidget(description_lineEdit, 10, 0, 1, 1);

        location_lineEdit = new QLineEdit(layoutWidget);
        location_lineEdit->setObjectName(QStringLiteral("location_lineEdit"));

        gridLayout_3->addWidget(location_lineEdit, 8, 0, 1, 1);

        update_pushButton = new QPushButton(layoutWidget);
        update_pushButton->setObjectName(QStringLiteral("update_pushButton"));

        gridLayout_3->addWidget(update_pushButton, 11, 0, 1, 1);


        retranslateUi(event_edit);

        QMetaObject::connectSlotsByName(event_edit);
    } // setupUi

    void retranslateUi(QDialog *event_edit)
    {
        event_edit->setWindowTitle(QApplication::translate("event_edit", "Dialog", 0));
        label_4->setText(QApplication::translate("event_edit", "* End (yyy-mm-dd) :", 0));
        start_dateEdit->setDisplayFormat(QApplication::translate("event_edit", "yyyy-MM-dd", 0));
        start_timeEdit->setDisplayFormat(QApplication::translate("event_edit", "HH:mm", 0));
        end_dateEdit->setDisplayFormat(QApplication::translate("event_edit", "yyyy-MM-dd", 0));
        end_timeEdit->setDisplayFormat(QApplication::translate("event_edit", "HH:mm", 0));
        label_5->setText(QApplication::translate("event_edit", "Location:", 0));
        label_2->setText(QApplication::translate("event_edit", "* Summary :", 0));
        label_3->setText(QApplication::translate("event_edit", "* Start (yyy-mm-dd) :", 0));
        label_6->setText(QApplication::translate("event_edit", "Description:", 0));
        description_lineEdit->setText(QString());
        location_lineEdit->setText(QString());
        update_pushButton->setText(QApplication::translate("event_edit", "Update event", 0));
    } // retranslateUi

};

namespace Ui {
    class event_edit: public Ui_event_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENT_EDIT_H
