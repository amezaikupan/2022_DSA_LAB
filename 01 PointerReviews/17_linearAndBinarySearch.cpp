#include <iostream>
#include <cstdlib>

using namespace std;
//Problem 17 - 20
int LinearSearch(int* a, int n, int key){
    int i = 0;
    while (i < n){
        if(a[i] == key) return i;
        i++;
    }
    return -1;
}

int SentinelLinearSearch(int* a, int n, int key){
    int last = a[n - 1];
    a[n - 1] = key;

    int i = 0;
    while (a[i] != key) i++;

    //Return value of last to array
    a[n - 1] = last;

    if(i < n - 1) return i;
    else if(last == key) return n-1;
    else return -1;
}

int BinarySearch(int* a, int n, int key){
    int l = 0, r = n - 1;

    while(l <= r){
        int mid = l + (r - l)/2;
        if(a[mid] == key) return mid;
        else if(a[mid] < key) l = mid + 1;
        else r = mid - 1;
    }

    return -1;
}

int RecursiveBinanrySearch(int* a, int left, int right, int key){
    int mid = left + (right - left)/2;
    //Stop case 01: no key is found
    if(left == right) return -1;

    //Stop case 02: key is found in mid
    if(a[mid == key]) return mid;
    else if(a[mid] > key) return RecursiveBinanrySearch(a, left, mid - 1, key);
    else return RecursiveBinanrySearch(a, mid + 1, right, key);
}


int main(){
    int* a = new int[10];
    for (int i = 0; i < 10; i++) a[i] = i;
    

    cout << "Find item exist in array: " << endl;
    cout << "Linear Search: " << LinearSearch(a, 10, 4) << endl;
    cout << "Sentiel Linear Search: " << SentinelLinearSearch(a, 10, 4) << endl;
    cout << "Binanry Search: " << BinarySearch(a, 10, 4) << endl;
    cout << "Recursive Binary Search: " << RecursiveBinanrySearch(a, 0, 9, 4) << endl;

    cout << "Find item doesn't exist in array: " << endl;
    cout << "Linear Search: " << LinearSearch(a, 10, 14) << endl;
    cout << "Sentiel Linear Search: " << SentinelLinearSearch(a, 10, 14) << endl;
    cout << "Binanry Search: " << BinarySearch(a, 10, 14) << endl;
    cout << "Recursive Binary Search: " << RecursiveBinanrySearch(a, 0, 9, 14) << endl;

}
