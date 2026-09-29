#include <string>
#include <vector>

using namespace std;

int go(int a, int b, int n) {
    // 기저 사례
    if(n < a) return 0;
    
    int cola = (n / a) * b;
    int bottle = n % a;
    
    return cola + go(a, b, cola + bottle);
}

int solution(int a, int b, int n) {
    int answer = 0;
    
    answer = go(a, b, n);
    
    return answer;
}