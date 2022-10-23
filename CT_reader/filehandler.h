#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "qdebug.h"
#include <QFile>
#include <QVector>
#include <QtEndian>
#include <type_traits>

template <class T>
class FileHandler {
private:
    QFile file;

    QVector<T> content;

public:
    FileHandler() = default;

    int readContent(const QString& path, const int rows, const int cols) {
        content.clear();

        file.setFileName(path);
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Could not read the content";
            return 0;
        }

        int bytes_read = 0;
        content.reserve(rows);

        for (int i = 0; i < rows; i++) {
            QByteArray barr;
            barr.reserve(cols);

            for (int j = 0; j < cols; j++, bytes_read++) {
                barr.push_back(file.read(1));
            }

            // If needs to be converted from bytes to short
            if constexpr (std::is_same_v<T, QVector<short>>) {
                QVector<short> vec;
                vec.reserve(cols);

                qint16 *p = (qint16*) barr.data();
                int length = barr.size() / sizeof(qint16);

                for (int i = 0; i < length; i++) {
                    vec.push_back(qFromLittleEndian(p[i]));
                }
                content.push_back(std::move(vec));
            }
            else {
                content.push_back(std::move(barr));
            }
        }
        qDebug() << "File read";
        file.close();
        return bytes_read;
    }

    QVector<T> getContent() const {
        return content;
    }

    int size() const {
        return content.size();
    }


};

#endif // FILEHANDLER_H
