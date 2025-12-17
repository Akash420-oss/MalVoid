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

//int fd=open(*(argv+0x1),0644);
void  *val=malloc(size_file);
       printf("\033[1;32m[+] Press ENTER\033[0m  \033[2;37m| or |\033[0m  \033[1;31mq\033[0m exit > ");
//fscanf(fs,"%s",val);
  //printf("\033[33m%s\033[0m",val);
  //fseek(fs,ftell(fs),SEEK_CUR);
  char new_line;
while(!feof(fs)){

fscanf(fs,"%s",val);
if(new_line=='q'){
    break;
}


scanf("%c",&new_line);
if(new_line=='\n'){
    printf("\033[33m%s\033[0m",val);
      //printf("\n\033[0;32mPress Enter or q>\033[0m");
}

//read(fd,val,size_file);
}
//close(fd);
fclose(fs);
free(val);
// void *cmd=malloc(0x1);
// sprintf(cmd,"cat  %s",*(argv+0x1));
// system(cmd);
// free(cmd);
}