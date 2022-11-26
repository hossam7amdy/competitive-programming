"use strict";

// https://coderhub.sa/challenges/3b4a6874-de15-45dd-9f94-fd3b6e07398f/view?language=JavaScript

function arrowDuplicates(word) {
  const freq = {};
  for (const ch of word.toLowerCase()) {
    freq[ch] = freq[ch] ? 2 : 1;
  }
  let res = "";
  for (const ch of word.toLowerCase()) {
    res += freq[ch] === 1 ? ">" : "<";
  }
  return res;
}

const word = "SAFCSP";
console.log(arrowDuplicates(word));
