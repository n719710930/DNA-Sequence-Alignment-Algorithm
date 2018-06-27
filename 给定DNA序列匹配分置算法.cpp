#include<stdio.h>
#define m 10
#define n 8

//Defining the DNA sequence 
char x[11] = {'A','A','C','A','G','T','T','A','C','C',' '};
char y[9] = {'T','A','A','G','G','T','C','A',' '};

//Function initialization 
int Min(int a,int b,int c);
int getOPT(int i, int j );

//Main function 
int main(){
	int i,j;
	while(1){
	scanf("%d,%d",&i,&j);
	printf("%d\n",getOPT(i,j));
    }
	return 0;
} 

//OPT iterative function 
int getOPT(int i, int j ){
	int opt,penalty; 
    if (i == m) return opt = 2*(n-j);
    else if (j == n) return opt = 2*(m-i);
    else{
	    if (x[i] == y[j] ) penalty = 0;
 	    else penalty = 1;
    }
 	return opt= Min(getOPT(i+1, j+1)+penalty,getOPT(i+1, j)+2, getOPT(i, j+1)+2);
}


//Obtain the minimum OPT value function 
int Min(int a,int b,int c)
{	int t;
	if(a>b) 
	{
		t=a;
		a=b;
		b=t;
	}
	if(a>c)	{
		t=c;
		c=a;
		a=t;
	}
	
	return a;
}