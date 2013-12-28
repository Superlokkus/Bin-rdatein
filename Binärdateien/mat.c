//
//  mat.c
//  Binärdateien
//
//  Created by Markus Klemm on 28.12.13.
//  Copyright (c) 2013 Markus Klemm Enterprises. All rights reserved.
//

#include <stdio.h>
#include "mat.h"

void tArtPrint(const tArt *toprint)
{
    if (toprint->vBez[0] == 0  && toprint->vNr[0] == 0 && toprint->Lbst == 0)
    {
        printf("--------\n");
        return;
    }
    
    printf("%s %s %ld\n",toprint->vBez,toprint->vNr,toprint->Lbst);
    return;
}
