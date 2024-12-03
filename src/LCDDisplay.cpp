/*
LCDDisplay class definitions of ModPlug Player
Copyright (C) 2020 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "LCDDisplay.hpp"
#include "ui_LCDDisplay.h"
#include <QFile>
#include <QDebug>

LCDDisplay::LCDDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LCDDisplay)
{
    ui->setupUi(this);

    #ifdef Q_OS_MACOS
        //Makes this component seem under the transparent titlebar correctly
        setAttribute(Qt::WA_ContentsMarginsRespectsSafeArea, false);
    #endif

    SevenSegment = new QFont("Seven Segment", 25, QFont::Light);
    InterFont = new QFont("Inter", 20, QFont::Normal);
    connect(ui->propertiesArea, &PropertiesArea::repeatModeChangeRequested, this, &LCDDisplay::repeatModeChangeRequested);
    connect(ui->propertiesArea, &PropertiesArea::eqStateChangeRequested, this, &LCDDisplay::eqStateChangeRequested);
    connect(ui->propertiesArea, &PropertiesArea::agcStateChangeRequested, this, &LCDDisplay::agcStateChangeRequested);
    connect(ui->propertiesArea, &PropertiesArea::xBassStateChangeRequested, this, &LCDDisplay::xBassStateChangeRequested);
    connect(ui->propertiesArea, &PropertiesArea::surroundStateChangeRequested, this, &LCDDisplay::surroundStateChangeRequested);
    connect(ui->propertiesArea, &PropertiesArea::reverbStateChangeRequested, this, &LCDDisplay::reverbStateChangeRequested);
    connect(ui->propertiesArea, &PropertiesArea::interpolationModeChangeRequested, this, &LCDDisplay::interpolationModeChangeRequested);
}

void LCDDisplay::updateTime(int seconds)
{
    ui->timeArea->updateTime(seconds);
}

void LCDDisplay::setSongTitle(QString songTitle)
{
    ui->titleArea->setSongTitle(songTitle);
}

void LCDDisplay::setRepeatMode(ModPlugPlayer::RepeatMode repeatMode)
{
    ui->propertiesArea->setRepeatMode(repeatMode);
}

void LCDDisplay::setSongDuration(size_t songDurationSeconds)
{
    ui->titleArea->setSongDuration(songDurationSeconds);
}

LCDDisplay::~LCDDisplay() {
    delete SevenSegment;
    delete InterFont;
    delete ui;
}

void LCDDisplay::onEqStateChanged(bool activated) {
    ui->propertiesArea->setEqState(activated);
}

void LCDDisplay::onAGCStateChanged(bool activated) {
    ui->propertiesArea->setAGCState(activated);
}

void LCDDisplay::onSurroundStateChanged(bool activated) {
    ui->propertiesArea->setSurroundState(activated);
}

void LCDDisplay::onXBassStateChanged(bool activated) {
    ui->propertiesArea->setXBassState(activated);
}

void LCDDisplay::onReverbStateChanged(bool activated) {
    ui->propertiesArea->setReverbState(activated);
}

void LCDDisplay::onRepeatModeChanged(ModPlugPlayer::RepeatMode repeatMode) {
    ui->propertiesArea->setRepeatMode(repeatMode);
}

void LCDDisplay::onInterpolationModeChanged(ModPlugPlayer::InterpolationMode interpolationMode) {
    ui->propertiesArea->setInterpolationMode(interpolationMode);
}

void LCDDisplay::refreshStyleSheet() {
    QString backgroundStyle = QString("background-color:%1;").arg(backgroundColor.hex().c_str());
    QString textStyle = QString("color:%1;").arg(textColor.hex().c_str());
    QString style = QString("background-color:%1; color:%2;").arg(backgroundColor.hex().c_str(), textColor.hex().c_str());
    setStyleSheet(style);
}
