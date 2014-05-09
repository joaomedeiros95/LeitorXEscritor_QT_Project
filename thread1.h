#ifndef THREAD1_H
#define THREAD1_H

#include <QThread>
#include "semaforo.h"

class Thread1 : public QThread
{
    Q_OBJECT
public:
    explicit Thread1(QObject *parent = 0);
    void run();
    void setSem1(Semaforo *sem);
    void setSem2(Semaforo *sem);
    void setNum(int *num);
    Semaforo *sem1;
    Semaforo *sem2;
    int *numero;

private:

public slots:

};

#endif // THREAD1_H
