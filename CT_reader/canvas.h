#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QLabel>

class Canvas : public QWidget
{
    Q_OBJECT

private:
    QImage image;
    QLabel *label;
    int x = 0;

public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

    void setImage(const QImage &image);
    void paintEvent(QPaintEvent *event) override;


signals:

};

#endif // CANVAS_H
