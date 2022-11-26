"use strict";

// https://coderhub.sa/challenges/ef23c323-1a7f-48f0-9113-ccbcf8875b60/view?language=JavaScript

function filp_even_odd(numbers) {
  return numbers.map((num) => (num += num % 2 === 0 ? 1 : -1));
}

const numbers = [1, 23, 46, 2, 4];
console.log(filp_even_odd(numbers));
