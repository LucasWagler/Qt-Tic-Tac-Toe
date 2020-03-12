// Lucas Wagler
// Dr. Khadka
// 2020-03-11
// Tic-Tac-Toe with Victory Lines

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <string>
#include <QMessageBox>
#include <QApplication> // May not be needed; doesn't seem to affect functionality on my Manjaro Linux install

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resetBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetBoard()
{
    ui->win0->setStyleSheet("color: rgba(0,0,0,0)");
    ui->win0->lower();
    ui->win3->setStyleSheet("color: rgba(0,0,0,0)");
    ui->win3->lower();
    ui->win6->setStyleSheet("color: rgba(0,0,0,0)");
    ui->win6->lower();
    ui->win10->setStyleSheet("color: rgba(0,0,0,0)");
    ui->win10->lower();
    ui->win11->setStyleSheet("color: rgba(0,0,0,0)");
    ui->win11->lower();
    ui->win12->setStyleSheet("color: rgba(0,0,0,0)");
    ui->win12->lower();
    ui->win20->setStyleSheet("color: rgba(0,0,0,0)");
    ui->win20->lower();
    ui->win21->setStyleSheet("color: rgba(0,0,0,0)");
    ui->win21->lower();
}

void MainWindow::updateWinLine()
{
    int winResult = gameInstance.winResult();
    switch(winResult) {
        case 0:
            ui->win0->raise();
            ui->win0->setStyleSheet("color: rgba(238, 129, 99, 1)");
            break;
        case 3:
            ui->win3->raise();
            ui->win3->setStyleSheet("color: rgba(238, 129, 99, 1)");
            break;
        case 6:
            ui->win6->raise();
            ui->win6->setStyleSheet("color: rgba(238, 129, 99, 1)");
            break;
        case 10:
            ui->win10->raise();
            ui->win10->setStyleSheet("color: rgba(238, 129, 99, 1)");
            break;
        case 11:
            ui->win11->raise();
            ui->win11->setStyleSheet("color: rgba(238, 129, 99, 1)");
            break;
        case 12:
            ui->win12->raise();
            ui->win12->setStyleSheet("color: rgba(238, 129, 99, 1)");
            break;
        case 20:
            ui->win20->raise();
            ui->win20->setStyleSheet("color: rgba(238, 129, 99, 1)");
            break;
        case 21:
            ui->win21->raise();
            ui->win21->setStyleSheet("color: rgba(238, 129, 99, 1)");
            break;
    }
}

void MainWindow::update(int button)
{
    // Update game state with new click
    gameInstance.click(button);
    // Check for win/end condition
    int winner = gameInstance.winner();
    static bool winnerFlag = false;
    if (!winnerFlag)
    {
        updateButton(button);
        switch (winner) {
            case -1:
                ui->label->setText("TIE");
                updateWinLine();
                winnerFlag = true;
                exitDialog();
                break;
            case 1:
                ui->label->setText("X wins!");
                updateWinLine();
                winnerFlag = true;
                exitDialog();
                break;
            case 2:
                ui->label->setText("O wins!");
                updateWinLine();
                winnerFlag = true;
                exitDialog();
                break;
            default:
                QString turn = (gameInstance.getTurn() == 1) ? "X" : "O";
                ui->label->setText("It's " + turn + "'s turn.");
        }
    }
}

void MainWindow::updateButton(int button)
{
    // Sets button text according to game state
    int *stateptr = gameInstance.getState();
    QString butt_text = (stateptr[button] == 1) ? "X" : "O";
    switch (button)
    {
        case 0:
            ui->pushButton_0->setText( butt_text );
            break;
        case 1:
            ui->pushButton_1->setText( butt_text );
            break;
        case 2:
            ui->pushButton_2->setText( butt_text );
            break;
        case 3:
            ui->pushButton_3->setText( butt_text );
            break;
        case 4:
            ui->pushButton_4->setText( butt_text );
            break;
        case 5:
            ui->pushButton_5->setText( butt_text );
            break;
        case 6:
            ui->pushButton_6->setText( butt_text );
            break;
        case 7:
            ui->pushButton_7->setText( butt_text );
            break;
        case 8:
            ui->pushButton_8->setText( butt_text );
            break;
    }
}

void MainWindow::exitDialog()
{
    // Create dialog
    QMessageBox msgBox;
    msgBox.setWindowTitle("Quitting Time");
    msgBox.setText("Thank you for playing. Sending you back to the real world...");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    // Check dialog choice
    if( msgBox.exec() == QMessageBox::No )
    {
        QApplication::quit();
    }
    else
    {
        QApplication::quit();
    }
}


void MainWindow::on_pushButton_0_clicked()
{
    update(0);
}

void MainWindow::on_pushButton_1_clicked()
{
    update(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    update(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    update(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    update(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    update(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    update(6);
}

void MainWindow::on_pushButton_7_clicked()
{
    update(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    update(8);
}
