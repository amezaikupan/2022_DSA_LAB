//Problem 15: bruce force approach
bool multiple2Matrices (int** &res, int** a, int** b, int &lengthr, int &widthr, int lengtha, int widtha, int lengthb, int widthb){
    //Create res matrix
    lengthr = lengtha;
    widthr = widthb;

    res = new int*[lengthr];
    for(int i = 0; i < lengthr; i++) res[i] = new int[widthr];

    //Multiply a * b -> res
    for(int i = 0; i < lengthr; i++){
        for(int j = 0; j < widthr; j++){
            int temp  = 0;
            for(int x = 0; x < widtha; x++ ){
                temp += a[i][x] * b[x][j];
            }
            res[i][j] = temp;
        }
    }

    //No array allocation to clean up
}

