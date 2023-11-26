#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    vector<ll>s;
    ll mb=0;
    ll cb=0;
    while(n--)
    {
        int x1;
        cin>>x1;
        if(x1==1)
        {
            ll x2;
            cin>>x2;
            cb+=x2;
            mb=max(mb,cb);
            s.pb(x2);

        }
        else{
            assert(!s.empty());
            cb-=s.back();
            s.pop_back();
        }
    }
    cout<<mb<<endl;
    
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


