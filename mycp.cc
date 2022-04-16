#include "copy.h"
int main(int argc, char *argv[])
{
 //File pointer and variable initialization
//
FILE *fs, *ft;
//File size
//
int size;
//Blocksize being declared as an int
//
int blocksize;
//Memory allocation variable
//
int ma;
char *ptr;
//Input file is argv[1] and it is opened and read
//
fs = fopen(argv[1],"r");
//Output file is argv[2] and the contents of argv[1] are being prepared to be written to it
//
ft = fopen(argv[2],"w");
//Blocksize is converted from the string "Blocksize" to whatever int you use for argv[3]
//
blocksize=atoi(argv[3]);
//Finds the size of the input file
//
fseek(fs, 0, SEEK_END);
size = ftell(fs);
rewind(fs);
//If blocksize is greater than the file size then this statement makes them equal
//
if(blocksize>size){
ma = 1;
blocksize = size;
 printf("Blocksize is greater than file size");
}
else{
//mem address is size/blocksize
//
ma = size/blocksize;
}
//Allocates the chars to a specific space in memory
//
ptr = (char*)malloc(ma*blocksize);
//Copies files with specific blocksize
//
fread(ptr,blocksize,ma,fs);
fwrite(ptr, blocksize,ma,ft);
//Exit Gracefully :)
//
  return 0;
}
