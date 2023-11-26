#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
using namespace std;
void solve()
{
    ll n,v,x;
    cin>>n>>v>>x;
    ll ans=min(v*3,n)*x+v*x+x;
    cout<<ans<<endl;
}
int main()
{
    ios;
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}


