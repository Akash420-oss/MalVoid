#include<sys/stat.h>
#include"byte_sequence.h"
//#include"ascii_art.h"
void *cpu_byteorder(){
short int byteorder=0x424c;
return (*(char *)&byteorder==0x4c)?"Little Endian":"Big Endian";
}
char magic_num_compare(void *magic_num,char val){
     char count=0x0;
    if(val=='E'){
    char i=0x0;
for(;i<sizeof(ELF);i++){
//printf("check=%x from_file=%x\n",*(ELF+i),*((char *)magic_num+i));
     if(*((char *)magic_num+i)==*(ELF+i)){
        count++;
      }
    }
     (sizeof(ELF)>=count)?count:0x0;
}
   else if(val=='O'){
    char i=0x0;
for(;i<sizeof(DOS);i++){

     if(*((char *)magic_num+i)==*(DOS+i)){
        count++;
      }
    }

 (sizeof(DOS)>=count)?count:0x0;
}
   else if(val=='P'){
    char i=0x0;
for(;i<sizeof(PE);i++){

     if(*((char *)magic_num+i)==*(PE+i)){
        count++;
      }
    }

 (sizeof(PE)>=count)?count:0x0;
}
   else if(val=='D'){
    char i=0x0;
for(;i<sizeof(PDF);i++){

     if(*((char *)magic_num+i)==*(PDF+i)){
        count++;
      }
    }

 (sizeof(PDF)>=count)?count:0x0;
}
else if(val=='J'){
    char i=0x0;
for(;i<sizeof(JFIF);i++){

     if(*((char *)magic_num+i)==*(JFIF+i)){
        count++;
      }
    }

 (sizeof(JFIF)>=count)?count:0x0;
} 

else if(val=='N'){
    char i=0x0;
for(;i<sizeof(PNG);i++){

     if(*((char *)magic_num+i)==*(PNG+i)){
        count++;
      }
    }

 (sizeof(PNG)>=count)?count:0x0;
}
else if(val=='G'){
    char i=0x0;
for(;i<sizeof(GIF);i++){

     if(*((char *)magic_num+i)==*(GIF+i)){
        count++;
      }
    }

 (sizeof(GIF)>=count)?count:0x0;
}
else if(val=='B'){
    char i=0x0;
for(;i<sizeof(BMP);i++){

     if(*((char *)magic_num+i)==*(BMP+i)){
        count++;
      }
    }

 (sizeof(BMP)>=count)?count:0x0;
}

else if(val=='Z'){
    char i=0x0;
for(;i<sizeof(ZIP);i++){

     if(*((char *)magic_num+i)==*(ZIP+i)){
        count++;
      }
    }

 (sizeof(ZIP)>=count)?count:0x0;
}
else if(val=='I'){
    char i=0x0;
for(;i<sizeof(GZIP);i++){

     if(*((char *)magic_num+i)==*(GZIP+i)){
        count++;
      }
    }

 (sizeof(GZIP)>=count)?count:0x0;
}
else if(val=='R'){
    char i=0x0;
for(;i<sizeof(RAR);i++){

     if(*((char *)magic_num+i)==*(RAR+i)){
        count++;
      }
    }

 (sizeof(RAR)>=count)?count:0x0;
}
else if(val=='3'){
    char i=0x0;
for(;i<sizeof(MP3);i++){

     if(*((char *)magic_num+i)==*(MP3+i)){
        count++;
      }
    }

 (sizeof(MP3)>=count)?count:0x0;
}
else if(val=='W'){
    char i=0x0;
for(;i<sizeof(WAV);i++){

     if(*((char *)magic_num+i)==*(WAV+i)){
        count++;
      }
    }

 (sizeof(WAV)>=count)?count:0x0;
}
else if(val=='V'){
    char i=0x0;
for(;i<sizeof(JAVA);i++){
//printf("check=%x from_file=%x\n",*(JAVA+i),*((char *)magic_num+i));
     if(*((char *)magic_num+i)==*(JAVA+i)){
        count++;
      }
    }

 (sizeof(JAVA)>=count)?count:0x0;
}
else if(val=='C'){
    char i=0x0;
for(;i<sizeof(PCAP);i++){
//printf("check=%x from_file=%x\n",*(PCAP+i),*((char *)magic_num+i));
     if(*((char *)magic_num+i)==*(PCAP+i)){
        count++;
      }
    }

 (sizeof(PCAP)>=count)?count:0x0;
}
else if(val=='M'){
    char i=0x0;
for(;i<sizeof(MBR);i++){

     if(*((char *)magic_num+i)==*(MBR+i)){
        count++;
      }
    }

 (sizeof(MBR)>=count)?count:0x0;
}
else{
   return count=0x0;
}
}
char compare(void *str1,void *str2){
   char str1_len=strlen(str1);
    char str2_len=strlen(str2);
    char count=0x0;
    for(char i=0x0;i<=str1_len;i++){
        if(str1_len==str2_len){
        (*((char *)str1+i)==*((char *)str2+i))?count+=0x1:0x0;
        }
    }
 return (str2_len==count-0x1)?0x52:0x57;
}
char bytes_count(void *bytes,char val){
char count=0x0;
   if(val=='m'){
    char i=0x0;
for(;i<sizeof(JFIF);i++){
      //printf("bytes: %x == %x define\n",*((char *)bytes+i),*(JFIF+i));
     if(*((char *)bytes+i)==*(JFIF+i)){
        count++;
      }
      
    }
//printf("%d",count);
 (sizeof(JFIF)>=count)?count:0x0;
}
else if(val=='e'){
    char i=0x0;
for(;i<sizeof(EOI);i++){
 //  printf("bytes: %x == %x define\n",*((char *)bytes+i),*(EOI+i)); 
//   printf("define: %x\n",);
     if(*((char *)bytes+i)==*(EOI+i)){
     
        count++;
      }
    }
 //printf("%d",count);
  (sizeof(EOI)>=count)?count:0x0;
}
else if(val=='d'){
    char i=0x0;
for(;i<sizeof(DQT);i++){
 //  printf("bytes: %x == %x define\n",*((char *)bytes+i),*(DQT+i)); 
//   printf("define: %x\n",);
     if(*((char *)bytes+i)==*(DQT+i)){
     
        count++;
      }
    }
 //printf("%d",count);
  (sizeof(DQT)>=count)?count:0x0;
}
else if(val=='i'){
    char i=0x0;
for(;i<sizeof(IEND);i++){
 //  printf("bytes: %x == %x define\n",*((char *)bytes+i),*(IEND+i)); 
//   printf("define: %x\n",);
     if(*((char *)bytes+i)==*(IEND+i)){
     
        count++;
      }
    }
 //printf("%d",count);
  (sizeof(IEND)>=count)?count:0x0;
}
}