#include "gcal_api.h"

gcal_api::gcal_api (QWidget *parent) :
  QWidget (parent)
{
    manageris = new QNetworkAccessManager (this);
    connect (manageris, SIGNAL (finished (QNetworkReply *)), this, SLOT (reply_finished (QNetworkReply *)));

    connect(this, SIGNAL(calendarListChanged(QString)), this, SLOT(get_calendar_list(QString)));


    connect(this, SIGNAL(eventChanged(QString, QString)), this, SLOT(get_event_list(QString, QString)));

    loc_cal = new local_calendar();
}

QJsonDocument gcal_api::str_to_json_doc (QString str)
{
  return QJsonDocument::fromJson (str.toUtf8 ());
}

//// open file
QString gcal_api::open_file (QString filename)
{

  QString tmp;
  QFile file;
  file.setFileName ("data/" + filename);
  qDebug () << file.fileName ();
//  qDebug () << file.open (QIODevice::ReadOnly | QIODevice::Text);
  file.open (QIODevice::ReadOnly | QIODevice::Text);
  tmp = file.readAll ();
  file.close();
  return tmp;
}

//// save file
void gcal_api::save_file (QString filename, QString content)
{
  if (!QDir ("data").exists ())
  {
    QDir ().mkdir ("data");
  }

  QFile file ("data/" + filename);
  file.open (QIODevice::WriteOnly | QIODevice::Text);
  QTextStream out (&file);
  out << content;
  file.close ();
}

//// access token
void gcal_api::getAccessTokenFromFile ()
{
  QString json = open_file ("access.json");
  QJsonDocument json_doc = str_to_json_doc (json);
  QVariant var = json_doc.toVariant ();

  access_token = var.toMap ()["access_token"].toString ();
}

//// refresh token
void gcal_api::getRefreshTokenFromFile ()
{
  QString json = open_file ("refresh.json");
  QJsonDocument json_doc = str_to_json_doc (json);
  QVariant var = json_doc.toVariant ();

  refresh_token = var.toMap ()["refresh_token"].toString ();
}

