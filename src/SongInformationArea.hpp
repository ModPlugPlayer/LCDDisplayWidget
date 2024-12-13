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
    void setCurrentPattern(const size_t currentPatternIndex);
    void setCurrentSubSong(const size_t currentSubSongIndex);
    void setSubSongAmount(const size_t subSongAmount);
    void setPatternAmount(const size_t patternAmount);

private:
    Ui::SongInformationArea *ui;
    QFont *SevenSegment;
    QFont *InterFont;
    QFont *SongTitleFont;
};
