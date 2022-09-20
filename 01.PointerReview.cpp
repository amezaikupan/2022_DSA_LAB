#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int* a, int* b){
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}


int* sum(int* a, int* b){
    int s = *a + *b;
    int* ptr = &s;
    return ptr;
}


void printArray(int* a, int n){
    int i = 0;
    while(i < n){
        cout << *(a + i) << " ";
        i++;
    }
}


void inputArray(int* &a, int &n){
    cin >> n;

    a = new int[n];
    int i = 0;
    while (i < n){
        cin >> *(a + i);
        i++;
    }
}


int* findMax(int* a, int n){
    int i = 0;
    int max = -99999;
    
    while (i < n){
        if(a[i] > max) max = a[i];
        i++;
    }

    int* ptr = &max;
    return ptr;
}

int* findLongestAscendingSubArray(int* a, int n, int &length){
    //To track id and length of subarrays
    int maxID, maxLength = 1;

    //Set length value
    length = 1;

    //Case 01: If array is empty then return itself
    if(n == 0) return a;

    //To start loop
    int i = 1;
    while(i < n){        
        if(a[i - 1] < a[i]){
            //Check if subarray is ascending
            length++;
        }else{
            //If not ascending, check if the subarray is the longest
            if(length > maxLength){
                maxLength = length;
                maxID = i - length;
            }
            //Reset subarray
            length = 0;
        }
        i++;
    }

    //Case 02: If longest subarray include last memmber of array
    if(length > maxLength){
        maxLength = length;
        maxID = i - length;
    }
    
    int* ptr = &maxID;
    return ptr;
}

void swapArray(int* a, int* b, int &na, int &nb){
    //Swap array
    int* temp = a;
    a = b;
    b = temp;

    //Swap length 
    int nTemp = na;
    na = nb;
    nb = na;
}

int* concatenate2Arrays(int* a, int* b, int na, int nb){
    //create new array
    int* c = new int[na + nb];

    //add array a to c
    int i = 0;
    while(i < na){
        c[i] = a[i];
        i++; 
    }

    //add array b to c
    i = 0;
    while(i < nb){
        c[na + i] = b[i];
        i++;
    }

    //return c
    return c;
}

int* merge2Array(int* a, int* b, int na, int nb, int &nc){
    //Create merge array
    nc = na + nb;
    int* c = new int[nc];

    //To track index of array a and b and c
    int i = 0, j = 0, k = 0;

    //Merge members of array a and b to c
    while(i < na && j < nb){
        if(a[i] < b[j]){
            c[k] = a[i];
            i++;
        }else{
            c[k] = b[j];
            j++;
        }
        k++;
    }

    //Add left-over members of array a and b (if available)
    while(i < na) {
        c[k] = a[i];
        i++;
        k++;
    }

    while(j < nb){
        c[k] = b[j];
        j++;
        k++;
    }

    return c;
}

void generateMatrix1(int** &A, int &length, int &width){

    //input length and width
    cout << "Length: "; 
    cin >> length;

    cout << "Width: ";
    cin >> width;

    //Create array A with rows = length - cols = width
    A = new int*[length];

    int i = 0;
    while(i < length){
        A[i] = new int[width];
        i++;
    }

    //Generate random member values for matrix A
    i = 0;
    int j = 0;

    while(i < length){
        while(j < width){
            A[i][j] = rand() % 1000;
            j++;
        }
        i++;
        j = 0;
    }    
}

