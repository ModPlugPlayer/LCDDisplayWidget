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
    void setSongTitle(QString &songTitle);
    ~TitleArea();

    void setTotalTime(size_t songDurationSeconds);
private:
    Ui::TitleArea *ui;
    QFont *SevenSegment;
    QFont *InterFont;
};
