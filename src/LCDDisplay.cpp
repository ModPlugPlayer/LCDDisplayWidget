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
    ui(new Ui::LCDDisplay) {
    ui->setupUi(this);

    #ifdef Q_OS_MACOS
        //Makes this component seem under the transparent titlebar correctly
        setAttribute(Qt::WA_ContentsMarginsRespectsSafeArea, false);
        ui->songInformationArea->setMinimumHeight(ui->songInformationArea->minimumHeight()-1);
        ui->songInformationArea->setMaximumHeight(ui->songInformationArea->maximumHeight()-1);
    #endif

    SevenSegment = new QFont("Seven Segment", QFont::Light);
    SevenSegment->setPixelSize(25);
    InterFont = new QFont("Inter", QFont::Normal);
    InterFont->setPixelSize(20);
    connect(ui->propertiesArea, &PropertiesArea::repeatModeChangeRequested, this, &LCDDisplay::repeatModeChangeRequested);
    connect(ui->propertiesArea, &PropertiesArea::eqStateChangeRequested, this, &LCDDisplay::eqStateChangeRequested);
    connect(ui->propertiesArea, &PropertiesArea::dspStateChangeRequested, this, &LCDDisplay::dspStateChangeRequested);
    connect(ui->propertiesArea, &PropertiesArea::amigaFilterChangeRequested, this, &LCDDisplay::amigaFilterChangeRequested);
    connect(ui->propertiesArea, &PropertiesArea::interpolationFilterChangeRequested, this, &LCDDisplay::interpolationFilterChangeRequested);
}

void LCDDisplay::onElapsedTimeChanged(const size_t elapsedTimeSeconds) {
    ui->timeArea->updateTime(elapsedTimeSeconds);
}

void LCDDisplay::onTrackTitleChanged(const QString trackTitle) {
    ui->titleArea->setTitle(trackTitle);
}

void LCDDisplay::onRepeatModeChanged(const RepeatMode repeatMode) {
    ui->propertiesArea->setRepeatMode(repeatMode);
}

void LCDDisplay::onTrackDurationChanged(const size_t trackDurationSeconds) {
    ui->songInformationArea->setSongDuration(trackDurationSeconds);
}

void LCDDisplay::onActiveChannelAmountChanged(const size_t activeChannelAmount) {
    ui->propertiesArea->setActiveChannelAmount(activeChannelAmount);
}

void LCDDisplay::onCurrentSubSongChanged(const size_t currentSubSong) {
    ui->songInformationArea->setCurrentSubSong(currentSubSong);
}

void LCDDisplay::onSubSongAmountChanged(const size_t subSongAmount) {
    ui->songInformationArea->setSubSongAmount(subSongAmount);
}

void LCDDisplay::onModuleFormatChanged(const QString moduleFormat) {
    ui->propertiesArea->setModuleFormat(moduleFormat);
}

void LCDDisplay::onSoundResolutionChanged(const SampleRate sampleRate, const BitRate bitRate, const ChannelMode channelMode) {
    ui->propertiesArea->setSoundResolution(sampleRate, bitRate, channelMode);
}

void LCDDisplay::onSongDurationChanged(const size_t songDurationSeconds) {
    ui->songInformationArea->setSongDuration(songDurationSeconds);
}

void LCDDisplay::onCurrentPatternChanged(const size_t currentPattern) {
    ui->songInformationArea->setCurrentPattern(currentPattern);
}

void LCDDisplay::onPatternAmountChanged(const size_t patternAmount) {
    ui->songInformationArea->setPatternAmount(patternAmount);
}

void LCDDisplay::onChannelAmountChanged(const size_t channelAmount) {
    ui->propertiesArea->setChannelAmount(channelAmount);
}

void LCDDisplay::onEqStateChanged(const bool activated) {
    ui->propertiesArea->setEqState(activated);
}

void LCDDisplay::onDSPStateChanged(const bool activated) {
    ui->propertiesArea->setDSPState(activated);
}

void LCDDisplay::onAmigaFilterChanged(const AmigaFilter amigaFilter) {
    ui->propertiesArea->setAmigaFilter(amigaFilter);
}

void LCDDisplay::onInterpolationFilterChanged(const InterpolationFilter interpolationFilter) {
    ui->propertiesArea->setInterpolationFilter(interpolationFilter);
}

void LCDDisplay::refreshStyleSheet() {
    QString backgroundStyle = QString("background-color:%1;").arg(backgroundColor.hex().c_str());
    QString textStyle = QString("color:%1;").arg(textColor.hex().c_str());
    QString style = QString("background-color:%1; color:%2;").arg(backgroundColor.hex().c_str(), textColor.hex().c_str());
    setStyleSheet(style);
    ui->titleBorder->setBorderColor(textColor);
}

LCDDisplay::~LCDDisplay() {
    delete SevenSegment;
    delete InterFont;
    delete ui;
}
