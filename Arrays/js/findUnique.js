// Find Unique Element

const findUnique = (arr) => {
  let ans = 0;
  for (let i = 0; i < arr.length; i++) {
    ans = ans ^ arr[i];
  }
  return ans;
};

//Output
const arr = [2, 10, 11, 10, 2, 13, 15, 13, 15];
console.log(findUnique(arr));
