/*
PropertiesArea class declarations of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <APIStructures.hpp>
using namespace ModPlugPlayer;

namespace Ui {
class PropertiesArea;
}

class PropertiesArea : public QWidget
{
    Q_OBJECT

public:
    explicit PropertiesArea(QWidget *parent = nullptr);
    void setRepeatMode(const RepeatMode repeatMode);
    void setEqState(const bool enabled);
    void setDSPState(const bool enabled);
    void setAmigaFilter(const AmigaFilter amigaFilter);
    void setInterpolationFilter(const InterpolationFilter interpolationFilter);
    void setSoundResolution(const SoundResolution soundResolution);
    void setChannelAmount(const size_t channelAmount);
    void setActiveChannelAmount(const size_t activeChannelAmount);
    void setChannelMode(const ChannelMode channelMode);
    void setSampleRate(const SampleRate sampleRate);
    void setBitRate(const BitRate bitRate);
    void setModuleFormat(const QString moduleFormat);
    ~PropertiesArea();

private:
    Ui::PropertiesArea *ui;
    void onRepeatDoubleClicked();
    void onEqDoubleClicked();
    void onDSPDoubleClicked();
    void onAmigaFilterDoubleClicked();
    void onInterpolationFilterDoubleClicked();
    bool eqEnabled = false, dspEnabled = false;
    size_t activeChannelAmountDigit1PreviousValue = 0, activeChannelAmountDigit2PreviousValue = 0;
    RepeatMode repeatMode = RepeatMode::NoRepeat;
    InterpolationFilter interpolationFilter = InterpolationFilter::NoInterpolation;
    AmigaFilter amigaFilter = AmigaFilter::Amiga500;
    QFont *SevenSegment;
    QFont *InterFont;
};
