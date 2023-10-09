let input = require('fs').readFileSync("/dev/stdin").toString().trim().split("\n").map(e => { return e.split(" ").map(Number) });

let t = input.shift();
let one = new Array(45).fill(0);
let zero = new Array(45).fill(0);

for(let i = 1; i<=t; i++) {
    let n = input.shift();
    zero[0] = 1;
    zero[1] = 0;
    one[0] = 0;
    one[1] = 1;
    for(let j = 2; j<=n; j++){
        zero[j] = zero[j-1] + zero[j-2];
        one[j] = one[j-1] + one[j-2];
    }
    console.log(zero[n] + " " + one[n]);
}