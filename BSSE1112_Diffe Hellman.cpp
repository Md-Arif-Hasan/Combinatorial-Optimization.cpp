#include<bits/stdc++.h>
using namespace std;


#define ll long long int 
ll pow( ll par1, ll par2, ll par3 )
{
      ll res = 1;
      par1 %= par3;
      assert( par2 >= 0 );
      
      for( ; par2; par2 >>= 1 ) {
            if ( par2 & 1 ) 
                  res = res * par1 % par3;
            par1 = par1 * par1 % par3;
      }

      return res;
}


 int main()
 {
 ll n,g,x,a,y,b, k1=0, k2=0;
 
  printf("Enter the value of n and g : "); 
  cin>>n>>g;
     
 cout<<"Enter the value of x:";
  cin>>x;
 
  ll a = pow(g,x,n);
 
  cout<<"Enter the value of y: ";
  cin>>y;

   int b = pow(g,y,n);

  int  k1 = pow(b,x,n);
  
  int  k2 = pow(a,y,n);
	
  cout<<endl;
 cout<<"First key is : "<< k1 <<endl;
  cout<<"Second key is "<< k2 <<endl;
  return 0;
 }
