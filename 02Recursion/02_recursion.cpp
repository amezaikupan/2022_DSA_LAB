#include <iostream>
#include <string>

using namespace std;

//Preload FindGCD to count all common divisor
int FindGCD(int a, int b);


//#1
int FindSum(int n){
    if(n == 1) return 1;
    return n + FindSum(n - 1);
}

//#2
int FindFactorial(int n){
    if(n == 1) return 1;
    return n * FindFactorial(n - 1);
}

//#3
int FindExponential(int x, int n){
    if (n == 1) return x;
    return x * FindExponential(x, n - 1);
}

//#4
int FindNumberOfDigit(int x){
    if (x < 10) return 1;
    return 1 + FindNumberOfDigit(x/10);
}

//#5
bool IsAllDigitEven(int x){
    if(x < 10) return (x % 2 == 0);
    return (x % 2 == 0) && IsAllDigitEven(x/10);
}

//#6
int CountCommonDivisor(int a, int b, int x = 1){
    static int gcd = FindGCD(a, b);
    if(x == gcd) return 1;
    if(gcd % x == 0) return 1 + CountCommonDivisor(a, b, x + 1);
    return CountCommonDivisor(a, b, x + 1); 
    
}

//#7
int FindGCD(int a, int b){
    if(a % b == 0) return b;
    else return FindGCD(b, a % b);
}

//#7
int FindLCM(int a, int b){
    return (a * b)/FindGCD(a, b);
}

//#8
int MakeReverse(int a, int reverse = 0){
    reverse = reverse * 10 + a % 10;

    if(a < 10) return reverse;
    else return MakeReverse((a - a%10) / 10, reverse);
}

//#9
int FindFibonaci(int cnt, int fib, int prefib){
    if(cnt == 0) return 0;
    if(cnt == 1) return fib;
    else return FindFibonaci(cnt - 1, fib + prefib, fib);
}

//10
void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

//Idea explaination:
//For abcd
//First loop would take the a and switch it to b, c or d
//then for each b, c, or d
//Swap the remain element for the remain 2
//when return then swap back the element essentially to backtrack to previous version

//My explaination might be a bit murkey
//If you can't understand it well then drawing a tree structure 
//From the recurstion is going to help 

void FindAllPermutation(string s, int l = 0){
    static int cnt = 1;
    if (l == 4) cout << cnt++ << "."<< s << " ";
    for(int i = l; i < 4; i++){
        swap(s[l], s[i]);
        FindAllPermutation(s, l + 1);
        swap(s[l], s[i]);
    }
}

int main(){
    int n = 10, x = 2, a = 200000, b = 20;
    cout << "1. Sum to " << n << ": " << FindSum (n) << endl;
    cout << "2. Factorial to " << n << ": " << FindFactorial(n) << endl;
    cout << "3. Exponential of " << x << "^" << n << ": " << FindExponential(x, n) << endl;
    cout << "4. Number of digit of " << a << ": " << FindNumberOfDigit(a) << endl;
    cout << "5. All digit is even " << a << "? " << IsAllDigitEven(a) << endl;
    cout << "6. Number of Common Divisor between " << a  << " and " << b << ": " << CountCommonDivisor(a, b) << endl;
    cout << "7.1. GCD: " << FindGCD(a, b) << endl;
    cout << "7.2. LCM: " << FindLCM(a, b) << endl;
    cout << "8. Reverese of " << b << " is: " << MakeReverse(b) << endl;
    cout << "9. Fibonacci to number " << n << " is " << FindFibonaci(2, 1, 0) << endl;
    cout << "10. All posible permutation of a b c d are: " << endl;
    FindAllPermutation("abcd");
}
