#ifndef THREADRUN_H
#define THREADRUN_H

#include <qthread.h>
#include <qapplication.h>
#include "Data.h"

class CThreadRun : public QThread
{
public:
    CThreadRun(QWidget *pMainform);
    virtual void run();
    void AddTip( QString strTip);
    QWidget *m_pMain;
    CData m_Data;
};

#endif // DATA_H
