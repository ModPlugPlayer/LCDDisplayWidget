/*
ControlWindow class declarations of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <QDialog>
#include <Player.hpp>

namespace Ui {
class ControlWindow;
}

using namespace ModPlugPlayer;

class ControlWindow : public QDialog, public ModPlugPlayer::Player
{
    Q_OBJECT

public:
    explicit ControlWindow(QWidget *parent = nullptr);
    ~ControlWindow();
    int getVolume() const override;
    bool isAlwaysOnTop() const override;
    bool isTitleBarHidden() const override;
    bool isSnapToViewPort() const override;
    bool isKeptStayingInViewPort() const override;

signals:
    //Request Signals
    void openRequested(const std::filesystem::path filePath) override;
    void openRequested(const PlayListItem playListItem) override;
    void stopRequested() override;
    void stopRequested(const PlayListItem playListItem) override;
    void playRequested() override;
    void playRequested(const PlayListItem playListItem) override;
    void pauseRequested() override;
    void pauseRequested(const PlayListItem playListItem) override;
    void resumeRequested() override;
    void resumeRequested(const PlayListItem playListItem) override;
    void previousRequested() override;
    void nextRequested() override;
    void volumeChangeRequested(const int volume) override;
    void timeScrubbingRequested(const int position) override;
    void repeatModeChangeRequested(const ModPlugPlayer::RepeatMode repeatMode) override;
    void agcStateChangeRequested(const bool activated) override;
    void xBassStateChangeRequested(const bool activated) override;
    void surroundStateChangeRequested(const bool activated) override;
    void reverbStateChangeRequested(const bool activated) override;
    void interpolationModeChangeRequested(const ModPlugPlayer::InterpolationMode interpolationMode) override;
    void eqStateChangeRequested(const bool activated) override;
    void alwaysOnTopStateChangeRequested(const bool alwaysOnTop) override;
    void titleBarHidingStateChangeRequested(const bool hide) override;
    void snapingToViewPortStateChangeRequested(const bool toBeSnappedToViewPort) override;
    void keepingStayingInViewPortStateChangeRequested(const bool toBeKeptStayingInViewPort) override;

    //Response Signals
    void loaded(const std::filesystem::path filePath, bool successfull) override;
    void loaded(const PlayListItem playListItem, bool successfull) override;
    void stopped() override;
    void stopped(const PlayListItem playListItem) override;
    void playingStarted() override;
    void playingStarted(const PlayListItem playListItem) override;
    void paused() override;
    void paused(const PlayListItem playListItem) override;
    void resumed() override;
    void resumed(const PlayListItem playListItem) override;
    void previous() override;
    void next() override;
    void volumeChanged(const int volume) override;
    void timeScrubbed(const int position) override;
    void repeatModeChanged(const ModPlugPlayer::RepeatMode repeat) override;
    void eqStateChanged(const bool activated) override;
    void agcStateChanged(const bool activated) override;
    void xBassStateChanged(const bool activated) override;
    void surroundStateChanged(const bool activated) override;
    void reverbStateChanged(const bool activated) override;
    void interpolationModeChanged(const ModPlugPlayer::InterpolationMode interpolationMode) override;
    void alwaysOnTopStateChanged(const bool alwaysOnTop) override;
    void titleBarHidingStateChanged(const bool hide) override;
    void snappingToViewPortStateChanged(const bool snapToViewPort) override;
    void keepingStayingInViewPortStateChanged(const bool toBeKeptStayingInViewPort) override;

public slots:
    // Request Signal Handlers
    void onLoaded(std::filesystem::path filePath, bool successfull) override;
    void onLoaded(PlayListItem playListItem, bool successfull) override;
    void onStopRequested() override;
    void onStopRequested(PlayListItem playListItem) override;
    void onPlayRequested() override;
    void onPlayRequested(PlayListItem playListItem) override;
    void onPauseRequested() override;
    void onPauseRequested(PlayListItem playListItem) override;
    void onResumeRequested() override;
    void onResumeRequested(PlayListItem playListItem) override;
    void onVolumeChangeRequested(int volume) override;
    void onTimeScrubbingRequested(int position) override;
    void onAlwaysOnTopStateChangeRequested(bool alwaysOnTop) override;
    void onTitleBarHidingStateChangeRequested(bool hide) override;
    void onSnappingToViewPortStateChangeRequested(bool snapToViewPort) override;
    void onSnappingThresholdChangeRequested(int snappingThreshold) override;
    void onKeepingStayingInViewPortStateChangeRequested(bool keepStayingInViewPort) override;
    void onPreviousRequested() override;
    void onNextRequested() override;
    void onRepeatModeChangeRequested(ModPlugPlayer::RepeatMode repeatMode) override;
    void onEqStateChangeRequested(const bool activated) override;
    void onAGCStateChangeRequested(const bool activated) override;
    void onXBassStateChangeRequested(const bool activated) override;
    void onSurroundStateChangeRequested(const bool activated) override;
    void onReverbStateChangeRequested(const bool activated) override;
    void onInterpolationModeChangeRequested(const ModPlugPlayer::InterpolationMode interpolationMode) override;

private slots:
    void on_previousButton_clicked();
    void on_nextButton_clicked();
    void on_playButton_clicked();
    void on_pauseButton_clicked();
    void on_stopButton_clicked();
    void on_repeatButton_clicked();
    void on_playlistButton_clicked();
    void onPlayListEditorIsHidden();
    void on_openButton_clicked();

private:
    Ui::ControlWindow *ui;
    RepeatMode repeatMode = RepeatMode::None;
    InterpolationMode interpolationMode = InterpolationMode::NoInterpolation;
    bool eqState = false, agcState = false, xBassState = false, surroundState = false, reverbState = false;
    PlayingStatus playingStatus = PlayingStatus::Stopped;
    void changeRepeatMode(ModPlugPlayer::RepeatMode repeatMode);
    PlayingMode playingMode = PlayingMode::SingleTrack;
    void setRepeatMode(RepeatMode repeatMode);
};

