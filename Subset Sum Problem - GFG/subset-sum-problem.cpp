// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
     bool t[n+1][sum+1];
      for(int j=0;j<=sum;j++){
         t[0][j]=false;
     }
     for(int i=0;i<=n;i++){
        t[i][0]=true;
      }
    
     for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            
        if(arr[i-1]<=j){
            t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
        }
        else {
            t[i][j]=t[i-1][j];
        }
        }
     }
    return t[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends