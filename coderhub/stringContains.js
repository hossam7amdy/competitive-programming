"use strict";

// https://coderhub.sa/challenges/2b77e2c5-6e27-42a3-822b-3bd41f777414/view?language=JavaScript

function stringContains(firstName, contains) {
  const regex = new RegExp(contains);
  return regex.test(firstName);
}

const firstName = "Ahmad",
  contains = "N";
console.log(stringContains(firstName, contains));
