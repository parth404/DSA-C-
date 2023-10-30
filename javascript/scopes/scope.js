// BLOCK SCOPE & Shadowing in JS

// What is Block in Javascript

// In JavaScript, a block is a group of statements enclosed within curly braces {}.
// Blocks are used to group multiple statements together into a single, compound statement.
// They are often used in control flow structures,
// such as conditionals (if statements, switch statements) and loops (for loops, while loops).

// Here's an example of a block within an if statement:

// if (condition) {
//     // This is a block
//     statement1;
//     statement2;
//     // ...
//     statementN;
//   }

// Blocks are also used to define the scope of variables declared with let and const.
// Variables declared within a block are limited in scope to that block, and they are not accessible outside of it.

// {
//   let x = 10; // Variable x is only accessible within this block
// }
// // x is not accessible here

// However, since Var is global scope this works differently for var when declared inside var

// {
//   var a = 10;
//   let b = 20; // not accessible outside block scope
// }

// console.log(a); // 10
// console.log(b); // Uncaught ReferenceError: b is not defined

// Variable Shadowing

var a = 20;
let b = 20;
{
  var a = 10;
  let b = 30;
  console.log(a); // 10 - value of a
  console.log(b); // 30 - value of b declared locally
}

console.log(a); // 10 - value of a, as it was updated regardless of being inside block scope, as it's pointing to the same memory location
console.log(b); // 20 - value of b declared globally

// Watching the above code in debugger tool reveals that:

// Block
// b : 30
// Script
// b : 20

// both b's were allocated to different memory locations and hence don't point to the same value

// Shadowing in JavaScript occurs when a variable declared within a specific scope has the same name as a variable in an outer scope,
// effectively "hiding" or "shadowing" the variable from the outer scope. This means that when you reference the variable
// with the same name within the inner scope, you're actually referring to the inner variable, not the outer one.
// This can lead to unexpected behavior and potential bugs if not handled correctly.

// Illegal shadowing, also known as "illegal re-declaration" or "duplicate declaration," occurs in JavaScript when you attempt to declare
// a variable with the same name within the same scope or block, violating the rules of variable declaration.
// JavaScript does not allow re-declaring a variable with the same name within the same scope using the same declaration keyword (e.g., let, const, var).

// let c = 100;

// {
//   var c = 20;
// }
// Cannot redeclare block-scoped variable 'c'

// however vice-versa works

// var c = 100;

// {
//   let c = 20;
// }
