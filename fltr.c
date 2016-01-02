#include <stdio.h>
#include <string.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define BUFFER_SIZE 1024

void strcatc(char* dest, char c) {
   while (*dest)
      dest++;
   *dest++ = c;
   dest = '\0';
}

int matches(char* needle, char* haystack, char* coloredHaystack)
{
   const unsigned int nLength = strlen(needle);
   const unsigned int hLength = strlen(haystack);
   if (nLength > hLength)
      return 0;

   unsigned int i = 0, j = 0;
   while (j < hLength) {
      if (needle[i] == haystack[j]) {
         strcat(coloredHaystack, COLOR_RED);
         strcatc(coloredHaystack, haystack[j]);
         strcat(coloredHaystack, COLOR_RESET);
         i++;
      } else {
         strcatc(coloredHaystack, haystack[j]);
      }
      j++;
   }

   return (i == nLength);
}

int main(int argc, char* argv[])
{
   if (argc < 2) {
      printf("Usage: fltr <needle>");
      return 0;
   }

   char* needle = argv[1];
   char buffer[BUFFER_SIZE];
   while (fgets(buffer, sizeof(buffer), stdin)) {
      char coloredBuffer[BUFFER_SIZE] = "";
      if(matches(needle, buffer,coloredBuffer)) {
         printf("%s", coloredBuffer);
      }
   }

   return 0;
}
