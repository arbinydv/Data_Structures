
    // count the number of fresh oranges
    int fresh=0;

    // queue stores the co-ordinates of the rotten oranges

    queue<pair<int,int>>q;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]==1)
            {
                fresh++;
            }
            if(grid[i][j]==2)