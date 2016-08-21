#ifndef LOCAL_CALENDAR_H
#define LOCAL_CALENDAR_H

#include <QWidget>
#include <QObject>
#include <QMessageBox>
#include <QApplication>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QFile>
#include <QDir>
#include <QCoreApplication>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>
#include <QList>
#include <QMap>
#include <QListWidgetItem>
#include <QTextCodec>
#include <QUuid>

class local_calendar : public QWidget
{
    Q_OBJECT
public:
    explicit local_calendar(QWidget *parent = 0);
    QJsonDocument str_to_json_doc (QString str);
    QString open_file (QString filename);
    void save_file (QString filename, QString content);

    void create_calendar_list_template();
    void create_calendar(QString json);
    void delete_calendar(QString id_calendar);
    void update_calendar(QString id_calendar, QString json);

    void create_event(QString id_calendar, QString json);
    void delete_event(QString id_calendar, QString id_event);
    void update_event(QString id_calendar, QString id_event, QString json);

signals:

public slots:

};

#endif // LOCAL_CALENDAR_H
