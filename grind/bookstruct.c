#include <stdio.h>
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

  b->title = "doawk";
  b->author = "kinney";
  b->price = 32.32;

  printf("Title of book a: %s\n", a.title);
  printf("Author f book a: %s\n", a.author);
  printf("Title of book a: $%.2f\n", a.price);

  printf("Title of book b: %s\n", b->title);
  printf("Author f book b: %s\n", b->author);
  printf("Title of book b: $%.2f\n", b->price);
  return 0;

}
