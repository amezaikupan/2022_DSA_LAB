//Problem 12:
//How to change the value of a if not use a pass by reference 
void swapRows (int** &a, int length, int width, int ir1, int ir2){
    for (int i = 0; i < width; i++){
        int temp = a[ir1][i];
        a[ir1][i] = a[ir2][i];
        a[ir2][i] = temp; 
    }
}

void swapColumns (int** &a, int length, int width, int ir1, int ir2){
    for (int i = 0; i < length; i++){
        int temp = a[i][ir1];
        a[i][ir1] = a[i][ir2];
        a[i][ir2] = temp;
    }
}

