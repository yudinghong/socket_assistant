#include "widget.h"
#include "ui_widget.h"
#include "utils.h"
#include "QStringList"

static bool connectedStatus = false;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->serverIPEdit->setVisible(false);
    ui->serverIPLabel->setVisible(false);
    ui->ClientIPLabel->setVisible(true);
    ui->clientIPComboBox->setVisible(true);
    QStringList addressList = getAllLocalIP();
    ui->clientIPComboBox->addItems(addressList);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_protocolComboBox_currentTextChanged(const QString &itemText)
{
   if (itemText == QString("udp") || itemText == QString("tcp server")){
       ui->serverIPEdit->setVisible(false);
       ui->serverIPLabel->setVisible(false);
       ui->ClientIPLabel->setVisible(true);
       ui->clientIPComboBox->setVisible(true);
   }
   else if(itemText == QString("tcp client")){
       ui->ClientIPLabel->setVisible(false);
       ui->clientIPComboBox->setVisible(false);
       ui->serverIPEdit->setVisible(true);
       ui->serverIPLabel->setVisible(true);
   }
}

void Widget::on_connectButton_clicked()
{

}
