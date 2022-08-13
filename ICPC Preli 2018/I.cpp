/**    Tuhin ahmed                    **
*      Email:tuhin107494@gmail.com     *
*      university:comilla university  **
*/
#include<bits/stdc++.h>
using namespace std;
#define TT ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define       ll                   long long int
#define       ull                  unsigned long long int
#define       vi                   vector<int>
#define       vc                   vector<char>
#define       vs                   vector<string>
#define       vll                  vector<long long int>
#define       vp                   vector<  pair<int,int> >
#define       pb                   push_back
#define       pob                  pop_back
#define       pll                  pair<long long  int, long long int>
#define       F                    first
#define       S                    second
#define       sc(x)                scanf("%lld",&x)
#define       sci(x)                scanf("%d",&x)
#define       sc2(x,y)             scanf("%lld %lld",&x,&y)
#define       pf                   printf
#define       min3(a,b,c)          min(a,b<c?b:c)
#define       max3(a,b,c)          max(a,b>c?b:c)
#define       all(v)               v.begin(), v.end()
#define       rall(v)               v.rbegin(), v.rend()
///============ CONSTANT ===============///
#define mx18  1000000000000000000
#define mx9   1000000007
#define mx8   100000007
#define mx7   10000006
#define mx6   1000056
#define mx5   200095
#define mx4   10005
#define inf   1<<30
#define eps   1e-9
#define mod   mx9
ll dx[]= {1,1,-1,-1,2,-2,2,-2};
ll dy[]= {2,-2,2,-2,1,1,-1,-1};
long double PI = acosl(-1);
///=============== Debugging ============================///
#define       debug(x) cerr << #x << " = " << x << endl
#define       debug2(x, y)             cerr << #x << ": " << x << "  " << #y << ": " << y << endl;
#define       debug3(x, y, z)          cerr << #x << ": " << x << "  " << #y << ": " << y << "  " << #z << ": " << z << endl;
#define       debug4(a, b, c, d)       cerr << #a << ": " << a << "  " << #b << ": " << b << "  " << #c << ": " << c << "  " << #d << ": " << d << endl;
///=====================Bitmask===================///
//ordered_set st;
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
///========================================FUNCTION=========================================///
//bool check(int n){if(n==1) return false; for(int i=2; i*i<=n; i++){if(n%i==0) return false;} return true;}
//ll fact(ll n){if(n==0 or n==1)return 1; else return ((n%mod)*fact(n-1)%mod)mod;}
ll big_mod(ll b,ll p,ll m )
{
    ll res=1;
    while(p!=0)
    {
        if(p&1)res=(res*b)%m;
        b=(b*b)%m;
        p=p>>1;
    }
    res=(res)%m;
    return res;
}
//void seive(){for(ll i=2; i<mx6; i++){if(visit[i])continue;dv[i]=i;for(ll j=i*i; j<mx6; j+=i){dv[j]=i;visit[j]=true;}}}
//void build(int u,int b,int e){if(b==e){tr[u]=dif[b];return;}ll mid=(b+e)/2;build(2*u,b,mid);build(2*u+1,mid+1,e);tr[u]=gcd(tr[(2*u)],tr[(2*u)+1]);}
//ll quary(int u,int b,int e,int i,int j){if(e<i or b>j)return 0;else if(b>=i and e<=j){return tr[u];}int   mid=(b+e)/2;ll  left=quary(2*u,b,mid,i,j);ll right=quary((2*u)+1,mid+1,e,i,j);return  gcd(left,right);}
//void  update (int u,int b,int e,int i,int j,int x){if(e<i or b>j)return;else if(b>=i and e<=j){tr[u]=x;return;}int mid=(b+e)/2;update(2*u,b,mid,i,j,x);update((2*u)+1,mid+1,e,i,j,x);tr[u]=max(tr[2*u],tr[2*u +1]);}

//vector<ll> kmp_prefix_fun(string s){ll n=s.size();vector<ll>pi(n);for(ll i=1; i<n; i++){ll j=pi[i-1];while(j>0 and s[i]!=s[j])j=pi[j-1];if(s[i]==s[j])++j;pi[i]=j;}return pi;}
//void trie_add_string(string s){int cur=1;cnt[cur]++;for(int i=0; i<s.size(); i++){int  ch=s[i]-'a';if(!to[cur][ch])to[cur][ch]=++to_node;cur=to[cur][ch];cnt[cur]++;}track[cur]++;}
//int trie_quary(string s){int cur=1;for(int i=0; i<s.size(); i++){int ch=s[i]-'a';if(!to[cur][ch])return cnt[cur];cur=to[cur][ch];}return cnt[cur];}
//void sparse_table(){for(int i=1;i<=n;i++)table[i][0]=a[i];for(int k=1;k<20;k++){for(int i=1;i+(1<<k)-1<=n;i++){table[i][k]=min(table[i][k-1],table[i+(1<<(k-1))][k-1]);}}}
//int sparse_quary(int l,int r){int len=r-l+1;int k=log2(len);return min(table[l][k],table[r-(1<<k)+1][k]);}
///====================================StartHere=================////////////
#define ff first
#define ss second
#define mp make_pair
typedef long long LL;
typedef pair<LL, LL> PLL;

