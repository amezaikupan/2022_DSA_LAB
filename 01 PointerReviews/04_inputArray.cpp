//Problem 16: 
//04: Input array of unknow n size
void inputArray(int* &a, int &n){

    //Approach: Input the member of array to a really large
    //allocated space -> copy to all member to array of size n
    //and delete the big array

    //Innitital asignment of n
    n = 0;

    //Big array allocation
    int* temp = new int[10000];

    //Input in array and check for end point - invalid input
    cout << "Input array: " << endl;

    do{
        if(cin >> temp[n]) n++;
        else{
            cin.clear();
            cin.ignore();
            cout << "Stop input" << endl;
            break;
        }

    }while (true);
    
    //Allocate space for array a now that we know the size of the array
    a = new int[n];

    //Copy element from temp to a
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }

    delete temp;
    
}