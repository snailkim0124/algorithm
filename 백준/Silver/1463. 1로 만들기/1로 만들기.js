let input = require('fs').readFileSync("/dev/stdin").toString().trim().split("\n").map(e => { return e.split(" ").map(Number) });

let n = input[0][0];
let dp = new Array(n+1).fill(0);

dp[1] = 0;
for(let i =2; i<=n; i++){
    dp[i] = dp[i-1] +1;
    if(i%3 == 0) dp[i] = Math.min(dp[i], dp[i/3] +1);
    if(i%2 == 0) dp[i] = Math.min(dp[i], dp[i/2] +1);
}

console.log(dp[n]);