#pragma once

#include <QWidget>

namespace Ui {
class SongInformationArea;
}

class SongInformationArea : public QWidget
{
    Q_OBJECT

public:
    explicit SongInformationArea(QWidget *parent = nullptr);
    ~SongInformationArea();

    void setSongDuration(const size_t songDurationSeconds);
    void setCurrentPattern(const size_t currentPattern);
    void setCurrentSubSong(const size_t currentSubSong);
    void setSubSongAmount(const size_t subSongAmount);
    void setPatternAmount(const size_t patternAmount);

private:
    Ui::SongInformationArea *ui;
    QFont *SevenSegment;
    QFont *InterFont;
    QFont *SongTitleFont;
};
