#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tic Tac Toe");
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_Button1_clicked()
{
    if (ui->Button1->text().isEmpty() && !(gameOver))
    {
        ui->Button1->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        ui->currentPlayerLabel->setText((turnNumber%2==0) ? "1" : "2");
        grid[0][0] = turnNumber%2+1;
        checkWin();
    }


}

void MainWindow::on_Button2_clicked()
{
    if (ui->Button2->text().isEmpty() && !(gameOver))
    {
        ui->Button2->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        ui->currentPlayerLabel->setText((turnNumber%2==0) ? "1" : "2");
        grid[0][1] = turnNumber%2+1;
        checkWin();
    }

}

void MainWindow::on_Button3_clicked()
{
    if (ui->Button3->text().isEmpty() && !(gameOver))
    {
        ui->Button3->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        ui->currentPlayerLabel->setText((turnNumber%2==0) ? "1" : "2");
        grid[0][2] = turnNumber%2+1;
        checkWin();
    }
}

void MainWindow::on_Button4_clicked()
{
    if (ui->Button4->text().isEmpty() && !(gameOver))
    {
        ui->Button4->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        ui->currentPlayerLabel->setText((turnNumber%2==0) ? "1" : "2");
        grid[1][0] = turnNumber%2+1;
        checkWin();
    }
}

void MainWindow::on_Button5_clicked()
{
    if (ui->Button5->text().isEmpty() && !(gameOver))
    {
        ui->Button5->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        ui->currentPlayerLabel->setText((turnNumber%2==0) ? "1" : "2");
        grid[1][1] = turnNumber%2+1;
        checkWin();
    }
}

void MainWindow::on_Button6_clicked()
{
    if (ui->Button6->text().isEmpty() && !(gameOver))
    {
        ui->Button6->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        ui->currentPlayerLabel->setText((turnNumber%2==0) ? "1" : "2");
        grid[1][2] = turnNumber%2+1;
        checkWin();
    }
}

void MainWindow::on_Button7_clicked()
{
    if (ui->Button7->text().isEmpty() && !(gameOver))
    {
        ui->Button7->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        ui->currentPlayerLabel->setText((turnNumber%2==0) ? "1" : "2");
        grid[2][0] = turnNumber%2+1;
        checkWin();
    }
}

void MainWindow::on_Button8_clicked()
{
    if (ui->Button8->text().isEmpty() && !(gameOver))
    {
        ui->Button8->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        ui->currentPlayerLabel->setText((turnNumber%2==0) ? "1" : "2");
        grid[2][1] = turnNumber%2+1;
        checkWin();
    }
}

void MainWindow::on_Button9_clicked()
{
    if (ui->Button9->text().isEmpty() && !(gameOver))
    {
        ui->Button9->setText(currentPlayerSymbol);
        turnNumber++;
        currentPlayerSymbol = nextSymbol(turnNumber);
        ui->currentPlayerLabel->setText((turnNumber%2==0) ? "1" : "2");
        grid[2][2] = turnNumber%2+1;
        checkWin();
    }
}




void MainWindow::on_actionReset_triggered()
{
    ui->Button1->setText("");
    ui->Button2->setText("");
    ui->Button3->setText("");
    ui->Button4->setText("");
    ui->Button5->setText("");
    ui->Button6->setText("");
    ui->Button7->setText("");
    ui->Button8->setText("");
    ui->Button9->setText("");

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

