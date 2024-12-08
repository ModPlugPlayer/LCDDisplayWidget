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

private:
    Ui::SongInformationArea *ui;
};
