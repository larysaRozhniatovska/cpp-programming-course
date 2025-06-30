#include <QCoreApplication>

#include <iostream>
#include <thread>
#include <vector>
#include <random>


#include <mutex>
#include <atomic>

#include "unsafe.h"
#include "SafeBank.h"
/*
Умова задачі
Ви розробляєте систему для банку, де кілька касирів (потоків) одночасно обслуговують клієнтів. Потрібно реалізувати безпечні операції з рахунками та статистикою.
Вимоги:
    Симуляція роботи банку:

    5 касирів (потоків) одночасно обслуговують клієнтів
    Кожен касир робить 100 випадкових операцій
    Операції: поповнення (50-500 грн) або зняття (10-200 грн)

Частина 1: Небезпечна версія
Спочатку реалізуйте версію БЕЗ синхронізації:
// TODO: Реалізуйте функцію cashier_work
// TODO: Реалізуйте main функцію з 5 потоками

Запустіть кілька разів і порівняйте результати. Що ви помічаєте?

Частина 2: Безпечна версія

Тепер реалізуйте безпечну версію, використовуючи різні механізми синхронізації:

Очікувані результати

Небезпечна версія:

    Баланс може бути від'ємним
    Статистика неточна
    Результати відрізняються між запусками

Безпечна версія:

    Баланс завжди коректний
    Точна статистика
    Стабільні результати

Приклад виводу:

=== Bank Simulation Results ===
Initial balance: 1000.00
Final balance: 1150.75
Total transactions: 500
Total transaction amount: 45230.50
All cashiers completed work safely!
 */


void cashier_work(UnsafeBankAccount &account,
                  UnsafeBankStatistics &statistics, int operation)
{
    int count = 0;
    for (int i = 1; i <= operation; ++i) {
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        std::uniform_int_distribution<> dist(5000,50000); // distribute results between 1 and 6 inclusive.

        std::random_device rdZ;   // non-deterministic generator
        std::mt19937 genZ(rdZ());  // to seed mersenne twister.
        std::uniform_int_distribution<> distZ(1,2); // distribute results between 1 and 6 inclusive.

        int operation = distZ(genZ);
        double sum = dist(gen) * 0.01;

        if(operation == 1){
            account.deposit(sum);
        }else{
            account.withdraw(sum);
            sum = -sum;
        }

        statistics.record_transaction(sum);
        count++;
   }

}
std::mutex balance_mutex;
void cashier_workSafe( SafeBankAccount &account,
                  SafeBankStatistics &statistics, int id,int operation)
{
    int count = 0;
    for (int i = 1; i <= operation; ++i) {
        std::lock_guard<std::mutex> lock(balance_mutex);

        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        std::uniform_int_distribution<> dist(5000,50000); // distribute results between 1 and 6 inclusive.

        std::random_device rdZ;   // non-deterministic generator
        std::mt19937 genZ(rdZ());  // to seed mersenne twister.
        std::uniform_int_distribution<> distZ(1,2); // distribute results between 1 and 6 inclusive.

        int operation = distZ(genZ);
        double sum = dist(gen) * 0.01;

        if(operation == 1){
            account.deposit(sum);
            std::cout<<"id: "<<id<< " sum "<< sum<<std::endl;
        }else{
            account.withdraw(sum);
            sum = -sum;
//            std::cout<<"id: "<<id<<" sum "<< -sum<<std::endl;
        }

        statistics.record_transaction(sum);
//        std::cout<<"id: "<<id<< " statistics "<< statistics.get_total_transactions()<<std::endl;
        count++;
   }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    UnsafeBankAccount account;
    UnsafeBankStatistics statistics;
    std::vector<std::thread> threads;

    auto start = std::chrono::high_resolution_clock::now();

    std::cout<<"=== Bank Simulation Results Unsafe==="<<std::endl;
    std::cout<<"Initial balance: "<<account.get_balance()<<std::endl;

    for (int i = 0; i < 5; ++i) {
       threads.emplace_back(cashier_work, std::ref(account),
                            std::ref(statistics), 100);
    }

    // Wait for all threads
    for (auto& t : threads) {
       t.join();
    }

    std::cout<<"Final balance: "<<account.get_balance()<<std::endl;

    std::cout<<"Total transactions: "<<statistics.get_total_transactions()<<std::endl;
    std::cout<<"Total transaction amount: "<<statistics.get_total_amount()<<std::endl;
    std::cout<<"Total transaction amount Minus: "<<statistics.get_total_amountMinus()<<std::endl;
    if (statistics.get_total_transactions() == 100)
        std::cout<<"All cashiers completed work safely! "<<std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "UnSafe time: " << duration.count() << " ms" << std::endl;


    auto startS = std::chrono::high_resolution_clock::now();

    SafeBankAccount accountS;
    SafeBankStatistics statisticsS;
    std::vector<std::thread> threadsS;

    std::cout<<std::endl<<std::endl;
    std::cout<<"=== Bank Simulation Results Safe==="<<std::endl;
    std::cout<<"Initial balance: "<<accountS.get_balance()<<std::endl;

    for (int i = 0; i < 5; ++i) {
       threadsS.emplace_back(cashier_workSafe, std::ref(accountS),
                            std::ref(statisticsS),i+1, 100);
    }

    // Wait for all threads
    for (auto& t : threadsS) {
       t.join();
    }

    std::cout<<"Final balance: "<<accountS.get_balance()<<std::endl;

    std::cout<<"Total transactions: "<<statisticsS.get_total_transactions()<<std::endl;
    std::cout<<"Total transaction amount: "<<statisticsS.get_total_amount()<<std::endl;
    std::cout<<"Total transaction amount Minus: "<<statisticsS.get_total_amountMinus()<<std::endl;


    if (statisticsS.get_total_transactions() == 100)
        std::cout<<"All cashiers completed work safely! "<<std::endl;

    auto endS = std::chrono::high_resolution_clock::now();
    auto durationS = std::chrono::duration_cast<std::chrono::milliseconds>(endS - startS);

    std::cout << "Safe time: " << durationS.count() << " ms" << std::endl;


    return a.exec();
}
