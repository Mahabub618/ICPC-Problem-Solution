
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

}
const int N = 3e4+4;
vector<int> g[N];
int a[N], level[N], even, odd, vis[N], cnt_pos, cnt_neg;
void dfs(int u, int p, int d)
{
    //debug(u);
    level[u] = d;
    if(d%2) odd+= (a[1]-a[u]), cnt_neg++;
    else even+=(a[1]-a[u]), cnt_pos++;
    for(auto v: g[u])
    {
        if(v!=p) dfs(v, u, d+1);
    }
}
int main()
{
    //init_code();
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++)
    {
        int n, u, v;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &a[i]);
        for(int i=1; i<=n; i++)
        {
            g[i].clear();
            level[i] = 0;
        }
        for(int i=1; i<n; i++)
        {
            scanf("%d %d", &u, &v);
            g[u].pb(v);
            g[v].pb(u);
        }
        even = 0;
        odd = 0;
        cnt_neg = 0;
        cnt_pos = 0;
        //even = odd = cnt_neg = cnt_pos = 0;
        dfs(1, -1, 0);
        cnt_pos--;
        int ans = (-1*odd)+even;
        int root = 1;
        int n_odd, n_even, dif, sum;
        for(int i=2; i<=n; i++)
        {
            int l = level[i];
            if(l%2 == 0)
            {
                dif = a[i]-a[1];
                n_even = even + (cnt_pos*dif) + dif;
                n_odd = odd + (cnt_neg*dif);
            }
            else
            {
                dif = a[i]-a[1];
                n_odd = even + (cnt_pos*dif) + dif;
                n_even = odd + (cnt_neg*dif);
            }
            sum = (-1*n_odd)+n_even;
            if(sum > ans)
            {
                ans = sum;
                root = i;
            }
            //debug3(i, level[i], sum);
        }
        printf("Case %d: %d\n", cs, root);
    }

return 0;
}
