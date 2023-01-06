/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function (word) {
  if (word.toUpperCase() === word) {
    return true;
  }
  if (word.toLowerCase() === word) {
    return true;
  }
  const copy = word.toLowerCase().split("");
  copy[0] = copy[0].toUpperCase();
  if (copy.join("") === word) {
    return true;
  }
  return false;
};
