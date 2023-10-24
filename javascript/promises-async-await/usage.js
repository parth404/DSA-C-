const cart = ["shirts", "shoes", "hats"];

// Assume that we have the below function that returns us a promise

const promise = createOrder(cart); // returns orderId
console.log(promise); // to see state of the promise

// We can attach a callback function to use other functions

promise
  // Handling resolve
  .then(function (orderId) {
    console.log("OrderId", orderId);
    //   proceedToPayment(orderId);
  })
  // Handling rejection
  .catch(function (err) {
    console.log("Car Items are invalid");
  });

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Now lets create the createOrder Function that creates an orderId for cart items

function createOrder(cart) {
  // use Promise constructor to create a function, with resolve and reject as arguements
  const pr = new Promise(function (resolve, reject) {
    // validate cart
    if (!validateCart(cart)) {
      const err = new Error("invalid items in cart");
      reject(err);
    }
    // logic to create order
    const orderId = "387rtgfiagf98"; // Dummy data
    if (orderId) {
      // simulating delay for API call
      setTimeout(() => {
        resolve(orderId);
      }, 5000);
    }
  });

  return pr;
}

// dummy validate function
function validateCart(cart) {
  return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Promise Chaining

//In case we have more functions to be attached to the promise for example
function proceedToPayment(orderId) {
  return new Promise(function (resolve, reject) {
    const valid = true;
    console.log(`processing payment`);
    if (!valid) {
      const err = new Error("error in processing payment");
      reject(err);
    }
    resolve(`Payment successfull for order id : ${orderId}`);
  });
}

createOrder(cart)
  .then(function (orderId) {
    return orderId;
  })
  .then(function (orderId) {
    return proceedToPayment(orderId);
  })
  .then(function (paymentInfo) {
    console.log(paymentInfo);
  })
  .catch(function (err) {
    // This will handle errors above it not for other callbacks below
    // chained promises after this catch will still execute, even if there is an error
    console.log("encountered following error", err);
  })
  .then(function () {
    console.log("Unaffected by above catch");
  })
  .catch(function (err) {
    console.log("encountered following error", err); // This will spot any reject states and stop execution after any of the promise above is rejected
  });

// Since catch can be chained after then anywhere within the chain we can decide either
// to stop all promise execution on error or return seperate error and continue with chain execution
