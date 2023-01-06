/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */

var wordPattern = function (pattern, s) {
  const words = s.split(" ");

  if (pattern.length !== words.length) {
    return false;
  }

  const wToP = new Map();
  const pToW = new Map();
  for (let i = 0; i < words.length; ++i) {
    if (!pToW.has(pattern[i])) {
      pToW.set(pattern[i], words[i]);
    } else if (pToW.get(pattern[i]) !== words[i]) {
      return false;
    }

    if (!wToP.has(words[i])) {
      wToP.set(words[i], pattern[i]);
    } else if (wToP.get(words[i]) !== pattern[i]) {
      return false;
    }
  }

  return true;
};
