#ifndef GCAL_API_H
#define GCAL_API_H

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
#include <QDate>
#include <QTime>
#include "lcal_api.h"

class gcal_api : public QWidget
{
  Q_OBJECT
public:
  explicit gcal_api (QWidget *parent = 0);

  QNetworkAccessManager *manageris;

  QVariantList calendar_list;
  QVariantList event_list;

  QVariantList get_calendar_list ();
  QVariantList get_event_list ();

  void getAccessTokenFromFile ();
  void getRefreshTokenFromFile ();

  void checkAccessToken ();
  void getFreshAccessToken ();

  QJsonDocument str_to_json_doc (QString str);

  QString open_file (QString filename);
  void save_file (QString filename, QString content);

  QString access_token;
  QString refresh_token;

  void local_calendar_to_google(QString access_token, QString local_calendar_id);
  void local_events_to_google_calendar();
  local_calendar *loc_cal;

  QString local_id;
  QString remote_id;


signals:
  void calendarListReady ();
  void calendarListChanged (QString remote_id);
  void eventsReady ();
  void eventListChanged(QString access_token, QString id);
  void eventChanged (QString access_token, QString id);
  void refresh_sig(QString s);

public slots:
  void reply_finished (QNetworkReply *rep);
  void get_calendar_list (QString access_token);
  void get_event_list (QString access_token, QString calendar_id);
  void create_calendar (QString access_token, QString json);
  void delete_calendar (QString access_token, QString calendar_id);
  void edit_calendar (QString access_token, QString calendar_id, QString json);
  void create_event (QString access_token, QString calendar_id, QString json);
  void delete_event (QString access_token, QString calendar_id, QString event_id);
  void edit_event(QString access_token, QString calendar_id, QString event_id, QString json);
  
  void checkAccessToken_finish (QNetworkReply *rep);
  void getFreshAccessToken_finish (QNetworkReply *rep);

  void get_calendar_id(QString remote_id);

};

#endif // GCAL_API_H
