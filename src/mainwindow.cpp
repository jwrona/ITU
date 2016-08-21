#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QIcon icon("tray_icon.png");
    setWindowIcon(icon);
    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
    setWindowTitle("Calendar Editor");



    ui->calendar_id_lineEdit->setVisible(false);
    ui->event_id_lineEdit->setVisible(false);

    checked = false;
    ui->calendar_edit_pushButton->setDisabled (true);
    ui->calendar_delete_pushButton->setDisabled(true);
    ui->event_create_pushButton->setDisabled(true);
    ui->event_edit_pushButton->setDisabled(true);
    ui->event_delete_pushButton->setDisabled(true);

    ui->local_calendar_checkBox->setDisabled(true);
    ui->remote_calendar_checkBox->setDisabled(true);

    setFixedSize(size());

    g_api = new gcal_api ();
    l_api = new local_calendar();

    event_create_dialog = new event_create(this);
    calendar_create_dialog = new calendar_create(this);

    connect(g_api, SIGNAL(calendarListReady()), this, SLOT(refresh_calendar_list()));

    connect(calendar_create_dialog, SIGNAL(refresh()), this, SLOT(on_refresh_pushButton_clicked()));
    connect(event_create_dialog, SIGNAL(refresh()), this, SLOT(on_calendar_list_listWidget_itemClicked()));


//    connect(g_api, SIGNAL(haha()), this, SLOT(on_refresh_pushButton_clicked()));


    /*********************************************************/
    ui->local_calendar_checkBox->setChecked(true);
    /*********************************************************/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_pushButton_clicked()
{
    m_pOAuth2 = new OAuth2 (this);
    m_pOAuth2->setScope ("https://www.google.com/calendar/feeds/");
    m_pOAuth2->setClientID ("876312718797.apps.googleusercontent.com");
    m_pOAuth2->setRedirectURI ("urn:ietf:wg:oauth:2.0:oob");
    m_pOAuth2->setCompanyName ("YOUR_COMPANY_NAME");
    m_pOAuth2->setAppName ("YOUR_APPLICATION_NAME");
    m_pOAuth2->startLogin (true);

}

