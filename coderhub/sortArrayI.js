"use strict";

// https://coderhub.sa/challenges/46dab9c7-3b55-48f1-8763-6ef4b30006da/view?language=JavaScript

function sort_array(elements_array) {
  return elements_array.sort((a, b) => a - b);
}

const elements_array = [63, 12, 43, 56, 12];
console.log(sort_array(elements_array));
