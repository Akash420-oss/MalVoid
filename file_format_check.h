void *sourcefile_name;
void for_elf(void *data,void *magic_num){
char elf_file_ok=magic_num_compare(magic_num,'E');
elf_file_signature=(elf_file_ok==0x4)?"Matched":"Not Matched";
FILE *elf_file=fopen(data,"r+");
char elf_val;
fseek(elf_file,0x4,SEEK_SET);
fscanf(elf_file,"%c",&elf_val);
if(elf_val==0x2){
bit_value="64-bit";    
}
else if(elf_val==0x1){
    bit_value="32-bit";
}
else{
    bit_value="Unknown-bit";
}
fseek(elf_file,0x5,SEEK_SET);
fscanf(elf_file,"%c",&elf_val);
if(elf_val==0x2){
endian="Big Endian";    
}
else if(elf_val==0x1){
    endian="Little Endian";
}
else{
    endian="Unknown Endian";
}
if(compare(endian,cpu_byteorder())==0x52){
    endian_check="Good Byte Order";
}
else if(compare(endian,cpu_byteorder())==0x57){
    endian_check="Bad Byte Order";
}
if(compare(endian,"Unknown Endian")==0x52){
  endian_check="Unknown Byte Order";
}
fseek(elf_file,0x6,SEEK_SET);
fscanf(elf_file,"%c",&elf_val);
if(elf_val==0x1){
elf_version="ELF Vesrsion 1";    
}
else{
elf_version="Invalid Version";
}
fseek(elf_file,0x7,SEEK_SET);
char check=0x0;
void *proper_elf=malloc(0x1);
while(!feof(elf_file)){
fread(proper_elf,0x1,0x7,elf_file);
if(compare(proper_elf,"text")==0x52){
  check++;
}
else if(compare(proper_elf,"data")==0x52){
  check++;
}
else if(compare(proper_elf,"_bss_st")==0x52){
  check++;
}
else if(compare(proper_elf,"_start")==0x52){
  check++;
}
else if(compare(proper_elf,"main")==0x52||compare(proper_elf,"_main@G")==0x52){
  check++;
}

}
fseek(elf_file,0x7,SEEK_SET);
fscanf(elf_file,"%c",&elf_val);
switch(("0x%x",elf_val)){
case 0x00: elf_osabi="System V ABI";break;
case 0x01: elf_osabi="HP-UX";break;
case 0x02: elf_osabi="NetBSD";break;
case 0x03: elf_osabi="Linux Old";break;
case 0x04: elf_osabi="GNU Hurd";break;
case 0x06: elf_osabi="Sun Solaris";break;
case 0x07: elf_osabi="IBM AIX";break;
case 0x08: elf_osabi="SGI IRIX";break;
case 0x09: elf_osabi="FreeBSD";break;
case 0x0a: elf_osabi="Compaq TRU64 Unix";break;
case 0x0b: elf_osabi="Novell Modesto";break;
case 0x0c: elf_osabi="OpenBSD";break;
case 0x0d: elf_osabi="OpenVMS";break;
case 0x0e: elf_osabi="HP Nonstop Kernel";break;
case 0x0f: elf_osabi="AROS Research OS";break;
case 0x10: elf_osabi="Fenix OS";break;
case 0x11: elf_osabi="Nuxi Cloud ABI";break;
case 0x12: elf_osabi="Status OpenVOS";break;
case 0x40: elf_osabi="ARM EABI";break;
case 0x41: elf_osabi="ARM Architecture";break;
case 0xa0: elf_osabi="Standalone";break;
default: elf_osabi="No Os";break;
}
free(proper_elf);
fclose(elf_file);
if(compare(elf_file_signature,"Matched")==0x52){
  packed=(check>0x0)?"No":"Yes";
}
}

