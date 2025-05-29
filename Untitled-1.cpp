#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,T;
struct node{
    int x,y,i;
    bool operator <(const node &s)const{
        return (s.x+s.y)>(x+y);
    }
};
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        int xx,yy,ans=0;
        vector<node> a;
        vector<int> x;
        vector<int> y;
        for(int i=1;i<=n;i++)
        {
            cin>>xx>>yy;
            a.push_back({xx,yy,i});
            x.push_back(xx);
            y.push_back(yy);

        }
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        for(int i=0;i<n;i++)
        {
            int tempx1=x[n-1];
            int tempx2=x[0];
            int tempy1=y[n-1];
            int tempy2=y[0];

            if(tempx1==a[i].x) tempx1=x[n-2];
            if(tempx2==a[i].x) tempx2=x[1];
            if(tempy1==a[i].y) tempy1=y[n-2];
            if(tempy2==a[i].y) tempy2=y[1];
            int tempans=(tempx1+1-tempx2)*(tempy1+1-tempy2);
           // cout<<x[0]<<" "<<y[0]<<endl;
            while(tempans<n)
            {
                tempans+=min((tempx1+1-tempx2),(tempy1+1-tempy2));
            }
            if(ans==0) ans=tempans;
            else ans=min(ans,tempans);
        }
        cout<<ans<<endl;
    }
}
    