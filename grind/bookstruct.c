#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char *title;
  char *author;
  float price;
} Book;

int main() {
  Book a; 
  a.title = "lotr";
  a.author = "tolkein";
  a.price = 25.25;
  
  Book *b = malloc(sizeof(Book));
  if (b == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  b->title = malloc(20);
  strcpy(b->title, "doawk");
  b->author = "kinney";
  b->price = 32.32;
  

  printf("Title of book a: %s\n", a.title);
  printf("Author f book a: %s\n", a.author);
  printf("Price of book a: $%.2f\n", a.price);

  printf("Title of book b: %s\n", b->title);
  printf("Author of book b: %s\n", b->author);
  printf("Price of book b: $%.2f\n", b->price);

  free(b->title);
  free(b);

  return 0;
}
