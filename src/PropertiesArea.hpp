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
    void setRepeatMode(RepeatMode repeatMode);
    void setEqState(bool enabled);
    void setAGCState(bool enabled);
    void setXBassState(bool enabled);
    void setSurroundState(bool enabled);
    void setReverbState(bool enabled);
    void setInterpolationFilter(InterpolationFilter interpolationFilter);
    ~PropertiesArea();

signals:
    void eqStateChangeRequested(bool activated);
    void agcStateChangeRequested(bool activated);
    void surroundStateChangeRequested(bool activated);
    void xBassStateChangeRequested(bool activated);
    void reverbStateChangeRequested(bool activated);
    void repeatModeChangeRequested(RepeatMode repeatMode);
    void interpolationFilterChangeRequested(InterpolationFilter interpolationFilter);

private:
    Ui::PropertiesArea *ui;
    void onRepeatDoubleClicked();
    void onEqDoubleClicked();
    void onAGCDoubleClicked();
    void onXBassDoubleClicked();
    void onSurroundDoubleClicked();
    void onReverbDoubleClicked();
    void onInterpolationFilterDoubleClicked();
    bool eqEnabled = false, agcEnabled = false, xBassEnabled = false, surroundEnabled = false, reverbEnabled = false;
    RepeatMode repeatMode = RepeatMode::None;
    InterpolationFilter interpolationFilter = InterpolationFilter::NoInterpolation;
};
