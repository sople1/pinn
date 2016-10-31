#ifndef OsSource_H
#define OsSource_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QMap>
#include <QVariant>
#include "osinfo.h"

class QNetworkAccessManager;

class OsSource : public QObject
{
    Q_OBJECT
public:
    explicit OsSource(QObject *parent = 0);
    void setSource(const char * type);
    void setDevice(const char * id);
    void setLocation(const char * locn);
    QString getDevice();
    QString getLocation();
    QString getSource();
    void clearOSes();
    void addOS(OsInfo * os,const QString source);
    QMap<QString,OsInfo *> oses;

protected:
    QString source;     // SDcard/USB/NETWORK etc.
    QString device;     // dev/sda1
    QString location;   // /media or http://...
    //QMap<QString,QVariantMap> images;

signals:
    void newSource(OsSource *src);

protected:


public slots:
    virtual void monitorDevice();
    virtual void monitorNetwork(QNetworkAccessManager *netaccess);
};



#endif // OsSource_H
