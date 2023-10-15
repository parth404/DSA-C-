// Check if number is even or odd

// const isEvenOdd = (num) => (num % 2 === 0 ? "even" : "odd");

// alternate method : using bitwise operation
const isEvenOdd = (num) => ((num & 1) === 0 ? "even" : "odd");

//output
console.log(isEvenOdd(7));
