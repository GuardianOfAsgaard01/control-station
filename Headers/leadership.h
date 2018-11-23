#ifndef LEADERSHIP_H
#define LEADERSHIP_H

#include <QMainWindow>
#include <fstream>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class leadership;
}

class leadership : public QMainWindow
{
    Q_OBJECT

public:
    explicit leadership(QWidget *parent = nullptr);
    ~leadership();

private slots:
    void on_refresh_clicked();

    void on_table_objectNameChanged();

private:
    Ui::leadership *ui;
};

struct{
    char nick[50];
    float time;
}Player[500];

#endif // LEADERSHIP_H
