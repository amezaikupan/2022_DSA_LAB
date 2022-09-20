void inputArray(int* &a, int &n){
    cin >> n;

    a = new int[n];
    int i = 0;
    while (i < n){
        cin >> *(a + i);
        i++;
    }
}