void MainWindow::on_send_code_pushButton_clicked()
{
    ui->send_code_pushButton->setDisabled (true);
    QByteArray data;

    QUrl url ("https://accounts.google.com/o/oauth2/token");

    data.append ("client_id=876312718797.apps.googleusercontent.com&");
    data.append ("client_secret=SW1yXwVo_Ziq2-ieUVGw-Yex&");
    data.append ("redirect_uri=urn:ietf:wg:oauth:2.0:oob&");
    data.append ("grant_type=authorization_code&");
    data.append ("code=" + ui->send_code_lineEdit->text ());

    QNetworkRequest req (url);
    req.setHeader (QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkAccessManager *mgr = new QNetworkAccessManager (this);
    connect (mgr, SIGNAL (finished (QNetworkReply *)), this, SLOT (send_code_finish (QNetworkReply *)));
    connect (mgr, SIGNAL (finished (QNetworkReply *)), mgr, SLOT (deleteLater ()));

    mgr->post (req, data);
    ui->send_code_lineEdit->clear();

        QTimer *timer = new QTimer (this);
        connect (timer, SIGNAL (timeout ()), this, SLOT (refresh_calendar_list()));
        timer->start (3000000); // 50min

        QFile ref ("data/refresh.json");
        QFile acc ("data/access.json");

        if (!ref.exists () || !acc.exists ())
        {
          // login routine
//          on_login_pushButton_clicked();
        }
        else
        {
          // mame subor s access tokenom
          if (acc.exists ())
          {
            // nacitame
            g_api->getAccessTokenFromFile ();
            // checkneme (ak je nevalidny tak chceck skusi refreshnut)
            g_api->checkAccessToken ();
          }
          else
          {
            // nemame subor s access tokenom, skusime refreshnut
            g_api->getRefreshTokenFromFile ();
            g_api->getFreshAccessToken ();
          }
        }
    ui->local_calendar_checkBox->setEnabled(true);
    ui->remote_calendar_checkBox->setEnabled(true);
}

void MainWindow::send_code_finish(QNetworkReply * rep)
{
    QByteArray bts = rep->readAll ();
    QString json (bts);

    g_api->save_file ("refresh.json", json);
    g_api->save_file ("access.json", json);

    QJsonDocument json_doc =  g_api->str_to_json_doc (json);
    QVariant var = json_doc.toVariant ();


    g_api->access_token = var.toMap ()["access_token"].toString ();
}

//////////////////////////////////////////////////////////

void MainWindow::on_calendar_create_pushButton_clicked()
{
//    calendar_create_dialog = new calendar_create(this);

    if(ui->local_calendar_checkBox->isChecked())
    {
        calendar_create_dialog->set_bool(true);
    }
    else
    {
        calendar_create_dialog->set_bool(false);
    }
    calendar_create_dialog->exec();

    /*********************************************************/
    if(ui->local_calendar_checkBox->isChecked())
    {
        on_refresh_pushButton_clicked();
    }
    /*********************************************************/
}

void MainWindow::on_calendar_edit_pushButton_clicked()
{
    calendar_edit_dialog = new calendar_edit(this);
    calendar_edit_dialog->show();

    if(ui->local_calendar_checkBox->isChecked())
    {
        calendar_edit_dialog->local_checked = true;
        calendar_edit_dialog->set_ID(l_api, ui->calendar_id_lineEdit->text());
    }
    else
    {
      calendar_edit_dialog->local_checked = false;
      calendar_edit_dialog->set_ID(g_api, ui->calendar_id_lineEdit->text());
    }
    calendar_edit_dialog->exec();

    /*********************************************************/
    if(ui->local_calendar_checkBox->isChecked())
    {
        on_refresh_pushButton_clicked();
    }
    /*********************************************************/
}

void MainWindow::on_calendar_delete_pushButton_clicked()
{
    //  QFile::remove("data/" + ui->lineEdit_2->text() + ".json");
        if(ui->local_calendar_checkBox->isChecked())
        {
            l_api->delete_calendar(ui->calendar_id_lineEdit->text());
        }
        else
        {
            g_api->delete_calendar (g_api->access_token, ui->calendar_id_lineEdit->text ());
        }

      cal_map.remove(ui->calendar_list_listWidget->currentRow());

      /*********************************************************/
      if(ui->local_calendar_checkBox->isChecked())
      {
          on_refresh_pushButton_clicked();
      }
      ui->event_list_listWidget->clear();
      /*********************************************************/

      ui->calendar_edit_pushButton->setEnabled(false);
      ui->calendar_delete_pushButton->setEnabled(false);
      ui->event_create_pushButton->setEnabled(false);
      ui->event_edit_pushButton->setEnabled(false);
      ui->event_delete_pushButton->setEnabled(false);
}

void MainWindow::on_event_create_pushButton_clicked()
{
    if(ui->local_calendar_checkBox->isChecked())
    {
        event_create_dialog->local_checked = true;
    }
    else
    {
        event_create_dialog->local_checked = false;
    }
    event_create_dialog->set_ID(ui->calendar_id_lineEdit->text());

    event_create_dialog->exec ();

    /*********************************************************/
    ui->calendar_list_listWidget->clicked(ui->calendar_list_listWidget->currentIndex());
    /*********************************************************/
}

void MainWindow::on_event_edit_pushButton_clicked()
{
    event_edit_dialog = new event_edit(this);

    if(ui->local_calendar_checkBox->isChecked())
    {
        event_edit_dialog->local_checked = true;
        event_edit_dialog->set_ID(l_api, ui->calendar_id_lineEdit->text(), ui->event_id_lineEdit->text());
    }
    else
    {
        event_edit_dialog->local_checked = false;
        event_edit_dialog->set_ID(g_api, ui->calendar_id_lineEdit->text(), ui->event_id_lineEdit->text());
    }

    event_edit_dialog->exec();
    /*********************************************************/
    ui->calendar_list_listWidget->clicked(ui->calendar_list_listWidget->currentIndex());
    /*********************************************************/
}

void MainWindow::on_event_delete_pushButton_clicked()
{
    if(ui->local_calendar_checkBox->isChecked())
    {
        l_api->delete_event(ui->calendar_id_lineEdit->text (), ui->event_id_lineEdit->text());
    }
    else
    {
        g_api->delete_event (g_api->access_token, ui->calendar_id_lineEdit->text (), ui->event_id_lineEdit->text ());
    }

    ui->event_id_lineEdit->clear();

    ui->event_edit_pushButton->setEnabled(false);
    ui->event_delete_pushButton->setEnabled(false);


    //g_api->get_event_list(g_api->access_token, ui->calendar_id_lineEdit->text ());
    //refresh_event_list(cal_map.lowerBound(ui->calendar_list_listWidget->currentRow()).value());
//    refresh_event_list(ui->calendar_id_lineEdit->text());

    //  ui->calendar_list_listWidget->clicked(ui->listWidget->currentIndex());

    /*********************************************************/
    ui->calendar_list_listWidget->clicked(ui->calendar_list_listWidget->currentIndex());
    /*********************************************************/
}


void MainWindow::on_local_calendar_checkBox_toggled()
{
    on_refresh_pushButton_clicked();

    ui->event_list_listWidget->clear();
}

void MainWindow::on_refresh_pushButton_clicked()
{
    qDebug() << "/////////////////////////////////////";
    if(!ui->local_calendar_checkBox->isChecked())
    {
        g_api->get_calendar_list(g_api->access_token);
    }

    refresh_calendar_list();
}

void MainWindow::refresh_calendar_list()
{
    qDebug() << "refresher!!!";

    QString data_file =  g_api->open_file ("calendar_list.json");
    QJsonDocument json_doc =  g_api->str_to_json_doc (data_file);

    ui->calendar_list_listWidget->clear ();
    cal_map.clear();

    QJsonArray arr = json_doc.object ().value ("items").toArray ();
    qint8 i;

    for (i = 0; i != arr.size (); i++)
    {
        if(ui->local_calendar_checkBox->isChecked())
        {
            ui->calendar_list_listWidget->addItem(arr.at (i).toObject ().value ("summary").toString ());
            ui->calendar_list_listWidget->item(i)->setHidden(true);
        }
        else
        {
            ui->calendar_list_listWidget->addItem(arr.at (i).toObject ().value ("summary").toString ());
            ui->calendar_list_listWidget->item(i)->setHidden(false);
        }

      cal_map.insert(i, arr.at (i).toObject ().value ("id").toString ());
    }

    if(!ui->local_calendar_checkBox->isChecked())
    {
        foreach(QString tmp, cal_map.values())
        {
            g_api->get_event_list(g_api->access_token, tmp);
        }
    }

    ///////////////////////////////////////////////
    data_file =  g_api->open_file ("local_calendar_list.json");
    json_doc =  g_api->str_to_json_doc (data_file);
    QJsonArray arr2;
    arr2 = json_doc.object ().value ("items").toArray ();

    for (qint8 a = 0; a != arr2.size (); a++)
    {
        if(ui->local_calendar_checkBox->isChecked())
        {
            ui->calendar_list_listWidget->addItem (arr2.at (a).toObject ().value ("summary").toString ());
            ui->calendar_list_listWidget->item(i + a)->setHidden(false);
        }
        else
        {
            ui->calendar_list_listWidget->addItem (arr2.at (a).toObject ().value ("summary").toString ());
            ui->calendar_list_listWidget->item(i + a)->setHidden(true);
        }
        cal_map.insert(i + a, arr2.at (a).toObject ().value ("id").toString ());
    }
}

void MainWindow::refresh_event_list (QString calendar_id)
{
  QString data_file;
  QJsonDocument json_doc;

//  g_api->get_event_list (g_api->access_token, calendar_id);

  foreach(QString tmp, cal_map.values())
  {
      if(tmp == calendar_id)
      {
          data_file =  g_api->open_file (tmp + ".json");
          json_doc =  g_api->str_to_json_doc (data_file);
      }
  }

  ui->event_list_listWidget->clear ();
  event_map.clear();

  QJsonArray arr = json_doc.object ().value ("items").toArray ();
//  var.toMap()["items"].toList()[i].toMap()["start"].toMap()["dateTime"].toString()
/////////////////////////////////////////////////////////////////////////////////////////////////////
  for (qint8 i = 0; i != arr.size (); i++)
  {
      QString summary = arr.at (i).toObject ().value ("summary").toString ();
      QString start_date = arr.at (i).toObject ().value ("start").toObject().value("dateTime").toString().left(10);
      QString end_date = arr.at (i).toObject ().value ("end").toObject().value("dateTime").toString().left(10);

      ui->event_list_listWidget->addItem (summary + "     " + start_date + " - " + end_date);
      event_map.insert(i, arr.at (i).toObject ().value ("id").toString ());
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////
}

void MainWindow::on_calendar_list_listWidget_itemClicked()
{
    ui->event_id_lineEdit->clear();
    ui->calendar_id_lineEdit->setText (cal_map.lowerBound(ui->calendar_list_listWidget->currentRow()).value());
    refresh_event_list(cal_map.lowerBound(ui->calendar_list_listWidget->currentRow()).value());

    ui->calendar_edit_pushButton->setEnabled(true);
    ui->calendar_delete_pushButton->setEnabled(true);
    ui->event_create_pushButton->setEnabled(true);
    ui->event_edit_pushButton->setEnabled(false);
    ui->event_delete_pushButton->setEnabled(false);
}

void MainWindow::on_event_list_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->event_id_lineEdit->setText (event_map.lowerBound(ui->event_list_listWidget->currentRow()).value());

    ui->event_edit_pushButton->setEnabled(true);
    ui->event_delete_pushButton->setEnabled(true);
}

void MainWindow::closeEvent(QCloseEvent *event)
 {
    emit closed();
    QMainWindow::closeEvent(event);
 }
