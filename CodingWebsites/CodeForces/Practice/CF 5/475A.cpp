#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
char bus[6][30]={
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"
};
void F(int k){
	for(int i=0;i<6*30;++i){
		if(k<=0) break;
		if(bus[i%6][i/6]=='#'){
			bus[i%6][i/6]='O';
			k--;
		}
	}
	for(int i=0;i<6;++i){
		printf("%s\n",bus[i]);
	}
}
int main(void)
{
	freopen("475A.txt","r",stdin); 
	int k;cin>>k;
	F(k);
return 0;
}














