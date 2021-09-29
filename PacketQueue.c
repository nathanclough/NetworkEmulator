#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char messageArray[100][20];
int front = 0;
int rear = -1;
int itemCount = 0;
int max = 100;

char* Peek() {
     return &messageArray[front];
}

int IsEmpty() {
     return itemCount == 0;
}

int IsFUll() {
     return itemCount == max;
}

int Size() {
     return itemCount;
}

void Insert(char * data) {
     if (itemCount < max) {

          if (rear == max - 1) {
               rear = -1;
          }
          rear++;
          for (int x = 0; x < 20; x++) {
               messageArray[rear][x] = data[x];
          }
          
          itemCount++;
     }
}

char* RemoveData(char * data) {

     for (int x = 0; x < 20; x++) {
          data[x] = messageArray[front][x];
     }
     data[20] = '\0';

     front++;
     if (front == max) {
          front = 0;
     }
     
     itemCount--;
     return data;
}