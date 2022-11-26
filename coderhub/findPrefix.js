"use strict";

// https://coderhub.sa/challenges/9e11bab5-d074-4e04-bff6-9f594d5eb91c/view?language=JavaScript

function find_prefix(words, text) {
  const result = [];

  for (let word of words) {
    const cur = word.slice(0, text.length).toLowerCase();
    if (cur === text.toLowerCase()) result.push(word);
  }
  if (result.length === 0) result.push("No matches found");

  return result;
}

const words = ["Nouf", "Abdullah"];
const text = "Gh";

console.log(find_prefix(words, text));
