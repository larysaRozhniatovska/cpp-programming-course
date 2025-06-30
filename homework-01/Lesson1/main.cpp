#include <QCoreApplication>
#include <iostream>


/*
 Приймає в себе по посиланню будь який контейнер STL,
 та за допомогою range-based loop виводить на екран всі його елементи.
* @brief func1
* @param collection
*/

template<typename T> void func1(const T*collection)
{
    std::cout <<std::endl;
     std::cout <<"function 1" << std::endl;
     for(const auto& element : *collection){
         std::cout <<element << std::endl;
     }
      std::cout <<"end function 1" << std::endl;
      std::cout <<std::endl;
}
/**
 Приймає в себе по посиланню будь який контейнер STL, та за
 допомогою ітераторів виводить на екран всі його елементи, тип ітератора вивести через auto.
* @brief func2
* @param collection
*/
template<typename T> void func2(const T*collection)
{
    std::cout <<std::endl;
    std::cout <<"function 2" << std::endl;
    for(auto it = collection->begin(); it != collection->end(); it++){
        std::cout << *it << std::endl;
    }
     std::cout <<"end function 2" << std::endl;
     std::cout <<std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Start the Programm" << std::endl;

    std::vector<std::string> collection({"first","second","third"});
    func1(&collection);

     func2(&collection);

    return a.exec();
}
