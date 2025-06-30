#include "sensor.h"

Sensor::Sensor(std::shared_ptr<std::vector<int>> *ptr)
{
    if(ptr == nullptr){
        dataPtr = std::make_shared<std::vector<int>>();
    }else{
        dataPtr = *ptr;
    }

}
Sensor::~Sensor()
{

}
void Sensor::add(int a)
{
    dataPtr->push_back(a);
}
void Sensor::print()
{
    std::string str = "";
    for(auto it = dataPtr->begin(); it != dataPtr->end(); it++){
        std::cout << *it << std::endl;
    }
}

void CustomDeleteForArray(std::vector<int> *ptr)
{
     std::cout<<"==== CustomDeleteForArray"<<std::endl;
     delete ptr;
}
