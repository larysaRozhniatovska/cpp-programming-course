#ifndef SAFEBANK_H
#define SAFEBANK_H

#include <mutex>
#include <atomic>
#include <iostream>

class SafeBankAccount {
private:
    double balance = 1000.0;
    mutable std::mutex balance_mutex;

public:
    void deposit(double amount) {
        std::lock_guard<std::mutex> lock(balance_mutex);
        balance += amount;
    }

    bool withdraw(double amount) {
        std::lock_guard<std::mutex> lock(balance_mutex);
        if (balance >= amount) {
            balance -= amount;

            return true;
        }
        return false;
    }

    double get_balance() const {
        std::lock_guard<std::mutex> lock(balance_mutex);
        return balance;
    }
};

class SafeBankStatistics {
private:
    std::atomic<int> transaction_count{0};
    std::atomic<double> total_amount{0.0};
    std::atomic<double> total_amountMinus{0.0};

public:
    void record_transaction(double amount) {
        transaction_count++;

        if (amount > 0){
            total_amount = total_amount + amount;
        }else{
            total_amountMinus = total_amountMinus - amount;
        }
    }

    int get_total_transactions() const {
        return transaction_count.load();
    }

    double get_total_amount() const {
        return total_amount.load();
    }
    double get_total_amountMinus() const {
        return total_amountMinus.load();
    }
};

#endif // SAFEBANK_H
