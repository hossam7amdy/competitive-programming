"use strict";

// https://coderhub.sa/challenges/f2ed4815-d856-4c89-9ae5-9ecb8bdae9e7/view?language=JavaScript

function middle_char(word) {
  const mid = Math.trunc(word.length / 2);
  // odd
  if (word.length % 2 == 1) return word[mid];
  // even
  return word.slice(mid - 1, mid + 1);
}

const word = "like";
console.log(middle_char(word));
