//6: Find the longest ascending subarray
int* findLongestAscendingSubArray(int* a, int n, int &length){
    //To track id and length of subarrays
    int maxID, maxLength = 1;

    //Set length value
    length = 1;

    //Case 01: If array is empty then return itself
    if(n == 0) return a;

    //To start loop
    int i = 1;
    while(i < n){        
        if(a[i - 1] < a[i]){
            //Check if subarray is ascending
            length++;
        }else{
            //If not ascending, check if the subarray is the longest
            if(length > maxLength){
                maxLength = length;
                maxID = i - length;
            }
            //Reset subarray
            length = 0;
        }
        i++;
    }

    //Case 02: If longest subarray include last memmber of array
    if(length > maxLength){
        maxLength = length;
        maxID = i - length;
    }
    
    //Return longest subarray
    int* res = new int[length];

    for (int i = 0; i < length; i++)
    {
        res[i] = a[maxID + i];
    }

    //No array allocation to clean up
    return res;
}