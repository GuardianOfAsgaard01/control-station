#ifndef SAYTEK_H
#define SAYTEK_H

#include <QMainWindow>
#include <fstream>
#include <time.h>
#include <scoretable.h>
#include <leadership.h>
#include <QKeyEvent>

namespace Ui {
class saytek;
}

class saytek : public QMainWindow
{
    Q_OBJECT

public:
    explicit saytek(QWidget *parent = nullptr);
    ~saytek();
    virtual void keyPressEvent(QKeyEvent *e);

private:
    Ui::saytek *ui;
    ScoreTable *scoretable;
    leadership *leader;

private slots:
    void StartPressed();
    void FinishPressed();
    void BreakPressed();
    void LeadershipPressed();
};

extern time_t started,ended;
extern double sure;

#endif // SAYTEK_H
