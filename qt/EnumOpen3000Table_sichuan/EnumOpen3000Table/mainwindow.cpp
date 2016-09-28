#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_TableIndex = -1;
    m_ColumnIndex = -1;
    m_ColumnRowSelected = -1;
    m_TableRowSelected = -1;
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{

    if(QFile::exists(".\\Data.dat") == false)
    {
        QMessageBox::information(NULL, "", "No Data.dat File");
        return;
    }

    if(QFile::exists(".\\profile.xml") == false)
    {
        QMessageBox::information(NULL, "", "No profile.xml File");
        return;
    }

    m_BVecFOpen.PhraseFile(".\\Data.dat");
    m_BVecFOpen.PhraseXmlFile(".\\profile.xml");

    ui->TableWidgetInfo->setColumnCount(3);
    ui->TableWidgetInfo->setEditTriggers( QAbstractItemView::NoEditTriggers );
    QStringList header;
    header<<"Table ID"<<"Chinese Name"<<"English Name";
    ui->TableWidgetInfo->setHorizontalHeaderLabels(header);
    int nTableWidth = ui->TableWidgetInfo->width();
    ui->TableWidgetInfo->setColumnWidth(0, nTableWidth/5);
    ui->TableWidgetInfo->setColumnWidth(1, nTableWidth/5*2);
    ui->TableWidgetInfo->setColumnWidth(2, nTableWidth/5*2);


    ui->ColumnWidgetInfo->setColumnCount(5);
    ui->ColumnWidgetInfo->setEditTriggers( QAbstractItemView::NoEditTriggers );
    QStringList header1;
    header1<<"Column ID"<<"Chinese Name"<<"English Name"<<"Data Type"<<"Data Length";
    ui->ColumnWidgetInfo->setHorizontalHeaderLabels(header1);
    int nPerColumnWidth = ui->ColumnWidgetInfo->width()/10;
    ui->ColumnWidgetInfo->setColumnWidth(0, nPerColumnWidth);
    ui->ColumnWidgetInfo->setColumnWidth(1, nPerColumnWidth*3);
    ui->ColumnWidgetInfo->setColumnWidth(2, nPerColumnWidth*3);
    ui->ColumnWidgetInfo->setColumnWidth(3, nPerColumnWidth*1.5);
    ui->ColumnWidgetInfo->setColumnWidth(4, nPerColumnWidth*1.5);

    ST_TableInfo *pST;
    for (int i=0; i<m_BVecFOpen.m_VecTableInfo.size(); i++)
    {
        ui->TableWidgetInfo->insertRow(i);

        pST = &m_BVecFOpen.m_VecTableInfo.at(i);
        ui->TableWidgetInfo->setItem(i, 0, new QTableWidgetItem(QString::number(pST->table_id)));
        ui->TableWidgetInfo->setItem(i, 1, new QTableWidgetItem(QString::fromLocal8Bit(pST->name_chn)));
        ui->TableWidgetInfo->setItem(i, 2, new QTableWidgetItem(pST->name_eng));

        if(pST->bColor == ColorTable)
            SetTableWidgetRowColor(ColorTable, i, true);
    }


  //  ui->ColumnWidgetInfo->setContextMenuPolicy(Qt::CustomContextMenu);
    popMenu = new QMenu(ui->ColumnWidgetInfo);
    actionModel = new QAction("Model", this);
    actionReal = new QAction("Real", this);
    actionModelAndReal = new QAction("Model and Real", this);
    actionCancel = new QAction("Cancel", this);
    popMenu->addAction(actionModel);
    popMenu->addAction(actionReal);
    popMenu->addAction(actionModelAndReal);
    popMenu->addAction(actionCancel);


 //   connect(ui->ColumnWidgetInfo, SIGNAL(customContextMenuRequested(QPoint)),
  //          this, SLOT(on_ColumnWidgetInfo_customContextMenuRequested(QPoint)));
    connect(actionModel, SIGNAL(triggered()), this, SLOT(rightChooseModel()));
    connect(actionReal, SIGNAL(triggered()), this, SLOT(rightChooseReal()));
    connect(actionModelAndReal, SIGNAL(triggered()), this, SLOT(rightChooseModelAndReal()));
    connect(actionCancel, SIGNAL(triggered()), this, SLOT(rightChooseCancel()));

    QString color1("background-color: rgb(%1,%2,%3);");
    QString str1 = color1.arg((ColorModel&0x00ff0000)>>16).arg((ColorModel&0x0000ff00)>>8).arg(ColorModel&0x000000ff);
    ui->pushButtonModel->setStyleSheet(str1);

    QString color2("background-color: rgb(%1,%2,%3);");
    QString str2 = color2.arg((ColorReal&0x00ff0000)>>16).arg((ColorReal&0x0000ff00)>>8).arg(ColorReal&0x000000ff);
    ui->pushButtonReal->setStyleSheet(str2);

    QString color3("background-color: rgb(%1,%2,%3);");
    QString str3 = color3.arg((ColorModelAndReal&0x00ff0000)>>16).arg((ColorModelAndReal&0x0000ff00)>>8).arg(ColorModelAndReal&0x000000ff);
    ui->pushButtonModelAndReal->setStyleSheet(str3);

}

