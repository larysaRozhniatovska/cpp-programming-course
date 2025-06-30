#include <QCoreApplication>
#include <iostream>
#include <thread>

#include "order.h"
/*
Задача 1: Паралельне обчислення математичних функцій

Створіть програму, яка обчислює різні математичні функції в окремих потоках:

    Потік 1: обчислює факторіал числа 15
    Потік 2: знаходить суму квадратів чисел від 1 до 1000
    Потік 3: обчислює числа Фібоначчі до 30-го елементу
    Потік 4: знаходить всі прості числа до 100

Кожен потік виводить свій результат незалежно від інших. Потоки повинні знаходитись в пулі потоків, а не створюватись окремо!
 */
void factorial(int &value)
{
    int res = 1;
    for(int i = 1; i <= value; i++){
        res *= i;
    }
    std::cout << "function factorial " << value << "! : " << res << std::endl;
    value = res;
}
void SumOfSquares(int min, int max, int &sum)
{
    sum = 0;
    for(int i = min; i <= max; i++){
        sum += (i*i);
    }
    std::cout << "function sum of squares " << min << " ... "<< max<< " = " << sum << std::endl;
}
void Fibonacci(int max)
{
    int i0 = 1;
    int i1 = 1;
    std::cout << "function Fibonacci 1: " << i0 << std::endl;
    std::cout << "function Fibonacci 2: " << i1 << std::endl;
    for(int i = 0; i < max-2; i++){
        int temp = (i0 + i1);
        i0 = i1;
        i1 = temp;
        std::cout << "function Fibonacci "<<i+2 <<": "<< i1 << std::endl;
    }
}

void Primary(int max)
{

    for (int i = 2; i <= max; i++)
    {
        bool bPrimes = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0){
                bPrimes = false;
                break;
            }
        }
        if (bPrimes){
           std::cout << "function Primary "<<i << std::endl;
        }
    }
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int value_factorial = 15;
    std::cout << "1. Define factorial: " << value_factorial << std::endl;

    int min = 1;
    int max = 1000;
    int sum = 0;
    std::cout << "2. Determine the sum of squares: " << min << " ... " << max << std::endl;

    int fibonacci = 30;
    std::cout << "3. Calculate Fibonacci numbers up to the " << fibonacci <<"th element" << std::endl;

    int primary = 100;
    std::cout << "4. Find all prime numbers up to " << primary << std::endl;


    std::thread worker(factorial, std::ref(value_factorial));
    std::thread worker1(SumOfSquares,min,max, std::ref(sum));
    std::thread worker2(Fibonacci,fibonacci);
    std::thread worker3(Primary, primary);

    worker.join();
    worker1.join();
    worker2.join();
    worker3.join();

    std::cout << " factorial " << value_factorial << std::endl;
    std::cout << " sum of squares " << sum << std::endl;

    std::vector<Order> orders;
    Order order(102);
    order.add("apple",78,2);
    order.add("bread",34,1);

    orders.push_back(order);

    std::vector<Order> ordersAnswer;
    std::thread orderThread(&OrderProcessor::safeValidateOrders, std::cref(orders),
                            std::ref(ordersAnswer));
    if (orderThread.joinable()) {
       orderThread.join();
    }
    for(size_t i = 0; i < ordersAnswer.size(); i++)
    {
        Order order = ordersAnswer[i];
        auto items = order.getItems();
        std::cout<<" Order "<<order.getId()<<"   "<<order.getStatus()<< std::endl;
        for(auto  it = items->begin(); it < items->end(); it++)
        {
            std::cout<<it->name <<"  "<<it->count<<"  "<<it->price<< std::endl;
        }
    }
    std::thread orderThread1(&OrderProcessor::calculatePricing,
                            std::ref(ordersAnswer));
    if (orderThread1.joinable()) {
       orderThread1.join();
    }
    for(size_t i = 0; i < ordersAnswer.size(); i++)
    {
        Order order = ordersAnswer[i];
        std::cout<<" Order "<<order.getId()<<"  TotalPrice: "<<order.getTotalPrices()<< std::endl;
    }
    std::thread orderThread2(&OrderProcessor::checkInventory,
                            std::ref(ordersAnswer));
    if (orderThread2.joinable()) {
       orderThread2.join();
    }
    for(size_t i = 0; i < ordersAnswer.size(); i++)
    {
        Order order = ordersAnswer[i];
        std::cout<<" Order "<<order.getId()<<"  checkInventory: "<<order.getStatus()<< std::endl;
    }
    std::thread orderThread3(&OrderProcessor::generateInvoices,
                            std::ref(ordersAnswer));
    if (orderThread3.joinable()) {
       orderThread3.join();
    }

    return a.exec();
}
