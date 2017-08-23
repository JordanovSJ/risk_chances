#include <iostream>
using namespace std;
#include <cmath>
#include <stdlib.h>

void bb_sort(int arr[], int length){
	for(int i=0; i<length;i++){
		for(int j=0; j<length-1;j++){
			if (arr[j+1]>arr[j]){
				int x=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=x;
			}			
		}
	}	
}

int * battle(int n_dices_attacker,int n_dices_defender){
	int dices_attacker[n_dices_attacker];
	int dices_defender[n_dices_defender];
	
	int def_lost=0;
	int atc_lost=0;
	
	for (int i=0;i<n_dices_attacker;i++){
		dices_attacker[i]=rand()%6+1;
		bb_sort(dices_attacker,n_dices_attacker);
	}
	for (int i=0;i<n_dices_defender;i++){
		dices_defender[i]=rand()%6+1;
		bb_sort(dices_defender,n_dices_defender);
	}	
	
	int less;
	if (n_dices_attacker>=n_dices_defender) less=n_dices_defender;
	else less=n_dices_attacker;
	
	for (int i=0;i<less;i++){
		if( dices_attacker[i]>dices_defender[i]) def_lost++;
		else atc_lost++;
	}
	
	static int  r[2];
	r[0]=atc_lost;
	r[1]=def_lost;
	return r;
	
}


int main(){
	int N=1000000;
	int a=0;
	int b=0;
	int c=0;
	int *r;
	int m,n;
	cin>>m;
	cout<<endl;
	cin>>n;
	for(int i=0;i<N;i++){
		r=battle(m,n);
		if (r[0]>r[1]) a++;
		if (r[0]==r[1]) b++;
		if (r[0]<r[1]) c++;		
	}
	double p,q,t;
	p=(double) c/N;
	q=(double) b/N;
	t=(double) a/N;
	cout<<"attacker wins"<<p<<endl;
	cout<<"draws"<< q<< endl;
	cout<<"defender wins"<< t<<endl;
	cout<<"sum " << p+q+t<<endl;
	return 0;
}
