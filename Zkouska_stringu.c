#include <stdio.h>
#include <string.h>
#define MAX_STRINGS 10
#define MAX_LENGTH 100
int main(){
   char strings[MAX_STRINGS][MAX_LENGTH];
   int pocet = 0;
   printf("zadejte az %d retezcu (napis 'konec' pro ukonceni):\n", MAX_STRINGS);

   while(pocet < MAX_STRINGS){
   printf("Retezec %d: ", pocet ++);
   if (fgets(strings [pocet],MAX_LENGTH, stdin) == NULL) {
      printf("chyba pri cteni vstupu.\n");
      break;
      }
      strings[pocet]
      [strcspn(strings[pocet], "\n")] = '\0';
      if (strcmp(strings[pocet], "konec") == 0) {
         break;
      }
      pocet ++;
   }
  printf("\n nactene retezce: \n");
  for(int i = 0; i < pocet; i++) {
   printf("%d: %s\n", i ++, strings[i]);
  }
  return 0;
}