/********************************************************************************
** Form generated from reading UI file 'calendar_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_EDIT_H
#define UI_CALENDAR_EDIT_H

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

class Ui_calendar_edit
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *calendar_id_lineEdit;
    QLabel *label_6;
    QLineEdit *summary_lineEdit;
    QLabel *label_7;
    QLineEdit *description_lineEdit;
    QLabel *label_8;
    QLineEdit *location_lineEdit;
    QPushButton *update_pushButton;

    void setupUi(QDialog *calendar_edit)
    {
        if (calendar_edit->objectName().isEmpty())
            calendar_edit->setObjectName(QStringLiteral("calendar_edit"));
        calendar_edit->resize(397, 256);
        calendar_edit->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        layoutWidget = new QWidget(calendar_edit);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 371, 225));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        calendar_id_lineEdit = new QLineEdit(layoutWidget);
        calendar_id_lineEdit->setObjectName(QStringLiteral("calendar_id_lineEdit"));

        verticalLayout_2->addWidget(calendar_id_lineEdit);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        summary_lineEdit = new QLineEdit(layoutWidget);
        summary_lineEdit->setObjectName(QStringLiteral("summary_lineEdit"));

        verticalLayout_2->addWidget(summary_lineEdit);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        description_lineEdit = new QLineEdit(layoutWidget);
        description_lineEdit->setObjectName(QStringLiteral("description_lineEdit"));

        verticalLayout_2->addWidget(description_lineEdit);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        location_lineEdit = new QLineEdit(layoutWidget);
        location_lineEdit->setObjectName(QStringLiteral("location_lineEdit"));

        verticalLayout_2->addWidget(location_lineEdit);

        update_pushButton = new QPushButton(layoutWidget);
        update_pushButton->setObjectName(QStringLiteral("update_pushButton"));

        verticalLayout_2->addWidget(update_pushButton);


        retranslateUi(calendar_edit);

        QMetaObject::connectSlotsByName(calendar_edit);
    } // setupUi

    void retranslateUi(QDialog *calendar_edit)
    {
        calendar_edit->setWindowTitle(QApplication::translate("calendar_edit", "Dialog", 0));
        calendar_id_lineEdit->setText(QString());
        label_6->setText(QApplication::translate("calendar_edit", "* Summary:", 0));
        label_7->setText(QApplication::translate("calendar_edit", "Description:", 0));
        label_8->setText(QApplication::translate("calendar_edit", "Location", 0));
        location_lineEdit->setText(QString());
        update_pushButton->setText(QApplication::translate("calendar_edit", "Update Calendar", 0));
    } // retranslateUi

};

namespace Ui {
    class calendar_edit: public Ui_calendar_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_EDIT_H
