/*
ControlWindow function definition for the test purposes of LCDDisplayWidget
Copyright (C) 2024 Volkan Orhan

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include "ControlWindow.hpp"
#include "ui_ControlWindow.h"
#include <Interfaces/PlayList.hpp>

ControlWindow::ControlWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlWindow) {
    ui->setupUi(this);
    QObject::connect(this, &ControlWindow::repeatModeChangeRequested, this, &ControlWindow::onRepeatModeChangeRequested);
    QObject::connect(this, qOverload<>(&ControlWindow::playRequested), this, qOverload<>(&ControlWindow::onPlayRequested));
    QObject::connect(this, qOverload<>(&ControlWindow::pauseRequested), this, qOverload<>(&ControlWindow::onPauseRequested));
    QObject::connect(this, qOverload<>(&ControlWindow::resumeRequested), this, qOverload<>(&ControlWindow::onResumeRequested));
    QObject::connect(this, qOverload<>(&ControlWindow::stopRequested), this, qOverload<>(&ControlWindow::onStopRequested));
    QObject::connect(this, &ControlWindow::previousRequested, this, &ControlWindow::onPreviousRequested);
    QObject::connect(this, &ControlWindow::nextRequested, this, &ControlWindow::onNextRequested);

    connect(this, &ControlWindow::repeatModeChanged, ui->display, &LCDDisplay::onRepeatModeChanged);
    connect(this, &ControlWindow::eqStateChanged, ui->display, &LCDDisplay::onEqStateChanged);
    connect(this, &ControlWindow::dspStateChanged, ui->display, &LCDDisplay::onDSPStateChanged);
    connect(this, &ControlWindow::interpolationFilterChanged, ui->display, &LCDDisplay::onInterpolationFilterChanged);

    connect(ui->display, &LCDDisplay::repeatModeChangeRequested, this, &ControlWindow::repeatModeChangeRequested);
    connect(ui->display, &LCDDisplay::eqStateChangeRequested, this, &ControlWindow::onEqStateChangeRequested);
    connect(ui->display, &LCDDisplay::dspStateChangeRequested, this, &ControlWindow::onDSPStateChangeRequested);
    connect(ui->display, &LCDDisplay::interpolationFilterChangeRequested, this, &ControlWindow::onInterpolationFilterChangeRequested);
    ui->playlistButton->click();
}

ControlWindow::~ControlWindow() {
    delete ui;
}

int ControlWindow::getVolume() const {
    return 0;
}

bool ControlWindow::isAlwaysOnTop() const {
    return false;
}

bool ControlWindow::isTitleBarHidden() const {
    return false;
}

bool ControlWindow::isSnapToViewPort() const {
    return false;
}

bool ControlWindow::isKeptStayingInViewPort() const {
    return false;
}

void ControlWindow::onOpenRequested(const std::filesystem::path filePath) {

}

void ControlWindow::onOpenRequested(const PlayListItem playListItem) {

}

void ControlWindow::onLoaded(std::filesystem::path filePath, bool successfull) {
    playingMode = PlayingMode::SingleTrack;
}

void ControlWindow::onLoaded(const ModuleFileInfo fileInfo, const bool successfull)
{

}

void ControlWindow::onLoaded(PlayListItem playListItem, bool successfull) {
    playingMode = PlayingMode::PlayList;
    emit trackTitleChanged(playListItem.filePath.filename().c_str());
    emit loaded(playListItem, successfull);
}

void ControlWindow::onStopRequested() {
    playingStatus = PlayingStatus::Stopped;
    ui->stopButton->setStyleSheet("color: green;");
    ui->pauseButton->setStyleSheet("color: blue;");
    ui->playButton->setStyleSheet("color: blue;");
}

void ControlWindow::onStopRequested(const PlayListItem playListItem) {
    playingStatus = PlayingStatus::Stopped;
    ui->stopButton->setStyleSheet("color: green;");
    ui->pauseButton->setStyleSheet("color: blue;");
    ui->playButton->setStyleSheet("color: blue;");
}

void ControlWindow::onPlayRequested() {
    playingStatus = PlayingStatus::Playing;
    ui->stopButton->setStyleSheet("color: blue;");
    ui->pauseButton->setStyleSheet("color: blue;");
    ui->playButton->setStyleSheet("color: green;");
}

void ControlWindow::onPlayRequested(const PlayListItem playListItem) {
    playingStatus = PlayingStatus::Playing;
    ui->stopButton->setStyleSheet("color: blue;");
    ui->pauseButton->setStyleSheet("color: blue;");
    ui->playButton->setStyleSheet("color: green;");
}

void ControlWindow::onPauseRequested() {
    playingStatus = PlayingStatus::Paused;
    ui->stopButton->setStyleSheet("color: blue;");
    ui->pauseButton->setStyleSheet("color: green;");
    ui->playButton->setStyleSheet("color: blue;");
}

void ControlWindow::onPauseRequested(const PlayListItem playListItem) {
    playingStatus = PlayingStatus::Paused;
    ui->stopButton->setStyleSheet("color: blue;");
    ui->pauseButton->setStyleSheet("color: green;");
    ui->playButton->setStyleSheet("color: blue;");
}

void ControlWindow::onResumeRequested() {
    playingStatus = PlayingStatus::Playing;
    ui->stopButton->setStyleSheet("color: blue;");
    ui->pauseButton->setStyleSheet("color: blue;");
    ui->playButton->setStyleSheet("color: green;");
}

void ControlWindow::onResumeRequested(const PlayListItem playListItem) {
    playingStatus = PlayingStatus::Playing;
    ui->stopButton->setStyleSheet("color: blue;");
    ui->pauseButton->setStyleSheet("color: blue;");
    ui->playButton->setStyleSheet("color: green;");
}

void ControlWindow::onPreviousRequested() {
}

void ControlWindow::onNextRequested() {
}

void ControlWindow::onVolumeChangeRequested(int volume) {

}

void ControlWindow::onTimeScrubbingRequested(int position) {

}

void ControlWindow::onRepeatModeChangeRequested(RepeatMode repeatMode) {
    this->repeatMode = repeatMode;
    emit repeatModeChanged(repeatMode);
}

void ControlWindow::onEqStateChangeRequested(const bool activated) {
    eqEnabled = activated;
    emit eqStateChanged(activated);
}

void ControlWindow::onDSPStateChangeRequested(const bool activated) {
    dspEnabled = activated;
    emit dspStateChanged(activated);
}

void ControlWindow::onAmigaFilterChangeRequested(const AmigaFilter amigaFilter) {

}

void ControlWindow::onInterpolationFilterChangeRequested(const InterpolationFilter interpolationFilter) {
    this->interpolationFilter = interpolationFilter;
    emit interpolationFilterChanged(interpolationFilter);
}

void ControlWindow::onRepeatModeChanged(const RepeatMode repeatMode) {

}

void ControlWindow::onAlwaysOnTopStateChangeRequested(bool alwaysOnTop) {

}

void ControlWindow::onTitleBarHidingStateChangeRequested(bool hide) {

}

void ControlWindow::onSnappingToViewPortStateChangeRequested(bool snapToViewPort) {

}

void ControlWindow::onKeepingStayingInViewPortStateChangeRequested(bool keepStayingInViewPort) {

}

void ControlWindow::onSnappingThresholdChangeRequested(int snappingThreshold) {

}

void ControlWindow::on_previousButton_clicked() {
    emit previousRequested();
}

void ControlWindow::on_nextButton_clicked() {
    emit nextRequested();
}

void ControlWindow::on_playButton_clicked() {
    emit playingStarted();
}

void ControlWindow::on_pauseButton_clicked() {
    if(playingStatus == PlayingStatus::Playing)
        emit paused();
    else if(playingStatus == PlayingStatus::Paused)
        emit resumed();
}

void ControlWindow::on_stopButton_clicked() {
    emit stopped();
}

void ControlWindow::on_repeatButton_clicked() {
    RepeatMode repeat = repeatMode;

    emit repeatModeChangeRequested(repeat++);
}

void ControlWindow::on_playlistButton_clicked() {
}

void ControlWindow::onPlayListEditorIsHidden() {
    ui->playlistButton->setStyleSheet("color: blue;");
}

void ControlWindow::on_openButton_clicked() {

}
