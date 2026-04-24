/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const nums = [];
    for (let i =0; i < arr.length; i++) {
        nums[i] = fn(arr[i], i);
    }
    return nums;

};