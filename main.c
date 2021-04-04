/* Name: Henry Tsai
   Date: 4/3/21
   This program displays websites in text and hexadecimal given a URL.

   Write a command-line program that takes one argument (a URL) and prints the
   resource at that URL to standard output, in the following way:
    - If the resource is text, print one line of that text per second, preceded 
    by line numbers, then exit.
    - If the resource is not text, print 16 bytes of the resource per line, in 
    hexadecimal with a space between each byte, preceded by file offset in hex, 
    one line per second (similar to the output of "od -t x1" on Linux)
    - While the lines are printing, if the user presses the "+" key, speed up 
    the display. If he presses "-", slow it down. If he presses the space bar, 
    stop the display, and restart it when he presses the space bar again. Do not
    echo these key presses to the output.
    - The program must respond immediately to key presses while printing.
    - Do not use threads. Otherwise,you may use whatever libraries are available
    and useful on your system, but bonus points using fewer libraries.
    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <curl/curl.h>

int main(){
// 1. get url input
    printf("Hello World!");
}

