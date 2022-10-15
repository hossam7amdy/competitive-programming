"use strict";

// https://coderhub.sa/challenges/d122bc96-d15b-483f-8fda-c937c8bcd833/view?language=JavaScript

function primes_nums(numbers) {
  const isPrime = function (num) {
    for (let i = 2; i < num; ++i) {
      if (num % i == 0) return false;
    }
    return true;
  };

  return numbers.filter((num) => isPrime(num));
}

const numbers = [1, 3, 80, 25];

console.log(primes_nums(numbers));
