#ifndef FILESCANNER_H
#define FILESCANNER_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QAtomicInt>
#include <QDebug>
#include <QThread>

#include "file_item.h"

class FileScanner : public QObject
{
    Q_OBJECT
public:
    explicit FileScanner(const QString &path,QObject *parent = nullptr);
    void moveToThread(QThread *thread);

public slots:
    void scanDirectory();
    void stopScanning();

signals:
    void fileFound(const FileItem &file);
    void progress(int filesProcessed, const QString &currentPath);
    void finished(const QList<FileItem> &allFiles);
    void error(const QString &message);

private:
    void scanRecursive(const QDir &dir);
    FileItem createFileItem(const QFileInfo &info);

    QList<FileItem> m_foundFiles;

    QString m_selectedPath;

    static bool f_single;
    std::atomic_bool m_running{false};

    QThread *m_thread;
};


#endif // FILESCANNER_H
