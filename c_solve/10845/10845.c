#include<stdio.h>
#include<string.h>

int queue[10000];
int frontPtr = 0;
int ptr = 0;

int push(int val) {
	queue[ptr] = val;
	ptr++;
}
int pop() {
	if (ptr > 0)
		return queue[frontPtr++];
	else
		return -1;
}
int size() {
	return ptr - frontPtr;
}
int empty() {
	if (ptr - frontPtr == 0) {
		return 1;
	}else {
		return 0;
	}
}
int front() {
	if (ptr - frontPtr > 0)
		return  queue[frontPtr];
	else
		return -1;
}
int back() {
	if (ptr - frontPtr > 0)
		return queue[ptr - 1];
	else
		return -1;
}

int main(){
	int n = 0;
	int result[10000];
	int j = 0;

	for (int i = 0; i < n; i++) {
		char commend[12];
		scanf("%s", commend);
		
		if (strcmp(commend, "pop")) {
			result[j] = pop();
			j++;
		}
		else if (strcmp(commend, "size")) {
			result[j] = size();
			j++;
		}
		else if (strcmp(commend, "empty")) {
			result[j] = empty();
			j++;
		}
		else if(strcmp(commend, "front"))
		{
			result[j] = front();
			j++;
		}
		else if (strcmp(commend, "back")) {
			result[j] = back();
			j++;
		}
		else {
			char *space = strtok(commend, " ");
			space = strtok(NULL, " ");
			int pushVal = atoi(space);
			push(pushVal);
		}
	}
	for (int i = 0; i < j;i++) {
		printf("%d\n",result[i]);
	}
	return 0;
}