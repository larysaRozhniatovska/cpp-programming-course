#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <vector>

/*

Завдання: Створіть систему, де:

    Потік 1: валідує початкові замовлення (перевіряє формат, коректність даних)
    Потік 2: чекає завершення потоку 1, розраховує ціни для валідних замовлень
    Потік 3: чекає потік 2, перевіряє наявність товарів на складі
    Потік 4: чекає потік 3, генерує рахунки-фактури та відправляє клієнтам

 */

struct Product{
    std::string name;
    double price;
    int count;
};

class Order {
private:
    int id;
    std::vector<Product> items;
    double totalPrice;
    std::string status;
public:
     Order(int id);
    void add(std::string name, double price, int count);
    std::vector<Product> *getItems()
    {
        return &items;
    }
    int getId()
    {
        return id;
    }
    void setStatus(std::string value)
    {
        status = value;
    }
    std::string getStatus()
    {
        return status;
    }
    void setTotalPrice(double value)
    {
        totalPrice = value;
    }
    double getTotalPrices()
    {
        return totalPrice;
    }
};

class OrderProcessor {
private:
    static std::vector<Order> validateOrders(const std::vector<Order>& rawOrders);
public:

    static void safeValidateOrders(const std::vector<Order>& rawOrders,
                                          std::vector<Order>& orders);
    static void calculatePricing(std::vector<Order>& validOrders);
    static void checkInventory(std::vector<Order>& pricedOrders);
    static void generateInvoices(const std::vector<Order>& finalOrders);
};

#endif // ORDER_H
