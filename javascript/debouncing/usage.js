// Debouncing

// Debouncing is a technique used in web development to improve the performance and efficiency of event handlers, especially for events that can fire rapidly in succession,
// such as scroll, resize, and keyboard input events. The primary purpose of debouncing is to limit the number of times a particular event handler is executed, making it
// more efficient and preventing excessive or unnecessary function calls.

// Debouncing works as follows:

// When an event occurs, a timer is started with a certain delay.
// If the event occurs again before the timer expires, the previous timer is canceled, and a new one is started.
// The event handler is only executed when the timer finally expires, meaning it won't be triggered for every intermediate event.
// Debouncing is commonly used for scenarios like handling user input in real-time search boxes or filtering data while typing. It ensures that the actual processing or
// response to the input event occurs only after a user has finished their input, reducing the computational load and preventing unnecessary network requests.

// Example
let counter = 0;
const getData = () => {
  // calls an API and gets Data
  console.log("Fetching Data....", counter++);
};

// With the above function the function gets called everytime a key is pressed

// Instead we can trigger the function only when the user pauses from entering input
// we can create a function that triggers getData only if the difference between key inputs is more than 300 ms

const optimizeIt = function (fn, delay) {
  let timer;
  return function () {
    let context = this;
    args = arguments;

    clearTimeout(timer);

    timer = setTimeout(() => {
      fn.apply(context, arguments);
    }, delay);
  };
};

const betterFunction = optimizeIt(getData, 600);
