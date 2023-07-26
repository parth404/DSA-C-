#include <iostream>
using namespace std;

int main(){
    // int rows;
    // int cols;
    // cout << "rows :";
    // cin >> rows;
    // cout << "columns :";
    // cin >> cols;

    // ************* Print rectangle with input ***************
    // for(int i=0; i< rows; i++){
    //     for(int j=0; j< cols; j++){
    //     cout << "* ";
    //     }
    //     cout << endl;
    // }

    // ************* Print hollow rectangle with input ***************
    // for(int i=0; i<rows; i++){
    //     if(i==0 || i==rows-1){
    //         for(int j=0; j<cols; j++){
    //             cout<< "* ";
    //         }
    //     } else {
    //         for(int j=0; j<cols; j++){
    //             if(j==0 || j==cols-1){
    //                 cout<<"* ";
    //             } else {
    //                 cout << "  ";
    //             }
    //         }
    //     }
    //     cout << endl;
    // }

    // ************* Print half pyramid with input ***************
    // for(int i=0; i<rows; i++){
    //     for(int j=0; j<=i; j++){
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }
    

    // ************* Print inverted half pyramid with input ***************
    // for(int i=0; i<=rows; i++){
    //     for(int j=0; j<=rows - i; j++){
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // ************* Print numeric half pyramid with input ***************
    // for(int i=0; i<rows; i++){
    //     for(int j=1; j<=i+1; j++){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }   
    
    // ************* Print numeric full pyramid with input ***************
    // for(int i=0; i<rows; i++){
    //     for(int j=1; j<=(rows - i); j++){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // ************* Print full pyramid with input ***************     
    // for(int i=1; i<=rows; i++){
    //     for(int j=0; j<rows-i; j++){
    //         cout << " ";
    //     }
    //     for(int k=0; k<i; k++){
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // ************* Print inverted full pyramid with input ***************     
    // for(int i=0; i<=rows; i++){
    //     for(int j=0; j<i; j++){
    //         cout << " ";
    //     }
    //     for(int k=0; k<rows-i; k++){
    //         cout << k+1 << " ";
    //     }
    //     cout << endl;
    // }    



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    //debugging problems

    // int n;
    // cin>>n;
    // for(int i=0;i<n;++i){
    //     for(int j=1;j<=n;j++){
    //         if(j==1 || j == n - i || i==0){
    //             cout<<j;
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// print hollow diamond pattern
    // int n;
    // cin>>n;

    // // outer loop for upper half
    // for(int rows = 0; rows<n; rows++){
    //     // inner loop for spaces
    //     for(int cols = 0; cols < n-rows - 1 ; cols++){
    //         cout << " ";
    //         }
    //     // inner loop for stars
    //     for(int j = 0; j < 2*rows + 1; j++){
    //         if(j==0 || j==2*rows){
    //             cout <<"*";
    //         }else {
    //             cout << " ";
    //         }
    //     }
        
    //     // inner loop for spaces
    //     // for(int cols =0; cols <)
    //     cout << endl;
    // }
    // //outer loop for bottom half
    // for(int rows = 0; rows<n; rows++){
    //     // inner loop for spaces
    //     for(int cols = 0; cols < rows; cols++){
    //         cout << " ";
    //         }
    //     // inner loop for stars
    //     for(int j = 0; j < 2*n-2*rows-1; j++){
    //         if(j==0){
    //             cout <<"*";
    //         }else if(j==2*n-2*rows-2){
    //             cout << "*";
    //         } else {
    //             cout << " " ;
    //         }
    //     }
        
    //     // inner loop for spaces
    //     // for(int cols =0; cols <)
    //     cout << endl;
    // }

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// print flipped solid diamond
    // int n;
    // cin>>n;

    // //print first part of upper half
    
    // //print half pyramid stars
    // for(int rows=0; rows<n; rows++){
    //     for(int cols=0; cols<n-rows; cols++){
    //         cout << "*";
    //     }
    //     //print full pyramid spaces
    //     for(int cols=0; cols<2*rows+1; cols++){
    //         cout << " ";
    //     }
    //     //print half pyramid stars
    //     for(int cols=0; cols<n-rows; cols++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // //print first part of bottom half
    // for(int rows=0; rows<n; rows++){
    //     //print inverted half pyramid stars
    //     for(int cols=0; cols<rows+1; cols++){
    //         cout << "*";
    //     }
    //     //print inverted full pyramid spaces
    //     for(int cols=0;cols<2*n-2*rows -1;cols++){
    //         cout << " ";
    //     }
    //     //print inverted half pyramid stars
    //     for(int cols=0; cols<rows+1; cols++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// print the following pattern
