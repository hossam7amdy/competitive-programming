"use strict";

// https://coderhub.sa/challenges/86000c8c-c148-4f21-9fb2-ad968ed53488/view?language=JavaScript

function sortByLength(txt) {
  return txt
    .split(" ")
    .sort((a, b) => {
      if (a.length === b.length) return a - b;
      return a.length - b.length;
    })
    .join(" ");
}

const txt = "Get in the boat";
console.log(sortByLength(txt));
