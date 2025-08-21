#include "file_item.h"

FileItem::FileItem(const QString &name, const QString &path,
                   qint64 size, const QDateTime &modified, const QString &type)
{
    m_name = name;
    m_path = path;
    m_size = size;
    m_modified = modified;
    m_type = type;
}

QString FileItem::extension() const
{
    if( m_type == "png" || m_type == "bmp" || m_type == "jpg" || m_type == "jpeg"){
        return "Image";
    }
    if( m_type == "pdf" ){
        return "PDF";
    }
    if( m_type == "csv" || m_type == "xlsx" || m_type == "xlx" ){
        return "Exel";
    }
    if( m_type == "doc" || m_type == "docx"  ){
        return "Exel";
    }
    if( m_type == "zip" || m_type == "tar" || m_type == "7z" ){
        return "Archive";
    }
    if( m_type == "cpp" || m_type == "h" || m_type == "pro"
       || m_type == "pro.user" || m_type == "txt.user"){
        return "file C++";
    }
    if( m_type == "txt"  ){
        return "Text";
    }
    if( m_type == "mp4"  ){
        return "Video";
    }
    return m_type;
}

// Для відображення
QString FileItem::sizeString() const
{
    double dd = m_size / 1024.0 / 1024.0;
    return QString::number(dd,'f', 6) + " MB";
}
QString FileItem::modifiedString() const
{
    return m_modified.toString("dd.MM.yy");
}
