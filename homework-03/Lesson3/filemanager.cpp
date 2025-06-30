#include "filemanager.h"
#include <cstdio>
#include <cstdlib>

FileManager::FileManager(std::string name )
{
    file = std::fopen(name.c_str(),"w");

    if (!file)
    {
        std::perror("File opening failed");
    }else{
         std::cout << "open file "<< name << std::endl;
    }
}

FileManager::~FileManager()
{
    if (file)
    {
        std::cout << "close file "<< std::endl;
        std::fclose(file) ;
    }

}

void FileManager::write(const std::string& str)
{
    if (file)
    {
       size_t numwritten = fwrite( str.c_str(), sizeof( char ), str.size(), file);
       if(numwritten != str.size()){
           std::perror("File writing failed");
       }
       std::cout <<"Wrote in file  "<< numwritten << std::endl ;
    }
}
