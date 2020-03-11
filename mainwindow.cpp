#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <string>

//game gameInstance;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->pushButton0->setFlat(true);
//    QBrush tb(Qt::transparent); // Transparent brush, solid pattern
//    ui->pushButton0->setPalette(QPalette(tb, tb, tb, tb, tb, tb, tb, tb, tb)); // Set every color roles to the transparent brush
//    ui->pushButton0->setText("X");
//    QPushButton* helpButton = new QPushButton("Help");

//    ui->tableView->setIndexWidget(model->index(position,COLUMN_NUMBER), helpButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(int button)
{
    gameInstance.click(button);
    int winner = gameInstance.winner();
    static bool winnerFlag = false;
//    updateButton(button);
    if (!winnerFlag)
    {
        updateButton(button);
        switch (winner) {
            case -1:
                ui->label->setText("TIE");
//                updateButton(button);
                winnerFlag = true;
                break;
            case 1:
                ui->label->setText("X wins!");
//                updateButton(button);
                winnerFlag = true;
                break;
            case 2:
                ui->label->setText("O wins!");
//                updateButton(button);
                winnerFlag = true;
                break;
            default:
                QString turn = (gameInstance.getTurn() == 1) ? "X" : "O";
                ui->label->setText("It's " + turn + "'s turn.");
//                updateButton(button);
        }
    }
    winner = gameInstance.winner();
//    winner = gameInstance.winner();

//    ui->pushButton_0->setText( butt_text );
}

void MainWindow::updateButton(int button)
{
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


void MainWindow::on_pushButton_0_clicked()
{
//    gameInstance.click(0);
    update(0);
}

void MainWindow::on_pushButton_1_clicked()
{
//    gameInstance.click(1);
    update(1);
}

void MainWindow::on_pushButton_2_clicked()
{
//    gameInstance.click(2);
    update(2);
}

void MainWindow::on_pushButton_3_clicked()
{
//    gameInstance.click(3);
    update(3);
}

void MainWindow::on_pushButton_4_clicked()
{
//    gameInstance.click(4);
    update(4);
}

void MainWindow::on_pushButton_5_clicked()
{
//    gameInstance.click(5);
    update(5);
}

void MainWindow::on_pushButton_6_clicked()
{
//    gameInstance.click(6);
    update(6);
}

void MainWindow::on_pushButton_7_clicked()
{
//    gameInstance.click(7);
    update(7);
}

void MainWindow::on_pushButton_8_clicked()
{
//    gameInstance.click(8);
    update(8);
}
