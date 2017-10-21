#include "headers/gui.hpp"
#include "QGridLayout"
#include "QSpinBox"
#include "QLabel"
#include "QPushButton"

gui::gui() : QWidget()
{
    QLabel *nbSortie = new QLabel("Nombre de sorties :");
    QLabel *nbLayer = new QLabel("Nombre de couches :");
    QSpinBox *spinNbSortie = new QSpinBox();
    QSpinBox *spinNbLayer = new QSpinBox();
    QPushButton *boutonPret = new QPushButton("Paramètres");
    QLabel *validationConf = new QLabel("Configuration non terminee");
    QPushButton *bouttonFin = new QPushButton("GOOOOOO !");

    QGridLayout *monLayout = new QGridLayout();
    monLayout->addWidget(nbSortie, 1,1,1,1);
    monLayout->addWidget(spinNbSortie, 2,1,1,1);
    monLayout->addWidget(nbLayer, 3, 1, 1 ,1);
    monLayout->addWidget(spinNbLayer, 4, 1, 1, 1);
    monLayout->addWidget(boutonPret, 4, 2, 1 ,1);
    monLayout->addWidget(validationConf, 5, 1, 1, 2);
    monLayout->addWidget(bouttonFin, 6, 2, 1, 1);

    this->setLayout(monLayout);
}

