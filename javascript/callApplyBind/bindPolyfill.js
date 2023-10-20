// Polyfill for bind method

// Polyfill is sort of a browser fallback, in-case browser doesn't have bind we can create our own bind method

let name = {
  firstName: "Parth",
  lastName: "Bhattacharya",
};

let printName = function (homeTown, city) {
  console.log(
    this.firstName + " " + this.lastName + " from " + homeTown + ", " + city
  );
};

// create our own implementation of bind method

Function.prototype.myBind = function (...args) {
  let obj = this;
  params = args.slice(1); // array of arguments
  // bind lets us copy a method or function which can be later invoked
  return function (...args2) {
    obj.apply(args[0], [...params, ...args2]); // first arguement should be the reference object
  };
};

let printName2 = printName.myBind(name, "Gujarat");
printName2("Surat"); // Parth Bhattacharya from Gujarat, Surat