void MainWindow::on_ColumnWidgetInfo_customContextMenuRequested(QPoint pos)
{
    m_ColumnIndex = -1;
    m_ColumnRowSelected = -1;
    QTableWidgetItem *item = ui->ColumnWidgetInfo->itemAt(pos);
    if(item != NULL)
    {
        m_ColumnRowSelected = item->row();
        int nID = ui->ColumnWidgetInfo->item(item->row(), 0)->text().toInt();
        for (int i=0; i<m_BVecFOpen.m_VecTableInfo.at(m_TableIndex).veccolumninfo.size(); i++)
        {
            ST_ColumnInfo *pCol = &m_BVecFOpen.m_VecTableInfo.at(m_TableIndex).veccolumninfo.at(i);
            if(pCol->id == nID)
            {
                m_ColumnIndex = i;
                break;
            }
        }
        popMenu->exec(QCursor::pos());
    }
}

void MainWindow::SetTableWidgetRowColor(QRgb color, int row, bool bAlreadyColored)
{
    for(int i=0; i<3; i++)
        ui->TableWidgetInfo->item(row, i)->setBackgroundColor(QColor(color));


    if(bAlreadyColored == false)
        m_BVecFOpen.m_VecTableInfo.at(m_TableIndex).bColor = color;
}

void MainWindow::SetColumnRowColor(QRgb color, int row)
{
    ST_ColumnInfo *pCol = &m_BVecFOpen.m_VecTableInfo.at(m_TableIndex).veccolumninfo.at(m_ColumnIndex);

    if( (pCol->bColor == ColorReal && color == ColorModel)||
                 (pCol->bColor == ColorModel && color == ColorReal) )
            pCol->bColor = ColorModelAndReal;
    else
        pCol->bColor = color;


    for(int i=0; i<5; i++)
        ui->ColumnWidgetInfo->item(row, i)->setBackgroundColor(QColor(pCol->bColor));

//    m_BVecFOpen.m_VecTableInfo.at(m_TableIndex).veccolumninfo.at(m_ColumnIndex).bColor = color;
}

void MainWindow::rightChooseModel()
{
    if(m_ColumnIndex == -1 || m_TableIndex==-1 || m_ColumnRowSelected==-1 || m_TableRowSelected==-1)
        return;

    SetColumnRowColor(ColorModel, m_ColumnRowSelected);
    SetTableWidgetRowColor(ColorTable, m_TableRowSelected);
}

void MainWindow::rightChooseReal()
{
    if(m_ColumnIndex == -1 || m_TableIndex==-1 || m_ColumnRowSelected==-1 || m_TableRowSelected==-1)
        return;

    SetColumnRowColor(ColorReal, m_ColumnRowSelected);
    SetTableWidgetRowColor(ColorTable, m_TableRowSelected);
}

void MainWindow::rightChooseModelAndReal()
{
    if(m_ColumnIndex == -1 || m_TableIndex==-1 || m_ColumnRowSelected==-1 || m_TableRowSelected==-1)
        return;

    SetColumnRowColor(ColorModelAndReal, m_ColumnRowSelected);
    SetTableWidgetRowColor(ColorTable, m_TableRowSelected);
}

