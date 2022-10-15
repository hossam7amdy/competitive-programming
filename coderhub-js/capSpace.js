"use strict";

// https://coderhub.sa/challenges/e35bb082-6cc1-4aa9-89f5-03077f5ab9f3/view?language=JavaScript

function cap_space(txt) {
  let str = "";
  for (const ch of txt) {
    str += /[A-Z]/.test(ch) ? ` ${ch.toLowerCase()}` : ch;
  }

  return str;
}

const txt = "iLikeCats";
console.log(cap_space(txt));
