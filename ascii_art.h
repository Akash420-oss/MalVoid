void deepscan_ascii(void *file_name,void *file_type,void *byteorder,void *file_format){
printf(
"\033[38;5;93m   ╔════════════════════════════════════════════╗\033[0m\n"
"\033[38;5;51m   ║           DEEP-SCAN :: INITIATED           ║\033[0m\n"
"\033[38;5;93m   ╠════════════════════════════════════════════╣\033[0m\n"
"\033[38;5;196m   ║  [!] MALICIOUS CODE DETECTED               ║\033[0m\n"
"\033[38;5;93m   ╚════════════════════════════════════════════╝\033[0m\n"
);

printf("\033[0;31m   ┌────────────────────────────────────────────┐\033[0m\n");
printf("                   \033[31mSCAN \033[32mRESULT\033[0m                 \n");
printf("     • \033[31mCPU byteorder: \033[32m%s           \n",byteorder);
printf("     • \033[31mFile: \033[32m%s \n",file_name);
printf("     • \033[31mFile type: \033[32m%s               \n",file_type);
printf("     • \033[31mFile fingerprint: \033[32m%s               \n",file_format);
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
printf("     • \033[31mGhostHide: \033[32m%s               \n",pdf_hidden_data);          
printf("\033[31m  └────────────────────────────────────────────┘\n\033[0m");
printf("\033[31m  ┌────────────────────────────────────────────┐\n");
printf("                   \033[31mJPG \033[32mRESULT\033[0m                 \n");
printf("     • \033[31mMagic Number: \033[32m%s           \n",jpg_file_signature);
printf("     • \033[31mVesrion: \033[32m%x%c%x \n",*(jpg_file_version+0x0),*(jpg_file_version+0x1)=0x2e,*(jpg_file_version+0x2));
printf("     • \033[31mShadow Signature: \033[32m%s \n",label);
printf("     • \033[31mPayload: \033[32m%s               \n",suspect);          
printf("\033[31m  └────────────────────────────────────────────┘\n\033[0m");
printf("\033[31m  ┌────────────────────────────────────────────┐\n");
printf("                   \033[31mPNG \033[32mRESULT\033[0m                 \n");
printf("     • \033[31mMagic Number: \033[32m%s           \n",png_file_signature);
printf("     • \033[31mPixelCrypt: \033[32m%s               \n",suspect_png);          
printf("\033[31m  └────────────────────────────────────────────┘\n\033[0m");
printf("\033[31m  ┌────────────────────────────────────────────┐\n");
printf("                   \033[31mPE \033[32mRESULT\033[0m                 \n");
printf("     • \033[31mDOS Magic Number: \033[32m%s           \n",dos_file_signature);
printf("     • \033[31mPE Magic Number: \033[32m%s \n",pe_file_signare);
printf("     • \033[31mBinary Type: \033[32m%s               \n",pe_type);
printf("     • \033[31mBit Value: \033[32m%s               \n",pe_bit);
printf("     • \033[31mObfuscated: \033[32m%s                               \n",packed_exe);           
printf("\033[31m  └────────────────────────────────────────────┘\n\033[0m");
printf("\033[31m  ┌────────────────────────────────────────────┐\n");
printf("                   \033[31mJAVA \033[32mRESULT\033[0m                 \n");
printf("     • \033[31mMagic Number: \033[32m%s           \n",bytecode_file_signature);
printf("     • \033[31mVesrion: \033[32m%s \n",java_version);
printf("     • \033[31mRoot Script: \033[32m%s \n",SourceFile);        
printf("\033[31m  └────────────────────────────────────────────┘\n\033[0m");
}