// example

function x() {
  var i = 1;
  setTimeout(function () {
    console.log(i);
  }, 1000);
  console.log("hello world");
}

x();
// hello world
// 1

// Js will push the setTimeout out of call stack
// execute console.log()
// print result of setTimeout once timer is resolved

// ***QUESTION - Print 1 after 1s, 2 after 2s, 3 after 3s, 4 after 4s, 5 after 5s

function printX() {
  for (var i = 1; i <= 5; i++) {
    setTimeout(function () {
      console.log(i);
    }, i * 1000);
  }
}

// printX();
// 6
// 6
// 6
// 6
// 6

// explanation:
// as we have used var to declare i, for all iterations i refers to the same variable
// console.log(i) is pointing to reference of i, however, Js runs the loop instantly and doesn't wait for the timer to expire
// by the time the timer expires i has already incremented to 6, 5 + 1 due to i++
// once timer has expired the callback function containing the console.log() is executed and it refers to i=6 and prints 6 everytime

// To fix this we need to use let instead of var

// since let is block scope, it creates a new copy of i for every iteration with updated value, hence each iteration refers to a different value
function printY() {
  for (let i = 1; i <= 5; i++) {
    setTimeout(function () {
      console.log(i);
    }, i * 1000);
  }
}

// printY();
// 1
// 2
// 3
// 4
// 5

// Alternate Solution: without using let

function printZ() {
  for (var i = 1; i <= 5; i++) {
    function close(x) {
      setTimeout(function () {
        console.log(x);
      }, x * 1000);
    }
    close(i);
  }
}

// Using closures,
// we can wrap our setTimeout function inside a outer function that takes i and provides it to setTimeout.
// next we need to call the function on every iteration and provide i as parameter
// everytime outer function is called it saves a new copy of i in its scope and same is referenced by setTimeout

printZ();
// 1
// 2
// 3
// 4
// 5
