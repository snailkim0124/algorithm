let input = require('fs').readFileSync("/dev/stdin").toString().trim().split("\n").map(e => { return e.split(" ").map(Number) });

let [n, k] = input[0];
let list = input.slice(1);
let ans = 0;

for(let i = n-1;i>=0; i--) {
    ans += Math.floor(k/list[i][0]);
    k -= list[i] * Math.floor(k/list[i][0]);
}

console.log(ans);