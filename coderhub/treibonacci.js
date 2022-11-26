"use strict";

// https://www.udemy.com/course/the-complete-javascript-course/learn/lecture/22649229#questions

function tribonacci(num) {
  const seq = new Array(num);
  seq.fill(1);

  for (let i = 3; i < seq.length; ++i) {
    seq[i] = seq[i - 1] + seq[i - 2] + seq[i - 3];
  }

  return seq;
}

const num = 5;
console.log(tribonacci(1));
console.log(tribonacci(2));
console.log(tribonacci(3));
console.log(tribonacci(4));
console.log(tribonacci(5));
console.log(tribonacci(6));
