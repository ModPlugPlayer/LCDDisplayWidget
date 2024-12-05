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
    ui->subSong->setFont(*SevenSegment);
    ui->subSongAmount->setFont(*SevenSegment);
    ui->songDuration_colon->setFont(*SevenSegment);
    ui->pattern->setFont(*SevenSegment);
    ui->pattern_3->setFont(*SevenSegment);

    ui->songDuration_minute1->setFont(*SevenSegment);
    ui->songDuration_minute2->setFont(*SevenSegment);
    ui->songDuration_second1->setFont(*SevenSegment);
    ui->songDuration_second2->setFont(*SevenSegment);

    ui->s->setFont(*InterFont);
    ui->of->setFont(*InterFont);
    ui->slash->setFont(*InterFont);
    ui->song->setFont(*InterFont);
}

void TitleArea::setSongTitle(const QString &songTitle) {
    ui->title->setText(songTitle);
}

TitleArea::~TitleArea()
{
    delete SevenSegment;
    delete InterFont;
    delete SongTitleFont;
    delete ui;
}

void TitleArea::setSongDuration(const size_t songDurationSeconds) {
    QString text = QStringLiteral("%1:%2").arg(songDurationSeconds/60, 2, 10, QLatin1Char('0')).arg(songDurationSeconds%60, 2, 10, QLatin1Char('0'));
    //text.sprintf("%02d:%02ds", songDurationSeconds/60, songDurationSeconds%60);

    ui->songDuration_second2->setText(text);
}
