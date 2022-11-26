"use strict";

// https://coderhub.sa/challenges/d415189d-85a1-4765-a89e-ea61f653251f/view?language=JavaScript

function word_length(arr) {
  return arr.map((el) => el.length);
}

const arr = ["java", "swift", "javascript", "python"];
console.log(word_length(arr));
