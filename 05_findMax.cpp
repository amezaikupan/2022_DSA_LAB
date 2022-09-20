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