const PLL M=mp(1e9+7, 1e9+9);   ///Should be large primes
const LL base=347;              ///Should be a prime larger than highest value
const int N = 1e6+7;            ///Highest length of string
///Highest length of string

ostream& operator<<(ostream& os, PLL hash)
{
    return os<<"("<<hash.ff<<", "<<hash.ss<<")";
}

PLL operator+ (PLL a, LL x)
{
    return mp(a.ff + x, a.ss + x);
}
PLL operator- (PLL a, LL x)
{
    return mp(a.ff - x, a.ss - x);
}
PLL operator* (PLL a, LL x)
{
    return mp(a.ff * x, a.ss * x);
}
PLL operator+ (PLL a, PLL x)
{
    return mp(a.ff + x.ff, a.ss + x.ss);
}
PLL operator- (PLL a, PLL x)
{
    return mp(a.ff - x.ff, a.ss - x.ss);
}
PLL operator* (PLL a, PLL x)
{
    return mp(a.ff * x.ff, a.ss * x.ss);
}
PLL operator% (PLL a, PLL m)
{
    return mp(a.ff % m.ff, a.ss % m.ss);
}

PLL power (PLL a, LL p)
{
    if (p==0)   return mp(1,1);
    PLL ans = power(a, p/2);
    ans = (ans * ans)%M;
    if (p%2)    ans = (ans*a)%M;
    return ans;
}

///Magic!!!!!!!
PLL inverse(PLL a)
{
    return power(a, (M.ff-1)*(M.ss-1)-1);
}

PLL pb[N];      ///powers of base mod M
PLL invb;

///Call pre before everything
void hashPre()
{
    pb[0] = mp(1,1);
    for (int i=1; i<N; i++)
        pb[i] = (pb[i-1] * base)%M;
    invb = inverse(pb[1]);
}

///Calculates Hash of a string
PLL Hash (string s)
{
    PLL ans = mp(0,0);
    for (int i=0; i<s.size(); i++)
        ans=(ans*base + s[i])%M;
    return ans;
}
int  cs=0;
int cnt[mx5],to_node=1,to[mx5][26],depth[mx5];
map<int,map<PLL,ll> >ma;
void trie_add_string(string s,ll joy,PLL h_value)
{
    int cur=1;
    depth[cur]=0;
    cnt[cur]++;
    ll val=0LL;
    //cout<<h_value.F<<" "<<h_value.S<<endl;
    val=ma[cur][h_value];
    ma[cur][h_value]=max(val,joy);
    for(int i=0; i<s.size(); i++)
    {
        int  ch=s[i]-'a';
        if(!to[cur][ch])to[cur][ch]=++to_node;
        int indx=cur;
        cur=to[cur][ch];
        depth[cur]=depth[indx]+1;
        cnt[cur]++;
        val=ma[cur][h_value];
        ma[cur][h_value]=max(val,joy);

    }
}

ll trie_quary(string s,PLL h_value)
{
    int cur=1;
    ll val=0LL;
    val=ma[cur][h_value];
    for(int i=0; i<s.size(); i++)
    {
        int ch=s[i]-'a';
        if(!to[cur][ch])return val;
        cur=to[cur][ch];
        val=max(val,depth[cur]+ma[cur][h_value]);
    }

    return val;
}
vector<PLL> ha,hb;
char buffer[200005];
int c[200005];
void input()
{
    int n,m,k,l;
    sci(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &c[i]);
    }

    for(int i=0; i<n; i++)
    {
        scanf("%s",buffer);
        string a=buffer;
        string b=buffer;

        sort(all(b));
        PLL hash_value=Hash(b);
        trie_add_string(a,(ll)c[i],hash_value);

    }
    sci(m);

    while(m--)
    {

        scanf("%s",buffer);
        string a=buffer;
        string b=buffer;

        sort(all(b));
        PLL hash_value=Hash(b);
        printf("%lld\n",trie_quary(a,hash_value));
    }
    memset(cnt,0,sizeof(cnt));
    memset(to,0,sizeof(to));
}

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
    hashPre();
    int t=1;
    sci(t);
    while(t--)
    {
        to_node=1;
        input();
        ma.clear();
    }
    return 0;
}

