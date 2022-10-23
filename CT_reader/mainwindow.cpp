#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QPixmap>
#include <QFile>
#include <QFileDialog>
#include <QByteArray>
#include <QVector>
#include <QPixmap>
#include <QRgb>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow), image(512, 512, QImage::Format_RGB888)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::createImage() {
    QVector<QByteArray> v_color = fh_color.getContent();        // 256*3
    QVector<QVector<short>> v_CTImage = fh_CTScan.getContent(); // 512*512

    // QImage tmp = image;
    QImage img(512, 512, QImage::Format_RGB888);

    // Converts every pixel from CTImage to RGB(grayscale) value
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) {
            quint8 color_idx = ((float)(v_CTImage[i][j] + 2048) / 4095) * 255;
            QRgb color = qRgb(v_color[color_idx][0], v_color[color_idx][1], v_color[color_idx][2]);
            img.setPixel(i, j, color);
            // qDebug() << "idx: " << color_idx << ", color: " << color;
        }
    }
    // this->image = img;

    // qDebug() << "img == img: " << QString::number(tmp == image);

    // Sets the image to render
    ui->image->setImage(img);
}


void MainWindow::on_pb_fileBrowseColor_clicked() {
    // Browse for a color file
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/alex/Documents/Letnik03/Multimedia/tasks/", 0, nullptr, QFileDialog::DontUseNativeDialog);
    ui->le_fileBrowseColor->setText(filename);

    // Save color content
    if (!fh_color.readContent(filename, 256, 3)) {
        qDebug() << "Color pallete could not be read\n";
    }

    if (fh_CTScan.size()) {
        ui->pb_showImage->setEnabled(true);
    }
}

void MainWindow::on_pb_fileBrowseCT_clicked() {
    // Browse for a CT image
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/alex/Documents/Letnik03/Multimedia/tasks/", 0, nullptr, QFileDialog::DontUseNativeDialog);
    ui->le_fileBrowseCT->setText(filename);

    // Save ct scan content
    if (!fh_CTScan.readContent(filename, 512, 512 * sizeof(short))) {
        qDebug() << "CT scan could not be read\n";
    }

    if (fh_color.size()) {
        ui->pb_showImage->setEnabled(true);
    }
}

void MainWindow::on_pb_showImage_clicked() {
    createImage();
    ui->image->update();
    qDebug() << "Show image button clicked";
}

