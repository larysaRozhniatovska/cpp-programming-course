#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <vector>
#include <memory>
/*
Написати клас Sensor, який:

    Зберігає показання датчика в std::shared_ptr<std::vector<int>>.
    Надає функції для додавання та виводу показань.
    Зімітувати одночасне використання спільних даних датчика в main():
    Створити два екземпляри Sensor, які спільно володіють одним
    і тим самим std::vector<int> через std::shared_ptr.

 */
class Sensor
{
public:
    Sensor(std::shared_ptr<std::vector<int>> *ptr);
    ~Sensor();
    void add(int a);
    void print();

    std::shared_ptr<std::vector<int>> dataPtr;
private:
    void CustomDeleteForArray(int *ptr);
};

#endif // SENSOR_H
