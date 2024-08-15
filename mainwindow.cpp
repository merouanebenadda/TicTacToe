#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkWin()
{
    if (turnNumber == 9)
    {
        ui->winnerLabel->setText("Game is a draw...");
    }

    else
    {
        ui->currentPlayerLabel->setText((currentPlayerSymbol == "X") ? "1" : "2");
    }
}

QString nextSymbol(int n)
{
    return (n%2==0) ? "X" : "O";
}

void MainWindow::on_Button1_clicked()
{
    if (ui->Button1->text().isEmpty())
    {
        ui->Button1->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        checkWin();
    }


}

void MainWindow::on_Button2_clicked()
{
    if (ui->Button2->text().isEmpty())
    {
        ui->Button2->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        checkWin();
    }

}

void MainWindow::on_Button3_clicked()
{
    if (ui->Button3->text().isEmpty())
    {
        ui->Button3->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        checkWin();
    }
}

void MainWindow::on_Button4_clicked()
{
    if (ui->Button4->text().isEmpty())
    {
        ui->Button4->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        checkWin();
    }
}

void MainWindow::on_Button5_clicked()
{
    if (ui->Button5->text().isEmpty())
    {
        ui->Button5->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        checkWin();
    }
}

void MainWindow::on_Button6_clicked()
{
    if (ui->Button6->text().isEmpty())
    {
        ui->Button6->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        checkWin();
    }
}

void MainWindow::on_Button7_clicked()
{
    if (ui->Button7->text().isEmpty())
    {
        ui->Button7->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        checkWin();
    }
}

void MainWindow::on_Button8_clicked()
{
    if (ui->Button8->text().isEmpty())
    {
        ui->Button8->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        checkWin();
    }
}

void MainWindow::on_Button9_clicked()
{
    if (ui->Button9->text().isEmpty())
    {
        ui->Button9->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        checkWin();
    }
}



