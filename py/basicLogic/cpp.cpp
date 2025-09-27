#include<bits/stdc++.h>
using namespace std;
int main(){

    long long int t; cin>>t;
    while(t--){
        long long int n,k;cin>>n>>k;
        long long int pro[n];
        long long int dis[k];
        for(int i=0; i<n; i++){
            cin>>pro[i];
        }
        for (int j=0; j<k; j++){
            cin>>dis[j];
        }
        sort(pro, pro + n, std::greater<int>());
        sort(dis, dis + k);
long long int count=0;
        for(int i : dis){
            
            while(pro[i-1+count]==0){
            }pro[i-1+count]=0;
            count+=i;
        }

        long long int sum=0;
        for (int i = 0; i < n; ++i) {
        sum += pro[i]; 
    }
    cout<<sum<<"\n";
    }

    return 0;
}