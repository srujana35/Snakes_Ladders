#include "finished.h"
#include "ui_finished.h"

finished::finished(QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finished)
{
    ui->setupUi(this);
    ui->label->setText(name);
    ui->label->setFont(QFont("Times",30,QFont::Bold));
    ui->label_2->setText("finished");
    ui->label_2->setFont(QFont("Times",30,QFont::Bold));
}

finished::~finished()
{
    delete ui;
}

void finished::on_pushButton_clicked()
{
    hide();
}
