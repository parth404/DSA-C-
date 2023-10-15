// What are Closures?

// In simple terms closure is the bundling of two or more functions
// where the inner function has access to the methods and properties
// of the outer function even after execution of the outer function is done.

function example1() {
  let blog = "blogTitle";
  function displayBlog() {
    console.log(blog);
  }
  displayBlog();
}
example1();
// "blogTitle"

// This is because variables are lexical scope in JavaScript and then can
// be accessed anywhere inside that scope unless and until they are
// overridden. In the above example, the variable is function scoped and
// it can be accessed anywhere within the function body (even in the
// inner functions).

function example2() {
  // outer scoped
  let blog = "blogTitle";
  function displayBlog() {
    // new variable with the same name
    // declared in a new scope
    // this will be printed
    let blog = "hello";
    console.log(blog);
  }
  displayBlog();
}
example2();
// hello

// Preference is always given to the nearest declared one.
// This feature makes the closures extremely powerful as even if we
// return the inner function, it will have access to the variables (it will be
// alive) in the outer scope and perform all sorts of operations.

function sum() {
  let a = 10;
  function add(b) {
    return a + b;
  }
  return add;
}
// sum will return a function that will accept an argument
const fn = sum();
// pass the argument and it will sum with
// the value of variable 'a' that is in outer scope
// and return the total
let total = fn(20);
console.log(total);
// 30

// Not only variables but can also access all the other properties and methods
// of the outer function, not just parent but at any level in the scope it is
// declared.

function x(a) {
  function y(b) {
    function z(c) {
      return a + b + c;
    }
    return z;
  }
  return y;
}
// the outer function accepts an argument and returns a function
const a = x(5);
// the inner function also accepts an argument and returns the
// total of both outer and inner argument
let b = a(1);
let c = b(1);
console.log(c);
// 60

// If you notice, in this, the inner function has access to the outer
// function’s arguments and can use it for each instance it is created
