"use strict";

// https://coderhub.sa/challenges/5bd914c3-ab6d-49df-bf9b-5c01ef189974/view?language=JavaScript

function bin_to_oct(b) {
  function toDecimal(binary) {
    let res = 0;
    for (const [i, d] of binary.entries()) {
      if (+d === 0) continue;
      res += Math.pow(2, i);
    }
    return res;
  }

  let res = "";
  let decimal = toDecimal([...b].reverse());
  while (decimal > 0) {
    res = (decimal % 8) + res;
    decimal = Math.trunc(decimal / 8);
  }

  return +res;
}

console.log(bin_to_oct("101010101010"));
console.log(bin_to_oct("1000000000"));
console.log(bin_to_oct("10101111000"));
console.log(bin_to_oct("1"));
