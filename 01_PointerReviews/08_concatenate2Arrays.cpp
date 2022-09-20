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

