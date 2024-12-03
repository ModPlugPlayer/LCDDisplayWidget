#include "ClickableLabel.hpp"
#include <QMouseEvent>

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {
}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mouseDoubleClickEvent(QMouseEvent *event) {
    emit doubleClicked();
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent *event) {
    emit clicked();
}