//   1
//   2*2
//   3*3*3
//   4*4*4*4
//   4*4*4*4
//   3*3*3
//   2*2
//   1

    // int n;
    // cin>>n;

    // //Print upper half
    // for(int rows=0; rows<n; rows++){
    //     for(int cols=0; cols<rows+1; cols++){
    //         if(cols==rows){
    //             cout << rows+1;
    //         } else {
    //             cout << rows+1; cout << "*";
    //         }
    //     }
    //     cout << endl;
    // }
    // //Print lower half
    // for(int rows=0; rows<n; rows++){
    //     for(int cols=0; cols<n-rows; cols++){
    //         if(cols==n-rows-1){
    //             cout << n-rows;
    //         } else {
    //             cout << n-rows; cout << "*";
    //         }
    //     }
    //     cout << endl;
    // }

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// print alphabet palindrome pyramid
//   A
//   ABA
//   ABCBA
//   ABCDCBA
//   ABCDEDCBA

    // int n;
    // cin>>n;

    // //Outer loop for rows
    // for(int rows=0; rows<n; rows++){
    //     //inner loop for columns
    //     for(int cols=0; cols<rows+1; cols++){
    //         int ans = cols + 1;
    //         char ch = ans + 'A' - 1;
    //         cout << ch;
    //     }
    //     //add reverse colums for pallindrome
    //     for(int cols=0; cols < rows; cols++){
    //         int ans = rows - cols;
    //         char ch = ans + 'A' - 1;
    //         cout << ch;
    //     }
    //     cout << endl;
    // }

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// print numeric full pyramid
//        1        
//      2 3 2      
//    3 4 5 4 3    
//  4 5 6 7 6 5 4  
//5 6 7 8 9 8 7 6 5

    // int n;
    // cin>>n;

    // //outer loop for rows
    // for(int rows=0; rows<n; rows++){
    //     //inner loop for columns
    //     //loop for spaces
    //      for(int cols=0; cols<(n-rows)-1; cols++){
    //         cout << ".";
    //     }       
    //     //loop for numbers
    //     // int start = rows +1;
    //     for(int cols=0; cols<rows+1; cols++){
    //         cout << rows + cols + 1;
    //         // start = start + 1;
    //     }
    //     //loop for reverse counting
    //     int start = 2*rows;
    //     for(int cols=0; cols<rows; cols++){
    //         cout << start;
    //         start = start - 1;
    //     }        
    //     cout << endl;
    // }

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// print numeric hollow pyramid
//     1        
//    1 2      
//   1   3    
//  1     4  
// 1 2 3 4 5

    int n;
    cin>>n;

    //outer loop for rows
    for(int rows=0; rows<n; rows++){
        //inner loop for columns
        //loop for spaces
        for(int cols=0; cols<n-rows-1; cols++){
            cout << " ";
        }
        //loop for column elements, elements increase as prime number pattern 1,3,5,7...
        int start = 1;
        for(int cols=0; cols<2*rows+1; cols++){
            //printing elements for first and last row
            if(rows==0 || rows==n-1){
                //for last row print elements and spaces, elements are printed at every even interval hence:
                if(cols%2==0){
                    cout << start;
                    start = start + 1;                    
                }else{
                    cout << " ";
                }
            } else {
                //first elements are allways 1
                if(cols==0){
                    cout << 1;
                } else{
                    //last elements are the row number
                    if(cols==2*rows+1-1){
                        cout << rows+1;
                    } else{
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }
}