//The following code can encrypt and decrypt both a rotation cipher and a substitution cipher


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>

int main() {
    
  int A;
  int i;
  int KEY;
  int X;
  char string[8888];
  char message[8888];
     char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   //                   ||||||||||||||||||||||||||
char Substitution[] = ("QWERTYUIOPASDFGHJKLZXCVBNM");


printf("Would you like to: \n\n");                                    //lists the task that are able to be performed 
                                                                      
printf("1.  Encrypt a message using a rotation cipher given message text AND the rotation amount?\n\n");
printf("2.  Decrypt a message encrypted with a rotation cipher given cipher text AND rotation amount?\n\n");
printf("3.  Encrypt of a message using a substitution cipher given message text AND alphabet substitutions?\n\n");
printf("4.  Decrypt a message encrypted with a substitution cipher given cipher text AND substitutions?\n\n");
/*printf("5.  Decrypt a message encrypted with a rotation cipher given ONLY cipher text?\n\n");
printf("6.  Decrypt a message encrypted with a substitution cipher given ONLY cipher text?\n\n\n\n");*/

printf("Please choose a task and enter the number which corresponds to it above: \n\n");

scanf("%d", &A);                                                    //get the user to enter a value for the task


switch (A)
{
    
                       
case 1:  
 printf("1; Rotation cipher encryption: Enter a word or phrase to be encrypted: ");   //the user is prompted to enter the word or phrase 
        scanf(" %[^\n]s", string);                                  //this is scanned into the string 
    printf("Enter the key: ");                                      //the user is prompted to enter the letter shift amount (key)
        scanf("%d", &KEY);                                          //this is scanned and stored into the KEY value 
  for ( i = 0; i < strlen(string); i++)                             //the conditions for which the encryption will work
    {
       X = string[i] - 65;                                          //converts ASCII value of letter to alphabet position of letter and stores this value in the letter X
       if (string[i]>31 && string[i]<65)                            //code checks if the ASCII value of the letter lies outside upper case A to lower case z
 {
   
     message[i]= string[i];                                         //if the above statement is true, the console will print whatever character is there (i.e. not encrypt)
                                                       
 }
   else if(X > -1 && X < 26)                                        //code checks if the letters entered are in upper case 
  {
    //if the above statement is true the following steps execute
      X= X+KEY;                                                     //KEY is added to the alphabet position of the letter
      X= X%26;                                                      //modulus of this number is calculated
      X= X+65;                                                      //65 is added to the number found through the modulus operator to shift the letter back into the ASCII range 
      message[i]= X;                                                //this converted letter is stored in the string array message[i]
}   
 else                                                               //if the letter isn't in upper case then the following steps execute 
    {
        X= X-32;                                                    //this shifts the ASCII value of a lower case letter to the corresponding upper case letter value in the range of 0 to 25
        X= X+KEY;                                                   //KEY is added to the alphabet position of the upper case letter
        X= X%26;                                                    //modulus of this number is calculated
        X= X+65;                                                    //adds 65 to the new value to shift the letter back into the ASCII range
        message[i]= X;                                              //this converted letter is stored in the string array message[i]
     }
}
   
   printf("Therefore the new phrase is: \n\%s\n\n", message);       //the new phrase/word is printed in all upper case
 
 break;
 
 
 
 case 2:
 printf("1; Rotation cipher decryption: Enter a word or phrase to be decrypted: ");   //the user is prompted to enter the word or phrase 
        scanf(" %[^\n]s", string);                                  //this is scanned into the string 
    printf("Enter the key: ");                                      //the user is prompted to enter the letter shift amount (key)
        scanf("%d", &KEY);                                          //this is scanned and stored into the KEY value
  for ( i = 0; i < strlen(string); i++)                             //the conditions for which the encryption will work
    {
     X = string[i] - 65;                                            //converts ASCII value of letter to alphabet position of letter and stores this value in the letter X
     if(string[i]>31 && string[i]<65)                               //code checks if the ASCII value of the letter lies outside upper case A to lower case z
 {
   
     message[i]= string[i];                                         //if the above statement is true, the console will print whatever character is there (i.e. not encrypt)
                                                        
 }
  else if(X > -1 && X < 26)                                         //code checks if the letters entered are in upper case 
  
  {
      X= X+(26 - KEY);                                              //KEY is added to the alphabet position of the letter (26-KEY so it shifts the letter forwards and keeps the value positive)
      X= X%26;                                                      //modulus of this number is calculated
      X= X+65;                                                      //adds 65 to the new value to shift the letter back into the ASCII range
      message[i]= X;                                                //this converted letter is stored in the string array message[i]
}                    
else                                                                //if the letter isn't in upper case then the following steps execute 
    {
       X= X-32;                                                     //this shifts the ASCII value of a lower case letter to the corresponding upper case letter value in the range of 0 to 25
       X= X+(26-KEY);                                               //KEY is added to the alphabet position of the letter (26-KEY so it shifts the letter forwards and keeps the value positive)
       X= X%26;                                                     //modulus of this number is calculated
       X= X+65;                                                     //adds 65 to the new value to shift the letter back into the ASCII range
       message[i]= X;                                               //this converted letter is stored in the string array message[i]
     }
 }

 printf("Therefore the new phrase is: \n\%s\n\n", message);         //the new phrase/word is printed
  break;
  
  
    
  
  
  case 3:                                                        
  printf("3; Substitution cipher encryption: The letter KEY that will be used in this substitution cipher is: %s \n\n", Substitution);  
  printf("Enter a word or phrase to be encrypted: ");              //the user is prompted to enter the word or phrase
  scanf(" %[^\n]s", string);                                       //this is scanned into the string 
  for ( i = 0; i < strlen(string); i++){                           //the conditions for the encryption
      X = string[i] - 65;                                          //converts ASCII value of letter to alphabet position of letter and stores this value in the letter X
                                  
   
if(string[i]>64 && string[i]<91){                                  //code checks if the letters entered are in upper case 
          X= Substitution[X];                                      //the letter X is assigned to the letter value of position X along the substitution key array
          message[i]= X;                                           //this converted letter is stored in the string array message[i]
     }
         
          
      
     else if(string[i]>96 && string[i]<123)                        //checks if the letters entered are in lowercase 
      {
          X= (string[i] - 65) -32;                                 //this shifts the ASCII value of a lower case letter to the corresponding upper case letter value in the range of 0 to 25
          X= Substitution[X];                                      //the letter X is assigned to the letter value of position X along the substitution key array
          message[i]= X;                                           //this converted letter is stored in the string array message[i]
     
     }
      
      else{
           message[i]= string[i];                                  //all other values are kept the same (i.e. are not encrypted and are printed as the plain text) 
      }
  }

     
   printf("Therefore the new phrase is: \n\%s\n\n", message);      //the new phrase/word is printed
  break;
  
  
  case 4:
  //substitution decryption 
  break;
  
  default:
  printf("Error: invalid input, pleae try again\n\n");
  
  }
return 0;
}
