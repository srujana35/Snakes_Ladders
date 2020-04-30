#include "playerintroduction.h"
#include "ui_playerintroduction.h"

playerIntroduction::playerIntroduction(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::playerIntroduction)
{
    ui->setupUi(this);
}

playerIntroduction::~playerIntroduction()
{
    delete ui;
}

void playerIntroduction::on_pushButton_clicked()
{
    QString text = QInputDialog::getText(this, "Player Names", "add a name");
    playerNames.push_back(text);
    ui->label_2->setText(QString::number(playerNames.size()));
}

void playerIntroduction::on_pushButton_2_clicked()
{
    hide();
    game *Game = new game(playerNames,this);
    Game->showMaximized();
}
