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
    connect(ui->interpolationMode, &ClickableLabel::doubleClicked, this, &PropertiesArea::onInterpolationModeDoubleClicked);
}

void PropertiesArea::setRepeatMode(ModPlugPlayer::RepeatMode repeatMode) {
    this->repeatMode = repeatMode;
    switch(repeatMode) {
    case ModPlugPlayer::RepeatMode::None:
        ui->repeatMode->setText("");
    break;
    case ModPlugPlayer::RepeatMode::SingleTrack:
        ui->repeatMode->setText("Repeat Track");
    break;
    case ModPlugPlayer::RepeatMode::PlayList:
        ui->repeatMode->setText("Repeat PlayList");
    break;
    }
}

void PropertiesArea::setEqState(bool enabled) {
    eqState = enabled;
    if(enabled) {
        ui->eqState->setText("EQ");
    }
    else {
        ui->eqState->setText("");
    }
}

void PropertiesArea::setAGCState(bool enabled) {
    agcState = enabled;
    if(enabled)
        ui->eqState->setText("AGC");
    else
        ui->eqState->setText("");
}

void PropertiesArea::setXBassState(bool enabled) {
    xBassState = enabled;
    if(enabled)
        ui->xBassState->setText("XBass");
    else
        ui->xBassState->setText("");
}

void PropertiesArea::setSurroundState(bool enabled) {
    surroundState = enabled;
    if(enabled)
        ui->surroundState->setText("Surround");
    else
        ui->surroundState->setText("");
}

void PropertiesArea::setReverbState(bool enabled) {
    reverbState = enabled;
    if(enabled)
        ui->reverbState->setText("Reverb");
    else
        ui->reverbState->setText("");
}

void PropertiesArea::setInterpolationMode(ModPlugPlayer::InterpolationMode interpolationMode) {
    this->interpolationMode = interpolationMode;
    switch(interpolationMode) {
        case ModPlugPlayer::InterpolationMode::NoInterpolation:
            ui->interpolationMode->setText("No Interpolation");
            break;
        case ModPlugPlayer::InterpolationMode::Linear:
            ui->interpolationMode->setText("Linear");
            break;
        case ModPlugPlayer::InterpolationMode::Cubic:
            ui->interpolationMode->setText("Cubic");
            break;
        case ModPlugPlayer::InterpolationMode::Sinc:
            ui->interpolationMode->setText("HQ");
            break;
        case ModPlugPlayer::InterpolationMode::SincPlusLowPass:
            ui->interpolationMode->setText("HQ+");
            break;
    }
}

PropertiesArea::~PropertiesArea() {
    delete ui;
}

void PropertiesArea::onRepeatDoubleClicked()
{
    ModPlugPlayer::RepeatMode currentRepeatMode = this->repeatMode;
    emit repeatModeChangeRequested(currentRepeatMode++);
}

void PropertiesArea::onEqDoubleClicked() {
    emit eqStateChangeRequested(!eqState);
}

void PropertiesArea::onAGCDoubleClicked() {
    emit agcStateChangeRequested(!agcState);
}

void PropertiesArea::onXBassDoubleClicked() {
    emit xBassStateChangeRequested(!xBassState);
}

void PropertiesArea::onSurroundDoubleClicked() {
    emit surroundStateChangeRequested(!surroundState);
}

void PropertiesArea::onReverbDoubleClicked() {
    emit reverbStateChangeRequested(!reverbState);
}

void PropertiesArea::onInterpolationModeDoubleClicked() {
    ModPlugPlayer::InterpolationMode currentInterpolationMode = this->interpolationMode;
    emit interpolationModeChangeRequested(currentInterpolationMode++);
}
