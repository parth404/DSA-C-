// Array.reduce() method

// Array.reduce() is one of the most powerful methods available that can
// be used to perform different types of actions like segregation,
// aggregation, running things in sequence/series, etc.

// Anatomy of Array.reduce()

// verbose
// arr.reduce(callbackfn, initialValue);
// // simplified
// // callback function with parameters
// arr.reduce((previousValue, currentValue, currentIndex, array) => {
//   const nextValue = previousValue + currentValue;
//   return nextValue;
// }, initialValue);

// Array.reduce() accepts a callback function and initial value as an input
// (initial value is optional). The function will be called for each element
// of the array with the initial value at the beginning and then with the
// value returned from the last call of the same function.
// The callback function has 4 parameters, (previousValue, currentValue,
// currentIndex, array).
// ● previousValue – The value returned from the last call of the
// same function or the initial value at the beginning.
// ● currentValue – Current value of the array.
// ● currentIndex – Current index position of the iteration.
// ● array – The array itself.
// Using this method we can perform different types of operations.

// --------------------------------------------------------------------------------

// Aggregation
// Sum all the elements of the array or multiply all the elements of the array.

const arr1 = [1, 2, 3, 4];

const sum = arr1.reduce(
  (previousValue, currentValue) => previousValue + currentValue,
  0
);
const product = arr1.reduce(
  (previousValue, currentValue) => previousValue * currentValue,
  1
);

console.log(sum);
console.log(product);

// Segregation
// We can group a certain set of values depending on our requirements.

const arr2 = [1.1, 1.2, 1.3, 2.2, 2.3, 2.4];

const segregate = arr2.reduce((previousValue, currentValue) => {
  // round of the value
  const floored = Math.floor(currentValue);

  // If no key present
  // create a new entry with the array value
  if (!previousValue[floored]) {
    previousValue[floored] = [];
  }

  //segregate the current value in the respective key
  previousValue[floored].push(currentValue);

  //return updated value
  return previousValue;
}, {});

console.log(segregate);
/*
{
1: [1.1, 1.2, 1.3],
2: [2.2, 2.3, 2.4]
}
*/

//Run in sequence

// Let’s say we have an array of functions and a value, the value has to be
// passed through these functions in a pipe. Like the initial value has to
// be passed to the first function and then the returned value from the
// first function has to be passed to the next function and so on.

// functions
const upperCase = (str) => {
  return str.toUpperCase();
};
const reverse = (str) => {
  return str.split("").reverse().join("");
};
const append = (str) => {
  return "Practice " + str;
};
// array of functions to be piped
const arr3 = [upperCase, reverse, append];
// initial value
const initialValue = "reduceFunction";

const finalValue = arr3.reduce((previousValue, currentElement) => {
  // pass the value through each function
  // currentElement is the function from the array
  const newValue = currentElement(previousValue);

  // return the value received from the function
  return newValue;
}, initialValue);

console.log(finalValue);
// Practice NOITCNUFECUDER

// Similarly, if we want to run a promise in a sequence we can do the same with this.
// helper function to create a promise
// that resolves after a certain time

const asyncTask = function (time) {
  return new Promise((resolve, reject) => {
    setTimeout(() => resolve(`completing ${time}`), 100 * time);
  });
};

// create an array of tasks
const promises = [
  asyncTask(3),
  asyncTask(1),
  asyncTask(7),
  asyncTask(2),
  asyncTask(5),
];

// Main function to run promise in series

const asyncSeriesExecuter = function (promises) {
  promises.reduce((acc, curr) => {
    // return when previous promise is resolved
    return acc.then(() => {
      // Run the current promise
      return curr.then((val) => console.log(val));
    });
  }, Promise.resolve());
};

asyncSeriesExecuter(promises);
