/**********************/
/* Mahabub Rahman     */
/* Cse 10th           */
/* Comilla University */
/**********************/

#include<bits/stdc++.h>
using namespace std;
#define       ll                  long long int
#define       veci                 vector<int>
#define       vecl                 vector<long long int>
#define       pb                   push_back
#define       newline cerr << endl
#define       pii                  pair<int, int>
#define       F                    first
#define       S                    second
#define       nl                   "\n"
#define       all(v)               v.begin(), v.end()
///============ CONSTANT ===============///
#define mx9   1000000007
#define mx5   200005
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mod   mx9
///=============== Debugging ============================///
#ifndef ONLINE_JUDGE
#define       debug(x) cout << #x << " = " << x << endl
#define       debug2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define       debug3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define       debug4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#endif
void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif    
}
const int N = 1e5+5;
ll fact[N];
void pre_compute()
{
    fact[0] = 1;
    for(int i=1; i<N; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
}
ll power(ll x, ll y, int p)
{
    ll res = 1;
    x = x%p;
    while(y > 0)
    {
        if(y&1) res = (res*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}
ll mod_inverse(ll n, int p)
{
    return power(n, p-2, p);
}
ll ncrMod(ll n, ll r, int p)
{
    if(n < r) return 0;
    if(r == 0) return 1;
    return (fact[n]*mod_inverse(fact[r], p)%p * mod_inverse(fact[n-r], p)%p)%p;
}
int main()
{
    //init_code();
    pre_compute();
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++)
    {
        int n, m, x, y;
        scanf("%d %d", &n, &m);
        deque<pii> a;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &x, &y);
            a.pb({x, y});
        }
        if(a.back().F != n-1) a.pb({n, n});
        if(a.front().F != 0) a.push_front({-1, 1});
        
        ll tot = 1LL;
        
        for(int i=a.size()-2; i>=0; i--)
        {
            x = a[i].F, y = a[i].S;
            int xx = a[i+1].F, yy = a[i+1].S;
            if(xx-x > 1)
            {
                int ghor = xx-x-1;
                int gap = yy-y;
                
                ghor+=gap;
                ll val = ncrMod(ghor, gap, mod);
                //debug3(ghor, gap, val);
                tot = tot*val;
                tot = (tot+mod)%mod;    
            }
        }
        printf("Case %d: %lld\n", cs, tot);
    }
    
     
return 0;
}
