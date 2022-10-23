//#include "filehandler.h"

//template <class T>
//FileHandler<T>::FileHandler() { }

//template <typename T>
//FileHandler<T>::FileHandler(const FileHandler<T>& fh) : file(fh.file), content(fh.content) { }

//template <class T>
//int FileHandler<T>::readContent(const QString& path, const int rows, const int cols) {
//    file.setFileName(path);
//    if (!file.open(QIODevice::ReadOnly)) { return 0; }

//    int bytes_read = 0;
//    content.reserve(rows);

//    for (int i = 0; i < rows; i++) {
//        T barr;
//        barr.reserve(cols);

//        for (int j = 0; j < cols; j++, bytes_read++) {
//            barr.append(file.read(1));
//        }
//        content.push_back(std::move(barr));
//    }
//    return bytes_read;

//    file.close();
//}


//template <class T>
//QVector<T> FileHandler<T>::getContent() const {
//    return content;
//}

//template FileHandler<QVector<short>>::FileHandler();
//template FileHandler<QByteArray>::FileHandler();
