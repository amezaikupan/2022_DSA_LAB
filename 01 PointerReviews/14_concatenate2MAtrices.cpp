//Problem 14
//Input: 
//a and b are square matrices
//length and width are of a and b
//lres and lwid are of return matrix
int** concatenate2MatricesH(int** a, int** b, int length, int width, int &lres, int &wres){
    //Create matrix c
    lres = 2 * length;
    wres = width;

    int** c = new int*[lres];
    for (int i = 0; i < lres; i++) c[i] = new int[wres];

    //Concatenate a and b -> c
    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            c[i][j] = a[i][j];
        }
    }

    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            c[i + length][j] = b[i][j];
        }
    }
    return c;
}

int** concatenate2MatricesW(int** a, int** b, int length, int width, int &lres, int &wres){
    //Create matrix c
    lres = length;
    wres = 2 * width;
    
    int** c = new int*[lres];
    for (int i = 0; i < lres; i++) c[i] = new int[wres];

    //Concatenate a and b -> c
    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            c[i][j] = a[i][j];
        }
    }

    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            c[i][j + width] = b[i][j];
        }
    }
    return c;
}

