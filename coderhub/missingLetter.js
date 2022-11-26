"use strict";

// https://coderhub.sa/challenges/96e99ad0-260a-4bd2-bce8-0040b241dc81/view?language=JavaScript

function missingLetter(txt) {
  let curCode = txt.toLowerCase().charCodeAt(0);
  for (let i = 0; i < txt.length; ++i) {
    if (txt.toLowerCase().charCodeAt(i) !== curCode) {
      return String.fromCharCode(curCode);
    }
    ++curCode;
  }

  return "No Missing Letter";
}

const txt = "abcd";
console.log(missingLetter(txt));
