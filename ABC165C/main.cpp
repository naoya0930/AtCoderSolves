#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, Q;
vector<int> a, b, c, d;
int ans = 0;

void dfs(vector<int> s)
{
    if (s.size()> N)
    {
        
        int now = 0;
        for (int m = 0; m < Q; m++)
        {
            if (s[b[m]] - s[a[m]] == c[m])now += d[m];
        }
        ans = max(now, ans);
        //
        //for(int f=0;f<s.size();f++){
        //cout << s[f]<< " ";
        //}
        //cout <<ans<<endl;
        //
        return;
    }
    ////
    //for(int f=0;f<s.size();f++){
    //    cout << s[f]<< " ";
    //}
    //cout << endl;
    //
    s.push_back(s.back());
    while(s.back()<=M){
        dfs(s);
        s.back()++;
    }
}

int main(void)
{
    cin >> N >> M >> Q;
    b=vector<int>(Q);
    a=vector<int>(Q);
    c=vector<int>(Q);
    d=vector<int>(Q);
    for (int k = 0; k < Q; k++)
    {
        int n, l, p;
        cin >> n >> l >> c[k] >> d[k];
        a[k] = n;
        b[k] = l;
    }
    vector<int> ax(1,1);
    dfs(ax);
    cout <<ans <<endl;
}