void MainWindow::rightChooseCancel()
{
    if(m_ColumnIndex == -1 || m_TableIndex==-1 || m_ColumnRowSelected==-1 || m_TableRowSelected==-1)
        return;

    SetColumnRowColor(ColorCancel, m_ColumnRowSelected);

    bool bFound=false;
    for(int i=0; i<m_BVecFOpen.m_VecTableInfo.at(m_TableIndex).veccolumninfo.size(); i++)
    {
        if(m_BVecFOpen.m_VecTableInfo.at(m_TableIndex).veccolumninfo.at(i).bColor != ColorCancel)
        {
            bFound = true;
            break;
        }
    }

    if(bFound == true)
    {
        SetTableWidgetRowColor(ColorTable, m_TableRowSelected);
    }
    else
    {
        SetTableWidgetRowColor(ColorCancel, m_TableRowSelected);
    }
}

void MainWindow::on_TableWidgetInfo_cellClicked(int row, int column)
{
    ST_TableInfo *pTab;
    ST_ColumnInfo *pCol;

    m_TableRowSelected = row;
    m_TableIndex = m_BVecFOpen.BinaryFind_TableInfo_TableID(ui->TableWidgetInfo->item(row, 0)->text().toInt());
    if(m_TableIndex != -1)
    {
        ui->ColumnWidgetInfo->setRowCount(0);
        ui->ColumnWidgetInfo->clearContents();

        pTab = &m_BVecFOpen.m_VecTableInfo.at(m_TableIndex);
        for (int i=0; i<pTab->veccolumninfo.size(); i++)
        {
            pCol = &pTab->veccolumninfo.at(i);

            ui->ColumnWidgetInfo->insertRow(i);
            ui->ColumnWidgetInfo->setItem(i, 0, new QTableWidgetItem(QString::number(pCol->id)));
            ui->ColumnWidgetInfo->setItem(i, 1, new QTableWidgetItem(QString::fromLocal8Bit(pCol->name_chn)));
            ui->ColumnWidgetInfo->setItem(i, 2, new QTableWidgetItem(pCol->name_eng));
            ui->ColumnWidgetInfo->setItem(i, 3, new QTableWidgetItem(m_BVecFOpen.GetDataTypeByID(pCol->dataType)));
            ui->ColumnWidgetInfo->setItem(i, 4, new QTableWidgetItem(QString::number(pCol->dataLength)));

            m_ColumnIndex = i;
            SetColumnRowColor(pCol->bColor, i);
        }

        ui->lineEditModel->setText(QString::number(pTab->TimeInterval_Model));
        ui->lineEditReal->setText(QString::number(pTab->TimeInterval_Real));
        ui->lineEditAppNo->setText(QString::number(pTab->AppNo));
    }
}


void MainWindow::on_pushButton_clicked()
{
    m_BVecFOpen.CreateHFile();
    m_BVecFOpen.CreateXmlFile();
    QMessageBox::information(NULL, "wd", "Create ok!!!");
}

void MainWindow::on_pushButtonModel_clicked()
{
 //   ui->tabWigDataShow->scrollToItem( ui->tabWigDataShow->item(row-1,0), QAbstractItemView::PositionAtBottom);
  //  ui->TableWidgetInfo->scrollToItem(ui->TableWidgetInfo->item(144,0));
}

void MainWindow::on_lineEditModel_editingFinished()
{
    //;
}

void MainWindow::on_lineEditReal_editingFinished()
{

}

void MainWindow::on_lineEditModel_textEdited(const QString &arg1)
{
    m_BVecFOpen.m_VecTableInfo.at(m_TableIndex).TimeInterval_Model = arg1.toInt();
}

void MainWindow::on_lineEditReal_textEdited(const QString &arg1)
{
    m_BVecFOpen.m_VecTableInfo.at(m_TableIndex).TimeInterval_Real = arg1.toInt();
}

void MainWindow::on_lineEditAppNo_textEdited(const QString &arg1)
{
    m_BVecFOpen.m_VecTableInfo.at(m_TableIndex).AppNo = arg1.toInt();
}
