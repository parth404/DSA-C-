// Closures with examples

// A closure is the combination of a function bundled together with references to its surrounding state(the lexical environment).
// A closure gives us access to another function's scope from an inner function.
// In JS, closures are created every time a function is created, at function creation time

// Basic Example

function x() {
  var a = 7;
  function y() {
    // inside y a closure is formed with the access to it's parent's lexical scope
    console.log(a);
  }
  return y;
}

let z = x(); // a new execution is created as x is invoked
// once y() is returned by x(), it no loger exists in the call stack

// now y() exists outside of x()
console.log(z);
// ƒ y() {
//     // inside y a closure is formed with the access to it's parent's lexical scope
//     console.log(a);
//   }

z(); // 7 value of a which was declared in lexical scope of x()

// This shows that, lexical scope is maintained even after the outer scope has finished execution

//-----------------------------------------------------------------------------------CORNER CASES-------------------------------------------------------------------------------------------------------------------------------------------------------------------

//#1
function a() {
  var x = 7;
  function b() {
    console.log(x);
  }
  x = 100; // changing value of x after declaring function b
  return b;
}

let c = a();

c(); // 100

// function b() executes console.log(x)
// here x is a reference to the variable and not 7
// since value of x was updated to 100, upon execution, b() prints 100 as the value was changed to 100

//#2

function ex() {
  var x = 900;
  function a() {
    var y = 7;
    function b() {
      console.log(x, y);
    }
    b();
  }
  a();
}
ex(); // 900 7

// In the above example b() forms a closure with a() it's parent, and ex() it's parent's parent

// Use cases of Closures
// - Module Design Pattern
// - Currying
// - Functions line Once - _.once(function)
// - memoize
// - maintaining state in async world
// - setTimeouts
// - Iterators
