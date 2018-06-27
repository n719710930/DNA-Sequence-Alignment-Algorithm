#include<stdio.h>
#define m 10
#define n 8

struct opt{ 
          opt *p;
          int x,y; 
          int optnum; 
      }OPT[11][9];
      
//Defining the DNA sequence 
char x[11] = {'A','A','C','A','G','T','T','A','C','C',' '};
char y[9] = {'T','A','A','G','G','T','C','A',' '};

//Function initialization 
int getOPT(int i, int j );
int Min(int a,int b,int c);

//Main function 
int main(){
	int i,j,k,a,b;
	for(k=10;k>1;k--){
	    for(i=k;i>=0;i--){
			OPT[i][k-2].optnum = getOPT(i,k-2);
		}
	    for(j=k-3;j>=0;j--){
		    OPT[k][j].optnum = getOPT(k,j);
	    } 
	}

	printf("Pprogram is ready\n");
	while(1){
	printf("input:");
	scanf("%d %d",&a,&b);
	printf("%d\n",OPT[a][b].optnum);
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
    
 	return opt= Min(OPT[i+1][j+1].optnum+penalty, OPT[i+1][j].optnum+2, OPT[i][j+1].optnum+2);
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
