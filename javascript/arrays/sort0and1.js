// sort 0's and 1's

// count number of occurences of 0 and 1
// const sortFunc = (arr) => {
//   let zeroCount = 0;
//   let oneCount = 0;

//   //count zeros and ones
//   for (let i = 0; i < arr.length; i++) {
//     if (arr[i] === 0) {
//       zeroCount++;
//     } else {
//       oneCount++;
//     }
//   }
//   //fill zeros and ones
//   for (let i = 0; i < arr.length; i++) {
//     while (zeroCount--) {
//       arr[j] = 0;
//       j++;
//     }
//     if (i > zeroCount) {
//       arr[i] = 1;
//     }
//   }
//   return arr;
// };

// Two pointer approach

const sortFunc = (arr) => {
  let start = 0;
  let end = arr.length - 1;
  let i = 0;

  while (i != end) {
    let current = arr[i];

    if (arr[i] === 0) {
      //swap from left
      arr[i] = arr[start];
      arr[start] = current;
      i++;
      start++;
    } else if (arr[i] === 1) {
      //swap from right
      arr[i] = arr[end];
      arr[end] = current;
      end--;
    }
  }
  return arr;
};

//output
const arr = [0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0];

console.log(sortFunc(arr));
