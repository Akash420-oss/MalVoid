void deepscan_ascii(void *file_name,void *file_type,void *byteorder,void *file_format){
printf("\n"
"\033[38;5;24m   ╔════════════════════════════════════════════╗\033[0m\n"
"\033[1;38;5;45m   ║           DEEP-SCAN :: INITIATED           ║\033[0m\n"
"\033[38;5;24m   ╠════════════════════════════════════════════╣\033[0m\n"
"\033[1;38;5;196m   ║  [!] MALICIOUS CODE DETECTED               ║\033[0m\n"
"\033[38;5;24m   ╚════════════════════════════════════════════╝\033[0m\n"
);
printf("\033[38;5;24m   ┌────────────────────────────────────────────┐\033[0m\n");
printf("                   \033[1;38;5;45mSCAN \033[38;5;118mRESULT\033[0m                 \n");
printf("     • \033[38;5;250mCPU byteorder: \033[38;5;118m%s\n", byteorder);
printf("     • \033[38;5;250mFile: \033[38;5;118m%s\n", file_name);
printf("     • \033[38;5;250mFile type: \033[38;5;118m%s\n", file_type);
printf("     • \033[38;5;250mFile fingerprint: \033[38;5;118m%s\n", file_format);
printf("     • \033[38;5;250mFile size: \033[38;5;118m%d %s\n", file_size, file_size_unit);           
printf("\033[38;5;24m   └────────────────────────────────────────────┘\033[0m\n");

printf("\033[38;5;24m   ┌────────────────────────────────────────────┐\033[0m\n");
printf("                   \033[1;38;5;45mELF \033[38;5;118mRESULT\033[0m                 \n");
printf("     • \033[38;5;250mMagic number: \033[38;5;118m%s\n", elf_file_signature);
printf("     • \033[38;5;250mBit value: \033[38;5;118m%s\n", bit_value);
printf("     • \033[38;5;250mEndian: \033[38;5;118m%s\n", endian);
printf("     • \033[38;5;250mByte order: \033[38;5;118m%s\n", endian_check);
printf("     • \033[38;5;250mVersion: \033[38;5;118m%s\n", elf_version);  
printf("     • \033[38;5;250mOS ABI: \033[38;5;118m%s\n", elf_osabi);
printf("     • \033[38;5;250mObfuscated: \033[38;5;118m%s\n", packed);           
printf("\033[38;5;24m   └────────────────────────────────────────────┘\033[0m\n");
printf("\033[38;5;24m  ┌────────────────────────────────────────────┐\n");
printf("                   \033[1;38;5;45mPDF \033[38;5;118mRESULT\033[0m                 \n");
printf("     • \033[38;5;250mMagic Number: \033[38;5;118m%s           \n",pdf_file_signature);
printf("     • \033[38;5;250mVesrion: \033[38;5;118m%s \n",pdf_version);
printf("     • \033[38;5;250mGhostHide: \033[38;5;118m%s               \n",pdf_hidden_data);          
printf("\033[38;5;24m  └────────────────────────────────────────────┘\n\033[0m");
printf("\033[38;5;24m  ┌────────────────────────────────────────────┐\n");
printf("                   \033[1;38;5;45mJPG \033[38;5;118mRESULT\033[0m                 \n");
printf("     • \033[38;5;250mMagic Number: \033[38;5;118m%s           \n",jpg_file_signature);
printf("     • \033[38;5;250mVesrion: \033[38;5;118m%x%c%x \n",*(jpg_file_version+0x0),*(jpg_file_version+0x1)=0x2e,*(jpg_file_version+0x2));
printf("     • \033[38;5;250mShadow Signature: \033[38;5;118m%s \n",label);
printf("     • \033[38;5;250mPayload: \033[38;5;118m%s               \n",suspect);          
printf("\033[38;5;24m  └────────────────────────────────────────────┘\n\033[0m");
printf("\033[38;5;24m  ┌────────────────────────────────────────────┐\n");
printf("                   \033[1;38;5;45mPNG \033[38;5;118mRESULT\033[0m                 \n");
printf("     • \033[38;5;250mMagic Number: \033[38;5;118m%s           \n",png_file_signature);
printf("     • \033[38;5;250mPixelCrypt: \033[38;5;118m%s               \n",suspect_png);          
printf("\033[38;5;24m  └────────────────────────────────────────────┘\n\033[0m");
printf("\033[38;5;24m  ┌────────────────────────────────────────────┐\n");
printf("                   \033[1;38;5;45mPE \033[38;5;118mRESULT\033[0m                 \n");
printf("     • \033[38;5;250mDOS Magic Number: \033[38;5;118m%s           \n",dos_file_signature);
printf("     • \033[38;5;250mPE Magic Number: \033[38;5;118m%s \n",pe_file_signare);
printf("     • \033[38;5;250mBinary Type: \033[38;5;118m%s               \n",pe_type);
printf("     • \033[38;5;250mBit Value: \033[38;5;118m%s               \n",pe_bit);
printf("     • \033[38;5;250mObfuscated: \033[38;5;118m%s                               \n",packed_exe);           
printf("\033[38;5;24m  └────────────────────────────────────────────┘\n\033[0m");
printf("\033[38;5;24m  ┌────────────────────────────────────────────┐\n");
printf("                   \033[1;38;5;45mJAVA \033[38;5;118mRESULT\033[0m                 \n");
printf("     • \033[38;5;250mMagic Number: \033[38;5;118m%s           \n",bytecode_file_signature);
printf("     • \033[38;5;250mVesrion: \033[38;5;118m%s \n",java_version);
printf("     • \033[38;5;250mRoot Script: \033[38;5;118m%s \n",SourceFile);        
printf("\033[38;5;24m  └────────────────────────────────────────────┘\n\033[0m");
}