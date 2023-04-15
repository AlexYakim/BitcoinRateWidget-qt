#include "CurrencyParsing.h"

Currency_parsing::Currency_parsing()
{

//Setting up signal and slot connections
    manager_now = new QNetworkAccessManager(this);
    connect(manager_now,&QNetworkAccessManager::finished,this, &Currency_parsing::Get_Currency_Finished_Now);
    manager_1h_1d_7d= new QNetworkAccessManager(this);
    connect(manager_1h_1d_7d,&QNetworkAccessManager::finished,this, &Currency_parsing::Get_Currency_Finished_1h_1d_7d);
}
// Method to set up a currency exchange Url
void Currency_parsing::SetUrl(QString API_link){
    url.setUrl(API_link);

}

//Sending a request for currency exchange rate data at a given time
void Currency_parsing::Request_now(){

   QNetworkRequest request(url);
   manager_now->get(request);
}
//sending a request for exchange rate data for 1 day 1 hour and weeks
void Currency_parsing::Request_1h_1d_7d(){

   QNetworkRequest request(url);
   manager_1h_1d_7d->get(request);
}


//Processing a response received about the state of bitcoin now
void Currency_parsing::Get_Currency_Finished_Now(QNetworkReply* reply){

   if(reply->error() == QNetworkReply::NoError){
   QByteArray byte_array = reply->readAll();
   QJsonDocument Jdoc = QJsonDocument::fromJson(byte_array);
   QJsonObject Jobj = Jdoc.object();
   price_now=Jobj["bitcoin"].toObject()["usd"].toDouble();

   }
   else{

   }
}


//Processing of 1 day 1 hour and 1 week bitcoin response received
void Currency_parsing::Get_Currency_Finished_1h_1d_7d(QNetworkReply* reply){

   if(reply->error() == QNetworkReply::NoError){
   QByteArray byte_array = reply->readAll();
   QJsonDocument Jdoc = QJsonDocument::fromJson(byte_array);
   QJsonObject Jobj = Jdoc.object();
   price_1h=Jobj["market_data"].toObject()["price_change_percentage_1h_in_currency"].toObject()["usd"].toDouble();

      price_1d=Jobj["market_data"].toObject()["price_change_percentage_24h_in_currency"].toObject()["usd"].toDouble();
      price_7d=Jobj["market_data"].toObject()["price_change_percentage_7d_in_currency"].toObject()["usd"].toDouble();
   }
   else{

   }
}

Currency_parsing::~Currency_parsing(){
    delete manager_now;
    delete manager_1h_1d_7d;
}
