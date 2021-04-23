#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define sz size() 
#define f first
#define s second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ins insert
#define all(x) x.begin(), x.end()
#define Add_Speed ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int maxm = (int)1e5 + 7;
const int maxn = (int)1e5 + 7;
const int mod = (int)1e9 + 7;

int n, a[maxn], ds[maxn], q, magic = 317, nxts[maxn];

void build(){
	for(int bl = 0; bl <= n / magic; bl++){
		for(int i = min(n, (bl + 1) * magic) - 1; i >= bl * magic; i--){
			//cout << bl << " ";
			int next = a[i] + i;
			if(next >= n || bl != next / magic){ 
				ds[i] = 1;
				nxts[i] = next;
			}
			else{
				ds[i] = ds[next] + 1;
				nxts[i] = nxts[next];
			}
		}
	}
}

void upd(int pos, int val){
	int bl = pos / magic;
	a[pos] = val;
	for(int i = pos; i >= bl * magic; i--){
		int next = a[i] + i;
		if(next >= n || bl != next / magic){ 
			ds[i] = 1;
			nxts[i] = next;
		}
		else{
			ds[i] = ds[next] + 1;
			nxts[i] = nxts[next];
		}
	}
}

pii get(int x){
	int res = 0, pos = x;
	while(x < n){
		res += ds[x];
		if(nxts[x] >= n) pos = x;
		x = nxts[x];
	}
	while(pos < n){
		if(pos + a[pos] >= n) return {pos + 1, res};
		pos += a[pos];
	}
	return {pos, res};
}

int main () {

	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	build();
	/*cout << endl;
	for(int i = 0; i < n; i++){
		cout << i + a[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < n; i++){
		cout << nxts[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < n; i++){
		cout << ds[i] << " ";
	}
	cout << endl;*/
	while(q--){
		int type, pos, x;
		scanf("%d", &type);
		if(type == 0){
			scanf("%d%d", &pos, &x);
			upd(pos - 1, x);
		}
		else{
			scanf("%d", &pos);
			pii ans = get(pos - 1);
			printf("%d %d\n", ans.f, ans.s);
		}
	}
	
}



