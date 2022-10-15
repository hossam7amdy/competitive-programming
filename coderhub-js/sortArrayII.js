"use strict";

function sort_array(my_array, typeParam) {
  return my_array.sort((a, b) => (typeParam === "S" ? a - b : b - a));
}

const my_array = [63, 12, 43, 56, 12],
  typeParam = "";

console.log(sort_array(my_array, typeParam));
