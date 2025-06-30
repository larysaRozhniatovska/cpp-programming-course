#include <QCoreApplication>
#include "bigdata.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const BigData data0(6);
    data0.print();
    std::cout  <<std::endl << " copy :" << std::endl;

    BigData dataCopy(data0);
    std::cout << " data0 :" << std::endl;
    data0.print();
    std::cout << " dataCopy :" << std::endl;
    dataCopy.print();

    std::cout <<std::endl << " move :" << std::endl;
    BigData dataMove(std::move(dataCopy));
    std::cout << " data0 :" << std::endl;
    data0.print();

    std::cout << " dataCopy :" << std::endl;
    dataCopy.print();
    std::cout << " dataMove :" << std::endl;
    dataMove.print();

    std::cout << std::endl;
    std::vector<int> collection({4,8,12,16,20});
     int iadd = 5;
     std::cout << " Lamda :" << std::endl;
     for(const auto& element : collection){
           std::cout  <<element << "  ";
     }
     std::cout << std::endl;
    auto add = [&collection](int iadd)
    {
        for(auto& element : collection){
            element += iadd;
        }
    };
    add(iadd);
    std::cout << "after Lambda :" << std::endl;
    for(const auto& element : collection){
          std::cout  <<element << " ";
    }
    std::cout << std::endl;



    return a.exec();
}
