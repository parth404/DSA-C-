// Find a pair that upon addition gives value equal to sum

#include <iostream>
#include <vector>
using namespace std;

int main(){
    // vector<int> arr{1,3,5,7,2,4,6};
    // int sum = 9;
    // // vector<int> brr{3,3,4,6,10};

    // vector<int> ans;

    // for(int i=0; i<arr.size(); i++){
    //     // current element in loop
    //     int element = arr[i];
    //     // Traverse through all elements and add with current element to  find pair sum
    //     for(int j=i+1; j<arr.size(); j++){
    //         if(element + arr[j] == sum){
    //             ans.push_back(element);
    //             ans.push_back(arr[j]);
    //         }
    //     }
    // }


// ---------------------------------------------------------------------------------------------------------------------------
    
// Find triplet sum

    // vector<int> arr{10,20,30,40};
    // int sum = 80;
    // // vector<int> brr{3,3,4,6,10};

    // vector<int> ans;

    // for(int i=0; i<arr.size(); i++){
    //     // current element in loop
    //     int firstElement = arr[i];
    //     // Traverse through all elements and add with current element to  find pair sum
    //     for(int j=i+1; j<arr.size(); j++){
    //         for(int k=j+1; k<arr.size(); k++){
    //             if(firstElement + arr[j] + arr[k] == sum){
    //                 ans.push_back(firstElement);
    //                 ans.push_back(arr[j]);
    //                 ans.push_back(arr[k]);
    //             }
    //         }
    //     }
    // }

    // cout << "pair sum array is " << endl;
    // // print result array
    // for(int i=0; i<ans.size(); i++){
    //     cout << ans[i] << " ";
    // }


// ---------------------------------------------------------------------------------------------------------------------------
    
// Find quadruplet sum


    vector<int> arr{40, 10, 2, 8, 20, 30, 1, 2, 4};
    int sum = 100;
    // vector<int> brr{3,3,4,6,10};

    vector<int> ans;

    for(int i=0; i<arr.size(); i++){
        // current element in loop
        int firstElement = arr[i];
        // Traverse through all elements and add with current element to  find pair sum
        for(int j=i+1; j<arr.size(); j++){
            for(int k=j+1; k<arr.size(); k++){
                for(int l=k+1; l<arr.size(); l++){
                    if(firstElement + arr[j] + arr[k] + arr[l] == sum){
                        ans.push_back(firstElement);
                        ans.push_back(arr[j]);
                        ans.push_back(arr[k]);
                        ans.push_back(arr[l]);
                    }
                }
            }
        }
    }

    cout << "quadruplet sum array is " << endl;
    // print result array
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}