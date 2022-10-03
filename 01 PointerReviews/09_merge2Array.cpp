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

    //No array allocation to clean up
    return c;
}

