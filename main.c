/*
The following code can encrypt and decrypt both a rotation cipher and a substitution cipher

To run the code, in the terminal type: 
ls <enter> 
cd assessment1 <enter> 
ls <enter> 
gcc main.c <enter> 
./a.out <enter>

*/
/*
The substitution cipher text to decrypt is: RCR VYE BGBX HBNX FHB FXNQBRV YM RNXFH IZNQEBCJ FHB PCJB? C FHYEQHF KYF. CF'J KYF N JFYXV FHB DBRC PYEZR FBZZ VYE. CF'J N JCFH ZBQBKR. RNXFH IZNQEBCJ PNJ N RNXA ZYXR YM FHB JCFH, JY IYPBXMEZ NKR JY PCJB HB LYEZR EJB FHB MYXLB FY CKMZEBKLB FHB OCRCLHZYXCNKJ FY LXBNFB ZCMB… HB HNR JELH N AKYPZBRQB YM FHB RNXA JCRB FHNF HB LYEZR BGBK ABBI FHB YKBJ HB LNXBR NWYEF MXYO RVCKQ. FHB RNXA JCRB YM FHB MYXLB CJ N INFHPNV FY ONKV NWCZCFCBJ JYOB LYKJCRBX FY WB EKKNFEXNZ. HB WBLNOB JY IYPBXMEZ… FHB YKZV FHCKQ HB PNJ NMXNCR YM PNJ ZYJCKQ HCJ IYPBX, PHCLH BGBKFENZZV, YM LYEXJB, HB RCR. EKMYXFEKNFBZV, HB FNEQHF HCJ NIIXBKFCLB BGBXVFHCKQ HB AKBP, FHBK HCJ NIIXBKFCLB ACZZBR HCO CK HCJ JZBBI. CXYKCL. HB LYEZR JNGB YFHBXJ MXYO RBNFH, WEF KYF HCOJBZM.
The Key is: NWLRBMQHCDAZOKYISXJFEGPTVU 
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>

int main() {

    int A=0;
    int i=0;
    int KEY=0;
    int Y=0;
    int W=0;
    int Z=0;
    char X;
    char string[8888];
    char message[8888];
    char Substitution[26]; 
    char Alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";


    printf("Would you like to: \n\n");                                    //lists the task that are able to be performed

    printf("1.  Encrypt a message using a rotation cipher given message text AND the rotation amount?\n\n");
    printf("2.  Decrypt a message encrypted with a rotation cipher given cipher text AND rotation amount?\n\n");
    printf("3.  Encrypt of a message using a substitution cipher given message text AND alphabet substitutions?\n\n");
    //printf("4.  Decrypt a message encrypted with a substitution cipher given cipher text AND substitutions?\n\n");
    //printf("5.  Decrypt a message encrypted with a rotation cipher given ONLY cipher text?\n\n");
    //printf("6.  Decrypt a message encrypted with a substitution cipher given ONLY cipher text?\n\n\n\n");*/

    printf("Please choose a task and enter the number which corresponds to it above: \n\n");

    scanf("%d", &A);                                                    //get the user to enter a value for the task


    switch (A)
    {


    case 1:
        printf("1; Rotation cipher encryption: Enter a word or phrase to be encrypted: ");   //the user is prompted to enter the word or phrase
        scanf(" %[^\n]s", string);                                      //this is scanned into the string
        printf("Enter the key: ");                                      //the user is prompted to enter the letter shift amount (key)
        scanf("%d", &KEY);                                              //this is scanned and stored into the KEY value
        for ( i = 0; i < strlen(string); i++)                           //the conditions for which the encryption will work
        {
            X = string[i] - 65;                                         //converts ASCII value of letter to alphabet position of letter and stores this value in the letter X
            
            if(string[i]>64 && string[i]<91)                            //code checks if the ASCII value of the letter lies outside upper case A to lower case z
            {
                //if the above statement is true the following steps execute
                X= X+KEY;                                               //KEY is added to the alphabet position of the letter to give the letter the key shift
                X= X%26;                                                //modulus of this number is calculated
                X= X+65;                                                //65 is added to the number found through the modulus operator to shift the letter back into the ASCII range
                message[i]= X;                                          //this converted letter is stored in the string array message[i]
            }    
            
            else if(string[i]>96 && string[i]<123)                       //checks if the letters entered are in lowercase                                        
            {
                //if the above statement is true the following steps execute
                X= X-32;                                                //this shifts the ASCII value of a lower case letter to the corresponding upper case letter value in the range of 0 to 25
                X= X+KEY;                                               //KEY is added to the alphabet position of the letter to give the letter the key shift
                X= X%26;                                                //modulus of this number is calculated
                X= X+65;                                                //65 is added to the number found through the modulus operator to shift the letter back into the ASCII range
                message[i]= X;                                          //this converted letter is stored in the string array message[i]
            }
            
            else                                                        //if the letter isn't in upper case then the following steps execute
            {
                message[i] = string[i];                                 //If the value of the input is neither an upper or lowercase letter, it is not encrypted
            }
        }

        printf("Therefore the new phrase is: \n\%s\n\n", message);      //the new phrase/word is printed in all upper case

        break;



    case 2:
        printf("2; Rotation cipher decryption: Enter a word or phrase to be decrypted: ");   //the user is prompted to enter the word or phrase
        scanf(" %[^\n]s", string);                                     //this is scanned into the string
        printf("Enter the key: ");                                     //the user is prompted to enter the letter shift amount (key)
        scanf("%d", &KEY);                                             //this is scanned and stored into the KEY value
       for ( i = 0; i < strlen(string); i++)                           //the conditions for which the encryption will work
        {
            X = string[i] - 65;                                        //converts ASCII value of letter to alphabet position of letter and stores this value in the letter X
            
            if(string[i]>64 && string[i]<91)                           //code checks if the ASCII value of the letter lies outside upper case A to lower case z
            {
                //if the above statement is true the following steps execute
                X= X+(26-KEY);                                         //KEY is added to the alphabet position of the letter to give the letter the key shift
                X= X%26;                                               //modulus of this number is calculated
                X= X+65;                                               //65 is added to the number found through the modulus operator to shift the letter back into the ASCII range
                message[i]= X;                                         //this converted letter is stored in the string array message[i]
            }    
                                                           
           else if(string[i]>96 && string[i]<123)                      //checks if the letters entered are in lowercase                                        
            {
                //if the above statement is true the following steps execute
                X= X-32;                                               //this shifts the ASCII value of a lower case letter to the corresponding upper case letter value in the range of 0 to 25
                X= X+(26-KEY);                                         //KEY is added to the alphabet position of the letter to give the letter the key shift
                X= X%26;                                               //modulus of this number is calculated
                X= X+65;                                               //65 is added to the number found through the modulus operator to shift the letter back into the ASCII range
                message[i]= X;                                         //this converted letter is stored in the string array message[i]
            }
            
            else                                                       //if the letter isn't in upper case then the following steps execute
            {
                message[i] = string[i];                                //If the value of the input is neither an upper or lowercase letter, it is not encrypted
            }
        }

        printf("Therefore the new phrase is: \n\%s\n\n", message);     //the new phrase/word is printed
        break;



    case 3:
        printf("3; Substitution cipher encryption: Enter a word or phrase to be encrypted: ");    //the user is prompted to enter the word or phrase
        scanf(" %[^\n]s", string);                                     //this is scanned into the string
        printf("Enter the 26 capital letter substitution key with no spaces: ");  //the user is prompted to enter the letter substitution key
        scanf("%s", Substitution);                                    //this is scanned and stored into the substitution array
        for ( i = 0; i < strlen(string); i++)                         //the conditions for the encryption
        {                       
            X = string[i] - 65;                                       //converts ASCII value of letter to alphabet position of letter and stores this value in the letter X


            if(string[i]>64 && string[i]<91)                          //code checks if the letters entered are in upper case
            {                        
                X= Substitution[X];                                   //the letter X is assigned to the letter value of position X along the substitution key array
                message[i]= X;                                        //this converted letter is stored in the string array message[i]
            }

            else if(string[i]>96 && string[i]<123)                    //checks if the letters entered are in lowercase
            {
                X= (string[i] - 65) -32;                              //this shifts the ASCII value of a lower case letter to the corresponding upper case letter value in the range of 0 to 25
                X= Substitution[X];                                   //the letter X is assigned to the letter value of position X along the substitution key array
                message[i]= X;                                        //this converted letter is stored in the string array message[i]
            }
            
            else 
			{
                message[i]= string[i];                                //all other values are kept the same (i.e. are not encrypted and are printed as the plain text)
            }
        }


        printf("Therefore the new phrase is: \n\%s\n\n", message);    //the new phrase/word is printed
        break;


    /*case 4:
        printf("4 Substitution cipher decryption; Enter a word or phrase to be decrypted: ");           //the user is prompted to enter the word or phrase
        scanf(" %[^\n]s", string);                                 //this is scanned into the string
        printf("Enter the 26 capital letter substitution key with no spaces: ");  //the user is prompted to enter the letter substitution key
        scanf("%s", Substitution);
        for (i = 0; i< strlen(string); i++) {
            Y= string[i] - 65; 
          if(Y>=0 && Y<=26){
              X=string[i];
              for(Z=0; Z<26; Z++){
                  if(Substitution[Y]==X){
                      W = Z;
                  }
              }
              string[i]= 65 + W;
              message[i]= string[i];
          }
          else{message[i]=string[i];
          }
      }

         printf("Therefore the new phrase is: \n\%s\n\n", message); 

    break;*/


    default:
        printf("Error: invalid input, pleae try again\n\n");

    }
    return 0;
}
  

  