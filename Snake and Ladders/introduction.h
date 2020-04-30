#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include <QMainWindow>
#include "playerintroduction.h"

QT_BEGIN_NAMESPACE
namespace Ui { class introduction; }
QT_END_NAMESPACE

class introduction : public QMainWindow
{
    Q_OBJECT

public:
    introduction(QWidget *parent = nullptr);
    ~introduction();

private slots:
    void on_pushButton_clicked();

private:
    Ui::introduction *ui;
};
#endif // INTRODUCTION_H
