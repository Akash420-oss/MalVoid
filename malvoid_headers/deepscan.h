#include <malvoid_headers/file_format_check.h>
#include <malvoid_headers/ascii_art.h>
void *file_format_guess(void *magic_num_arrr){
char *arr[]={"undefined/text","elf","pe","pdf","jpg","png","gif","bmp","zip","gzip","rar","mp3","wav","java","pcap","mbr"};
char maxsize=*((char *)magic_num_arrr+0x0);
char j=0x0;
for(char i=0x0;i<0x10;i++){
  //  printf("%d",*((char *)magic_num_arrr+i));
    if(maxsize<*((char *)magic_num_arrr+i)){
        maxsize=*((char *)magic_num_arrr+i);
     //  printf("\nmatch=%d\n",*((char *)magic_num_arrr+i));
        j=i;
    }
}
//printf("boom %d",j);
return *(arr+j);
}
void deepscan(void *file){
struct stat type;
void *file_type=malloc(0x1);
if(lstat(file,&type)==-1){
    perror("file not found");
}
else{
    switch(type.st_mode & S_IFMT){
     case S_IFDIR: file_type="Directory type";break;
     case S_IFSOCK: file_type="Socket type";break;
     case S_IFREG: file_type="Regular type";break;
     case S_IFCHR: file_type="Character type";break;
     case S_IFIFO: file_type="FIFO type";break;
     case S_IFBLK: file_type="Block type";break;
     case S_IFLNK: file_type="Symbolic type";break;
     default: file_type="unknown type";break;
    }

FILE *file_checker=fopen(file,"r+");

fread(&magic_num,0x1,0x9,file_checker);
//printf(magic_num);
fclose(file_checker);
char magic_num_arr[]={magic_num_compare(magic_num,'u'),
magic_num_compare(magic_num,'E'),
magic_num_compare(magic_num,'O'),
 magic_num_compare(magic_num,'D'),
 magic_num_compare(magic_num,'J'),
// magic_num_compare(magic_num,EXIF),
 magic_num_compare(magic_num,'N'),
 magic_num_compare(magic_num,'G'),
 magic_num_compare(magic_num,'B'),
 magic_num_compare(magic_num,'Z'),
 magic_num_compare(magic_num,'I'),
 magic_num_compare(magic_num,'R'),
 magic_num_compare(magic_num,'3'),
 magic_num_compare(magic_num,'W'),
 magic_num_compare(magic_num,'V'),
 magic_num_compare(magic_num,'C'),
 magic_num_compare(magic_num,'M')
};
//for_elf(file,magic_num);
file_format=file_format_guess(magic_num_arr);
file_checking(file);
deepscan_ascii(file,file_type,cpu_byteorder(),file_format);
//printf("%s",bytecode_file_signature);

//printf(file_format_guess(magic_num_arr));
}
}

