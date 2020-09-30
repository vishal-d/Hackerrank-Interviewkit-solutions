#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
 
    a.erase(unique(a.begin(),a.end()),a.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    
    long i = 0, j = 0, k = 0;
    long sol=0;
    long n1=0,n2=0;
    for(i=0; i<b.size(); i++){
    
        while(a[j]<=b[i] && j<a.size()){
            j++;
        }
        while(c[k]<=b[i]&& k<c.size()){
            k++;
        }
       
        sol+=(j*k);
    }
    return sol;


}
