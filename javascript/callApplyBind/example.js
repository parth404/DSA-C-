// call, apply, bind

let name = {
  firstName: "Parth",
  lastName: "Bhattacharya",
  printFullName: function () {
    console.log(this.firstName + " " + this.lastName);
  },
};

name.printFullName(); // Parth Bhattacharya

let name2 = {
  firstName: "Luke",
  lastName: "Skywalker",
};

// Function Borrowing
// Function borrowing in JavaScript is a concept where you take a method from one object
// and use it in the context of another object. This allows you to reuse methods across
// different objects without duplicating code.

name.printFullName.call(name2);

// Optimized way

// create the function
let getAge = function (homeTown, age) {
  console.log(
    this.firstName + " from " + homeTown + " is " + age + " years old"
  );
};

// Now we can pass the reference using call to the getAge function, also we can pass additional variables as a second parameter in call

getAge.call(name, "Surat", 20); // Parth from Surat is 20 years old
getAge.call(name2, "Tatooine", 21); // Luke from Tatooine is 21 years old

// Apply Method

getAge.apply(name2, ["Tatooine", 21]); // Luke from Tatooine is 21 years old

// Bind method
// creates a copy of the method and can be invoked later

let printMyName = getAge.bind(name2, "Tatooine", 21);
console.log(printMyName); // function: bound getAge

printMyName(); // Luke from Tatooine is 21 years old
