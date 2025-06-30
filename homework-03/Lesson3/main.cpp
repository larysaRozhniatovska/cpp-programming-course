#include <QCoreApplication>
#include "filemanager.h"
#include "sensor.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        std::cout<<"===== FileManager "<<std::endl;
        FileManager  managerFile("test.txt");
        managerFile.write("Hello! Lesson 3");
    }
    {
        std::cout<<"==== Sensor "<<std::endl;
        Sensor sensor(nullptr);
        sensor.add(5);
        sensor.add(55);
        std::cout<<"==== sensor "<<std::endl;
        sensor.print();
        auto ptr = sensor.dataPtr;
        Sensor sensor2(&sensor.dataPtr);
        sensor2.add(155);
        std::cout<<"==== sensor "<<std::endl;
        sensor.print();
        std::cout<<"==== sensor2 "<<std::endl;
        sensor2.print();

    }
    return a.exec();
}
