#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minTime function below.
long minTime(vector<long> machines, long goal) {
    sort(machines.begin(),machines.end());
    long n = machines.size();
    long upperbound=goal*machines[n-1];
    long lowerbound=1;
    long result=0;
    while(lowerbound!=upperbound){
        long mid=(upperbound+lowerbound)/2;
        long total=0;
        for(long i=0; i<n; i++){
            total+=floor(mid/machines[i]);
        }
        if(total >= goal){
            result=mid;
            upperbound=mid;
        }else{
            lowerbound=mid+1;
        }
    }
    return lowerbound;

}
