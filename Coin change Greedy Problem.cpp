#include<bits/stdc++.h>
using namespace std;

int denomination[]= {1,5,6,9};
int n = (sizeof(denomination)/ sizeof(denomination[0]));

void findMinimumCoin(int money)
{
    vector<int> v;

    for(int i=n-1; i>=0; i--)
    {
        while(denomination[i]<= money)
        {
            money-=denomination[i];
            v.push_back(denomination[i]);
        }

    }


    cout<<"The needed coins are:";
    for(int i=0;i<v.size()  ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    cout<<"The amount of needed coins are :"<< v.size() ;


}




int main()
{

    int value;
    cout<<"Enter total value :";
    cin>>value;
    findMinimumCoin(value);

    return 0;
}

