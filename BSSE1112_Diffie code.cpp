#include<bits/stdc++.h>
using namespace std;

// 23 9
// 4 3

#define ll long long int
ll pow( ll par1, ll par2, ll par3 )
{
    ll res = 1;
    par1 %= par3;
    assert( par2 >= 0 );

    for( ; par2; par2 >>= 1 )
    {
        if ( par2 & 1 )
            res = res * par1 % par3;
        par1 = par1 * par1 % par3;
    }

    return res;
}

bool checkPrimitiveRoot(long long q,long long a)
{
    if(__gcd(q,a)==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ll q,x,alpha, y,a, b, k1=0, k2=0;


    printf("Enter the value of q and alpha : ");
    cin>> q >> alpha;


    bool isPrim = checkPrimitiveRoot(q,alpha );
    while(isPrim ==false)
    {
        cout<<endl<<" Not primitive "<<endl;
        cin>>q>>alpha;
        isPrim= checkPrimitiveRoot(q,alpha);
    }


    cout<<"Enter the value of x:";
    cin>>x;

    a = pow(alpha ,x ,q );

    cout<<"Enter the value of y: ";
    cin>>y;

    b = pow(alpha,y,q);

    k1 = pow(b,x,q);

    k2 = pow(a,y,q);

    cout<<endl;
    cout<<"First key is : "<< k1 <<endl;
    cout<<"Second key is "<< k2 <<endl;
    return 0;
}
