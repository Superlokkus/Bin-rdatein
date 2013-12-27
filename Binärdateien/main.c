//
//  main.c
//  Binärdateien
//
//  Created by Markus Klemm on 19.12.13.
//  Copyright (c) 2013 Markus Klemm Enterprises. All rights reserved.
//

#include <stdio.h>
#include "mat.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage %s <Filename>", argv[0]);
        return EXIT_FAILURE;
    }

#if DEBUG
    printf("Parameter: %s\n",argv[1]);
#endif
    
    FILE *file;
    
    if ( (file = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr,"%s\n",strerror(errno));
            return EXIT_FAILURE;
        }
    
    if (fclose(file)) //I wonder if that ever happens
    {
        fprintf(stderr, "%s\n",strerror(errno));
        return EXIT_FAILURE;
    }
    
    
    return 0;
}

