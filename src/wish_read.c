#include "wish.h"
#include <string.h>
#include <ctype.h>

char *wish_read_line(FILE *in) { 
  
  if(in == NULL){
    perror("No file is present..."); 
    return NULL; 
  }

  //declaration 
  char* buff[WISH_MAX_INPUT];
  size_t len = sizeof(buff); 
  char* line = malloc(len); 
  //printf("size of buff: %ld", sizeof(buff)); 
  //printf("size of line: %ld", sizeof(line)); 

  line[0] = '\0'; 

  // readline and save it to buffer
  // param: destination, length of the input, file to stream
  size_t read = getline(buff, &len, in); 

  // size_t return -1 if there is issue 
  if(read == (size_t)-1){
    perror("Error reading message...\n");  
    free(line); 
    return NULL; 
  }

  // if read == 0 nothing on the line is present 
  if(read == 0){ 
    free(line); 
    return NULL; 
  }
  // if it stream more than the amount of memory available
  //printf("%ld, %ld", read, sizeof(line)); 
  if(read > len){
    fprintf(stderr,"wish : line too long\n");
    free(line); 
    return NULL; 
  }

  // copies from buffer to a new array without newline key
  strncpy(line, *buff, read-1); 
  if(line[read-1] == '\n'){
    line[read-1] = '\0';
  }
  printf("%s\n", line); 

  return line;  
}

int wish_read_config(char *fname, int ok_if_missing) {

  if((ok_if_missing == 0) && (fname != NULL)){
    FILE *in = fopen(fname, "r"); 
    char *line = wish_read_line(in);
  } else if((ok_if_missing == 0) && (fname == NULL)) { 
    perror("File not found...\n"); 
    return 1;  
  } 

  return 0;
}
