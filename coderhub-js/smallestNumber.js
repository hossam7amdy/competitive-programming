"use strict";

// https://coderhub.sa/challenges/9268e98c-5504-4adb-9eec-4341afe2df77/view?language=JavaScript

function smallest_number(arr) {
  return Math.min(...arr);
}

const arr = [43, 3, -5, 205];
console.log(smallest_number(arr));
