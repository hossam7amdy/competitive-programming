"use strict";

// https://coderhub.sa/challenges/17bce426-4504-4df5-a1af-ec8203f7359b/view?language=JavaScript

function find_element(elements_array, element) {
  // write your code here
  if (elements_array.find((el) => el === element)) return true;
  return false;
}

const elements_array = [2, 5, 6, 7, 8, 2, 1],
  element = 5;
console.log(find_element(elements_array, element));
