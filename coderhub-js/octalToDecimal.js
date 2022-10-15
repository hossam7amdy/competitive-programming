"use strict";

// https://coderhub.sa/challenges/baa9f593-afa7-4dc2-bb5c-60df19f644fd/view?language=JavaScript

function oct_to_dec(octal_number) {
  let n = 0,
    res = 0;

  while (octal_number > 0) {
    const cur = octal_number % 10;
    res += cur * Math.pow(8, n);

    ++n;
    octal_number = Math.trunc(octal_number / 10);
  }

  return res;
}

const octal_number = 1000;
console.log(oct_to_dec(octal_number));
