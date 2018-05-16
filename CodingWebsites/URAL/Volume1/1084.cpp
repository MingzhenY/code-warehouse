#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double L,R;
int main(void)
{freopen("1084.txt","r",stdin); 
	cin>>L>>R;
	double ANS;
	if(R<=L/2){
		ANS=acos(-1)*R*R;
	}
	else if(R>=L*cos(acos(-1)/4)){
		ANS=L*L;
	}
	else{
		ANS=acos(-1)*R*R-4*R*R*acos(L/R/2)+2*L*sqrt(R*R-L*L/4);
	}
	printf("%.3f",ANS);
return 0;
}








