typedef struct
{
  char vBez [25+1];
  char vNr  [12+1];
  long Lbst;
}tArt;


void tArtPrint(const tArt *toprint);

void sorttArtBez(tArt *tosort, unsigned long count);

void swaptArt(tArt *n1,tArt *n2);



