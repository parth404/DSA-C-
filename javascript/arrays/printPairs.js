// Print all possible pairs

const printPairs = (arr) => {
  let ans = [];
  for (let i = 0; i < arr.length; i++) {
    for (let k = 0; k < arr.length; k++) {
      ans.push([arr[i], arr[k]]);
    }
  }
  return ans;
};

console.log(printPairs([10, 20, 30]));
