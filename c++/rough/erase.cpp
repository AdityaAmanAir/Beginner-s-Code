    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int n,k,s=1;
        cin>>n>>k;
        while (k--)
        {
            s*=n;
        }
        cout<<s;
    }