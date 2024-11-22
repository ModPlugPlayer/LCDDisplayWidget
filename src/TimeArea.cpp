/*
TimeArea class definitions of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "TimeArea.hpp"
#include "ui_TimeArea.h"

TimeArea::TimeArea(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TimeArea)
{
    ui->setupUi(this);
    SevenSegment = new QFont("Seven Segment", 25, QFont::Light);
    InterFont = new QFont("Inter", 20, QFont::Normal);
    ui->secondDigit1->setFont(*SevenSegment);
    ui->secondDigit2->setFont(*SevenSegment);
    ui->minuteDigit1->setFont(*SevenSegment);
    ui->minuteDigit2->setFont(*SevenSegment);
    ui->colon->setFont(*SevenSegment);
}

void TimeArea::updateTime(int seconds)
{
    ui->minuteDigit1->setText(QString::number(seconds/600));
    ui->minuteDigit2->setText(QString::number(seconds/60));
    ui->secondDigit1->setText(QString::number((seconds%60)/10));
    ui->secondDigit2->setText(QString::number((seconds%60)%10));

}

TimeArea::~TimeArea()
{
    delete SevenSegment;
    delete InterFont;
    delete ui;
}
