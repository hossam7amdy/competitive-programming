"use strict";

// https://coderhub.sa/challenges/a25be439-0887-4775-9498-ec36eb413888/view?language=JavaScript

function first_n_vowels(phrase, n) {
  const regex = /[a,o,e,i,u,A,O,E,I,U]/g;
  const vowels = phrase.match(regex);

  if (n > vowels.length) return "invalid";

  return vowels.splice(0, n).join("");
}

const phrase = "Queen",
  n = 3;
console.log(first_n_vowels(phrase, n));
