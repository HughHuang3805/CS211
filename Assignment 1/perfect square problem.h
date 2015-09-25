#inlcude<iostream>
using namespace std;

int main(){
	int n=1;
	while(n>=1){
		if(((n*n)%2!=0)&&((n*n)/10%2!=0)){
			cout << The first perfect square whose last two digits are both odd is: " << n*n;
			return 0;
		}
		n++;
	}
	return 0;
}d