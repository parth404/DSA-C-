#include <iostream>
#include <vector>
using namespace std;

int main(){
    int rows;
    int cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of cols: ";
    cin >> cols;



    // INPUT

    // Taking input for array row wise

    cout << "Enter Input for 2D Array" << endl;
    // Declare 2D array
    int arr[rows][cols];

    //row wise input
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> arr[i][j];
        }
    }
    

    //outer loop to traverse through each row
    vector<int> rowSum;
    for(int i=0; i<rows;i++){
        int sum = 0;
        // inner loop to traverse through each column element in a row
        for(int j=0; j<cols; j++){
            sum = sum + arr[i][j];
        }
        rowSum.push_back(sum);
    }

    // print sum of row elements
    cout << "Sum of each row element are" << endl;

    for(auto val:rowSum){
        cout << val << " ";
    }

    return 0;
}