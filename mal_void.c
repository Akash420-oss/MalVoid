#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<malvoid_headers/header_files.h>
#include<malvoid_headers/deepscan.h>
#include<malboid_headers/stringextract.h>
#include<malvoid_headers/hexdecipher.h>
#include<malvoid_headers/dataforge.h>
#define malvoid main
void help();
void error_catch(int sig){
     printf(
"\n\033[1;38;5;199m>\033[0m "
"\033[38;5;51mNo input detected.\033[0m "
"\033[38;5;45mEnter '\033[1;38;5;82mhelp\033[38;5;45m' to list commands.\033[0m\n"
);
     exit(1);
}
void malvoid(char argc,void *argv[]){
signal(SIGSEGV,error_catch);
if(argc<=0x3){
if(compare(*(argv+0x1),"?")==0x52||compare(*(argv+0x1),"help")==0x52){

(*(argv+0x2))?printf("Invalid commands try help or ?\n"):help();
}
else if(compare(*(argv+0x1),"deepscan")==0x52){
deepscan(*(argv+0x2)); 
}
else if(compare(*(argv+0x1),"stringextract")==0x52){
stringextract(*(argv+0x2)); 
}
else if(compare(*(argv+0x1),"hexdecipher")==0x52){
hexdecipher(*(argv+0x2)); 
}
else if(compare(*(argv+0x1),"dataforge")==0x52){
dataforge(*(argv+0x2)); 
}
else{
    printf(
"\033[1;38;5;196m[ERROR]\033[0m "
"\033[38;5;51mCommand not found:\033[0m "
"\033[38;5;39m%s\033[0m\n",
*(argv+0x1)
);

}
}
//else{
  //  perror("help or ?\n");

}
void help(){
printf("\n\033[1;38;5;51m┌────────────────────────────────────────────────────────────┐\033[0m");
printf("\n\033[1;38;5;51m│       \033[0m \033[1;38;5;199mM A L V O I D   —   C O M M A N D   G U I D E\033[0m \033[1;38;5;51m      │\033[0m");
printf("\n\033[1;38;5;51m└────────────────────────────────────────────────────────────┘\033[0m\n");

printf("\n\033[2;38;5;39mThis tool performs static malware analysis and binary inspection.\033[0m\n");

printf("\n\033[1;38;5;45m--- CORE DISCOVERY TOOLS -----------------------------------\033[0m");

printf("\n\033[38;5;51mdeepscan\033[0m        Analyze the file header and structure. Identifies file type, size, format, and layout.");
printf("\n\033[38;5;51mstringextract\033[0m   Extract all readable text, URLs, and embedded strings from the binary.");
printf("\n\033[38;5;51mhexdecipher\033[0m     Display the raw binary data as a formatted hex and ASCII view.");

printf("\n");

printf("\n\033[1;38;5;45m--- THE FORGE (Manipulation) -------------------------------\033[0m");

printf("\n\033[38;5;51mdataforge\033[0m       Modify raw bytes inside the file to patch instructions or change structural markers.");

printf("\n");

printf("\n\033[1;38;5;45m--- SYSTEM UTILITIES --------------------------------------\033[0m");

printf("\n\033[38;5;51mhelp\033[0m / \033[38;5;51m?\033[0m         Display this command reference.");
printf("\n\033[38;5;51mbye\033[0m /  \033[38;5;51mquit\033[0m      Exit the console.");

printf("\n");
printf("\n\033[1;38;5;45m--- USAGE -----------------------------------------------\033[0m");
printf("\n\033[38;5;39m<command_name>\033[0m \033[38;5;51m<target_file_name>\033[0m");

printf("\n");

}
