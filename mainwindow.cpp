#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->leResult->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cbxType_currentIndexChanged(int index)
{
    switch(ui->cbxType->currentIndex())
    {
    case 0:
        ui->cbxFrom->clear();
        ui->cbxFrom->addItem("Carat");
        ui->cbxFrom->addItem("Gram");
        ui->cbxFrom->addItem("Kilogram");
        ui->cbxFrom->addItem("Milligram");
        ui->cbxFrom->addItem("Lb.");
        ui->cbxFrom->addItem("Ton");
        //=========================================
        ui->cbxTo->clear();
        ui->cbxTo->addItem("Carat");
        ui->cbxTo->addItem("Gram");
        ui->cbxTo->addItem("Kilogram");
        ui->cbxTo->addItem("Milligram");
        ui->cbxTo->addItem("Lb.");
        ui->cbxTo->addItem("Ton");
        break;
    case 1:
        ui->cbxFrom->clear();
        ui->cbxFrom->addItem("Millimeter");
        ui->cbxFrom->addItem("Centimetre");
        ui->cbxFrom->addItem("Decimeter");
        ui->cbxFrom->addItem("Metre");
        ui->cbxFrom->addItem("Kilometer");
        ui->cbxFrom->addItem("Inch");
        ui->cbxFrom->addItem("Foot");
        ui->cbxFrom->addItem("Mile");
        ui->cbxFrom->addItem("Arshin");
        ui->cbxFrom->addItem("Caliber");
        //=========================================
        ui->cbxTo->clear();
        ui->cbxTo->addItem("Millimeter");
        ui->cbxTo->addItem("Centimetre");
        ui->cbxTo->addItem("Decimeter");
        ui->cbxTo->addItem("Metre");
        ui->cbxTo->addItem("Kilometer");
        ui->cbxTo->addItem("Inch");
        ui->cbxTo->addItem("Foot");
        ui->cbxTo->addItem("Mile");
        ui->cbxTo->addItem("Arshin");
        ui->cbxTo->addItem("Caliber");
        break;
    case 2:
        ui->cbxFrom->clear();
        ui->cbxFrom->addItem("Millisecond");
        ui->cbxFrom->addItem("Second");
        ui->cbxFrom->addItem("Minute");
        ui->cbxFrom->addItem("Hour");
        ui->cbxFrom->addItem("Day");
        ui->cbxFrom->addItem("Week");
        ui->cbxFrom->addItem("Month");
        ui->cbxFrom->addItem("Year");
        //=====================================
        ui->cbxTo->clear();
        ui->cbxTo->addItem("Millisecond");
        ui->cbxTo->addItem("Second");
        ui->cbxTo->addItem("Minute");
        ui->cbxTo->addItem("Hour");
        ui->cbxTo->addItem("Day");
        ui->cbxTo->addItem("Week");
        ui->cbxTo->addItem("Month");
        ui->cbxTo->addItem("Year");
        break;
    case 3:
        ui->cbxFrom->clear();
        ui->cbxFrom->addItem("Barrel");
        ui->cbxFrom->addItem("cm³");
        ui->cbxFrom->addItem("ft³");
        ui->cbxFrom->addItem("m³");
        ui->cbxFrom->addItem("Gallon");
        ui->cbxFrom->addItem("Litre");
        ui->cbxFrom->addItem("Milliliter");
        ui->cbxFrom->addItem("Ounce (fl oz)");
        //====================================
        ui->cbxTo->clear();
        ui->cbxTo->addItem("Barrel");
        ui->cbxTo->addItem("cm³");
        ui->cbxTo->addItem("ft³");
        ui->cbxTo->addItem("m³");
        ui->cbxTo->addItem("Gallon");
        ui->cbxTo->addItem("Litre");
        ui->cbxTo->addItem("Milliliter");
        ui->cbxTo->addItem("Ounce (fl oz)");
        break;
    }
}


