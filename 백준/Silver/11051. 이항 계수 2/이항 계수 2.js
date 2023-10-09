let input = require('fs').readFileSync("/dev/stdin").toString().trim().split("\n").map(e => { return e.split(" ").map(Number) });

let dp = new Array(1005).fill(null).map(e=>new Array(1005).fill(0));

let n = input[0][0];
let k = input[0][1];
let mod = 10007;

for(let i = 0; i<=n; i++){
    dp[i][0] =1;
    dp[i][i] =1;
}

for(let i=2; i<=n; i++){
    for(let j =1;j<i; j++){
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        dp[i][j] %= mod;
    }
}

console.log(dp[n][k]);