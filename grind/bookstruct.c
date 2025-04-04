#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char *title;
  char *author;
  float price;
} Book;

void create_book(Book *obj, const char *name, const char *title, const char*author, float price) {
  obj->title = malloc(strlen(title) + 1);
  strcpy(obj->title, title);
  obj->author = malloc(strlen(author) + 1);
  strcpy(obj->author, author);
  obj->price = price;

  printf("Title of book %s: %s\n", name, title);
  printf("Author of book %s: %s\n", name, author);
  printf("Price of book %s: $%.2f\n", name, price);
}
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
  b->author = malloc(20);
  strcpy(b->author, "kinney");
  b->price = 32.32;
  

  printf("Title of book a: %s\n", a.title);
  printf("Author f book a: %s\n", a.author);
  printf("Price of book a: $%.2f\n", a.price);

  printf("Title of book b: %s\n", b->title);
  printf("Author of book b: %s\n", b->author);
  printf("Price of book b: $%.2f\n", b->price);
  
  Book *c = malloc(sizeof(Book));
  create_book(c, "c", "kots", "murakami", 69.69); 
  
  Book *d = malloc(sizeof(Book));
  create_book(d, "d", "cmbyn", "aciman", 69.69); 

  Book *e = malloc(sizeof(Book));
  create_book(e, "e", "tpodg", "wilde", 69.69); 

  Book *f = malloc(sizeof(Book));
  create_book(f, "f", "cap", "dostoevsky", 69.69); 
  free(b->title);
  free(b->author);
  free(b);
  free(c->title);
  free(c->author);
  free(c);
  return 0;
}
