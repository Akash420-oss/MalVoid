#include<stdio.h>
#include<stdlib.h>
void hexdecipher(void *hex_file){
printf(
"\n"
"\033[38;5;75m"
"╔════════════════════════════════════════════════════╗\n"
"\033[0m"
"\033[38;5;39m"
"║            HEX DECIPHER :: STATIC MODE             ║\n"
"\033[0m"
"\033[38;5;75m"
"╠════════════════════════════════════════════════════╣\n"
"\033[0m"
"\033[38;5;105m"
"║  INPUT  : hexadecimal byte stream                  ║\n"
"║  MODE   : raw hex analysis                         ║\n"
"║  SCOPE  : binary inspection                        ║\n"
"\033[0m"
"\033[38;5;75m"
"╚════════════════════════════════════════════════════╝\n"
"\033[0m"
"\n"
);
printf(
"\033[38;5;46m[+] Press ENTER\033[0m  "
"\033[38;5;243m| or |\033[0m  "
"\033[38;5;160mq\033[0m "
"\033[38;5;245mexit\033[0m > "
);
    FILE *fs=fopen(hex_file,"r+");
  char go;
  long int i=0x0;
    char data[0x10];
   while(!feof(fs)){
    if(go=='q'){
        break;
    }
        fscanf(fs,"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(data+0x0),(data+0x1),(data+0x2),(data+0x3),(data+0x4),(data+0x5),(data+0x6),(data+0x7),(data+0x8),(data+0x9),(data+0xa),(data+0xb),(data+0xc),(data+0xd),(data+0xe),(data+0xf));
        scanf("%c",&go);
        if(go=='\n'){
        printf("\033[38;5;75m%07x:\033[0m \033[38;5;196m%02x\033[0m \033[38;5;202m%02x\033[0m \033[38;5;226m%02x\033[0m \033[38;5;118m%02x\033[0m \033[38;5;51m%02x\033[0m \033[38;5;45m%02x\033[0m \033[38;5;39m%02x\033[0m \033[38;5;201m%02x\033[0m \033[38;5;177m%02x\033[0m \033[38;5;141m%02x\033[0m \033[38;5;105m%02x\033[0m \033[38;5;69m%02x\033[0m \033[38;5;33m%02x\033[0m \033[38;5;27m%02x\033[0m \033[38;5;21m%02x\033[0m \033[38;5;66m%02x\033[0m",i,*(data+0x0),*(data+0x1),*(data+0x2),*(data+0x3),*(data+0x4),*(data+0x5),*(data+0x6),*(data+0x7),*(data+0x8),*(data+0x9),*(data+0xa),*(data+0xb),*(data+0xc),*(data+0xd),*(data+0xe),*(data+0xf));
        }
        i+=0x10;
    }
  fclose(fs);
}
