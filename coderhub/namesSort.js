"use strict";

// https://coderhub.sa/challenges/745d5c59-111c-4dc1-bfdc-0ec30dcf0476/view?language=JavaScript

function namesSort(namesArray, order) {
  namesArray.sort();

  if (order === "ASC") return namesArray;
  return namesArray.reverse();
}

const namesArray = ["Ahmed Omar", "Yousef Abdullah"],
  order = "DESC";

console.log(namesSort(namesArray, order));
