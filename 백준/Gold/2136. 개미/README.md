# [Gold I] 개미 - 2136 

[문제 링크](https://www.acmicpc.net/problem/2136) 

### 성능 요약

메모리: 6004 KB, 시간: 20 ms

### 분류

정렬, 애드 혹, 불변량 찾기

### 제출 일자

2025년 7월 11일 14:34:12

### 문제 설명

<p>길이가 L(2 ≤ L ≤ 1,000,000,000)인 막대기 위에 N(1 ≤ N ≤ 100,000)마리의 개미들이 서로 다른 위치에 살고 있다. 개미들은 크기가 매우 작기 때문에 이 문제에서는 개미가 크기가 없는 점이라고 생각하자. 각각의 개미의 위치는 x좌표로 표시되며, 좌표값은 0보다 크고 L보다 작은 값으로 표현된다.</p>

<p>각각의 개미는 왼쪽, 혹은 오른쪽으로 움직이고 있다. 모든 개미들은 똑같은 속도로, 1초에 한 칸씩 움직인다. 개미들이 움직이는 도중에 서로 부딪히는 경우가 생길 수도 있다. 두 마리의 개미가 서로 부딪혔을 때, 두 마리의 개미는 모두 즉시 방향을 바꾸어 다시 움직이게 된다.</p>

<p>개미들이 이동하다가 0인 위치나 L인 위치에 도달하게 되면, 그 개미는 막대기 아래로 떨어지게 된다. 개미들의 초기상태가 주어졌을 때, 가장 마지막에 떨어지는 개미와 그 개미가 떨어지는 시각을 알아내는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 두 정수 N, L이 주어진다. 다음 N개의 줄에는 각 개미의 초기 위치가 주어진다. 초기 위치가 양수로 주어지는 경우는 그 값이 그 개미의 위치가 되며, 그 개미는 오른쪽으로 움직이고 있다. 초기 위치가 음수로 주어지는 경우에는 그 절댓값이 그 개미의 위치가 되며, 그 개미는 왼쪽으로 움직이고 있다. 예를 들어 3이 주어지는 경우에는 3인 위치에서 오른쪽으로 움직이고 있고, -7인 경우에는 7인 위치에서 왼쪽으로 움직이고 있다.</p>

### 출력 

 <p>첫째 줄에 두 정수 i, t를 출력한다. i는 가장 마지막에 떨어지는 개미의 번호이다. 개미의 번호는 입력에서 주어지는 순서대로 1, 2, …, N이다. t는 가장 마지막에 떨어지는 개미가 바닥에 떨어지는 시간이다. 가장 마지막에 떨어지는 개미가 여러 마리인 경우는 없다고 가정한다.</p>

