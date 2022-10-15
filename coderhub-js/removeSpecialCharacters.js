"use strict";

// https://coderhub.sa/challenges/614741e5-e7b7-4daa-89e2-e32ba6a75e38/view?language=JavaScript

function removeSpecialCharacters(strParam) {
  const regex = /[^-_a-zA-Z ]/g;
  return strParam.replaceAll(regex, "");
}

const strParam = "Hi How are you!";
console.log(removeSpecialCharacters(strParam));
