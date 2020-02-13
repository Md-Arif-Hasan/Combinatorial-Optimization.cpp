#include<bits/stdc++.h>
using namespace std;



count_coin(int coins[],int value)
{
    int x,y;
    x= (sizeof(coins)/ sizeof(coins[0]));

    int a[x][value+1];

    for(int i=0; i<x; i++)
    {
        for(int k=0; k<=value; k++)
        {
            if(k%2==0)
            {
                a[i][k]=1;
            }
            else
            {
                a[i][k]=0;
            }
        }
    }



    for(int i=0; i<x; i++)
    {
        for(int j=0; j<=value; j++)
        {
            if(coins[i]>j)
            {
                a[i][j]= a[i-1][j];

            }
            else
            {
                a[i][j]= (a[i-1][j] + a[i][j-coins[i]]);

            }
        }
    }


    for(int i=1; i<x; i++)
    {
        for(int j=0; j<=value; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int w;
    int coins[4]= {2,3,5,10};

    cin>>w;
    count_coin(coins,w);
    return 0;
}
