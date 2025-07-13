#include <iostream>

using namespace std;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t=0, n=0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int xx = n,a, c0 = 0, c1 = 0, c2 = 0, c3 = 0, c5 = 0,ans;
        while (n--)
        {
            cin >> a;
            if (a == 0){c0++;}
            else if (a == 1){c1++;}
            else if (a == 2){c2++;}
            else if (a == 5){c5++;}
            else if (a == 3){c3++;}
            if (c0 >=3 && c1 >=1 && c2 >=2 && c3 >=1 && c5 >=1 && ans ==0 ){
                ans= xx - n ;
                

            }
            
        }
        cout<<ans<<"\n";
    }

    return 0;
}