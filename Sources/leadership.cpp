#include "leadership.h"
#include "ui_leadership.h"
#include <iostream>
#include <string>

leadership::leadership(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::leadership)
{
    ui->setupUi(this);

    connect(ui->refresh, SIGNAL(released()), this, SLOT(on_refresh_pressed()));
}

leadership::~leadership()
{
    delete ui;
}

static int count = 0;

void leadership::on_refresh_clicked()
{
    std::ifstream file;
    int i;
    file.open("scoreBoard.dat", std::ios::in);
    for(count=0, i=0; !file.eof(); ++i){
        if (i%2 == 0){
            file >> Player[count].nick;
        }
        else{
            file >> Player[count].time;
            ++count;
        }
    }
    file.close();
    leadership::on_table_objectNameChanged();
}

void leadership::on_table_objectNameChanged()
{
    char temp[100];
    ui->table->clearContents();
    ui->table->	setRowCount(count);
    ui->table->setHorizontalHeaderItem(0, new QTableWidgetItem("Oyuncu"));
    ui->table->setHorizontalHeaderItem(1, new QTableWidgetItem("Puan"));
    for(int i=0; i< count; ++i){
        sprintf(temp, "%f", Player[i].time);
        ui->table->setItem(i, 0, new QTableWidgetItem(Player[i].nick));
        ui->table->setItem(i, 1, new QTableWidgetItem(temp));
    }
    ui->table->sortItems(1, Qt::AscendingOrder);
}
