#include <stdio.h>

int main(){
    
  int A;
  int i;
  int KEY=19;
  int Y;
  int X;
  char string[] = "KHAN";
  char message[4];


printf("Would you like to: \n\n");

printf("1.  Encrypt a message using a rotation cipher given message text AND the rotation amount?\n\n");
printf("                                                     OR                                        \n\n");
printf("2.  Decrypt a message encrypted with a rotation cipher given cipher text AND rotation amount?\n\n");
printf("                                                     OR                                        \n\n");
printf("3.  Encrypt of a message using a substitution cipher given message text AND alphabet substitutions?\n\n");
printf("                                                     OR                                        \n\n");
printf("4.  Decrypt a message encrypted with a substitution cipher given cipher text AND substitutions?\n\n");
printf("                                                     OR                                        \n\n");
printf("5.  Decrypt a message encrypted with a rotation cipher given ONLY cipher text?\n\n");
printf("                                                     OR                                        \n\n");
printf("6.  Decrypt a message encrypted with a substitution cipher given ONLY cipher text?\n\n\n\n");

printf("Enter a whole number between 0 and 7: \n\n");

scanf("%d", &A); //get the user to enter a value 

switch (A)
{
case 1:
 
  for ( i = 0; i < 4; i++)
    {
      printf ("%c=%d  :  ", string[i], string[i] - 65);
     Y = (string[i] - 65 + KEY) % 26;
   printf("  The key shifted value is %d  :  ", Y);
   X=Y+65;
   printf("  The new letters ASCII positon is %d  :  ", X);
   printf("  The new letter is %c\n\n", X);
   message[i]= X;
   
  } 
  
    printf("Therefore the new phrase is: \n\%s\n\n", message);
  break;
  }
return 0;
}


