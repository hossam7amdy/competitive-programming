"use strict";

// https://coderhub.sa/challenges/96ec9554-a3ce-4783-9bef-ecf225bc318e/view?language=JavaScript

function str_len_comparison(words) {
  if (words.length <= 1) return false;

  for (let i = 1; i < words.length; ++i) {
    if (words[i - 1].length !== words[i].length) {
      return false;
    }
  }
  return true;
}

const words = ["123"];
console.log(str_len_comparison(words));
