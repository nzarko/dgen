#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "igenerator.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupActions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupActions()
{
    connect(ui->actionE_xit, &QAction::triggered,qApp, &QApplication::closeAllWindows );
    connect(ui->actionGenerate, &QAction::triggered, this, &MainWindow::generate );
}

void MainWindow::generate()
{
    ///TODO: create data
    /// Float Generation
    IGenerator<float> fgen(0.2, 100.0, 20);
    auto res = fgen.generate();
    QString fdata;
    for(auto elem: res) {
        fdata += QString::number(elem,'g') + "\n";
    }
    ui->plainTextEdit->setPlainText(fdata);

    //Int Generation
    IGenerator<int> igen(1 ,100, 200);
    auto nums = igen.generate();

    QString separator(40, '*');
    ui->plainTextEdit->appendPlainText(separator);
    QString idata;
    auto print = [&idata](const int& n) { idata.append(QString::number( n) + '\n'); };
    std::for_each(nums.begin(), nums.end(), print);
    ui->plainTextEdit->appendPlainText(idata);

    // String Generation
    QString sdata;
    IGenerator<QString> str_gen(10);
    auto str_res = str_gen.generate();
    auto print_n = [&sdata](const QString& n) { sdata.append(n +  '\n'); };
    std::for_each(str_res.begin(), str_res.end(), print_n);
    //Separator
    ui->plainTextEdit->appendPlainText(separator);
    ui->plainTextEdit->appendPlainText(sdata);

}

