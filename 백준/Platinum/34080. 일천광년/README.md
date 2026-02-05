# [Platinum IV] 일천광년 - 34080 

[문제 링크](https://www.acmicpc.net/problem/34080) 

### 성능 요약

메모리: 2020 KB, 시간: 224 ms

### 분류

수학, 애드 혹, 불변량 찾기

### 제출 일자

2026년 2월 5일 22:36:15

### 문제 설명

<blockquote>
<p><em><strong>일천광년 앞으로</strong></em></p>

<p><em><strong>끊기지 않을 실로 이어줄래</strong></em></p>

<p><em><strong>그 소매에 사랑을 숨겨보고파</strong></em></p>

<p>    —  一千光年 - iyowa</p>
</blockquote>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/289baa03-7f30-4ea4-9238-ca7403799c81/-/preview/" style="width:100%;min-width:500px"></p>


<p><span style="color:#1abc9c;">미쿠</span>는 모래의 행성에, <span style="color:#9b59b6;">플라워</span>는 모래의 행성으로부터 $N\ \text{km}$ 떨어진 푸른 행성에 살고 있다. <span style="color:#1abc9c;">미쿠</span>와 <span style="color:#9b59b6;">플라워</span>는 어느 날, 넘치는 <strong>사랑</strong>을 서로에게 전하기로 했다!</p>

<p>모래의 행성에서 푸른 행성 방향으로 $i\ \text{km}$ 떨어진 위치에 있는 <strong>사랑</strong>의 양은 $L_i$로 표현되며, 초기에는 $L_0=x$, $L_N=y$, $L_j = 0$ ($1 \leq j < N$)이다.</p>

<p><span style="color:#1abc9c;">미쿠</span>와 <span style="color:#9b59b6;">플라워</span>는 $1$의 시간이 지날 때마다 다음과 같이 서로를 향해 <strong>사랑</strong>을 옮긴다. </p>

<ul>
	<li>$L_i \neq 0$을 만족하는 $i$ 중에서 $i$의 최솟값과 최댓값을 각각 $l$과 $r$, 이때의 $\min(L_l,L_r)$을 $M$이라고 하자.</li>
	<li>$r-l>1$인 경우, $L_l$과 $L_r$의 값을 $M$만큼 감소시키고, $L_{l+1}$과 $L_{r-1}$의 값을 $M$만큼 증가시킨다.</li>
	<li>$r-l \leq 1$인 경우, 옮겼을 때 서로의 뜨거운 <strong>사랑</strong>이 너무 가까워져 <span style="color:#1abc9c;">미쿠미쿠해지므로<strong>♪</strong></span> <strong>사랑</strong> 옮기기를 중단한다.</li>
</ul>

<p><span style="color:#1abc9c;">미쿠</span>와<span style="color:#9b59b6;"> 플라워</span>는 여러 상황에서 <strong>사랑</strong>이 어디에 도달할지 궁금해졌다.  $39^{39^{39}}$의 시간이 지났을 때, $Q$개의 상황에 대해 <strong>사랑</strong>이 존재하는 위치와 <strong>사랑</strong>의 양을 구해 주자!</p>

### 입력 

 <p>첫 번째 줄에 상황의 수 $Q$가 주어진다.</p>

<p>두 번째 줄부터 $Q+1$번째 줄까지 각 줄에 양의 정수 $N$, $x$, $y$가 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>주어진 $Q$개의 각 상황에 대해, 첫 번째 줄에 <strong>사랑</strong>이 존재하는 위치의 수를 출력한다.</p>

<p>두 번째 줄부터는 모든 <strong>사랑</strong>이 존재하는 위치에 대해, 각 줄에 모래의 행성에 가까운 순으로 모래의 행성으로부터 <strong>사랑</strong>이 존재하는 위치까지의 거리와 <strong>사랑</strong>의 양을 공백으로 구분하여 출력한다.</p>

