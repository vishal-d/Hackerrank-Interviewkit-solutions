#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
int count=0; 
string sub;
unordered_map<string,int> umap;
for(int i=1; i<s.length(); i++){
    //for anagram substring should be of equal size
    //and the frequency of character in the substring should be equal
    //therfore we find all the substrings of the string and map their sorted
    //character frequency to their values as keys and frequency as pair
    for(int j=0; j<=s.length()-i; j++){
        sub=s.substr(j,i);
        sort(sub.begin(),sub.end());
        int len=sub.length();
        umap[sub]++;
    }
}
for(auto&el1:umap){
    if(el1.second>=2){
        count=count+(el1.second*(el1.second-1)/2);
    }
}
return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
