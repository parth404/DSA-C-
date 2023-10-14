// sort 0's and 1's

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
const arr = [1, 1, 0];

console.log(sortFunc(arr));
