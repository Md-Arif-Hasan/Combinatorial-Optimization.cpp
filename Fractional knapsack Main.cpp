#include <bits/stdc++.h>

using namespace std;



// Structure for an item
struct myItem
{
	int itemNo;
	int profit;
	int weight;
	float ppw; // profit per weight
};

// Comparison function to sort Item according to profit per weight ratio
bool cmp(struct myItem a, struct myItem b)
{
    ///a.ppw > b.ppw;   For decending order ....
	if(a.ppw > b.ppw)
	    return 1;
    else
        return 0;
}

float fractionalKnapsack(int Capacity, struct myItem arr[], int n)
{
	//calculating profit per weight ratio
	for(int i=0;i<n;i++)
	{
		arr[i].ppw = ((float)arr[i].profit / arr[i].weight);
	}

	// sorting Item on basis of profit per weight ratio
	sort(arr, arr + n, cmp);



	cout<<"details of all items : \n";
	cout<<"itemNo\t"<<"Profit\t"<<"Weight\t"<<"PPW\t"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout <<arr[i].itemNo<<"\t"<<arr[i].profit<<"\t"<<arr[i].weight<<"\t"<<((float)arr[i].ppw)<<endl;
	}

	cout<<endl;

	float Max = 0.0; // Maximum profit
	int i=0;

	//take items until capacity becomes zero
	while(Capacity > 0 && i<n)
	{
		// if we can take all weights of item
		if(Capacity >= arr[i].weight)
		{
			Max = Max + (float)arr[i].profit;
			Capacity = Capacity - arr[i].weight;
		}
		// we can take only fraction of item
		else
		{
			Max += (Capacity * arr[i].ppw);
			Capacity = 0;
		}
		i++;
	}

	return Max;
}

// driver function
int main()
{
	int c ;
	cout<<"Enter Capacity of knapsack :";
	cin>> c;   //    Capacity of knapsack
	myItem arr[] = { {1, 30, 10, 0}, {2, 20, 5, 0} , {3, 40, 15, 0}, {4, 36, 8, 0}};  ///Item, Profit , weight, PPW

	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<"details of all items before sorting and without calculating PPW: \n";
	cout<<"itemNo\t"<<"Profit\t"<<"Weight\t"<<"PPW\t"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout <<arr[i].itemNo<<"\t"<<arr[i].profit<<"\t"<<arr[i].weight<<"\t"<<((float)arr[i].ppw)<<endl;
	}

	cout<<endl;
	cout << "Maximum profit we can obtain = "<< fractionalKnapsack(c, arr, n);

	return 0;
}
