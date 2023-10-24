// Another take on understanding Promises

const cart = ["shirts", "shoes", "hats"];

// api.createOrder(cart, function () {
//   api.proceedToPayment();
// });

// To handle inversion of control we can use Promises

// const promise = createOrder(cart);

// in the above line createOrder() will return a promise which is stored in promise variable

// Promise is nothing but an object {data: undefined}

const GITHUB_API = "https://api.github.com/users/parth404";

const user = fetch(GITHUB_API);

// How Promise is executed

// GITHUB_API : "https://api.github.com/users/parth404"
// cart : (3) ['shirts', 'shoes', 'hats']
// user : <value unavailable>

// GITHUB_API : "https://api.github.com/users/parth404"
// cart : (3) ['shirts', 'shoes', 'hats']
// user : Promise {<pending>}

// GITHUB_API : "https://api.github.com/users/parth404"
// cart : (3) ['shirts', 'shoes', 'hats']
// user : Promise {<fulfilled>: Response}

console.log(user);
// Promise {<pending>}{}
// {
//     [[Prototype]] : Promise,
//     [[PromiseState]]: fullfilled,
//     [[PromiseResult]] : Response
// }

// Here we witness an inconsistency in chrome browser showing pending and promiseState fullfilled at the same time
// why? Because when console.log() statement is executed at that moment fetch returns a promise which is in a pending state
// at that moment, it takes some time to get fulfillied. However, JS doesn't wait and goes ahead and logs pending in the console
// However, later promise state is updated to fulfilled which is shown in PromiseState upon expanding it

// Attaching Callbacks to Promises

user.then(function (data) {
  console.log(data);
});
// Response {type: 'cors', url: 'https://api.github.com/users/parth404', redirected: false, status: 200, ok: true, …}

// -------------------------------------------------------SUMMARY----------------------------------------------------------------------------------------------------------------

// Promise is a special object in Javascript. JS guarantees that this special object
// can only be resolved once - either success or failure (resolve/reject)
// it can have three states - pending, fulfilled, rejected
// Promise objects are immutable - we can pass the data received from a fulfilled promise
// without worrying that it may be mutated by other functions

// How to answer in interviews? What are Promises

// Promise object can be called a placeholder for a certain period of time untill we recieve a value from a async operation
// OR - It's a container for a future value
// MDN Definition - a Promise is an Object representing eventual completion of an asynchronous operation.
// Esentially a promise is a returned object to which you attach callbacks, instead of passing callbacks into a function

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// CALLBACK HELL EXAMPLE

api.createOrder(cart, function (orderId) {
  api.proceedToPayment(orderId, function (paymentInfo) {
    api.showOrderSummary(paymentInfo, function () {
      api.updateWallet();
    });
  });
});

// Handling this using Promise Chaining

const promise = createOrder(cart);

promise
  .then(function (orderId) {
    return proceedToPayment(orderId);
  })
  .then(function (paymentInfo) {
    return showOrderSummary(paymentInfo);
  })
  .then(function (paymentInfo) {
    return updateWallet(paymentInfo);
  });
