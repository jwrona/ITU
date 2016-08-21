#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <string.h>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QFile>
#include <QDir>
#include <QCoreApplication>
#include <QTextStream>
#include <QListWidgetItem>
#include <QEvent>
#include <QWidget>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#include <QList>
#include <QMap>

#include <QDebug>

#include "oauth2.h"

#include "calendar_create.h"
#include "calendar_edit.h"

#include "event_create.h"
#include "event_edit.h"

#include "gcal_api.h"
#include "lcal_api.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    OAuth2 *m_pOAuth2;
    QNetworkAccessManager *nwam;
    QNetworkReply *requestApi (QNetworkAccessManager &nwam);

    calendar_create *calendar_create_dialog;
    calendar_edit *calendar_edit_dialog;

    event_create *event_create_dialog;
    event_edit *event_edit_dialog;

    gcal_api *g_api;
    local_calendar *l_api;

    QMap<int, QString> cal_map;
    QMap<int, QString> event_map;

    QMap<int, QString> cal_local_map;
    QMap<int, QString> event_local_map;

    void test ();
    void test2 (QString calendar_id);
    bool checked;
    QString glob_ID;

public slots:
    void on_calendar_create_pushButton_clicked();

    void on_calendar_edit_pushButton_clicked();

    void on_calendar_delete_pushButton_clicked();

    void on_event_create_pushButton_clicked();

    void on_event_edit_pushButton_clicked();

    void on_event_delete_pushButton_clicked();

    void on_login_pushButton_clicked();

    void on_send_code_pushButton_clicked();

    void on_local_calendar_checkBox_toggled();

    void on_refresh_pushButton_clicked();

    void send_code_finish(QNetworkReply*);

    void refresh_calendar_list();
    void refresh_event_list (QString calendar_id);

    void on_calendar_list_listWidget_itemClicked();
    void on_event_list_listWidget_itemClicked(QListWidgetItem *item);

    void closeEvent(QCloseEvent *event);

signals:
    void closed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
