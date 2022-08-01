num operator << (int b){
//     num ans;
//     if(b>0) {
//         int i=b;
//         for(;i>2*M;i--) ans.x[i-b] = x[i];
//         for(;i-b>2*M; i--) ans.x[i-b] =0;
//         return ans;
//     }
//     b = -b;
//     char l = x[0]>4 ? 9:0;
//     int i = 2*M -1 - b;
//     for(;i>=0;i--) ans.x[i+b] = x[i];
//     for(;i+b>0; i--) ans.x[i+b] = l;
//     return ans;
// }
// num operator >> (int b){
//     num ans;
//     if(b>0) {
//         char l = x[0]>4 ? 9:0;
//         int i = 2*M -1 - b;
//         for(;i>=0;i--) ans.x[i+b] = x[i];
//         for(;i+b>0; i--) ans.x[i+b] = l;
//     }
//     return *this << (-b);
// }    // multiplication
