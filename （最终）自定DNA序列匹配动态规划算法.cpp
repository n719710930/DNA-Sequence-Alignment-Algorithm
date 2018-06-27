#include<stdio.h>
struct opt{ 
          opt *p;
		  int x,y; 
          int optnum; 
      }OPT[9999][9999];
      
//Defining the DNA sequence 
char x[9999];
char y[9999];

char Sequence[2][9999];
//Function initialization 
int getOPT(int i, int j, int m, int n );
int judgeMin(int i, int j,int a,int b,int c);
int getAlignmentSequence();
int printAlignmentSequence();
//Main function 
int main(){
	int i,j,k,a,b,xnum,ynum;
	
	printf("X number:");	
	scanf("%d",&xnum);

	getchar();
	printf("X Sequence:");	
    for(k=0;k<xnum;k++){
    	x[k] = getchar();	
	}
    	
	getchar();
	printf("Y number:");
	scanf("%d",&ynum);

	getchar();
	printf("Y Sequence:");	
    for(k=0;k<ynum;k++){
    	y[k] = getchar();	
	}
	
	
   
    if(xnum>=ynum) 
	for(k=xnum;k>=xnum-ynum;k--){
		for(i=k;i>=0;i--){
			OPT[i][k-xnum+ynum].x = i;
	     	OPT[i][k-xnum+ynum].y = k-xnum+ynum;
			OPT[i][k-xnum+ynum].optnum = getOPT(i,k-xnum+ynum,xnum,ynum);
		}
	    for(j=k-xnum+ynum-1;j>=0;j--){
	    	OPT[k][j].x = k;
	     	OPT[k][j].y = j;
		    OPT[k][j].optnum = getOPT(k,j,xnum,ynum);
	    } 
	}
	
	else if(xnum<ynum) 
	for(k=ynum;k>=ynum-xnum;k--){
		for(i=k-ynum+xnum-1;i>=0;i--){
			OPT[i][k].x = i;
	     	OPT[i][k].y = k;
			OPT[i][k].optnum = getOPT(i,k,xnum,ynum);
		}
	    for(j=k;j>=0;j--){
	    	OPT[k-ynum+xnum][j].x = k-ynum+xnum;
	     	OPT[k-ynum+xnum][j].y = j;
		    OPT[k-ynum+xnum][j].optnum = getOPT(k-ynum+xnum,j,xnum,ynum);
	    } 
	}
 
	getAlignmentSequence();
	printAlignmentSequence();
	printf("Pprogram is ready\n");
	while(1){
	printf("input:");
	scanf("%d %d",&a,&b);
	printf("%d\n",OPT[a][b].optnum);
	printf("(%d,%d)\n",(* OPT[a][b].p).x,(* OPT[a][b].p).y);
    }

	return 0;
} 

//OPT iterative function 
int getOPT(int i, int j, int m, int n){
	int opt,penalty; 
    if (i == m) return opt = 2*(n-j);
    else if (j == n) return opt = 2*(m-i);
    else{
	    if (x[i] == y[j] ) penalty = 0;
 	    else penalty = 1;
    }
    
 	return opt= judgeMin(i, j, OPT[i+1][j+1].optnum+penalty, OPT[i+1][j].optnum+2, OPT[i][j+1].optnum+2);
}


//Obtain the minimum OPT value function 

int judgeMin(int i, int j,int a,int b,int c)
{	

	if(a<=b&&a<=c)
	{
		OPT[i][j].p = &OPT[i+1][j+1];
		return a;
	}
	else if(b<=a&&b<=c)
	{
		OPT[i][j].p = &OPT[i+1][j];
		return b;
	}
	else
	{
		OPT[i][j].p = &OPT[i][j+1];
		return c;
	}
}

int getAlignmentSequence()
{
	int a=0;
	int b=0;
	for(int i=0;(x[i]!=NULL||y[i]!=NULL);i++)
		{
		if(((* OPT[a][b].p).x == OPT[a][b].x+1)&&((* OPT[a][b].p).y == OPT[a][b].y+1))
		{
			Sequence[0][i] = x[a];
			Sequence[1][i] = y[b];
			a++;
			b++;
		}
		else if(((* OPT[a][b].p).x == OPT[a][b].x)&&((* OPT[a][b].p).y == OPT[a][b].y+1))
		{
			Sequence[0][i] = '#';
			Sequence[1][i] = y[b];
			b++;
		}
		else if(((* OPT[a][b].p).x == OPT[a][b].x+1)&&((* OPT[a][b].p).y == OPT[a][b].y))
		{
			Sequence[0][i] = x[a];
			Sequence[1][i] = '#';
			a++;
		}
	}
		return 0;
}

int printAlignmentSequence()
{
	for(int p=0;Sequence[0][p]!=NULL;p++)
		printf("%c",Sequence[0][p]);
	printf("\n");
	for(int q=0;Sequence[1][q]!=NULL;q++)
		printf("%c",Sequence[1][q]);
	printf("\n");
	return 0;
}