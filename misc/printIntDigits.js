// Print all digits of an integer

// Input N=1234
// Output 1 2 3 4

const printDigits = (n) => {
  let ans = [];
  while (n > 0) {
    ans.unshift(n % 10);
    n = Math.floor(n / 10);
  }
  console.log(...ans);
};

printDigits(134);
