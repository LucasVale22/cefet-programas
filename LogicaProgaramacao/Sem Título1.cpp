#include <stdio.h>
#include <stdlib.h> //para usar o comando system

#include<conio.h> // para a função getch

main ()
{

char string[5];
printf ("\n Digite a senha de 5 digitos: ");
string[0] = getch();
printf ("*");
string[1] = getch();
printf ("*");
string[2] = getch();
printf ("*");
string[3] = getch();
printf ("*");
string[4] = getch();
printf ("*");




if((string[0] == 'a') && (string[1] == 'd') && (string[2] == 'r') && (string[3] == 'i') && (string[4] == 'a'))
printf ("\nAcesso permitido!\nparabens!\no que voce deseja fazer agora?\n");
else
printf ("\nAcesso negado!\n voce nao tem permicao para acesso!\n");

system("pause"); //para ver o resultado
}
