"use strict";

// https://coderhub.sa/challenges/d4278c7b-0b4b-4c2d-998f-fa9822e918bb/view?language=JavaScript

function largest_smallest(array_values) {
  return array_values.reduce(
    ([max, min], cur) => [Math.max(cur, max), Math.min(cur, min)],
    [array_values[0], array_values[0]]
  );
}

const array_values = [5, 1, 2, 4, 9, 10, 200];
console.log(largest_smallest(array_values));
