// find factorial of a number

const findFactorial = (num) => {
  let fact = 1;
  for (let i = 1; i <= num; i++) {
    fact *= i;
  }
  return fact;
};

// TODO: Recusrsive solution

const number = 45; //won't return correct result

console.log(`factorial of ${number} is ${findFactorial(number)}`);
