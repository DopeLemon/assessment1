//The following code can encrypt or decrypt both a rotation cipher and a substitution cipher


#include <stdio.h>

int main(){
    
  int A;
  int i;
  int KEY;
  int Y;
  int X;
  char string[8888];
  char message[5];


printf("Would you like to: \n\n"); //lists the task that are able to be performed 

printf("1.  Encrypt a message using a rotation cipher given message text AND the rotation amount?\n\n");
printf("2.  Decrypt a message encrypted with a rotation cipher given cipher text AND rotation amount?\n\n");
printf("3.  Encrypt of a message using a substitution cipher given message text AND alphabet substitutions?\n\n");
printf("4.  Decrypt a message encrypted with a substitution cipher given cipher text AND substitutions?\n\n");
/*printf("5.  Decrypt a message encrypted with a rotation cipher given ONLY cipher text?\n\n");
printf("6.  Decrypt a message encrypted with a substitution cipher given ONLY cipher text?\n\n\n\n");*/

printf("Please choose a task and enter the number which corresponds to it above: \n\n");

scanf("%d", &A);                                              //get the user to enter a value for the task

switch (A)
{
    
    
case 1:
 printf("Enter a word or phrase: ", string);                   //the user is prompted to enter the word or phrase 
        scanf("%s", &string);                                  //this is scanned into the string 
    printf("Enter the key: ", KEY);                            //the user is prompted to enter the letter shift amount (key)
        scanf("%d", &KEY);                                     //this is scanned and stored into the KEY value 
  for ( i = 0; i < 5; i++)                                     //the conditions for the encryption to work
    {
      printf ("%c=%d  :  ", string[i], string[i] - 65);        //shows the position of the letter in the alphabet
     Y = (string[i] - 65 + KEY) % 26;                          //shifts the value according to the key value
   printf("  The KEY shifted value is %d  :  ", Y);            //prints this new value
   X=Y+65;                                                     //adds 65 to the new value to shift the letter back into the ASCII range
   printf("  The new letter ASCII positon is %d  :  ", X);     //prints this new position
   printf("  The new letter is %c\n\n", X);                    //prints the correspnding letter for this ASCII value 
   message[i]= X;                                              //assigns the value X to the new letter 
   
  } 
  
    printf("Therefore the new phrase is: \n\%s\n\n", message); //the new phrase/word is printed
  break;
 
 
 
 case 2:
 printf("Enter a word or phrase: ", string);                   //the user is prompted to enter the word or phrase 
        scanf("%s", &string);                                  //this is scanned into the string 
    printf("Enter the key: ", KEY);                            //the user is prompted to enter the letter shift amount (key)
        scanf("%d", &KEY);                                     //this is scanned and stored into the KEY value
  for ( i = 0; i < 5; i++)                                     //the conditions for the encryption to work
    {
      printf ("%c=%d  :  ", string[i], string[i] - 65);        //shows the position of the letter in the alphabet
     Y = (string[i] - 65 - KEY) % 26;                          //shifts the value according to the key value
   printf("  The KEY shifted value is %d  :  ", Y);            //prints this new value
   X=Y+65;                                                     //adds 65 to the new value to shift the letter back into the ASCII range
   printf("  The new letter ASCII positon is %d  :  ", X);     //prints this new position
   printf("  The new letter is %c\n\n", X);                    //prints the correspnding letter for this ASCII value 
   message[i]= X;                                              //assigns the value X to the new letter 
   
  } 
  
    printf("Therefore the new phrase is: \n\%s\n\n", message); //the new phrase/word is printed
  break;
  
  }
return 0;
}