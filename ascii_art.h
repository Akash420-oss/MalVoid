void deepscan_ascii(void *file_name,void *file_type,void *byteorder,void *file_format){
printf("\033[33m                     .-\"      \"-.\n");
printf("\033[33m                    /            \\ \n");
printf("\033[33m                   |              | \n");
printf("\033[33m                   |,  .-.  .-.  ,| \n");
printf("\033[31m                   | \)\(_o/  \\o_\)\( | \n");
printf("\033[31m                   |/     /\\     \\| \n");
printf("\033[31m                   (_     ^^     _) \n");
printf("\033[31m                    \\__|IIIIII|__/ \n");
printf("\033[31m                     | \\IIIIII/ | \n");
printf("\033[31m                     \\          / \n");
printf("\033[31m                      `--------` \n");
//if(code==0x1){
printf("\n\033[31m                [!] MALICIOUS CODE DETECTED \n");
//}
// else{
// printf("\n\033[32m                [✓] NO MALICIOUS CODE FOUND \n");    
// }

printf("  ┌────────────────────────────────────────────┐\n");
printf("                   \033[31mSCAN \033[32mRESULT\033[0m                 \n");
printf("     • \033[31mCPU byteorder: \033[32m%s           \n",byteorder);
printf("     • \033[31mFile: \033[32m%s \n",file_name);
printf("     • \033[31mFile type: \033[32m%s               \n",file_type);
printf("     • \033[31mFile format: \033[32m%s               \n",file_format);
printf("     • \033[31mFile Size: \033[32m%d %s                              \n",file_size,file_size_unit);           
printf("\033[31m  └────────────────────────────────────────────┘\n\033[0m");
printf("\033[31m  ┌────────────────────────────────────────────┐\n");
printf("                   \033[31mELF \033[32mRESULT\033[0m                 \n");
printf("     • \033[31mMagic Number: \033[32m%s           \n",elf_file_signature);
printf("     • \033[31mBit Value: \033[32m%s \n",bit_value);
printf("     • \033[31mEndian: \033[32m%s               \n",endian);
printf("     • \033[31mByteorder Status: \033[32m%s               \n",endian_check);
printf("     • \033[31mVersion: \033[32m%s                               \n",elf_version);  
printf("     • \033[31mUnix Type: \033[32m%s                               \n",elf_osabi);
printf("     • \033[31mObfuscated: \033[32m%s                               \n",packed);           
printf("\033[31m  └────────────────────────────────────────────┘\n\033[0m");
printf("\033[31m  ┌────────────────────────────────────────────┐\n");
printf("                   \033[31mPDF \033[32mRESULT\033[0m                 \n");
printf("     • \033[31mMagic Number: \033[32m%s           \n",pdf_file_signature);
printf("     • \033[31mVesrion: \033[32m%s \n",pdf_version);
printf("     • \033[31mHidden Data: \033[32m%s               \n",pdf_hidden_data);          
printf("\033[31m  └────────────────────────────────────────────┘\n\033[0m");
}