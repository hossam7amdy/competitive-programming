"use strict";

// https://coderhub.sa/challenges/741926f8-2c0c-4f23-8862-4370301b9187/view?language=JavaScript

function postFix(expr) {
  function calc(l, op, r) {
    if (op === "+") return l + r;
    else if (op === "-") return l - r;
    else if (op === "*") return l * r;
    return l / r;
  }

  const stack = [];
  for (const ch of expr.split(" ")) {
    if (isFinite(ch)) {
      stack.push(+ch);
    } else {
      const r = stack.pop();
      const l = stack.pop();
      stack.push(calc(l, ch, r));
    }
  }
  return stack.pop();
}

console.log(postFix("6 2 / 3 +"));
console.log(postFix("10 4 - 3 / 2 *"));
console.log(postFix("4 2 /"));
console.log(postFix("10 1 + 11 /"));
