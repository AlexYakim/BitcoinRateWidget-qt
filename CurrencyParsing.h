#ifndef CURRENCYPARSING_H
#define CURRENCYPARSING_H

#ifndef CURRENCY_PARSING_H
#define CURRENCY_PARSING_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>

class Currency_parsing: public QObject
{
    Q_OBJECT
private slots:
    void Get_Currency_Finished_Now(QNetworkReply* reply);
    void Get_Currency_Finished_1h_1d_7d(QNetworkReply* reply);


protected:


public:
    Currency_parsing();
void SetUrl(QString);
    void fech_now();
    void fech_1h_1d_7d();
    double price_now;
    double price_1h;
    double price_1d;
    double price_7d;
    ~Currency_parsing();

private:

    QNetworkAccessManager* manager_now;
    QNetworkAccessManager* manager_1h_1d_7d;
    QUrl url;
};

#endif // CURRENCY_PARSING_H


#endif // CURRENCYPARSING_H
