#include <stdio.h>
#include <stdlib.h>
#define SIZE 11

struct dataItem {
   int data;
};

int R;
int modded;
int i;

struct dataItem* table[SIZE];

void nullTheTable() {
	for(i=0;i<SIZE;i++) {	
		table[i] = (struct dataItem*) malloc(sizeof(struct dataItem));
		table[i]->data = -1;
	}
}

void linkCheck(int number) {
	modded = (modded + R) % SIZE;
	if(table[modded]->data == -1) {
		table[modded]->data = number;
	} else {
		linkCheck(number);
	}
}

void insert(int number) {
	modded = number % SIZE;
	
	if(table[modded]->data == -1) {
		table[modded]->data = number;
	}
	else {
		printf("overflow for number %d at line %d\n\n", number, modded);
		R = (number) / SIZE;
		linkCheck(number);
	}
}

void display() {
		printf("ID >>> DTA\n----------\n");
	for(i=0;i<SIZE;i++) {
		printf("%2d >>> %3d\n", i, table[i]->data);
	}
}

int main() {
	nullTheTable();
	
	insert(27);
	insert(18);
	insert(29);
	insert(28);
	insert(39);
	insert(13);
	insert(16);
	insert(50);
	
	display();
}
