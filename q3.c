#include <stdio.h>
int main(){
	
	char op[2],c;int num[3],n;
	for(int i=0;i<5;i+=1){      //taking all the entered values
		if(i%2==0){
			scanf("d",&n);
			if(n<0 || n>1000){
				printf("Incorrect input: numbers cannot exceed 1000. Program terminated, please try again.");
				return 0;
			}
			else if (n>=0 && n<=1000){
				num[i/2]=n;
			}
			else {
				printf("Incorrect expression. Program terminated");
				return 0;
			}
		}
		else{
			scanf("%c",&c);
			if(c=='*' || c=='/' || c=='-' || c=='+') op[i/2]=c;
			else {
				printf("Incorrect expression. Program terminated.");
				return 0;
			}
		}
	}
	int val;
	if (op[0]=='+' && op[1]=='-'){val=num[0]+num[1]-num[2];printf("Result: %d",val);}
	else if (op[0]=='+' && op[1]=='*'){val=num[0]+num[1]*num[2];printf("Result: %d",val);}
	else if (op[0]=='+' && op[1]=='/'){
		if (num)val=num[0]+num[1]*num[2];printf("Result: %d",val);
	} 
	
	return 0;
}
