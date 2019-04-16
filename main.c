//The following code can encrypt or decrypt both a rotation cipher and a substitution cipher


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    
  int A;
  int i;
  int KEY;
  //char Y;
  int X;
  char string[8888];
  char message[8888];


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
 printf("1: Enter a word or phrase in CAPITAL letters only: ");                   //the user is prompted to enter the word or phrase 
        scanf(" %[^\n]s", string);                                  //this is scanned into the string 
    printf("Enter the key: ");                            //the user is prompted to enter the letter shift amount (key)
        scanf("%d", &KEY);                                     //this is scanned and stored into the KEY value 
  for ( i = 0; i < strlen(string); i++)                                     //the conditions for the encryption to work
    {
     X = (string[i] - 65 + KEY) % 26;  
     if(string[i]<65 || string[i]>90)
 {
   
     message[i]= ' ';
                                                        //adds 65 to the new value to shift the letter back into the ASCII range
 }
  else 
  {
                              //shifts the value according to the key value
      X=X+65;   
 message[i]= X; 
}
 
}
   
   printf("Therefore the new phrase is: \n\%s\n\n", message); //the new phrase/word is printed
 
 break;
 
 
 
 case 2:
 printf("2: Enter a word or phrase using CAPITAL letters only: ");                   //the user is prompted to enter the word or phrase 
        scanf(" %[^\n]s", string);                                  //this is scanned into the string 
    printf("Enter the key: ");                            //the user is prompted to enter the letter shift amount (key)
        scanf("%d", &KEY);                                     //this is scanned and stored into the KEY value
  for ( i = 0; i < strlen(string); i++)                                     //the conditions for the encryption to work
    {
     X = (string[i] - 65 + (26 - KEY)) % 26;                          //shifts the value according to the key value
     if(string[i]<65 || string[i]>90)
 {
   
     message[i]= ' ';
                                                        //adds 65 to the new value to shift the letter back into the ASCII range
 }
  else 
  {
                                //shifts the value according to the key value
      X=X+65;   
 message[i]= X; 
}
                                                        //adds 65 to the new value to shift the letter back into the ASCII range
                                                 //assigns the value X to the new letter 
   }
  printf("Therefore the new phrase is: \n\%s\n\n", message); //the new phrase/word is printed
  break;
  
  
    
  
  
  case 3:
  printf("3: The letter substitution that will be used in this substitution cipher is: QWERTYUIOPASDFGHJKLZXCVBNM\n\n"); 
  printf("Enter a word or phrase in CAPITAL letters only: "); //substitution encryption
  scanf(" %[^\n]s", string); 
  printf("%s\n\n", string);
  break;
  
  
  case 4:
  //substitution decryption 
  break;
  
  default:
  printf("Error: invalid input, pleae try again\n\n");
  
  }
return 0;
}
