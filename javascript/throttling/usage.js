// Throttling in Javascript

// Throttling is a technique used in web development to limit the rate at which a particular function or event handler can be executed.
// It ensures that the function is called at a specified interval, no matter how often the event that triggers it occurs.
// Throttling is often used for scenarios where you want to control the frequency of function calls to prevent performance issues or to limit network requests.

// Throttling works as follows:

// 1. When an event occurs, the function is initially executed.
// 2. Subsequent calls to the function during the specified interval are ignored.
// 3. After the interval has passed, the function is allowed to execute again for the next occurrence of the event.
// 4. Throttling ensures that the function is executed periodically at a controlled rate, which can be particularly useful
//    for scenarios like scroll events (to improve performance), button click events, or repetitive AJAX requests.

// Where throttling is used instead of deboucing

// #Example : calling a function on resizing of the browser window

// Here we want to limit the function call because resizing triggers thousands of events and it will cause performance issues

// User can resize very fast or may resize very slow i.e it cannot be guaranteed how often the function will be called
// Here debouncing is not a good option to limit the rate as it will depend on
// how fast or slow the user is resizing the window resulting in very few or more function calls

// The better way would be to set a specified interval after which the next event trigger will call the function i.e throttling

// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Usage

// let's assume we have an expensive function which should be called very few times

const expensive = () => {
  console.log("Expensive");
};

// assume that we are calling it on window resize event

window.addEventListener("resize", expensive); // on every new size this will be called

// we need to limit the rate as it can be thousands of times
// lets create a optimized function that uses throttling

// Throttle function to limit the rate of function calls
const throttle = (fn, limit) => {
  let flag = true; // maintains a flag in the created closure to keep a track of function execution

  return function () {
    let context = this;
    args = arguments;
    if (flag) {
      fn.apply(context, args);
      flag = false;

      setTimeout(() => {
        flag = true; // flag is set to true after specified limit
      }, limit);
    }
  };
};

const betterExpensive = throttle(expensive, limit); // takes in fn and rate limit in ms
