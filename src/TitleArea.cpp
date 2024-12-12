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

    SevenSegment = new QFont("Seven Segment", QFont::Normal);
    SevenSegment->setPixelSize(12);
    InterFont = new QFont("Inter", QFont::Normal);
    InterFont->setPixelSize(11);
    SongTitleFont = new QFont("Inter", QFont::Normal);
    SongTitleFont->setPixelSize(19);
    ui->title->setFont(*SongTitleFont);
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
