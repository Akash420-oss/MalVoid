void stringextract(void *str_file){
file_size_fun(str_file);
  printf(
"\033[38;5;82m"
"┌──────────────────────────────────────────────────┐\n"
"│                STRING ANALYSIS MODE              │\n"
"└──────────────────────────────────────────────────┘\n"
"\033[38;5;214m");
printf("  input  : %s                     \n",str_file);
printf("  filter : printable ASCII / UTF-8                 \n");
printf("  size  : %d %s                                  \n",file_size,file_size_unit);
printf("\033[0m"
"\n"
);


FILE *fs=fopen(str_file,"r+");
fseek(fs,0x0,SEEK_END);
long long int size_file=ftell(fs);
fseek(fs,0x0,SEEK_SET);

void  *val=malloc(size_file);
printf(
"\033[38;5;39m[+] Press ENTER\033[0m  "
"\033[38;5;244m| or |\033[0m  "          
"\033[38;5;196mq\033[0m "                 
"\033[38;5;243mexit\033[0m > "            
);
  char new_line;
while(!feof(fs)){

fscanf(fs,"%s",val);
if(new_line=='q'){
    break;
}


scanf("%c",&new_line);
if(new_line=='\n'){
    printf("\033[38;5;46mm%s\033[0m",val);
}

}

fclose(fs);
free(val);
}