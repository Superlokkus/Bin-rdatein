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
    printf("%s %s %ld\n",toprint->vBez,toprint->vNr,toprint->Lbst);
    return;
}
