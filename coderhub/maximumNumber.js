"use strict";

// https://coderhub.sa/challenges/e2c5e9b1-9632-4a2e-ae65-717836e4f3f8/view?language=JavaScript

function max_element(arr) {
  return Math.max(...arr);
}

const arr = [1, 2, 3, 4, 5, 1000];
console.log(max_element(arr));
