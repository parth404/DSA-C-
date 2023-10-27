// interview questions

//#1 example of closure
function outer() {
  var a = 10;
  function inner() {
    console.log(a);
  }
  return inner;
}

// inner() along with it's lexical environment is known as closure

outer()();
// 10 - value of a which was in scope of outer() but inner() can access it
// also works if variable is declared as below
// function outer() {
//   function inner() {
//     console.log(a);
//   }
//   var a = 10;
//   return inner;
// }

// changing var to let doesn't make a difference as the inner function forms closure with it's lexical environment
// function outer() {
//   function inner() {
//     console.log(a);
//   }
//   let a = 10;
//   return inner;
// }

// another example of accessing variables in lexical environment
//function outer(b){
// function outer(b) {
//   function inner() {
//     console.log(a, b);
//   }
//   let a = 10;
//   return inner;
// }
//}

// outer('hello world')() --- 10, hello world

// another example of showing that inner function forms closure with parent and parent's parent's lexical scope
// function outest() {
//   var c = 20
//   function outer(b) {
//     function inner() {
//       console.log(a, b, c);
//     }
//     let a = 10;
//     return inner;
//   }
// }

// outer('hello world')() --- 10 hello world 20

//**** #2 Advantages of Closures
// - Module Design Pattern
// - Currying
// - Functions line Once - _.once(function)
// - memoize
// - maintaining state in async world
// - Helps in data hiding and encapsulation

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ******* Data Hiding and Encapsulation
// example
var count = 0; // accesible by other functions

function counter() {
  var count = 0; // not accesible by other functions
  return function incrementCounter() {
    count++;
    console.log(count);
  };
}

var pvtCounter = counter();
pvtCounter(); // now we can access count
pvtCounter(); // 2

// when creating invoking counter() again
var newCounter = counter();
// This creates a fresh counter and won't affect the previous counter
// a new counter function that forms a new closure everytime it's invoked
newCounter(); // 1

// How to make this scalable
// We can use a constructor function to achieve that

function Counter2() {
  var count = 0; // not accesible by other functions
  this.incrementCounter = function () {
    count++;
    console.log(count);
  };
  this.decrementCounter = function () {
    count--;
    console.log(count);
  };
}

var counter1 = new Counter2(); // use new keyword to use constructor function

counter1.incrementCounter(); // 1
counter1.incrementCounter(); // 2
counter1.incrementCounter(); // 3

counter1.decrementCounter(); // 2

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//**** #3 Disadvantages of Closures
// Over consumption of memory - everytime closures are formed it creates new variables in memory.
// These closed over variables are not garbage collected and keeps accumulating till the program expires
// if not handled it can cause memory leaks

// Garbage collection
// garbage collector is a program in the js engine
// whenever there are unused variables it clears them from memory

// closures & garbage collection
//example

function a() {
  var x = 20;
  return function b() {
    console.log(x);
  };
}

var printX = a();

// Ideally after invoking a(), i.e after it's execution is completed,
// x could have been garbage collected, as it is no longer needed after execution
// However it cannot free up as the closure formed by b() is referencing x
// This way it keeps accumulating as it cannot be garbage collected

printX(); // 20
