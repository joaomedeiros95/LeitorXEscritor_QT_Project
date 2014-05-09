#include "thread1.h"
#include <QMutex>
#include <iostream>
#include <QDebug>

Thread1::Thread1(QObject *parent) :
    QThread(parent)
{
}

void Thread1::run() {
    QMutex mutex;
    sem2->P();  //Espera os escritores terminarem
    if(sem2->getContador() <= 0) sem2->V();  //Libera os escirtores a pedirem acesso de novo
    mutex.lock();
    (*numero) = (*numero) + 1;
    if ((*numero) == 1)
    {
        sem1->P();
    }
    mutex.unlock();
    sleep(4);    //Lendo da base de dados
    mutex.lock();
    (*numero) = (*numero) - 1;
    mutex.unlock();
    if ((*numero) == 0)
    {
        if(sem1->getContador() <= 0) sem1->V();
    }
}

void Thread1::setSem1(Semaforo *sem)
{
    sem1 = sem;
}

void Thread1::setSem2(Semaforo *sem)
{
    sem2 = sem;
}

void Thread1::setNum(int *num) {
    numero = num;
}


