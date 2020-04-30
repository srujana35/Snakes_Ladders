#ifndef PLAYERINTRODUCTION_H
#define PLAYERINTRODUCTION_H

#include <QMainWindow>
#include <QString>
#include <QInputDialog>
#include "game.h"

namespace Ui {
class playerIntroduction;
}

class playerIntroduction : public QMainWindow
{
    Q_OBJECT

public:
    explicit playerIntroduction(QWidget *parent = nullptr);
    ~playerIntroduction();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::playerIntroduction *ui;
    QVector <QString> playerNames;
};

#endif // PLAYERINTRODUCTION_H
