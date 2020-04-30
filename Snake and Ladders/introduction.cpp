#include "introduction.h"
#include "ui_introduction.h"

introduction::introduction(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::introduction)
{
    ui->setupUi(this);
}

introduction::~introduction()
{
    delete ui;
}
void introduction::on_pushButton_clicked()
{
    hide();
    playerIntroduction *v = new playerIntroduction();
    v->showMaximized();
}
