#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

//function to count items
// int countItem(int arr[], int size, int key){
//     //linear search to count key occurence
//     int count = 0;
//     for(int i=0; i<size; i++){
//         if(arr[i] == key){
//             count++;
//         }
//     }
//     return count;
// }

// int max(int arr[], int size){
//     int maxitem = INT_MIN;
//     for(int i=0; i<size; i++){
//         if(arr[i] > maxitem){
//             maxitem = arr[i];
//         }
//     } 
//     return maxitem;
// }

int main(){

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// take 5 items as input in array and print their doubles    
    // int n = 5;
    // int arr[n];
    // //take ninput for array
    // for(int i=0; i<n; i++){
    //     cout << "enter array item " << i+1 << ": ";
    //     cin >> arr[i];
    //     cout << endl;
    // }
    // //print array elements
    // cout << "doubles of array items are : ";
    // for(int i=0; i<n; i++){
    //     cout << 2*arr[i] << " ";
    // }

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//count 0s and 1s in array
// int n;
// cout << "Enter size of array: ";
// cin >> n ;
// cout<< "Enter array elements: ";
// int arr[n];
// for(int i=0; i<n; i++){
//     cout << "Enter value for item number " << i+1 << ": ";
//     cin >> arr[i];
//     }
// int zeros = countItem(arr, n, 0);
// int ones = countItem(arr, n, 1);
// //print result
// cout << "The array has " << zeros << " 0s & " << ones << " 1s";

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// //Find max number in ana array
// int n;
// cout << "Enter size of array: ";
// cin >> n ;
// cout<< "Enter array elements: ";
// int arr[n];
// for(int i=0; i<n; i++){
//     cout << "Enter value for item number " << i+1 << ": ";
//     cin >> arr[i];
//     }
// int ans = max(arr, n);
// //print result
// cout << "The Max number is " << ans;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Find Extremes in Array
// int n;
// cout << "Enter size of array: ";
// cin >> n ;
// cout<< "Enter array elements: ";
// int arr[n];
// for(int i=0; i<n; i++){
//     cout << "Enter value for item number " << i+1 << ": ";
//     cin >> arr[i];
//     }
// int start = 0;
// int end = n -1;
// while(start <= end){
//     if(start > end){
//         break;
//     }
//     if(start == end){
//         cout << arr[start] << " ";
//     }
//     else {
//         cout << arr[start] << " ";
//         cout << arr[end] << " ";
//     }
//     start++;
//     end--;
//     }

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Reverse an Array
int n;
cout << "Enter size of array: ";
cin >> n ;
cout<< "Enter array elements: ";
int arr[n];
for(int i=0; i<n; i++){
    cout << "Enter value for item number " << i+1 << ": ";
    cin >> arr[i];
    }
//reverse array items
int end = n-1;
int ans[n];
for(int i=0; i<n; i++){
    ans[i] = arr[end];
    end--;
}
cout << "reversed array is:" << endl;
for(int i=0; i<n; i++){
    cout << ans[i] << " ";
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//VECTORS
// int n;
// cout << "Enter size: ";
// cin >> n;
// vector<int>arr(n);
// vector<int>arr;// int ans = (sizeof(arr)/sizeof(int));
// // cout << ans << endl;
// cout << arr.size()<<endl;
// cout << arr.capacity()<<endl;

// //insert
// arr.push_back(5);
// arr.push_back(6);
// //remove
// arr.pop_back();
// //print vector
// for(int i=0; i<arr.size(); i++){
//     cout << arr[i] << " "; 
// }
}