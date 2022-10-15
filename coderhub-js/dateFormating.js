"use strict";

// https://coderhub.sa/challenges/a2df08ef-faa1-4aaf-bbd5-66f7e021855a/view?language=JavaScript

function date_formating(date) {
  return date.split("-").reverse().join("-");
}

const date = "2020-01-01";
console.log(date_formating(date));
