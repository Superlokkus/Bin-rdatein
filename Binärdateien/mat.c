//
//  mat.c
//  Binärdateien
//
//  Created by Markus Klemm on 28.12.13.
//  Copyright (c) 2013 Markus Klemm Enterprises. All rights reserved.
//

#include <stdio.h>
#include "mat.h"
#include <string.h>

void swaptArt(tArt *n1,tArt *n2)
{
    tArt tmp;
    
    strcpy(tmp.vNr,n1->vNr);
    strcpy(tmp.vBez, n1->vBez);
    tmp.Lbst = n1->Lbst;
    
    strcpy(n1->vBez, n2->vBez);
    strcpy(n1->vNr, n2->vNr);
    n1->Lbst = n2->Lbst;
    
    strcpy(n2->vBez, tmp.vBez);
    strcpy(n2->vNr, tmp.vNr);
    n2->Lbst = tmp.Lbst;
    
}

void tArtPrint(const tArt *toprint)
{
    if (toprint->vBez[0] == 0  && toprint->vNr[0] == 0 && toprint->Lbst == 0)
    {
        printf("--------\n");
        return;
    }
    
    printf("%12s %25s %ld\n",toprint->vBez,toprint->vNr,toprint->Lbst);
    return;
}

void sorttArtBez(tArt tosort[], unsigned long count)
{
    unsigned long i;
    for (i=0; i<count; i++) {
        unsigned long j;
        for (j = i+1; j<count; j++) {
            
            if (strcmp(tosort[i].vBez,tosort[j].vBez) > 0) {
                swaptArt(&tosort[i],&tosort[j]);
            }
        }
        
    }
}
void sorttArtvNr(tArt tosort[], unsigned long count)
{
    unsigned long i;
    for (i=0; i<count; i++) {
        unsigned long j;
        for (j = i+1; j<count; j++) {
            
            if (strcmp(tosort[i].vNr,tosort[j].vNr) > 0) {
                swaptArt(&tosort[i],&tosort[j]);
            }
        }
        
    }
}