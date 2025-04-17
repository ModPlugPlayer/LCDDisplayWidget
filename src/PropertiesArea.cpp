/*
PropertiesArea class definitions of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "PropertiesArea.hpp"
#include "ui_PropertiesArea.h"
#include <MessageCenter.hpp>

PropertiesArea::PropertiesArea(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PropertiesArea) {
    ui->setupUi(this);

    SevenSegment = new QFont("Seven Segment", QFont::Normal);
    SevenSegment->setPixelSize(11);
    InterFont = new QFont("Inter", QFont::Normal);
    InterFont->setPixelSize(10);

    ui->activeChannelAmountDigit1->setFont(*SevenSegment);
    ui->activeChannelAmountDigit2->setFont(*SevenSegment);
    ui->channelAmountDigit1->setFont(*SevenSegment);
    ui->channelAmountDigit2->setFont(*SevenSegment);
    ui->sampleRate->setFont(*SevenSegment);
    ui->bitRate->setFont(*SevenSegment);

    ui->repeatMode->setFont(*InterFont);
    ui->channelMode->setFont(*InterFont);
    ui->interpolationFilter->setFont(*InterFont);
    ui->amigaFilter->setFont(*InterFont);
    ui->chn->setFont(*InterFont);
    ui->eqState->setFont(*InterFont);
    ui->kHz->setFont(*InterFont);
    ui->moduleFormat->setFont(*InterFont);
    ui->slash->setFont(*InterFont);
    ui->bit->setFont(*InterFont);
    ui->dspState->setFont(*InterFont);
    ui->repeatMode->setFont(*InterFont);
    connect(ui->repeatMode, &ClickableLabel::doubleClicked, this, &PropertiesArea::onRepeatDoubleClicked);
    connect(ui->eqState, &ClickableLabel::doubleClicked, this, &PropertiesArea::onEqDoubleClicked);
    connect(ui->dspState, &ClickableLabel::doubleClicked, this, &PropertiesArea::onDSPDoubleClicked);
    connect(ui->amigaFilter, &ClickableLabel::doubleClicked, this, &PropertiesArea::onAmigaFilterDoubleClicked);
    connect(ui->interpolationFilter, &ClickableLabel::doubleClicked, this, &PropertiesArea::onInterpolationFilterDoubleClicked);
}

void PropertiesArea::setRepeatMode(const RepeatMode repeatMode) {
    this->repeatMode = repeatMode;
    switch(repeatMode) {
    case RepeatMode::NoRepeat:
        ui->repeatMode->setText("");
    break;
    case RepeatMode::RepeatSong:
        ui->repeatMode->setText("Repeat");
    break;
    case RepeatMode::LoopSong:
        ui->repeatMode->setText("Loop");
        break;
    case RepeatMode::RepeatPlayList:
        ui->repeatMode->setText("Rpt Lst");
    break;
    }
}

void PropertiesArea::setEqState(const bool enabled) {
    eqEnabled = enabled;
    if(enabled) {
        ui->eqState->setText("EQ");
    }
    else {
        ui->eqState->setText("");
    }
}


void PropertiesArea::setDSPState(const bool enabled) {
    dspEnabled = enabled;
    if(enabled)
        ui->dspState->setText("DSP");
    else
        ui->dspState->setText("");
}

void PropertiesArea::setAmigaFilter(const AmigaFilter amigaFilter) {
    this->amigaFilter = amigaFilter;
    switch(amigaFilter) {
        case AmigaFilter::Unfiltered:
            ui->amigaFilter->setText("Unfiltered");
            break;
        case AmigaFilter::Amiga500:
            ui->amigaFilter->setText("Amiga 500");
            break;
        case AmigaFilter::Amiga1200:
            ui->amigaFilter->setText("Amiga 1200");
            break;
        case AmigaFilter::DisablePaulaEmulation:
            ui->amigaFilter->setText("");
            break;
        case AmigaFilter::Auto:
            ui->amigaFilter->setText("Auto Amiga");
            break;
    }
}

void PropertiesArea::setInterpolationFilter(const InterpolationFilter interpolationFilter) {
    this->interpolationFilter = interpolationFilter;
    switch(interpolationFilter) {
        case InterpolationFilter::Internal:
            ui->interpolationFilter->setText("Default");
            break;
        case InterpolationFilter::NoInterpolation:
            ui->interpolationFilter->setText("");
            break;
        case InterpolationFilter::LinearInterpolation:
            ui->interpolationFilter->setText("Linear");
            break;
        case InterpolationFilter::CubicInterpolation:
            ui->interpolationFilter->setText("Cubic");
            break;
        case InterpolationFilter::WindowedSincWith8Taps:
            ui->interpolationFilter->setText("Sinc");
            break;
    }
}

void PropertiesArea::setSoundResolution(const SoundResolution soundResolution) {
    setSamplingFrequency(soundResolution.sampleRate);
    setBitDepth(soundResolution.bitDepth);
    setChannelMode(soundResolution.channelMode);
}

void PropertiesArea::setChannelAmount(const size_t channelAmount) {
    ui->channelAmountDigit1->setText(QString::number(channelAmount%10));
    ui->channelAmountDigit2->setText(QString::number(channelAmount/10));
}

void PropertiesArea::setActiveChannelAmount(const size_t activeChannelAmount)
{
    size_t activeChannelAmountDigit1 = activeChannelAmount%10;
    size_t activeChannelAmountDigit2 = activeChannelAmount/10;
    if(activeChannelAmountDigit1 != activeChannelAmountDigit1PreviousValue) {
        activeChannelAmountDigit1PreviousValue = activeChannelAmountDigit1;
        ui->activeChannelAmountDigit1->setText(QString::number(activeChannelAmountDigit1));
    }
    if(activeChannelAmountDigit2 != activeChannelAmountDigit2PreviousValue) {
        activeChannelAmountDigit2PreviousValue = activeChannelAmountDigit2;
        ui->activeChannelAmountDigit2->setText(QString::number(activeChannelAmountDigit2));
    }
}

void PropertiesArea::setChannelMode(const ChannelMode channelMode)
{
    QString channelModeString;
    switch (channelMode) {
    case ChannelMode::Mono:
        channelModeString = "Mono";
        break;
    case ChannelMode::Stereo:
        channelModeString = "Stereo";
        break;
    case ChannelMode::Quadraphonic:
        channelModeString = "Quad";
        break;
    case ChannelMode::Pentaphonic:
        channelModeString = "Penta";
        break;
    case ChannelMode::Surround_5_1:
        channelModeString = "5.1";
        break;
    case ChannelMode::Surround_7_1:
        channelModeString = "7.1";
        break;
    }
    ui->channelMode->setText(channelModeString);
}

void PropertiesArea::setSamplingFrequency(const SamplingFrequency samplingFrequency) {
    QString samplingFrequencyString;
    switch (samplingFrequency) {
    case SamplingFrequency::Hz8000:
        samplingFrequencyString = "08";
        break;
    case SamplingFrequency::Hz9600:
        samplingFrequencyString = "09";
        break;
    case SamplingFrequency::Hz11025:
        samplingFrequencyString = "11";
        break;
    case SamplingFrequency::Hz12000:
        samplingFrequencyString = "12";
        break;
    case SamplingFrequency::Hz16000:
        samplingFrequencyString = "16";
        break;
    case SamplingFrequency::Hz22050:
        samplingFrequencyString = "22";
        break;
    case SamplingFrequency::Hz24000:
        samplingFrequencyString = "24";
        break;
    case SamplingFrequency::Hz32000:
        samplingFrequencyString = "32";
        break;
    case SamplingFrequency::Hz44100:
        samplingFrequencyString = "44";
        break;
    case SamplingFrequency::Hz48000:
        samplingFrequencyString = "48";
        break;
    case SamplingFrequency::Hz88200:
        samplingFrequencyString = "88";
        break;
    case SamplingFrequency::Hz96000:
        samplingFrequencyString = "96";
        break;
    case SamplingFrequency::Hz192000:
        samplingFrequencyString = "192";
        break;
    }
    ui->sampleRate->setText(samplingFrequencyString);
}

void PropertiesArea::setBitDepth(const BitDepth bitDepth) {
    QString bitRateString;
    switch(bitDepth) {
    case BitDepth::Bits8:
        bitRateString = "8";
        break;
    case BitDepth::Bits16:
        bitRateString = "16";
        break;
    case BitDepth::Bits24:
        bitRateString = "24";
        break;
    case BitDepth::Bits32:
        bitRateString = "32";
        break;
    }
    ui->bitRate->setText(bitRateString);
}

void PropertiesArea::setModuleFormat(const QString moduleFormat) {
    ui->moduleFormat->setText(moduleFormat);
}

PropertiesArea::~PropertiesArea() {
    delete SevenSegment;
    delete InterFont;
    delete ui;
}

void PropertiesArea::onRepeatDoubleClicked()
{
    RepeatMode currentRepeatMode = this->repeatMode;
    emit MessageCenter::getInstance().requests.songRequests.repeatModeChangeRequested(currentRepeatMode++);
}

void PropertiesArea::onEqDoubleClicked() {
    emit MessageCenter::getInstance().requests.soundRequests.eqStateChangeRequested(!eqEnabled);
}

void PropertiesArea::onDSPDoubleClicked() {
    emit MessageCenter::getInstance().requests.soundRequests.dspStateChangeRequested(!dspEnabled);
}

void PropertiesArea::onAmigaFilterDoubleClicked() {
    AmigaFilter currentAmigaFilter = amigaFilter;
    emit MessageCenter::getInstance().requests.moduleRequests.amigaFilterChangeRequested(currentAmigaFilter++);
}

void PropertiesArea::onInterpolationFilterDoubleClicked() {
    InterpolationFilter currentInterpolationFilter = this->interpolationFilter;
    emit MessageCenter::getInstance().requests.moduleRequests.interpolationFilterChangeRequested(currentInterpolationFilter++);
}
