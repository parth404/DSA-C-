// Promises

// JavaScript is a synchronous programming language. However,
// callback functions enable us to transform it into an asynchronous programming language.

// Promises are a critical feature that helps to manage async operations and handle complexities of non-blocking code execution.
// They allow us to write a cleaner, more maintainable, and predictable code when working with tasks like network requests, file I/O,
// or any operation that takes time to complete

// At it's core a JavaScript Promise is an object representing the eventual completion or failure of an asynchronous operation

// - When a promise is created there are only two outcomes - fulfilled(resolved) or rejected
// - By the time it's not fulfilled neither rejected it remains in a pending state
// - Promises are Resolved with a certain value that value can be further processed(if the value is also a promise) or returned raw
// - Promises are Rejected with the reason that caused the operation to fail.
// - After either of the results we can perform the next set of operations

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Anatomy of a promise

// const promise = new Promise((resolve, reject) => {
//   // resolve or reject
// });

// A promise has three methods
// - (then , catch, finally) that can be used once the promise is settled (resolved or rejected)
// - Each method accepts a callback function that is invoked depending on the state of the promise
// - then(onResolvedFn, onRejectedFn) - This will be called either when promise is resolved or rejected
// - catch(onRejecteFn) - This will be called when a promise is rejected with a reason
// - finally(onFinallyFn) - This will be called every time after then and catch

// Promise.prototype.then(onResolvedFn) Promise.prototype.catch(onRejectedFn) Promise.prototype.finally(onFinallyFn)

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Working of promises

// Example: Create a promise that will resolve after 5 seconds

const promise = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("Hello from a promise");
  }, 5000);
});

// Initially, the promise will be in the pending state.
console.log(promise);
//output
// Promise { : "pending" }
// : "pending"
// : Promise.prototype { ... }

// After 5 seconds, the state of the promise will be updated.
// setTimeout(() => {
//   console.log(promise);
// }, 6000);
// Output
// Promise { : "fulfilled", : "Hello from a promise" }
// : "fulfilled"
// : "Hello from a promise"
// : Prromise.prototype { ... }

//We can assign the .then(onResolvedFn, onRejectedFn) method to the
// promise but the onResolvedFn callback function will be called only
// after the promise is resolved and will have the value
// promise.then((val) => {
//   console.log(val);
// });
// "Hello from a promise" // after the promise is resolved that is after 5 seconds

//Thenable promises can be chained further.
// promise.then((val) => "ABC " + val).then((val) => console.log(val));
// ABC Hello from a promise

// We can attach a finally block independently to the then, as well as
// catch, and it will be invoked at the end.

promise
  .then((val) => {
    return "ABC " + val;
  })
  .then((val) => {
    console.log(val);
  })
  .finally(() => {
    console.log("task done");
  });
// "ABC Hello from a promise"
// "task done"

// Similarly, let’s say we reject a promise after 5 seconds, then we can
// either use the .then(null, onRejectedFn) or .catch(onRejectedFn).

const promise2 = new Promise((resolve, reject) => {
  // a promise that will reject after
  // 5 second
  setTimeout(() => {
    reject("Error 404");
  }, 5000);
});

// promise2.then(null, (error) => {
//   console.error("Called from then method", error);
// });
// // "Called from then method" "Error 404"
// promise2.catch((error) => {
//   console.error("Called from catch method", error);
// });

// "Called from catch method" "Error 404"

// As you can notice multiple handlers can be assigned on the same
// promise and .then() will execute in the order of assignment.
// The catch block can also be extended further using .then().

// promise2
//   .then(null, (error) => {
//     return error;
//   })
//   .then((val) => {
//     console.log("I am chained from then", val);
//   });
// // "I am chained from then" "Error 404"
// promise2
//   .catch((error) => {
//     return error;
//   })
//   .then((val) => {
//     console.log("I am chained from catch", val);
//   });
// "I am chained from catch" "Error 404"

// And .finally() can be attached to both of these.
promise2
  .then(null, (error) => {
    return error;
  })
  .then((val) => {
    console.log("I am chained from then", val);
  })
  .finally(() => {
    console.log(" Then block finally done");
  });
promise2
  .catch((error) => {
    return error;
  })
  .then((val) => {
    console.log("I am chained from catch", val);
  })
  .finally(() => {
    console.log(" Catch block finally done");
  });
// "I am chained from then" "Error 404"
// "I am chained from catch" "Error 404"
// " Then block finally done"
// " Catch block finally done"

// Notice the order of execution, the first error is handled in .then and
// then in .catch and then finally blocks of both are called in order.

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// # Helper Methods

// The promise object has many static methods. Some are helper’s
// methods while others help to process the promise better.

// Promise.resolve(value) creates a resolved promise.

// .resolve("I am resolved")
// .then((val) => { console.log(val); });
// "I am resolved"

// Similarly, Promise.reject(reason) creates a rejected promise.

// .reject("I am throwing error")
// .catch((error) => { console.error(error); });
// "I am throwing error"

// # Process methods

// These methods help to process async task concurrency.

// ● Promise.all()

// The Promise.all() accepts an array of promises and returns a promise
// that resolves when all of the promises in the array are fulfilled or when
// the iterable contains no promises. It rejects with the reason of the first
// promise that rejects

// ● Promise.allSettled()

// The Promise.allSettled() method returns a promise that fulfills after all
// of the given promises have either fulfilled or rejected, with an array of
// objects that each describes the outcome of each promise.

// ● Promise.any()

// Promise.any() takes an iterable of Promise objects. It returns a single
// promise that fulfills as soon as any of the promises in the iterable
// fulfills, with the value of the fulfilled promise. If no promises in the
// iterable fulfill (if all of the given promises are rejected), then the
// returned promise is rejected with an AggregateError, a new subclass of
// Error that groups together individual errors

// ● Promise.race()

// The Promise.race() method returns a promise that fulfills or rejects as
// soon as one of the promises in an iterable fulfills or rejects, with the
// value or reason from that promise.

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// # Async...await
