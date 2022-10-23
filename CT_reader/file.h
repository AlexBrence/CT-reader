#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QVector>
#include <QFile>

class File : public QFile {
private:
    QVector<QByteArray> content;

public:
    File(QString path);

    int read_content(const int rows, const int cols);

};

#endif // FILE_H
