let input = require('fs').readFileSync("/dev/stdin").toString().trim().split("\n").map(e => e.split(" ").map(Number));

let n, m, k;
const map = new Array(1005).fill(null).map(() => new Array(1005).fill(false));
//const visited = new Array(50).fill(null).map(() => new Array(50).fill(false));

let ans = 0;
let nowIdx = 0;
let queue = [];
m = input[0][0];
n = input[0][1];

//console.log(input);

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

for(let i= 0 ; i < n; i++){
    for(let j = 0; j < m; j++){
        let num = input[i + 1][j];
        map[i][j] = num;
        if(num == 1){
            queue.push([i, j]);
        }
    }
}

while(nowIdx<queue.length){
    let x = queue[nowIdx][0];
    let y = queue[nowIdx++][1];
	for(let i = 0; i<4; i++){
        let nx = x + dx[i];
        let ny = y + dy[i];
        if(nx<0 || ny<0 || nx>= n || ny>= m) continue;
        if(map[nx][ny] == 0){
            map[nx][ny] = map[x][y] +1;
            queue.push([nx, ny]);
        }
    }
}

//console.log(map);

let check = 0;
for(let i = 0; i<n; i++){
    for(let j =0;j<m; j++){
        if(map[i][j] == 0){
            check =1;
        }
        ans = Math.max(ans, map[i][j]);
    }
}

if(check == 0){
    console.log(ans - 1);
}
else{
    console.log(-1);
}