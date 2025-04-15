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
#include <MessageCenter.hpp>

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
    connectSignalsAndSlots();
}

void LCDDisplay::connectSignalsAndSlots() {
    connect(&MessageCenter::getInstance().events.songEvents, &MessageCenterEvents::SongEvents::songTitleChanged, this, &LCDDisplay::onSongTitleChanged);
    connect(&MessageCenter::getInstance().events.songEvents, &MessageCenterEvents::SongEvents::elapsedTimeChanged, this, &LCDDisplay::onElapsedTimeChanged);
    connect(&MessageCenter::getInstance().events.songEvents, &MessageCenterEvents::SongEvents::repeatModeChanged, this, &LCDDisplay::onRepeatModeChanged);
    connect(&MessageCenter::getInstance().events.songEvents, &MessageCenterEvents::SongEvents::songDurationChanged, this, &LCDDisplay::onSongDurationChanged);
    connect(&MessageCenter::getInstance().events.moduleEvents, &MessageCenterEvents::ModuleEvents::activeChannelAmountChanged, this, &LCDDisplay::onActiveChannelAmountChanged);
    connect(&MessageCenter::getInstance().events.moduleEvents, &MessageCenterEvents::ModuleEvents::currentSubSongIndexChanged, this, &LCDDisplay::onCurrentSubSongIndexChanged);
    connect(&MessageCenter::getInstance().events.moduleEvents, &MessageCenterEvents::ModuleEvents::subSongAmountChanged, this, &LCDDisplay::onSubSongAmountChanged);
    connect(&MessageCenter::getInstance().events.moduleEvents, &MessageCenterEvents::ModuleEvents::moduleFormatChanged, this, &LCDDisplay::onModuleFormatChanged);
    connect(&MessageCenter::getInstance().events.soundEvents, &MessageCenterEvents::SoundEvents::soundResolutionChanged, this, &LCDDisplay::onSoundResolutionChanged);
    connect(&MessageCenter::getInstance().events.moduleEvents, &MessageCenterEvents::ModuleEvents::currentPatternIndexChanged, this, &LCDDisplay::onCurrentPatternIndexChanged);
    connect(&MessageCenter::getInstance().events.moduleEvents, &MessageCenterEvents::ModuleEvents::patternAmountChanged, this, &LCDDisplay::onPatternAmountChanged);
    connect(&MessageCenter::getInstance().events.moduleEvents, &MessageCenterEvents::ModuleEvents::channelAmountChanged, this, &LCDDisplay::onChannelAmountChanged);
    connect(&MessageCenter::getInstance().events.soundEvents, &MessageCenterEvents::SoundEvents::eqStateChanged, this, &LCDDisplay::onEqStateChanged);
    connect(&MessageCenter::getInstance().events.soundEvents, &MessageCenterEvents::SoundEvents::dspStateChanged, this, &LCDDisplay::onDSPStateChanged);
    connect(&MessageCenter::getInstance().events.moduleEvents, &MessageCenterEvents::ModuleEvents::amigaFilterChanged, this, &LCDDisplay::onAmigaFilterChanged);
    connect(&MessageCenter::getInstance().events.moduleEvents, &MessageCenterEvents::ModuleEvents::interpolationFilterChanged, this, &LCDDisplay::onInterpolationFilterChanged);
}

void LCDDisplay::onElapsedTimeChanged(const size_t elapsedTimeSeconds) {
    ui->timeArea->updateTime(elapsedTimeSeconds);
}

void LCDDisplay::onSongTitleChanged(const std::string songTitle) {
    ui->titleArea->setTitle(QString::fromStdString(songTitle));
}

void LCDDisplay::onRepeatModeChanged(const RepeatMode repeatMode) {
    ui->propertiesArea->setRepeatMode(repeatMode);
}

void LCDDisplay::onSongDurationChanged(const size_t songDurationSeconds) {
    ui->songInformationArea->setSongDuration(songDurationSeconds);
}

void LCDDisplay::onActiveChannelAmountChanged(const size_t activeChannelAmount) {
    ui->propertiesArea->setActiveChannelAmount(activeChannelAmount);
}

void LCDDisplay::onCurrentSubSongIndexChanged(const size_t currentSubSongIndex) {
    ui->songInformationArea->setCurrentSubSongIndex(currentSubSongIndex);
}

void LCDDisplay::onSubSongAmountChanged(const size_t subSongAmount) {
    ui->songInformationArea->setSubSongAmount(subSongAmount);
}

void LCDDisplay::onModuleFormatChanged(const std::string moduleFormat) {
    ui->propertiesArea->setModuleFormat(QString::fromStdString(moduleFormat));
}

void LCDDisplay::onSoundResolutionChanged(const SoundResolution soundResolution) {
    ui->propertiesArea->setSoundResolution(soundResolution);
}

void LCDDisplay::onCurrentPatternIndexChanged(const size_t currentPatternIndex) {
    ui->songInformationArea->setCurrentPatternIndex(currentPatternIndex);
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
