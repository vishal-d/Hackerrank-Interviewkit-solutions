#include <bits/stdc++.h>

using namespace std;
int arr[5005][5005];
// Complete the commonChild function below.
int commonChild(string s1, string s2) {
for(int i=0; i<5005; i++){
        arr[i][0]=0;
        arr[0][i]=0; 
}
for(int i=0; i<s1.length(); i++){
    for(int j=0; j<s2.length(); j++){
        if(s1[i]==s2[j]){
            arr[i+1][j+1]=arr[i][j]+1;
        } else{
            arr[i+1][j+1]=max(arr[i+1][j],arr[i][j+1]);
        }
    }
}

return arr[s1.length()][s2.length()];
}
