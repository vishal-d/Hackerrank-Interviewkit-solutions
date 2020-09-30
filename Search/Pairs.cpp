#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the pairs function below.
int pairs(int k, vector<int> arr) {
    int n=arr.size();
    unordered_map<int,int> umap;
    int count=0;
    for(int i=0; i<n; i++){
        umap[arr[i]]++;
    }
    for(int i=0; i<n; i++){
        int num=k+arr[i];
        if(umap.find(num)!=umap.end()){
            count++;
        }
    }
    return count;
}
