#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
    int n=cost.size();
    unordered_map<int,int> umap;
    int balance;
    int num;
    /*for(int i=0; i<n; i++){
        umap[cost[i]]=i;
    }
    for(int i=0; i<n; i++){
        cout<<umap[cost[i]]<<" ";
    }
    cout<<endl;*/
    for(int i=0; i<n; i++){
        balance=money;
        num=balance-cost[i];
        if(umap.find(num)!=umap.end()){
            cout<<umap[num]+1<<" "<<i+1<<endl;
            break;
        }
        else{
            umap[cost[i]]=i;
        }
    }
}
