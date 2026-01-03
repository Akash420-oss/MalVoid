#!/usr/bin/python
from os import system
system("clear")
print(
        "\033[1;38;5;199m"
        "███╗   ███╗ █████╗ ██╗     ██╗   ██╗ ██████╗ ██╗██████╗ \n"
        "████╗ ████║██╔══██╗██║     ██║   ██║██╔═══██╗██║██╔══██╗\n"
        "██╔████╔██║███████║██║     ██║   ██║██║   ██║██║██║  ██║\n"
        "██║╚██╔╝██║██╔══██║██║     ╚██╗ ██╔╝██║   ██║██║██║  ██║\n"
        "██║ ╚═╝ ██║██║  ██║███████╗ ╚████╔╝ ╚██████╔╝██║██████╔╝\n"
        "╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝  ╚═══╝   ╚═════╝ ╚═╝╚═════╝ \n"
        "\033[0m"
        "\033[38;5;51m   >>> MALVOID :: STATIC MALWARE ANALYSIS TOOL <<<\n"
        "\033[38;5;45m"
        "──────────────────────────────────────────────────────\n"
        "\033[2;38;5;39m"
        "  help           \033[38;5;51mshow command list\n"
        "\033[2;38;5;39m"
        "  bye            \033[38;5;51mterminate session\n"
        "\033[2;38;5;39m"
        "  deepscan       \033[38;5;51mdeep threat inspection\n"
        "\033[2;38;5;39m"
        "  hexdecipher    \033[38;5;51mdecode hex / binary\n"
        "\033[2;38;5;39m"
        "  stringextract  \033[38;5;51mextract printable data\n"
        "\033[2;38;5;39m"
        "  dataforge      \033[38;5;51mforge / mutate payload\n"
        "\033[38;5;45m"
        "──────────────────────────────────────────────────────\n"
        "\033[0m\n"
)
def main():
    cmd=input("\033[1;38;5;51mmalvoid\033[38;5;39m@\033[38;5;45manalysis\033[38;5;39m > \033[0m"
)
    if(cmd=="quit" or cmd=="bye"):
       print("\n\033[38;5;51mSession terminated.\033[0m\n")
    else:
        system(f"mal_void {cmd}")
        main() 
main()
