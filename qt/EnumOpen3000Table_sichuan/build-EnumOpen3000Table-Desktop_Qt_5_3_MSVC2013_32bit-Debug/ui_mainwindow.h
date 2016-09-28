/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *ColumnWidgetInfo;
    QTableWidget *TableWidgetInfo;
    QPushButton *pushButton;
    QSplitter *splitter;
    QPushButton *pushButtonModel;
    QPushButton *pushButtonReal;
    QPushButton *pushButtonModelAndReal;
    QLineEdit *lineEditModel;
    QLineEdit *lineEditReal;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditAppNo;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1359, 619);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ColumnWidgetInfo = new QTableWidget(centralWidget);
        ColumnWidgetInfo->setObjectName(QStringLiteral("ColumnWidgetInfo"));
        ColumnWidgetInfo->setGeometry(QRect(460, 10, 891, 551));
        ColumnWidgetInfo->setContextMenuPolicy(Qt::CustomContextMenu);
        ColumnWidgetInfo->setStyleSheet(QLatin1String("selection-background-color: rgb(255, 250, 250);\n"
"selection-color: rgb(0, 0, 0);"));
        ColumnWidgetInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ColumnWidgetInfo->setSelectionMode(QAbstractItemView::SingleSelection);
        ColumnWidgetInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
        ColumnWidgetInfo->verticalHeader()->setVisible(false);
        TableWidgetInfo = new QTableWidget(centralWidget);
        TableWidgetInfo->setObjectName(QStringLiteral("TableWidgetInfo"));
        TableWidgetInfo->setGeometry(QRect(10, 10, 441, 551));
        TableWidgetInfo->setStyleSheet(QLatin1String("selection-background-color: rgba(0, 255, 255, 125);\n"
"selection-color: rgba(0, 0, 0, 125);"));
        TableWidgetInfo->setSelectionMode(QAbstractItemView::SingleSelection);
        TableWidgetInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
        TableWidgetInfo->verticalHeader()->setVisible(false);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1210, 570, 141, 41));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(640, 570, 421, 41));
        splitter->setOrientation(Qt::Horizontal);
        pushButtonModel = new QPushButton(splitter);
        pushButtonModel->setObjectName(QStringLiteral("pushButtonModel"));
        pushButtonModel->setEnabled(true);
        pushButtonModel->setAutoFillBackground(false);
        pushButtonModel->setStyleSheet(QStringLiteral("font: 75 14pt \"Calibri\";"));
        splitter->addWidget(pushButtonModel);
        pushButtonReal = new QPushButton(splitter);
        pushButtonReal->setObjectName(QStringLiteral("pushButtonReal"));
        pushButtonReal->setEnabled(true);
        pushButtonReal->setAutoFillBackground(false);
        pushButtonReal->setStyleSheet(QStringLiteral("font: 75 14pt \"Calibri\";"));
        splitter->addWidget(pushButtonReal);
        pushButtonModelAndReal = new QPushButton(splitter);
        pushButtonModelAndReal->setObjectName(QStringLiteral("pushButtonModelAndReal"));
        pushButtonModelAndReal->setEnabled(true);
        pushButtonModelAndReal->setAutoFillBackground(false);
        pushButtonModelAndReal->setStyleSheet(QStringLiteral("font: 75 14pt \"Calibri\";"));
        splitter->addWidget(pushButtonModelAndReal);
        lineEditModel = new QLineEdit(centralWidget);
        lineEditModel->setObjectName(QStringLiteral("lineEditModel"));
        lineEditModel->setGeometry(QRect(230, 580, 91, 21));
        lineEditReal = new QLineEdit(centralWidget);
        lineEditReal->setObjectName(QStringLiteral("lineEditReal"));
        lineEditReal->setGeometry(QRect(370, 580, 91, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 580, 31, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 580, 31, 21));
        lineEditAppNo = new QLineEdit(centralWidget);
        lineEditAppNo->setObjectName(QStringLiteral("lineEditAppNo"));
        lineEditAppNo->setGeometry(QRect(40, 580, 113, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 580, 31, 21));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Create", 0));
        pushButtonModel->setText(QApplication::translate("MainWindow", "Model", 0));
        pushButtonReal->setText(QApplication::translate("MainWindow", "Real", 0));
        pushButtonModelAndReal->setText(QApplication::translate("MainWindow", "ModelAndReal", 0));
        label->setText(QApplication::translate("MainWindow", "Model", 0));
        label_2->setText(QApplication::translate("MainWindow", "Real", 0));
        label_3->setText(QApplication::translate("MainWindow", "AppNo", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
