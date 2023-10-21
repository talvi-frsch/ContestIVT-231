#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int count_first;
    int count_second;

    cin >> count_first;
    vector<int> first(count_first);

    for (int i = 0; i < count_first; i++) {
        cin >> first[i];
    }

    cin >> count_second;
    vector<int> second(count_second);

    for (int i = 0; i < count_second; i++) {
        cin >> second[i];
    }
    
    //for (int i = 0; i < first.size(); i++) {
    //    cout << first[i] << " ";
    //}
    //cout << endl;
    //for (int i = 0; i < second.size(); i++) {
    //    cout << second[i] << " ";
    //}
    //cout << endl;

    int count_result = count_first + count_second;
    // if (first.size() < second.size()) {
    //    first.resize(second.size());
    // }
    // else {
    //    second.resize(first.size());
    // }
    //int j = 0, k = 0;
    //vector<int> result(count_result);
    //for (int i = 0; i < count_result; i++) {
    //    if (first[i] < second[j]) {
    //        result[i++] = first[i++];
    //    }
    //    if (first[i] > second[j]) {
    //        result[i++] = second[j++];
    //    }
    //}
    
    int result[count_result];

    for (int i = 0; i < count_first; i++) {
        result[i] = first[i];
    } 

    int k = 0;
    for (int j = count_first; j < count_result; j++) {
        result[j] = second[k];
        k++;
    }
    
    sort(result, result + count_result);    

    for (int i = 0; i < count_result; i++) {
        cout << result[i] << " ";    
    }
}
