//16: Find maxium sub matrix 
//Use Kadane algorithm for 2d matrix
//Refrence: https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/ 

void findSubmatrix(int** a, int length, int width, int &lres, int &wres){
    //01: Deine 
    //Calculate sum of array in 2d
    int* kadane = new int[width];
    
    //Find max sum
    int sum = -9999, maxSum = sum;

    //Find subarray location in original array
    int lRow = 0, rRow = 0, tCol = 0, bCol = 0, ftCol = 0, flRow = 0;
 
    //02: Find submatrix
    //Set left of sub-matrix
    for(int l = 0; l < width; l ++){
        
        //Create - Reset  kadane array
        for(int x = 0; x < width; x++) kadane[x] = 0;
 
        //Set right of sub-matrix
        for(int r = l; r < width; r++){
            
            //Add to Kadane array
            for(int i = 0; i < length; i++){
                kadane[i] += a[i][r];
            }
 
            //Use kadane algorithm on 1d array to find max sum
            for(int i = 0; i < length; i++){
                sum += kadane[i];
 
                //Check for top column and left row of sub array
                //If the sum is smaller than the sum than the subarray is cut at sum
                if(sum < kadane[i]){
                    sum = kadane[i];
                    tCol = l;
                    lRow = i;
                }
 
                //Check for max sum 
                //If is max sum then record bottom row and right row
                if(sum > maxSum){
                    //Reset max sum
                    maxSum = sum;

                    //Set final top column and final left row
                    ftCol = tCol;
                    flRow = lRow;

                    //Set bottom column and right row
                    rRow = i;
                    bCol = r;
                }
            }
            //Reset sum
            sum = 0;
        }
    }
 
    //Set size of sub array
    wres = flRow - rRow;
    lres = ftCol - bCol;

    //Print result
    cout << "Max Sub Array Sum is: " << maxSum << endl;
    cout << "Lelf-Top most point: " << flRow << ":" << ftCol << endl;
    cout << "Right-Bottom most point: " << rRow << ":" << bCol << endl;

    //Clean up array allocation
    delete kadane;
}
