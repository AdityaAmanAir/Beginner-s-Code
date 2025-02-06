#include <iostream>
using namespace std;
int main(){
unsigned int t, d = 0, h = 0, m = 0, y = 0;
cin >> t;
while (31536000 <= t){
   t -= 31536000;
   ++y;
}
while (86400 <= t){
   t -= 86400;
   ++d;
}
while (3600 <= t){
   t -= 3600;
   ++h;
}
while (60 <= t){
   t -= 60;
   ++m;
}
if ((m != 0) || (h != 0) || (y != 0) || (d != 0)){
   if ((h != 0) || (y != 0) || (d != 0)){
      if ((y != 0) || (d != 0)){
         if (y != 0){
               cout << y;
               if (y == 1){
                  cout << " year, ";
               }
               else{
                  cout << " years, ";
               }
               cout << d;
               if (d == 1){
                  cout << " day, ";
               }
               else{
                 cout << " days, ";
               }
               cout << h;
               if (h == 1){
                  cout << " hour, ";
               }
               else{
                  cout << " hours, ";
               }
               cout << m;
               if (m == 1){
                  cout << " minute and ";
               }else{
                 cout << " minutes and ";
               }
               cout << t;
               if (t == 1){
                  cout << " second";
               }else{
                  cout << " seconds";
               }
            }else{
               cout << d;
               if (d == 1){
                  cout << " day, ";
               }else{
                 cout << " days, ";
               }
               cout << h;
               if (h == 1){
                  cout << " hour, ";
               }else{
                  cout << " hours, ";
               }
               cout << m;
               if (m == 1){
                  cout << " minute and ";
               }else{
                 cout << " minutes and ";
               }
               cout << t;
               if (t == 1){
                  cout << " second";
               }else{
                 cout << " seconds";
               }
            }
         }else{
            cout << h;
            if (h == 1){
               cout << " hour, ";
            }else{
               cout << " hours, ";
            }
            cout << m;
            if (m == 1){
               cout << " minute and ";
            }else{
              cout << " minutes and ";
            }
            cout << t;
            if (t == 1){
               cout << " second";
            }else{
              cout << " seconds";
            }
         }
      }else{
         cout << m;
       if (m == 1){
          cout << " minute and ";
       }else{
         cout<< " minutes and";
       }
       cout << t;
       if (t == 1){
          cout << " second";
       }else{
         cout << " seconds";
       }
     }  
   }else{
      cout << t;
      if (t == 1){
         cout << " second";
      }else{
         cout << " seconds";
      }
   }
}