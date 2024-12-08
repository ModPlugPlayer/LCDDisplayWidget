#include "SongInformationArea.hpp"
#include "ui_SongInformationArea.h"

SongInformationArea::SongInformationArea(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SongInformationArea)
{
    ui->setupUi(this);
    setWindowOpacity(0);
}

SongInformationArea::~SongInformationArea()
{
    delete ui;
}
