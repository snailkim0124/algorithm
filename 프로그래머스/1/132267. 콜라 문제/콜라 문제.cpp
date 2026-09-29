#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n >= a) {
        int cola = (n / a) * b;
        int bottle = n % a;
        
        answer += cola;
        n = cola + bottle;
    }
    
    return answer;
}