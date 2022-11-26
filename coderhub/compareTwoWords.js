"use strict";

// https://coderhub.sa/challenges/96ec9554-a3ce-4783-9bef-ecf225bc318e/view?language=JavaScript

function compare_two_words(s1, s2) {
  return s1.slice(s1.length - 2) === s2.slice(s2.length - 2);
}

const s1 = "ac",
  s2 = "abc";

console.log(compare_two_words(s1, s2));
