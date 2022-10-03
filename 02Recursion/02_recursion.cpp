#include <iostream>
using namespace std;

int FindSum(int n){
    if(n == 1) return 1;
    return n + FindSum(n - 1);
}

int FindFactorial(int n){
    if(n == 1) return 1;
    return n * FindFactorial(n - 1);
}

int FindExponential(int x, int n){
    if (n == 1) return x;
    return x * FindExponential(x, n - 1);
}

int FindNumberOfDigit(int x){
    if (x < 10) return 1;
    return 1 + FindNumberOfDigit(x/10);
}

bool IsAllDigitEven(int x){
    if (x % 2 == 0){
        if(x < 10) return true;
        else return IsAllDigitEven((x - (x%10))/10);
    } 
    else return false;
}

int CountCommonDivisor(int a, int b){
    if (a == 1 || b == 1) return 1;
    else if (a % b == 0) return 
}

int main(){
    int n = 10, x = 2, a = 200000;
    cout << "Sum to " << n << ": " << FindSum (n) << endl;
    cout << "Factorial to " << n << ": " << FindFactorial(n) << endl;
    cout << "Exponential of " << x << "^" << n << ": " << FindExponential(x, n) << endl;
    cout << "Number of digit of " << a << ": " << FindNumberOfDigit(a) << endl;
    cout << "All digit is even " << a << "? " << IsAllDigitEven(a) << endl;
}