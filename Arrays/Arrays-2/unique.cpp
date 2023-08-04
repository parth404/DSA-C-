// Find unique element in an array(for series like 1,1,2,3,3,4,4 only!!)

#include <iostream>
#include <vector>
using namespace std;

//Function to find unique element
int findUnique(vector<int> arr){
    int ans = 0;

//Using XOR to compare all elements
    for(int i=0; i<arr.size(); i++){
        ans = ans ^ arr[i];
    }

    return ans;
}

int main (){

    int n;
    cout << "Enter array size " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of the array " << endl;
    // taking input
    for(int i=0; i<arr.size(); i++){
        cin >> arr[i];
    }

    //Function to find unique element
    int uniqueElement = findUnique(arr);

    cout << "Unique element is " << uniqueElement << endl;


    return 0;

}