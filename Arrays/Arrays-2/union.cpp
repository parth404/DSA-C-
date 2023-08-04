// Union of two arrays

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[] = {2,2,3,1,0};
    int sizea = 5;
    int brr[] = {2,4,3,3};
    int sizeb = 4;


    vector<int> ans;

    for(int i=0; i<sizea; i++){
    // push all items of arr
        ans.push_back(arr[i]);
    // mark duplicate items on second array as int_min
        for(int j=0; j<sizeb; j++){
            if (arr[i] == brr[j]){
                brr[j] = INT8_MIN;
                break;
            }
        }
    }

    // push unique items of brr
    for(int i=0; i<sizeb; i++){
    // check if items are marked before pushing to result array
        if(brr[i] != INT8_MIN){
            ans.push_back(brr[i]);
        }
    }

    // print result array
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}