void for_pdf(void *data,void *magic_num){
pdf_file_signature=(magic_num_compare(magic_num,'D')==0x4)?"Matched":"Not Matched";

FILE *pdf_file=fopen(data,"r+");

fseek(pdf_file,0x5,SEEK_SET);
fread(pdf_val,0x1,0x3,pdf_file);
if(*(pdf_val+0x0)>=0x30 && *(pdf_val+0x0)<=0x39 && *(pdf_val+0x1)==0x2e && *(pdf_val+0x2)>=0x30 && *(pdf_val+0x2)<=0x39){
pdf_version=pdf_val;
if(compare(pdf_file_signature,"Matched")==0x52){
void *pdf_eof=malloc(0x1);
while(!feof(pdf_file)){
fread(pdf_eof,0x1,0x3,pdf_file);

 if(compare(pdf_eof,"EOF")==0x52){
pdf_hidden_data="No";
break;
 }
 else{
pdf_hidden_data="Yes";
 }
}
free(pdf_eof);
}
}
else{
  pdf_version="Not Detected";
}
fclose(pdf_file);
}

void for_jpg(void *data,void *magic_num){
jpg_file_signature=(magic_num_compare(magic_num,'J')==0x2)?"Matched":"Not Matched";
char sections_count[0x2];
FILE *jpg_file=fopen(data,"r+");
fseek(jpg_file,0x6,SEEK_SET);

while(!feof(jpg_file)){
  fread(label_check,0x1,0x5,jpg_file);
 // printf("%s\n",label_check);
  if(compare(label_check,"JFIF")==0x52){
    label=label_check;
    break;
  }
  else if(compare(label_check,"EXIF")==0x52){
label=label_check;
break;
  }
  else{
    label="Unknown label";
    break;
  }
}
if(compare(jpg_file_signature,"Matched")==0x52){
fseek(jpg_file,0xb,SEEK_SET);
fread(bytes_two,0x1,0x2,jpg_file);
//printf("%x",bytes_two[1]);
*((char *)jpg_file_version+0x0)=("%x",bytes_two[0x0]);
*((char *)jpg_file_version+0x1)=0x2e;
*((char *)jpg_file_version+0x2)=("%x",*(bytes_two+0x1));
}
// char soi[]={0xff,0xd8};
char soi_count=0x0,eoi_count=0x0,dqt_count=0x0;
fseek(jpg_file,0x0,SEEK_SET);
// *(bytes_two+0x0)=0x0;
// *(bytes_two+0x1)=0x0;

while(!feof(jpg_file)){


fread(*(&bytes_two+0x1),0x1,0x2,jpg_file);

 if(bytes_count(*(&bytes_two+0x1),'m')==0x2){   

soi_count++;


}

}

fseek(jpg_file,-2,SEEK_END);
fread(*(&bytes_two+0x1),0x1,0x2,jpg_file);
  //fscanf(jpg_file,"%c",*(&bytes_two+0x0));
//printf("%c\n",*(bytes_two+0x0));
 if(bytes_count(*(&bytes_two+0x1),'e')==0x2){   

eoi_count++;
}


int offset=0x0;
//rewind(jpg_file);
fseek(jpg_file,0x0,SEEK_SET);

while(!feof(jpg_file)){

fread(*(&bytes_two+0x1),0x1,0x2,jpg_file);

 if(bytes_count(*(&bytes_two+0x1),'d')==0x2){   

dqt_count++;
break;
}
offset++;
}
fseek(jpg_file,(0x2*offset)+0x3,SEEK_SET);
fread(*(&bytes_two+0x0),0x1,0x2,jpg_file);
if(**(&bytes_two+0x0)>0x0&&**(&bytes_two+0x0)<0x7f){
char dqt_bytes[**(&bytes_two+0x0)-0x2];
//printf("%d\n",**(&bytes_two+0x0));
char identical_bytes=0x0;
fseek(jpg_file,sizeof(dqt_bytes)-0x1,SEEK_CUR);
fread(*(&bytes_two+0x0),0x1,0x2,jpg_file);
 if(bytes_count(*(&bytes_two+0x0),'d')==0x2){   
dqt_count++;
}

if(dqt_count==0x2){
fseek(jpg_file,(0x2*offset)+0x4,SEEK_SET);
for(char i=0x0;i<sizeof(dqt_bytes);i++){
  *(dqt_bytes+i)=("%x",fgetc(jpg_file));
}
fseek(jpg_file,0x4,SEEK_CUR);
char next_byte;
for(char i=0x0;i<sizeof(dqt_bytes);i++){
  fread(&next_byte,0x1,0x1,jpg_file);
  //printf("%x\n",next_byte);
  if(*(dqt_bytes+i)==next_byte){
   // printf("%x==%x\n",*(dqt_bytes+i),next_byte);
    identical_bytes++;
  }
}
if(sizeof(dqt_bytes)<=identical_bytes||sizeof(dqt_bytes)-0x1<=identical_bytes){
  dqt_bytes_match="Yes";
}
else{
  dqt_bytes_match="No";
}

}
}
if(compare(dqt_bytes_match,"Yes")==0x52||eoi_count<0x1||eoi_count>0x1||soi_count>0x1){
  suspect="Yes";
}
else{
  suspect="No";
}
//printf("%x",*(jpg_file_version+0x2));
fclose(jpg_file);
}

