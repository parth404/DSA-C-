// Hoisting in Javascript

// Hoisting is a JavaScript mechanism where variable and function declarations are moved to the top
// of their containing scope during the compilation phase before the code is executed. This means that,
// in the context of variable declarations, you can use a variable before it is declared in your code
// without causing an error, although it may not be initialized with a value. Function declarations are
// fully hoisted, so you can call a function before it's defined in your code.

x = 7;
greet();
console.log(x);

var x;

function greet() {
  console.log("hello there");
}

// Output
// hello there
// undefined

// explanation
// even before code is executed, js allocates memory for variables and functions
// js starts by assigning undefined to all variables, and function code for functions
// if we had an arrow function instead
// var greet = () => {
//     console.log("hello there");
//   };
// in memory execution context, greet would have been undefined and we would get
// greet is not a function as output
