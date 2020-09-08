#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
//ref: discussion panel.
int get_twice_median(vector<int> &A, vector<int> &count, int d){
        vector<int> countf(count);
        for(int i=1; i<countf.size(); i++){
            countf[i]=countf[i]+countf[i-1];
        }
        int a=0;
        int b=0;
        int twice_median;
        if(d%2==0){ // a+b/2
            int first=d/2;
            int second=first + 1;
            for(int i=0; i<201; i++){
                if(first<=countf[i]){
                    a=i;
                    break;
                }
            }
            for(int i=0;i<201; i++){
                if(second<=countf[i]){
                    b=i;
                    break;
                }
            }
        }
        else{// a+0/2
            int first=d/2 + 1;
            for(int i=0; i<201; i++){
                if(first<=countf[i]){
                    a=2*i;
                    break;
                }
            }
        }
        twice_median=a+b;
        return twice_median;
}
int activityNotifications(vector<int> expenditure, int d) {
    int n=expenditure.size();
    vector<int> count(201,0);
    for(int i=0; i<d; i++){
        count[expenditure[i]]++;
    }
    int alert=0;
    for(int i=d; i<n; i++){
        if(expenditure[i]>=get_twice_median(expenditure,count,d)){
            alert++;
        }
        count[expenditure[i]]++;
        count[expenditure[i-d]]--;

    }
    return alert;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
