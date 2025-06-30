#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>

class FileManager
{
public:
    FileManager(std::string name );
    ~FileManager();

    void write(const std::string& str);

    std::FILE *file;

};

#endif // FILEMANAGER_H
