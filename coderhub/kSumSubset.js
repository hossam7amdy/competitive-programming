"use strict";

// https://coderhub.sa/challenges/8d921f6e-1f9c-446e-9fc4-60f995c00dde/view?language=JavaScript

function kSumSubset(numArray, k, i = 0) {
  if (k === 0) return true;
  if (i === numArray.length) return false;

  let option1 = false;
  if (k - numArray[i] >= 0) {
    option1 = kSumSubset(numArray, k - numArray[i], i + 1);
  }
  const option2 = kSumSubset(numArray, k, i + 1);

  return option1 || option2;
}

const numArray = [14, 8, 12, 9],
  k = 21;
console.log(kSumSubset(numArray, k));