void for_png(void *data,void *magic_num){
png_file_signature=(magic_num_compare(magic_num,'N')==0x8)?"Matched":"Not Matched";
FILE *png_file=fopen(data,"r+");
void *eof_correct=malloc(0x1);
fseek(png_file,-8,SEEK_END);
fread(eof_correct,0x1,0x8,png_file);
if(compare(png_file_signature,"Matched")==0x52){
suspect_png=bytes_count(eof_correct,'i')?"No":"Yes";
}
free(eof_correct);
fclose(png_file);
}

void for_pe(void *data,void *magic_num){
  dos_file_signature=(magic_num_compare(magic_num,'O')==0x2)?"Matched":"Not Matched";
  FILE *pe_file=fopen(data,"r+");
fseek(pe_file,0x3c,SEEK_SET);
short int find_pe_number;

fread(&find_pe_number,0x1,0x2,pe_file);
//printf("%x",find_pe_number);
fseek(pe_file,find_pe_number,SEEK_SET);
char pe_magic_num[0x2];
fread(pe_magic_num,0x1,0x2,pe_file);
pe_file_signare=(magic_num_compare(pe_magic_num,'P')==0x2)?"Matched":"Not Matched";
fseek(pe_file,find_pe_number+0x16,SEEK_SET);
fread(pe_magic_num,0x1,0x2,pe_file);
//printf("%x",pe_magic_num[0x1]);
if(*(pe_magic_num+0x1)==0x0&&*(pe_magic_num+0x0)==0x26||*(pe_magic_num+0x1)==0x0&&*(pe_magic_num+0x0)==0x2){
pe_type="exe";
}
else if(*(pe_magic_num+0x1)==0x20&&*(pe_magic_num+0x0)==0x0){
pe_type="dll";
}
else if(*(pe_magic_num+0x1)==0x20&&*(pe_magic_num+0x0)==0x2){
pe_type="dll+exe";
}
else{
  pe_type="exe";
}
fseek(pe_file,find_pe_number+0x18,SEEK_SET);
fread(pe_magic_num,0x1,0x2,pe_file);

if(*(pe_magic_num+0x1)==0x2&&*(pe_magic_num+0x0)==0xb){
pe_bit="64-bit";
}
else if(*(pe_magic_num+0x1)==0x1&&*(pe_magic_num+0x0)==0xb){
pe_bit="32-bit";
}
fseek(pe_file,0x0,SEEK_SET);
char packed_check_count=0x0;
void *dos_mode=malloc(0x27);
while(!feof(pe_file)){
  fread(dos_mode,0x1,0x27,pe_file);
  if(compare(dos_mode,"This program cannot be run in DOS mode.")==0x52){
    packed_check_count++;
break;
  }
}
free(dos_mode);
void *check_data=malloc(0x1);
find_pe_number=0x188;
short int pack_offset=0x4e0;
fseek(pe_file,find_pe_number,SEEK_SET);
while(find_pe_number<pack_offset){
  fread(check_data,0x1,0x7,pe_file);
  if(compare(check_data,".text")==0x52){
    packed_check_count++;
  }
  else if(compare(check_data,"xdata")==0x52){
    packed_check_count++;
  }
find_pe_number++;
}
packed_exe=(packed_check_count>0x1)?"No":"Yes";

free(check_data);
fclose(pe_file);
}

