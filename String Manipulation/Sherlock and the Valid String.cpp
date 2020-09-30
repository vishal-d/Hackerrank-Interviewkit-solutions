#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int frequency[256];
    memset(frequency,0,sizeof(frequency));
    int fill;
    for(int i=0; i<s.length(); i++){
        fill=s[i];
        frequency[fill]++;
    }
    sort(frequency, frequency + 256);
    int i=0;
    //string answer;
    while(frequency[i]==0){
        i++;
    }
    int min=frequency[i];
    int max=frequency[255];
    for(int j=i; j<256; j++){
        cout<<"j="<<j<<" = "<<frequency[j]<<"\n";
    }
    cout<<"\n";
    int mincount=0;
    int maxcount=0;
    for(int i=0; i<256; i++){
        if(frequency[i]==min){
            mincount++;
        }
        if(frequency[i]==max){
            maxcount++;
        }
    }
    cout<<"Min count is "<<mincount<<"\n";
    cout<<"Max count is "<<maxcount<<"\n";
    cout<<"Min number is "<<min<<"\n";
    cout<<"Max number is "<<max<<"\n";
    if(min==max ||
      (max-min==1&&maxcount==1) ||
      (max-min==1&&mincount==1) || 
      (mincount==1 && min==1 && max==frequency[i+1]) ){
        return "YES";   
    }
    /*if(max-min==1 && maxcount==1){
        return "YES";
    }
    if(max-min==1 && mincount==1){
        return "YES";
    }*/
    else{
        return "NO";
    }

    
  
    //return answer;
}
