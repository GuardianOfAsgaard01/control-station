#ifndef SCORETABLE_H
#define SCORETABLE_H

#include <QMainWindow>
#include <fstream>
#include <ctime>

extern clock_t time_now, timer;

namespace Ui {
class ScoreTable;
}

class ScoreTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScoreTable(QWidget *parent = nullptr);
    ~ScoreTable();

private:
    Ui::ScoreTable *ui;

private slots:
    void on_kaydet_pressed();
};

#endif // SCORETABLE_H
