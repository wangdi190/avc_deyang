/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/
#include "Data.h"
#include "ThreadRun.h"
#include <qdatetime.h>

CData m_Data;
CThreadRun *pThread;

void MainForm::init()
{
    QString strTmp;
    QDateTime time = QDateTime::currentDateTime();
    strTmp = "Program start time\n"+time.toString("yyyy-MM-dd hh:mm:ss");
    textLabel_show->setText(strTmp);
    listBox_info->clear();
    pThread = new CThreadRun(this);
    pThread->start();
}

void MainForm::BtnClicked()
{
}
void MainForm::AddTip( QString strTip, bool bWarn )
{
    QTime time = QTime::currentTime();
    if(listBox_info->count ()>100)
	listBox_info->clear();
    else
	listBox_info->insertItem(time.toString("hh:mm:ss")+"    "+strTip, 0);
}

void MainForm::closeEvent( QCloseEvent *e )
{
    if(QMessageBox::information(this, "Warn", "Are you sure to quit program.",  QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
    {
	//QMessageBox::information(this, "1", "2");
	kill(getpid(), SIGINT);
    }
}


void MainForm::customEvent( QCustomEvent *event )
{
    switch (event->type()) 
    {
	case 12345:
	    {
		QString *s = (QString *) event->data();
		AddTip(*s, false);
		break;
	    }
    }
}
