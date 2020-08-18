#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int count;
    count=0;
    int sea_level=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='U'){
            sea_level++;
        }
        else if(s[i]=='D'){
            sea_level--;
        }

        if(sea_level==0 && s[i]=='U'){
            count++;
        }
    }

return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
