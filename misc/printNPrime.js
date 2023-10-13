// Print all prime numbers from 1 to N

const isPrime = (n) => {
  for (let i = 2; i <= Math.sqrt(n); i++) {
    if (n % i === 0) return false;
  }
  return true;
};

const num = 19;

for (let i = 2; i <= num; i++) {
  if (isPrime(i)) console.log(i, " ");
}
