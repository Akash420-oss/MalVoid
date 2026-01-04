CC = gcc
CFLAGS = -w 
SRC = mal_void.c
OUT = mal_void
PY = malvoid.py
HDR = malvoid_headers
PYBIN = malvoid
CHKDIR = /usr/include/malvoid_headers
build:
	@$(CC) $(CFLAGS) -I. $(SRC) -o $(OUT)
	@mv $(PY) $(PYBIN) 
	@chmod a+x mal_void malvoid
install:
	@clear
	@echo -e "\033[1;36m[ INIT ]\033[0m Installing + building project..."
	@sleep 0.5

	@bash -c '\
	frames=("[█       ]" "[██      ]" "[███     ]" "[████    ]" "[█████   ]" "[██████  ]" "[███████ ]" "[████████]"); \
	rm -f malvoid_banner.png malvoid_output.png; \
	i=0; \
	if [ ! -d "$(CHKDIR)" ]; then \
	  echo -e "\033[1;34m[ MKDIR ]\033[0m Creating $(CHKDIR)"; \
	  sudo cp -r "$(HDR)" "/usr/include/$(HDR)"; \
	  sudo cp  malvoid_icon.png "/usr/share/pixmaps"; \
	  sudo cp  malvoid.desktop "/usr/share/applications"; \
	fi; \
	for h in "$(HDR)"/*.h; do \
	  printf "\r\033[1;32m[ INSTALL ]\033[0m %-12s \033[2;37m%s\033[0m" "$${frames[$$((i%8))]}" "$$(basename "$$h")"; \
	  sudo install -m 644 "$$h" "$(CHKDIR)/" || exit 1; \
	  sleep 0.15; \
	  ((i++)); \
	done; \
	echo "" \
	'

	@echo -e "\033[1;34m[ BUILD:C ]\033[0m Compiling $(SRC)..."
	@$(CC) $(CFLAGS) "$(SRC)" -o "$(OUT)" || { echo -e "\033[1;31m[ FAIL ]\033[0m C compilation failed."; exit 1; }
	@sudo install -m 744 $(OUT) "/usr/bin/" && rm -f "$(OUT)"
	@if [ -f "$(PY)" ]; then \
	  echo -e "\033[1;34m[ CHECK:PY ]\033[0m Found $(PY)"; \
	  cp $(PY) malvoid;\
	  sudo install -m 744 $(PYBIN) "/usr/bin/" && rm -f $(PYBIN) || exit 1; \
	fi

	@echo -e "\033[1;35m[ OK ]\033[0m All steps completed successfully ✔"
	@echo -e "\033[2;37mRun: sudo $(PYBIN)\033[0m"
clean:
	@clear
	@echo -e "\033[1;36m[ CLEAN ]\033[0m Removing installed files..."
	@sleep 0.4

	@bash -c '\
	frames=("[░       ]" "[▒░      ]" "[▒▒░     ]" "[▒▒▒░    ]" "[▒▒▒▒░   ]" "[▒▒▒▒▒░  ]" "[▒▒▒▒▒▒░ ]" "[▒▒▒▒▒▒▒░]"); \
	i=0; \
	if [ -d "$(CHKDIR)" ]; then \
	  for step in "$(CHKDIR)"/*.h; do \
	    printf "\r\033[1;31m[ REMOVE ]\033[0m %-12s \033[2;37m%s\033[0m" "$${frames[$$((i%8))]}" "$$(basename "$$step")"; \
	    sleep 0.2; \
	    ((i++)); \
	  done; \
	  sudo rm -rf "$(CHKDIR)"; \
	fi; \
	sudo rm -f /usr/share/pixmaps/malvoid_icon.png /usr/share/applications/malvoid.desktop; \
	sudo rm -f "/usr/bin/$(OUT)" && sudo rm -f "/usr/bin/$(PYBIN)"; \
	echo "" \
	'
	

	@echo -e "\033[1;35m[ OK ]\033[0m Clean complete ✔"
