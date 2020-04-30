#include "playerintroduction.h"
#include "ui_playerintroduction.h"

playerIntroduction::playerIntroduction(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::playerIntroduction)
{

    ui->setupUi(this);
    num_players=0;
    names.push_back("ks");
    vGrid = new QVBoxLayout;
    parent->setLayout(vGrid);
}
playerIntroduction::~playerIntroduction()
{
    delete ui;
}


void playerIntroduction::on_pushButton_clicked()
{
    QLineEdit *lineEdit = new QLineEdit;
    vGrid->addWidget(lineEdit,0,0);

}
