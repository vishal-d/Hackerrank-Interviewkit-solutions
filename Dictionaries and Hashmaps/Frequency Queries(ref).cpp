#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
//ref: https://www.youtube.com/watch?v=2epG6DYeKGU&t=214s
vector<int> freqQuery(vector<vector<int>> queries) {
    unordered_map<long,long> umap;
    unordered_map<long,long> freq;
    int ans;
    long n=queries.size();
    vector<int> result;
    for(long i=0; i<n; i++){
        if(queries[i][0]==1){//insert x
            freq[ umap[queries[i][1]] ]--;
            umap[queries[i][1]]++;
            freq[ umap[queries[i][1]] ]++;
            continue;
        }
        else if(queries[i][0]==2){//delete one y
             if(umap[queries[i][1]]==0){
                 continue;
             }
             else{
                    freq[ umap[queries[i][1]] ]--;
                    umap[queries[i][1]]--;
                    freq[ umap[queries[i][1]] ]++;
             }
        }
        else if(queries[i][0]==3){//if frequency is z print 1 else 0
            ans=0;
            if(freq[queries[i][1]]>0){
                ans=1;
            }
            /*for(auto&el1:umap){
                if(el1.second==queries[i][1]){
                    ans=1;
                    break;
                }
            }*/
            result.push_back(ans);
            continue;
            //cout<<ans<<"\n";
        }
        
    }
    
    //cout<<ans;
    return result;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
