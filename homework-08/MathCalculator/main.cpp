#include <QCoreApplication>
#include <memory>
#include <iostream>
#include "../MathLib/MathLib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int choice,choice1, ii;
    double a1,b1,c1;
//    std::unique_ptr<double[]> arr;
    bool res;
    MathLib libb;// = new MathLib();

   do {
       choice = -1;
       std::cout << "\n==== Static lib ====\n";
       std::cout << "1. Basic arithmetic operations\n";
       std::cout << "2. Mathematical functions\n";
       std::cout << "3. Working with arrays \n";
       std::cout << "4. Whole numbers\n";
       std::cout << "5. Utility functions\n";
       std::cout << "6. Examples\n";
       std::cout << "0. Exit\n";
       std::cout << "Enter your choice: ";
       std::cin >> choice;
       if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
       {
           std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
           std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
           choice = -1;
       }else
       std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)

           std::cout << "\n";

           switch (choice) {
           case 1:
               std::cout << "==== Basic arithmetic operations ====\n";
               std::cout << "1. add\n";
               std::cout << "2. subtract\n";
               std::cout << "3. multiply\n";
               std::cout << "4. divide\n";
               std::cout << "Enter your choice: ";
               std::cin >> choice1;
               if (std::cin.fail() || choice1 > 4) // если предыдущее извлечение оказалось неудачным,
               {
                   std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                   std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                   choice1 = -1;
               }else{
                   std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                   std::cout << "Enter your first number: ";
                   std::cin >> a1;
                   if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                   {
                       std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                       std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                       choice1 = -1;
                   }else{
                       std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                       std::cout << "Enter your second number: ";
                       std::cin >> b1;
                       if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                       {
                           std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                           std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                           choice1 = -1;
                       }else
                           std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                   }
               }
               switch (choice1) {
               case 1:
                   c1 = libb.add(a1,b1);
                   std::cout << a1  << " + " << b1 <<" = " <<c1<<"\n";
                   break;
               case 2:
                   c1 = libb.subtract(a1,b1);
                   std::cout << a1  << " - " << b1 <<" = " <<c1<<"\n";
                   break;
               case 3:
                   c1 = libb.multiply(a1,b1);
                   std::cout << a1  << " * " << b1 <<" = " <<c1<<"\n";
                   break;
               case 4:
                   c1 = libb.divide(a1,b1);
                   std::cout << a1  << " / " << b1 <<" = " <<c1<<"\n";
                   break;
               default:
                   std::cout << "Invalid Basic arithmetic operations. Please try again.\n";
               }
               break;
           case 2:{
               std::cout << "==== Mathematical functions ====\n";
               std::cout << "1. power\n";
               std::cout << "2. squareRoot\n";
               std::cout << "3. absoluteValue\n";
               std::cout << "Enter your choice: ";
               std::cin >> choice1;
               if (std::cin.fail() || choice1 > 3) // если предыдущее извлечение оказалось неудачным,
               {
                   std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                   std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                   choice1 = -1;
               }else{
                   std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                   std::cout << "Enter your first number: ";
                   std::cin >> a1;
                   if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                   {
                       std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                       std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                       choice1 = -1;
                   }else{
                       std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                   }
               }
               switch (choice1) {
               case 1:
                   std::cout << "Enter your second number: ";
                   std::cin >> b1;
                   if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                   {
                       std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                       std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                       choice1 = -1;
                   }else{
                       std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                       c1 = libb.power(a1,b1);
                       std::cout << a1  << " ^ " << b1 <<" = " <<c1<<"\n";
                   }
                   break;
               case 2:
                   c1 = libb.squareRoot(a1);
                   std::cout<< " square " << a1  <<" = " <<c1<<"\n";
                   break;
               case 3:
                   c1 = libb.absoluteValue(a1);
                   std::cout << "|"<<a1 <<"|"<<" = " <<c1<<"\n";
                   break;
               default:
                   std::cout << "Invalid Mathematical functions. Please try again.\n";

               }
               break;}
           case 3:{
               std::cout << "====  Working with arrays ====\n";
               std::cout << "1. findMax\n";
               std::cout << "2. findMin\n";
               std::cout << "3. calculateSum\n";
               std::cout << "4. calculateAverage\n";
               std::cout << "5. sortArray\n";
               std::cout << "Enter your choice: ";
               std::cin >> choice1;
               double* rr;
               std::unique_ptr<double[]> arr;
               if (std::cin.fail() || choice1 > 5) // если предыдущее извлечение оказалось неудачным,
               {
                   std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                   std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                   choice1 = -1;
               }else{
                   std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                   std::cout << "Enter your size: ";
                   std::cin >> ii;
                   if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                   {
                       std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                       std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                       choice1 = -1;
                   }else{
                       std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                       arr =  std::make_unique<double[]>(ii);
                       for (int ia = 0; ia < ii; ia++)
                       {
                            std::cout << "Enter "<< ia+1<<" el array: ";
                            std::cin >> arr[ia];
                            if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                            {
                                std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                                std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                                choice1 = -1;
                                break;
                            }else{
                                std::cin.ignore(32767, '\n');
                            }
                       }

                   }
               }
               rr = arr.get();
               switch (choice1) {
               case 1:
                   c1 = libb.findMax(rr,ii);
                   for (int ia = 0; ia < ii; ia++)
                   {
                       std::cout << rr[ia] <<"  ";
                   }
                   std::cout  << " -  max " << c1<<"\n";
                   break;
               case 2:
                   c1 = libb.findMin(rr,ii);
                   for (int ia = 0; ia < ii; ia++)
                   {
                       std::cout << rr[ia] <<"  ";
                   }
                   std::cout  << " -  min " << c1<<"\n";
                   break;
               case 3:
                   c1 = libb.calculateSum(rr,ii);
                   for (int ia = 0; ia < ii; ia++)
                   {
                       std::cout << rr[ia] <<"  ";
                   }
                   std::cout  << " -  sum " << c1<<"\n";
                   break;
               case 4:
                   c1 = libb.calculateAverage(rr,ii);
                   for (int ia = 0; ia < ii; ia++)
                   {
                       std::cout << rr[ia] <<"  ";
                   }

                   std::cout  << " -  average " << c1<<"\n";
                   break;
               case 5:{
                   libb.sortArray(rr,ii);
                   for (int ia = 0; ia < ii; ia++)
                   {
                       std::cout << rr[ia] <<"  ";
                   }
                   std::cout <<"\n";
                   break;
               }
               default:
                   std::cout << "Invalid Working with arrays . Please try again.\n";

               }//switch (choice1)
               break;}
           case 4:{
               std::cout << "==== Whole numbers ====\n";
               std::cout << "1. factorial\n";
               std::cout << "2. isPrime\n";
               std::cout << "3. gcd\n";
               std::cout << "Enter your choice: ";
               std::cin >> choice1;
               if (std::cin.fail() || choice1 > 3) // если предыдущее извлечение оказалось неудачным,
               {
                   std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                   std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                   choice1 = -1;
               }else{
                   std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                   std::cout << "Enter your number: ";
                   std::cin >> a1;
                   if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                   {
                       std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                       std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                       choice1 = -1;
                   }else{
                       std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                   }
               }

               switch (choice1) {
               case 1:
                   c1 = libb.factorial(a1);
                   std::cout << a1  << "! " <<c1<<"\n";
                   break;
               case 2:
                   res = libb.isPrime(a1);
                   std::cout << a1  << " prime " <<res<<"\n";
                   break;
               case 3:
                   std::cout << "Enter your second number: ";
                   std::cin >> b1;
                   if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                   {
                       std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                       std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                       choice1 = -1;
                   }else{
                       std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                       c1 = libb.gcd(a1,b1);
                       std::cout << a1  << "  " << b1 <<" largest multiplier " <<c1<<"\n";
                   }
                    break;
               default:
                   std::cout << "Invalid Whole numbers. Please try again.\n";
               }
               break; }
           case 5:{
               std::cout << "==== Utility functions ====\n";
               std::cout << "1. isEven\n";
               std::cout << "2. isOdd\n";
               std::cout << "3. fibonacci\n";
               std::cout << "Enter your choice: ";
               std::cin >> choice1;
               if (std::cin.fail() || choice1 > 3) // если предыдущее извлечение оказалось неудачным,
               {
                   std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                   std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                   choice1 = -1;
               }else{
                   std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                   std::cout << "Enter your number: ";
                   std::cin >> a1;
                   if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                   {
                       std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                       std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
                       choice1 = -1;
                   }else{
                       std::cin.ignore(32767, '\n'); // удаляем до 32767 символов из входного буфера вплоть до появления символа '\n' (который мы также удаляем)
                   }
               }
               switch (choice1) {
               case 1:
                   res = libb.isEven(a1);
                   std::cout << a1  << " isEven " << res<<"\n";
                   break;
               case 2:
                   res = libb.isOdd(a1);
                   std::cout << a1  << " isOdd " << res<<"\n";
                   break;
               case 3:
                   ii = libb.fibonacci(a1);
                   std::cout <<"fibonacci "<< a1  << " = " <<ii<<"\n";
                   break;
               default:
                   std::cout << "Invalid Utility functions. Please try again.\n";

               }
               break;}
           case 6:{
               std::cout << "==== examples ====\n";
               a1 = 67;
               b1 = 35;
               c1 = libb.add(a1,b1);
               std::cout << a1  << " + " << b1 <<" = " <<c1<<"\n";
               c1 = libb.subtract(a1,b1);
               std::cout << a1  << " - " << b1 <<" = " <<c1<<"\n";
               c1 = libb.multiply(a1,b1);
               std::cout << a1  << " * " << b1 <<" = " <<c1<<"\n";
               c1 = libb.divide(a1,b1);
               std::cout << a1  << " / " << b1 <<" = " <<c1<<"\n";
               a1 = 3;
               b1 = 6;
               c1 = libb.power(a1,b1);
               std::cout << a1  << " ^ " << b1 <<" = " <<c1<<"\n";
               c1 = libb.squareRoot(a1);
               std::cout<< " square " << a1  <<" = " <<c1<<"\n";
               c1 = libb.absoluteValue(a1);
               std::cout << "|"<<a1 <<"|"<<" = " <<c1<<"\n";
               c1 = libb.absoluteValue(-a1);
               std::cout << "|"<<-a1 <<"|"<<" = " <<c1<<"\n";

               ii = 5;
               double rr[5]{13,67,45,34,89};
               c1 = libb.findMax(rr,ii);
               std::cout  << "array: ";
               for (int ia = 0; ia < ii; ia++)
               {
                   std::cout << rr[ia] <<"  ";
               }
               std::cout  << " -  max " << c1<<"\n";
               c1 = libb.findMin(rr,ii);
               std::cout  << "array: ";
               for (int ia = 0; ia < ii; ia++)
               {
                   std::cout << rr[ia] <<"  ";
               }
               std::cout  << " -  min " << c1<<"\n";
               c1 = libb.calculateSum(rr,ii);
               std::cout  << "array: ";
               for (int ia = 0; ia < ii; ia++)
               {
                   std::cout << rr[ia] <<"  ";
               }
               std::cout  << " -  sum " << c1<<"\n";
               std::cout  << "array: ";
               c1 = libb.calculateAverage(rr,ii);
               for (int ia = 0; ia < ii; ia++)
               {
                   std::cout << rr[ia] <<"  ";
               }
               std::cout  << " -  average " << c1<<"\n";
               libb.sortArray(rr,ii);
               std::cout  << "array sort: ";
               for (int ia = 0; ia < ii; ia++)
               {
                   std::cout << rr[ia] <<"  ";
               }
               std::cout <<"\n";
               a1 = 9;
               c1 = libb.factorial(a1);
               std::cout << a1  << "! " <<c1<<"\n";
               c1 = libb.isPrime(a1);
               std::cout << a1  << " prime " <<res<<"\n";
               c1 = libb.gcd(a1,b1);
               std::cout << a1  << "  " << b1 <<" largest multiplier " <<c1<<"\n";
               res = libb.isEven(a1);
               std::cout << a1  << " isEven " << res<<"\n";
               res = libb.isOdd(a1);
               std::cout << a1  << " isOdd " << res<<"\n";
               ii = libb.fibonacci(a1);
               std::cout <<"fibonacci "<< a1  << " = " <<ii<<"\n";


               break;
           }
           case 0:
               std::cout << "Exiting program...\n";
               break;
           default:
               std::cout << "Invalid choice. Please try again.\n";
           }
       } while (choice != 0);
    return a.exec();
}
