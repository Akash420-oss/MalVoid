#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header_files.h"
#include "deepscan.h"
#define malvoid main
void help();
void malvoid(char argc,void *argv[]){
if(argc<=0x3){
if(compare(*(argv+0x1),"?")==0x52||compare(*(argv+0x1),"help")==0x52){

(*(argv+0x2))?printf("Invalid commands try help or ?\n"):help();
}
else if(compare(*(argv+0x1),"deepscan")==0x52){
deepscan(*(argv+0x2)); 
}
else{
    printf("I don't recognize that command.\n");
}
}
else{
    printf("help or ?\n");
}
}
void help(){
printf("\nThe shellcode is instruction-dense. Executable functions include:");
    printf("\n");

printf("\n\033[32m--- CORE DISCOVERY TOOLS ---\033[0m");

printf("\ndeepscan        The File's ID Card: Checks the file's type, size, and how its data blocks are organized.");

printf("\nstringextract   The Whisper Snatcher: Rips out any readable words, web addresses, or secret commands hidden deep inside the binary.");
                

printf("\nhexdecipher     The Data Prism: Displays the file's soul—the raw binary code—in a neat hex/ASCII grid for byte-by-byte inspection.");

printf("\n");

printf("\n\033[31m--- THE FORGE (Manipulation) ---\033[0m");

printf("\ndataforge       The Binary Alchemist: Allows you to directly rewrite data inside the file, patching instructions or altering key structure markers.");

printf("\ncodedissect     The Instruction Decoder: Translates the confusing machine language into clear assembly steps.");
printf("\n");

printf("\n\033[033m--- SYSTEM UTILITIES ---\033[0m");

printf("\n? / help        The Field Manual: Displays this list of authorized commands.");

printf("\nquit / bye      Logout: exit the console.");
printf("\n");
}
