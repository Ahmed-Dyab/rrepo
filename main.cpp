#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define vll vector<ll>
#define vi vector<int>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
double pi = acos(-1);
#define int long long
//#define int long long
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    //cin.tie(0); cin.sync_with_stdio(0);
}

/*ll gcd(ll a, ll b)
{
    return(b == 0) ? a : gcd(b, a % b);
}*/
ll gcd(ll a, ll b)
{
    return(b == 0) ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b) * b);
}
ll getbit(ll n, ll i)
{
    return ((n >> i) & 1);
}
int mod = (ll)1e9+7;
ll inv(ll nn, ll xx = mod - 2)
{
    return !xx ? 1 : (inv(((nn % mod) * (nn % mod)) % mod, (xx >> 1)) % mod * ((xx & 1) ? (nn % mod) : 1) % mod) % mod;
}
int dx[8] = { 1,0,-1,0,1,-1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,-1,1};

int solve(int ttttc)
{
    int n,k;
    cin>>n;
    vector<int>a(n+1),b(n+1);
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>a[i+1];
        s.insert(i+1);
    }
    int q;cin>>q;
    while(q--){
        int t;cin>>t;
        if(t==1){
            int p,x;cin>>p>>x;
            auto it=s.lower_bound(p);
            if(it==s.end())continue;
            while(it!=s.end()&&x){
                if(a[*it]-b[*it]>x){
                    b[*it]+=x;
                    x=0;
                    it++;
                }
                else {
                    x-=(a[*it]-b[*it]);
                    b[*it]=a[*it];
                    auto iit=it;
                    it++;
                    s.erase(iit);
                }
            }
        }
        else {
            int x;cin>>x;
            cout<<b[x]<<"\n";
        }
    }
    return 0;
}
signed main()
{
    //memset(vs,-1,sizeof(vs));
    /*for(int i=0;i<n;i++)*/
    //freopen("street.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //memset(dp,-1,sizeof(dp));
    //memset(vs,-1,sizeof(vs));
    fast();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {

        //cout<<"Case #"<<ttttc<<": ";
        solve(tc);
        if (tc != T)
            cout << "\n"
                 ;

    }
    return 0;
}
