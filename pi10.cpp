#include<iostream>
using namespace std;
#define ld long double
ld rt(ld num ){
    ld guess = num /2.0;
    for(;;){

        ld error = guess * guess - num;
        if(abs(error) < (ld)1.0e-18) break;
        guess = (guess + num/guess )/2.0;
    }
    guess = (guess + num/guess )/2.0;guess = (guess + num/guess )/2.0;
    return guess;
}
int main(){
    ld u = rt(2) -1.0, w=u*u;
    long double pi=0.0;
    printf("%.20Lf\n" , u);

    for(long double i = 1.0, prev = u ; i<48.0; i = i +2.0 , prev = prev *(-1.0)*(w)){
        pi = pi +  prev/i;
        
    }
    printf("%.18Lf\n", 8.0*pi);
    return 0;
}