#include<bits/stdc++.h>
using namespace std;
#define vi vector<string>
#define pb push_back
#define endl "\n"
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi arrival(n),departure(n);
        for(int i=0;i<n;i++) cin>>arrival[i];
        for(int j=0;j<n;j++) cin>>departure[j];

        //sorting both the array
        //Since the question is simply caring about how many trains are there at station w/o caring train number
        //So we simply can get the no of train that arrives and leaves in particular range
        //TECH DOSE explanation
        sort(arrival.begin(),arrival.end());
        sort(departure.begin(),departure.end());
        //calculating the maximum platform needed
        int maxplatform=1; // at least there must be one platform on train station
        int needful=1; //max platforms needed at train station

        int i=1,j=0;
        while(i<n)
        {
            if(arrival[i]>departure[j])
            {
                maxplatform--;
                j++;
            }
            else
            {
                maxplatform++;
                i++;
            }
            needful= max(maxplatform,needful);

        }
        cout<<needful<<endl;
    }
}
