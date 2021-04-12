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

// char* getAddress();
// void getWebsite(const char* address);

int main(int argc, char** argv){
    CURL *curl;
    FILE *file;
    int result;

    char address[1000];
    printf("Please enter URL: ");
    scanf("%s", address);

    file = fopen(argv[0], "wb");
    curl = curl_easy_init();
    printf("%s\n", address);

    curl_easy_setopt(curl, CURLOPT_URL, address);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
    result = curl_easy_perform(curl);

    if (result == CURLE_OK)
        printf("Download successful!\n");
    else
        printf("Error: %s\n", curl_easy_strerror(result));

    fclose(file);
    curl_easy_cleanup(curl);
}

// char* getAddress(){
//     char address[1000];
//     printf("Please enter URL: ");
//     scanf("%s", address);
//     return addressPtr;
// }

// void getWebsite(const char* address){
//     CURL *curl;
//     FILE *file;
//     int result;

//     file = fopen("/Users/henrytsai/Documents/Ansync/test.html", "wb");
//     curl = curl_easy_init();
//     printf("%s\n", address);

//     curl_easy_setopt(curl, CURLOPT_URL, address);
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
//     curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
//     result = curl_easy_perform(curl);

//     if (result == CURLE_OK)
//         printf("Download successful!\n");
//     else
//         printf("Error: %s\n", curl_easy_strerror(result));

//     fclose(file);
//     curl_easy_cleanup(curl);
// }
