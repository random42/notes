#include <stdio.h> // scanf e printf
#include <string.h> // stringhe
#include <stdlib.h> // libreria standard

void print() {
  // printf restituisce il numero di caratteri stampati
  // %i o %d int
  // %ld long
  // %c char
  // %f, %e not esponenziale, %g (migliore)  float
  // %lf double
  // %s stringhe
  // %p pointers
  // %3.1f 3 cifre prima della virgola e 1 dopo
}

void core() {
  // tipi primitivi
  char lettera = 'c';
  int intero = 5;
  unsigned int absolute = 10;
  short jj = 255;
  long gg = 93845734;
  float virgola = 1.5;
  double ee = 213.912482359;
  lettera += 1;

  //costanti
  const int COSTANTE = 30;

  //escape chars
  char newline = '\n';
  char tab = '\t';
  char backspace = '\b';
  char formfeed = '\f';
  char carriageReturn = '\r';
  char backslash = '\\';
  char apici = '\"';
  char percentage; // = '%%';

  // scanf

  int val0;
  int var_lette;
  var_lette = scanf("%d", &val0);
  printf("%d\n",var_lette);
}

void funzioni() {
  // exit(0); per terminare il programma, il numero e' uno status
  // header.h file di intestazione con dichiarazione funzioni
}

void puntatori() {
  // se non inizializzati corrispondono all'indirizzo 0, NULL
  int a = 3;
  int *pointer = &a;
  int b = *pointer; // b = 3;
  *pointer = 4; // a = 4;

  void *v; // generico, per essere deferenziato bisogna castarlo
  int i;char c;float f;
  v = &f;
  // posso creare una funzione che ritorna un puntatore
  // int *max()
}

void array() {
  int a[5] = {1,2,3}; // gli altri due sono 0
  //int a[2] = {}; // SBAGLIATO
  int b[] = {1,2,3,4,5}; // giusto
  //b = i; // SBAGLIATO
  // L'unica operazione e' l'accesso a un elemento
  // b == &b[0]
  // un array e' un puntatore al primo elemento

  // Prendo 10 interi da tastiera e li ficco in un array
  int array[10];
  int *p = array;
  for (int i = 0;i < 10;i++) {
    scanf("%d",p+i);
  }
  printf("\n[");
  for (int i = 0;i < 10;i++) {
    printf("%d",*(p+i));
    if (i < 9) {
      printf(", ");
    } else {
      printf("]");
    }
  }
}

void stringhe() {
  // array di char con \0 alla fine
  char s[6] = {'c','i','a','o','!','\0'};
  char s1[] = "ciao!";
  char *s3 = "ciao";
  printf("%ld\n",strlen(s3));
}

void strutture() {
  typedef struct student { // il nome e' omissibile se non la riutilizziamo
    char name[30];
    int age;
    float media;
  } student;
  student stud1, stud2;
  strcpy(stud1.name,"Bimbo");
  stud2 = stud1;
  /* stud1 == stud2 Errore */

  typedef union ifd {
    int i;
    float f;
    double d;
  } ifd;
  ifd n1;
  n1.i = 2;
  n1.f = 2.5;
  n1.d = 2.666666;
  //printf("%lu\n",sizeof(ifd));

  typedef enum {FALSE,TRUE} boolean; // ogni campo e' un numero da 0 in poi
  boolean x = TRUE; // x == 1
  //printf("%d\n",x);

  student *p;
  strcpy(p->name,"Bob");
  strcpy((*p).name,"Meh");
  printf("%s\n",p->name);
}

void allocazione() {
  typedef int intero;
  intero* ptr;
  ptr = (intero*)malloc(sizeof(intero));
  printf("%lu\n",sizeof(intero));  // 4

  int* array;
  int length = 50;
  array = (int*)malloc(sizeof(int)*length); // alloca nell'heap
  array[0] = 12;

  int arr[12]; // alloca in stack
}

void cast() {
  // autocast
  // char < short < int < long < float < double
  // si puo' castare verso destra
  double d;
  int a = 123;
  d = a;
  d = (double)a;
}

void bitwise() {
  // & = and
  // | = or
  // ^ = xor
  // ~ = not (complemento a 1)
  // >> = shift destra
  // << = shift sinistra
}

void preprocessore() {
  /* #define identificatore stringa
  quando scrivo l'identificatore lo scambia con la stringa
  #define id(id1,id2,id3) stringa
  funzione in base agli identificatori es:
  #define SQ(x,y) (x*x+y)

  __LINE__ rappresenta il numero di linea corrente
  __FILE__ una stringa contenente il nome del file sorgente corrente
  __DATE__ Una stringa che rappresenta la data corrente al tempo di compilazione nel formato “mm dd yyyy”
  __TIME__ Una stringa che rappresenta il tempo corrente al momento della compilazione nel formato “hh:mm:ss”

  #define DEBUG 0
  #ifdef DEBUG
  codice....
  #else
  altro codice
  #endif

  librerie utili:
  - limits.h (proprieta' di tipi di variabile)
  - float.h
  - ctype.h (gestione caratteri)
  - math.h

  #ifndef __PLUTO_H__
  #define __PLUTO_H__
  #include “pippo.h”
  serve a non includere piu' volte lo stesso file
  */
}

void scan() {
  // char a = getchar();
  // putchar(a);
  // putchar('\n');
  FILE* in = fopen("input.txt","r"); // read, write, append e varianti
  char* b = malloc(128);
  if (!in) {
    printf("Error reading file.\n");
  }
  while (fscanf(in,"%s",b) == 1) {
    printf("%s\n",b);
  }
  fclose(in);

  //sscanf and sprintf per i/o su stringhe
  //atoi and atof per convertire stringhe in interi o float
}

void visibilita_variabili() {
  /*
  AUTO
  default, visibile dalla funzione

  EXTERN
  dichiarata fuori da funzioni, puo' essere dichiarata
  dentro una funzione tramite extern

  REGISTER
  da tenere nei registri della cpu perche' spesso usata

  STATIC
  mantiene il valore dopo che la funzione e' finita,
  viene inizializzata solo alla prima chiamata

  STATIC EXTERN
  variabile accessibile solo nel file

  le variabile statiche e esterne vengono inizializzate a 0
  le altre hanno valori sporchi
  */

}

void parametri_main() {
  //(int argc, char *argv[])
}

void make() {
  /*
  gcc -c per avere il modulo oggetto
  da ricompilare ogni volta che cambia il .c o il .h

  MAKE
  automatizza la compilazione tramite un
  makefile che descrive le dipendenze del progetto

  nome_target: file1.o file2.o filen.o
  gcc -o nome_target file1.o file2.o filen.o
  file1.o: file1.c file1.h gcc -c file1.c
  ...
  filen.o: filen.c filen.h
  gcc -c filen.c
  clean: rm -f *.o
  */
}


int main() {

}
