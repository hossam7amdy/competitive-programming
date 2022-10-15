"use strict";

// https://coderhub.sa/challenges/3e97adbc-137b-46c2-9ec4-2532cebacbdf/view?language=JavaScript

function oddsVsEvens(num) {
  let even = 0,
    odd = 0;
  while (num) {
    const cur = num % 10;
    if (cur % 2 === 0) {
      even += cur;
    } else {
      odd += cur;
    }
    num = Math.trunc(num / 10);
  }

  if (even > odd) {
    return "even";
  } else if (odd > even) {
    return "odd";
  }

  return "equal";
}

console.log(oddsVsEvens(97428));
console.log(oddsVsEvens(81961));
console.log(oddsVsEvens(54870));
console.log(oddsVsEvens(26341));
