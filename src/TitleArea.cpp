#include "TitleArea.hpp"
#include "ui_TitleArea.h"

TitleArea::TitleArea(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TitleArea)
{
    ui->setupUi(this);
    SevenSegment = new QFont("Seven Segment", 25, QFont::Light);
    InterFont = new QFont("Inter", 20, QFont::Normal);
    ui->songTitle->setFont(*InterFont);
}

void TitleArea::setSongTitle(QString &songTitle)
{
    ui->songTitle->setText(songTitle);
}

TitleArea::~TitleArea()
{
    delete SevenSegment;
    delete InterFont;
    delete ui;
}

void TitleArea::setSongDuration(size_t songDurationSeconds)
{
    QString text = QStringLiteral("%1:%2s").arg(songDurationSeconds/60, 2, 10, QLatin1Char('0')).arg(songDurationSeconds%60, 2, 10, QLatin1Char('0'));
    //text.sprintf("%02d:%02ds", songDurationSeconds/60, songDurationSeconds%60);

    ui->songDuration->setText(text);

}
