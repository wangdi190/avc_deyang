/****************************************************************************
** Form interface generated from reading ui file 'Mainform.ui'
**
** Created: 二  8月 25 14:37:24 2015
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.6   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MAINFORM_H
#define MAINFORM_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QListBox;
class QListBoxItem;
class QLabel;

class MainForm : public QDialog
{
    Q_OBJECT

public:
    MainForm( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~MainForm();

    QListBox* listBox_info;
    QLabel* textLabel_show;

    virtual void init();
    virtual void customEvent( QCustomEvent * event );

public slots:
    virtual void BtnClicked();
    virtual void AddTip( QString strTip, bool bWarn );

protected:
    virtual void closeEvent( QCloseEvent * e );


protected slots:
    virtual void languageChange();

};

#endif // MAINFORM_H
