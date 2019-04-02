#include <stdio.h>

//Inputs: 
//Outputs: encryption, decryption  

int func (int encryption, int decryption, int x);	//function prototype

int main()
{
 int x;
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

printf("Enter a whole number between 0 and 7: \n\n", x);

scanf("%d", &x);

return 0;
}

