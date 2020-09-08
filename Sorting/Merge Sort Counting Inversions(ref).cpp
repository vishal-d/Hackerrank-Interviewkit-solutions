#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countInversions function below.
long merge(vector<int>& arr, int l, int m, int r) 
{
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    long count=0;

    /* create temp arrays */
    int L[n1], R[n2]; 

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
            count=count+(n1-i);
        } 
        k++; 
    } 

    /* Copy the remaining elements of L[], if there 
    are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    /* Copy the remaining elements of R[], if there 
    are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    return count;
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
long mergeSort(vector<int>&arr, int l, int r) 
{ 
    long icount=0;
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
        
        // Sort first and second halves 
        icount=icount+mergeSort(arr, l, m); 
        icount=icount+mergeSort(arr, m + 1, r); 

        icount=icount+merge(arr, l, m, r); 
    } 
    return icount;
} 
long countInversions(vector<int> arr) {
    int n=arr.size();

    return mergeSort(arr,0,n-1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

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
