# [Platinum IV] Prehistoric Programs - 26137 

[문제 링크](https://www.acmicpc.net/problem/26137) 

### 성능 요약

메모리: 45168 KB, 시간: 384 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2025년 8월 7일 18:28:27

### 문제 설명

<p>Archaeologists have discovered exciting clay tablets in deep layers of Alutila Cave. Nobody was able to decipher the script on the tablets, except for two symbols that seem to describe nested structures not unlike opening and closing parentheses in LISP. Could it be that humans wrote programs thousands of years ago?</p>

<p>Taken together, the tablets appear to describe a great piece of work – perhaps a program, or an epic, or even tax records! Unsurprisingly, after such a long time, the tablets are in a state of disorder. Your job is to arrange them into a sequence so that the resulting work has a properly nested parenthesis structure. Considering only opening and closing parentheses, a properly nested structure is either</p>

<ul>
	<li>(), or</li>
	<li>(A), where A is a properly nested structure, or</li>
	<li>AB, where A and B are properly nested structures.</li>
</ul>

### 입력 

 <p>The first line of input contains one integer n (1 ≤ n ≤ 10<sup>6</sup>), the number of tablets. Each of the remaining n lines describes a tablet, and contains a non-empty string of opening and closing parentheses; symbols unrelated to the nesting structure are omitted. The strings are numbered from 1 to n in the order that they appear in the input. The input contains at most 10<sup>7</sup> parentheses.</p>

### 출력 

 <p>Output a permutation of the numbers from 1 to n such that concatenating the strings in this order results in a properly nested structure. If this happens for multiple permutations, any one of them will be accepted. If there is no such permutation, output <code>impossible</code> instead.</p>

