"use strict";

// https://coderhub.sa/challenges/eee774ad-b85b-4ab1-957b-11de84a5ac8b/view?language=JavaScript

function math_expr(expr) {
  for (let i = 0; i < expr.length; ++i) {
    if (isFinite(expr[i])) continue;
    if (
      !/[-,+,/,*]/.test(expr[i]) ||
      !isFinite(expr[i - 1] || !isFinite(expr[i + 1]))
    )
      return false;
  }

  return true;
}

console.log(math_expr("8-6"));
console.log(math_expr("q-3"));
console.log(math_expr("7#4"));
console.log(math_expr("6/1"));
