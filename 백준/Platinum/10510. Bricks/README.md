# [Platinum V] Bricks - 10510 

[문제 링크](https://www.acmicpc.net/problem/10510) 

### 성능 요약

메모리: 4192 KB, 시간: 988 ms

### 분류

그리디 알고리즘

### 제출 일자

2026년 2월 6일 22:22:12

### 문제 설명

<p>You are given a sequence of white (W) and black (B) bricks. The goal is to partition it into some number of non-empty, contiguous blocks, each one having the same ratio of white and black bricks.</p>

<p>Of course one can always “partition” the sequence into one single block (which is not very interesting). We want, however, to have as many blocks as possible. Consider for example the following sequences and its partitions:</p>

<ul>
	<li>BWWWBB = BW + WWBB (ratio 1:1),</li>
	<li>WWWBBBWWWWWWWWWB = WWWB + BBWWWWWW + WWWB (ratio 3:1).</li>
</ul>

<p>Note that both of these partitions are optimal with respect to the number of blocks.</p>

### 입력 

 <p>The first line of input contains the number of test cases T. The descriptions of the test cases follow:</p>

<p>Each test case starts with one line containing an integer n (1 ≤ n ≤ 10<sup>5</sup>) which is the length of the description of a sequence. Each of the following n lines consists of an integer k (1 ≤ k ≤ 10<sup>9</sup>) and one of the characters W or B, meaning that k bricks of the given color follow next in the sequence. It is guaranteed that the total length of the brick sequence does not exceed 10<sup>9</sup>.</p>

### 출력 

 <p>For each test case, output a single line containing the largest possible number of blocks.</p>

