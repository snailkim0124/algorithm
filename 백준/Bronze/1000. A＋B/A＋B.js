let input = require('fs').readFileSync("/dev/stdin").toString().trim().split("\n").map(e => { return e.split(" ").map(Number) });

let a = input[0][0];
let b = input[0][1];
console.log(a+b);