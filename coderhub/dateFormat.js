"use strict";

// https://coderhub.sa/challenges/c93a5e09-2578-42ec-95db-88d1e87d6459/view?language=JavaScript

function date_format(date) {
  const options = {
    year: "numeric",
    month: "numeric",
    day: "numeric",
  };
  const last = new Date(date);

  return `${date} | ${date.replaceAll("/", "-")} | ${last.toLocaleDateString(
    "en-US",
    options
  )}`;
}

const date = "2013/11/29";
console.log(date_format(date));
