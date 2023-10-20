// Function Currying

// Function currying is a technique in functional programming and JavaScript
// where a function is transformed into a series of unary (single-argument) functions.
// This allows us to call the original function with multiple arguments by invoking
// each unary function one at a time.

// The process of currying a function involves the following steps:

// 1. The original function, which takes multiple arguments, is transformed into a
// function that takes a single argument and returns a new function.

let multiply = function (x, y) {
  console.log(x * y);
};

// Bind method allows us to copy a method without invoking it immediately

let twice = multiply.bind(this, 2); // 2 is set as the x variable

// 2. The new function, when called with the first argument, returns another function
// that expects the next argument, and so on. This continues until all the arguments
// are provided, and the final function (which may not take any more arguments) is
// called to produce the result.

twice(4); // 4 is set as y variable
// output : 8

// simillarly

let thrice = multiply.bind(this, 3);
thrice(4); // output : 12

// Alternate way using function closures

let add = function (x) {
  return function (y) {
    console.log(x + y);
  };
};

let addTwo = add(2);
let addThree = add(3);

addTwo(2); // 4
addThree(2); // 5
