#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int frequencya[256];
    int frequencyb[256];
    memset(frequencya,0,sizeof(frequencya));
    memset(frequencyb,0,sizeof(frequencyb));
    int count=0;
    int convert;
    for(int i=0; i<a.length(); i++){
        convert=a[i];
        cout<<convert<<" ";
        frequencya[convert]++;
    }
    for(int i=0; i<b.length(); i++){
        convert=b[i];
        cout<<convert<<" ";
        frequencyb[convert]++;
    }
    for(int i=0; i<256; i++){
        if(frequencya[i]!=frequencyb[i]){
            count=count+abs(frequencya[i]-frequencyb[i]);
        }
    }
    return count;

}
