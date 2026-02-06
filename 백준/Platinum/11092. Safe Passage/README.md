# [Platinum V] Safe Passage - 11092 

[문제 링크](https://www.acmicpc.net/problem/11092) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그리디 알고리즘, 비트마스킹, 최단 경로, 데이크스트라, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2026년 2월 6일 16:36:20

### 문제 설명

<p>A group of friends snuck away from their school campus, but now they must return from the main campus gate to their dorm while remaining undetected by the many teachers who patrol the campus. Fortunately, they have an invisibility cloak, but it is only large enough to cover two people at a time. They will take turns as individuals or pairs traveling across campus under the cloak (and by necessity, returning the cloak to the gate if others remain). Each student has a maximum pace at which he or she is able to travel, yet if a pair of students are walking under the cloak together, they will have to travel at the pace of the slower of the two. Their goal is to have everyone back at the dorm as quickly as possible.</p>

<p>As an example, assume that there are four people in the group, with person A able to make the trip in 1 minute, person B able to travel in 2 minutes, person C able to travel in 7 minutes, and person D able to travel in 10 minutes. It is possible to get everyone to the dorm in 17 minutes with the following plan:</p>

<ul>
	<li>A and B go from the gate to the dorm together (taking 2 minutes)</li>
	<li>A returns with the cloak to the gate (taking 1 minute)</li>
	<li>C and D go from the gate to the dorm together (taking 10 minutes)</li>
	<li>B returns with the cloak to the gate (taking 2 minutes)</li>
	<li>A and B go from the gate to the dorm together (taking 2 minutes)</li>
</ul>

### 입력 

 <p>The input is a single line beginning with an integer, 2 ≤ N ≤ 15. Following that are N positive integers that respectively represent the minimum time in which each person is able to cross the campus if alone; these times are measured in minutes, with each being at most 5 000. (It is a very large campus!)</p>

### 출력 

 <p>Output the minimum possible time it takes to get the entire group from the gate to the dorm.</p>

