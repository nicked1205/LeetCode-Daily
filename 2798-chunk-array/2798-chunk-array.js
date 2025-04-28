/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    var resArr = [];
    var i = 0;
    while (i * size < arr.length) {
        resArr[i] = (arr.slice(i * size, size * (i + 1)));
        i++;
    }

    return resArr;
};
