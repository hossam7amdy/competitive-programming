"use strict";

// https://coderhub.sa/challenges/cb02e542-e5ff-4407-9fef-417586128920/view?language=JavaScript

function longestZero(strParam) {
  strParam += "1"; // dummey: force to proceed it all

  let cur = 0,
    best = 0;
  for (const ch of strParam) {
    if (ch === "0") ++cur;
    else {
      best = Math.max(best, cur);
      cur = 0;
    }
  }

  return "".padEnd(best, 0);
}

const strParam = "0000000000000000010001000000";
console.log(longestZero(strParam));
