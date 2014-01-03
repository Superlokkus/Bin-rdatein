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
#include <unistd.h>

int main(int argc, const char * argv[])
{
    //Handling flags/options
    int filenamepos = 1;
    int option;
    enum sortcrit {
        none = 0,
        vBez = 1,
        vNr = 2
    };
    int sortcrit = none;
    while ((option = getopt(argc, argv, "hba")) != -1) {
#if DEBUG
        printf("%d\n",optind);
#endif
        switch (option) {
            case 'h':
                printf("%s [-h[-b|-a]] filename\n \n ", argv[0]);
                printf("Commands:\n -b Sort by Bezeichner \n -a Sort by Artnummer \n");
                return EXIT_SUCCESS;
                break;
            case 'b':
                sortcrit = vBez;
                break;
            case 'a':
                sortcrit = vNr;
                break;
            default:
                fprintf(stderr, "Usage: %s [-h[-b|-a]] filename\n Type %s -h for help\n ", argv[0],argv[0]);
                return EXIT_FAILURE;
                break;
        }
    }
    filenamepos = optind; //Filename is at the moment always last option, but maybe filename handling will be changed
    
    
    //Creating tArtList
    FILE *file;
    
    if ( (file = fopen(argv[filenamepos], "r")) == NULL)
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
    //tArtList ready for use
    
    
    //Sorting takes place
    if (sortcrit) {
        switch (sortcrit) {
            case vBez:
                sorttArtBez(tArtList, tArtCount);
                break;
            case vNr:
                sorttArtvNr(tArtList, tArtCount);
                break;
            
            default:
                break;
        }
    }
    
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
    return EXIT_SUCCESS;
}

