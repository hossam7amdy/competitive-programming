"use strict";

// https://coderhub.sa/challenges/9965fb59-e700-4087-8bef-05c15e7cb0da/view?language=JavaScript

function unique(arr) {
  const myMap = {};
  arr.forEach((el) => {
    myMap[el] = myMap[el] ? 2 : 1;
  });

  arr = [];
  for (const [key, value] of Object.entries(myMap)) {
    if (value === 1) arr.push(+key);
  }

  return arr;
}

const arr = [3, -4, 3, 3, -3];
console.log(unique(arr));
