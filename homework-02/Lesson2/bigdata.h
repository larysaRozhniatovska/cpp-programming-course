#ifndef BIGDATA_H
#define BIGDATA_H

#include <iostream>
/*
Вимоги:

    - Реалізуйте конструктор, конструктор копіювання, оператор копіювання, конструктор переміщення та
      оператор переміщення.
    - Створіть функцію, яка повертає об'єкт BigData (за значенням), щоб продемонструвати роботу переміщення.
    - Додайте логи(вивід в консоль) в кожен конструктор/деструктор/оператор, щоб бачити, коли копіюється,
      а коли переміщується об'єкт.

    Написати Lambda-вираз який захоплює по посиланню будь який зручний вам контейнер STL.
    Також він приймає по параметру певне значення, на котре збільшує кожен елемент цього контейнеру.
 */

class BigData {
    private:
        int* data = nullptr;
        size_t size;

    public:
        BigData(size_t size);
        ~BigData();

    // Конструктор копіювання
        BigData(const BigData& other);

    // Оператор копіювання
        BigData& operator=(const BigData& other);

    // Конструктор переміщення
        BigData(BigData&& other) noexcept;

    // Оператор переміщення
        BigData& operator=(BigData&& other) noexcept;

        void print() const;
};

#endif // BIGDATA_H
