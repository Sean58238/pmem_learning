#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define bSIZE 4096
 
int main(int argc, char * argv[])
{
     int fd1, nread, fd2, n;
     struct stat sb;
     char *mapped;
     FILE *f;
     char* buf = NULL;
     unsigned long pages = 1;
 
     if((fd1 = open(argv[1], O_RDWR)) < 0){
         perror("open") ;
     }   
 
     if((fstat(fd1, &sb)) == -1 ){
           perror("fstat") ;
     }   

     if (argc > 2) {
         pages = atoi(argv[2]);
         printf("pages %d\n", pages);
     }
     
     if((mapped = mmap(NULL,  pages * 1024 , PROT_READ| \
               PROT_WRITE, MAP_SHARED|MAP_POPULATE, fd1, 0)) ==(void*) -1){
           perror("mmap") ;
     }

     printf("mapped addr: %p\n",mapped);
     sleep(1000);
     return 0;
                 
}