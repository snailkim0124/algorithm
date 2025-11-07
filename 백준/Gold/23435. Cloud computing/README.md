# [Gold I] Cloud computing - 23435 

[문제 링크](https://www.acmicpc.net/problem/23435) 

### 성능 요약

메모리: 19860 KB, 시간: 5016 ms

### 분류

자료 구조, 세그먼트 트리, 해 구성하기, 분할 정복

### 제출 일자

2025년 11월 7일 22:05:56

### 문제 설명

<p>Cloud computations are gaining popularity as a powerful and versatile tool. However, they are seriously flawed: processing your data on a remote computer puts your information safety at risk.</p>

<p>Vanya works in an Organization which implemented cloud computing for calculating order statistics of arrays. An order statistic of an array for a specific <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>k</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$k$</span></mjx-container> is the value of the element, which is <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>k</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$k$</span></mjx-container>th in the array, if the array is sorted.</p>

<p>However, the array which requires order statistics is extremely classified. The only thing known about it is that all its elements are different. With this in mind, Vanya came up with the following scheme: the array is stored on the Organization's server, and the cloud server performing the order statistics calculations can access the Organization's server to get the results of the comparison of two elements of the array. In this manner, the cloud server can define the position of the <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>k</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$k$</span></mjx-container>th order statistic, and the classified array is never revealed to the cloud server. This produces another problem: the number of requests from the cloud server to the Organization's server should not be exceedingly large.</p>

<p>In particular, Vanya decided to limit the calculations of the second order statistics to no more than <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>+</mo><mn>20</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N + 20$</span></mjx-container> requests, where <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> is the size of the array. Help Vanya implement an algorithm of finding the second smallest element of the classified array, such that it complies to this limitation.</p>

### 입력 

 Empty

### 출력 

 Empty

