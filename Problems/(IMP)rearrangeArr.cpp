//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	int left = 0;
    	int right = n - 1;
    	int operation = 1;
    // 	swap(arr[left], arr[right]);
    	while(left <= right){
    	    cout << left << " " << right << " " << operation << endl;
    	    swap(arr[left], arr[right]);
    	    if(operation == 1){
    	        right = n-1;  
    	    }else{
    	        right = n-2;
    	    }
    	    left+= 1;
    	    operation = !operation;
    	     
    	}
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends

----------------------------------------------------------------------------------------------------------------------------------------------------------
  
  //{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    {
        // Dividend = Divisor * Quotient + Remainder
        //            NewVal    MaxVal      OldVal
        // Remainder = Dividend % Divisor
        // Quotient = Dividend / Divisor
        int minInd = 0;
        int maxInd = n - 1;
        int quotient = arr[n - 1] + 1;
        for(int i = 0; i<n; i++){
            int divisor;
            if(i % 2 == 0){
                divisor = arr[maxInd] % quotient; 
                maxInd--;
            }else{
                divisor = arr[minInd] % quotient;
                minInd++;
            }
            int remainder = arr[i]; //OldVal
            arr[i] = remainder + divisor*quotient;
        }
        for(int i = 0; i<n; i++){
            int dividend = arr[i];
            int divisor = dividend / quotient; //NewVal
            arr[i] = divisor; 
        }
        
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends
