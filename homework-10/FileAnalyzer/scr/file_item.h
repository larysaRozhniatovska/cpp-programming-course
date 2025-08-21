#ifndef FILEITEM_H
#define FILEITEM_H


#include <QDateEdit>
#include <QDir>

class FileItem
{
public:
       FileItem() = default;
       FileItem(const QString &name, const QString &path,
                qint64 size, const QDateTime &modified, const QString &type);

       // Getters
       QString name() const { return m_name; }
       QString path() const { return m_path; }
       QString fullPath() const { return QDir(m_path).filePath(m_name); }
       qint64 size() const { return m_size; }
       QDateTime modified() const { return m_modified; }
       QString type() const { return m_type; }
       QString extension() const;

       // Для відображення
       QString sizeString() const;
       QString modifiedString() const;

   private:
       QString m_name;
       QString m_path;
       qint64 m_size = 0;
       QDateTime m_modified;
       QString m_type;

};

#endif // FILEITEM_H
