// find factorial of a number

const findFactorial = (num) => {
  let fact = 1;
  for (let i = 1; i <= num; i++) {
    fact *= i;
  }
  return fact;
};

const number = 6;

console.log(`factorial of ${number} is ${findFactorial(number)}`);
