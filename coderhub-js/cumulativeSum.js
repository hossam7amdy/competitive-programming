"use strict";

// https://coderhub.sa/challenges/b28a9de2-0e47-42ba-9cf5-99543d52578c/view?language=JavaScript

function cumulative_sum(arr) {
  arr.reduce((accum, cur, idx) => (accum = arr[idx] = accum + cur), 0);
  return arr;
}

const arr = [-4, -3, -2];
console.log(cumulative_sum(arr));
