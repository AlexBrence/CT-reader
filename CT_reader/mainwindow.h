#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include "filehandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    FileHandler<QByteArray> fh_color;
    FileHandler<QVector<short>> fh_CTScan;

    QImage image;


private slots:
    void on_pb_fileBrowseColor_clicked();
    void on_pb_fileBrowseCT_clicked();

    void on_pb_showImage_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createImage();

};
#endif // MAINWINDOW_H
