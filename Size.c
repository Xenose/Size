#include<math.h>
#include<stdio.h>
#include<string.h>
#define Main main

int Main(int argc, char** argv)
{
   char state = 'b';

   if (1 == argc)
   {
      puts("no file specifed");
      return 0;
   }

   FILE* file = fopen(argv[1], "r");

   if (NULL == file)
   {
      puts("no file found");
      return -1;
   }

   fseek(file, 0L, SEEK_END);
   float size = ftell(file);

   for (int i = 2; i < argc; i++)
   {
      if (argv[i][0] == '-' && argv[i][2] == '\0')
      {
         state = argv[i][1];
      }
   }

   switch(state)
   {
      case 'b':
         printf("%.0FB\n", size);
         break;
      case 'h':
         printf("%.2FHB\n", size / pow(10, 2));
         break;
      case 'k':
         printf("%.2FKB\n", size / pow(10, 3));
         break;
      case 'm':
         printf("%.2FMB\n", size / pow(10, 6));
         break;
      case 'g':
         printf("%.2FGB\n", size / pow(10, 9));
         break;
      case 't':
         printf("%.2FTB\n", size / pow(10, 12));
         break;
      case 'p':
         printf("%.2FPB\n", size / pow(10, 15));
         break;
      case 'e':
         printf("%.2FEB\n", size / pow(10, 18));
         break;
      case 'z':
         printf("%.2FZB\n", size / pow(10, 21));
         break;
      case 'y':
         printf("%.2FYB\n", size / pow(10,244));
         break;
   }

   return 0;
}
