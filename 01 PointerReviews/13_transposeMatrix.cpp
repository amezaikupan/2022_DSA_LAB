//Problem 13
int** transposeMatrix (int** a, int length, int width){
    //Make array b
    int** b = new int*[width];

    for (int i = 0; i < width; i++) b[i] = new int[length];

    //Make b transpose matrix of a
    //Track index of a
    int x = 0, y = 0;

    for (int i = 0; i < width; i++){
        for (int j = 0; j < length; j++){ 
            b[i][j] = a[x][y];
            cout << b[i][j] << " " ;
            x++;
        }
        cout << endl;
        x = 0;
        y++;
    }
    return b;
}


