#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    int n=contests.size();
    sort(contests.begin(),contests.end());
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cout<<contests[i][j]<<" ";
        }
        cout<<endl;
    }
    //k games toh loose krne hi hia important wale
    int important_match=0;
    for(int i=0; i<n; i++){
        if(contests[i][1]==1){
            important_match++;
        }
    }
    int sum=0;
    for(int i=0; i<n; i++){
        sum=sum+contests[i][0];
     }
     cout<<"sum is "<<sum; 
    if(k>=important_match){
        return sum;  
    }
    
    else if(k<important_match){
        int test=important_match-k;
        for(int i=0; i<n; i++){
            if(contests[i][1]==1){
                cout<<"\nTo delete "<<contests[i][0];
                sum=sum-(2*contests[i][0]);
                test--;
                if(test==0){
                    return sum;
                }

            }
        }
    }

    return -1;

}
