#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tic Tac Toe");

    buttons[0][0] = ui->Button1;
    buttons[0][1] = ui->Button2;
    buttons[0][2] = ui->Button3;

    buttons[1][0] = ui->Button4;
    buttons[1][1] = ui->Button5;
    buttons[1][2] = ui->Button6;

    buttons[2][0] = ui->Button7;
    buttons[2][1] = ui->Button8;
    buttons[2][2] = ui->Button9;

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            buttons[i][j]->setStyleSheet("background-color: " + defaultButtonColor + ";");
        }
    }
    this->setStyleSheet("background-color: " + defaultBackgroundColor + ";");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::applyStyle(const QString buttonColor, const QString backgroundColor)
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            buttons[i][j]->setStyleSheet("background-color: " + buttonColor + ";");
        }
    }
    this->setStyleSheet("background-color: " + backgroundColor + ";");
}

bool MainWindow::victory(int grid[3][3], int player) {
    for (int i=0; i<3; i++) {
        if ((grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
          ||(grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)) {

            return true;
        }
    }

    if ((grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
       ||(grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
            ) {

        return true;
    }

    else {
        return false;
    }
}

void MainWindow::checkWin()
{
    if (victory(grid, 1)||victory(grid, 2))
    {
        QString winner = (turnNumber%2==0) ? "1" : "2";
        ui->winnerLabel->setText("Player " + winner +  " won.");
        gameOver=true;
    }

    else if (turnNumber == 9)
    {
        ui->winnerLabel->setText("Game is a draw...");
        gameOver = true;
    }

}

QString MainWindow::nextSymbol(int n)
{
    return (n%2==0) ? playerSymbol1 : playerSymbol2;
}


void MainWindow::buttonClick(int i, int j)
{
    if (buttons[i][j]->text().isEmpty() && !(gameOver))
    {
        buttons[i][j]->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        ui->currentPlayerLabel->setText((turnNumber%2==0) ? "1" : "2");
        grid[2][2] = turnNumber%2+1;
        checkWin();
    }
}

void MainWindow::on_Button1_clicked()
{
    buttonClick(0,0);
}

void MainWindow::on_Button2_clicked()
{
    buttonClick(0,1);
}

void MainWindow::on_Button3_clicked()
{
    buttonClick(0, 2);
}

void MainWindow::on_Button4_clicked()
{
    buttonClick(1, 0);
}

void MainWindow::on_Button5_clicked()
{
    buttonClick(1, 1);
}

void MainWindow::on_Button6_clicked()
{
    buttonClick(1, 2);
}

void MainWindow::on_Button7_clicked()
{
    buttonClick(2, 0);
}

void MainWindow::on_Button8_clicked()
{
    buttonClick(2, 1);
}

void MainWindow::on_Button9_clicked()
{
    buttonClick(2, 2);
}




void MainWindow::on_actionReset_triggered()
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            buttons[i][j]->setText("");
        }
    }

    ui->currentPlayerLabel->setText("1");
    ui->winnerLabel->setText("");

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            grid[i][j] =0;
        }
    }

    gameOver=false;
    currentPlayerSymbol = playerSymbol1;
    turnNumber=0;
    ui->currentPlayerLabel->setText("1");


}


void MainWindow::on_actionDark_Mode_triggered(bool checked)
{
    if (checked)
    {
        applyStyle("rgb(69, 69, 69)","rgb(96, 96, 96)");
    }

    else
    {
        applyStyle(defaultButtonColor, defaultBackgroundColor);
    }
}

