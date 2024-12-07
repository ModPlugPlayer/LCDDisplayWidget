/*
LCDDisplay class declarations of ModPlug Player
Copyright (C) 2020 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <QWidget>
#include "TextColorProperties.hpp"
#include <APIStructures.hpp>

using namespace ModPlugPlayer;

namespace Ui {
class LCDDisplay;
}

class LCDDisplay : public QWidget, public TextColorProperties
{
    Q_OBJECT

public:
    explicit LCDDisplay(QWidget *parent = nullptr);
    ~LCDDisplay();

signals:
    void repeatModeChangeRequested(const RepeatMode repeatMode);
    void eqStateChangeRequested(const bool activated);
    void dspStateChangeRequested(const bool activated);
    void amigaFilterChangeRequested(const AmigaFilter amigaFilter);
    void interpolationFilterChangeRequested(const InterpolationFilter interpolationFilter);

public slots:
    void onRepeatModeChanged(const RepeatMode repeatMode);
    void onEqStateChanged(const bool activated);
    void onDSPStateChanged(const bool activated);
    void onAmigaFilterChanged(const AmigaFilter amigaFilter);
    void onInterpolationFilterChanged(const InterpolationFilter interpolationFilter);
    void onElapsedTimeChanged(const size_t elapsedTimeSeconds);
    void onTrackTitleChanged(const QString songTitle);
    void onTrackDurationChanged(const size_t songDurationSeconds);
    void onActiveChannelAmountChanged(const size_t activeChannelAmount);
    void onCurrentSubSongChanged(const size_t currentSubSong);
    void onSubSongAmountChanged(const size_t subSongAmount);
    void onModuleFormatChanged(const QString moduleFormat);
    void onSoundResolutionChanged(const int frequency,const int bitRate, const ChannelMode channelMode);
    void onSongDurationChanged(const size_t songDurationSeconds);
    void onCurrentPatternChanged(const size_t currentPattern);
    void onPatternAmountChanged(const size_t patternAmount);
    void onChannelAmountChanged(const size_t channelAmount);

private:
    Ui::LCDDisplay *ui;
    QFont *SevenSegment;
    QFont *InterFont;

protected:
    void refreshStyleSheet() override;
};
