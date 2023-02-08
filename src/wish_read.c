#include "wish.h"
#include <string.h>
#include <ctype.h>

char *wish_read_line(FILE *in) { 
  
  if(in == NULL){
    perror("No line is present..."); 
    return NULL; 
  }

  char* buff[WISH_MAX_INPUT];
  size_t buff_len = sizeof(buff); 
  char* line = malloc(buff_len); 

  line[0] = '\0'; 

  if(line == NULL){
    perror("Unable to allocate memory...\n"); 
    free(line); 
    return NULL; 
  }

  size_t len = getline(buff,&buff_len, in);  

  if(len > WISH_MAX_INPUT){ 
    perror("wish : line too long"); 
    return NULL; 
  }

  if(len == 0){ 
    perror("Buffer is empty"); 
    return NULL; 
  }

  strncpy(line, *buff, len-1); 
  printf("%s\n",line);
  return line; 
}
  /*
  if (in == NULL){
    perror("No line is present..."); 
    return NULL; 
  }

  char chunk[WISH_MAX_INPUT]; 
  
  size_t len = sizeof(chunk); 
  char *line = malloc(len); 

  if(line == NULL){
    perror("Unable to allocate memory for line buffer..."); 
    exit(1); 
  }

  line[0] = '\0'; 

  while(fgets(chunk, sizeof(chunk), in) != NULL){
    size_t len_used = strlen(line); 
    size_t chunk_used = strlen(chunk); 

    if(len - len_used < chunk_used){
      len *= 2; 
      fprintf(stderr, "wish : line too long\n"); 
      free(line); 
      return NULL; 
    }

    strncpy(line + len_used, chunk, len-len_used); 
    len_used += chunk_used; 

     if(*line == '\0'){
        return NULL; 
    } 

    if(line[len_used-1] == '\n'){
      fputs(line, stdout); 
      len_used -= 1;  
      return line;
    }
  }
  return NULL; 
}
*/

  /*
  if(read == -1){
    perror(1); 
    return NULL; 
  }

  if(ptr[read-1]== '\n'){
    ptr[read-1] = '\0'; 
  }

  if(read > WISH_MAX_INPUT){
    free(ptr); 
    return NULL; 
  }

  for(int i = 0; i < read - 1; i++){
    if(isspace(ptr[i])){
      return ptr; 
    }
  }

  free(ptr); 
  return NULL; 
  */


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
