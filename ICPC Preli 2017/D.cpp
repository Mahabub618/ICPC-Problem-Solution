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
const int N = 40004;
int par[N], one[N], sz[N];
int Root(int u)
{
    if(par[u] == u) return u;
    else
    {
        par[u] = Root(par[u]);
        return par[u];
    }
}

struct edge
{
    int w, u, v;
    bool operator<(const edge& p) const
    {
        return w<p.w;
    }
};
int main()
{
    //init_code();
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++)
    {
        int n, m, u, v, w;
        scanf("%d %d", &n, &m);
        priority_queue<edge> pq;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            if(u > v) swap(u, v);
            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            pq.push(get);
        }
        int q;
        scanf("%d", &q);
        vector<pii> vv;
        for(int i=1; i<=q; i++)
        {
            scanf("%d", &u);
            vv.pb({u, i});
        }
        sort(vv.rbegin(), vv.rend());
        int tot = 1;
        for(int i=1; i<=n; i++)
        {
            par[i] = i;
            sz[i] = 1;
            one[i] = 0;
        }
        map<int, int> ans;
        one[1] = 1;
        for(int i=0; i<q; i++)
        {
            int qv = vv[i].F;
            int id = vv[i].S;
            
            while(!pq.empty() and pq.top().w >= qv)
            {
                u = pq.top().u;
                v = pq.top().v;
                w = pq.top().w;
                //debug4(qv, u, v, w);
                pq.pop();
                
                int ru = Root(u);
                int rv = Root(v);
                
                if(ru == rv) continue;
                else
                {
                    if(sz[ru] > sz[rv])
                    {
                        par[rv] = ru;
                        
                        if(one[ru] > 0) tot += sz[rv];
                        else if(one[rv] > 0) tot += sz[ru], one[ru] = 1;
                        sz[ru] += sz[rv];
                    }
                    else
                    {
                        par[ru] = rv;
                        
                        if(one[ru] > 0) tot += sz[rv], one[rv] = 1;
                        else if(one[rv] > 0) tot += sz[ru];
                        sz[rv] += sz[ru];
                    }
                }
            }
            ans[id] = tot-1;
        }
        printf("Case %d:\n", cs);
        for(int i=1; i<=q; i++) printf("%d\n", ans[i]);
    }
     
return 0;
}
