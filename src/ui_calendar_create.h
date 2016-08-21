/********************************************************************************
** Form generated from reading UI file 'calendar_create.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_CREATE_H
#define UI_CALENDAR_CREATE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calendar_create
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLineEdit *summary_lineEdit;
    QLabel *label_5;
    QLineEdit *description_lineEdit;
    QLabel *label_6;
    QLineEdit *location_lineEdit;
    QPushButton *create_pushButton;

    void setupUi(QDialog *calendar_create)
    {
        if (calendar_create->objectName().isEmpty())
            calendar_create->setObjectName(QStringLiteral("calendar_create"));
        calendar_create->resize(420, 222);
        calendar_create->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        layoutWidget = new QWidget(calendar_create);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 371, 175));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        summary_lineEdit = new QLineEdit(layoutWidget);
        summary_lineEdit->setObjectName(QStringLiteral("summary_lineEdit"));

        verticalLayout_2->addWidget(summary_lineEdit);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        description_lineEdit = new QLineEdit(layoutWidget);
        description_lineEdit->setObjectName(QStringLiteral("description_lineEdit"));

        verticalLayout_2->addWidget(description_lineEdit);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        location_lineEdit = new QLineEdit(layoutWidget);
        location_lineEdit->setObjectName(QStringLiteral("location_lineEdit"));

        verticalLayout_2->addWidget(location_lineEdit);

        create_pushButton = new QPushButton(layoutWidget);
        create_pushButton->setObjectName(QStringLiteral("create_pushButton"));

        verticalLayout_2->addWidget(create_pushButton);


        retranslateUi(calendar_create);

        QMetaObject::connectSlotsByName(calendar_create);
    } // setupUi

    void retranslateUi(QDialog *calendar_create)
    {
        calendar_create->setWindowTitle(QApplication::translate("calendar_create", "Dialog", 0));
        label_4->setText(QApplication::translate("calendar_create", "* Summary:", 0));
        label_5->setText(QApplication::translate("calendar_create", "Description:", 0));
        label_6->setText(QApplication::translate("calendar_create", "Location", 0));
        location_lineEdit->setText(QString());
        create_pushButton->setText(QApplication::translate("calendar_create", "Create Calendar", 0));
    } // retranslateUi

};

namespace Ui {
    class calendar_create: public Ui_calendar_create {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_CREATE_H
