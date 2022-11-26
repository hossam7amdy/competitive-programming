"use strict";

// https://coderhub.sa/challenges/f437870e-89fc-4331-994c-a53b0c3f3a0d/view?language=JavaScript

function count_ones(num) {
  let res = 0;
  while (num > 0) {
    if (num % 2 === 1) res++;
    num = Math.trunc(num / 2);
  }

  return res;
}

const num = 0;
console.log(count_ones(num));
