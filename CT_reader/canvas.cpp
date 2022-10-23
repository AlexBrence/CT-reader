#include "canvas.h"

#include <QPainter>
#include <QLabel>
#include <QHBoxLayout>

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}, label(new QLabel(this))
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    label->setFixedSize(512, 512);
    layout->addWidget(label);

    delete layout;
}

Canvas::~Canvas()
{
    qDebug() << "~Canvas";
    delete label;
}


void Canvas::setImage(const QImage &image) {
    this->image = image;
}


void Canvas::paintEvent(QPaintEvent *event) {
    if (image.isNull()) {
        qDebug() << "image.isNull()";
        QWidget::paintEvent(event);
        return;
    }

    QPixmap pixmap = QPixmap::fromImage(image);

    qDebug() << "Repaint called" << QString::number(x++) << ", img.size " << image.size();
    label->setPixmap(pixmap);
    image = QImage();
}
