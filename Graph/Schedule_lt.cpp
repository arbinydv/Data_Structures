class Solution {
public:
    
    bool DFS(int v,vector<int>gph[],vector<bool>&visited,vector<bool>&curr)
    {
        visited[v]=true;
        curr[v]=true;
        for(auto it:gph[v])
        {
             if(!visited[it] && curr[it]==false)
             {
                 if(DFS(it,gph,visited,curr))
                    return true;
             }
             else if(curr[it])
                return true;
        }
        curr[v]=false;
        return false;
        
    }
    
    bool isCyclic(int V, vector<int>gph[])
    {
        // use color method 
        vector<bool>visited(V,false);
        vector<bool>curr(V,false);

        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
              if(DFS(i,gph,visited,curr))  // cycle found
                 return false;
            }
        }
        return true;   
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Question is simply construct the graph and check the cyclicity
        // If cyclicity exist then no else topological sort is possible
        
        // Graph construction
        
        int n= prerequisites.size();
        if(n==0)
            return true;
        int m=prerequisites[0].size();
        vector<int>gph[numCourses];
        for(int i=0;i<n;i++)
        {
            int x= prerequisites[i][0];
            for(int j=1;j<m;j++)
            {
                gph[x].push_back(prerequisites[i][j]);
            }
        }
        
        // check cyclicity       
        return isCyclic(numCourses,gph);  
    }
};