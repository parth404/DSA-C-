// Promise APIs

// Promise.all() - when we need to make parallel API calls and get the results

// suppose we have three promises p1, p2, p3
// Promise.all([p1, p2, p3]) promise.all takes an array of promises as arguments
// Promise all will wait for all the promises to resolve and then collect the results in an array and return the result as an array
// here result will be returned after the maximum time to resolve all promises
// Failure Case

// In case any one of the promises gets rejected
// As soon as any of these promises get rejected promise.all() will throw an error and result in failure
// output will be error returned by rejected promise
// Here error will be returned at minimum time of failure of any of the promises

//---------------------------------------------promise.allSettled---------------------------------------------------------------------------------------------------------------------

// promise.allSettled([p1, p2, p3])

// if all the promises get resolved, result will be collected and returned as an array of results

// However in case any of the promises fail, promise.allSettled() will wait for all the promises to settle.
// Irrespective of success or failure it will return the results once all promises are resolved

//---------------------------------------------Promise.race----------------------------------------------------------------------------------------------------------------------

// Promise.race([p1, p2, p3])
//---------------3s--1s--2s--  Time taken to resolve promises

// after 1s, promise.race() will return the result of the first settled promise

// In case of failure - Error will be thrown after 1s
// it will return result of first settled promise(fulfilled or rejected)
// it will not wait for other promises to settle

//---------------------------------------------promise.any---------------------------------------------------------------------------------------------------------------------

// promise.any([p1, p2, p3])
// -------------3s--1s--2s--  Time taken to resolve promises

// Simillar to promise.race but here
// it returns the result of first fulfilled promise (success)
// In case any of the promises get rejected, promise.any() will wait for other promises to resolve
// till it finds it's first success(fulfilled) and return it as result

// In case all promises fail
// result will be an aggregated error [err1, err2, err3]
