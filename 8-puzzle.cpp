#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll read() {
    ll f=1,x=0;
    char ch;
    do {
        ch=getchar();
        if(ch=='-')f=-1;
    } while(ch>'9'||ch<'0');
    do {
        x=x*10+ch-'0';
        ch=getchar();
    } while(ch>='0'&&ch<='9');
    return f*x;
}

ll a,goal=123804765;

ll s[4][4];

map<int,int>dis;

map<int,int>vis;

int dx[5]={1,-1,0,0};
int dy[5]={0,0,1,-1};

inline void deque_BFS()
{
    queue<ll>q;
    if(a==goal){
        cout<<"0\n";
        exit(0);
    }
    vis[a]=1;vis[goal]=2;
    dis[a]=0;dis[goal]=0;
    q.push(a);
    q.push(goal);
    while(!q.empty())
    {
        ll now,cur=q.front();q.pop();
        now=cur;
        int sx,sy;
        for(int i=3;i>=1;i--)
        {
            for(int j=3;j>=1;j--)
            {
                s[i][j]=now%10;now/=10;
                if(!s[i][j])sx=i,sy=j;	
            }
        }
        for(int i=0;i<4;i++)
        {
            int xx=sx+dx[i],yy=sy+dy[i];
            if(xx<1||xx>3||yy<1||yy>3) continue;
            swap(s[sx][sy],s[xx][yy]);
            now=0;
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    now=now*10+s[j][k];
                }
            }
            if(vis[cur]==vis[now])
            {
                swap(s[sx][sy],s[xx][yy]);
                continue;
            }
            if(vis[now]+vis[cur]==3)
            {
                cout<<dis[cur]+dis[now]+1<<endl;
                exit(0); 
            }
            
            dis[now]=dis[cur]+1;
            vis[now]=vis[cur];
            q.push(now);
            swap(s[sx][sy],s[xx][yy]);
        }
    }
}

int main(){
    a=read();
    deque_BFS(); 
    return 0;
}