void MainWindow::on_btnCalculate_clicked()
{
    double referenceValue;
    double enteredValue;
    double endValue;
    enteredValue = ui->leFrom->text().toDouble();
    //Перевод в эталонную величину
    switch(ui->cbxType->currentIndex())
    {
    case 0:
        //Килограмм
        switch(ui->cbxFrom->currentIndex())
        {
        case 0:
            referenceValue = enteredValue * 0.0002;
            break;
        case 1:
            referenceValue = enteredValue * 0.001;
            break;
        case 2:
            referenceValue = enteredValue;
            break;
        case 3:
            referenceValue = enteredValue * 0.000001;
            break;
        case 4:
            referenceValue = enteredValue * 0.453592369999995;
            break;
        case 5:
            referenceValue = enteredValue * 1000;
            break;
        }
        break;
    case 1:
        //Метр
        switch(ui->cbxFrom->currentIndex())
        {
        case 0:
            referenceValue = enteredValue * 0.001;
            break;
        case 1:
            referenceValue = enteredValue * 0.01;
            break;
        case 2:
            referenceValue = enteredValue * 0.1;
            break;
        case 3:
            referenceValue = enteredValue;
            break;
        case 4:
            referenceValue = enteredValue * 1000;
            break;
        case 5:
            referenceValue = enteredValue * 0.02540000000000031;
            break;
        case 6:
            referenceValue = enteredValue * 0.3048000000000022;
            break;
        case 7:
            referenceValue = enteredValue * 1609.3439999999998;
            break;
        case 8:
            referenceValue = enteredValue * 0.711200000000005;
            break;
        case 9:
            referenceValue = enteredValue * 0.0002540000000000031;
            break;
        }
        break;
    case 2:
        //Час
        switch(ui->cbxFrom->currentIndex())
        {
        case 0:
            referenceValue = enteredValue * 2.7777777777777776;
            break;
        case 1:
            referenceValue = enteredValue * 0.0002777777777777778;
            break;
        case 2:
            referenceValue = enteredValue * 0.016666666666666666;
            break;
        case 3:
            referenceValue = enteredValue;
            break;
        case 4:
            referenceValue = enteredValue * 24;
            break;
        case 5:
            referenceValue = enteredValue * 167.99999999999997;
            break;
        case 6:
            referenceValue = enteredValue * 720.0000000000001;
            break;
        case 7:
            referenceValue = enteredValue * 8760.000000119137;
            break;
        }
        break;
    case 3:
        //Литр
        switch(ui->cbxFrom->currentIndex())
        {
        case 0:
            referenceValue = enteredValue * 158.98729492800013;
            break;
        case 1:
            referenceValue = enteredValue * 0.001;
            break;
        case 2:
            referenceValue = enteredValue * 28.31684659199967;
            break;
        case 3:
            referenceValue = enteredValue * 1000;
            break;
        case 4:
            referenceValue = enteredValue * 3.7854117839999772;
            break;
        case 5:
            referenceValue = enteredValue;
            break;
        case 6:
            referenceValue = enteredValue * 0.001;
            break;
        case 7:
            referenceValue = enteredValue * 0.029573529562499996;
            break;
        }
        break;
    }
    //==========================
    switch(ui->cbxType->currentIndex())
    {
    case 0:
        //Килограмм
        switch(ui->cbxTo->currentIndex())
        {
        case 0:
            endValue = referenceValue * 5000;
            break;
        case 1:
            endValue = referenceValue * 1000;
            break;
        case 2:
            endValue = referenceValue;
            break;
        case 3:
            endValue = referenceValue * 1000000;
            break;
        case 4:
            endValue = referenceValue * 2.2046226218488;
            break;
        case 5:
            endValue = referenceValue * 0.001;
            break;
        }
        break;
    case 1:
        //Метр
        switch(ui->cbxTo->currentIndex())
        {
        case 0:
            endValue = referenceValue * 1000;
            break;
        case 1:
            endValue = referenceValue * 100;
            break;
        case 2:
            endValue = referenceValue * 10;
            break;
        case 3:
            endValue = referenceValue;
            break;
        case 4:
            endValue = referenceValue * 0.001;
            break;
        case 5:
            endValue = referenceValue * 39.370078740157;
            break;
        case 6:
            endValue = referenceValue * 3.2808398950131;
            break;
        case 7:
            endValue = referenceValue * 0.000621371192237334;
            break;
        case 8:
            endValue = referenceValue * 1.4060742407199;
            break;
        case 9:
            endValue = referenceValue * 3937.0078740157;
            break;
        }
        break;
    case 2:
        //Час
        switch(ui->cbxTo->currentIndex())
        {
        case 0:
            endValue = referenceValue * 3600000 ;
            break;
        case 1:
            endValue = referenceValue * 3600;
            break;
        case 2:
            endValue = referenceValue * 60;
            break;
        case 3:
            endValue = referenceValue;
            break;
        case 4:
            endValue = referenceValue * 0.041666666666666664;
            break;
        case 5:
            endValue = referenceValue * 0.005952380952380953;
            break;
        case 6:
            endValue = referenceValue * 0.0013888888888888887;
            break;
        case 7:
            endValue = referenceValue * 0.00011415525114;
            break;
        }
        break;
    case 3:
        //Литр
        switch(ui->cbxTo->currentIndex())
        {
        case 0:
            endValue = referenceValue * 0.0062898107704321;
            break;
        case 1:
            endValue = referenceValue * 1000;
            break;
        case 2:
            endValue = referenceValue * 0.035314666721489;
            break;
        case 3:
            endValue = referenceValue * 0.001;
            break;
        case 4:
            endValue = referenceValue * 0.26417205235815;
            break;
        case 5:
            endValue = referenceValue;
            break;
        case 6:
            endValue = referenceValue * 1000;
            break;
        case 7:
            endValue = referenceValue * 33.814022701843;
            break;
        }
        break;
    }
    ui->leResult->setText(QString("%1").arg(endValue));
}

void MainWindow::on_leFrom_cursorPositionChanged(int arg1, int arg2)
{
    QRegularExpressionValidator *v = new QRegularExpressionValidator(QRegularExpression("^\\d+|\\d+.\\d+$"));
    ui->leFrom->setValidator(v);
}

