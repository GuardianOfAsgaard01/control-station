#include "saytek.h"
#include "ui_saytek.h"
#include <QDialog>
#include "scoretable.h"
#include "leadership.h"
#include <QKeyEvent>

saytek::saytek(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::saytek)
{
    ui->setupUi(this);

    connect(ui->start, SIGNAL(released()), this, SLOT(StartPressed()));
    connect(ui->finish, SIGNAL(released()), this, SLOT(FinishPressed()));
    connect(ui->break_2, SIGNAL(released()), this, SLOT(BreakPressed()));
    connect(ui->leadership, SIGNAL(released()), this, SLOT(LeadershipPressed()));
    QPixmap pix("saytekk.jpg");
    ui->logo->setPixmap(pix);
}

saytek::~saytek()
{
    delete ui;
}

time_t started,ended;
double sure;
static bool flag = false;
static int check = 0;

void saytek::StartPressed()
{
    flag = true;
    time (&started);
}

void saytek::keyPressEvent(QKeyEvent *e)
{
    if (flag){
        switch(e->key())
        {
        case Qt::Key_W:
            if (check != 1){
                system("python client.py fren");
                system("python client.py geri");
                check = 1;
            }
            break;
        case Qt::Key_A:
            if (check != 2){
                system("python client.py fren");
                system("python client.py sol");
                check = 2;
            }
            break;
        case Qt::Key_S:
            if(check != 3){
                system("python client.py fren");
                system("python client.py ileri");
                check = 3;
            }
            break;
        case Qt::Key_D:
            if (check != 4){
                system("python client.py fren");
                system("python client.py sag");
                check = 4;
            }
            break;
        default:
            if (check != 5){
                system("python client.py fren");
                check = 5;
            }
        }
    }
}

void saytek::FinishPressed()
{
    time (&ended);
    flag = false;
    sure = difftime (ended, started);
    scoretable = new ScoreTable(this);
    scoretable->show();
}

void saytek::BreakPressed()
{
    system("python client.py fren");
}

void saytek::LeadershipPressed()
{
    leader = new leadership(this);
    leader->show();
}