void for_bytecode(void *data,void *magic_num){
  bytecode_file_signature=(magic_num_compare(magic_num,'V')==0x4)?"Matched":"Not Matched";
  FILE *bytecode_file=fopen(data,"r+");
  char version;
  fseek(bytecode_file,0x7,SEEK_SET);
  fread(&version,0x1,0x1,bytecode_file);
  switch(("0x%x",version)){
    case 0x2d: java_version="1.1";break;
    case 0x2e: java_version="1.2";break;
    case 0x2f: java_version="1.3";break;
    case 0x30: java_version="1.4";break;
    case 0x31: java_version="5";break;
    case 0x32: java_version="6";break;
    case 0x33: java_version="7";break;
    case 0x34: java_version="8";break;
    case 0x35: java_version="9";break;
    case 0x36: java_version="10";break;
    case 0x37: java_version="11";break;
    case 0x38: java_version="12";break;
    case 0x39: java_version="13";break;
    case 0x3a: java_version="14";break;
    case 0x3b: java_version="15";break;
    case 0x3c: java_version="16";break;
    case 0x3d: java_version="17";break;
    case 0x3e: java_version="18";break;
    case 0x3f: java_version="19";break;
    case 0x40: java_version="20";break;
    case 0x41: java_version="21";break;
    case 0x42: java_version="22";break;
    case 0x43: java_version="23";break;
    case 0x44: java_version="24";break;
    case 0x45: java_version="25";break;
    case 0x46: java_version="26";break;
    default: java_version="Unknown";break;
  }
  fseek(bytecode_file,0x0,SEEK_SET);
 //
char sourcefile_detect[0xb];
  //char count=0x0;
  int soucefile_offset=0x0;
  while(!feof(bytecode_file)){
// fread(sourcefile_name,0x1,0x2,bytecode_file);
fscanf(bytecode_file,"%10s",sourcefile_detect);
// printf("%s\n",sourcefile_name);
  if(compare(sourcefile_detect,"SourceFile")==0x52){
      //printf("%s\n",sourcefile_name);
        soucefile_offset=ftell(bytecode_file);
      
     break;
 }
  }
 // void *sourcefile_name=malloc(0x1);
if(soucefile_offset!=0x0){
 fseek(bytecode_file,soucefile_offset+0x3,SEEK_SET); 
 fscanf(bytecode_file,"%s",&sourcefile_name);
 //printf("%s",&SourceFile);
 SourceFile=&sourcefile_name;
}
else{
  SourceFile="Hidden";
}

  fclose(bytecode_file);
}
char file_checking(void *data){
  FILE *file_val=fopen(data,"r+");
  fseek(file_val,0x0,SEEK_END);
  file_size=ftell(file_val);
  if(file_size>=1000 && file_size<=1000000){
    file_size=file_size/1000;
    file_size_unit="kb";
  }
  else if(file_size>=1000000){
    file_size=file_size/1000000;
    file_size_unit="mb";
  }
  else{
  file_size=file_size;
   file_size_unit="byte";
  }
 // printf("%d",file_size);
  fclose(file_val);
 // if(compare(file_format,"elf")==0x52||compare(file_format,"pcap")==0x52||compare(file_format,"gzip")==0x52||compare(file_format,"zip")==0x52||compare(file_format,"rar")==0x52||compare(file_format,"gif")==0x52||compare(file_format,"bmp")==0x52||compare(file_format,"mbr")==0x52||compare(file_format,"wav")==0x52||compare(file_format,"undefined")==0x52)
for_elf(data,magic_num);
for_pe(data,magic_num);
for_bytecode(data,magic_num);
for_jpg(data,magic_num);
for_pdf(data,magic_num);
for_png(data,magic_num);
}