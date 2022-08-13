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

int main()
{
    //init_code();
    int t;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++)
    {
        int n;
        scanf("%d", &n);
        int a[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) scanf("%d", &a[i][j]);
        }
        int cnt = 0;
        for(int i=0; i+1<n; i++)
        {
            for(int j=0; j+4<n; j++)
            {
                set<int> Set;
                for(int k=0; k<5; k++)
                {
                    Set.insert(a[i][j+k]);
                    Set.insert(a[i+1][j+k]);
                }
                //debug3(i, j, Set.size());
                if(Set.size() == 10) cnt++;
            }
        }
        for(int i=0; i<n; i++)
        {
            set<int> Set;
            if(n == 10)
            {
                set<int> Set;
                for(int j=0; j<n; j++) Set.insert(a[i][j]);
                if(Set.size() == 10) cnt++;
            }
        }
        for(int i=0; i+4<n; i++)
        {
            for(int j=0; j+1<n; j++)
            {
                set<int> Set;
                for(int k=0; k<5; k++)
                {
                    Set.insert(a[i+k][j]);
                    Set.insert(a[i+k][j+1]);
                }
                if(Set.size() == 10) cnt++;
            }
        }
        for(int j=0; j<n; j++)
        {
            if(n==10)
            {
                set<int> Set;
                for(int i=0; i<n; i++) Set.insert(a[i][j]);
                if(Set.size() == 10) cnt++;
            }
        }
        printf("Case %d: %d\n", cs, cnt);
    }
     
return 0;
}
