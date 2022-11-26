"use strict";

// https://coderhub.sa/challenges/6af0fc35-818d-4c74-89b1-1ed8df554371/view?language=JavaScript

function timePeriod(date1, date2) {
  date1 = new Date(date1);
  date2 = new Date(date2);
  const now = new Date();

  return now > date2 && date2 > date1;
}

const date1 = "2022-01-02T00:00:00",
  date2 = "2022-01-12T00:00:00";

console.log(timePeriod(date1, date2));
