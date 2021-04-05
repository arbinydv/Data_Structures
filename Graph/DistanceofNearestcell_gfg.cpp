 #include<bits/stdc++.h>
using namespace std;
// Mulit source BFS technique where the source can be anyone
// In this qsn we simply put all the cordiantes of 1 and it's distance from itself==0 and then run BFS in four dir until we find 0
// and then we store the distance of 0 from 1 for the given cell 
vector<int> xMove({0,0,1,-1});
vector<int> yMove({1,-1,0,0});
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int mat[m][n];

        int distance[m][n];

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>mat[i][j];
                if(mat[i][j])
                {
                    distance[i][j]=0;
                    q.push({{i,j},0});
                }
                else
                {
                    distance[i][j]=-1;
                }
                
            }
        }

        while(!q.empty())
        {
            pair<pair<int,int>,int> p= q.front();
            q.pop();

            int x= p.first.first;
            int y= p.first.second;
            int d=p.second;

            //BFS call

            for(int i=0;i<4;i++)
            {
                int X= x+xMove[i];
                int Y= y+yMove[i];

                if(X>=0 && X<m && Y>=0 && Y<n && distance[X][Y]==-1)
                {
                    distance[X][Y]=d+1;
                    q.push({{X,Y},d+1});
                }

            }


        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<distance[i][j]<<" ";
            }
        }
        cout<<endl;

                
    }
}