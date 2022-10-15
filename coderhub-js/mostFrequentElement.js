"use strict";

// https://coderhub.sa/challenges/9d62db84-0b4e-4562-8027-9667472b1280/view?language=JavaScript

function most_frequent_element(arr) {
  const myMap = new Map();
  arr.forEach((val) => (myMap[val] ? myMap[val]++ : (myMap[val] = 1)));

  let max = 0,
    res;

  for (const [key, value] of Object.entries(myMap)) {
    if (value > max) {
      max = value;
      res = key;
    }
  }

  return res;
}

const arr = [1, 2, 3, 4, 1, 5, -5, -5, -5, -5, -5, 6];
console.log(most_frequent_element(arr));