//// check accesstoken
void gcal_api::checkAccessToken ()
{
  QUrl url ("https://www.googleapis.com/oauth2/v2/tokeninfo?access_token=" + access_token);

  QNetworkRequest req (url);
  req.setHeader (QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

  QNetworkAccessManager *mgr = new QNetworkAccessManager (this);
  connect (mgr, SIGNAL (finished (QNetworkReply *)), this, SLOT (checkAccessToken_finish (QNetworkReply *)));
  connect (mgr, SIGNAL (finished (QNetworkReply *)), mgr, SLOT (deleteLater ()));

  mgr->get (req);
}

//// check accesstoken finish
void gcal_api::checkAccessToken_finish (QNetworkReply *rep)
{
  QVariant statusCode = rep->attribute (QNetworkRequest::HttpStatusCodeAttribute);

  int status = statusCode.toInt ();

  if (!statusCode.isValid ())
  {
    return;
  }

  if (status == 200)
  {
    QByteArray barr = rep->readAll ();
    QString json (barr);

    QJsonDocument json_doc =  str_to_json_doc (json);
    QVariant var = json_doc.toVariant ();
  }
  else if (status == 400)
  {
    getRefreshTokenFromFile ();
    getFreshAccessToken ();
  }
}

void gcal_api::getFreshAccessToken ()
{
  QByteArray data;

  QUrl url ("https://accounts.google.com/o/oauth2/token");

  data.append ("client_id=876312718797.apps.googleusercontent.com&");
  data.append ("client_secret=SW1yXwVo_Ziq2-ieUVGw-Yex&");
  data.append ("grant_type=refresh_token&");
  data.append ("refresh_token=" + refresh_token);

  QNetworkRequest req (url);
  req.setHeader (QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

  QNetworkAccessManager *mgr = new QNetworkAccessManager (this);
  connect (mgr, SIGNAL (finished (QNetworkReply *)), this, SLOT (getFreshAccessToken_finish (QNetworkReply *)));
  connect (mgr, SIGNAL (finished (QNetworkReply *)), mgr, SLOT (deleteLater ()));

  mgr->post (req, data);
}

void gcal_api::getFreshAccessToken_finish (QNetworkReply *rep)
{
  QVariant statusCode = rep->attribute (QNetworkRequest::HttpStatusCodeAttribute);

  if (!statusCode.isValid ())
  {
    return;
  }

  int status = statusCode.toInt ();

  if (status != 200)
  {
    QString reason = rep->attribute (QNetworkRequest::HttpReasonPhraseAttribute).toString ();
//    QMessageBox::critical (this, "Error", "Erron in function 'getFreshAccessToken_finish' " + statusCode.toString () + ": " + reason + "\n" + rep->readAll (), "Ok");
  }
  else
  {
    QByteArray barr = rep->readAll ();
    QString json (barr);

    QJsonDocument json_doc =  str_to_json_doc (json);
    QVariant var = json_doc.toVariant ();

    access_token = var.toMap ()["access_token"].toString ();
    save_file ("access.json", json);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

void gcal_api::reply_finished (QNetworkReply *rep)
{
    // QApplication::restoreOverrideCursor ();
    // qDebug () << __FUNCTION__;
    // QString json = reply->readAll ();
    // qDebug () << "Reply = " << json;
    // qDebug () << "URL = " << reply->url ();
    // QString strUrl = reply->url ().toString ();

    QVariant statusCode = rep->attribute (QNetworkRequest::HttpStatusCodeAttribute);

    if (!statusCode.isValid ())
    {
        QMessageBox::critical (this, "Error", "Undefined HTTP error!", "Ok");
        return;
    }

    int status = statusCode.toInt ();

    if (status != 200 && status != 204)
    {
        QString reason = rep->attribute (QNetworkRequest::HttpReasonPhraseAttribute).toString ();
//        QMessageBox::critical (this, "Error", "Erron in function '"+ QString(__FUNCTION__) +"' " + statusCode.toString () + ": " + reason + "\n" + rep->readAll (), "Ok");
    }
    else
    {
        QString reason = rep->attribute (QNetworkRequest::HttpReasonPhraseAttribute).toString ();
        //QMessageBox::critical (this, "Error", "Erron in function '"+ QString(__FUNCTION__) +"' " + statusCode.toString () + ": " + reason + "\n" + rep->readAll (), "Ok");
        QByteArray barr = rep->readAll ();
        QString str_json (barr);

        QJsonDocument json_doc = str_to_json_doc(str_json);
        QVariant var_json = json_doc.toVariant ();

        if(status == 204)
        {
            qDebug() << "204";
            emit calendarListChanged ("");
        }

        if (var_json.toMap()["kind"].toString () == "calendar#calendarList")
        {
          qDebug() << "calendar#calendarList";
          save_file("calendar_list.json" , str_json);
          calendar_list = var_json.toMap ()["items"].toList ();
          emit calendarListReady ();
        }

        else if (var_json.toMap ()["kind"].toString () == "calendar#calendar")
        {
            qDebug() << "calendar#calendar";
            save_file("calendar_list.json" , str_json);
            emit calendarListChanged (var_json.toMap ()["id"].toString ());
        }

        else if (var_json.toMap ()["kind"].toString () == "calendar#events")
        {
            qDebug() << "calendar#events";
//          int end = rep->url().toString().toStdString().find("/events");
//          qDebug() << rep->url().toString().mid(49, end - 49);

          QString tmp =  rep->url().toString();
          tmp = tmp.replace("%23", "#");
          tmp = tmp.remove(0, 49);
          tmp = tmp.remove(tmp.indexOf("/events"), tmp.length());

          save_file(tmp + ".json" , str_json);

          event_list = var_json.toMap ()["items"].toList ();
          emit eventsReady ();
        }

        else if (var_json.toMap ()["kind"].toString () == "calendar#event")
        {
            qDebug() << "calendar#event";
            qDebug() << var_json.toMap ()["id"].toString ();

            QString tmp =  rep->url().toString();
            tmp = tmp.replace("%23", "#");
            tmp = tmp.remove(0, 49);
            tmp = tmp.remove(tmp.indexOf("/events"), tmp.length());
          emit eventChanged (this->access_token, tmp);
        }

    }
}


void gcal_api::get_calendar_list (QString access_token)
{
  QUrl url ("https://www.googleapis.com/calendar/v3/users/me/calendarList?access_token=" + this->access_token);
  QNetworkRequest req (url);
  manageris->get (req);
}

void gcal_api::get_event_list (QString access_token, QString calendar_id)
{
    qDebug() << "marhaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!!!";
    qDebug() << calendar_id;
  QUrl url ("https://www.googleapis.com/calendar/v3/calendars/" + QUrl::toPercentEncoding (calendar_id) + "/events?access_token=" + this->access_token + "&timeMin=" + QDate::currentDate().addDays(-7).toString("yyyy-MM-dd") + "T00:00:00Z"+"&timeMax=" + QDate::QDate::currentDate().addYears(1).toString("yyyy-MM-dd") + "T00:00:00Z");
  QNetworkRequest req (url);
  manageris->get (req);
}

QVariantList gcal_api::get_calendar_list ()
{
  return calendar_list;
}

QVariantList gcal_api::get_event_list ()
{
  return event_list;
}

void gcal_api::create_calendar (QString access_token, QString json)
{
  QUrl url ("https://www.googleapis.com/calendar/v3/calendars?access_token=" + access_token);

  QByteArray data;
  data.append (json);

  QNetworkRequest req (url);
  req.setHeader (QNetworkRequest::ContentTypeHeader, "application/json");
  manageris->post (req, data);
}

void gcal_api::delete_calendar (QString access_token, QString calendar_id)
{
  QFile::remove(QString("data/" + calendar_id + ".json"));
  QUrl url ("https://www.googleapis.com/calendar/v3/calendars/" + QUrl::toPercentEncoding (calendar_id) + "?access_token=" + access_token);
  QNetworkRequest req (url);
  manageris->deleteResource (req);
}

void gcal_api::edit_calendar (QString access_token, QString calendar_id, QString json)
{
  QUrl url ("https://www.googleapis.com/calendar/v3/calendars/" + QUrl::toPercentEncoding (calendar_id) + "?access_token=" + access_token);

  QByteArray data;
  data.append (json);

  QNetworkRequest req (url);
  req.setHeader (QNetworkRequest::ContentTypeHeader, "application/json");
  manageris->put (req, data);

}

void gcal_api::create_event (QString access_token, QString calendar_id, QString json)
{
  QUrl url ("https://www.googleapis.com/calendar/v3/calendars/" + QUrl::toPercentEncoding (calendar_id) + "/events?access_token=" + access_token);

  QByteArray data;
  data.append (json);
  QNetworkRequest req (url);
  req.setHeader (QNetworkRequest::ContentTypeHeader, "application/json");
  manageris->post (req, data);
}

void gcal_api::delete_event (QString access_token, QString calendar_id, QString event_id)
{
  QUrl url ("https://www.googleapis.com/calendar/v3/calendars/" + QUrl::toPercentEncoding (calendar_id) + "/events/" + QUrl::toPercentEncoding (event_id) + "?access_token=" + access_token);
  QNetworkRequest req (url);
  manageris->deleteResource (req);
}

void gcal_api::edit_event(QString access_token, QString calendar_id, QString event_id, QString json)
{
    QUrl url("https://www.googleapis.com/calendar/v3/calendars/" + QUrl::toPercentEncoding (calendar_id) + "/events/" + QUrl::toPercentEncoding (event_id) + "?access_token=" + access_token);

    QByteArray data;
    data.append (json);

    QNetworkRequest req (url);
    req.setHeader (QNetworkRequest::ContentTypeHeader, "application/json");
    manageris->put (req, data);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

void gcal_api::local_calendar_to_google(QString access_token, QString local_calendar_id)
{
    QString json_calendar_list = open_file("local_calendar_list.json");
    QString final_json;

    QJsonDocument json_doc = str_to_json_doc(json_calendar_list);
    QVariant var = json_doc.toVariant();
    QVariant data;

    for(int i = 0; i < var.toMap()["items"].toList().size(); i++) {
      data = var.toMap()["items"].toList()[i].toMap()["id"];

      if(data == local_calendar_id) {
      final_json = QString("{\n") +
                   QString("\"summary\": \"" + var.toMap()["items"].toList()[i].toMap()["summary"].toString() + "\",\n") +
                   QString("\"description\": \"" + var.toMap()["items"].toList()[i].toMap()["description"].toString() + "\",\n") +
                   QString("\"location\": \"" + var.toMap()["items"].toList()[i].toMap()["location"].toString() + "\",\n") +
                   QString("\"kind\": \"calendar#calendar\"\n") +
                   QString("}");
      break;
      }
    }
    local_id = local_calendar_id;
    create_calendar(access_token, final_json);
}


void gcal_api::get_calendar_id(QString remote_id)
{
    this->remote_id = remote_id;
    local_events_to_google_calendar();
}


void gcal_api::local_events_to_google_calendar()
{
    QString json = open_file(local_id + ".json");
    QJsonDocument json_doc = str_to_json_doc(json);
    QVariant var = json_doc.toVariant();
    QString final_json;

    for(int i = 0; i < var.toMap()["items"].toList().size(); i++) {
      final_json = QString("{\n") +
                   QString("\"end\": {\n") +
                   QString("\"dateTime\": \"" + var.toMap()["items"].toList()[0].toMap()["end"].toMap()["dateTime"].toString().left(10) + "T" + var.toMap()["items"].toList()[0].toMap()["end"].toMap()["dateTime"].toString().mid(11,8) + ":00Z" +"\"\n},\n") +
                   QString("\"start\": {\n") +
                   QString("\"dateTime\": \"" + var.toMap()["items"].toList()[0].toMap()["start"].toMap()["dateTime"].toString().left(10) + "T" + var.toMap()["items"].toList()[0].toMap()["start"].toMap()["dateTime"].toString().mid(11,8) + ":00Z" + "\"\n},\n") +
                   QString("\"location\": \"" + var.toMap()["items"].toList()[i].toMap()["location"].toString() + "\",\n") +
                   QString("\"description\": \"" + var.toMap()["items"].toList()[i].toMap()["description"].toString() + "\",\n") +
                   QString("\"summary\": \"" + var.toMap()["items"].toList()[i].toMap()["summary"].toString() + "\"\n") +
                   QString("}");
//       create_event(access_token, remote_id, final_json);
    }



//    loc_cal->delete_calendar(local_id);
}



























