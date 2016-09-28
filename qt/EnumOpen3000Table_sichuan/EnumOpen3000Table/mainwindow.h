#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMenu>
#include "ui_mainwindow.h"

#include "buildvectorfromopen3000.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init();

    void SetTableWidgetRowColor(QRgb color, int row, bool bAlreadyColored=false);
    void SetColumnRowColor(QRgb color, int row);


private slots:
    void on_TableWidgetInfo_cellClicked(int row, int column);

    void on_ColumnWidgetInfo_customContextMenuRequested(QPoint pos);

    void rightChooseModel();
    void rightChooseReal();
    void rightChooseModelAndReal();
    void rightChooseCancel();

    void on_pushButton_clicked();

    void on_pushButtonModel_clicked();

    void on_lineEditModel_editingFinished();

    void on_lineEditReal_editingFinished();

    void on_lineEditModel_textEdited(const QString &arg1);

    void on_lineEditReal_textEdited(const QString &arg1);

    void on_lineEditAppNo_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;

    BuildVectorFromOpen3000 m_BVecFOpen;
    int m_TableIndex, m_TableRowSelected;
    int m_ColumnIndex, m_ColumnRowSelected;

    QMenu *popMenu;
    QAction *actionModel, *actionReal, *actionModelAndReal, *actionCancel;
};

#endif // MAINWINDOW_H
