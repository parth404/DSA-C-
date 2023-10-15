// Check if number is prime or not

// a number N is prime if it has only two factors i.e, 1 & N itself

// const isPrime = (n) => {
//   for (let i = 2; i < n; i++) {
//     if (n % i === 0) return false;
//   }
//   return true;
// };

// Optimized Solution
const isPrime = (n) => {
  for (let i = 2; i <= Math.sqrt(n); i++) {
    if (n % i === 0) return false;
  }
  return true;
};

//output
const num = 1000000007;

console.log(isPrime(num));
