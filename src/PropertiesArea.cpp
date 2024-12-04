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
        ui->repeatMode->setText("Rpt PList");
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
            ui->amigaFilter->setText("Non Amiga");
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
            ui->amigaFilter->setText("No Int.");
            break;
        case InterpolationFilter::LinearInterpolation:
            ui->amigaFilter->setText("Linear");
            break;
        case InterpolationFilter::CubicInterpolation:
            ui->amigaFilter->setText("Cubic");
            break;
        case InterpolationFilter::WindowedSincWith8Taps:
            ui->amigaFilter->setText("Sinc");
            break;
    }
}

PropertiesArea::~PropertiesArea() {
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
