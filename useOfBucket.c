#include <stdio.h>
#include <stdlib.h>
#define SIZE 11

struct dataItem {
   int data;
   int bucket;
};

int modded;
int i;

struct dataItem* table[SIZE];

void nullTheTable() {
	for(i=0;i<SIZE;i++) {	
		table[i] = (struct dataItem*) malloc(sizeof(struct dataItem));
		table[i]->data = -1;
		table[i]->bucket = -1;
	}
}

void linkCheck(int number) {
	modded++;
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
	} else if(table[modded]->bucket == -1) {
		table[modded]->bucket = number;
	} else {
		printf("overflow for number %d at line %d\n\n", number, modded);
		linkCheck(number);
	}
}

void display() {
		printf("ID >>> DTA --- BCK\n------------------\n");
	for(i=0;i<SIZE;i++) {
		printf("%2d >>> %3d --- %3d\n", i, table[i]->data, table[i]->bucket);
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
