#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
char ch[8][8];
int ans=0;
void permute(int l, int r)  
{  
    // Base case  
    if (l == r)  
        {
        	//ans+=1;
        	bool rc[16]={0}, lc[16]={0};
        	for(int i=0; i<8; ++i)
        	{
        		//ans+=1;
        		int j = a[i];
        		if(ch[i][j] == '*')
        		{
        			return;
        		}
        		if(rc[i+j]==false)
        			rc[i+j]=true;
        		else return;
        		if(lc[i-j+7]==false)
        			lc[i-j+7]=true;
        		else return;
        	}
        	ans+=1;
        }
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            swap(a[l], a[i]);  
  
            // Recursion called  
            permute(l+1, r);  
  
            //backtrack  
            swap(a[l], a[i]);  
        }  
    }  
}  
 
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for(int i=0; i<8; ++i)
	{
		a.push_back(i);
		for(int j=0; j<8; ++j)
		{
			cin>>ch[i][j];
		}
	}
    //for every permutation of 0, 1, ... 7 say arr
    //we can get every possible way of filling the board
    // with position (0, arr[0]), (1, arr[1]), ..., (7, arr[7])
    //since no 2 queens are in the same row


    //we can try and fit every single one of these 8! permutations
	permute(0, 7);
 
	cout<<ans;
 
	return 0;	
}