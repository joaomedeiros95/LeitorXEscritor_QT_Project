#include "thread2.h"
#include <QMutex>
#include <qglobal.h>
#include <QDebug>

Thread2::Thread2(QObject *parent) :
    QThread(parent)
{
}

void Thread2::run() {
    QMutex mutex;
    while (1) {
        sem2->P(); //Diz que está escrevendo
        sem1->P(); //Aguarda todos os leitores saírem
        mutex.lock();
        (*escritor) = true;
        mutex.unlock();
        sleep(6);    //Tempo de escrita no banco de dados;
        mutex.lock();
        (*escritor) = false;
        mutex.unlock();
        if(sem1->getContador() <= 0) sem1->V();
        if(sem2->getContador() <= 0) sem2->V(); //Parou de escrever
    }
}

void Thread2::setSem1(Semaforo *sem)
{
    sem1 = sem;
}

void Thread2::setSem2(Semaforo *sem)
{
    sem2 = sem;
}

void Thread2::setNum(bool *esc, int *num) {
    numero = num;
    escritor = esc;
}
