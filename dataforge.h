#include<termios.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<ctype.h>
int file_eof,count=0x0,show_offset=0x0;
int col,row,c;
void move_cursor(int row,int col){
  printf("\033[%d;%dH",row,col);
  printf("\n");
  
}
void dataforge_ascii(void *input_file){
  col=0x10,row=0x1;
  move_cursor(row,col);
  file_size_fun(input_file);
  printf(
    "\033[1;38;5;51m"
    "╔════════════════════════════════════════════════════════════════════════════╗\n"
    "║  █▓▒░  D A T A F O R G E   //   R A W   B I N A R Y   E D I T O R    ░▒▓█  ║\n"
    "╚════════════════════════════════════════════════════════════════════════════╝\n"
    "\033[0m"
    "\n"

    "\033[38;5;247m   ◈ Secure low-level binary manipulation environment\033[0m\n"
    "\n"

    "\033[1;38;5;51m  ┌─[ OPERATION MATRIX ]────────────────────────────────────────────────────┐\033[0m\n"
    "\033[38;5;118m    [←]\033[0m previous offset      \033[38;5;118m[→]\033[0m next offset\n"
    "\033[38;5;118m    [↵]\033[0m inject byte          \033[38;5;118m[s]\033[0m save changes\n"
    "\033[38;5;118m    [n]\033[0m next segment         \033[38;5;118m[q]\033[0m disengage\n"
    "\033[38;5;118m    [0-9A-F]\033[0m input hex pair (2 keystrokes)\n"
    "\033[1;38;5;51m  └─────────────────────────────────────────────────────────────────────────┘\033[0m\n"
    "\n"

    "\033[2;38;5;244m  STATE :: RAW_STREAM  |  ENCODING :: HEX_PAIR  |  BACKSPACE :: DISABLED\033[0m\n"
    "\n");

  printf("\033[1;38;5;51m  TARGET ::\033[0m \033[38;5;118m%s\033[0m   ", input_file);
  printf("\033[1;38;5;51mSIZE ::\033[0m \033[38;5;118m%d %s\033[0m\n"
  "\n",file_size,file_size_unit);

printf("\033[1;38;5;160m  ⚠ WARNING:\033[0m \033[38;5;250mDirect file modification. No undo available. Save each byte\033[0m\n"
"\n"
  );
}

void *file_stream(unsigned int byte_val,void *read_file){
    FILE *fs=fopen(read_file,"r+");

    fseek(fs,0x0,SEEK_SET);
   unsigned char *p=malloc(0x10);int i=0x0;
   if(byte_val>0x10){

      byte_val-=1;
     fseek(fs,byte_val,SEEK_CUR);
   }

   while(!feof(fs)){

     if(i==0x10){
       break;
    }
      fscanf(fs,"%c",(p+i));

   i++;
   if(!feof(fs)){

     file_eof=i;


   }

   }
   count=i;

   fclose(fs);
   return p;
   free(p);
}

void file_offset(unsigned int offset,unsigned int cursor_pointer,void *offset_file){
  FILE *fw=fopen(offset_file,"r+");

  fseek(fw,0x0,SEEK_SET);


  if(offset>0xf){
    offset+=cursor_pointer;

    fseek(fw,offset,SEEK_CUR);
    show_offset=ftell(fw);

  }
  else{

    fseek(fw,cursor_pointer,SEEK_CUR);
     show_offset=ftell(fw);
  }


  fclose(fw);
}


void file_write(unsigned int offset,unsigned char data,unsigned int cursor_pointer,void *write_file){
  FILE *fw=fopen(write_file,"rw+");

  fseek(fw,0x0,SEEK_SET);


  if(offset>0xf){
     offset+=cursor_pointer;

  fseek(fw,offset,SEEK_CUR);


  }
  else{

    fseek(fw,cursor_pointer,SEEK_CUR);

  }

  fprintf(fw,"%c",data);
  fclose(fw);
}

void dataforge(void *target_file){
    struct termios old,new;
    unsigned int cursor=0x0,c;
    char *c1=malloc(0x2);
     char *show=malloc(0x10);
  tcgetattr(STDIN_FILENO,&old);
  new=old;

  new.c_lflag&=~(ICANON);

  new.c_lflag&=ECHO;

  tcsetattr(STDIN_FILENO,TCSANOW,&new);
  unsigned char *file_data=malloc(0x10);
  unsigned char byte;
  static unsigned int line=0x10,pointer=0x0,offsets=0x0;
  printf("\033[?25l");
  printf("\033[2J");

dataforge_ascii(target_file);
col=0x10,row=0x14;

   start_stream:
                file_data=file_stream(line,target_file);

 while(count!=0x1){
   move_cursor(row,col);
    printf("  \033[1;38;5;202m%07x:     \033[0m", offsets);
   for(int i=0x0;i<file_eof;i++){


     if(i==cursor){

       printf("\033[1;38;5;196m[%02x]\033[0m ", *(file_data+i));

     }
     else{
       printf("\033[1;38;5;46m%02x \033[0m", *(file_data+i));
     }


     }


     printf("\033[?25l");
  fflush(stdout);
  printf("\033[38;5;238m");
  c=getchar();
   if(c=='q'){
     break;
  }


  if(c==27){
    unsigned char seq1=getchar(),seq2=getchar();
    if(seq1=='['){
      switch (seq2) {

        case 'C':   if(cursor<file_eof-0x1) cursor++;break;
        case 'D':   if(cursor>0x0) cursor--;break;
       break;
      }

    }
  }
  if(c=='n'){

    cursor=0x0;
    row+=0x2;
    offsets+=0x10;



    move_cursor(row,col);
     pointer+=0x10;
if(line%0x2==0x0){
    line++;

}
else{
  line+=0x10;

}
    goto start_stream;
  }
  if(c=='\n'){
     file_offset(pointer, cursor,target_file);
     printf("\n"
           "\033[1;38;5;39m  ⟦\033[0m"
       "\033[1;38;5;45mPATCH\033[0m"
       "\033[1;38;5;39m⟧\033[0m "
       "\033[38;5;245mbyte @ \033[0m"
       "\033[1;38;5;45m0x%07X\033[0m "
        "\033[38;5;245m::\033[0m "
       "\033[1;38;5;118m",
       show_offset
     );




    printf("\033[?25h");
    *(c1+0x0)=getchar();
    *(c1+0x1)=getchar();
printf("\033[2K");
     if(isdigit(*(c1+0x0))){
       *(c1+0x0)-=0x30;
     }
     else{
       *(c1+0x0)=toupper(*(c1+0x0))-0x41+0xa;
     }
     if(isdigit(*(c1+0x1))){
       *(c1+0x1)-=0x30;
     }
     else{
       *(c1+0x1)=toupper(*(c1+0x1))-0x41+0xa;
     }
     byte=(*(c1+0x0)<<0x4)|*(c1+0x1);

  }
  if(c=='s'){

    file_write(pointer,byte, cursor,target_file);

  }

  }
  free(show);
free(c1);
system("clear");
  tcsetattr(STDIN_FILENO,TCSANOW,&old);
  free(file_data);
  printf("\033[?25h");

}