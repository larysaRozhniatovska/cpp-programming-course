#include "bigdata.h"

BigData::BigData(size_t size)
{
    std::cout<<"Constructor"<< std::endl;
    this->size = size;
    data = new int[size];
    for(size_t i = 0; i < size; i++){
        data[i] = i+ 54;
    }
}
BigData::~BigData()
{
    delete data;
}

// Конструктор копіювання
BigData::BigData(const BigData& other)
{
     std::cout<<"Constructor copied"<< std::endl;
     data = new int[other.size];
     for(size_t i = 0; i<other.size; i++){
         data[i] = other.data[i];
     }

      //or
     // memcpy(data,other.data,sizeof (int)*other.size);

     size = other.size;
}

// Оператор копіювання
BigData& BigData:: operator=(const BigData& other)
{
    std::cout<<"Operator copied"<< std::endl;
    // Перевірка на самоприсвоювання
    if (&other == this)
        return *this;

    // Видаляємо все, що до цього моменту може зберігати вказівник
    delete data;

    // Копіюємо переданий об'єкт
    memcpy(data,other.data,sizeof (int)*other.size);
    size = other.size;

    return *this;
}

// Конструктор переміщення
BigData::BigData(BigData&& other) noexcept
{
    std::cout<<"Constructor moved"<< std::endl;
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
}

// Оператор переміщення
BigData& BigData::operator=(BigData&& other) noexcept
{
     std::cout<<"Operator moved"<< std::endl;
    // Перевірка на самоприсвоювання
    if (&other == this)
        return *this;

    // Видаляємо все, що до цього моменту може зберігати вказівник
    delete data;

    // Передаємо право власності на other.data в this->data
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
    return *this;
}

void BigData::print() const
{
    if(size > 0){
        for(size_t i = 0; i < size; i++){
            std::cout <<data[i] << "  ";
        }
    }else{
        std::cout <<"empty"<< std::endl;
    }
     std::cout << std::endl;
}
