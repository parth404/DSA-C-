// Shift array elements by one or rotate array by one

// Input [10,20,30,40,50,60]
// Output [60,10,20,30,40,50]

// -----------------------------------------------------------------------------

// Approach 1

// const rotateArray = (arr) => {
//   // shift last element to start
//   let next = arr[0];
//   arr[0] = arr[arr.length - 1];

//   //shift rest of the elements by 1
//   for (let i = 1; i < arr.length; i++) {
//     let curr = arr[i];
//     arr[i] = next;
//     if (i < arr.length) {
//       next = curr;
//     }
//   }
//   return arr;
// };

// --------------------------------------------------------------------------

// Approach 2 : start shifting from last index

const rotateArray = (arr) => {
  let lastItem = arr[arr.length - 1]; // save value of last item

  //shift the elements by 1
  for (let i = arr.length - 1; i > 0; i--) {
    arr[i] = arr[i - 1];
  }
  // shift last element to start
  arr[0] = lastItem;
  return arr;
};

//output
const arr = [10, 20, 30, 40, 50, 60];

console.log(rotateArray(arr));
