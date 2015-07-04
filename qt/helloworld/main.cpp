#include <QCoreApplication>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString mstr="hahaha";
    qDebug()<<"hello,world!"<<endl<<mstr;
    return a.exec();
}
