///**Bismillahir Rahmanir Rahim.**
//Amantu Amir, University of Barishal, Bangladesh
//Accepted
#include <bits/stdc++.h>
#define int                   long long int
#define clr(a, v)             memset(a,v,sizeof a)
#define all(v)                v.begin(),v.end()
#define ast(v)                sort(all(v))
#define sfs(s)                scanf("%s", s)
#define sf(n)                 scanf("%lld", &n)
#define sff(n, m)             scanf("%lld %lld",&n,&m)
#define dst(v)                sort(all(v),greater<int>())
#define sfff(n, m, o)         scanf("%lld %lld %lld",&n,&m,&o)
#define PP(n, m)              cout << n << " " << m << "\n"
#define PPP(a, b, c)          cout<<a<<" "<<b<<" "<<c<<"\n"
#define MX(a)                 *max_element(all(a))
#define MI(a)                 *min_element(all(a))
#define SUM(a)                accumulate(all(a),0)
#define I(n)                  cin >> n
#define II(n, m)              cin >> n >> m
#define III(a, b, c)          cin >> a >> b >> c
#define MIN(a, b, c)          min(a, min(b, c))
#define MAX(a, b, c)          max(a, max(b, c))
#define MID(b, e)             (b+(e-b)/2)
#define CAS(a)                cout << "Case " << a << ":"
#define pf(n)                 printf("%lld", n)
#define pff(n,m)              printf("%lld %lld\n",n,m)
#define prln(n)               cout<<n<<"\n"
#define P(n)                  cout << n
#define debug                 cout << " debug\n"
#define yes                   cout << "Yes\n"
#define no                    cout << "No\n"
#define minus1                cout << "-1\n"
#define zero                  cout << "0\n"
#define sp                    cout << " "
#define nl                    cout << "\n"
#define pii                   pair<int,int>
#define mp                    make_pair
#define pb                    push_back
#define S                     second
#define F                     first

using namespace std;
const int N = 2e5+50;
const int mod = 1e9+7;
bool is_prime[N+50];
vector<int>prime,primeFactor;
int digit(int n){return log10(n)+1;}
int bit_on(int n,int pos){return n=n|(1<<pos);}
int bit_off(int n,int pos){return n=n&~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}
void fast(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
string toString(int n){stringstream ss;ss<<n;string s;ss>>s;return s;}
int toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
bool isVowel(char ch){ ch=tolower(ch); if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
double dis(double x, double y, double x2, double y2){double res = sqrt(pow(x-x2,2) + pow(y-y2,2));return res;}
void sieve(){prime.push_back(2);for(int i=4;i<=N;i+=2)is_prime[i]=1;for(int i=3; i<N; i+=2){if(is_prime[i] == 0)
{prime.push_back(i);for(int j = i*i; j<N; j += (i*2))is_prime[j]=1;}}}
bool isPrime(int n){if(n == 1) return false;if(n == 2) return true;if(n%2 == 0) return false;
for(int i = 3; i * i <= n; i += 2 )if(n%i == 0) return false;return true;}
void primeFac(int n){int tmp = sqrt(n);for(int i = 0; prime[i] <= tmp; i++){if(n%prime[i] == 0)
{while(n%prime[i] == 0){n /= prime[i];primeFactor.pb(prime[i]);}}}if(n > 1)primeFactor.pb(n);}
int SOD(int n){int sum = 1;for(int i = 0; prime[i] <= n; i++){if(n%prime[i] == 0){int cnt = 1;
while(n%prime[i] == 0){n /= prime[i];cnt++;}sum *= (pow(prime[i], cnt) - 1)/ (prime[i] - 1);}}return sum;}
int NOD(int n){int till=sqrt(n+1);int p,divisor=1;for(int i=0;prime[i]<=till;i++){if(n%prime[i]==0){p=1;
while(n%prime[i]==0){n/=prime[i];p++;}till=sqrt(n);divisor*=p;}}if(n>1)divisor*=2;return divisor;}
bool isDigit(char ch){if(ch >= 48 && ch <= 57) return true; else return false;}
string Upper(string s){transform(all(s),s.begin(),::toupper);return s;}
string Lower(string s){transform(all(s),s.begin(),::tolower);return s;}
//Template end
//-------------------******Alhamdulillah******--------------------//

vector<int>G[N];
bool vis[N];
int node,edg;
void dfs(int root){
    vis[root]=true;
    edg+=G[root].size();
    node++;
    for(auto i:G[root]){
        if(vis[i]==false){
            dfs(i);
        }
    }
}

int32_t main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast();
    int tc=1;
    for(int T=1; T<=tc; T++){
        int n,m,k; cin>>n>>m>>k;
        vector<int>city(k);
        for(int i=0; i<k; i++) cin>>city[i];
        int u,v;
        for(int i=0; i<m; i++){
            cin>>u>>v;
            G[u].pb(v);G[v].pb(u);
        }
        int tot_city_node=0;
        int ans=0,mx_node=0,mx_edg=0;
        for(int i=0; i<k; i++){
            node=0;edg=0;
            dfs(city[i]);
            edg/=2;
            ans+=((node*(node-1))/2-edg);
            if(mx_node<=node){
                if(mx_node==node){
                    if(mx_edg>edg){
                        mx_edg=edg;
                    }
                }
                else{
                    mx_node=node;
                    mx_edg=edg;
                }
            }
            tot_city_node+=node;
        }
        ans-=((mx_node*(mx_node-1))/2-mx_edg);
        edg=0;
        for(int i=1; i<=n; i++){
            if(vis[i]==false){
                dfs(i);
            }
        }
        edg/=2;
        int tot_node=n-tot_city_node;
        tot_node+=mx_node;
        ans += (tot_node*(tot_node-1))/2;
        ans -= (mx_edg+edg);
        prln(ans);
    }
    return 0;

}

//--------------------******Alhamdulillah******-------------------//
