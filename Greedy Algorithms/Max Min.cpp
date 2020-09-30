#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int unfairness=INT_MAX;
    int n=arr.size();
    for(int i=0; i<n-k+1; i++){
        unfairness=std::min(arr[i+k-1]-arr[i],unfairness);
    }
    return unfairness;

}
