"use strict";

// https://coderhub.sa/challenges/8720c931-b2c0-4922-bb59-2970019a3f01/view?language=JavaScript

function add_five(arr) {
  return arr.map((el) => el + "5");
}

const arr = ["code", "c"];
console.log(add_five(arr));
