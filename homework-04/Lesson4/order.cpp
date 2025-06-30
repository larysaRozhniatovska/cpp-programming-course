#include "order.h"

Order::Order(int id)
{
    this->id = id;
}
void Order::add(std::string name, double price, int count)
{
    Product item;
    item.name = name;
    item.price = price;
    item.count = count;
    status = "accepted";
    items.push_back(item);
}

std::vector<Order> OrderProcessor::validateOrders(const std::vector<Order>& rawOrders)
{
    std::cout << "validateOrders" <<  std::endl;
    std::vector<Order> result;

    for(size_t i = 0; i < rawOrders.size(); i++)
    {
        Order order = rawOrders[i];
        bool valid = true;
        auto items = order.getItems();
        for(auto  it = items->begin(); it < items->end(); it++)
        {
            if(it->name == ""){
                std::cout << "the name is empty!";
                valid = false;
            }else
            if(it->count == 0){
                std::cout << "count = 0!";
                valid = false;
            }else
            if(it->price <= 0){
                std::cout << "the price is incorrect!";
                valid = false;
            }
        }
        if(valid){
            order.setStatus("verified");

        }else{
             order.setStatus("not valid");
        }
        result.push_back(order);
    }
    return result;
}
void OrderProcessor::safeValidateOrders(const std::vector<Order>& rawOrders,
                                     std::vector<Order>& orders   )
{
    std::vector<Order> res;
    try {
        orders = validateOrders(rawOrders);
    }
        catch (const std::exception& e) {
        std::cout << "Перехоплено виняток у потоці: " << e.what() << std::endl;
    }
}
void OrderProcessor::calculatePricing(std::vector<Order>& orders )
{
    std::cout << "calculatePricing" <<  std::endl;
    std::vector<Order> result;

    for(size_t i = 0; i < orders.size(); i++)
    {
        Order order = orders[i];
        auto items = order.getItems();
        if(order.getStatus() == "verified" ){
            double price = 0;
            for(auto  it = items->begin(); it < items->end(); it++)
            {
               price += it->price * it->count;
               orders[i].setTotalPrice(price);
               orders[i].setStatus("totalPrice");
            }
        }
    }
}
void OrderProcessor::checkInventory(std::vector<Order>& pricedOrders)
{
    std::cout << "checkInventory" <<  std::endl;
    std::vector<Order> result;

    for(size_t i = 0; i < pricedOrders.size(); i++)
    {
        Order order = pricedOrders[i];
        auto items = order.getItems();
        if(order.getStatus() == "totalPrice" ){
            bool exist = false;
            for(auto  it = items->begin(); it < items->end(); it++)
            {
               exist = true;
            }
            if(exist)
                pricedOrders[i].setStatus("checkInventory");
        }
    }
}
void OrderProcessor::generateInvoices(const std::vector<Order>& finalOrders)
{
    std::cout << "finalOrders:" <<  std::endl;
    std::vector<Order> result;

    for(size_t i = 0; i < finalOrders.size(); i++)
    {
        Order order = finalOrders[i];
        auto items = order.getItems();
        if(order.getStatus() == "checkInventory" ){
            for(auto  it = items->begin(); it < items->end(); it++)
            {
                std::cout<<"      "<<it->name <<"  "<<it->count<<"  "<<it->price<< std::endl;
            }
        }
    }
}
