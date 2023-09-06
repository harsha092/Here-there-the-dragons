#include <bits/stdc++.h>
using namespace std;

struct s
{
    int x,y;
};
int main() {
	// your code goes here
	int r,c,k,d;
	cin>>r>>c>>k>>d;
	s a[d];                       //to store coordinates of d dragons.
	for(int i=0;i<d;i++)
	{
	    int x1,y1;
	    cin>>x1>>y1;
	    a[i].x=x1;
	    a[i].y=y1;
	}
	
	for(int i=0;i<d-1;i++)
	{
	    for(int j=0;j<d-i-1;j++)
	    {
	        if(a[j].x>a[j+1].x)
	        {
	            s temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
	        }
	    }
	}
	
	
	int mindist[d][k];
	for(int i=0;i<d;i++)
	{
	    for(int j=0;j<k;j++)
	    {
	        mindist[i][j]=-1;
	    }
	}
	for(int j=0;j<k;j++)
	{
	    for(int i=0-j;i<d;i++)
	    {
	        if(j==0)
	        {
	            mindist[i][j]=a[i].x+a[i].y;
	        }
	        else
	        {
	            int minn=INT_MAX;
	            for(int k=j-1;k<i;k++)
	            {
	                int diff=abs(a[i].x-a[k].x)+abs(a[i].y-a[k].y);
	                minn=min(minn,mindist[k][j-1]+diff);
	            }
	            if(minn!=INT_MAX)
	            {
	                mindist[i][j]=minn;
	            }
	        }
	    }
	}
	
	int ans=INT_MAX;
	for(int i=0;i<d;i++)
	{
	    if(mindist[i][k-1]!=-1)
	    {
	        ans=min(ans,mindist[i][k-1]);
	    }
	}
	cout<<ans<<"\n";
	return 0;
}
