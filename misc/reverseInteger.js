// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example 1:
// Input: x = 123
// Output: 321

// Example 2:
// Input: x = -123
// Output: -321

// Example 3:
// Input: x = 120
// Output: 21

// Constraints:

// -231 <= x <= 231 - 1

const reverseInt = (n) => {
  let ans = 0;
  let sign = 1;

  const min = 1 << 31;
  const max = -(1 << 31) - 1;

  console.log(max);

  if (n < min) return 0;

  if (n < 0) {
    sign = -1;
    n = sign * n;
  }

  while (n > 0) {
    if (ans > max / 10) return 0;
    let rem = n % 10;
    ans = ans * 10 + rem;
    n = Math.floor(n / 10);
  }
  return ans * sign;
};

const num = -123;
console.log(reverseInt(num));
