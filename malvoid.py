from os import system
system("clear")
print("""
 \033[0;33m          .                                                      .
           .n                   .                 .                  n.
     .   .dP                  dP                   9b                 9b.    .
    4    qXb         .       dX                     Xb       .        dXp     t
   dX.    9Xb      .dXb    __                         __    dXb.     dXP     .Xb
   9XXb._       _.dXXXXb dXXXXbo.                 .odXXXXb dXXXXb._       _.dXXP
    9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.           .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP
     `9XXXXXXXXXXXXXXXXXXXXX'~   ~`OOO8b   d8OOO'~   ~`XXXXXXXXXXXXXXXXXXXXXP'
       `9XXXXXXXXXXXP' `9XX'   \033[32mMAL\033[0m\033[33m    `98v8P'  \033[32mVOID\033[0m\033[33m   `XXP' `9XXXXXXXXXXXP'\033[0m
         \033[31m  ~~~~~~~       9X.          .db|db.          .XP       ~~~~~~~
                           )b.  .dbo.dP'`v'`9b.odb.  .dX(
                         ,dXXXXXXXXXXXb     dXXXXXXXXXXXb.
                        dXXXXXXXXXXXP'   .   `9XXXXXXXXXXXb
                       dXXXXXXXXXXXXb   d|b   dXXXXXXXXXXXXb
                       9XXb'   `XXXXXb.dX|Xb.dXXXXX'   `dXXP
                        `'      9XXXXXX(   )XXXXXXP      `'
                                 XXXX X.`v'.X XXXX
                                 XP^X'`b   d'`X^XX
                                 X. 9  `   '  P )X
                                 `b  `       '  d'
                                  `             '\033[0m

 \033[0;33m        @@@@@@@@@@    @@@@@@   @@@       @@@  @@@   @@@@@@   @@@  @@@@@@@  
         @@@@@@@@@@@  @@@@@@@@  @@@       @@@  @@@  @@@@@@@@  @@@  @@@@@@@@ 
         @@! @@! @@!  @@!  @@@  @@!       @@!  @@@  @@!  @@@  @@!  @@!  @@@ 
         !@! !@! !@!  !@!  @!@  !@!       !@!  @!@  !@!  @!@  !@!  !@!  @!@ 
         @!! !!@ @!@  @!@!@!@!  @!!       @!@  !@!  @!@  !@!  !!@  @!@  !@! 
         !@!   ! !@!  !!!@!!!!  !!!       !@!  !!!  !@!  !!!  !!!  !@!  !!! 
 \033[0;31m        !!:     !!:  !!:  !!!  !!:       :!:  !!:  !!:  !!!  !!:  !!:  !!! 
         :!:     :!:  :!:  !:!   :!:       ::!!:!   :!:  !:!  :!:  :!:  !:! 
         :::     ::   ::   :::   :: ::::    ::::    ::::: ::   ::   :::: :: 
          :      :     :   : :  : :: : :     :       : :  :   :    :: :  :\033[0m  
                                           
                                               \033[5;31m~ᵐᵃˡʷᵃʳᵉ ˡⁱᵛᵉˢ ⁱⁿ ᵗʰᵉ ᵛᵒⁱᵈ~\033[0m

 """)
print("\nWelcome, Analyst. Your MalOps Console is ready. Type 'help/?' to see commands and 'quit' to exit.\n")
def main():
    cmd=input("\033[0;31mMalVoid➢ \033[0m")
    if(cmd=="quit" or cmd=="bye"):
      print("""
      .-.
     (o o)   G@@D 8Y3
     | O \\
      \   \\
       `~~~'   -- Session Terminated --
      """)
    else:
        system(f"./mal_void {cmd}")
        main() 
main()