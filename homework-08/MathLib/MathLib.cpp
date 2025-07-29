#include "MathLib.h"

MathLib::MathLib()
{
}
#include "MathLib.h"

/**
* додавання a+b
* @param a
* @param b
* @return
*/
double MathLib::add(double a, double b) //
{
    return a+b;
}
/**
* віднімання a - b
* @param a
* @param b
* @return
*/
double MathLib::subtract(double a, double b)
{
    return a - b;
}
/**
 * множення a*b
 * @param a
 * @param b
 * @return
 */
double MathLib::multiply(double a, double b)
{
    return a * b;
}
/**
 * ділення a/b
 * @param a
 * @param b
 * @return
 */
double MathLib::divide(double a, double b)
{
    if (b == 0){
       throw std::invalid_argument( "ділення на нуль" );
    }else
    {
        return a / b;
    }
}
//Математичні функції:
/**
 * піднесення base до степеня exponent
 * @param base
 * @param exponent
 * @return
 */
double MathLib::power(double base, int exponent)
{
    if (exponent == 0)
    {
        return 1.0;
    }
    double a = base;
    for(int i = 0; i < exponent-1; i++){
        a *= base;
    }
    return a;
}
/**
 *  квадратний корінь value
 * @param value
 * @return
 */
double MathLib::squareRoot(double value)
{
    return sqrt(value);
}
/**
 *  абсолютне значення
 * @param value
 * @return
 */
double MathLib::absoluteValue(double value)
{
    if(value < 0)
    {
        return -value;
    }
    return value;
}
//Функції з цілими числами:
/**
 *  факторіал числа
 * @param n
 * @return
 */
int MathLib::factorial(int n)
{
    int res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
   return res;
}
/**
 * перевірка чи число просте
 * @param number
 * @return
 */
bool MathLib::isPrime(int number)
{
    if(number < 2){
        return false;
    }else
    if(number  ==  2){
        return true;
    }
    bool bPrimes = true;
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0){
            bPrimes = false;
            break;
        }
    }
    return bPrimes;
}
/**
 * найбільший спільний дільник
 * @param a
 * @param b
 * @return
 */
int MathLib::gcd(int a, int b)
{
    int i0 = a;
    int i1 = 1;
    if (b < a){
        i0 = b;
    }
    for (int i = 2; i < i0; i++)
    {
        if ((a % i == 0) && (b % i == 0)){
           i1 = i;
        }
    }
     return i1;
}

//Робота з масивами:
/**
 * максимум масиву arr
 * @param arr
 * @param size
 * @return
 */
double MathLib::findMax(const double arr[], int size)
{
    if (size < 1)
    {
         throw std::invalid_argument( "пустий масив" );
    }
    double max = arr[0];
    for(int i=1; i < size; i++){
        if (max < arr[i]){
             max = arr[i];
        }
    }
   return max;
}
/**
 * мінімум масиву arr
 * @param arr
 * @param size
 * @return
 */
double MathLib::findMin(const double arr[], int size)
{
    if (size < 1)
    {
         throw std::invalid_argument( "пустий масив" );
    }
    double min = arr[0];
    for(int i=1; i < size; i++){
        if (min > arr[i]){
             min = arr[i];
        }
    }
   return min;
}
/**
 * сума елементів масиву arr
 * @param arr
 * @param size
 * @return
 */
double MathLib::calculateSum(const double arr[], int size)
{
    if (size < 1)
    {
         throw std::invalid_argument( "пустий масив" );
    }
    double sum = arr[0];
    for(int i=1; i < size; i++){
        sum += arr[i];
    }
   return sum;
}
/**
 * середнє арифметичне  масиву arr
 * @param arr
 * @param size
 * @return
 */
double MathLib::calculateAverage(const double arr[], int size)// - середнє арифметичне
{
    if (size < 1)
    {
         throw std::invalid_argument( "пустий масив" );
    }
    double sum = arr[0];
    for(int i=1; i < size; i++){
        sum += arr[i];
    }
   return sum/size;
}
/**
 * сортування масиву arr
 * @param arr
 * @param size
 */
void MathLib::sortArray(double arr[], int size)// -
{
    if (size < 1)
    {
         throw std::invalid_argument( "пустий масив" );
    }
    bool swapped;
    for(int i=0; i < size; i++){
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
//Утилітарні функції:
/**
 * перевірка на парність числа number
 * @param number
 * @return
 */
bool MathLib::isEven(int number)
{
    if (number % 2 == 0){
        return true;
    }
    return false;
}
/**
 * перевірка на непарність
 * @param number
 * @return
 */
bool MathLib::isOdd(int number)
{
    if (number % 2 != 0){
        return true;
    }
    return false;
}
/**
 * n-те число Фібоначчі
 * @param n
 * @return
 */
int MathLib::fibonacci(int n)
{
    int i0 = 1;
    int i1 = 1;
    for(int i = 0; i < n-2; i++){
        int temp = (i0 + i1);
        i0 = i1;
        i1 = temp;
    }
    return i1;
}
