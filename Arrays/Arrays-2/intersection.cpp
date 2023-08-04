// Intersection of two arrays

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr{1,2,3,6,6,3,3,4,6,8};
    vector<int> brr{3,3,4,6,10};

    vector<int> ans;

    for(int i=0; i<arr.size(); i++){
        // current element in loop
        int element = arr[i];
        for(int j=0; j<brr.size(); j++){
            // check if current element in arr is equal to element in brr
            if(element == brr[j]){
                // mark element in brr with int_min to avoid duplicates
                brr[j] = INT8_MIN;
                ans.push_back(element);
                break;
            }
        }
    }

    cout << "intersection array is " << endl;
    // print result array
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}