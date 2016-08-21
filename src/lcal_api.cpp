#include "lcal_api.h"

local_calendar::local_calendar(QWidget *parent) :
    QWidget(parent)
{
    QFile file("data/local_calendar_list.json");

    if(!file.exists())
    {
        create_calendar_list_template();
    }
}

QJsonDocument local_calendar::str_to_json_doc (QString str)
{
  return QJsonDocument::fromJson (str.toUtf8 ());
}

//// open file
QString local_calendar::open_file (QString filename)
{
  QString tmp;
  QFile file;
  file.setFileName ("data/" + filename);
  qDebug () << file.fileName ();
  qDebug () << file.open (QIODevice::ReadOnly | QIODevice::Text);
  file.open (QIODevice::ReadOnly | QIODevice::Text);
  tmp = file.readAll ();
  file.close();
  return tmp;
}

//// save file
void local_calendar::save_file (QString filename, QString content)
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

void local_calendar::create_calendar_list_template()
{
    QString new_cal_json;
    new_cal_json = QString("{\n") +
                   QString("\"kind\": \"calendar#calendarList\",\n") +
                   QString("\"items\": []\n") +
                   QString("}");

    save_file("local_calendar_list.json", new_cal_json);
}



void local_calendar::create_calendar(QString json)
{
    QString data_file = open_file ("local_calendar_list.json");

    QJsonDocument json_doc =  str_to_json_doc (data_file);
    QJsonDocument json_input = str_to_json_doc (json);

    QJsonObject obj = json_doc.object();
    QJsonObject o = json_input.object();

    o.insert(QString("id"), QUuid::createUuid().toString());

    QJsonArray arr(obj[QString("items")].toArray());
    arr.append(o);
    obj.insert(QString("items"), arr);

    QJsonDocument final(obj);

    save_file("local_calendar_list.json", final.toJson());
}

void local_calendar::delete_calendar(QString id_calendar)
{
    QFile::remove(QString("data/" + id_calendar + ".json"));

    QString data_file = open_file ("local_calendar_list.json");

    QJsonDocument json_doc =  str_to_json_doc (data_file);
    QJsonObject obj = json_doc.object();

    QJsonArray arr(obj[QString("items")].toArray());

    for (qint8 i = 0; i != arr.size (); i++)
    {
        if(arr[i].toObject()["id"].toString() == id_calendar)
        {
            arr.removeAt(i);
            break;
        }
    }
    obj.insert(QString("items"), arr);

    QJsonDocument final(obj);
    save_file("local_calendar_list.json", final.toJson());
}

void local_calendar::update_calendar(QString id_calendar, QString json)
{
    QString data_file = open_file ("local_calendar_list.json");

    QJsonDocument json_doc =  str_to_json_doc (data_file);
    QJsonObject obj = json_doc.object();
    QJsonDocument json_input = str_to_json_doc (json);
    QJsonObject o = json_input.object();

    QJsonArray arr(obj[QString("items")].toArray());

    for (qint8 i = 0; i != arr.size (); i++)
    {
        if(arr[i].toObject()["id"].toString() == id_calendar)
        {
            arr.removeAt(i);
            o.insert(QString("id"), QString(id_calendar));
            arr.append(o);
            obj.insert(QString("items"), arr);
            break;
        }
    }

    QJsonDocument final(obj);
//    //qDebug() << jj.toVariant().toMap()["kind"].toString();

    save_file("local_calendar_list.json", final.toJson());
}


void local_calendar::create_event(QString id_calendar, QString json)
{

    QString new_cal_json;
    QFile file("data/" + id_calendar + ".json");

    if(!file.exists())
    {
        new_cal_json = QString("{\n") +
                       QString("\"kind\": \"calendar#events\",\n") +
                       QString("\"items\": []\n") +
                       QString("}");
    }

    else
    {
        new_cal_json = open_file (id_calendar + ".json");
    }

    QJsonDocument json_doc =  str_to_json_doc (new_cal_json);
    QJsonDocument json_input = str_to_json_doc (json);
    QJsonObject obj = json_doc.object();


    QString json_cal_list = open_file ("local_calendar_list.json");
    QJsonDocument document_cal_list =  str_to_json_doc (json_cal_list);
    QJsonObject obj_cal_list = document_cal_list.object();

    QJsonArray arr_cal_list(obj_cal_list[QString("items")].toArray());

    for (qint8 i = 0; i != arr_cal_list.size (); i++)
    {
        if(arr_cal_list[i].toObject()["id"].toString() == id_calendar)
        {
            obj.insert(QString("summary"), QString(arr_cal_list[i].toObject()["summary"].toString()));
            obj.insert(QString("description"), QString(arr_cal_list[i].toObject()["description"].toString()));
            break;
        }
    }

    QJsonObject o = json_input.object();


    o.insert(QString("id"), QUuid::createUuid().toString());
    QJsonArray arr(obj[QString("items")].toArray());
    arr.append(o);
    obj.insert(QString("items"), arr);

    QJsonDocument final(obj);

    save_file(id_calendar + ".json", final.toJson());
}

void local_calendar::delete_event(QString id_calendar, QString id_event)
{
    QString data_file = open_file (id_calendar + ".json");

    QJsonDocument json_doc =  str_to_json_doc (data_file);
    QJsonObject obj = json_doc.object();

    QJsonArray arr(obj[QString("items")].toArray());

    for (qint8 i = 0; i != arr.size (); i++)
    {
        if(arr[i].toObject()["id"].toString() == id_event)
        {
            arr.removeAt(i);
            break;
        }
    }

    obj.insert(QString("items"), arr);
    QJsonDocument final(obj);
    save_file(id_calendar + ".json", final.toJson());
}

void local_calendar::update_event(QString id_calendar, QString id_event, QString json)
{
    QString data_file = open_file (id_calendar + ".json");
    QJsonDocument json_doc =  str_to_json_doc(data_file);
    QJsonObject obj = json_doc.object();

    QJsonDocument json_input = str_to_json_doc (json);
    QJsonObject o = json_input.object();

    QJsonArray arr(obj[QString("items")].toArray());

    for (qint8 i = 0; i != arr.size (); i++)
    {
        if(arr[i].toObject()["id"].toString() == id_event)
        {
            arr.removeAt(i);
            o.insert(QString("id"), QString(id_event));
            arr.append(o);
            obj.insert(QString("items"), arr);
            break;
        }
    }

    QJsonDocument final(obj);

    save_file(id_calendar + ".json", final.toJson());
}





















