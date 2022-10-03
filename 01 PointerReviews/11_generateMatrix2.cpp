//What is the role of nc in this &nc
int** generateMatrix2(int* a, int* b, int na, int nb, int &nc){
    //Create 2d matrix
    int** c = new int*[na];

    int i = 0, j = 0;
    while (i < na){
        c[i] = new int[nb];
        i++;
    }

    //Generate matrix c that c[i][j] = a[i] * [j]
    i = 0;
    while (i < na){
        while (j < na){
            c[i][j] = a[i] * b[j];
            j++;
        }
        i++;
        j = 0;
    }
    return c;
}

