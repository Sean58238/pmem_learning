/*
* This example shows how to create and destory pmem kind with defined or unlimited size.
*/

#include <memkind.h>

#include <stdio.h>
#include <stdlib.h>

//pmem max size = 32MB
#define PMEM_MAX_SIZE ( 32 * 1024 * 1024);
#define NUM_KINDS 10

static char path[PATH_MAX] = "/mnt/pmem0";

static void print_err_message(int err){
    char error_message[MEMKIND_ERROR_MESSAGE_SIZE];
    memkind_error_message(err, error_message, MEMKIND_ERROR_MESSAGE_SIZE);
    fprintf(stderr, "%s\n", error_message);
}

int main(int argc, char *argv[]){
    struct memkind *pmem_kinds[NUM_KINDS] = {NULL};
    struct memkind *pmem_kind = NULL;
    struct memkind *pmem_kind_unlimited = NULL;

    int err = 0, i = 0;
    
    if(agrc > 2){
        fprintf(stderr, "Usage:%s [pmem_kind_dir_path]\n", argv[0]);
        return 1;
    }else if(argc == 2 && (realpath(argv[1],path)==NULL)){
        fprintf(stderr, "Incorrect pmem_kind_dir_path%s\n", argv[1]);
        return 1;
    }

    fprintf(stdout, "This example shows how to create and destroy pmem kind with defined or unlimited size,\n PMEM kind directory:%s\n", path);
    
    return 0;
}