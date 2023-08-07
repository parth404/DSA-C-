// Sort 0's and 1's

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr{0, 1, 0, 1, 1, 0, 1, 0, 1, 1};

    int start = 0;
    int end = arr.size() - 1;
    int i = 0;

// traverse through array

    while(i != end){
        if(arr[i] == 0){
            //swap from left
            swap(arr[start], arr[i]);
            i++;
            start++;
        }
        else if(arr[i] == 1){
            //swap from right
            swap(arr[i], arr[end]);
            end--;
        }
    }
    cout << "sorted array is " << endl;
    // print result array
    for(auto value:arr){
        cout << value << " ";
    }

    return 0;
}