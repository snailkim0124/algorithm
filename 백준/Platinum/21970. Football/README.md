# [Platinum III] Football - 21970 

[문제 링크](https://www.acmicpc.net/problem/21970) 

### 성능 요약

메모리: 2296 KB, 시간: 36 ms

### 분류

수학, 게임 이론

### 제출 일자

2025년 12월 16일 14:46:45

### 문제 설명

<p>Little Square’s school is organising the annual football match. The two team captains are Little Square and Little Triangle. They will select their teams from the N classes in the school. The team selection works in the following way:</p>

<ul>
	<li>Little Square and Little Triangle alternate picking people in turns. Little Square goes first.</li>
	<li>In a turn, only students from a single class can be chosen.</li>
	<li>In a turn, at least one and at most K students can be chosen.</li>
	<li>In a turn, one must select at most as many students as were selected in the previous turn.</li>
	<li>The captain who selects the last student(s) gets the ”Fo(1)otball” prize.</li>
</ul>

<p>The captains do not care how many students they select overall, and all students are identical when it comes to football skill. They only care about the ”Fo(1)otball” prize. Assuming both have perfect strategy, who wins it ?</p>

### 입력 

 <p>Each test file will contain multiple test cases, describing different scenarios. On the first line you will find T, the number of testcases. Their descriptions follow. On the first line of a testcase you will find N and K. On the second line of a testcase you will find N positive integers, which represent the sizes of the classes in Little Square’s school.</p>

### 출력 

 <p>Output the answers for the T testcases, each on the same line, not separated by spaces. If Little Square wins the prize in a testcase, output <code>1</code>; output <code>0</code> otherwise.</p>

