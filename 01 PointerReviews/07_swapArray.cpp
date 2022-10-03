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

