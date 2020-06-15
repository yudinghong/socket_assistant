#include "utils.h"

QStringList getAllLocalIP(){
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    QStringList addressList;
    foreach(QHostAddress address, ipAddressesList){
        if(address.protocol() == QAbstractSocket::IPv4Protocol &&
            address != QHostAddress::Null){
            addressList << address.toString();
        }
    }
    return addressList;
}
