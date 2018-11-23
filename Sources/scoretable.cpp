#include "scoretable.h"
#include "ui_scoretable.h"
#include "saytek.h"
#include "leadership.h"

ScoreTable::ScoreTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScoreTable)
{
    ui->setupUi(this);
}

ScoreTable::~ScoreTable()
{
    delete ui;
}

void ScoreTable::on_kaydet_pressed()
{
    std::ofstream data;
    QString nickname=ui->input->text();
    QString score=ui->ekPuan->text();
    double puan = (sure - (score.toDouble() * 0.8));
    data.open("scoreBoard.dat", std::ios_base::app);
    data << nickname.toStdString() << std::endl; // converting type to save it
    data << puan << std::endl;
    data.close();
    this->hide();
}
