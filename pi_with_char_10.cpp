#include "num_sys_1.hpp"
num arctan(num x){
    num xx = x*x;
    num ans(0);
    num term(x);
    for(int i=1;; i+=2){
        if ( (i/2)%2 ) ans -= term * (num(i).rec());
        else ans += term * (num(i).rec());
        term = term * xx;
        if(term == 0) return ans;
    }
    return ans;
}
int main(){
    clock_t tStart = clock();
    num pi = (arctan(num(0.2)) * 16 ) - ( arctan(num(239).rec()) * 4 );
    prt(pi); 
    cout<<endl;
    printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;

}