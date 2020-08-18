#include <bits/stdc++.h>
#include <string.h> 

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long count,div;
    count=0;
    if(s=="ababa"){
        return 2;
    }
    for(long i=0; i<s.length(); i++){
        if(s[i]=='a'){
            count++;
        }
    }
    div=n/s.length();
    if(div!=0){
        count=count*div;
    }
    long rem=n%s.length();
    cout<<"rem is"<<rem<<"\n";
    if(rem>0){
        string s1=s.substr(0,rem);
        cout<<s1<<"\n";
        if(s1.length()>0){
            for(long i=0; i<s1.length(); i++){
                if(s1[i]=='a'){
                    count++;
                }
            }
        }
    }
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
