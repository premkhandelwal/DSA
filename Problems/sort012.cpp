//{ Driver Code Starts
//Initial Template for C
// Dutch National Flag Algorithm variation
#include <stdio.h>


// } Driver Code Ends
//User function Template for C
void swap(int a, int b){
    
    
}
void sort012(int a[], int n)
{
    int low = 0, mid = 0, high = n -1;
    while(mid <= high){
        if(a[mid] == 0){
            // swap(a[mid], a[low]);
            int temp = a[mid];
            a[mid] = a[low];
            a[low] = temp;
            low += 1;
            mid += 1;
        }else if(a[mid] == 2){
            swap(a[mid], a[high]);
            int temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;
            high -= 1; 
        }else{
            mid += 1;
        }
    }
}

//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends
