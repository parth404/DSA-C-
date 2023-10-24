// Async Await

// #EXAMPLE

// async function will always retrun a promise
async function getData() {
  // Either we return a promise
  //   return new Promise(function (resolve, reject) {
  //     resolve("from async function");
  //   });
  // If we just return a value , async will wrap the value inside a promise and return it
  return "from async function";
}

const data = getData();

// console.log("data", data); // data Promise {<fulfilled>: 'from async function'}

// data.then((res) => console.log(res)); // from async function

// lets assume we have another promise
const p = new Promise(function (resolve, reject) {
  resolve("Promise resolved value");
});

async function dummy() {
  // since p is already a promise it will not be additionally wrapped inside a promise and returned as it is
  return p;
}

const dummyPromise = dummy();
// console.log("dummyPromise", dummyPromise); // Promise {<pending>}
// dummyPromise.then((res) => console.log(res)); // Promise resolved value

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Using Async Await combo

// Async and await are used to handle promises.
// Do we really need async await

const newPromise = new Promise(function (resolve, reject) {
  setTimeout(() => {
    resolve("new Promise resolved value");
  }, 10000);
});

// If we have a normal function
// function getUsers() {
//   newPromise.then((res) => console.log(res));
//   console.log("some console text"); // js engine won't wait for promise to be resolved and print this first
// }

// getUsers();

// Using async await instead
// async function handlePromise() {
//   // Await is a keyword that can only be used inside of async function
//   const val = await newPromise;
//   console.log("some console text"); // this won't be printed till await is complete
//   console.log(val);
// }
// handlePromise();

// Deep Dive into Async Await

// lets create two promises

const p1 = new Promise(function (resolve, reject) {
  setTimeout(() => {
    resolve("P1 resolved value");
  }, 10000); // 10 secs
});

const p2 = new Promise(function (resolve, reject) {
  setTimeout(() => {
    resolve("P2 resolved value");
  }, 5000); // 5 secs
});

// the above promises have different resolve times

async function handleAsyncPromise() {
  console.log("hello world");

  const val = await p1;
  console.log("some console text");
  console.log(val);

  const val2 = await p2;
  console.log("some more text");
  console.log(val2);
}
handleAsyncPromise();
// hello world - this gets printed first

// Then all the await results are printed together despite the time difference in resolving them

// some console text
// P1 resolved value
// some more text
// P2 resolved value

// Js engine actually resolves val2 before val however it doesn't show the result till val is resolved due to await

// What JS engine does behind the scenes

// call stack -

// starts executing handleAsyncPromise()
// prints "hello world"
// encounters await p1 - checks if it is resolved if not resolved:
// suspends handleAsyncPromise() and JS engine removes it from call stack
// starts executing handleAsyncPromise()
// encounters await p2 - checks if resolved
// if resolved-continues execution else suspends handleAsyncPromise()

// real world example

const API_URL = "https://api.github.com/users/parth404";

// async function handleFetch() {
//   const data = await fetch(API_URL);

//   //fetch() => response => response.json() => jsonValue

//   const jsonValue = await data.json();

//   console.log(jsonValue);

//   // also can be written as
//   // fetch(API_URL) // this is a promise
//   //   .then((response) => {
//   //     return response.json(); // this is also a promise
//   //   })
//   //   .then((data) => {
//   //     console.log(data);
//   //   });
// }

// handleFetch();

// Handling Errors in async await

async function handleFetch() {
  try {
    const data = await fetch(API_URL);
    const jsonValue = await data.json();
    console.log(jsonValue);
  } catch (error) {
    console.log(error);
  }
}

handleFetch();

// How to answer what is async await

// async is a special keyword to use with functions. and async functions are a different thing. await keyword can be used only inside async functions to handle promises

// Promises vs async await

// async await is just syntactical sugar that improves readability behind the scenes it works just like promise.then.catch
// promise chaining can be reduced
