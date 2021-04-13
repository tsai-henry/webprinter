# webprinter
This program displays online content in text and hexadecimal format given a URL. It relies on three libraries to do so:

    -libcurl: a file transfer library for accessing online content
     (Download libcurl here: https://curl.se/download.html)
    -html2text: a library that parses html for text content
     (Download html2text here: http://www.mbayer.de/html2text/downloads/)
    -ncurses: a library for formatting command line programs
     (Download ncurses here: https://invisible-island.net/ncurses/)

To compile the program, run the following command in a Mac terminal:

    gcc main.c -lcurl -lncurses -o main

This could be simplified by using a makefile which I hope to add in the future.

To execute the program, run "./main" in a Mac terminal, then enter the URL of the online content you wish to access.


