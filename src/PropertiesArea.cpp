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
    connect(ui->agcState, &ClickableLabel::doubleClicked, this, &PropertiesArea::onAGCDoubleClicked);
    connect(ui->xBassState, &ClickableLabel::doubleClicked, this, &PropertiesArea::onXBassDoubleClicked);
    connect(ui->surroundState, &ClickableLabel::doubleClicked, this, &PropertiesArea::onSurroundDoubleClicked);
    connect(ui->reverbState, &ClickableLabel::doubleClicked, this, &PropertiesArea::onReverbDoubleClicked);
    connect(ui->interpolationFilter, &ClickableLabel::doubleClicked, this, &PropertiesArea::onInterpolationFilterDoubleClicked);
}

void PropertiesArea::setRepeatMode(RepeatMode repeatMode) {
    this->repeatMode = repeatMode;
    switch(repeatMode) {
    case RepeatMode::None:
        ui->repeatMode->setText("");
    break;
    case RepeatMode::SingleTrack:
        ui->repeatMode->setText("Repeat Track");
    break;
    case RepeatMode::PlayList:
        ui->repeatMode->setText("Repeat PlayList");
    break;
    }
}

void PropertiesArea::setEqState(bool enabled) {
    eqEnabled = enabled;
    if(enabled) {
        ui->eqState->setText("EQ");
    }
    else {
        ui->eqState->setText("");
    }
}

void PropertiesArea::setAGCState(bool enabled) {
    agcEnabled = enabled;
    if(enabled)
        ui->agcState->setText("AGC");
    else
        ui->agcState->setText("");
}

void PropertiesArea::setXBassState(bool enabled) {
    xBassEnabled = enabled;
    if(enabled)
        ui->xBassState->setText("XBass");
    else
        ui->xBassState->setText("");
}

void PropertiesArea::setSurroundState(bool enabled) {
    surroundEnabled = enabled;
    if(enabled)
        ui->surroundState->setText("Surround");
    else
        ui->surroundState->setText("");
}

void PropertiesArea::setReverbState(bool enabled) {
    reverbEnabled = enabled;
    if(enabled)
        ui->reverbState->setText("Reverb");
    else
        ui->reverbState->setText("");
}

void PropertiesArea::setInterpolationFilter(InterpolationFilter interpolationFilter) {
    this->interpolationFilter = interpolationFilter;
    switch(interpolationFilter) {
        case InterpolationFilter::Internal:
            ui->interpolationFilter->setText("Int");
            break;
        case InterpolationFilter::NoInterpolation:
            ui->interpolationFilter->setText("No Int");
            break;
        case InterpolationFilter::LinearInterpolation:
            ui->interpolationFilter->setText("Linear");
            break;
        case InterpolationFilter::CubicInterpolation:
            ui->interpolationFilter->setText("Cubic");
            break;
        case InterpolationFilter::WindowedSincWith8Taps:
            ui->interpolationFilter->setText("HQ");
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

void PropertiesArea::onAGCDoubleClicked() {
    emit agcStateChangeRequested(!agcEnabled);
}

void PropertiesArea::onXBassDoubleClicked() {
    emit xBassStateChangeRequested(!xBassEnabled);
}

void PropertiesArea::onSurroundDoubleClicked() {
    emit surroundStateChangeRequested(!surroundEnabled);
}

void PropertiesArea::onReverbDoubleClicked() {
    emit reverbStateChangeRequested(!reverbEnabled);
}

void PropertiesArea::onInterpolationFilterDoubleClicked() {
    InterpolationFilter currentInterpolationFilter = this->interpolationFilter;
    emit interpolationFilterChangeRequested(currentInterpolationFilter++);
}
