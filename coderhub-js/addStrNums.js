"use strict";

// https://coderhub.sa/challenges/033163c2-91be-4f1b-b0c0-01aff0811448/view?language=JavaScript

function addStrNums(num1, num2) {
  if (isFinite(num1) && isFinite(num2)) return `${+num1 + +num2}`;

  return "-1";
}

console.log(addStrNums("4", "6"));
console.log(addStrNums("5", "hi"));
console.log(addStrNums("1", "0"));
console.log(addStrNums("2", "1"));
