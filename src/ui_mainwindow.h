/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QListWidget *calendar_list_listWidget;
    QPushButton *send_code_pushButton;
    QListWidget *event_list_listWidget;
    QLineEdit *calendar_id_lineEdit;
    QLineEdit *event_id_lineEdit;
    QPushButton *event_edit_pushButton;
    QLineEdit *send_code_lineEdit;
    QPushButton *event_delete_pushButton;
    QPushButton *event_create_pushButton;
    QPushButton *calendar_create_pushButton;
    QPushButton *calendar_edit_pushButton;
    QPushButton *refresh_pushButton;
    QPushButton *calendar_delete_pushButton;
    QLabel *label_2;
    QRadioButton *local_calendar_checkBox;
    QPushButton *login_pushButton;
    QRadioButton *remote_calendar_checkBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(827, 492);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 801, 431));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 3, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 8);

        calendar_list_listWidget = new QListWidget(layoutWidget);
        calendar_list_listWidget->setObjectName(QStringLiteral("calendar_list_listWidget"));

        gridLayout->addWidget(calendar_list_listWidget, 4, 0, 1, 4);

        send_code_pushButton = new QPushButton(layoutWidget);
        send_code_pushButton->setObjectName(QStringLiteral("send_code_pushButton"));

        gridLayout->addWidget(send_code_pushButton, 1, 7, 1, 1);

        event_list_listWidget = new QListWidget(layoutWidget);
        event_list_listWidget->setObjectName(QStringLiteral("event_list_listWidget"));

        gridLayout->addWidget(event_list_listWidget, 4, 4, 1, 4);

        calendar_id_lineEdit = new QLineEdit(layoutWidget);
        calendar_id_lineEdit->setObjectName(QStringLiteral("calendar_id_lineEdit"));

        gridLayout->addWidget(calendar_id_lineEdit, 5, 0, 1, 4);

        event_id_lineEdit = new QLineEdit(layoutWidget);
        event_id_lineEdit->setObjectName(QStringLiteral("event_id_lineEdit"));

        gridLayout->addWidget(event_id_lineEdit, 5, 4, 1, 4);

        event_edit_pushButton = new QPushButton(layoutWidget);
        event_edit_pushButton->setObjectName(QStringLiteral("event_edit_pushButton"));

        gridLayout->addWidget(event_edit_pushButton, 6, 6, 1, 1);

        send_code_lineEdit = new QLineEdit(layoutWidget);
        send_code_lineEdit->setObjectName(QStringLiteral("send_code_lineEdit"));

        gridLayout->addWidget(send_code_lineEdit, 1, 0, 1, 7);

        event_delete_pushButton = new QPushButton(layoutWidget);
        event_delete_pushButton->setObjectName(QStringLiteral("event_delete_pushButton"));

        gridLayout->addWidget(event_delete_pushButton, 6, 7, 1, 1);

        event_create_pushButton = new QPushButton(layoutWidget);
        event_create_pushButton->setObjectName(QStringLiteral("event_create_pushButton"));

        gridLayout->addWidget(event_create_pushButton, 6, 5, 1, 1);

        calendar_create_pushButton = new QPushButton(layoutWidget);
        calendar_create_pushButton->setObjectName(QStringLiteral("calendar_create_pushButton"));

        gridLayout->addWidget(calendar_create_pushButton, 6, 1, 1, 1);

        calendar_edit_pushButton = new QPushButton(layoutWidget);
        calendar_edit_pushButton->setObjectName(QStringLiteral("calendar_edit_pushButton"));

        gridLayout->addWidget(calendar_edit_pushButton, 6, 2, 1, 1);

        refresh_pushButton = new QPushButton(layoutWidget);
        refresh_pushButton->setObjectName(QStringLiteral("refresh_pushButton"));
        refresh_pushButton->setStyleSheet(QStringLiteral("background-color: transparent;"));

        gridLayout->addWidget(refresh_pushButton, 6, 0, 1, 1);

        calendar_delete_pushButton = new QPushButton(layoutWidget);
        calendar_delete_pushButton->setObjectName(QStringLiteral("calendar_delete_pushButton"));

        gridLayout->addWidget(calendar_delete_pushButton, 6, 3, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 4, 1, 2);

        local_calendar_checkBox = new QRadioButton(layoutWidget);
        local_calendar_checkBox->setObjectName(QStringLiteral("local_calendar_checkBox"));

        gridLayout->addWidget(local_calendar_checkBox, 0, 0, 1, 1);

        login_pushButton = new QPushButton(layoutWidget);
        login_pushButton->setObjectName(QStringLiteral("login_pushButton"));

        gridLayout->addWidget(login_pushButton, 0, 2, 1, 1);

        remote_calendar_checkBox = new QRadioButton(layoutWidget);
        remote_calendar_checkBox->setObjectName(QStringLiteral("remote_calendar_checkBox"));

        gridLayout->addWidget(remote_calendar_checkBox, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Calendars:", 0));
        send_code_pushButton->setText(QApplication::translate("MainWindow", "Send Code", 0));
        event_edit_pushButton->setText(QApplication::translate("MainWindow", "Edit", 0));
        event_delete_pushButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        event_create_pushButton->setText(QApplication::translate("MainWindow", "Create", 0));
        calendar_create_pushButton->setText(QApplication::translate("MainWindow", "Create", 0));
        calendar_edit_pushButton->setText(QApplication::translate("MainWindow", "Edit", 0));
        refresh_pushButton->setText(QString());
        calendar_delete_pushButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        label_2->setText(QApplication::translate("MainWindow", "Events:", 0));
        local_calendar_checkBox->setText(QApplication::translate("MainWindow", "Local Calendar", 0));
        login_pushButton->setText(QApplication::translate("MainWindow", "Login to Google", 0));
        remote_calendar_checkBox->setText(QApplication::translate("MainWindow", "Google Calendar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
