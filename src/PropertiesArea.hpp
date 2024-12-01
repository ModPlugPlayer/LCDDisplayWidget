/*
PropertiesArea class declarations of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <QWidget>
#include <APIStructures.hpp>
#include <QMouseEvent>

namespace Ui {
class PropertiesArea;
}

class PropertiesArea : public QWidget
{
    Q_OBJECT

public:
    explicit PropertiesArea(QWidget *parent = nullptr);
    void setRepeatState(ModPlugPlayer::RepeatState repeatState);
    void setEqState(bool enabled);
    void setAGCState(bool enabled);
    void setXBassState(bool enabled);
    void setSurroundState(bool enabled);
    void setReverbState(bool enabled);
    void setInterpolationState(ModPlugPlayer::InterpolationState interpolationState);
    ~PropertiesArea();

signals:
    void eqStateChangeRequested(bool activated);
    void agcStateChangeRequested(bool activated);
    void surroundStateChangeRequested(bool activated);
    void xBassStateChangeRequested(bool activated);
    void reverbStateChangeRequested(bool activated);
    void repeatStateChangeRequested(ModPlugPlayer::RepeatState repeatState);
    void interpolationStateChangeRequested(ModPlugPlayer::InterpolationState interpolationState);

private:
    Ui::PropertiesArea *ui;
    void onRepeatDoubleClicked();
    void onEqDoubleClicked();
    void onAGCDoubleClicked();
    void onXBassDoubleClicked();
    void onSurroundDoubleClicked();
    void onReverbDoubleClicked();
    void onInterpolationDoubleClicked();
    bool eqState = false, agcState = false, xBassState = false, surroundState = false, reverbState = false;
    ModPlugPlayer::RepeatState repeatState = ModPlugPlayer::RepeatState::None;
    ModPlugPlayer::InterpolationState interpolationState = ModPlugPlayer::InterpolationState::NoInterpolation;
};
