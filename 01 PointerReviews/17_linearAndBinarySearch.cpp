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

