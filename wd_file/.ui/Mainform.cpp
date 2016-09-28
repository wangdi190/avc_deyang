/****************************************************************************
** Form implementation generated from reading ui file 'Mainform.ui'
**
** Created: 二  8月 25 14:37:30 2015
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.6   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Mainform.h"

#include <qvariant.h>
#include <qlistbox.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "../Mainform.ui.h"
/*
 *  Constructs a MainForm as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
MainForm::MainForm( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "MainForm" );
    setIcon( QPixmap::fromMimeSource( "Data.bmp" ) );

    listBox_info = new QListBox( this, "listBox_info" );
    listBox_info->setGeometry( QRect( 10, 151, 580, 320 ) );

    textLabel_show = new QLabel( this, "textLabel_show" );
    textLabel_show->setGeometry( QRect( 120, 30, 351, 71 ) );
    textLabel_show->setAlignment( int( QLabel::AlignCenter ) );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
MainForm::~MainForm()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MainForm::languageChange()
{
    setCaption( tr( "Open3000_Data" ) );
    listBox_info->clear();
    listBox_info->insertItem( tr( "New Item" ) );
    textLabel_show->setText( tr( "textLabel1" ) );
}

