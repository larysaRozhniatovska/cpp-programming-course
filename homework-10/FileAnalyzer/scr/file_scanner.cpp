#include "file_scanner.h"

bool FileScanner::f_single = true;

FileScanner::FileScanner(const QString &path,QObject *parent) : QObject(parent)
{
    if (f_single)
    {
        f_single = false;
        qRegisterMetaType<FileItem>("FileItem");
        qRegisterMetaType<QList<FileItem>>("QList<FileItem>");
    }
     m_selectedPath = path;
}
void FileScanner::moveToThread(QThread *thread)
{
    m_thread = thread;
    QObject::moveToThread(thread);
}
void FileScanner::scanDirectory()
{
    if (this->m_running.exchange(true)) {
        emit error("Сканування вже запущено");
        return; // already running
    }

    if (m_selectedPath == ""){
        emit error("Не вибрана директрорія");
        return;
    }
    QDir mDir;
    mDir.setPath(m_selectedPath);
    if (!mDir.exists()){
        emit error("Не існує директрорія");
        return;
    }
    m_foundFiles.clear();

    emit progress(0,"");

    scanRecursive(mDir);

    this->m_running.store(false);
    emit  finished(m_foundFiles);
}
void FileScanner::stopScanning()
{
    this->m_running.store(false);
}
void FileScanner::scanRecursive(const QDir &dir)
{
    bool firstFile = true;

    QFileInfoList folderitems( dir.entryInfoList() );
    foreach ( QFileInfo info, folderitems )
    {
        if(this->m_running.load() == false){
            return;
        }
        QString iname( info.fileName() );
        if ( iname == "." || iname == ".." || iname.isEmpty() )
            continue;

        if ( info.isDir() ){
            QDir recursive(info.absoluteFilePath());
            scanRecursive( recursive );
        }
        else{
            if(firstFile){
                firstFile = false;
                QStringList fileList = dir.entryList(QDir::Files);
                emit progress(fileList.count(),dir.absolutePath());
            }
            FileItem item = createFileItem(info);
            m_foundFiles.append(item);
            emit fileFound(item);

        }
        thread()->msleep(1);
    }
}
FileItem FileScanner::createFileItem(const QFileInfo &info)
{
    FileItem item(info.fileName(),info.absoluteFilePath(),
                  info.size(),info.lastModified(),info.completeSuffix() );
    return item;
}
