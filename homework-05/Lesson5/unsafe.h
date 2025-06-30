#ifndef UNSAFE_H
#define UNSAFE_H

class UnsafeBankAccount {
private:
    double balance = 1000.0;  // Початковий баланс

public:
    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double get_balance() const {
        return balance;
    }
};

class UnsafeBankStatistics {
private:
    int transaction_count = 0;
    double total_amount = 0.0;
    double total_amountMinus = 0.0;
public:
    void record_transaction(double amount) {
        transaction_count++;
        if(amount > 0){
            total_amount = total_amount + amount;
        }else{
            total_amountMinus = total_amountMinus - amount;
        }
    }

    int get_total_transactions() const { return transaction_count; }
    double get_total_amount() const { return total_amount; }
    double get_total_amountMinus() const { return total_amountMinus; }
};

#endif // UNSAFE_H
