#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
    int n=c.size();
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    int sum=0;
    for(int i=0; i<n; i++){
        sum=sum+((i/k)+1)*c[i];
    }
    return sum;
}
