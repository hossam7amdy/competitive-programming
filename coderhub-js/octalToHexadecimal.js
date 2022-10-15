"use strict";

// https://coderhub.sa/challenges/02c2b94c-20f7-4c79-a90d-d43b67234ec7/view?language=JavaScript

function oct_to_hex(octal_number) {
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

  let decimal = oct_to_dec(octal_number);

  const map = {
    10: "A",
    11: "B",
    12: "C",
    13: "D",
    14: "E",
    15: "F",
  };

  let res = "";
  while (decimal > 0) {
    const cur = decimal % 16;
    res = `${cur > 9 ? map[cur] : cur}` + res;

    decimal = Math.trunc(decimal / 16);
  }

  return res;
}

const octal_number = 5252;
console.log(oct_to_hex(octal_number)); // 'AAA'
