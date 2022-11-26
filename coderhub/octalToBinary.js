"use strict";

// https://coderhub.sa/challenges/44be3e9f-8b91-495d-91f2-c514693ff190/view?language=JavaScript

function oct_to_bin(octal) {
  const octal_binary = {
    0: "000",
    1: "001",
    2: "010",
    3: "011",
    4: "100",
    5: "101",
    6: "110",
    7: "111",
  };

  let res = "";
  while (octal > 0) {
    res = octal_binary[octal % 10] + res;
    octal = Math.trunc(octal / 10);
  }
  return +res + "";
}

const octal = 123;
console.log(oct_to_bin(octal));
