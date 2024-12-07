/*
TitleArea class definitions of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "TitleArea.hpp"
#include "ui_TitleArea.h"

TitleArea::TitleArea(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TitleArea)
{
    ui->setupUi(this);

    #ifdef Q_OS_MACOS
        //Makes this component seem under the transparent titlebar correctly
        setAttribute(Qt::WA_ContentsMarginsRespectsSafeArea, false);
    #endif

    SevenSegment = new QFont("Seven Segment", 12, QFont::Normal);
    InterFont = new QFont("Inter", 11, QFont::Normal);
    SongTitleFont = new QFont("Inter", 19, QFont::Normal);
    ui->title->setFont(*SongTitleFont);
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

void TitleArea::setTitle(const QString &title) {
    ui->title->setText(title);
}

TitleArea::~TitleArea()
{
    delete SevenSegment;
    delete InterFont;
    delete SongTitleFont;
    delete ui;
}

void TitleArea::setSongDuration(const size_t songDurationSeconds) {
    //QString text = QStringLiteral("%1:%2").arg(songDurationSeconds/60, 2, 10, QLatin1Char('0')).arg(songDurationSeconds%60, 2, 10, QLatin1Char('0'));
    //text.sprintf("%02d:%02ds", songDurationSeconds/60, songDurationSeconds%60);

    ui->songDurationSecondDigit1->setText(QString::number(songDurationSeconds%60%10));
    ui->songDurationSecondDigit2->setText(QString::number(songDurationSeconds%60/10));

    ui->songDurationMinuteDigit1->setText(QString::number(songDurationSeconds/60%10));
    ui->songDurationMinuteDigit2->setText(QString::number(songDurationSeconds/60/10));
}

void TitleArea::setCurrentPattern(const size_t currentPattern) {
    ui->currentPatternDigit1->setText(QString::number(currentPattern%10));
    ui->currentPatternDigit2->setText(QString::number(currentPattern/10%10));
    ui->currentPatternDigit3->setText(QString::number(currentPattern/100));
}

void TitleArea::setCurrentSubSong(const size_t currentSubSong) {
    ui->currentSubSongDigit1->setText(QString::number(currentSubSong%10));
    ui->currentSubSongDigit2->setText(QString::number(currentSubSong/10%10));
    ui->currentSubSongDigit3->setText(QString::number(currentSubSong/100));
}

void TitleArea::setSubSongAmount(const size_t subSongAmount) {
    ui->subSongAmountDigit1->setText(QString::number(subSongAmount%10));
    ui->subSongAmountDigit2->setText(QString::number(subSongAmount/10%10));
    ui->subSongAmountDigit3->setText(QString::number(subSongAmount/100));
}

void TitleArea::setPatternAmount(const size_t patternAmount) {
    ui->patternAmountDigit1->setText(QString::number(patternAmount%10));
    ui->patternAmountDigit2->setText(QString::number(patternAmount/10%10));
    ui->patternAmountDigit3->setText(QString::number(patternAmount/100));
}
