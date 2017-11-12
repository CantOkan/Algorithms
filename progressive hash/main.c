#include <stdio.h>
#include <stdlib.h>
#define SIZE 11
struct hash
{
	int data;
};
struct hash*table[SIZE];

void nullTheTable() {
	int i;
	for(i=0;i<SIZE;i++) {	
		table[i] = (struct hash*) malloc(sizeof(struct hash));
		table[i]->data = -1;
	}
	
}
void linkCheck(int num,int mod) {
	mod++;
	if(mod>=SIZE)
	{
		mod=0;
	}
	if(table[mod]->data == -1) {
		table[mod]->data = num;
	} else {
		linkCheck(num,mod);
	}
}

void insert(int num)
{
	int mod;
	mod=num%SIZE;
	if(table[mod]->data==-1)
	{
			table[mod]->data=num;
	}
	else
	{
		printf("overflow for number %d at line %d\n\n", num, mod);
		linkCheck(num,mod);
	}
}
void display() {
	int i;
		printf("ID >>> DTA\n----------\n");
	for(i=0;i<SIZE;i++) {
		printf("%2d >>> %3d\n", i, table[i]->data);
	}
}
int main(int argc, char *argv[]) {
	nullTheTable();
	insert(27);
	insert(18);
	insert(29);
	insert(28);
	insert(39);
	insert(13);
	insert(16);
	insert(17);//17 table dolu olduğı için başa geçiyor
	display();
	return 0;
}
