#include<bits/stdc++.h>
using namespace std;

struct activity
{
    int s_time;
    int f_time;
};

bool compare(activity a, activity b)
{
    if(a.f_time< b.f_time)
    {
      return 1;
    }
    else
    {
        return 0;
    }
}

void prefectActivities( activity a[],int n)
{
    sort(a,a+n,compare);
    int i=0;
    cout<<"["<< a[i].s_time<<","<<a[i].f_time<<"]"<< endl;


    for(int j=1;j<n;j++)
    {
        if(a[j].s_time >= a[i].f_time)
        {
            cout<<"["<< a[j].s_time<<","<<a[j].f_time<<"]"<< endl;
            i=j;
        }
    }
}


int main()
{
    int n;

    activity a[] ={{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};
    n = sizeof(a)/sizeof(a[0]);

    prefectActivities(a,n);
}

