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
#include <time.h>
#include <curl/curl.h>
#include <ncurses.h>

int main(){
    // Declaring file pointer, curl pointer, int for curl, string for URL
    FILE *file = fopen("output.html", "wb");
    CURL *curl = curl_easy_init();
    int result;
    char address[1000];

    // Initializing ncurses window and prompting user for address
    initscr();
    scrollok(stdscr, TRUE);
    printw("Please enter a valid URL: ");
    scanw("%s", address);

    // Accessing website using curl and writing output to file
    curl_easy_setopt(curl, CURLOPT_URL, address);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
    result = curl_easy_perform(curl);
    printw("Downloading website data . . .\n");

    // Checking if website was successfully downloaded
    if (result == 0)
        printw("Successfully downloaded data from %s\n", address);
    else
        printw("Error: %s\n", curl_easy_strerror(result));
    fclose(file);
    
    // Parsing website data into text or hexadecimal
    printw("Parsing website data . . .\n");
    if(strstr(address, ".png") != NULL || strstr(address, ".jpg") != NULL || strstr(address, ".bmp") != NULL )
        system("od -t x1 output.html > output.txt");
    else
        system("html2text output.html > output.txt");

    char input;
    char line[10000];
    int line_number = 1;
    int delay = 9E5;
    file = fopen("output.txt", "rb");
    noecho();
    timeout(100);

    while (getc(file) != EOF){
        input = getch();
        if (input == '+')
            delay = 1E5;
        else if (input == '-')
            delay = 2E6;
        else if (input == ' '){
            while (true){
                input = getch();
                if (input == ' ')
                    break;
            }
        }
        clock_t start_time = clock();
        while (clock() < start_time + delay)
            ;
        fgets(line, 10000, (FILE*)file);
        for (int i = 0; i < strlen(line); i++){
            if ((line[i] > 47 && line[i] < 123) && (line[i] < 58 || line[i] > 64) && (line[i] < 91 || line[i] > 96)){
                printw("%i  %s", line_number++, line);
                break;
            }
        }
    }
    // printw("\nEnd of file\n");

    printw("Press any key to exit.");
    timeout(-1);
    input = getch();
    endwin();
    fclose(file);
    return(0);
}
