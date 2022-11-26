"use strict";

// https://coderhub.sa/challenges/4df423f8-d7ef-49bc-acfb-abd77452667d/view?language=JavaScript

function sub_arrays(arr1, arr2) {
  return arr1.map((val, i) => arr2[i] - val);
}

const arr1 = [-3, 4, 0],
  arr2 = [93, 22, 7];

console.log(sub_arrays(arr1, arr2));
