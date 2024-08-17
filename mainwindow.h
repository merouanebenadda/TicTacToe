#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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
    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_Button3_clicked();

    void on_Button4_clicked();

    void on_Button5_clicked();

    void on_Button6_clicked();

    void on_Button7_clicked();

    void on_Button8_clicked();

    void on_Button9_clicked();

    void on_actionReset_triggered();

    void on_actionDark_Mode_triggered(bool checked);

private:
    Ui::MainWindow *ui;

private:
    const QString playerSymbol1 = "x";
    const QString playerSymbol2 = "o";
    QString currentPlayerSymbol = playerSymbol1;
    int grid[3][3];
    int turnNumber;
    bool gameOver = false;
    QPushButton* buttons[3][3];
    const QString defaultButtonColor = "rgb(200, 200, 200)";
    const QString defaultBackgroundColor = "rgb(230, 230, 230)";

    void applyStyle(QString buttonColor, QString backgroundColor);
    void buttonClick(int i, int j);
    void checkWin();
    QString nextSymbol(int n);
    bool victory(int grid[3][3], int player);


};
#endif // MAINWINDOW_H
