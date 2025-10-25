# [Platinum II] Blokada - 8551 

[문제 링크](https://www.acmicpc.net/problem/8551) 

### 성능 요약

메모리: 14712 KB, 시간: 48 ms

### 분류

그래프 이론, 최대 유량, 최대 유량 최소 컷 정리

### 제출 일자

2025년 10월 25일 15:06:17

### 문제 설명

<p>Już w zeszłym roku UOB (Urząd Ochrony Bajtocji) dowiedział się o planowanym zamachu na bajtockie łącza internetowe. Długie śledztwo wykazało, że za tym zamachem stoi jedna osoba. Mózgiem całej operacji jest prawdopodobnie pewien informatyk ukrywjący się pod pseudonimem "S**" (nie możemy go całkowicie ujawnić ze względu na dobro śledztwa). Jednakże od kilku miesięcy nie mozna go znaleźć mimo poszukiwań na wielką skalę. Ze zdobytych podczas śledztwa informacji wynika, że celem ataku będzie uniemożliwienie wysyłania komunikatów z serwera 1 do serwera <em>n</em>. Wiadomo, że Bajtocki Internet niewiele różni się od tego jaki znamy. Składa się on z serwerów i łączy internetowych pomiędzy nimi. Jednakże bajtockie łącza są jednokierunkowe. Przebiegły informatyk "S**" pozakładał pułapki na łączach. Po aktywacji pułapka przerywa łącze, na którym została założona. Wiadomo, że "S**" zlecił założenie możliwie najmniejszej liczby pułapek, ale w sposób uniemożliwiający komunikację od serwera 1 do serwera <em>n</em>. UOB zwraca się do Ciebie (jako najlepszego programisty :-)) z prośbą o pomoc. Chciałby wiedzieć ile pułapek polecił założyć "S**" (jak je znaleźć to już inna historia).</p>

### 입력 

 <p>Na wejściu znajdują się informacje na temat bajtockiej sieci internetowej. W pierwszej lini są podane liczby <em>n</em> i <em>m</em>, 2 ≤ n ≤ 10 000, oznaczające odpowiednio liczbę serwerów i łączy. Serwery ponumerowane są od 1 do <em>n</em>. W następnych <em>m</em> wierszach znajdują się opisy łączy. Opis każdego łącza składa się z liczb <em>a</em> i <em>b</em>, 1 ≤ <em>a</em>, <em>b</em> ≤ <em>n</em>, <em>a</em> ≠ <em>b</em>. Oznaczają one, że istnieje łącze od serwera <em>a</em> do serwera <em>b</em>. Wiadomo, że pomiędzy dwoma dowolnymi serwerami może istnieć tylko jedno bezpośrednie łącze.</p>

### 출력 

 <p>Na wyjściu powinna znaleźć się jedna liczba - minimalna liczba pułapek, które polecił zastawić "S**", żeby przerwać połączenie pomiędzy serwerami 1 i <em>n</em>.</p>

