#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int count=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='A'){
            if(s[i+1]=='A'){
                count++;
                //i++;
                continue;
            }
        }
        if(s[i]=='B'){
            if(s[i+1]=='B'){
                count++;
                //i++;
                continue;
            }
        }
    }
    return count;
}
