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
    printf("Argument 1: %s\n",argv[1]);
#endif
    
    FILE *file;
    
    if ( (file = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr,"%s\n",strerror(errno));
            return EXIT_FAILURE;
        }
    

    //Get the filelenght
    fseek(file, 0, SEEK_END);
    unsigned long filelenght = ftell(file);
    fseek(file, 0L, SEEK_SET);
#if DEBUG
    printf("Count of objects: %ld\n",filelenght/sizeof(tArt));
#endif
    
    tArt *tArtList = malloc(filelenght);
    if (tArtList == NULL) {
        fprintf(stderr, "%s\n",strerror(errno));
        return EXIT_FAILURE;
    }

    unsigned long tArtCount = filelenght/sizeof(tArt);
    fread(tArtList,sizeof(tArt),tArtCount, file);
    
    
    sorttArtBez(tArtList, tArtCount);
    
    //Output
    unsigned long i;
    printf("Art.-Nr      Bezeichnung              Stueckzahl   Soll   Unterschrift\n");
    for (i=0; i<= tArtCount; i++) {
        tArtPrint(&tArtList[i]);
    }
    
    
    //Cleanup
    if (fclose(file)) //I wonder if that ever happens
    {
        fprintf(stderr, "%s\n",strerror(errno));
        return EXIT_FAILURE;
    }
    free(tArtList);
    return 0;
}

