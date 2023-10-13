// create Number using Digits

// Input = [1,2,3]
// Output = 123

// Enter only signle digits in array

const createNum = (digits) => {
  let number = 0;
  for (let i = 0; i < digits.length; i++) {
    number = number * 10 + digits[i];
  }
  return number;
};

//output
const digits = [3, 2, 3];

console.log(createNum(digits));
