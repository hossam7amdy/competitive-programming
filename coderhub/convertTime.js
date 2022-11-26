"use strict";

// https://coderhub.sa/challenges/627b881a-1624-4521-9f90-6f54b07e6faa/view?language=JavaScript

function convert_time(time) {
  const arr = time.split(":");

  if (/am/.test(time)) {
    return `${(arr[0] = +arr[0] % 12)}:${arr[1].replace(" am", "")}`;
  } else if (/pm/.test(time)) {
    return `${(arr[0] = +arr[0] + 12)}:${arr[1].replace(" pm", "")}`;
  } else if (arr[0] > 12) {
    arr[0] = +arr[0] % 12;
    return `${arr.join(":")} pm`;
  }
  if (+arr[0] === 0) +arr[0]++;
  return `${arr.join(":")} am`;
}

const time = "0:00";
console.log(convert_time(time));
