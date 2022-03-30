#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cbxType_currentIndexChanged(int index);

    void on_btnCalculate_clicked();

    void on_leFrom_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
