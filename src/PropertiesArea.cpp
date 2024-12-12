/*
PropertiesArea class definitions of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "PropertiesArea.hpp"
#include "ui_PropertiesArea.h"

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
    case RepeatMode::RepeatTrack:
        ui->repeatMode->setText("Repeat");
    break;
    case RepeatMode::LoopTrack:
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

void PropertiesArea::setSoundResolution(const SampleRate sampleRate, const BitRate bitRate, const ChannelMode channelMode) {
    setSampleRate(sampleRate);
    setBitRate(bitRate);
    setChannelMode(channelMode);
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

void PropertiesArea::setSampleRate(const SampleRate sampleRate) {
    QString sampleRateString;
    switch (sampleRate) {
    case SampleRate::Hz8000:
        sampleRateString = "08";
        break;
    case SampleRate::Hz9600:
        sampleRateString = "09";
        break;
    case SampleRate::Hz11025:
        sampleRateString = "11";
        break;
    case SampleRate::Hz12000:
        sampleRateString = "12";
        break;
    case SampleRate::Hz16000:
        sampleRateString = "16";
        break;
    case SampleRate::Hz22050:
        sampleRateString = "22";
        break;
    case SampleRate::Hz24000:
        sampleRateString = "24";
        break;
    case SampleRate::Hz32000:
        sampleRateString = "32";
        break;
    case SampleRate::Hz44100:
        sampleRateString = "44";
        break;
    case SampleRate::Hz48000:
        sampleRateString = "48";
        break;
    case SampleRate::Hz88200:
        sampleRateString = "88";
        break;
    case SampleRate::Hz96000:
        sampleRateString = "96";
        break;
    case SampleRate::Hz192000:
        sampleRateString = "192";
        break;
    }
    ui->sampleRate->setText(sampleRateString);
}

void PropertiesArea::setBitRate(const BitRate bitRate) {
    QString bitRateString;
    switch(bitRate) {
    case BitRate::Bits8:
        bitRateString = "8";
        break;
    case BitRate::Bits16:
        bitRateString = "16";
        break;
    case BitRate::Bits24:
        bitRateString = "24";
        break;
    case BitRate::Bits32:
        bitRateString = "32";
        break;
    }
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
    emit repeatModeChangeRequested(currentRepeatMode++);
}

void PropertiesArea::onEqDoubleClicked() {
    emit eqStateChangeRequested(!eqEnabled);
}

void PropertiesArea::onDSPDoubleClicked() {
    emit dspStateChangeRequested(!dspEnabled);
}

void PropertiesArea::onAmigaFilterDoubleClicked() {
    AmigaFilter currentAmigaFilter = amigaFilter;
    emit amigaFilterChangeRequested(currentAmigaFilter++);
}

void PropertiesArea::onInterpolationFilterDoubleClicked() {
    InterpolationFilter currentInterpolationFilter = this->interpolationFilter;
    emit interpolationFilterChangeRequested(currentInterpolationFilter++);
}
