#include<iostream>
#include<math.h>
using namespace std;

void reset(bool *table, int q){
	for(int i=0; i<q; i++){
		table[i] = false;
	}
}

void print_table(bool *table, int q){
	for(int i=0; i<q; i++){
		cout<<table[i]<<"\t";
	}
	cout<<endl;
}

int primitive_root(int q){
	int i, j, alpha = 0, x, y=1;
	bool table[q];
	for(i = 2; i<q; i++){
		reset(table, q);
		x = 1;
		// cout<<"Alpha considered: "<<i<<endl;
		for(j = 1; j<q; j++){
			x = (y*i)%q;
			cout<<"x: "<<x<<" y: "<<y<<endl;
			// print_table(table,q);
			if(table[x]==true)
				goto a;
			else{
				table[x] = true;
				y = x;
			}
		}
		if(j==q){
			alpha = i;
			break;
		}
		a: continue;
	}
	return alpha;
}

int main(){
	int q = 11, alpha, xa=8, xb=4;
	alpha = primitive_root(q);

	int ya = (int)pow(alpha,xa)%q;
	int yb = (int)pow(alpha,xb)%q;
	
	int ka = (int)pow(ya,xa)%q;
	int kb = (int)pow(yb,xb)%q;
	
	cout<<ka<<" "<<kb<<endl;

	return 0;
}
