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

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Temporal Dead Zone

// Example
// console.log(a);
// let a = 10;
// var b = 100;

// Uncaught ReferenceError: Cannot access 'a' before initialization

// To understand this behavior better we can see the scopes inn which these variables are assigned using debugger tools

// adding a break point at let a = 10. i.e to observe the memory creation phase
// shows that var b is assigned to global scope where as let a is in script

// Script
// a : <value unavailable></value>

// Global
// b : undefined

// forwarding one step in debugger, let's us observe that a is now assigned the value
// as the line var b = 100 has not been read yet b is still undefined

// Script
// a : 10
// Global
// b : undefined

// when var b = 100 is read, we can observe that b is assigned a vlaue of 100
// Global
// b : 100

// Temporal Dead Zone: The time since when let variable was hoisted and uptill it was assigned a value

// so in case we had our order as below
// console.log(a); // this line gets executed when a is still in temporal dead zone
// let a = 10;
// var b = 100;

// hence when we try to access a before it exits the temporal dead zone it gives us a Uncaught ReferenceError

// Difference between in var, let and const

// let a = 10;
// console.log(a);
// let a = 20;

// Doing the above would throw an error
// Uncaught SyntaxError: Identifier 'a' has already been declared

// However --
// var a = 10;
// console.log(a);
// var a = 20;

// output 10

// This doesnot throw any error

//------------------------------When using Const--------------------
// let a;
// console.log(a);
// a = 20;
// output undefined -- however no error is thrown

// however for const

// const a;
// console.log(a);
// a = 20;

// Uncaught SyntaxError: Missing initializer in const declaration. So, wehen using cont we need to initialize with value when using const to declare a variable

// var b = 20;
// let b = 30;

// console.log(b); // Uncaught SyntaxError: Identifier 'b' has already been declared

// also

// const c = 1000;

// c = 30; // Uncaught TypeError: Assignment to constant variable.
