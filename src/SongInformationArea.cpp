#include "SongInformationArea.hpp"
#include "ui_SongInformationArea.h"

SongInformationArea::SongInformationArea(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SongInformationArea)
{
    ui->setupUi(this);
    setWindowOpacity(0);
    SevenSegment = new QFont("Seven Segment", QFont::Normal);
    SevenSegment->setPixelSize(12);
    InterFont = new QFont("Inter", QFont::Normal);
    InterFont->setPixelSize(11);
    SongTitleFont = new QFont("Inter", QFont::Normal);
    SongTitleFont->setPixelSize(19);
    //ui->title->setFont(*SongTitleFont);

    ui->subSongAmountDigit1->setFont(*SevenSegment);
    ui->subSongAmountDigit2->setFont(*SevenSegment);
    ui->subSongAmountDigit3->setFont(*SevenSegment);
    ui->currentSubSongDigit1->setFont(*SevenSegment);
    ui->currentSubSongDigit2->setFont(*SevenSegment);
    ui->currentSubSongDigit3->setFont(*SevenSegment);
    ui->songDurationColon->setFont(*SevenSegment);
    ui->patternAmountDigit1->setFont(*SevenSegment);
    ui->patternAmountDigit2->setFont(*SevenSegment);
    ui->patternAmountDigit3->setFont(*SevenSegment);
    ui->currentPatternDigit1->setFont(*SevenSegment);
    ui->currentPatternDigit2->setFont(*SevenSegment);
    ui->currentPatternDigit3->setFont(*SevenSegment);

    ui->songDurationMinuteDigit1->setFont(*SevenSegment);
    ui->songDurationMinuteDigit2->setFont(*SevenSegment);
    ui->songDurationSecondDigit1->setFont(*SevenSegment);
    ui->songDurationSecondDigit2->setFont(*SevenSegment);

    ui->s->setFont(*InterFont);
    ui->of->setFont(*InterFont);
    ui->slash->setFont(*InterFont);
    ui->song->setFont(*InterFont);
}

void SongInformationArea::setSongDuration(const size_t songDurationSeconds) {
    //QString text = QStringLiteral("%1:%2").arg(songDurationSeconds/60, 2, 10, QLatin1Char('0')).arg(songDurationSeconds%60, 2, 10, QLatin1Char('0'));
    //text.sprintf("%02d:%02ds", songDurationSeconds/60, songDurationSeconds%60);

    ui->songDurationSecondDigit1->setText(QString::number(songDurationSeconds%60%10));
    ui->songDurationSecondDigit2->setText(QString::number(songDurationSeconds%60/10));

    ui->songDurationMinuteDigit1->setText(QString::number(songDurationSeconds/60%10));
    ui->songDurationMinuteDigit2->setText(QString::number(songDurationSeconds/60/10));

}

void SongInformationArea::setCurrentPattern(const size_t currentPattern) {
    ui->currentPatternDigit1->setText(QString::number(currentPattern%10));
    ui->currentPatternDigit2->setText(QString::number(currentPattern/10%10));
    ui->currentPatternDigit3->setText(QString::number(currentPattern/100));
}

void SongInformationArea::setCurrentSubSong(const size_t currentSubSong) {
    ui->currentSubSongDigit1->setText(QString::number(currentSubSong%10));
    ui->currentSubSongDigit2->setText(QString::number(currentSubSong/10%10));
    ui->currentSubSongDigit3->setText(QString::number(currentSubSong/100));
}

void SongInformationArea::setSubSongAmount(const size_t subSongAmount) {
    ui->subSongAmountDigit1->setText(QString::number(subSongAmount%10));
    ui->subSongAmountDigit2->setText(QString::number(subSongAmount/10%10));
    ui->subSongAmountDigit3->setText(QString::number(subSongAmount/100));
}

void SongInformationArea::setPatternAmount(const size_t patternAmount) {
    ui->patternAmountDigit1->setText(QString::number(patternAmount%10));
    ui->patternAmountDigit2->setText(QString::number(patternAmount/10%10));
    ui->patternAmountDigit3->setText(QString::number(patternAmount/100));
}

SongInformationArea::~SongInformationArea()
{
    delete ui;
}
