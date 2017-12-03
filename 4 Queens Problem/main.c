#include <stdio.h>
#include <stdlib.h>
int t[5]={-1};
int sol = 1;
void printsol()
{
	int i,j;
	char board[4][4];
	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
			board[i][j]='_';
			
			
			
	for(i=0;i<4;i++)
	{
		board[i][t[i]]='q';
	}
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	} 
			
}
int empty(int i)
{
	int j=0;
		while((t[i]!=t[j])&&(abs(t[i]-t[j])!=(i-j))&&j<5)j++;
		return i==j?1:0;
}
void queen(int i)
{
	for(t[i]=0; t[i]<4; t[i]++)
	{
		if(empty(i))
			if(i==3)
			{
				printf("sol %d \n",sol++);		
				printsol();	
					printf("\n");	
			}
			else{
				queen(i+1);
			}
	}
}

int main(int argc, char *argv[]) {
	queen(0);
	return 0;

}

