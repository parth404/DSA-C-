// Callbacks

// Example 1:
// lets assume we have three functions and we want to execute one of the functions
// after a specified time. In order to do so we can wrap it inside a Callback function

console.log("Hello");

setTimeout(function () {
  console.log("How are you?");
}, 5000);

console.log("Awesome!!");

// In the above example we are passing our function as a callback function to setTimeOut so that it can be executed later

// Example 2:
// Assume we have certain items in a cart array

const cart = ["shirts", "shoes", "hats"];

// suppose we have access to a create order API to create an order

api.createOrder();

// Once order is created we use another API to proceed to payments

api.proceedToPayment();

// In order to manage the dependency we can use callback to handle the non blocking behaviour of asynchronous js code

// Lets wrap the dependent fn inside the createOrder fn

api.createOrder(cart, function () {
  api.proceedToPayment();
});

// since proceedToPayment is passed to the createOrder function, it's the later's responsibility to
// call the proceedToPayment function once order has been created

//Example 3: callback hell
// Adding to the above example
// what if we need to proceed to order summary page after payments is successful

api.createOrder(cart, function () {
  api.proceedToPayment(function () {
    api.showOrderSummary();
  });
});

// Lets add another step, where we need to update the user wallet

api.createOrder(cart, function () {
  api.proceedToPayment(function () {
    api.showOrderSummary(function () {
      api.updateWallet();
    });
  });
});

// Now the code is difficult to read and maintain

// ----------------------------------INVERSION OF CONTROL------------------------------------

// we lose the control of our code when using callbacks

// As seen in the above example the callback function totally depends on the parent function.
// This is risky as all the inner callbacks depends on the success of the parent function,
// and hence we lose control of our program

// -- continued in promises simplified.js --
