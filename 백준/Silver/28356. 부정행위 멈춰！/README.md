# [Silver III] 부정행위 멈춰! - 28356 

[문제 링크](https://www.acmicpc.net/problem/28356) 

### 성능 요약

메모리: 2020 KB, 시간: 52 ms

### 분류

해 구성하기

### 제출 일자

2025년 6월 26일 14:36:37

### 문제 설명

<p>김채완 교수는 “프로그래밍과 봉사” 과목의 기말고사를 준비하고 있다. 고사실은 가로 $M$칸, 세로 $N$칸인 직사각형 형태이며, 모든 칸마다 정확히 한 명의 학생이 앉게 된다. 김채완 교수는 학생들의 부정행위를 막기 위해 모든 학생이 인접한 칸의 학생과 다른 시험지를 받을 수 있도록 여러 종류의 시험지를 준비하려 한다. 이때 인접한 학생은 가로, 세로, 또는 대각선으로 붙어 있는 칸에 있는 학생을 의미한다.</p>

<p>김채완 교수는 많은 종류의 시험지를 준비할 시간이 없었기 때문에 시험지의 종류를 최소화하고자 한다. 가능한 한 적은 종류의 시험지를 사용하여 조건을 만족하도록 시험지를 배부하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 정수 $N$, $M$이 공백으로 구분되어 주어진다. $(1 \leq N, M \leq 1\,000)$</p>

### 출력 

 <p>첫째 줄에 사용한 시험지의 종류의 수 $K$를 출력한다.</p>

<p>둘째 줄부터 $N$개의 각 줄에 $1$ 이상 $K$ 이하의 정수 $M$개를 공백으로 구분하여 출력한다. 각 정수는 해당 칸에 배부된 시험지의 번호를 의미한다. 즉, $y+1$번째 줄의 $x$번째 정수는 위에서 $y$번째, 왼쪽에서 $x$번째 칸에 배부된 시험지의 번호이다.</p>

