/*
TitleArea class declarations of ModPlug Player
Copyright (C) 2024 Volkan Orhan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <QWidget>

namespace Ui {
class TitleArea;
}

class TitleArea : public QWidget
{
    Q_OBJECT

public:
    explicit TitleArea(QWidget *parent = nullptr);
    void setTitle(const QString &title);
    ~TitleArea();

private:
    Ui::TitleArea *ui;
    QFont *SevenSegment;
    QFont *InterFont;
    QFont *SongTitleFont;
};
