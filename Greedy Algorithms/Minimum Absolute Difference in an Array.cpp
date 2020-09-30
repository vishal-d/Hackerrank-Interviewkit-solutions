#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int min=abs(arr[0]-arr[n]);
    int diff;
    //int circular_diff;
    for(int i=0; i<n-1; i++){
        diff=abs(arr[i]-arr[i+1]);
        //circular_diff=abs(arr[0]-arr[n]);
        min=std::min(diff,min);
        
    }
    return min;

}
