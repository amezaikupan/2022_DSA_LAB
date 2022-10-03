void generateMatrix1(int** &A, int &length, int &width){

    //input length and width
    cout << "Length: "; 
    cin >> length;

    cout << "Width: ";
    cin >> width;

    //Create array A with rows = length - cols = width
    A = new int*[length];

    int i = 0;
    while(i < length){
        A[i] = new int[width];
        i++;
    }

    //Generate random member values for matrix A
    i = 0;
    int j = 0;

    while(i < length){
        while(j < width){
            A[i][j] = rand() % 1000;
            j++;
        }
        i++;
        j = 0;
    }    
}

