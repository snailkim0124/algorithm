# [Platinum V] Consecutive Primes - 23005 

[문제 링크](https://www.acmicpc.net/problem/23005) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2026년 1월 31일 20:28:46

### 문제 설명

<p>Ada has bought a secret present for her friend John. In order to open the present, Ada wants John to crack a secret code. She decides to give him a hint to make things simple for him. She tells him that the secret code is a number that can be formed by taking the product of two consecutive <a href="https://en.wikipedia.org/wiki/Prime_number">prime numbers</a>, such that it is the largest number that is smaller than or equal to $Z$. Given the value of $Z$, help John to determine the secret code.</p>

<p>Formally, let the order of prime numbers 2, 3, 5, 7, 11, ... be denoted by $p_1$, $p_2$, $p_3$, $p_4$, $p_5$, ... and so on. Consider $R_i$ to be the product of two consecutive primes $p_i$ and $p_{i+1}$. The secret code is the largest $R_j$ such that $R_j \le Z$.</p>

### 입력 

 <p>The first line of the input gives the number of test cases, $T$. $T$ lines follow.</p>

<p>Each line contains a single integer $Z$, representing the number provided by Ada as part of the hint.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where $x$ is the test case number (starting from 1) and $y$ is the secret code - the largest number less than or equal to $Z$ that is the product of two consecutive prime numbers.</p>

