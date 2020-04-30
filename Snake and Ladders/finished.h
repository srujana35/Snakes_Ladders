#ifndef FINISHED_H
#define FINISHED_H

#include <QDialog>

namespace Ui {
class finished;
}

class finished : public QDialog
{
    Q_OBJECT

public:
    explicit finished(QString name, QWidget *parent = nullptr);
    ~finished();

private slots:
    void on_pushButton_clicked();

private:
    Ui::finished *ui;
};

#endif // FINISHED_H
