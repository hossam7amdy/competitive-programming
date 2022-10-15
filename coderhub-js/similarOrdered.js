"use strict";

// https://coderhub.sa/challenges/30408bd0-d051-451b-8a5e-196c54101abb/view?language=JavaScript

function similarOrdered(word1, word2) {
  // remove duplicates & sort
  word1 = [...new Set([...word1])].sort();
  word2 = [...new Set([...word2])].sort();

  let result = "",
    current = "",
    i1 = 0,
    i2 = 0;

  // find logest match
  while (i1 < word1.length && i2 < word2.length) {
    if (word1[i1] === word2[i2]) {
      current += word1[i1];
      ++i1;
      ++i2;
    } else {
      if (current.length > result.length) result = current;

      current = "";
      if (word1[i1] < word2[i2]) ++i1;
      if (word1[i1] > word2[i2]) ++i2;
    }
  }

  // if last piece
  if (current.length > result.length) result = current;

  // result
  if (result === "") return "No matches found";
  return result;
}

const word1 = "Reem",
  word2 = "Nouf";
console.log(similarOrdered(word1, word2));
