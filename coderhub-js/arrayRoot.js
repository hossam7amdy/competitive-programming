"use strict";

// https://coderhub.sa/challenges/b83ff2cc-47e9-4965-b764-6fce3ba65be6/view?language=JavaScript

function array_root(arr) {
  return arr.map((val) => Math.sqrt(val));
}

const arr = [15, 6, 3];
console.log(array_root(arr)); // [3.87,2.45,1.73]
