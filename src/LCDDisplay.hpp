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
#include <APIStructures.hpp>.hpp>

using namespace ModPlugPlayer;

namespace Ui {
class LCDDisplay;
}

class LCDDisplay : public QWidget, public TextColorProperties
{
    Q_OBJECT

public:
    explicit LCDDisplay(QWidget *parent = nullptr);
    void updateTime(int seconds);
    void setSongTitle(QString songTitle);
    void setRepeatMode(RepeatMode repeatMode);
    void setSongDuration(size_t songDurationSeconds);
    ~LCDDisplay();

signals:
    void eqStateChangeRequested(bool activated);
    void agcStateChangeRequested(bool activated);
    void surroundStateChangeRequested(bool activated);
    void xBassStateChangeRequested(bool activated);
    void reverbStateChangeRequested(bool activated);
    void repeatModeChangeRequested(RepeatMode repeatMode);
    void interpolationFilterChangeRequested(InterpolationFilter interpolationFilter);

public slots:
    void onSurroundStateChanged(bool activated);
    void onEqStateChanged(bool activated);
    void onAGCStateChanged(bool activated);
    void onXBassStateChanged(bool activated);
    void onReverbStateChanged(bool activated);
    void onRepeatModeChanged(RepeatMode repeatMode);
    void onInterpolationFilterChanged(InterpolationFilter interpolationFilter);
private:
    Ui::LCDDisplay *ui;
    QFont *SevenSegment;
    QFont *InterFont;

protected:
    void refreshStyleSheet() override;
};
