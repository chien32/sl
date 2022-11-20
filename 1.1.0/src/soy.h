#ifndef SOY_LIB_H
#define SOY_LIB_H

/*=========================================================================*/
/* SOY LIB                                                                 */
/*=========================================================================*/

/*
* o-------------------------------------------o
* | soyLib                                    |
* o-------------------------------------------o
* | Graphics Audio and Input Library          |
* |                                           |
* |                                           |
* | Copyright 2022 Maj Zalaznik Novak         |
* | All rights reserved.                      |
* |                                           |
* | Version: 0.1.8                            |
* o-------------------------------------------o
*/

/*=========================================================================*/
/* CORE LIB                                                                */
/*=========================================================================*/

/*=========================================================================*/
/* READ-ONLY DATA                                                          */
/*=========================================================================*/

const unsigned short g_packedFont0[1792] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,56,68,170,130,198,186,68,56,0,0,0,0,
0,0,56,124,214,254,186,198,124,56,0,0,0,0,
0,0,108,254,254,254,124,56,56,16,16,0,0,0,
0,0,16,56,124,254,254,124,56,16,0,0,0,0,
0,16,56,56,124,254,254,108,16,124,0,0,0,0,
0,16,56,124,254,254,254,108,16,124,0,0,0,0,
0,0,0,16,56,124,56,16,0,0,0,0,0,0,
0,254,254,238,198,130,198,238,254,254,0,0,0,0,
0,0,0,56,68,68,68,56,0,0,0,0,0,0,
0,254,254,198,186,186,186,198,254,254,0,0,0,0,
0,224,192,160,28,34,34,34,28,0,0,0,0,0,
0,56,68,68,68,56,16,124,16,16,0,0,0,0,
0,24,24,40,104,72,72,46,6,0,0,0,0,0,
0,224,184,136,136,136,136,102,102,0,0,0,0,0,
0,16,84,56,68,198,68,56,84,16,0,0,0,0,
0,0,0,4,12,28,60,28,12,4,0,0,0,0,
0,0,0,64,96,112,120,112,96,64,0,0,0,0,
0,16,56,84,16,16,16,84,56,16,0,0,0,0,
36,36,36,36,36,36,0,0,36,36,0,0,0,0,
60,42,42,42,60,40,40,40,40,40,40,0,0,0,
56,68,4,24,36,72,48,64,68,56,0,0,0,0,
0,0,0,0,0,254,254,254,254,254,0,0,0,0,
16,56,84,16,16,84,56,16,0,124,0,0,0,0,
0,16,56,84,16,16,16,16,16,16,16,0,0,0,
0,16,16,16,16,16,16,16,84,56,16,0,0,0,
0,0,0,0,16,32,126,32,16,0,0,0,0,0,
0,0,0,0,8,4,126,4,8,0,0,0,0,0,
0,0,0,0,0,12,12,12,12,124,0,0,0,0,
0,0,0,0,40,68,254,68,40,0,0,0,0,0,
0,0,0,0,16,56,124,254,0,0,0,0,0,0,
0,0,0,0,254,124,56,16,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,16,16,16,16,16,16,16,0,0,16,0,0,0,
0,36,36,36,36,0,0,0,0,0,0,0,0,0,
0,72,72,72,252,72,36,126,36,36,36,0,0,0,
0,16,56,84,20,20,56,80,80,84,56,16,0,0,
0,76,82,50,44,16,16,104,152,148,100,0,0,0,
0,24,36,36,24,8,148,98,34,34,220,0,0,0,
0,32,32,16,8,0,0,0,0,0,0,0,0,0,
0,32,16,16,8,8,8,8,8,16,16,32,0,0,
0,8,16,16,32,32,32,32,32,16,16,8,0,0,
0,0,16,84,56,56,84,16,0,0,0,0,0,0,
0,0,0,0,16,16,124,16,16,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,48,48,32,24,0,
0,0,0,0,0,0,124,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,48,48,0,0,0,
0,64,64,32,32,16,16,8,8,4,4,0,0,0,
0,0,48,72,72,72,72,72,72,72,48,0,0,0,
0,0,16,24,20,16,16,16,16,16,124,0,0,0,
0,0,56,68,64,64,32,16,8,4,124,0,0,0,
0,0,56,68,64,64,48,64,64,68,56,0,0,0,
0,0,64,96,80,72,68,68,252,64,64,0,0,0,
0,0,124,4,4,60,64,64,68,68,56,0,0,0,
0,0,56,68,4,4,60,68,68,68,56,0,0,0,
0,0,124,68,64,32,32,32,16,16,16,0,0,0,
0,0,56,68,68,68,56,68,68,68,56,0,0,0,
0,0,56,68,68,68,120,64,64,68,56,0,0,0,
0,0,0,0,48,48,0,0,0,48,48,0,0,0,
0,0,0,0,48,48,0,0,0,48,48,32,24,0,
0,64,32,16,8,4,2,4,8,16,32,64,0,0,
0,0,0,0,0,62,0,0,62,0,0,0,0,0,
0,2,4,8,16,32,64,32,16,8,4,2,0,0,
0,56,68,68,64,32,16,16,0,0,16,0,0,0,
0,16,40,68,116,84,84,116,4,72,48,0,0,0,
0,0,16,16,40,40,40,68,124,68,68,0,0,0,
0,0,28,36,36,36,60,68,68,68,60,0,0,0,
0,0,56,68,68,4,4,4,68,68,56,0,0,0,
0,0,28,36,68,68,68,68,68,36,28,0,0,0,
0,0,124,4,4,4,60,4,4,4,124,0,0,0,
0,0,124,4,4,4,60,4,4,4,4,0,0,0,
0,0,56,68,4,4,100,68,68,100,88,0,0,0,
0,0,68,68,68,68,124,68,68,68,68,0,0,0,
0,0,124,16,16,16,16,16,16,16,124,0,0,0,
0,0,120,32,32,32,32,32,36,36,24,0,0,0,
0,0,68,36,20,12,20,36,36,68,68,0,0,0,
0,0,4,4,4,4,4,4,4,4,124,0,0,0,
0,0,66,66,102,102,90,90,66,66,66,0,0,0,
0,0,68,76,76,84,84,100,100,68,68,0,0,0,
0,0,56,68,68,68,68,68,68,68,56,0,0,0,
0,0,60,68,68,68,60,4,4,4,4,0,0,0,
0,0,56,68,68,68,68,68,68,68,56,16,96,0,
0,0,60,68,68,68,60,36,68,68,68,0,0,0,
0,0,56,68,4,8,48,64,68,68,56,0,0,0,
0,0,124,16,16,16,16,16,16,16,16,0,0,0,
0,0,68,68,68,68,68,68,68,68,56,0,0,0,
0,0,68,68,68,40,40,40,16,16,16,0,0,0,
0,0,130,130,130,146,84,84,84,40,40,0,0,0,
0,0,68,68,40,40,16,40,40,68,68,0,0,0,
0,0,68,68,68,40,16,16,16,16,16,0,0,0,
0,0,124,64,64,32,16,8,4,4,124,0,0,0,
0,120,8,8,8,8,8,8,8,8,8,120,0,0,
0,4,4,8,8,16,16,32,32,64,64,0,0,0,
0,60,32,32,32,32,32,32,32,32,32,60,0,0,
0,0,16,56,108,68,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,126,0,0,
0,8,8,16,32,0,0,0,0,0,0,0,0,0,
0,0,0,0,56,68,64,120,68,68,120,0,0,0,
0,0,4,4,52,76,68,68,68,76,52,0,0,0,
0,0,0,0,56,68,4,4,4,68,56,0,0,0,
0,0,64,64,88,100,68,68,68,100,88,0,0,0,
0,0,0,0,56,68,68,124,4,68,56,0,0,0,
0,0,96,16,16,124,16,16,16,16,16,0,0,0,
0,0,0,0,88,100,68,68,68,100,88,64,68,56,
0,0,4,4,52,76,68,68,68,68,68,0,0,0,
0,0,32,0,56,32,32,32,32,32,32,0,0,0,
0,0,32,0,56,32,32,32,32,32,32,32,36,24,
0,0,4,4,36,20,12,12,20,36,68,0,0,0,
0,0,56,32,32,32,32,32,32,32,32,0,0,0,
0,0,0,0,44,84,84,84,84,84,84,0,0,0,
0,0,0,0,52,76,68,68,68,68,68,0,0,0,
0,0,0,0,56,68,68,68,68,68,56,0,0,0,
0,0,0,0,52,76,68,68,68,76,52,4,4,4,
0,0,0,0,88,100,68,68,68,100,88,64,64,64,
0,0,0,0,52,76,4,4,4,4,4,0,0,0,
0,0,0,0,56,68,4,56,64,68,56,0,0,0,
0,0,16,16,124,16,16,16,16,16,96,0,0,0,
0,0,0,0,68,68,68,68,68,100,88,0,0,0,
0,0,0,0,68,68,68,40,40,16,16,0,0,0,
0,0,0,0,68,68,84,84,84,84,40,0,0,0,
0,0,0,0,68,68,40,16,40,68,68,0,0,0,
0,0,0,0,68,68,72,72,80,48,32,32,36,24,
0,0,0,0,124,64,32,16,8,4,124,0,0,0,
96,16,16,16,16,16,12,16,16,16,16,16,96,0,
0,16,16,16,16,16,16,16,16,16,16,16,16,0,
12,16,16,16,16,16,96,16,16,16,16,16,12,0,
0,0,72,84,36,0,0,0,0,0,0,0,0,0,
0,0,0,0,16,56,108,68,68,124,0,0,0,0
};

const unsigned short g_packedFont1[1792] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,56,68,170,130,198,186,68,56,0,0,0,0,
0,0,56,124,214,254,186,198,124,56,0,0,0,0,
0,0,108,254,254,254,124,56,56,16,16,0,0,0,
0,0,16,56,124,254,254,124,56,16,0,0,0,0,
0,16,56,56,124,254,254,108,16,124,0,0,0,0,
0,16,56,124,254,254,254,108,16,124,0,0,0,0,
0,0,0,16,56,124,56,16,0,0,0,0,0,0,
0,254,254,238,198,130,198,238,254,254,0,0,0,0,
0,0,0,56,68,68,68,56,0,0,0,0,0,0,
0,254,254,198,186,186,186,198,254,254,0,0,0,0,
0,224,192,160,28,34,34,34,28,0,0,0,0,0,
0,56,68,68,68,56,16,124,16,16,0,0,0,0,
0,24,24,40,104,72,72,46,6,0,0,0,0,0,
0,224,184,136,136,136,136,102,102,0,0,0,0,0,
0,16,84,56,68,198,68,56,84,16,0,0,0,0,
0,0,0,4,12,28,60,28,12,4,0,0,0,0,
0,0,0,64,96,112,120,112,96,64,0,0,0,0,
0,16,56,84,16,16,16,84,56,16,0,0,0,0,
36,36,36,36,36,36,0,0,36,36,0,0,0,0,
60,42,42,42,60,40,40,40,40,40,40,0,0,0,
56,68,4,24,36,72,48,64,68,56,0,0,0,0,
0,0,0,0,0,254,254,254,254,254,0,0,0,0,
16,56,84,16,16,84,56,16,0,124,0,0,0,0,
0,16,56,84,16,16,16,16,16,16,16,0,0,0,
0,16,16,16,16,16,16,16,84,56,16,0,0,0,
0,0,0,0,16,32,126,32,16,0,0,0,0,0,
0,0,0,0,8,4,126,4,8,0,0,0,0,0,
0,0,0,0,0,12,12,12,12,124,0,0,0,0,
0,0,0,0,40,68,254,68,40,0,0,0,0,0,
0,0,0,0,16,56,124,254,0,0,0,0,0,0,
0,0,0,0,254,124,56,16,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,48,48,48,48,48,48,48,0,48,48,0,0,0,
0,108,108,108,108,0,0,0,0,0,0,0,0,0,
0,108,108,108,254,108,108,254,108,108,108,0,0,0,
0,16,124,86,22,22,124,208,208,212,124,16,0,0,
0,204,218,122,108,48,48,216,376,364,204,0,0,0,
0,56,108,108,56,24,220,118,54,254,220,0,0,0,
0,48,48,24,12,0,0,0,0,0,0,0,0,0,
0,48,24,24,12,12,12,12,12,24,24,48,0,0,
0,24,48,48,96,96,96,96,96,48,48,24,0,0,
0,0,16,84,56,56,84,16,0,0,0,0,0,0,
0,0,0,0,48,48,252,252,48,48,0,0,0,0,
0,0,0,0,0,0,0,0,56,56,56,32,24,0,
0,0,0,0,0,0,124,124,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,56,56,56,0,0,0,
0,192,192,96,96,48,48,24,24,12,12,0,0,0,
0,0,120,204,204,236,252,220,204,204,120,0,0,0,
0,0,48,56,60,48,48,48,48,48,252,0,0,0,
0,0,120,204,204,192,96,48,24,12,252,0,0,0,
0,0,120,204,204,192,112,192,204,204,120,0,0,0,
0,0,192,224,240,216,204,204,508,192,192,0,0,0,
0,0,252,12,12,124,192,192,204,204,120,0,0,0,
0,0,120,204,204,12,124,204,204,204,120,0,0,0,
0,0,252,204,204,96,96,96,48,48,48,0,0,0,
0,0,120,204,204,204,120,204,204,204,120,0,0,0,
0,0,120,204,204,204,248,192,204,204,120,0,0,0,
0,0,0,56,56,56,0,0,56,56,56,0,0,0,
0,0,0,56,56,56,0,0,56,56,56,32,24,0,
0,0,96,48,24,12,6,12,24,48,96,0,0,0,
0,0,0,0,0,124,124,0,124,124,0,0,0,0,
0,0,12,24,48,96,192,96,48,24,12,0,0,0,
0,120,204,204,192,96,48,48,0,48,48,0,0,0,
0,0,120,204,236,172,172,172,236,12,120,0,0,0,
0,0,48,48,120,120,72,204,252,204,204,0,0,0,
0,0,60,108,108,108,124,204,204,204,124,0,0,0,
0,0,120,204,204,12,12,12,204,204,120,0,0,0,
0,0,60,108,204,204,204,204,204,108,60,0,0,0,
0,0,124,12,12,12,60,12,12,12,124,0,0,0,
0,0,124,12,12,12,60,12,12,12,12,0,0,0,
0,0,120,204,204,12,236,204,204,204,248,0,0,0,
0,0,204,204,204,204,252,204,204,204,204,0,0,0,
0,0,60,24,24,24,24,24,24,24,60,0,0,0,
0,0,120,96,96,96,96,96,108,108,56,0,0,0,
0,0,204,236,124,60,60,108,108,204,204,0,0,0,
0,0,12,12,12,12,12,12,12,12,124,0,0,0,
0,0,198,238,254,254,254,214,198,198,198,0,0,0,
0,0,204,204,220,220,252,236,236,204,204,0,0,0,
0,0,120,204,204,204,204,204,204,204,120,0,0,0,
0,0,124,204,204,204,124,12,12,12,12,0,0,0,
0,0,120,204,204,204,204,204,204,204,120,48,224,0,
0,0,124,204,204,204,124,108,204,204,204,0,0,0,
0,0,120,204,204,12,120,192,204,204,120,0,0,0,
0,0,252,48,48,48,48,48,48,48,48,0,0,0,
0,0,204,204,204,204,204,204,204,204,120,0,0,0,
0,0,204,204,204,120,120,120,48,48,48,0,0,0,
0,0,198,198,198,214,254,254,254,238,198,0,0,0,
0,0,198,198,108,124,56,124,108,198,198,0,0,0,
0,0,204,204,204,120,48,48,48,48,48,0,0,0,
0,0,252,192,192,96,48,24,12,12,252,0,0,0,
0,120,24,24,24,24,24,24,24,24,24,120,0,0,
0,12,12,24,24,48,48,96,96,192,192,0,0,0,
0,60,48,48,48,48,48,48,48,48,48,60,0,0,
0,0,16,56,108,68,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,254,254,0,0,
0,24,24,48,96,0,0,0,0,0,0,0,0,0,
0,0,0,0,124,204,192,248,204,204,248,0,0,0,
0,0,12,12,124,204,204,204,204,204,124,0,0,0,
0,0,0,0,120,204,204,12,204,204,120,0,0,0,
0,0,192,192,248,204,204,204,204,204,248,0,0,0,
0,0,0,0,120,204,204,252,12,204,120,0,0,0,
0,0,112,24,24,124,24,24,24,24,24,0,0,0,
0,0,0,0,120,108,108,108,108,108,120,96,108,56,
0,0,12,12,124,204,204,204,204,204,204,0,0,0,
0,48,48,0,56,48,48,48,48,48,48,0,0,0,
0,96,96,0,120,96,96,96,96,96,96,108,108,56,
0,0,12,12,108,108,60,28,60,108,108,0,0,0,
0,0,56,48,48,48,48,48,48,48,48,0,0,0,
0,0,0,0,102,238,254,214,198,198,198,0,0,0,
0,0,0,0,54,126,110,102,102,102,102,0,0,0,
0,0,0,0,120,204,204,204,204,204,120,0,0,0,
0,0,0,0,124,204,204,204,204,204,124,12,12,12,
0,0,0,0,248,204,204,204,204,204,248,192,192,192,
0,0,0,0,60,108,108,12,12,12,12,0,0,0,
0,0,0,0,120,204,12,120,192,204,120,0,0,0,
0,0,24,24,124,24,24,24,24,24,112,0,0,0,
0,0,0,0,204,204,204,204,204,252,120,0,0,0,
0,0,0,0,204,204,204,120,120,48,48,0,0,0,
0,0,0,0,198,198,198,214,254,238,102,0,0,0,
0,0,0,0,198,198,108,56,108,198,198,0,0,0,
0,0,0,0,198,198,204,204,216,120,48,48,54,30,
0,0,0,0,252,192,96,48,24,12,252,0,0,0,
96,48,48,48,48,56,28,56,48,48,48,48,96,0,
0,48,48,48,48,48,48,48,48,48,48,48,48,0,
12,24,24,24,24,56,112,56,24,24,24,24,12,0,
0,0,216,252,108,0,0,0,0,0,0,0,0,0,
0,0,0,0,48,120,204,204,204,252,0,0,0,0
};

const unsigned short g_packedFont2[1792] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,56,68,170,130,198,186,68,56,0,0,0,0,
0,0,56,124,214,254,186,198,124,56,0,0,0,0,
0,0,108,254,254,254,124,56,56,16,16,0,0,0,
0,0,16,56,124,254,254,124,56,16,0,0,0,0,
0,16,56,56,124,254,254,108,16,124,0,0,0,0,
0,16,56,124,254,254,254,108,16,124,0,0,0,0,
0,0,0,16,56,124,56,16,0,0,0,0,0,0,
0,254,254,238,198,130,198,238,254,254,0,0,0,0,
0,0,0,56,68,68,68,56,0,0,0,0,0,0,
0,254,254,198,186,186,186,198,254,254,0,0,0,0,
0,224,192,160,28,34,34,34,28,0,0,0,0,0,
0,56,68,68,68,56,16,124,16,16,0,0,0,0,
0,24,24,40,104,72,72,46,6,0,0,0,0,0,
0,224,184,136,136,136,136,102,102,0,0,0,0,0,
0,16,84,56,68,198,68,56,84,16,0,0,0,0,
0,0,0,4,12,28,60,28,12,4,0,0,0,0,
0,0,0,64,96,112,120,112,96,64,0,0,0,0,
0,16,56,84,16,16,16,84,56,16,0,0,0,0,
36,36,36,36,36,36,0,0,36,36,0,0,0,0,
60,42,42,42,60,40,40,40,40,40,40,0,0,0,
56,68,4,24,36,72,48,64,68,56,0,0,0,0,
0,0,0,0,0,254,254,254,254,254,0,0,0,0,
16,56,84,16,16,84,56,16,0,124,0,0,0,0,
0,16,56,84,16,16,16,16,16,16,16,0,0,0,
0,16,16,16,16,16,16,16,84,56,16,0,0,0,
0,0,0,0,16,32,126,32,16,0,0,0,0,0,
0,0,0,0,8,4,126,4,8,0,0,0,0,0,
0,0,0,0,0,12,12,12,12,124,0,0,0,0,
0,0,0,0,40,68,254,68,40,0,0,0,0,0,
0,0,0,0,16,56,124,254,0,0,0,0,0,0,
0,0,0,0,254,124,56,16,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,8,8,8,8,0,8,0,0,0,0,0,0,0,
0,20,20,0,0,0,0,0,0,0,0,0,0,0,
0,20,62,20,20,62,20,0,0,0,0,0,0,0,
0,8,60,10,28,40,30,8,0,0,0,0,0,0,
0,12,12,0,30,0,12,12,0,0,0,0,0,0,
0,8,20,84,56,36,36,88,0,0,0,0,0,0,
0,8,8,0,0,0,0,0,0,0,0,0,0,0,
0,16,8,8,8,8,8,16,0,0,0,0,0,0,
0,16,32,32,32,32,32,16,0,0,0,0,0,0,
0,0,20,8,20,0,0,0,0,0,0,0,0,0,
0,0,8,28,8,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,16,16,0,0,0,0,0,0,
0,0,0,28,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,16,0,0,0,0,0,0,0,
0,0,32,32,16,16,8,8,0,0,0,0,0,0,
0,0,24,36,52,44,36,24,0,0,0,0,0,0,
0,0,16,24,20,16,16,60,0,0,0,0,0,0,
0,0,24,36,32,16,8,60,0,0,0,0,0,0,
0,0,24,36,16,32,36,24,0,0,0,0,0,0,
0,0,24,20,20,60,16,16,0,0,0,0,0,0,
0,0,60,4,28,32,36,24,0,0,0,0,0,0,
0,0,24,4,28,36,36,24,0,0,0,0,0,0,
0,0,60,32,16,16,8,8,0,0,0,0,0,0,
0,0,24,36,24,36,36,24,0,0,0,0,0,0,
0,0,24,36,36,56,32,24,0,0,0,0,0,0,
0,0,0,16,0,0,16,0,0,0,0,0,0,0,
0,0,0,16,0,0,16,24,0,0,0,0,0,0,
0,0,8,4,2,4,8,0,0,0,0,0,0,0,
0,0,0,30,0,30,0,0,0,0,0,0,0,0,
0,0,16,32,64,32,16,0,0,0,0,0,0,0,
0,24,36,32,24,8,0,8,0,0,0,0,0,0,
0,0,24,36,52,52,4,56,0,0,0,0,0,0,
0,0,24,36,60,36,36,36,0,0,0,0,0,0,
0,0,28,36,28,36,36,28,0,0,0,0,0,0,
0,0,24,36,4,4,36,24,0,0,0,0,0,0,
0,0,28,36,36,36,36,28,0,0,0,0,0,0,
0,0,60,4,28,4,4,60,0,0,0,0,0,0,
0,0,60,4,28,4,4,4,0,0,0,0,0,0,
0,0,24,36,4,52,36,24,0,0,0,0,0,0,
0,0,36,36,60,36,36,36,0,0,0,0,0,0,
0,0,28,8,8,8,8,28,0,0,0,0,0,0,
0,0,32,32,32,32,36,24,0,0,0,0,0,0,
0,0,36,36,20,12,20,36,0,0,0,0,0,0,
0,0,4,4,4,4,4,60,0,0,0,0,0,0,
0,0,44,84,84,84,68,68,0,0,0,0,0,0,
0,0,76,76,84,84,100,100,0,0,0,0,0,0,
0,0,24,36,36,36,36,24,0,0,0,0,0,0,
0,0,28,36,28,4,4,4,0,0,0,0,0,0,
0,0,28,36,36,36,56,16,8,0,0,0,0,0,
0,0,28,36,28,36,36,36,0,0,0,0,0,0,
0,0,56,4,24,32,32,28,0,0,0,0,0,0,
0,0,28,8,8,8,8,8,0,0,0,0,0,0,
0,0,36,36,36,36,36,24,0,0,0,0,0,0,
0,0,36,36,36,60,24,24,0,0,0,0,0,0,
0,0,34,34,42,42,20,20,0,0,0,0,0,0,
0,0,68,40,16,16,40,68,0,0,0,0,0,0,
0,0,20,20,20,8,8,8,0,0,0,0,0,0,
0,0,60,32,16,8,4,60,0,0,0,0,0,0,
0,56,8,8,8,8,8,56,0,0,0,0,0,0,
0,0,4,4,8,8,16,16,0,0,0,0,0,0,
0,56,32,32,32,32,32,56,0,0,0,0,0,0,
0,0,16,40,68,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,124,0,0,0,0,0,0,
0,8,8,16,0,0,0,0,0,0,0,0,0,0,
0,0,0,24,32,56,36,56,0,0,0,0,0,0,
0,0,4,4,4,28,36,28,0,0,0,0,0,0,
0,0,0,24,36,4,36,24,0,0,0,0,0,0,
0,0,32,32,32,56,36,56,0,0,0,0,0,0,
0,0,0,24,36,60,4,56,0,0,0,0,0,0,
0,0,24,4,12,4,4,4,0,0,0,0,0,0,
0,0,0,24,36,36,56,32,28,0,0,0,0,0,
0,0,4,4,4,28,36,36,0,0,0,0,0,0,
0,0,4,0,4,4,4,4,0,0,0,0,0,0,
0,0,8,0,8,8,8,4,0,0,0,0,0,0,
0,0,36,36,20,12,20,36,0,0,0,0,0,0,
0,0,8,8,8,8,8,8,0,0,0,0,0,0,
0,0,0,22,42,42,42,42,0,0,0,0,0,0,
0,0,0,28,36,36,36,36,0,0,0,0,0,0,
0,0,0,24,36,36,36,24,0,0,0,0,0,0,
0,0,0,28,36,36,28,4,4,0,0,0,0,0,
0,0,0,28,36,36,56,16,8,0,0,0,0,0,
0,0,0,24,4,4,4,4,0,0,0,0,0,0,
0,0,0,56,4,24,32,28,0,0,0,0,0,0,
0,0,8,28,8,8,8,8,0,0,0,0,0,0,
0,0,0,36,36,36,36,24,0,0,0,0,0,0,
0,0,0,36,36,36,24,24,0,0,0,0,0,0,
0,0,0,42,42,42,42,20,0,0,0,0,0,0,
0,0,0,68,40,16,40,68,0,0,0,0,0,0,
0,0,0,36,36,56,32,24,0,0,0,0,0,0,
0,0,0,60,32,24,4,60,0,0,0,0,0,0,
0,16,8,8,4,8,8,16,0,0,0,0,0,0,
0,8,8,8,8,8,8,8,0,0,0,0,0,0,
0,8,16,16,32,16,16,8,0,0,0,0,0,0,
0,0,36,42,18,0,0,0,0,0,0,0,0,0,
0,0,0,0,16,56,108,68,68,124,0,0,0,0
};

/*=========================================================================*/
/* SYSTEM                                                                  */
/*=========================================================================*/

#ifdef UNICODE
#error "No unicode support -> go away!\n"
#endif

#ifdef _WIN32
#define SOY_WIN32
#define SOY_OS_NAME "Windows"
#endif
#ifdef __linux__
#define SOY_LINUX
#error "No linux support -> go away!"
#define SOY_OS_NAME "Linux"
#endif

/*=========================================================================*/
/* DEBUG                                                                   */
/*=========================================================================*/

/* NOTE: debug only! */
#define SOY_DEBUG
#define SOY_DEBUG_LOG
#define SOY_DEBUG_BOUNDS
/* NOTE: remove this for final build! */

#ifdef SOY_DEBUG_LOG

/* logging */
#define SOY_DEBUG_OUTPUT

#define SOY_DEBUG_PREFIX
#define SOY_DEBUG_COLOUR

#endif

#if 0
#define SOY_ENABLE_RW_BARRIERS /* enables read write barriers */
#endif

#define SOY_LEGACY_AUDIO /* dsound or wasapi on win32 */

/*=========================================================================*/
/* CORE INCLUDES                                                           */
/*=========================================================================*/

/*
* o-------------------------------------------o
* | @standard library for C89                 |
* o-------------------------------------------o
*/

#ifndef SOY_NO_C_STD
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>		/* input and output 				*/
#include <ctype.h>		/* character class tests 			*/
#include <string.h>		/* string functions 				*/
#include <math.h>		/* mathematical functions 			*/
#include <stdlib.h>		/* utility functions 				*/
#include <assert.h>		/* diagnostics 						*/
#include <stdarg.h>		/* variable argument lists 			*/
#include <setjmp.h>		/* non-local jumps 					*/
#include <signal.h>		/* signals 							*/
#include <time.h>		/* date and time functions 			*/
#include <limits.h>		/* implementation-defined limits 	*/
#include <float.h>      /* implementation-defined limits 	*/
#include <errno.h>
#endif /* SOY_NO_C_STD */

/*
* o-------------------------------------------o
* | @platform specific libraries              |
* o-------------------------------------------o
*/

#ifdef SOY_WIN32
#define CINTERFACE
#define WIN32_LEAN_AND_MEAN
#ifndef SOY_NO_WINDOWS
#include <windows.h>
#endif /* SOY_NO_WINDOWS */
#ifndef SOY_NO_WINDOWS_EXT
#include <windowsx.h>
#include <winsock.h>
#include <mmsystem.h>
#include <intrin.h>
#include <mmintrin.h>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <dsound.h>
#include <initguid.h>
#include <audioclient.h>
#include <mmdeviceapi.h>
#include <combaseapi.h>
#endif /* SOY_NO_WINDOWS_EXT */
#endif /* SOY_WIN32 */

/*=========================================================================*/
/* CORE DEFINES                                                            */
/*=========================================================================*/

#ifdef SOY_WIN32
typedef __int8 int8;
typedef __int16 int16;
typedef __int32 int32;
typedef __int64 int64;
typedef UINT8 uint8;
typedef UINT16 uint16;
typedef UINT32 uint32;
typedef UINT64 uint64;
#endif /* SOY_WIN32 */

#ifdef SOY_LINUX
typedef char int8;
typedef short int16;
typedef long int32;
typedef long long int64;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
#endif /* SOY_LINUX */

typedef double real64;
typedef float real32;

#undef TRUE
#define TRUE 1
#undef FALSE
#define FALSE 0

#ifdef SOY_WIN32
#ifdef SOY_ENABLE_RW_BARRIERS
#define SOY_WRITE_BARRIER _WriteBarrier()
#define SOY_READ_BARRIER _ReadBarrier()
#define SOY_READ_WRITE_BARRIER _ReadWriteBarrier()
#else
#define SOY_WRITE_BARRIER
#define SOY_READ_BARRIER
#define SOY_READ_WRITE_BARRIER
#endif /* SOY_ENABLE_RW_BARRIERS */

#ifndef SOY_NO_WINDOWS_EXT /* intrinsics */
#define int32x4 __m128i
#define real32x4 __m128
#define SOY_MM_zeroReal32x4 _mm_setzero_ps
#define SOY_MM_zeroInt32x4 _mm_setzero_si128
#define SOY_MM_real32x4Broad _mm_set_ps1
#define SOY_MM_int32x4Broad _mm_set1_epi32
#define SOY_MM_real32x4 _mm_set_ps
#define SOY_MM_int32x4 _mm_set_epi32
#define SOY_MM_addReal32x4 _mm_add_ps
#define SOY_MM_addInt32x4 _mm_add_epi32
#define SOY_MM_subReal32x4 _mm_sub_ps
#define SOY_MM_subInt32x4 _mm_sub_epi32
#define SOY_MM_mulReal32x4 _mm_mul_ps
#define SOY_MM_divReal32x4 _mm_div_ps
#define SOY_MM_mulInt32x4U _mm_mul_epu32
#define SOY_MM_sqrt32x4 _mm_sqrt_ps
#define SOY_MM_rsqrt32x4 _mm_rsqrt_ps
#define SOY_MM_rcp32x4 _mm_rcp_ps
#define SOY_MM_castToReal32x4 _mm_castsi128_ps
#define SOY_MM_castToInt32x4 _mm_castps_si128
#define SOY_MM_maxReal32x4 _mm_max_ps
#define SOY_MM_minReal32x4 _mm_min_ps
#define SOY_MM_shuffleReal32x4 _mm_shuffle_ps
#define SOY_MM_extractLow32x4 _mm_cvtss_f32
#endif /* SOY_NO_WINDOWS_EXT */
#endif /* SOY_WIN32 */

#define SOY_MAX_STRING 4096
#define SOY_MAX_KEYS 256
#define SOY_MAX_MOUSE_KEYS 8
#define SOY_MAX_THREADS 16
#define SOY_MAX_WORK_QUEUE_ITEMS 256
#define SOY_MAX_WORK_QUEUES 4

#define SOY_PI 3.141592653f
#define SOY_2PI 6.283185307f
#define SOY_EULER 2.71828f

#define SOY_GLOBAL static

#define SOY_UNUSED(x) (void)(x)

#define SOY_SWAP(x, y, temp) { temp = x; x = y; y = temp; }

#define SOY_BITSET(x, whence) ((x) |= (1<<(whence)))
#define SOY_BITCLEAR(x, whence) ((x) &= ~(1<<(whence)))
#define SOY_BITFLIP(x, whence) ((x) ^= (1<<(whence)))
#define SOY_BITCHECK(x, whence) ((x) & (1<<(whence)))

#define SOY_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define SOY_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define SOY_SQR(x) ((x)*(x))
#define SOY_CUB(x) ((x)*(x)*(x))
#define SOY_FASTFLOOR(x) (((x) > 0) ? (int64)(x) : (int64)(x) - 1)
#define SOY_SIGN(x) ((x) == 0 ? 0 : ((x) > 0 ? 1 : -1))

#define SOY_randInt(modulo) (rand()%modulo)

#define SOY_lerp(start, end, t) ((1.0f - (t)) * (start) + (t) * (end))

#define SOY_distance(x1, y1, x2, y2) \
  ((real32)sqrt(((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1))))

#define SOY_distance3D(x1, y1, z1, x2, y2, z2) \
  ((real32)sqrt( \
    ((x2)-(x1))*((x2)-(x1))+\
    ((y2)-(y1))*((y2)-(y1))+\
    ((z2)-(z1))*((z2)-(z1))))

real32 SOY_pow(real32 x, real32 expn) {
  return (real32)pow((real64)x, (real64)expn);
}

real32 SOY_exp(real32 x, int32 p) {
  real32 ret = x;
  while(p-- > 0) {
    ret*=x;
  }
  return ret;
}


#define SOY_ASSERT(x) if(!(x)) {             \
printf(                                   \
    "ABORTING PROGRAM - FATAL ERROR at: " \
    "%s, line: %d, time: %s [%s]\n"       \
  , __FILE__, (int32)__LINE__, __TIME__, #x);    \
exit(-1);                                 \
}

size_t Kilobytes(size_t size){  return 1024*(size_t)size; }
size_t Megabytes(size_t size){  return 1024*Kilobytes(size); }
size_t Gigabytes(size_t size){  return 1024*Megabytes(size); }
size_t Terabytes(size_t size){  return 1024*Gigabytes(size); }

typedef enum enum_soyKeyCode {
  SOY_LBUTTON = 0x01,   SOY_RBUTTON = 0x02,   SOY_CANCEL = 0x03,
  SOY_MBUTTON = 0x04,   SOY_XBUTTON1 = 0x05,  SOY_XBUTTON2 = 0x06,
  SOY_BACKSPACE = 0x08, SOY_TAB= 0x09,        SOY_CLEAR = 0x0C,
  SOY_RETURN = 0x0D,    SOY_SHIFT = 0x10,     SOY_CONTROL = 0x11,
  SOY_ALT = 0x12,       SOY_PAUSE = 0x13,     SOY_CAPS = 0x14,
  SOY_ESC = 0x1B,       SOY_SPACE = 0x20,     SOY_PGUP = 0x21,
  SOY_PGDOWN = 0x22,    SOY_END = 0x23,       SOY_HOME = 0x24,
  SOY_LEFT = 0x25,      SOY_UP = 0x26,        SOY_RIGHT = 0x27,
  SOY_DOWN = 0x28,      SOY_SELECT = 0x29,    SOY_PRINT = 0x2A,
  SOY_EXEC = 0x2B,      SOY_PRINTSCR = 0x2C,  SOY_INSERT = 0x2D,
  SOY_DELETE = 0x2E,    SOY_HELP = 0x2F,      SOY_0 = 0x30,
  SOY_1 = 0x31,         SOY_2 = 0x32,         SOY_3 = 0x33,
  SOY_4 = 0x34,         SOY_5 = 0x35,         SOY_6 = 0x36,
  SOY_7 = 0x37,         SOY_8 = 0x38,         SOY_9 = 0x39,
  SOY_A = 0x41,         SOY_B = 0x42,         SOY_C = 0x43,
  SOY_D = 0x44,         SOY_E = 0x45,         SOY_F = 0x46,
  SOY_G = 0x47,         SOY_H = 0x48,         SOY_I = 0x49,
  SOY_J = 0x4A,         SOY_K = 0x4B,         SOY_L = 0x4C,
  SOY_M = 0x4D,         SOY_N = 0x4E,         SOY_O = 0x4F,
  SOY_P = 0x50,         SOY_Q = 0x51,         SOY_R = 0x52,
  SOY_S = 0x53,         SOY_T = 0x54,         SOY_U = 0x55,
  SOY_V = 0x56,         SOY_W = 0x57,         SOY_X = 0x58,
  SOY_Y = 0x59,         SOY_Z = 0x5A,         SOY_LSUPER = 0x5B,
  SOY_RSUPER = 0x5C,    SOY_APPS = 0x5D,      SOY_SLEEP = 0x5F,
  SOY_NUMPAD0 = 0x60,   SOY_NUMPAD1 = 0x61,   SOY_NUMPAD2 = 0x62,
  SOY_NUMPAD3 = 0x63,   SOY_NUMPAD4 = 0x64,   SOY_NUMPAD5 = 0x65,
  SOY_NUMPAD6 = 0x66,   SOY_NUMPAD7 = 0x67,   SOY_NUMPAD8 = 0x68,
  SOY_NUMPAD9 = 0x69,   SOY_MULTIPLY = 0x6A,  SOY_ADD = 0x6B,
  SOY_SEPARATOR = 0x6C, SOY_SUBTRACT = 0x6D,  SOY_DECIMAL = 0x6E,
  SOY_DIVIDE = 0x6F,    SOY_F1 = 0x70,        SOY_F2 = 0x71,
  SOY_F3 = 0x72,        SOY_F4 = 0x73,        SOY_F5 = 0x74,
  SOY_F6 = 0x75,        SOY_F7 = 0x76,        SOY_F8 = 0x77,
  SOY_F9 = 0x78,        SOY_F10 = 0x79,       SOY_F11 = 0x7A,
  SOY_F12 = 0x7B,       SOY_F13 = 0x7C,       SOY_F14 = 0x7D,
  SOY_F15 = 0x7E,       SOY_F16 = 0x7F,       SOY_F17 = 0x80,
  SOY_F18 = 0x81,       SOY_F19 = 0x82,       SOY_F20 = 0x83,
  SOY_F21 = 0x84,       SOY_F22 = 0x85,       SOY_F23 = 0x86,
  SOY_F24 = 0x87,       SOY_NUMLOCK = 0x90,   SOY_SCRLOCK = 0x91,
  SOY_LSHIFT = 0xA0,    SOY_RSHIFT = 0xA1,    SOY_LCONTROL = 0xA2,
  SOY_RCONTROL = 0xA3,  SOY_LALT = 0xA4,      SOY_RALT = 0xA5,
  SOY_VOLMUTE = 0xAD,   SOY_VOLDOWN = 0xAE,   SOY_VOLUP = 0xAF,
  SOY_MEDIANEXT = 0xB0, SOY_MEDIAPREV = 0xB1, SOY_MEDIASTOP = 0xB2,
  SOY_MEDIAPLAY = 0xB4, SOY_OEM_1 = 0xBA,     SOY_OEM_PLUS = 0xBB,
  SOY_OEM_COMMA = 0xBC, SOY_OEM_MINUS = 0xBD, SOY_OEM_PERIOD = 0xBE,
  SOY_OEM_2 = 0xBF,     SOY_OEM_3 = 0xC0,     SOY_OEM_4 = 0xDB,
  SOY_OEM_5 = 0xDC,     SOY_OEM_6 = 0xDD,     SOY_OEM_7 = 0xDE,
  SOY_OEM_8 = 0xDF,     SOY_OEM_102 = 0xE2,   SOY_ANY = 0xFF
} soyKeyCode;

typedef enum enum_soyMouseCode {
  SOY_MOUSE_NONE,
  SOY_MOUSE_LEFT,
  SOY_MOUSE_MIDDLE,
  SOY_MOUSE_RIGHT,
  SOY_MOUSE_X1
} soyMouseCode;

int32 SOY_alphanumeric(uint32 key) {
  return ((key >= 0x30 && key <= 0x5A) ||
      key == SOY_OEM_PERIOD ||
      key == SOY_OEM_COMMA ||
      (key >= 0x60 && key <= 0x69)
      );
}

SOY_GLOBAL int32 SOY_MIN_WINDOW_X = 420;
SOY_GLOBAL int32 SOY_MIN_WINDOW_Y = 260;

int32 SOY_setWindowMin(int32 x, int32 y) {
  SOY_MIN_WINDOW_X = x;
  SOY_MIN_WINDOW_Y = x;
  return TRUE;
}


/*=========================================================================*/
/* LOGGING                                                                 */
/*=========================================================================*/

/* regular text */
#define SOY_CON_BLACK "\33[0;30m"
#define SOY_CON_RED "\33[0;31m"
#define SOY_CON_GREEN "\33[0;32m"
#define SOY_CON_YELLOW "\33[0;33m"
#define SOY_CON_BLUE "\33[0;34m"
#define SOY_CON_MAGENTA "\33[0;35m"
#define SOY_CON_CYAN "\33[0;36m"
#define SOY_CON_WHITE "\33[0;37m"

/* regular bold text */
#define SOY_CON_BBLACK "\33[1;30m"
#define SOY_CON_BRED "\33[1;31m"
#define SOY_CON_BGREEN "\33[1;32m"
#define SOY_CON_BYELLOW "\33[1;33m"
#define SOY_CON_BBLUE "\33[1;34m"
#define SOY_CON_BMAGENTA "\33[1;35m"
#define SOY_CON_BCYAN "\33[1;36m"
#define SOY_CON_BWHITE "\33[1;37m"

/* regular underline text */
#define SOY_CON_UBLACK "\33[4;30m"
#define SOY_CON_URED "\33[4;31m"
#define SOY_CON_UGREEN "\33[4;32m"
#define SOY_CON_UYELLOW "\33[4;33m"
#define SOY_CON_UBLUE "\33[4;34m"
#define SOY_CON_UMAGENTA "\33[4;35m"
#define SOY_CON_UCYAN "\33[4;36m"
#define SOY_CON_UWHITE "\33[4;37m"

/* regular high intensity text */
#define SOY_CON_HI_BLACK "\33[0;90m"
#define SOY_CON_HI_RED "\33[0;91m"
#define SOY_CON_HI_GREEN "\33[0;92m"
#define SOY_CON_HI_YELLOW "\33[0;93m"
#define SOY_CON_HI_BLUE "\33[0;94m"
#define SOY_CON_HI_MAGENTA "\33[0;95m"
#define SOY_CON_HI_CYAN "\33[0;96m"
#define SOY_CON_HI_WHITE "\33[0;97m"

/* regular high intensity bold text */
#define SOY_CON_HI_BBLACK "\33[1;90m"
#define SOY_CON_HI_BRED "\33[1;91m"
#define SOY_CON_HI_BGREEN "\33[1;92m"
#define SOY_CON_HI_BYELLOW "\33[1;93m"
#define SOY_CON_HI_BBLUE "\33[1;94m"
#define SOY_CON_HI_BMAGENTA "\33[1;95m"
#define SOY_CON_HI_BCYAN "\33[1;96m"
#define SOY_CON_HI_BWHITE "\33[1;97m"

/* colour reset */
#define SOY_CON_COLOUR_RESET "\33[0m"

#define SOY_CON_COL_A SOY_CON_CYAN
#define SOY_CON_COL_B SOY_CON_HI_CYAN
#define SOY_CON_COL_C SOY_CON_HI_WHITE
#define SOY_CON_COL_D SOY_CON_HI_RED

#ifdef SOY_DEBUG_OUTPUT
#ifdef SOY_DEBUG_PREFIX
#ifdef SOY_DEBUG_COLOUR
#define SOY_LOGPREFIX printf( \
    SOY_CON_COL_A "[SOY]" \
    SOY_CON_COL_B "[%s][%d]" \
    SOY_CON_COL_D " > " \
    SOY_CON_COLOUR_RESET, \
    __FILE__, (uint32)(__LINE__))
#else
#define SOY_LOGPREFIX printf("[SOY][%s][%d] > ", \
    __FILE__, (uint32)(__LINE__))
#endif /* SOY_DEBUG_COLOUR */
#else
#define SOY_LOGPREFIX while(0)
#endif /* SOY_DEBUG_PREFIX */

#ifdef SOY_DEBUG_COLOUR
#define SOY_LOGCOL(x) SOY_CON_COL_C x SOY_CON_COLOUR_RESET
#else
#define SOY_LOGCOL(x) x
#endif

#define SOY_LOG_ERROR() SOY_LOGPREFIX; \
  printf("Error: %s\n", strerror(errno));

#define SOY_LOG(x) SOY_LOGPREFIX;\
  printf(SOY_LOGCOL(x))
#define SOY_LOG1(x, a1) SOY_LOGPREFIX;\
  printf(SOY_LOGCOL(x), a1)
#define SOY_LOG2(x, a1, a2) SOY_LOGPREFIX;\
  printf(SOY_LOGCOL(x), a1, a2)
#define SOY_LOG3(x, a1, a2, a3) SOY_LOGPREFIX;\
  printf(SOY_LOGCOL(x), a1, a2, a3)
#define SOY_LOG4(x, a1, a2, a3, a4) SOY_LOGPREFIX;\
  printf(SOY_LOGCOL(x), a1, a2, a3, a4)
#define SOY_LOG5(x, a1, a2, a3, a4, a5) SOY_LOGPREFIX;\
  printf(SOY_LOGCOL(x), a1, a2, a3, a4, a5)
#define SOY_LOG6(x, a1, a2, a3, a4, a5, a6) SOY_LOGPREFIX;\
  printf(SOY_LOGCOL(x), a1, a2, a3, a4, a5, a6)
#define SOY_LOG7(x, a1, a2, a3, a4, a5, a6, a7) SOY_LOGPREFIX;\
  printf(SOY_LOGCOL(x), a1, a2, a3, a4, a5, a6, a7)
#define SOY_LOG8(x, a1, a2, a3, a4, a5, a6, a7, a8) SOY_LOGPREFIX;\
  printf(SOY_LOGCOL(x), a1, a2, a3, a4, a5, a6, a7, a8)
#define SOY_LOG9(x, a1, a2, a3, a4, a5, a6, a7, a8, a9) SOY_LOGPREFIX;\
  printf(SOY_LOGCOL(x), a1, a2, a3, a4, a5, a6, a7, a8, a9)
#define SOY_LOG10(x, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) SOY_LOGPREFIX;\
  printf(SOY_LOGCOL(x), a1, a2, a3, a4, a5, a6, a7, a8, a9, a10)
#else

#define SOY_LOG_ERROR() while(0) {}

#define ENDL while(0) {}
#define SOY_LOG(x) while(0) {}
#define SOY_LOG1(x, a1) while(0) {}
#define SOY_LOG2(x, a1, a2) while(0) {}
#define SOY_LOG3(x, a1, a2, a3) while(0) {}
#define SOY_LOG4(x, a1, a2, a3, a4) while(0) {}
#define SOY_LOG5(x, a1, a2, a3, a4, a5) while(0) {}
#define SOY_LOG6(x, a1, a2, a3, a4, a5, a6) while(0) {}
#define SOY_LOG7(x, a1, a2, a3, a4, a5, a6, a7) while(0) {}
#define SOY_LOG8(x, a1, a2, a3, a4, a5, a6, a7, a8) while(0) {}
#define SOY_LOG9(x, a1, a2, a3, a4, a5, a6, a7, a8, a9) while(0) {}
#define SOY_LOG10(x, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) while(0) {}
#endif /* SOY_DEBUG_OUTPUT */

/*=========================================================================*/
/* OPENGL LAYER                                                            */
/*=========================================================================*/

#ifndef SOY_NO_HARDWARE

/*
* o-------------------------------------------o
* | @openGL                                   |
* o-------------------------------------------o
*/

#ifndef SOY_OPENGL_H
#define SOY_OPENGL_H
#include <GL/gl.h>

#define WGL_DRAW_TO_WINDOW_ARB         	  0x2001
#define WGL_ACCELERATION_ARB              0x2003
#define WGL_SWAP_METHOD_ARB               0x2007
#define WGL_SUPPORT_OPENGL_ARB            0x2010
#define WGL_DOUBLE_BUFFER_ARB             0x2011
#define WGL_PIXEL_TYPE_ARB                0x2013
#define WGL_COLOR_BITS_ARB                0x2014
#define WGL_DEPTH_BITS_ARB                0x2022
#define WGL_STENCIL_BITS_ARB              0x2023
#define WGL_FULL_ACCELERATION_ARB         0x2027
#define WGL_SWAP_EXCHANGE_ARB          	  0x2028
#define WGL_TYPE_RGBA_ARB              	  0x202B
#define WGL_CONTEXT_DEBUG_BIT_ARB         0x00000001
#define WGL_CONTEXT_MAJOR_VERSION_ARB     0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB     0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB       0x2093
#define WGL_CONTEXT_FLAGS_ARB             0x2094
#define ERROR_INVALID_VERSION_ARB         0x2095
#define GL_ARRAY_BUFFER                   0x8892
#define GL_STATIC_DRAW                    0x88E4
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_TEXTURE0                       0x84C0
#define GL_BGRA                           0x80E1
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define WGL_CONTEXT_PROFILE_MASK_ARB      0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB  0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define WGL_NUMBER_PIXEL_FORMATS_ARB      0x2000
#define WGL_DRAW_TO_WINDOW_ARB            0x2001
#define WGL_DRAW_TO_BITMAP_ARB            0x2002
#define WGL_ACCELERATION_ARB              0x2003
#define WGL_NEED_PALETTE_ARB              0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB       0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB        0x2006
#define WGL_SWAP_METHOD_ARB               0x2007
#define WGL_NUMBER_OVERLAYS_ARB           0x2008
#define WGL_NUMBER_UNDERLAYS_ARB          0x2009
#define WGL_TRANSPARENT_ARB               0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB     0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB   0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB    0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB   0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB   0x203B
#define WGL_SHARE_DEPTH_ARB               0x200C
#define WGL_SHARE_STENCIL_ARB             0x200D
#define WGL_SHARE_ACCUM_ARB               0x200E
#define WGL_SUPPORT_GDI_ARB               0x200F
#define WGL_SUPPORT_OPENGL_ARB            0x2010
#define WGL_DOUBLE_BUFFER_ARB             0x2011
#define WGL_STEREO_ARB                    0x2012
#define WGL_PIXEL_TYPE_ARB                0x2013
#define WGL_COLOR_BITS_ARB                0x2014
#define WGL_RED_BITS_ARB                  0x2015
#define WGL_RED_SHIFT_ARB                 0x2016
#define WGL_GREEN_BITS_ARB                0x2017
#define WGL_GREEN_SHIFT_ARB               0x2018
#define WGL_BLUE_BITS_ARB                 0x2019
#define WGL_BLUE_SHIFT_ARB                0x201A
#define WGL_ALPHA_BITS_ARB                0x201B
#define WGL_ALPHA_SHIFT_ARB               0x201C
#define WGL_ACCUM_BITS_ARB                0x201D
#define WGL_ACCUM_RED_BITS_ARB            0x201E
#define WGL_ACCUM_GREEN_BITS_ARB          0x201F
#define WGL_ACCUM_BLUE_BITS_ARB           0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB          0x2021
#define WGL_DEPTH_BITS_ARB                0x2022
#define WGL_STENCIL_BITS_ARB              0x2023
#define WGL_AUX_BUFFERS_ARB               0x2024
#define WGL_NO_ACCELERATION_ARB           0x2025
#define WGL_GENERIC_ACCELERATION_ARB      0x2026
#define WGL_FULL_ACCELERATION_ARB         0x2027
#define WGL_SWAP_EXCHANGE_ARB             0x2028
#define WGL_SWAP_COPY_ARB                 0x2029
#define WGL_SWAP_UNDEFINED_ARB            0x202A
#define WGL_TYPE_RGBA_ARB                 0x202B
#define WGL_TYPE_COLORINDEX_ARB           0x202C
#define GL_MULTISAMPLE                    0x809D
#define WGL_SAMPLES_ARB                   0x2042

typedef BOOL (WINAPI * PFNWGLCHOOSEPIXELFORMATARBPROC)
  (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList,
   UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
typedef HGLRC (WINAPI * PFNWGLCREATECONTEXTATTRIBSARBPROC)
  (HDC hDC, HGLRC hShareContext, const int *attribList);
typedef BOOL (WINAPI * PFNWGLSWAPINTERVALEXTPROC)
  (int interval);
typedef void (APIENTRY * PFNGLATTACHSHADERPROC)
  (GLuint program, GLuint shader);
typedef void (APIENTRY * PFNGLBINDBUFFERPROC)
  (GLenum target, GLuint buffer);
typedef void (APIENTRY * PFNGLBINDVERTEXARRAYPROC)
  (GLuint array);
typedef void (APIENTRY * PFNGLBUFFERDATAPROC)
  (GLenum target, ptrdiff_t size, const GLvoid *data, GLenum usage);
typedef void (APIENTRY * PFNGLCOMPILESHADERPROC)
  (GLuint shader);
typedef GLuint (APIENTRY * PFNGLCREATEPROGRAMPROC)
  (void);
typedef GLuint (APIENTRY * PFNGLCREATESHADERPROC)
  (GLenum type);
typedef void (APIENTRY * PFNGLDELETEBUFFERSPROC)
  (GLsizei n, const GLuint *buffers);
typedef void (APIENTRY * PFNGLDELETEPROGRAMPROC)
  (GLuint program);
typedef void (APIENTRY * PFNGLDELETESHADERPROC)
  (GLuint shader);
typedef void (APIENTRY * PFNGLDELETEVERTEXARRAYSPROC)
  (GLsizei n, const GLuint *arrays);
typedef void (APIENTRY * PFNGLDETACHSHADERPROC)
  (GLuint program, GLuint shader);
typedef void (APIENTRY * PFNGLENABLEVERTEXATTRIBARRAYPROC)
  (GLuint index);
typedef void (APIENTRY * PFNGLGENBUFFERSPROC)
  (GLsizei n, GLuint *buffers);
typedef void (APIENTRY * PFNGLGENVERTEXARRAYSPROC)
  (GLsizei n, GLuint *arrays);
typedef GLint (APIENTRY * PFNGLGETATTRIBLOCATIONPROC)
  (GLuint program, const char *name);
typedef void (APIENTRY * PFNGLGETPROGRAMINFOLOGPROC)
  (GLuint program, GLsizei bufSize, GLsizei *length, char *infoLog);
typedef void (APIENTRY * PFNGLGETPROGRAMIVPROC)
  (GLuint program, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLGETSHADERINFOLOGPROC)
  (GLuint shader, GLsizei bufSize, GLsizei *length, char *infoLog);
typedef void (APIENTRY * PFNGLGETSHADERIVPROC)
  (GLuint shader, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNGLLINKPROGRAMPROC)
  (GLuint program);
typedef void (APIENTRY * PFNGLSHADERSOURCEPROC)
  (GLuint shader, GLsizei count, const char* *string, const GLint *length);
typedef void (APIENTRY * PFNGLUSEPROGRAMPROC)
  (GLuint program);
typedef void (APIENTRY * PFNGLVERTEXATTRIBPOINTERPROC)
  (GLuint index, GLint size, GLenum type, GLboolean normalized,
   GLsizei stride, const GLvoid *pointer);
typedef void (APIENTRY * PFNGLVERTEXATTRIBIPOINTERPROC)
  (GLuint index, GLint size, GLenum type,
   GLsizei stride, const GLvoid *pointer);
typedef void (APIENTRY * PFNGLBINDATTRIBLOCATIONPROC)
  (GLuint program, GLuint index, const char *name);
typedef GLint (APIENTRY * PFNGLGETUNIFORMLOCATIONPROC)
  (GLuint program, const char *name);
typedef void (APIENTRY * PFNGLUNIFORMMATRIX4FVPROC)
  (GLint location, GLsizei count,
   GLboolean transpose, const GLfloat *value);
typedef void (APIENTRY * PFNGLACTIVETEXTUREPROC)
  (GLenum texture);
typedef void (APIENTRY * PFNGLUNIFORM1IPROC)
  (GLint location, GLint v0);
typedef void (APIENTRY * PFNGLGENERATEMIPMAPPROC)
  (GLenum target);
typedef void (APIENTRY * PFNGLDISABLEVERTEXATTRIBARRAYPROC)
  (GLuint index);
typedef void (APIENTRY * PFNGLUNIFORM1FPROC)
  (GLint location, const GLfloat);
typedef void (APIENTRY * PFNGLUNIFORM2FPROC)
  (GLint location, const GLfloat);
typedef void (APIENTRY * PFNGLUNIFORM3FVPROC)
  (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRY * PFNGLUNIFORM4FVPROC)
  (GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRY * PFNGLDRAWARRAYSINSTANCEDPROC)
  (GLenum mode, GLint first, GLsizei count, GLsizei amt);
typedef void(APIENTRY * PFNVERTEXATTRIBDIVISORPROC)
  (GLuint index, GLuint divisor);
typedef void(APIENTRY * PFNDRAWELEMENTSINSTANCEDPROC)
  (GLenum mode, GLsizei count, GLenum type,
   const void* indices, GLsizei instanceCount);

PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
PFNGLATTACHSHADERPROC glAttachShader;
PFNGLBINDBUFFERPROC glBindBuffer;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLCOMPILESHADERPROC glCompileShader;
PFNGLCREATEPROGRAMPROC glCreateProgram;
PFNGLCREATESHADERPROC glCreateShader;
PFNGLDELETEBUFFERSPROC glDeleteBuffers;
PFNGLDELETEPROGRAMPROC glDeleteProgram;
PFNGLDELETESHADERPROC glDeleteShader;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
PFNGLDETACHSHADERPROC glDetachShader;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
PFNGLGENBUFFERSPROC glGenBuffers;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
PFNGLGETPROGRAMIVPROC glGetProgramiv;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
PFNGLGETSHADERIVPROC glGetShaderiv;
PFNGLLINKPROGRAMPROC glLinkProgram;
PFNGLSHADERSOURCEPROC glShaderSource;
PFNGLUSEPROGRAMPROC glUseProgram;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
PFNGLACTIVETEXTUREPROC glActiveTexture;
PFNGLUNIFORM1IPROC glUniform1i;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
PFNGLUNIFORM1FPROC glUniform1f;
PFNGLUNIFORM2FPROC glUniform2f;
PFNGLUNIFORM3FVPROC glUniform3fv;
PFNGLUNIFORM4FVPROC glUniform4fv;
PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
PFNVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
PFNDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;

SOY_GLOBAL uint32 g_soyGLError = 0;

#define GLCHECK() { \
  g_soyGLError = glGetError(); \
  if(g_soyGLError) { \
    printf("OPENGL ERROR: %s %d %d\n", __FILE__, \
        (int32)__LINE__, g_soyGLError);}}

#ifdef SOY_WIN32
int SOY_glLoadExtensionList(void) {
	wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)
      wglGetProcAddress("wglChoosePixelFormatARB");
	wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)
      wglGetProcAddress("wglCreateContextAttribsARB");
	wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)
      wglGetProcAddress("wglSwapIntervalEXT");
	glAttachShader = (PFNGLATTACHSHADERPROC)
      wglGetProcAddress("glAttachShader");
	glBindBuffer = (PFNGLBINDBUFFERPROC)
      wglGetProcAddress("glBindBuffer");
	glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)
      wglGetProcAddress("glBindVertexArray");
	glBufferData = (PFNGLBUFFERDATAPROC)
      wglGetProcAddress("glBufferData");
	glCompileShader = (PFNGLCOMPILESHADERPROC)
      wglGetProcAddress("glCompileShader");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)
      wglGetProcAddress("glCreateProgram");
	glCreateShader = (PFNGLCREATESHADERPROC)
      wglGetProcAddress("glCreateShader");
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)
      wglGetProcAddress("glDeleteBuffers");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)
      wglGetProcAddress("glDeleteProgram");
	glDeleteShader = (PFNGLDELETESHADERPROC)
      wglGetProcAddress("glDeleteShader");
	glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)
      wglGetProcAddress("glDeleteVertexArrays");
	glDetachShader = (PFNGLDETACHSHADERPROC)
      wglGetProcAddress("glDetachShader");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)
      wglGetProcAddress("glEnableVertexAttribArray");
	glGenBuffers = (PFNGLGENBUFFERSPROC)
      wglGetProcAddress("glGenBuffers");
	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)
      wglGetProcAddress("glGenVertexArrays");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)
      wglGetProcAddress("glGetAttribLocation");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)
      wglGetProcAddress("glGetProgramInfoLog");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)
      wglGetProcAddress("glGetProgramiv");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)
      wglGetProcAddress("glGetShaderInfoLog");
	glGetShaderiv = (PFNGLGETSHADERIVPROC)
      wglGetProcAddress("glGetShaderiv");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)
      wglGetProcAddress("glLinkProgram");
	glShaderSource = (PFNGLSHADERSOURCEPROC)
      wglGetProcAddress("glShaderSource");
	glUseProgram = (PFNGLUSEPROGRAMPROC)
      wglGetProcAddress("glUseProgram");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)
      wglGetProcAddress("glVertexAttribPointer");
  	glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)
      wglGetProcAddress("glVertexAttribIPointer");
    glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)
      wglGetProcAddress("glBindAttribLocation");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)
      wglGetProcAddress("glGetUniformLocation");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)
      wglGetProcAddress("glUniformMatrix4fv");
	glActiveTexture = (PFNGLACTIVETEXTUREPROC)
      wglGetProcAddress("glActiveTexture");
	glUniform1i = (PFNGLUNIFORM1IPROC)
      wglGetProcAddress("glUniform1i");
	glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)
      wglGetProcAddress("glGenerateMipmap");
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)
      wglGetProcAddress("glDisableVertexAttribArray");
	glUniform1f = (PFNGLUNIFORM1FPROC)
      wglGetProcAddress("glUniform1f");
	glUniform2f = (PFNGLUNIFORM2FPROC)
      wglGetProcAddress("glUniform2f");
    glUniform3fv = (PFNGLUNIFORM3FVPROC)
      wglGetProcAddress("glUniform3fv");
	glUniform4fv = (PFNGLUNIFORM4FVPROC)
      wglGetProcAddress("glUniform4fv");
	glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)
      wglGetProcAddress("glDrawArraysInstanced");
    glVertexAttribDivisor = (PFNVERTEXATTRIBDIVISORPROC)
      wglGetProcAddress("glVertexAttribDivisor");
    glDrawElementsInstanced = (PFNDRAWELEMENTSINSTANCEDPROC)
      wglGetProcAddress("glDrawElementsInstanced");
    return TRUE;
}
#else
#endif /* SOY_WIN32 */


/*
* o-------------------------------------------o
* | @openGL:shaders                           |
* o-------------------------------------------o
*/


/* default shaders */

#if 0
SOY_GLOBAL const int8* g_soyShaderVertexDefault =
"#version 330 core\n"
"layout(location = 0) in vec3 inPos;\n"
"layout(location = 1) in vec2 inUVCoord;\n"

"out vec3 outPos;\n"
"out vec2 uvCoords;\n"
"uniform float sTime;\n"

"void main() {\n"
"  uvCoords = inUVCoord;\n"
"  outPos = normalize(inPos);\n"
"  gl_Position = vec4(inPos.x, inPos.y, inPos.z, 1.0);\n"
"}\n";

SOY_GLOBAL const int8* g_soyShaderFragmentDefault =
"#version 330 core\n"
"out vec4 fragColor;\n"
"in vec3 outPos;\n"
"in vec2 uvCoords;\n"

"uniform sampler2D softTexture;\n"
"uniform float sTime;\n"

"void main() {\n"
"  fragColor = vec4(texture(softTexture, uvCoords).zyx, 1.0);\n"
"}\n";

#endif /* default shaders */

#define SOY_MAX_SHADER 8192*2

SOY_GLOBAL int8 g_soyGLSourceBuffer[SOY_MAX_SHADER];
SOY_GLOBAL const int8* srcPtrs[1] = {g_soyGLSourceBuffer};

/*
* o-------------------------------------------o
* | @openGL:interface                         |
* o-------------------------------------------o
*/

typedef enum enum_soyShaderType {
  SOY_VERTEX_SHADER,
  SOY_FRAGMENT_SHADER
} soyShaderType;

typedef struct tag_soyGLShader {
  uint32 program;
  uint32 vertID;
  uint32 fragID;
} soyShader, soyGLShader;

typedef uint32 SOY_TEX_ID;

typedef struct tag_soyGLTexture {
  SOY_TEX_ID id;
  uint8* data;
} soyGLTexture;

typedef uint32 SOY_VAO;
typedef uint32 SOY_VBO;
typedef uint32 SOY_EBO;

int32 SOY_glViewport(
    int32 x, int32 y, int32 width, int32 height) {
  glViewport(x, y, width, height);
  return TRUE;
}

int32 SOY_glGenTextures(GLuint num, GLuint* texture) {
  glGenTextures(num, texture);
  return TRUE;
}

int32 SOY_glEnable(GLenum cap) {
  glEnable(cap);
  return TRUE;
}

int32 SOY_glDisable(GLenum cap) {
  glDisable(cap);
  return TRUE;
}

int32 SOY_glCullFace(GLenum side) {
  glCullFace(side);
  return TRUE;
}

int32 SOY_glBlendFunc(GLenum s, GLenum d) {
  glBlendFunc(s, d);
  return TRUE;
}

int32 SOY_glBindTexture(GLenum type, GLuint texture) {
  glBindTexture(type, texture);
  return TRUE;
}

int32 SOY_glSetImageParams(int32 linear) {
  glTexParameteri(GL_TEXTURE_2D,
      GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,
      GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,
      GL_TEXTURE_MIN_FILTER, linear ?
        GL_NEAREST_MIPMAP_LINEAR : GL_NEAREST_MIPMAP_NEAREST);
  glTexParameteri(GL_TEXTURE_2D,
      GL_TEXTURE_MAG_FILTER, linear ? GL_LINEAR : GL_NEAREST);
  return TRUE;
}

int32 SOY_glTexImage2D(
    GLenum target,
    GLint level,
    GLint iFormat,
    GLsizei width,
    GLsizei height,
    GLint border,
    GLenum format,
    GLenum type,
    const void* data) {
  glTexImage2D(target,
      level, iFormat,
      width, height, border,
      format, type, data);
  return TRUE;
}

int32 SOY_glTexSubImage2D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
    const void* data) {
  glTexParameteri(GL_TEXTURE_2D,
      GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,
      GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,
      GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
  glTexParameteri(GL_TEXTURE_2D,
      GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexSubImage2D(target,
      level, xoffset, yoffset,
      width, height,
      format, type, data);
  return TRUE;
}

int32 SOY_glGenMipmap(GLenum type) {
  glGenerateMipmap(type);
  return TRUE;
}

int32 SOY_glActiveTexture(GLenum texture) {
  glActiveTexture(texture);
  return TRUE;
}

int32 SOY_glShaderLoad(
    char* filename, uint32* shader, GLenum type) {
  int8 curChar;
  int8 infoLog[512];
  int32 shaderRet = 0;
  int32 i = 0;
  void* file = fopen(filename, "r");
  if(file == NULL) { return FALSE; }
  SOY_LOG1("Loading shader \"%s\": \n", filename);
  while(fscanf(file, "%c", &curChar) != EOF) {
    g_soyGLSourceBuffer[i] = curChar;
    if(i < SOY_MAX_SHADER-1) { i++; }
#if 0
    printf("%c", curChar);
#endif
  }
  g_soyGLSourceBuffer[i] = 0;
  *shader = glCreateShader(type);
  if(!shader || *shader == 0) { SOY_LOG("Error creating shader\n"); }
  GLCHECK();
  glShaderSource(*shader, 1, &srcPtrs[0], NULL);
  GLCHECK();
  glCompileShader(*shader);
  GLCHECK();
  glGetShaderiv(*shader, GL_COMPILE_STATUS, &shaderRet);
  GLCHECK();
  if(!shaderRet) {
    glGetShaderInfoLog(*shader, 512, NULL, infoLog);
    GLCHECK();
    SOY_LOG1("Shader compilation faliure: %s\n", infoLog);
  }
  fclose(file);
  return TRUE;
}

int32 SOY_glShaderLoadInternal(
    char* source, uint32* shader, GLenum type) {
  int8 infoLog[512];
  int32 shaderRet = 0;
  int32 i = 0;
  while(source[i] != 0) {
    g_soyGLSourceBuffer[i] = source[i];
    if(i < SOY_MAX_SHADER-1) { i++; }
  }
  g_soyGLSourceBuffer[i] = 0;
  *shader = glCreateShader(type);
  if(!shader || *shader == 0) { SOY_LOG("Error creating shader\n"); }
  GLCHECK();
  glShaderSource(*shader, 1, &srcPtrs[0], NULL);
  GLCHECK();
  glCompileShader(*shader);
  GLCHECK();
  glGetShaderiv(*shader, GL_COMPILE_STATUS, &shaderRet);
  GLCHECK();
  if(!shaderRet) {
    glGetShaderInfoLog(*shader, 512, NULL, infoLog);
    GLCHECK();
    SOY_LOG1("Shader compilation faliure: %s\n", infoLog);
  }
  return TRUE;
}

int32 SOY_glShaderCreateInternal(
    char* vertSource, char* fragSource, soyGLShader* shader) {
  int8 infoLog[512];
  int32 glReturn = 0;
  int32 glError = 0;
  GLCHECK();
  if(!vertSource || !fragSource) { return FALSE; }
  shader->program = glCreateProgram();
  if(!shader->program) { SOY_LOG("Error creating shader program\n"); }
  SOY_glShaderLoadInternal(vertSource, &shader->vertID, GL_VERTEX_SHADER);
  GLCHECK();
  SOY_glShaderLoadInternal(fragSource, &shader->fragID, GL_FRAGMENT_SHADER);
  GLCHECK();
  glAttachShader(shader->program, shader->fragID);
  GLCHECK();
  glAttachShader(shader->program, shader->vertID);
  GLCHECK();
  glLinkProgram(shader->program);
  if(shader->program == GL_INVALID_VALUE) {
    SOY_LOG("Shader linking error\n");
  }

  GLCHECK();
  glGetProgramiv(shader->program, GL_LINK_STATUS, &glReturn);
  GLCHECK();
  if(!glReturn || glError) {
    SOY_LOG1("Shader create error: %d\n", glError);
    glGetProgramInfoLog(shader->program, 512, NULL, infoLog);
    SOY_LOG1("%s\n", infoLog);
  }
  glUseProgram(0);

  glDetachShader(shader->program, shader->vertID);
  glDetachShader(shader->program, shader->fragID);

  glDeleteShader(shader->vertID);
  GLCHECK();
  glDeleteShader(shader->fragID);
  GLCHECK();
  return TRUE;
}

int32 SOY_glShaderCreate(
    char* filenameVert, char* filenameFrag, soyGLShader* shader) {
  int8 infoLog[512];
  int32 glReturn = 0;
  int32 glError = 0;
  shader->program = glCreateProgram();
  GLCHECK();
  if(!shader->program) { SOY_LOG("Error creating shader program\n"); }
  SOY_glShaderLoad(filenameVert, &shader->vertID, GL_VERTEX_SHADER);
  GLCHECK();
  SOY_glShaderLoad(filenameFrag, &shader->fragID, GL_FRAGMENT_SHADER);
  GLCHECK();
  glAttachShader(shader->program, shader->fragID);
  GLCHECK();
  glAttachShader(shader->program, shader->vertID);
  GLCHECK();
  glLinkProgram(shader->program);
  if(shader->program == GL_INVALID_VALUE) {
    SOY_LOG("Shader linking error\n");
  }
  GLCHECK();
  glGetProgramiv(shader->program, GL_LINK_STATUS, &glReturn);
  GLCHECK();
  if(!glReturn || glError) {
    SOY_LOG1("Shader create error: %d\n", glError);
    glGetProgramInfoLog(shader->program, 512, NULL, infoLog);
    SOY_LOG1("%s\n", infoLog);
  }
  glUseProgram(0);
  glDetachShader(shader->program, shader->vertID);
  glDetachShader(shader->program, shader->fragID);
  glDeleteShader(shader->vertID);
  GLCHECK();
  glDeleteShader(shader->fragID);
  GLCHECK();
  return TRUE;
}

int32 SOY_glUseProgram(soyGLShader* shader) {
  glUseProgram(shader->program);
  return TRUE;
}

int32 SOY_glSetUniformBool(
    soyGLShader* shader, char* label, int32 value) {
  glUniform1i(glGetUniformLocation(
        shader->program, label), value);
  return TRUE;
}

int32 SOY_glSetUniformInt(
    soyGLShader* shader, char* label, int32 value) {
  glUniform1i(glGetUniformLocation(shader->program, label), value);
  return TRUE;
}

int32 SOY_glSetUniformFloat(
    soyGLShader* shader, char* label, real32 value) {
  glUniform1f(glGetUniformLocation(shader->program, label), value);
  return TRUE;
}

int32 SOY_glSetUniformFloat3(
    soyGLShader* shader, char* label, int32 count, real32* value) {
  glUniform3fv(glGetUniformLocation(shader->program, label), count, value);
  return TRUE;
}

int32 SOY_glSetUniformMat4(
    soyGLShader* shader,
    char* label, int32 count, int32 transpose, const GLfloat* value) {
  glUniformMatrix4fv(
      glGetUniformLocation(shader->program, label), count, transpose, value);
  return TRUE;
}

int32 SOY_glGenBuffers(GLsizei i, GLuint* buffer) {
  glGenBuffers(i, buffer);
  return TRUE;
}

int32 SOY_glDeleteBuffers(GLsizei i, GLuint* buffers) {
  glDeleteBuffers(i, buffers);
  return TRUE;
}

int32 SOY_glGenVertexArrays(GLsizei i, GLuint* buffer) {
  glGenVertexArrays(i, buffer);
  return TRUE;
}

int32 SOY_glBindVertexArray(GLuint arrayID) {
  glBindVertexArray(arrayID);
  return TRUE;
}

int32 SOY_glBindBuffer(GLenum target, GLuint bufferID) {
  glBindBuffer(target, bufferID);
  return TRUE;
}

int32 SOY_glVertexAttribDivisor(GLuint index, GLuint div) {
  glVertexAttribDivisor(index, div);
  return TRUE;
}

int32 SOY_glBufferData(
    GLenum target, GLsizei size, const void* data) {
  glBufferData(target, size, data, GL_STATIC_DRAW);
  return TRUE;
}

int32 SOY_glDynBufferData(
    GLenum target, GLsizei size, const void* data) {
  glBufferData(target, size, data,  GL_DYNAMIC_DRAW);
  return TRUE;
}

int32 SOY_glDrawArrays(
    GLenum mode, GLint startIndex, GLsizei vertCount) {
  glDrawArrays(mode, startIndex, vertCount);
  return TRUE;
}

int32 SOY_glDrawArraysInstanced(
    GLenum mode, GLint startIndex, GLsizei vertCount, GLsizei amt) {
  glDrawArraysInstanced(mode, startIndex, vertCount, amt);
  return TRUE;
}

int32 SOY_glDrawElements(
    GLenum mode, GLsizei vertCount, GLenum type, const void* indices) {
  glDrawElements(mode, vertCount, type, indices);
  return TRUE;
}

int32 SOY_glDrawElementsInstanced(
    GLenum mode, GLsizei vertCount, GLenum type,
    const void* indices, int32 instanceCount) {
  glDrawElementsInstanced(mode, vertCount, type, indices, instanceCount);
  return TRUE;
}

int32 SOY_glVertexAttribPointer(GLuint index,
  GLint amt, GLenum type, GLboolean norm,
  GLsizei size, const GLvoid* offset) {
  glVertexAttribPointer(index, amt, type, norm, size, offset);
  return TRUE;
}

int32 SOY_glVertexAttribIPointer(GLuint index,
  GLint amt, GLenum type,
  GLsizei size, const GLvoid* offset) {
  glVertexAttribIPointer(index, amt, type, size, offset);
  return TRUE;
}

int32 SOY_glVertexAttribEnable(GLuint index) {
  glEnableVertexAttribArray(index);
  return TRUE;
}

int32 SOY_glClearColour (real32 r, real32 g, real32 b, real32 a) {
  glClearColor(r, g, b, a);
  return TRUE;
}

int32 SOY_glClear (GLbitfield mask) {
  glClear(mask);
  return TRUE;
}

int32 SOY_glSwapBuffers(void* deviceContext) {
  return SwapBuffers(deviceContext);
}

#endif /* SOY_OPENGL_H */
#endif /* SOY_NO_HARDWARE */

/*=========================================================================*/
/* PLATFORM LAYER                                                          */
/*=========================================================================*/

typedef void* soyWindow;
typedef void* soyDeviceContext;
typedef void* soyRenderContext;
typedef void* soySemaphore;
typedef void* soyThread;
typedef void* soyAudioRenderClient;

typedef struct tag_soySampleResult soySampleResult;

typedef struct tag_soyWorkQueue soyWorkQueue;
typedef struct tag_soyWorkQueueEntry soyWorkQueueEntry;
typedef struct tag_soyWorkQueueThreadInfo soyWorkQueueThreadInfo;

typedef struct tag_soyFileData soyFileData;

typedef struct tag_soyApp soyApp;

typedef int32 (*PFUSERVOIDPROC) (void);
typedef void (*PFTHREADCALLBACK) (void* args);
typedef soySampleResult (*PFAUDIOSAMPLE) (void* sampleParams);
typedef int32 (*PFAUDIOCAPTURE) (void* sampleParams, int16 l, int16 r);
typedef int32 (*PFWORKQUEUEPROC) (soyWorkQueue* queue, void* args);
typedef int32 (*PFFILELIST) (soyFileData data, void* args);

struct tag_soySampleResult {
  int16 left;
  int16 right;
};

struct tag_soyFileData {
  int32 isDir;
  int32 isNormal;
  int32 isHidden;
  int32 indexInDir;
  int32 fileSize;
  int8* name;
  int64 lastWriteTime;
};

int32 SOY_fileDataReset(soyFileData* data) {
  data->isDir = FALSE;
  data->isHidden = FALSE;
  data->isNormal = TRUE;
  data->name = NULL;
  data->indexInDir = 0;
  data->isDir = FALSE;
  data->fileSize = 0;
  return TRUE;
}

struct tag_soyWorkQueueEntry {
  void* ptrUserData;
  PFWORKQUEUEPROC userCallback;
};

struct tag_soyWorkQueue {
  uint32 volatile completionGoal;
  uint32 volatile completionTarget;
  uint32 volatile nextEntryToStore;
  uint32 volatile nextEntryToLoad;
  uint32 volatile threadIndex;
  uint32 volatile numThreads;
  soyWorkQueueEntry entryData[SOY_MAX_WORK_QUEUE_ITEMS];
  soySemaphore semaphore;
};

struct tag_soyWorkQueueThreadInfo {
  soyWorkQueue* queueHandle;
  soyThread thread;
  uint32 threadIndex;
};

typedef struct tag_soyPlatformData soyPlatformData;

/*
* o-------------------------------------------o
* | @platform callbacks                       |
* o-------------------------------------------o
*/

int32 SOY_windowCreateCallback(soyWindow win);
int32 SOY_windowCloseCallback(soyWindow win);
int32 SOY_initCallback(int32 state);
int32 SOY_quitCallback(int32 state);
int32 SOY_charCallback(soyWindow win, uint8 key);
int32 SOY_keyCallback(soyWindow win, int32 key, int32 code, int32 state);
int32 SOY_mouseCallback(soyWindow win, int32 button, int32 state);
int32 SOY_mouseMoveCallback(soyWindow win, int32 x, int32 y);
int32 SOY_mouseScrollCallback(soyWindow win, int32 scroll);
int32 SOY_focusCallback(soyWindow win, int32 state);
int32 SOY_repaintCallback(soyWindow win);
int32 SOY_paintCallback(soyWindow win);
int32 SOY_renderCallback(soyWindow win);
int32 SOY_updateCallback(real32 delta);
int32 SOY_hitTestCallback(soyWindow win, int32* t, int32* b, int32* p);
int32 SOY_resizeCallback(soyWindow win, int32 x, int32 y, int32 w, int32 h);
int32 SOY_minMaxCallback(soyWindow win, int32* w, int32* h);

/*
* o-------------------------------------------o
* | @platform functions                       |
* o-------------------------------------------o
*/

/* misc. */
int32 SOY_closeHandle(void* handle);

/* file handling */
int32 SOY_fileCopy(int8* src, int8* dest);
uint64 SOY_lastWriteTime(int8* file);
int32 SOY_getWorkingDirectory(int8* buffer, int32 bufferLen);
int32 SOY_listFilesInDir(int8* dir, PFFILELIST callback, void* args);

/* timing related */
int64 SOY_wallClock(void);
real64 SOY_wallClockDelta(int64 begin, int64 end);
int32 SOY_sleep(int32 miliseconds);
int32 SOY_setScheduler(soyPlatformData* d, int32 miliseconds);
int32 SOY_resetScheduler(soyPlatformData* d, int32 ms);
uint64 SOY_cycleCount(void);

/* thread related */
soyThread SOY_createThread(
    PFTHREADCALLBACK threadProc, void* threadArgs, uint32* outThreadID);
void SOY_exitThread(int32 exitCode);
void* SOY_createSemaphore(int32 initialCount, int32 maximumCount);
int32 SOY_releaseSemaphore(
    soySemaphore semHandle, int32 releaseCount, int32* prevCount);
int32 SOY_waitForSingle(void** handle, int32 waitMs, int32 f);
int32 SOY_waitForMultiple(
    int32 objectCount, void** handles, int32 waitMs, int32 f);

/* thread work queue */
soyWorkQueueEntry SOY_workQueueEntry(PFWORKQUEUEPROC proc, void* data);
int32 SOY_workQueueAddEntry(
    soyWorkQueue* q, PFWORKQUEUEPROC callback, void* data);
int32 SOY_completeWorkEntry(soyWorkQueue* q);
int32 SOY_workQueueComplete(soyWorkQueue* q);
void SOY_workQueueProcedure(void* args);

/* window and input related */
soyWindow SOY_createWindowGL(
    const char* title, int32 x, int32 y, int32 width, int32 height);
soyWindow SOY_createWindow(
    const int8* title, int32 x, int32 y, int32 width, int32 height);
int32 SOY_windowBlit(
    soyWindow window, uint8* buffer, int32 srcWidth, int32 srcHeight);
int32 SOY_redrawWindow(soyWindow window);
int32 SOY_destroyWindow(soyWindow window);
int32 SOY_pollEvents(soyWindow window);
int16 SOY_getKeyState(soyWindow window, soyKeyCode key);
int32 SOY_windowIsMinimized(soyWindow window);
int32 SOY_windowIsMaximized(soyWindow window);
int32 SOY_windowIsFocused(soyWindow window);
int32 SOY_windowMaximize(soyWindow window);
int32 SOY_windowRestore(soyWindow window);
int32 SOY_windowMinimize(soyWindow window);
int32 SOY_windowHide(soyWindow window);
int32 SOY_windowShow(soyWindow window);
int32 SOY_windowX(soyWindow window);
int32 SOY_windowY(soyWindow window);
int32 SOY_windowWidth(soyWindow window);
int32 SOY_windowHeight(soyWindow window);
int32 SOY_screenWidth(void);
int32 SOY_screenHeight(void);
int32 SOY_windowX(soyWindow window);
int32 SOY_windowY(soyWindow window);
int32 SOY_getMouseScreenX(void);
int32 SOY_getMouseScreenY(void);
int32 SOY_getKeyboardState(uint8* keyArray256);
int32 SOY_keyToASCII(int32 keyCode, int32 scanCode);
int32 SOY_dialogBox(soyWindow hwnd, int8* title, int8* content);
int32 SOY_setMouseCursor(int32 x, int32 y);
int32 SOY_showMouseCursor(int32 value);
int32 SOY_setWindowPos(soyWindow win, int32 x, int32 y, int32 w, int32 h);

/* memory */
void* SOY_memoryAllocate(size_t size);
int32 SOY_memoryFree(void* memory);

/* shared libraries */
void* SOY_libraryLoad(char* name);
int32 SOY_libraryFree(void* hInst);

/* audio related */
int32 SOY_audioBufferPlay(soyPlatformData* pd);
int32 SOY_audioBufferStop(soyPlatformData* pd);
int32 SOY_audioCreate(soyWindow window, soyPlatformData* pd,
    int32 samplesPerSecond, int32 bitRate, int32 bufferSize);
int32 SOY_audioFillBuffer(soyPlatformData* pd,
    int32 bytesPerSample, int32 byteToLock, int32 bytesToWrite,
    PFAUDIOSAMPLE sampleFunc, void* sampleParams);
int32 SOY_audioUpdateBuffer(soyPlatformData* pd,
    int32 bytesPerSample, int32 bufferSize,
    PFAUDIOSAMPLE sampleFunc, void* sampleParams);
int32 SOY_audioCreateFullDuplex(soyWindow window, soyPlatformData* pd,
    int32 samplesPerSecond, int32 bitRate, int32 bufferSize);
int32 SOY_audioFillCaptureBuffer(soyPlatformData* pd,
    int32 bytesPerSample, int32 byteToLock, int32 bytesToWrite,
    PFAUDIOCAPTURE sampleFunc, void* sampleParams);
int32 SOY_audioUpdateCaptureBuffer(soyPlatformData* pd,
    int32 bytesPerSample, int32 bufferSize,
    PFAUDIOCAPTURE sampleFunc, void* sampleParams);
/*=========================================================================*/
/* PLATFORM WIN32                                                          */
/*=========================================================================*/

#ifdef SOY_WIN32

struct tag_soyPlatformData {
  int32 schedulerValid;
  int32 schedulerCount;
  int32 schedulerLastValue;

  LPDIRECTSOUND audioHandle;
  LPDIRECTSOUNDFULLDUPLEX audioHandleDuplex;

  LPDIRECTSOUNDBUFFER audioBuffer;
  LPDIRECTSOUNDCAPTUREBUFFER audioCaptureBuffer;

#ifndef SOY_LEGACY_AUDIO
  IAudioClient* wasapiSoundHandle;
  IAudioRenderClient* wasapiRenderClient;
#endif
  int32 soundLatencySamples;
  int32 soundBufferIndex;
  int32 soundCaptureBufferIndex;
  int32 soundCaptureBufferIndexNext;
  int32 audioValid;
  int32 audioCaptureValid;
  int32 soundPlaying;
};

int32 SOY_initPlatformData(soyPlatformData* d) {
  d->soundLatencySamples = 0;
  d->schedulerValid = FALSE;
  d->schedulerCount = 0;
  d->schedulerLastValue = 0;
  d->soundBufferIndex = 0;
  d->soundCaptureBufferIndex = 0;
  d->soundCaptureBufferIndexNext = 0;
  d->soundPlaying = FALSE;
  d->audioHandle = NULL;
  d->audioHandleDuplex = NULL;
  d->audioCaptureBuffer = NULL;
  d->audioBuffer = NULL;
  d->audioValid = FALSE;
  d->audioCaptureValid = FALSE;
  return TRUE;
}

uint64 SOY_lastWriteTime(int8* file) {
  FILETIME t;
  ULARGE_INTEGER copy;
  WIN32_FIND_DATAA findData;
  HANDLE findHandle = FindFirstFileA(file, &findData);
  t.dwHighDateTime = 0;
  t.dwLowDateTime = 0;
  if(findHandle != INVALID_HANDLE_VALUE) {
	FindClose(findHandle);
	t = findData.ftLastWriteTime;
    copy.LowPart = t.dwLowDateTime;
    copy.HighPart = t.dwHighDateTime;
    return copy.QuadPart;
  } else {
    return FALSE;
  }
}

int32 SOY_getWorkingDirectory(int8* buffer, int32 bufferLen) {
  return GetCurrentDirectory(bufferLen, buffer);
}

int32 SOY_fileCopy(int8* src, int8* dest) {
  return CopyFile(src, dest, FALSE);
}

int32 SOY_closeHandle(void* handle) {
  return CloseHandle(handle);
}

int32 SOY_listFilesInDir(int8* dir, PFFILELIST callback, void* args) {
  WIN32_FIND_DATAA ffd;
  LARGE_INTEGER filesize;
  LARGE_INTEGER lastWriteTime;
  HANDLE hFind = INVALID_HANDLE_VALUE;
  DWORD error = 0;
  int32 index = 0;
  soyFileData userFd;


  if(strnlen(dir, MAX_PATH) >= MAX_PATH - 1) {
    SOY_LOG("Error");
    return FALSE;
  }

  hFind = FindFirstFileA(dir, &ffd);

  if(hFind == INVALID_HANDLE_VALUE) {
    SOY_LOG("Error\n");
    return FALSE;
  }

  do {
    SOY_fileDataReset(&userFd);
    userFd.name = ffd.cFileName;
    userFd.indexInDir = index++;
    if(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
      userFd.isDir = TRUE;
    } else {
      filesize.LowPart = ffd.nFileSizeLow;
      filesize.HighPart = ffd.nFileSizeHigh;
      userFd.fileSize = (int32)(filesize.QuadPart);
    }
    lastWriteTime.LowPart = ffd.ftLastWriteTime.dwLowDateTime;
    lastWriteTime.HighPart = ffd.ftLastWriteTime.dwHighDateTime;
    userFd.lastWriteTime = (int64)lastWriteTime.QuadPart;
    if(callback) { callback(userFd, args); }
  } while(FindNextFile(hFind, &ffd) != 0);
  error = GetLastError();
  if(error != ERROR_NO_MORE_FILES) {
    SOY_LOG1("Error: %d\n", (int32)error);
    return FALSE;
  }
  FindClose(hFind);
  return TRUE;
}


int32 SOY_setScheduler(soyPlatformData* d, int32 miliseconds) {
  MMRESULT ret = timeBeginPeriod(miliseconds);
	if(ret == TIMERR_NOERROR) {
      d->schedulerValid = TRUE;
	  d->schedulerCount++;
      d->schedulerLastValue = miliseconds;
      return TRUE;
    } else {
      d->schedulerValid = FALSE;
    }
    SOY_LOG("Error setting scheduler\n");
	d->schedulerCount++;
	return FALSE;
}

int32 SOY_resetScheduler(soyPlatformData* d, int32 ms) {
	MMRESULT ret = timeEndPeriod(ms);
	if(ret == TIMERR_NOERROR) {
	  d->schedulerValid = FALSE;
	  d->schedulerCount--;
      d->schedulerLastValue = 0;
      return TRUE;
	}
    SOY_LOG("Error resetting scheduler\n");
	d->schedulerCount--;
	return FALSE;
}

void* SOY_createSemaphore(
    int32 initialCount, int32 maximumCount) {
  return CreateSemaphoreA(
      0, initialCount, maximumCount, 0);
}

int32 SOY_releaseSemaphore(
    soySemaphore semHandle, int32 releaseCount, int32* prevCount) {
  return ReleaseSemaphore(semHandle, releaseCount, (LPLONG)prevCount);
}

soyThread SOY_createThread(
    PFTHREADCALLBACK threadProc, void* threadArgs, uint32* outThreadID) {
  LPTHREAD_START_ROUTINE tprocPtr = (LPTHREAD_START_ROUTINE)threadProc;
  return CreateThread(
      NULL, 0, tprocPtr, threadArgs, 0, (LPDWORD)(outThreadID));
}

void SOY_exitThread(int32 exitCode) {
  ExitThread(exitCode);
}

int32 SOY_waitForSingle(
    void** handle, int32 waitMs, int32 f) {
  return WaitForSingleObjectEx(handle, f, waitMs);
}

int32 SOY_waitForMultiple(
    int32 objectCount, void** handles, int32 waitMs, int32 f) {
  return WaitForMultipleObjects(objectCount, handles, f, waitMs);
}

soyWorkQueueEntry SOY_workQueueEntry(PFWORKQUEUEPROC proc, void* data) {
  soyWorkQueueEntry ret;
  ret.ptrUserData = data;
  ret.userCallback = proc;
  return ret;
}

int32 SOY_workQueueAddEntry(
    soyWorkQueue* q, PFWORKQUEUEPROC callback, void* data) {
  /* NOTE: use InterlockedCompareExchange */
  soyWorkQueueEntry* curEntry = NULL;
  uint32 newNextEntryToStore =
    ((q->nextEntryToStore + 1) % SOY_MAX_WORK_QUEUE_ITEMS);
  SOY_ASSERT(newNextEntryToStore != q->nextEntryToStore);
  curEntry = q->entryData + q->nextEntryToStore;
  curEntry->ptrUserData = data;
  curEntry->userCallback = callback;
  q->completionGoal++;
  SOY_WRITE_BARRIER;
  q->nextEntryToStore = newNextEntryToStore;
  SOY_releaseSemaphore(q->semaphore, 1, 0);
  return TRUE;
}

int32 SOY_completeWorkEntry(soyWorkQueue* q) {
  soyWorkQueueEntry entry = SOY_workQueueEntry(NULL, NULL);
  int32 sleepThread = FALSE;
  uint32 entryIndex = 0;
  uint32 origEntryLoadIndex = q->nextEntryToLoad;
  uint32 newEntryLoadIndex =
    (origEntryLoadIndex + 1) % SOY_MAX_WORK_QUEUE_ITEMS;
  if(origEntryLoadIndex != q->nextEntryToStore) {
    entryIndex =
      InterlockedCompareExchange(
        (LONG volatile *)&q->nextEntryToLoad,
        newEntryLoadIndex,
        origEntryLoadIndex);
    if(entryIndex == origEntryLoadIndex) {
      entry = q->entryData[entryIndex];
      entry.userCallback(q, entry.ptrUserData);
      InterlockedIncrement(
          (LONG volatile * )&q->completionTarget);
    }
  } else {
    sleepThread = TRUE;
  }
  return sleepThread;
}

int32 SOY_workQueueComplete(soyWorkQueue* q) {
  while(q->completionGoal != q->completionTarget) {
    SOY_completeWorkEntry(q);
  }
  q->completionGoal = 0;
  q->completionTarget = 0;
  return TRUE;
}

void SOY_workQueueProcedure(void* args) {
  soyWorkQueueThreadInfo* workQueueInfo = (soyWorkQueueThreadInfo*)args;
  soyWorkQueue* workQueue = workQueueInfo->queueHandle;
  for(;;) {
    if(SOY_completeWorkEntry(workQueue)) {
      SOY_waitForSingle(
          workQueue->semaphore, INFINITE, FALSE);
    }
  }
}

SOY_GLOBAL soyWorkQueueThreadInfo g_soyWorkQueueThreadInfo[SOY_MAX_THREADS];

int32 SOY_workQueueInit(soyWorkQueue* q, int32 numThreads) {
  int32 numThreadsInt = numThreads - 1;
  int32 curThreadIndex = 0;
  int32 semInitialCount = 0;
  int32 semMaxCount = numThreadsInt;
  uint32 threadIDs[SOY_MAX_THREADS];
  q->numThreads = numThreads;
  q->semaphore = SOY_createSemaphore(semInitialCount, semMaxCount);
  SOY_ASSERT(numThreads <= SOY_MAX_THREADS);
  for(curThreadIndex = 0; curThreadIndex < numThreadsInt; curThreadIndex++) {
    g_soyWorkQueueThreadInfo[curThreadIndex].queueHandle = q;
    g_soyWorkQueueThreadInfo[curThreadIndex].threadIndex = curThreadIndex;
    g_soyWorkQueueThreadInfo[curThreadIndex].thread =
      SOY_createThread(
          SOY_workQueueProcedure,
          &g_soyWorkQueueThreadInfo[curThreadIndex],
          &threadIDs[curThreadIndex]);
    SOY_closeHandle(
        g_soyWorkQueueThreadInfo[curThreadIndex].thread);
  }
  SOY_LOG1("Initialized work queue with %d threads\n", numThreads);
  return TRUE;
}

int32 SOY_workQueueQuitProc(soyWorkQueue* q, void* args) {
  SOY_ASSERT(q != NULL);
  SOY_exitThread(0);
  return args != NULL;;
}

int32 SOY_workQueueFinalize(soyWorkQueue* q) {
  uint32 i;
  int32 shouldQuit = TRUE;
  for(i = 0; i < q->numThreads; i++) {
    SOY_workQueueAddEntry(q, SOY_workQueueQuitProc, &shouldQuit);
  }
  SOY_workQueueComplete(q);
  SOY_LOG("Finalized work queue threads\n");
  return TRUE;
}

LRESULT CALLBACK internal_SOY_eventCallback(
	HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int32 internal_SOY_setStyle(
  WNDCLASSA* winStyle, HINSTANCE hInst, const int8* className) {
  ATOM regRet;
  winStyle->lpszClassName = className;
  winStyle->lpfnWndProc = internal_SOY_eventCallback;
  winStyle->style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
  winStyle->cbClsExtra = 0;
  winStyle->cbWndExtra = 0;
  winStyle->hInstance = hInst;
  winStyle->hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
  winStyle->lpszMenuName = NULL;
  winStyle->hCursor = LoadCursor(NULL, IDC_ARROW);
  winStyle->hIcon = LoadIcon(NULL, IDI_APPLICATION);
  regRet = RegisterClassA(winStyle);
  if(regRet == 0) {
	MessageBoxA(NULL, "Window Registration Failed!", "Error!",
        MB_ICONEXCLAMATION | MB_OK);
		return FALSE;
	}
    return TRUE;
}

int32 internal_SOY_setPixelFormat(PIXELFORMATDESCRIPTOR* hpf) {
  hpf->nSize = sizeof(PIXELFORMATDESCRIPTOR);
  hpf->nVersion = 1;
  hpf->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
  hpf->iPixelType = PFD_TYPE_RGBA;
  hpf->cColorBits = 32;
  hpf->cRedBits = 0;
  hpf->cRedShift = 0;
  hpf->cGreenBits = 0;
  hpf->cGreenShift = 0;
  hpf->cBlueBits = 0;
  hpf->cBlueShift = 0;
  hpf->cAlphaBits = 0;
  hpf->cAlphaShift = 0;
  hpf->cAccumBits = 0;
  hpf->cAccumRedBits = 0;
  hpf->cAccumGreenBits = 0;
  hpf->cAccumBlueBits = 0;
  hpf->cDepthBits = 24;
  hpf->cStencilBits = 8;
  hpf->cAuxBuffers = 0;
  hpf->iLayerType = PFD_MAIN_PLANE;
  hpf->bReserved = 0;
  hpf->dwLayerMask = 0;
  hpf->dwVisibleMask = 0;
  hpf->dwDamageMask = 0;
  return TRUE;
}

soyDeviceContext SOY_getDeviceContext(soyWindow window) {
  return GetDC(window);
}

#ifndef SOY_NO_HARDWARE

SOY_GLOBAL int32 g_soyGLPixelAttribs[] = {
  WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
  WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
  WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
  /* WGL_SWAP_EXCHANGE_ARB causes problems with window menu in fullscreen */
  WGL_SWAP_METHOD_ARB, WGL_SWAP_COPY_ARB,
  WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
  WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
  WGL_COLOR_BITS_ARB, 32,
  WGL_ALPHA_BITS_ARB, 8,
  WGL_DEPTH_BITS_ARB, 24,
  WGL_SAMPLES_ARB, 4,
  0
};

SOY_GLOBAL int32 g_soyGLContextAttributes[] = {
  WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
  WGL_CONTEXT_MINOR_VERSION_ARB, 3,
  WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
  0
};

soyRenderContext internal_SOY_createFakeContextGL(soyWindow window) {
  int pixelFormat;
  PIXELFORMATDESCRIPTOR pf;
  HGLRC fakeRenderContext = NULL;
  HDC deviceContext = SOY_getDeviceContext(window);
  internal_SOY_setPixelFormat(&pf);
  if(deviceContext) {
    pixelFormat = ChoosePixelFormat(deviceContext, &pf);
    if(pixelFormat) {
      if(SetPixelFormat(
            deviceContext, pixelFormat, &pf)) {
            fakeRenderContext = wglCreateContext(deviceContext);
        if(!fakeRenderContext) {
          SOY_LOG("Failed to create fake render context\n");
          return NULL;
        }
      }
    }
  }
  return fakeRenderContext;
}

soyRenderContext internal_SOY_createRealContextGL(
    soyDeviceContext fakeDeviceContext,
    soyRenderContext fakeRenderContext) {
  PIXELFORMATDESCRIPTOR pf;
  int wglcret;
  HGLRC ret = NULL;
  int pixelFormat = 0;
  unsigned int numFormats = 0;
  SOY_LOG("Setting pixel format\n");
  internal_SOY_setPixelFormat(&pf);
  SOY_LOG("Making current\n");

  if(fakeDeviceContext) {
    wglMakeCurrent(
        fakeDeviceContext,
        fakeRenderContext);
  	SOY_LOG("Chosing pixel format\n");
    wglcret =
      wglChoosePixelFormatARB(
          fakeDeviceContext,
          g_soyGLPixelAttribs, NULL, 1, &pixelFormat, &numFormats);
  	SOY_LOG("Chosed pixel format\n");
    if(wglcret == 0) { SOY_LOG("Error chosing pixel format\n"); }
    if(numFormats) {

  		SOY_LOG("Describe pixel format\n");
      if(!DescribePixelFormat(
          fakeDeviceContext,
          pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pf)) {
        SOY_LOG("Error describing pixel format\n");
      }
      SOY_LOG("Setting pixel format\n");
      if(SetPixelFormat(fakeDeviceContext, pixelFormat, &pf)) {
        ret = wglCreateContextAttribsARB(
                fakeDeviceContext, 0, g_soyGLContextAttributes);
        if(!ret) {
          SOY_LOG("Error creating render context\n");
        }
      } else {
        SOY_LOG("Error setting pixel format\n");
        SOY_LOG1("Error: %d\n", (int32)GetLastError());
      }
    }
  } else {
    SOY_LOG("No fake device context found\n");
  }
  if(!ret) { SOY_LOG("Error creating render context\n"); }
  return ret;
}

soyWindow internal_SOY_createFakeWindowGL(
    HINSTANCE hInst, const char* title) {
  soyWindow ret = NULL;
  ret = CreateWindowA(title, title,
      WS_POPUP | WS_MINIMIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
      0, 0, 1, 1, NULL, NULL, hInst, NULL);
  if(!ret) {
    SOY_ASSERT(!"Error creating window\n");
    SOY_LOG1("Error creating fake window: %ld\n", GetLastError());
    return ret;
  }
  return ret;
}

soyWindow internal_SOY_createRealWindowGL(HINSTANCE hInst,
    int x, int y, int width, int height, const char* title) {
  soyWindow ret = NULL;
  ret = CreateWindowA(title, title,
      WS_POPUP | WS_MINIMIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
      x, y, width, height, NULL, NULL, hInst, NULL);
  if(!ret) {
    SOY_ASSERT(!"Error creating window\n");
    SOY_LOG("Error creating real window\n");
    return ret;
  }
  return ret;
}

int32 internal_SOY_destroyFakeWindowGL(
    soyWindow fakeHandle,
    soyDeviceContext fakeDeviceContext,
    soyRenderContext fakeRenderContext) {
  wglMakeCurrent(fakeDeviceContext, NULL);
  wglDeleteContext(fakeRenderContext);
  ReleaseDC(fakeHandle, fakeDeviceContext);
  DestroyWindow(fakeHandle);
  return TRUE;
}

soyWindow SOY_createWindowGL(
    const char* title, int32 x, int32 y, int32 width, int32 height) {
  WNDCLASSA winStyle;
  int32 vsync = 0;
  HINSTANCE hInst = GetModuleHandle(NULL);
  soyDeviceContext fakeDeviceContext = NULL;
  soyRenderContext fakeRenderContext = NULL;
  soyWindow fakeWindow = NULL;
  soyDeviceContext realDeviceContext = NULL;
  soyRenderContext realRenderContext = NULL;
  soyWindow realWindow = NULL;
  SOY_LOG("Creating opengl window\n");
  internal_SOY_setStyle(&winStyle, hInst, title);
  SOY_LOG("Set style\n");
  fakeWindow = internal_SOY_createFakeWindowGL(hInst, title);
  SOY_LOG("Fake window\n");
  fakeDeviceContext = SOY_getDeviceContext(fakeWindow);
  SOY_LOG("Device context\n");
  fakeRenderContext = internal_SOY_createFakeContextGL(fakeWindow);
  SOY_LOG("Render context\n");
  wglMakeCurrent(
      fakeDeviceContext,
      fakeRenderContext);
  SOY_LOG("Make current\n");
  if(!wglGetCurrentContext()) {SOY_LOG("Error, current context is NULL\n");}
  if(!SOY_glLoadExtensionList()) {
    SOY_LOG1("Error loading OpenGL extensions: %ld\n", GetLastError());
  }
  SOY_LOG("Load extensons\n");
  realWindow =
    internal_SOY_createRealWindowGL(hInst, x, y, width, height, title);

  SOY_LOG("Real window\n");
  if(!realWindow) { SOY_LOG("Error creating openGL window\n"); }

  realDeviceContext = SOY_getDeviceContext(realWindow);
  SOY_LOG("Dev context\n");
  realRenderContext = internal_SOY_createRealContextGL(
      realDeviceContext, fakeRenderContext);
  SOY_LOG("Render context\n");

  internal_SOY_destroyFakeWindowGL(
      fakeWindow, fakeDeviceContext, fakeRenderContext);
  SOY_LOG("Destroy fake\n");

  if(!realRenderContext) { SOY_LOG("Error getting render context\n"); }
  if(!realDeviceContext) { SOY_LOG("Error getting device context\n"); }

  if(!wglMakeCurrent(realDeviceContext, realRenderContext)) {
    SOY_LOG("Error making gl context current\n");
  };
  SOY_LOG("Make current\n");

  glClearDepth(1.0f);
  glDisable(GL_DEPTH_TEST);
  glFrontFace(GL_CW);
  glDisable(GL_CULL_FACE);
  glCullFace(GL_BACK);
#if 1
  if(vsync == 0 ){
	wglSwapIntervalEXT(0);
  } else if (vsync == 1) {
	wglSwapIntervalEXT(1);
  }
#endif
  glViewport(0, 0, width, height);
  ShowWindow(realWindow, SW_SHOW);
  SetForegroundWindow(realWindow);
  SetFocus(realWindow);
  UpdateWindow(realWindow);
  SOY_LOG("Created opengl window\n");
  return realWindow;
}

#endif /* SOY_NO_HARDWARE */

soyWindow SOY_createWindow(
    const int8* title, int32 x, int32 y, int32 width, int32 height) {
    WNDCLASSA winStyle;
	HINSTANCE hInstance = GetModuleHandle(NULL);
    soyWindow ret;
    internal_SOY_setStyle(&winStyle, hInstance, title);
#if 1
    ret = CreateWindowA(
        title, title, WS_POPUP | WS_MINIMIZEBOX, x, y, width, height,
        NULL, NULL, hInstance, NULL);
#else
    ret = CreateWindowA(
        title, title, WS_OVERLAPPED, x, y, width, height,
        NULL, NULL, hInstance, NULL);
#endif
    if(ret == NULL) {
        SOY_LOG1("Last error: %d\n", (int32)GetLastError());
        SOY_ASSERT(!"Error creating window\n");
		MessageBoxA(NULL, "Failed to create Window!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
		return FALSE;
    }
    ShowWindow(ret, SW_SHOW);
	SetForegroundWindow(ret);
	SetFocus(ret);
    return ret;
}

int32 SOY_destroyWindow(soyWindow window) {
  return DestroyWindow(window);
}

int32 SOY_redrawWindow(soyWindow window) {
  return RedrawWindow(window, NULL, NULL, RDW_INTERNALPAINT);
}

int32 SOY_pollEvents(soyWindow window) {
  MSG msg;
  while(PeekMessage(&msg, window, 0, 0, PM_REMOVE)) {
    if(msg.message == WM_QUIT) { return FALSE; }
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return msg.message != WM_QUIT;
}

int32 SOY_windowIsMinimized(soyWindow window) {
  return IsIconic(window);
}

int32 SOY_windowIsMaximized(soyWindow window) {
  WINDOWPLACEMENT wp;
  wp.length = sizeof(WINDOWPLACEMENT);
  GetWindowPlacement(window, &wp);
  return (wp.showCmd == SW_SHOWMAXIMIZED);
}

int32 SOY_windowIsFocused(soyWindow window) {
  return (window == GetFocus());
}

int32 SOY_dialogBox(soyWindow hwnd, int8* title, int8* content) {
  if(MessageBoxA(hwnd, title, content, MB_OKCANCEL) == IDOK) {
    DestroyWindow(hwnd);
    return TRUE;
  } else {
    return FALSE;
  }
  return TRUE;
}

int32 SOY_setMouseCursor(int32 x, int32 y) {
  return SetCursorPos(x, y);
}

/* win32 is retarded */
int32 SOY_showMouseCursor(int32 show) {
  int32 cret = show ? -1 : 1;
  if(show) {
    while(cret < 0) { cret = ShowCursor(TRUE); }
  } else {
    while(cret >= 0) { cret = ShowCursor(FALSE); }
  }
  return cret;
}

uint32 g_timerID = 1;
uint32 g_timerSet = 0;

LRESULT CALLBACK internal_SOY_eventCallback(
	HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  RECT wndRect;
#if 0
  PAINTSTRUCT ps;
#endif
  int32 htMx = 0;
  int32 htMy = 0;
  int32 mmX = 0;
  int32 mmY = 0;
  int32 scaledBtnPad = 0;
  int32 scaledBorder = 4;
  int32 scaledTitle = 18;
  switch(msg){
    case(WM_LBUTTONDOWN): {
      SOY_mouseCallback(hwnd, SOY_MOUSE_LEFT, 1); return 0; }
    case(WM_MBUTTONDOWN): {
      SOY_mouseCallback(hwnd, SOY_MOUSE_MIDDLE, 1); return 0; }
    case(WM_RBUTTONDOWN): {
      SOY_mouseCallback(hwnd, SOY_MOUSE_RIGHT, 1); return 0; }
    case(WM_LBUTTONUP): {
      SOY_mouseCallback(hwnd, SOY_MOUSE_LEFT, 0); return 0; }
    case(WM_MBUTTONUP): {
      SOY_mouseCallback(hwnd, SOY_MOUSE_MIDDLE, 0); return 0; }
    case(WM_RBUTTONUP): {
      SOY_mouseCallback(hwnd, SOY_MOUSE_RIGHT, 0); return 0; }
    case(WM_CREATE): {
      SOY_windowCreateCallback(hwnd);
      return 0;
    }

    case(WM_KILLFOCUS): {
      SOY_focusCallback(hwnd, FALSE);
      return 0;
    }

    case(WM_SETFOCUS): {
      SOY_focusCallback(hwnd, TRUE);
      return 0;
    }

#if 0
    case(WM_PAINT): {
      BeginPaint(hwnd, &ps);
      SOY_paintCallback(hwnd);
      EndPaint(hwnd, &ps);
      return 0;
    }
#endif
    case(WM_CHAR): {
      SOY_charCallback(hwnd, (uint8)wParam);
      return 0;
    }
    case(WM_KEYDOWN): {
      SOY_keyCallback(hwnd, (int32)wParam, LOBYTE(HIWORD(lParam)), 1);
      return 0;
    }
    case(WM_KEYUP): {
      SOY_keyCallback(hwnd, (int32)wParam, LOBYTE(HIWORD(lParam)), 0);
      return 0;
    }
    case(WM_SYSKEYDOWN): {
      SOY_keyCallback(hwnd, (int32)wParam, LOBYTE(HIWORD(lParam)), 1);
      return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    case(WM_SYSKEYUP): {
      SOY_keyCallback(hwnd, (int32)wParam, LOBYTE(HIWORD(lParam)), 0);
      return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    case(WM_MOUSEMOVE): {
      SOY_mouseMoveCallback(
          hwnd, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
      return 0;
    }
    case(WM_MOUSEWHEEL): {
      SOY_mouseScrollCallback(hwnd, GET_WHEEL_DELTA_WPARAM(wParam));
      return 0;
    }
    case(WM_GETMINMAXINFO): {
        SOY_minMaxCallback(hwnd, &mmX, &mmY);
        ((MINMAXINFO*)lParam)->ptMinTrackSize.x = mmX;
        ((MINMAXINFO*)lParam)->ptMinTrackSize.y = mmY;
      return 0;
    }
#if 1
    case(WM_ERASEBKGND): {
      SOY_paintCallback(hwnd);
      return 0;
    }
#endif
    case(WM_SIZING): {
      GetWindowRect(hwnd, &wndRect);
      SOY_resizeCallback(hwnd,
          wndRect.left,
          wndRect.top,
          wndRect.right - wndRect.left,
          wndRect.bottom - wndRect.top);
      return 0;
    }

    case(WM_MOVING): {
      GetWindowRect(hwnd, &wndRect);
      SOY_resizeCallback(hwnd,
          wndRect.left,
          wndRect.top,
          wndRect.right - wndRect.left,
          wndRect.bottom - wndRect.top);
      return 0;
    }

#if 1
    case(WM_ENTERSIZEMOVE): {
      if(!g_timerSet) {
        SetTimer(hwnd, g_timerID, 1, NULL);
        g_timerSet = 1;
      }
      return 0;
    }

    case(WM_EXITSIZEMOVE): {
      KillTimer(hwnd, g_timerID);
      g_timerSet = 0;
      return 0;
    }
#endif

    case(WM_TIMER): {
      SOY_paintCallback(hwnd);
      return 0;
    }

    case(WM_MOUSEACTIVATE): {
        SOY_focusCallback(hwnd, TRUE);
        SOY_paintCallback(hwnd);
        return 0;
    }

    case(WM_NCHITTEST): {
      GetWindowRect(hwnd, &wndRect);
      htMx = GET_X_LPARAM(lParam)-wndRect.left;
	  htMy = GET_Y_LPARAM(lParam)-wndRect.top;
      if(!SOY_hitTestCallback(
        hwnd, &scaledTitle, &scaledBorder, &scaledBtnPad)) {
        return HTCLIENT;
      }
      if(htMx >= 0 &&
          htMx <= wndRect.right - wndRect.left - scaledBtnPad &&
		  htMy > 0 && htMy <= scaledTitle) {
        return HTCAPTION;
	  } else if (htMx >= wndRect.right - wndRect.left - scaledBorder*2 &&
		  htMy >= wndRect.bottom - wndRect.top - scaledBorder*2) {
		return HTBOTTOMRIGHT;
	  } else if (htMx >= wndRect.right - wndRect.left - scaledBorder) {
        return HTRIGHT;
	  } else if (htMy >= wndRect.bottom - wndRect.top - scaledBorder) {
		return HTBOTTOM;
	  } else {
        return HTCLIENT;
	  }
    }

    case(WM_DESTROY): {
      SOY_windowCloseCallback(hwnd);
      PostQuitMessage(0);
      return 0;
    }
    case(WM_CLOSE): {
      if(MessageBoxA(hwnd, "Really quit?", ":(", MB_OKCANCEL) == IDOK) {
        DestroyWindow(hwnd);
        return 0;
      } else {
        return 0;
      }
    }
    default: {
      return DefWindowProc(hwnd, msg, wParam, lParam);
    }
  }
}

int16 SOY_getKeyState(soyWindow window, soyKeyCode key) {
  if(window == GetForegroundWindow()) {
    return GetAsyncKeyState(key);
  } else {
    return 0;
  }
}

int32 SOY_getMouseScreenX(void) {
  POINT point;
  GetCursorPos(&point);
  return point.x;
}

int32 SOY_getMouseScreenY(void) {
  POINT point;
  GetCursorPos(&point);
  return point.y;
}

int32 SOY_sleep(int32 miliseconds) {
  Sleep(miliseconds);
  return TRUE;
}

int32 SOY_windowMaximize(soyWindow window) {
  RECT rect;
  ShowWindow(window, SW_MAXIMIZE);
  GetWindowRect(window, &rect);
  SOY_resizeCallback(window,
      rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
  return TRUE;
}

int32 SOY_windowRestore(soyWindow window) {
  RECT rect;
  ShowWindow(window, SW_RESTORE);
  GetWindowRect(window, &rect);
  SOY_resizeCallback(window,
      rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
  return TRUE;
}

int32 SOY_windowMinimize(soyWindow window) {
  ShowWindow(window, SW_MINIMIZE);
  return TRUE;
}

int32 SOY_windowHide(soyWindow window) {
  ShowWindow(window, SW_HIDE);
  return TRUE;
}

int32 SOY_windowShow(soyWindow window) {
  ShowWindow(window, SW_SHOW);
  return TRUE;
}

int32 SOY_windowBlit(
    soyWindow window, uint8* buffer, int32 srcWidth, int32 srcHeight) {
  RECT wRect;
  BITMAPINFO bitmapInfo;
  bitmapInfo.bmiHeader.biSize = sizeof(bitmapInfo.bmiHeader);
  bitmapInfo.bmiHeader.biWidth = srcWidth;
  bitmapInfo.bmiHeader.biHeight = -srcHeight;
  bitmapInfo.bmiHeader.biPlanes = 1;
  bitmapInfo.bmiHeader.biBitCount = 32;
  bitmapInfo.bmiHeader.biCompression = BI_RGB;
  if(!GetWindowRect(window, &wRect)) {
    SOY_LOG1("GetWindowRect error: %ld\n", GetLastError());
  }
  if(StretchDIBits(
      SOY_getDeviceContext(window),
      0, 0,
      wRect.right - wRect.left, wRect.bottom - wRect.top,
	  0, 0,
      srcWidth, srcHeight,
      buffer, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY) != 0) {
    return TRUE;
  } else {

    SOY_LOG1("StretchDIBits error: %ld\n", GetLastError());
    SOY_LOG3("srcW: %d srcH: %d biSize: %d\n",
        srcWidth, srcHeight, (int32)sizeof(bitmapInfo.bmiHeader));
    SOY_LOG4("wL: %d wR: %d wT: %d wB: %d\n",
        (int32)wRect.left, (int32)wRect.right,
        (int32)wRect.top, (int32)wRect.bottom);
    return FALSE;
  }
}

int32 SOY_getKeyboardState(uint8* keyArray256) {
  return GetKeyboardState(keyArray256);
}

SOY_GLOBAL uint8 g_soyKeyboardStateForAscii[256];

int32 SOY_keyToASCII(
    int32 keyCode, int32 scanCode) {
  WORD outBuf[8];
  int32 keys = 0;
  int32 ret = GetKeyboardState(g_soyKeyboardStateForAscii);
  if (ret) {
    keys = ToAscii(keyCode, scanCode, g_soyKeyboardStateForAscii, outBuf, 0);
  }
  if(keys == 1 || keys == 2) {
    return (int32)outBuf[0]; } else { return -1; }
}

int32 SOY_screenWidth(void) {
  return GetSystemMetrics((SM_CXSCREEN));
}

int32 SOY_screenHeight(void) {
  return GetSystemMetrics((SM_CYSCREEN));
}

int32 SOY_windowX(soyWindow window) {
  RECT rect;
  GetWindowRect(window, &rect);
  return rect.left;
}

int32 SOY_windowY(soyWindow window) {
  RECT rect;
  GetWindowRect(window, &rect);
  return rect.top;
}

int32 SOY_windowWidth(soyWindow window) {
  RECT rect;
  GetWindowRect(window, &rect);
  return rect.right - rect.left;
}

int32 SOY_windowHeight(soyWindow window) {
  RECT rect;
  GetWindowRect(window, &rect);
  return rect.bottom - rect.top;
}

int32 SOY_setWindowPos(soyWindow window,
    int32 x, int32 y, int32 w, int32 h) {
  return SetWindowPos(window, HWND_TOP, x, y, w, h, SWP_SHOWWINDOW);
}

int64 SOY_wallClock(void) {
  int64 ret;
  QueryPerformanceCounter((LARGE_INTEGER*)&ret);
  return ret;
}

real64 SOY_wallClockDelta(int64 begin, int64 end) {
  LARGE_INTEGER qpFreq;
  QueryPerformanceFrequency(&qpFreq);
  return (real64)(end - begin) / (real64)qpFreq.QuadPart;
}

void* SOY_memoryAllocate(size_t size) {
  return VirtualAlloc(
      NULL,
      size,
      MEM_RESERVE | MEM_COMMIT,
      PAGE_READWRITE);
}

int32 SOY_memoryFree(void* memory) {
  return VirtualFree(memory, 0, MEM_RELEASE);
}

void* SOY_libraryLoad(char* name) {
  void* hInst = LoadLibraryA(name);
  if(!hInst) {
    SOY_LOG1("Error loading library: %s\n", name);
    return NULL;
  }
  return hInst;
}

int32 SOY_libraryFree(void* hInst) {
  return FreeLibrary(hInst);
}

PFUSERVOIDPROC SOY_libraryLoadFunction(void* hInst, char* name) {
  return (PFUSERVOIDPROC)GetProcAddress(hInst, name);
}

uint64 SOY_cycleCount(void) {
  return __rdtsc();
}

#ifdef SOY_LEGACY_AUDIO
#define SOY_DIRECT_SOUND_CREATE(name) \
HRESULT WINAPI name(              \
    LPCGUID pcGuidDevice,         \
    LPDIRECTSOUND* ppDS,          \
    LPUNKNOWN pUnkOuter)
typedef SOY_DIRECT_SOUND_CREATE(direct_sound_create);

int32 SOY_audioCreate(soyWindow window, soyPlatformData* pd,
    int32 samplesPerSecond, int32 bitRate, int32 bufferSize) {
  /* load direct sound library */
  DSBUFFERDESC bufferDescPrim;
  DSBUFFERDESC bufferDescSec;
  LPDIRECTSOUNDBUFFER primaryBuffer;
  LPDIRECTSOUND dSound;
  WAVEFORMATEX waveFormat;
  HMODULE dsLib = LoadLibraryA("dsound.dll");
  LPDIRECTSOUNDBUFFER soundBufferRes = NULL;
  LPDIRECTSOUND dSoundRes = NULL;
  SOY_LOG("Initializing audio playback\n");
  if(!dsLib) {
    return FALSE; }
  if(!samplesPerSecond || !bitRate || !bufferSize) {
    SOY_LOG("Invalid audio params\n");
  }
  if(dsLib) {
    /* get direct sound object */
    direct_sound_create* DirectSoundCreate =
      (direct_sound_create*)
      GetProcAddress(dsLib, "DirectSoundCreate");
    if(DirectSoundCreate &&
        SUCCEEDED(DirectSoundCreate(0, &dSound, 0))) {
          waveFormat.wFormatTag = WAVE_FORMAT_PCM;
          waveFormat.nChannels = 2;
          waveFormat.nSamplesPerSec = samplesPerSecond;
          waveFormat.wBitsPerSample = (int16)bitRate;
          waveFormat.nBlockAlign =
            (waveFormat.nChannels*waveFormat.wBitsPerSample)/8;
          waveFormat.nAvgBytesPerSec =
            waveFormat.nSamplesPerSec*waveFormat.nBlockAlign;
          waveFormat.cbSize = 0;
      if(SUCCEEDED(
            dSound->lpVtbl->SetCooperativeLevel(
              dSound,
              window,
              DSSCL_PRIORITY
              ))) {
        ZeroMemory(&bufferDescPrim, sizeof(bufferDescPrim));
        bufferDescPrim.dwSize = sizeof(bufferDescPrim);
        bufferDescPrim.dwFlags = DSBCAPS_PRIMARYBUFFER;
        /* create primary buffer */
        if(SUCCEEDED(
              dSound->lpVtbl->CreateSoundBuffer(
                dSound,
                &bufferDescPrim,
                &primaryBuffer,
                0
                ))) {
          dSoundRes = dSound;
          if(SUCCEEDED(
                primaryBuffer->lpVtbl->SetFormat(
                  primaryBuffer,
                  &waveFormat
                  ))) {
          } else {
            printf("Direct Sound Error - set primary buffer format\n");
          }
        } else {
          printf("Direct Sound Error - create primary buffer\n");
        }
      } else {
        printf("Direct Sound Error - set cooperative level\n");
      }

      /* create secondary buffer */
      ZeroMemory(&bufferDescSec, sizeof(bufferDescSec));
      bufferDescSec.dwSize = sizeof(bufferDescSec);
      bufferDescSec.dwFlags = DSBCAPS_GLOBALFOCUS;
      bufferDescSec.dwBufferBytes = bufferSize;
      bufferDescSec.lpwfxFormat = &waveFormat;
      if(SUCCEEDED(
            dSound->lpVtbl->CreateSoundBuffer(
              dSound,
              &bufferDescSec,
              &soundBufferRes,
              0))) {
      }
    } else {
      printf("Direct Sound Error - dsound create\n");
    }
  } else {
    printf("Direct Sound Error - no dslib\n");
  }
  pd->soundLatencySamples = samplesPerSecond / 30;
  pd->soundBufferIndex = 0;
  pd->audioBuffer = soundBufferRes;
  pd->audioHandle = dSoundRes;
  return TRUE;
}

#define SOY_DIRECT_SOUND_DUPLEX_CREATE(name) \
HRESULT WINAPI name(              \
    LPCGUID pcGuidCaptureDevice,         \
    LPCGUID pcGuidRenderDevice,         \
    LPCDSCBUFFERDESC pcDSCBufferDesc, \
    LPCDSBUFFERDESC pcDSBufferDesc, \
    HWND hWnd, \
    DWORD dwLevel, \
    LPDIRECTSOUNDFULLDUPLEX* ppDSFD, \
    LPDIRECTSOUNDCAPTUREBUFFER* ppDSCBuffer, \
    LPDIRECTSOUNDBUFFER* ppDSBuffe, \
    LPUNKNOWN pUnkOuter)

typedef SOY_DIRECT_SOUND_DUPLEX_CREATE(direct_sound_duplex_create);

#if 0
SOY_GLOBAL LPGUID g_audioCaptureGUID = 0;
SOY_GLOBAL LPGUID g_audioRenderGUID = 0;
#endif

BOOL CALLBACK DSEnumCallback(
         LPGUID lpGuid,
         LPCSTR lpcstrDescription,
         LPCSTR lpcstrModule,
         LPVOID lpContext
    ) {
  SOY_UNUSED(lpGuid);
  SOY_UNUSED(lpcstrModule);
  SOY_UNUSED(lpContext);
  SOY_LOG1("Device found: %s\n", lpcstrDescription);
  return TRUE;
}

int32 SOY_audioCreateFullDuplex(soyWindow window, soyPlatformData* pd,
    int32 samplesPerSecond, int32 bitRate, int32 bufferSize) {
  WAVEFORMATEX waveFormat;
  DSCBUFFERDESC bufferDescCapture;
  DSBUFFERDESC bufferDescSec;
  HMODULE dsLib = LoadLibraryA("dsound.dll");
  direct_sound_duplex_create* DirectSoundDuplexCreate;
  SOY_LOG("Initializing audio playback\n");
  if(!dsLib) { return FALSE; }
  if(!samplesPerSecond || !bitRate || !bufferSize) {
    SOY_LOG("Invalid audio params\n");
  }
  /* get direct sound object */
  DirectSoundDuplexCreate =
    (direct_sound_duplex_create*)
    GetProcAddress(dsLib, "DirectSoundFullDuplexCreate");
  SOY_LOG("Capture devices: \n");
  DirectSoundCaptureEnumerate(DSEnumCallback, NULL);
  SOY_LOG("Playback devices: \n");
  DirectSoundEnumerate(DSEnumCallback, NULL);
  SOY_LOG("Using default capture device\n");
  SOY_LOG("Using default playback device\n");
  waveFormat.wFormatTag = WAVE_FORMAT_PCM;
  waveFormat.nChannels = 2;
  waveFormat.nSamplesPerSec = samplesPerSecond;
  waveFormat.wBitsPerSample = (int16)bitRate;
  waveFormat.nBlockAlign =
    (waveFormat.nChannels*waveFormat.wBitsPerSample)/8;
  waveFormat.nAvgBytesPerSec =
  waveFormat.nSamplesPerSec*waveFormat.nBlockAlign;
  waveFormat.cbSize = 0;

  ZeroMemory(&bufferDescSec, sizeof(bufferDescSec));
  bufferDescSec.dwSize = sizeof(bufferDescSec);
  bufferDescSec.dwFlags = DSBCAPS_GLOBALFOCUS;
  bufferDescSec.dwBufferBytes = bufferSize;
  bufferDescSec.lpwfxFormat = &waveFormat;

  ZeroMemory(&bufferDescCapture, sizeof(bufferDescCapture));
  bufferDescCapture.dwSize = sizeof(bufferDescCapture);
  bufferDescCapture.dwFlags = 0;
  bufferDescCapture.dwBufferBytes = bufferSize;
  bufferDescCapture.lpwfxFormat = &waveFormat;
  bufferDescCapture.dwFXCount = 0;
  bufferDescCapture.lpDSCFXDesc = NULL;

  if(!DirectSoundDuplexCreate) {
    SOY_LOG("Error, create proc not found\n");
  }

  if(DirectSoundDuplexCreate &&
    SUCCEEDED(DirectSoundDuplexCreate(
        NULL,
        NULL,
        &bufferDescCapture,
        &bufferDescSec,
        window,
        DSSCL_PRIORITY,
        &pd->audioHandleDuplex,
        &pd->audioCaptureBuffer,
        &pd->audioBuffer,
        0))) {
    SOY_LOG("Created full duplex audio\n");
  } else {
    SOY_LOG("Error creating full duplex audio\n");
  }
  return TRUE;
}

int32 SOY_audioBufferPlay(soyPlatformData* pd) {
  LPDIRECTSOUNDBUFFER sb = pd->audioBuffer;
  return sb->lpVtbl->Play(sb, 0, 0, DSBPLAY_LOOPING);
}

int32 SOY_audioBufferStop(soyPlatformData* pd) {
  LPDIRECTSOUNDBUFFER sb = pd->audioBuffer;
  return sb->lpVtbl->Stop(sb);
}

int32 SOY_audioBufferCaptureStart(soyPlatformData* pd) {
  LPDIRECTSOUNDCAPTUREBUFFER sb = pd->audioCaptureBuffer;
  return sb->lpVtbl->Start(sb, DSCBSTART_LOOPING);
}

int32 SOY_audioBufferCaptureStop(soyPlatformData* pd) {
  LPDIRECTSOUNDCAPTUREBUFFER sb = pd->audioCaptureBuffer;
  return sb->lpVtbl->Stop(sb);
}

int32 SOY_audioFillBuffer(soyPlatformData* pd,
    int32 bytesPerSample, int32 byteToLock, int32 bytesToWrite,
    PFAUDIOSAMPLE sampleFunc, void* args) {
  void* region1;
  DWORD region1Size;
  DWORD region2SampleCnt;
  void* region2;
  DWORD region2Size;
  DWORD region1SampleCnt;
  DWORD sampleIndex;
  int16* sampleOut;
  soySampleResult sr;
  if(!sampleFunc) { return FALSE; }
  if(SUCCEEDED(
          pd->audioBuffer->lpVtbl->Lock(
          pd->audioBuffer,
          byteToLock, bytesToWrite,
          &region1, &region1Size,
          &region2, &region2Size,
          0))) {
    region1SampleCnt = region1Size/bytesPerSample;
    sampleOut = (int16*)region1;
    for(sampleIndex = 0;
        sampleIndex < region1SampleCnt;
        ++sampleIndex) {
      sr = sampleFunc(args);
      pd->soundBufferIndex++;
      *sampleOut++ = sr.left;
      *sampleOut++ = sr.right;
    }
    region2SampleCnt = region2Size/bytesPerSample;
    sampleOut = (int16*)region2;
    for(sampleIndex = 0;
        sampleIndex < region2SampleCnt;
        ++sampleIndex) {
      sr = sampleFunc(args);
      pd->soundBufferIndex++;
      *sampleOut++ = sr.left;
      *sampleOut++ = sr.right;
    }
    pd->audioBuffer->lpVtbl->Unlock(
        pd->audioBuffer,
        region1,
        region1Size,
        region2,
        region2Size);
  }
  return TRUE;
}

int32 SOY_audioUpdateBuffer(soyPlatformData* pd,
    int32 bytesPerSample, int32 bufferSize,
    PFAUDIOSAMPLE sampleFunc, void* args) {
  DWORD byteToLock = 0;
  DWORD bytesToWrite = 0;
  DWORD playCursor = 0;
  DWORD writeCursor = 0;
  DWORD targetCursor = 0;
  if(SUCCEEDED(
      pd->audioBuffer->lpVtbl->GetCurrentPosition(
      pd->audioBuffer,
      &playCursor,
      &writeCursor
      ))) {
    byteToLock =
      ((pd->soundBufferIndex * bytesPerSample)) % bufferSize;

    targetCursor =
      (playCursor + (pd->soundLatencySamples * bytesPerSample)) % bufferSize;

    if(byteToLock > targetCursor) {
      bytesToWrite = (bufferSize - byteToLock);
      bytesToWrite += targetCursor;
    } else {
      bytesToWrite = targetCursor - byteToLock;
    }

    SOY_audioFillBuffer(pd,
        bytesPerSample,
        byteToLock,
        bytesToWrite,
        sampleFunc,
        args);
  }
  return TRUE;
}

int32 SOY_audioFillCaptureBuffer(soyPlatformData* pd,
    int32 bytesPerSample, int32 byteToLock, int32 bytesToWrite,
    PFAUDIOCAPTURE sampleFunc, void* args) {
  void* region1;
  DWORD region1Size;
  DWORD region2SampleCnt;
  void* region2;
  DWORD region2Size;
  DWORD region1SampleCnt;
  DWORD sampleIndex;
  int16* sampleOut;
  int16 sampleL, sampleR;
  if(!sampleFunc) { return FALSE; }
  if(SUCCEEDED(
          pd->audioCaptureBuffer->lpVtbl->Lock(
          pd->audioCaptureBuffer,
          byteToLock, bytesToWrite,
          &region1, &region1Size,
          &region2, &region2Size,
          0))) {
    region1SampleCnt = region1Size/bytesPerSample;
    sampleOut = (int16*)region1;
    for(sampleIndex = 0;
        sampleIndex < region1SampleCnt;
        ++sampleIndex) {
      sampleL = *sampleOut++;
      sampleR = *sampleOut++;
      sampleFunc(args, sampleL, sampleR);
      pd->soundCaptureBufferIndex++;
    }
    region2SampleCnt = region2Size/bytesPerSample;
    sampleOut = (int16*)region2;
    for(sampleIndex = 0;
        sampleIndex < region2SampleCnt;
        ++sampleIndex) {
      sampleL = *sampleOut++;
      sampleR = *sampleOut++;
      sampleFunc(args, sampleL, sampleR);
      pd->soundCaptureBufferIndex++;
    }
    pd->audioCaptureBuffer->lpVtbl->Unlock(
        pd->audioCaptureBuffer,
        region1,
        region1Size,
        region2,
        region2Size);
  }
  return TRUE;
}

int32 SOY_audioUpdateCaptureBuffer(soyPlatformData* pd,
    int32 bytesPerSample, int32 bufferSize,
    PFAUDIOCAPTURE sampleFunc, void* args) {
  DWORD byteToLock = 0;
  DWORD bytesToWrite = 0;
  DWORD readCursor = 0;
  DWORD targetCursor = 0;

  if(SUCCEEDED(
      pd->audioCaptureBuffer->lpVtbl->GetCurrentPosition(
      pd->audioCaptureBuffer,
      NULL,
      &readCursor
      ))) {

    byteToLock =
      ((pd->soundCaptureBufferIndex * bytesPerSample)) % bufferSize;

    targetCursor =
      (readCursor);

    if(byteToLock > targetCursor) {
      bytesToWrite = (bufferSize - byteToLock);
      bytesToWrite += targetCursor;
    } else {
      bytesToWrite = targetCursor - byteToLock;
    }

    SOY_audioFillCaptureBuffer(pd,
        bytesPerSample,
        byteToLock,
        bytesToWrite,
        sampleFunc,
        args);
  }

  return TRUE;
}


#endif /* SOY_LEGACY_AUDIO */

#endif /* SOY_WIN32 */

/*=========================================================================*/
/* PLATFORM LINUX                                                          */
/*=========================================================================*/

#ifdef SOY_LINUX

#endif /* SOY_LINUX */

/*=========================================================================*/
/* USER LAYER                                                              */
/*=========================================================================*/

/*
* o-------------------------------------------o
* | @utility                                  |
* o-------------------------------------------o
*/

SOY_GLOBAL int32 g_soyIsLittleEndian = TRUE;

#define SOY_MAX_VERSION_STRING 256

SOY_GLOBAL int8 g_versionStringBuffer[SOY_MAX_VERSION_STRING];

int8* SOY_getVersionString(int8* title, int32 rel, int32 min, int32 maj) {
  snprintf(g_versionStringBuffer, SOY_MAX_VERSION_STRING,
      "%s %d.%d.%d", title, rel, min, maj);
  return g_versionStringBuffer;
}

int32 SOY_checkEndian(void) {
  int32 n = 1;
  if(*(int8*)&n == 1) {
    g_soyIsLittleEndian = TRUE;
    return TRUE;
  } else {
    g_soyIsLittleEndian = FALSE;
    return FALSE;
  }
}

uint32 SOY_toBigEndianUint32(uint8* mem) {
  uint32 i;
  uint32 result = 0;
  for(i = 0; i < 4; i++) {
    result <<= 8;
    result |= *(mem + i);
  }
  return result;
}

uint16 SOY_toBigEndianUint16(uint8* mem) {
  uint16 i;
  uint32 result = 0;
  for(i = 0; i < 2; i++) {
    result <<= 8;
    result |= *(mem + i);
  }
  return (uint16)result;
}

#define SOY_abs(a) (((a) ^ ((a) >> 31)) + (((a) >> 31) & 1))

#define SOY_fabs(a) (real32)(((a) < 0.0) ? ((a)*-1.0) : (a))

#define SOY_dot2(g, x, y) \
  ((real64)g[0]*(x)+(real64)g[1]*(y))

#define SOY_dot3(g, x, y, z) \
  ((real64)g[0]*(x)+(real64)g[1]*(y)+(real64)g[2]*(z))

#define SOY_dot4(g, x, y, z, w) \
  ((real64)g[0]*(x)+(real64)g[1]*(y)+(real64)g[2]*(z)+(real64)g[3]*(w))

#define SOY_dot2A(ax, ay, x, y) \
  ((real64)(ax)*(x)+(real64)(ay)*(y))

#define SOY_dot3A(ax, ay, az, x, y, z) \
  ((real64)(ax)*(x)+(real64)(ay)*(y)+(real64)(az)*(z))

#define SOY_dot4A(ax, ay, az, aw, x, y, z, w) \
  ((real64)(ax)*(x)+(real64)(ay)*(y)+(real64)(az)*(z)+(real64)(aw)*(w))

#define SOY_mix(a, b, t) (((1.0 - (t))*(a)) + (t)*(b))

#define SOY_4cc(str)        \
  ((uint32)(str[0] << 0) |  \
   (uint32)(str[1] << 8) |  \
   (uint32)(str[2] << 16) | \
   (uint32)(str[3] << 24))

#define SOY_inBounds(x, y, x1, y1, x2, y2) \
  (((x) > (x1) && (x) < (x2) && (y) > (y1) && (y) < (y2)))

#define SOY_sinc(x) (sin(SOY_PI*x)/(SOY_PI*x))


#define SOY_worldToScreen(worldCoord, offset, scale) \
  ((int32)((((worldCoord) - (offset)) * (scale))))

#define SOY_screenToWorld(screenCoord, offset, scale) \
  ((((real32)(screenCoord) / (scale) + (offset))))

#define SOY_sign(x) ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))

real32 SOY_intBounds(real32 s, real32 ds) {
  return (ds > 0 ? ceil(s) - s : s -floor(s)) / fabs(ds);
}

#define SOY_clamp(x, min, max) SOY_MIN(SOY_MAX((x), (min)), (max))

#define SOY_wrap(x, max) ((((x)%(max)) + (max))%max)

#define SOY_orientQuadF(a, b, c, d) (fabs((b) - (c)) >= fabs((a) - (d)))
#define SOY_orientQuad(a, b, c, d) (abs((b) - (c)) >= abs((a) - (d)))

/*
* o-------------------------------------------o
* | @memory                                   |
* o-------------------------------------------o
*/

typedef struct tag_soyMemorySector {
  uint8* base;
  size_t offset;
  size_t size;
  int8* label;
} soyMemorySector;

SOY_GLOBAL int32 g_soyAllocationCounter = 0;

void* SOY_memoryCopy(void* dest, void* src, size_t size) {
  return memcpy(dest, src, size);
}

void* SOY_memorySet(void* dest, int32 value, size_t size) {
  return memset(dest, value, size);
}

int32 SOY_memorySectorCreate(int8* label, soyMemorySector* sector,
    size_t size) {
  sector->base = SOY_memoryAllocate(size);
  sector->label = label;
  if(sector->base != NULL) {
    sector->offset = 0;
    sector->size = size;
    g_soyAllocationCounter++;
  } else {
    SOY_LOG("Error allocating memory sector\n");
    return -1;
  }
  if(size / 1024 < 1024) {
    SOY_LOG4("Allocated memory \"%s\" at [%p] [%dkb] "
             "Allocation counter: [%d]\n",
        label, sector->base, (uint32)(size / 1024), g_soyAllocationCounter);
  } else {
    SOY_LOG4("Allocated memory \"%s\" at [%p] [%.2fmb] "
             "Allocation counter: [%d]\n",
        label, sector->base,
        ((real32)size / 1024.0f / 1024.0f),
        g_soyAllocationCounter);
  }

  return TRUE;
}

int32 SOY_memorySectorFree(soyMemorySector* sector) {
  if(SOY_memoryFree(sector->base)) {
    sector->offset = 0;
    sector->size = 0;
    g_soyAllocationCounter--;
  } else {
    SOY_LOG("Error freeing memory sector\n");
    return -1;
  }
  SOY_LOG2("Freed memory at [%p] Allocation counter: [%d]\n",
      sector->base, g_soyAllocationCounter);
  return TRUE;
}

int32 SOY_memorySectorPartition(int8* label,
    soyMemorySector* src, soyMemorySector* dest,
    size_t size) {
  SOY_ASSERT((size_t)src->offset + size < (size_t)src->size);
  dest->base = src->base + src->offset;
  dest->offset = 0;
  dest->size = size;
  src->offset += size;
  
  if(size / 1024 < 1024) {
    SOY_LOG4("Partitioned memory \"%s\" at [%p] [%dkb][%.1f%%]\n",
        label, dest->base, (uint32)(dest->size / 1024),
        (((real32)src->offset)/((real32)src->size))*100.0f);
  } else {
    SOY_LOG4("Partitioned memory \"%s\" at [%p] [%.2fmb][%.1f%%]\n",
        label, dest->base, ((real32)dest->size / 1024.0f / 1024.0f), 
        (((real32)src->offset)/((real32)src->size))*100.0f);
  }
  return TRUE;
}

void* SOY_memorySectorReset(soyMemorySector* src) {
  src->offset = 0;
  return SOY_memorySet(src->base, 0, src->size);
}

int32 SOY_memoryAdvance(uint32* offset, uint32 amt, uint32 max) {
  if((*offset) + (amt) <= (max)) {
    ((*offset) += amt);
  } else {
    SOY_ASSERT(!"Memory max reached\n");
  }
  return TRUE;
}

/*
* o-------------------------------------------o
* | @io                                       |
* o-------------------------------------------o
*/

void* SOY_fileOpen(int8* file, int8* args) {
  void* ret = fopen(file, args);
  if(!ret) {
#if 0
    SOY_LOG1("Error opening file: %s\n", file);
    SOY_LOG_ERROR();
#endif
  }
  return ret;
}

int32 SOY_fileClose(void* file) {
  if(!file) {
    SOY_LOG("Error closing file\n");
    SOY_LOG_ERROR();
  }
  return fclose((FILE*)file);
}

size_t SOY_fileSize(void* file) {
  size_t size = 0;
  if(!file) {
#if 0
    SOY_LOG("Error getting file size - handle was NULL\n");
#endif
    return 0;
  }
  fseek((FILE*)file, 0, SEEK_END);
  size = ftell((FILE*)file);
  fseek((FILE*)file, 0, SEEK_SET);
  return size;
}

size_t SOY_fileToMemory(soyMemorySector* sec, char* filename) {
  void* file = SOY_fileOpen(filename, "rb");
  size_t fileSize = SOY_fileSize(file);
  size_t elementsRead = 0;
  SOY_ASSERT(sec->base);
  SOY_ASSERT((size_t)sec->size > (size_t)fileSize + sec->offset);
  if(file) {
    elementsRead = fread(sec->base, fileSize, 1, (FILE*)file);
    if(elementsRead == 1) {
      SOY_fileClose(file);
      return fileSize;
    } else {
#if 0
      SOY_LOG1("Error reading file %s: wrong number of elements read\n",
          filename);
      SOY_LOG_ERROR();
#endif
      SOY_fileClose(file);
      return 0;
    }
  } else {
#if 0
    SOY_LOG1("Error reading file %s: handle was NULL\n",
        filename);
#endif
    return 0;
  }
}

size_t SOY_writeEntireFile(
    int8* buffer, size_t maxSize, void* file) {
  size_t ret = fwrite(buffer, maxSize, 1, (FILE*)file);
  if(!ret) {
#if 0
    SOY_LOG("Error writing file: wrong number of elements written\n");
    SOY_LOG_ERROR();
#endif
  }
  return ret;
}

/*
* o-------------------------------------------o
* | @string                                   |
* o-------------------------------------------o
*/

int32 SOY_stringFormat(int8* dest, int8* fmt, ...) {
  int32 printRet = 0;
  va_list args;
  va_start(args, fmt);
  printRet = vsnprintf(dest, SOY_MAX_STRING-1, fmt, args);
  va_end(args);
  if(printRet > SOY_MAX_STRING-2) {
    SOY_LOG("Error: string overflow\n");
    return -1;
  } else {
    return printRet;
  }
}

int32 SOY_stringLen(int8* str) {
  int32 index = 0;
  if(str == NULL) { return 0; }
  while(index < SOY_MAX_STRING && str[index] != '\0') {
	  index++;
  }
  if(index == SOY_MAX_STRING) {
	  index = 0;
  }
  return index;
}

int32 SOY_stringMatch(int8* strA, int8* strB) {
  int32 same = 0;
  int32 index = 0;
  int32 subIndex = 0;
  int32 lenA = SOY_stringLen(strA);
  int32 lenB = SOY_stringLen(strB);
  while(index < lenA) {
    same = 0;
    subIndex = 0;
    while(subIndex < lenB) {
      if(index+subIndex < lenA) {
        if(strA[index+subIndex] == strB[subIndex]) {
          same++;
        }
      }
      subIndex++;
    }
    if(same == lenB) { return TRUE; }
    index++;
  }
  return FALSE;
}

int32 SOY_stringCompare(int8* strA, int8* strB) {
  int32 index = 0;
  int32 dif = 0;
  int32 lenA = SOY_stringLen(strA);
  int32 lenB = SOY_stringLen(strB);
  if(strA == NULL || strB == NULL) { return FALSE; }
  if(lenA != lenB) { return FALSE; }
  if(strA[0] == 0 || strB[0] == 0) { return FALSE; }
  while(index < lenA) {
    if(strA[index] != strB[index]) {
      dif++;
    }
    index++;
  }
  return (!dif);
}

int32 SOY_stringCopy(
  int8* src, int8* dest, int32 startIndex, int32 bufSize) {
  int32 i;
  int32 lenOrig;
  lenOrig = SOY_stringLen(src);
  if(src == NULL || dest == NULL || startIndex >= lenOrig) {
	return FALSE;
  }
  i = startIndex;
  while(src[i] != '\0' && i-startIndex < bufSize-1) {
	dest[i-startIndex] = src[i];
	i++;
  }
  dest[i-startIndex] = '\0';
  return TRUE;
}

int32 SOY_stringCat(int8* src, int8* dest, int32 destSize) {
  int32 lenDest= 0;
  int32 lenSrc = 0;
  int32 index = 0;
  lenDest = SOY_stringLen(dest);
  lenSrc = SOY_stringLen(src);
  if(dest == NULL || src == NULL) { return 0; }
  if(lenDest+lenSrc < destSize) {
	for(index = 0; index < lenSrc; index++) {
	  dest[lenDest+index] = src[index];
	  }
	  dest[index] = '\0';
  } else {
	SOY_LOG("Error: Destination buffer too small\n");
	return FALSE;
  }
  return TRUE;
}

/*
* o-------------------------------------------o
* | @intrinsics                               |
* o-------------------------------------------o
*/

#define SOY_MM_shuffle(z, y, x, w) \
  (((z) << 6 ) | ((y) << 4) | ((x) << 2) | (w))

#define SOY_MM_real32x4Index(p, i) \
  SOY_MM_extractLow32x4( \
      SOY_MM_shuffleReal32x4(p, p, SOY_MM_shuffle(i, i, i, i)))

/*
* o-------------------------------------------o
* | @timing                                   |
* o-------------------------------------------o
*/

typedef struct tag_soyTimingData {
  soyPlatformData* platformData;
  int64 cyclesTimer;
  real64 cyclesDelta;
  real64 userCyclesDelta;
  int64 globalTimer;
  int64 globalTimerPrev;
  real64 globalDeltaMs;
  int32 missedFramesCounter;
} soyTimingData;

int32 SOY_initTimingData(soyTimingData* data, soyPlatformData* pd) {
  data->cyclesTimer = 0;
  data->cyclesDelta = 0.0f;
  data->userCyclesDelta = 0.0;
  data->globalTimer = 0;
  data->globalTimerPrev = 0;
  data->globalDeltaMs = 0.0f;
  data->missedFramesCounter = 0;
  data->platformData = pd;
  return TRUE;
}

int32 SOY_timingInit(soyTimingData* td, soyPlatformData* pd) {
  SOY_initTimingData(td, pd);
  td->globalTimer = SOY_wallClock();
#if 0
  SOY_setScheduler(pd, 1);
#endif
  return TRUE;
}

int32 SOY_timingFinalize(soyTimingData* td, soyPlatformData* pd) {
#if 0
  return SOY_resetScheduler(pd, 1);
#endif
  SOY_UNUSED(pd);
  SOY_UNUSED(td);
  return FALSE;
}

real64 SOY_cyclesDelta(int64 prevCycles, int64 curCycles) {
  return (real64)(curCycles - prevCycles) / 1000000.0;
}

int32 SOY_timingLock(soyTimingData* td, real64 monitorHz, int32 sleep) {
  real64 secondsPerFrame;
  real64 workDelta;
  uint64 workCounter;
  uint64 endCounter;
  uint32 sleepMs;
  real64 expectedFrames = 1.0;
  real64 targetTimestep = expectedFrames / monitorHz;
  workCounter = SOY_wallClock();
  workDelta = SOY_wallClockDelta(td->globalTimerPrev, workCounter);
  secondsPerFrame = workDelta;
  td->cyclesDelta = SOY_cyclesDelta(td->cyclesTimer, SOY_cycleCount());
  td->cyclesTimer = SOY_cycleCount();
  if(secondsPerFrame < targetTimestep) {
    if(td->platformData->schedulerValid) {
      sleepMs = (int32)(1000.0*(targetTimestep - secondsPerFrame));
      if(sleepMs > 0 && sleep) {
        SOY_sleep(sleepMs);
      }
    }
    while(secondsPerFrame < targetTimestep && sleep) {
      secondsPerFrame = SOY_wallClockDelta(
          td->globalTimerPrev, SOY_wallClock());
    }
  } else {
    /*
    SOY_LOG("[missed frame]\n");
    */
    td->missedFramesCounter++;
  }

  endCounter = SOY_wallClock();
  td->globalDeltaMs = SOY_wallClockDelta(
      td->globalTimerPrev, endCounter);
  td->globalTimerPrev = endCounter;
  return TRUE;
}

/*
* o-------------------------------------------o
* | @dynamic libs                             |
* o-------------------------------------------o
*/

#ifndef SOY_NO_DLL

typedef int32 (*PFUSERSTART) (soyApp* app);
typedef int32 (*PFUSERUPDATE) (soyApp* app, real64 delta);
typedef int32 (*PFUSERRENDER) (soyApp* app, real64 delta);
typedef int32 (*PFUSERSTOP) (soyApp* app);

typedef struct tag_soyModule {
  char* filepath;
  void* lib;
  uint64 filetime;
  PFUSERSTART constFunc;
  PFUSERUPDATE updateFunc;
  PFUSERRENDER renderFunc;
  PFUSERSTOP deleteFunc;
  int32 enabled;
} soyModule;

int32 SOY_moduleLoad(soyApp* app, soyModule* sm, char* name) {
  int8 srcStr[64];
  int8 destStr[64];
  sprintf(srcStr, "%s", name);
  sprintf(destStr, "temp_%s", name);
  SOY_fileCopy(srcStr, destStr);
  sm->lib = SOY_libraryLoad(destStr);
  SOY_LOG1("Loading library: %s\n", name);
  if(!sm->lib) {
    SOY_LOG1("Error loading library %s\n", destStr);
    sm->enabled = FALSE;
    return FALSE;
  }
  sm->constFunc =
    (PFUSERSTART)SOY_libraryLoadFunction(sm->lib, "SOY_libStart");
  if(!sm->constFunc) { SOY_LOG("Error getting start proc.\n"); }
  sm->renderFunc =
    (PFUSERRENDER)SOY_libraryLoadFunction(sm->lib, "SOY_libRender");
  if(!sm->renderFunc) { SOY_LOG("Error getting render proc.\n"); }
  sm->updateFunc =
    (PFUSERUPDATE)SOY_libraryLoadFunction(sm->lib, "SOY_libUpdate");
  if(!sm->updateFunc) { SOY_LOG("Error getting update proc.\n"); }
  sm->deleteFunc =
    (PFUSERSTOP)SOY_libraryLoadFunction(sm->lib, "SOY_libStop");
  if(!sm->deleteFunc) { SOY_LOG("Error getting stop proc.\n"); }
  sm->filepath = name;
  sm->enabled = TRUE;
  sm->filetime = SOY_lastWriteTime(srcStr);
  if(sm->constFunc &&
     sm->renderFunc &&
     sm->updateFunc &&
     sm->deleteFunc) {
    sm->constFunc(app);
    SOY_LOG1("Loaded library: %s\n", destStr);
    return TRUE;
  }
  SOY_LOG1("Error initializing module %s\n", name);
  return FALSE;
}

int32 SOY_moduleFree(soyApp* app, soyModule* sm) {
  if(sm->enabled == FALSE) { return FALSE; }
  if(sm->deleteFunc) {
    sm->deleteFunc(app);
  }
  SOY_libraryFree(sm->lib);
  sm->enabled = FALSE;
  return TRUE;
}

int32 SOY_moduleReload(soyApp* app, soyModule* mod) {
  if(SOY_lastWriteTime(mod->filepath) != mod->filetime && mod->enabled) {
    SOY_moduleFree(app, mod);
    SOY_moduleLoad(app, mod, mod->filepath);
  }
  return TRUE;
}

int32 SOY_moduleStart(soyApp* app, soyModule* mod) {
  if(mod->constFunc) {
    mod->constFunc(app);
    return TRUE;
  } else {
    return FALSE;
  }
}

int32 SOY_moduleStop(soyApp* app, soyModule* mod) {
  if(mod->deleteFunc) {
    mod->deleteFunc(app);
    return TRUE;
  } else {
    return FALSE;
  }
}

int32 SOY_moduleUpdate(soyApp* app, soyModule* mod, real64 delta) {
  if(mod->updateFunc) {
    return mod->updateFunc(app, delta);
  } else {
    return FALSE;
  }
}

int32 SOY_moduleRender(soyApp* app, soyModule* mod, real64 delta) {
  if(mod->renderFunc) {
    return mod->renderFunc(app, delta);
  } else {
    return FALSE;
  }
}

#endif /* SOY_NO_DLL */

/*=========================================================================*/
/* FULL LIB                                                                */
/*=========================================================================*/

#ifndef SOY_LIB_LEAN

/*
* o-------------------------------------------o
* | @math                                     |
* o-------------------------------------------o
*/



real32 SOY_expToLin(real32 x, real32 c, real32 s) {
  return (pow(SOY_MIN(SOY_MAX(x,0.0f),1.0f),c)+SOY_MAX(x,1.0f)*c-c)*s;
}


typedef struct tag_vec2i {
  int32 x;
  int32 y;
} vec2i;

vec2i SOY_vec2i(int32 a, int32 b) {
  vec2i ret;
  ret.x = a;
  ret.y = b;
  return ret;
}

typedef struct tag_vec2f {
  real32 x;
  real32 y;
} vec2f;

vec2f SOY_vec2f(real32 a, real32 b) {
  vec2f ret;
  ret.x = a;
  ret.y = b;
  return ret;
}

typedef struct tag_vec4i {
  int32 x;
  int32 y;
  int32 z;
  int32 w;
} vec4i;

vec4i SOY_vec4i(int32 a, int32 b, int32 c, int32 d) {
  vec4i ret;
  ret.x = a;
  ret.y = b;
  ret.z = c;
  ret.w = d;
  return ret;
}

typedef struct tag_vec3f {
  real32 x;
  real32 y;
  real32 z;
} vec3f;

vec3f SOY_vec3f(real32 a, real32 b, real32 c) {
  vec3f ret;
  ret.x = a;
  ret.y = b;
  ret.z = c;
  return ret;
}

typedef struct tag_vec4f {
  real32 x;
  real32 y;
  real32 z;
  real32 w;
} vec4f, soyQuaternion, soyQuat;

vec4f SOY_vec4f(real32 a, real32 b, real32 c, real32 d) {
  vec4f ret;
  ret.x = a;
  ret.y = b;
  ret.z = c;
  ret.w = d;
  return ret;
}

typedef struct tag_soyTriangle {
  vec4f v1, v2, v3;
  vec4f t1, t2, t3;
  vec4f n1, n2, n3;
  vec4f colour;
} soyTriangle;

soyTriangle SOY_triangle(
    real32 x1, real32 y1, real32 z1,
    real32 x2, real32 y2, real32 z2,
    real32 x3, real32 y3, real32 z3) {
  soyTriangle tri;
  tri.v1 = SOY_vec4f(x1, y1, z1, 1.0f);
  tri.v2 = SOY_vec4f(x2, y2, z2, 1.0f);
  tri.v3 = SOY_vec4f(x3, y3, z3, 1.0f);
  tri.n1 = SOY_vec4f(0.0f, 0.0f, 1.0f, 1.0f);
  tri.n2 = SOY_vec4f(0.0f, 0.0f, 1.0f, 1.0f);
  tri.n3 = SOY_vec4f(0.0f, 0.0f, 1.0f, 1.0f);
  tri.t1 = SOY_vec4f(0.5f, 0.5f, 1.0f, 1.0f);
  tri.t2 = SOY_vec4f(0.0f, 1.0f, 1.0f, 1.0f);
  tri.t3 = SOY_vec4f(1.0f, 0.0f, 1.0f, 1.0f);
  tri.colour = SOY_vec4f(0, 0, 0, 0);
  return tri;
}

typedef struct tag_mat4f {
  real32 m[4][4];
} mat4f;

#ifndef SOY_NO_MATH

mat4f SOY_mat4f(real32 r) {
  mat4f m;
  m.m[0][0] = r; m.m[0][1] = 0.0f; m.m[0][2] = 0.0f; m.m[0][3] = 0.0f;
  m.m[1][0] = 0.0f; m.m[1][1] = r; m.m[1][2] = 0.0f; m.m[1][3] = 0.0f;
  m.m[2][0] = 0.0f; m.m[2][1] = 0.0f; m.m[2][2] = r; m.m[2][3] = 0.0f;
  m.m[3][0] = 0.0f; m.m[3][1] = 0.0f; m.m[3][2] = 0.0f; m.m[3][3] = r;
  return m;
}

mat4f SOY_mat4fProjection(
    real32 n, real32 f, real32 fov, real32 aspect) {
  real32 fFovRad;
  real32 fNear = n;
  real32 fFar = f;
  real32 fFov = fov;
  real32 fAspectRatio = aspect;
  real32 range = fNear - fFar;
  mat4f m = SOY_mat4f(1.0f);
  fFovRad = 1.0f / (real32)tan(fFov*0.5f / 180.0f * SOY_PI);
  m.m[0][0] = fAspectRatio * fFovRad;
  m.m[1][1] = fFovRad;
  m.m[2][2] = (-fNear - fFar) / range;
  m.m[3][2] = 2.0f * fFar * fNear / range;
  m.m[2][3] = 1.0f;
  m.m[3][3] = 0.0f;
  return m;
}

mat4f SOY_mat4fTranslation(real32 x, real32 y, real32 z) {
  mat4f m = SOY_mat4f(1.0f);
  m.m[3][0] = x;
  m.m[3][1] = y;
  m.m[3][2] = z;
  return m;
}

mat4f SOY_mat4fScaling(real32 x, real32 y, real32 z) {
  mat4f m = SOY_mat4f(1.0f);
  m.m[0][0] = x;
  m.m[1][1] = y;
  m.m[2][2] = z;
  return m;
}

mat4f SOY_mat4fRotationX(real32 angleRad) {
  mat4f rotX = SOY_mat4f(1.0f);
  rotX.m[0][0] = 1.0f;
  rotX.m[1][1] = (real32)cos(angleRad);
  rotX.m[1][2] = (real32)sin(angleRad);
  rotX.m[2][1] = -(real32)sin(angleRad);
  rotX.m[2][2] = (real32)cos(angleRad);
  rotX.m[3][3] = 1.0f;
  return rotX;
}

mat4f SOY_mat4fRotationY(real32 angleRad) {
  mat4f rotY = SOY_mat4f(1.0f);
  rotY.m[0][0] = (real32)cos(angleRad);
  rotY.m[0][2] = -(real32)sin(angleRad);
  rotY.m[2][0] = (real32)sin(angleRad);
  rotY.m[1][1] = 1.0f;
  rotY.m[2][2] = (real32)cos(angleRad);
  rotY.m[3][3] = 1.0f;
  return rotY;
}

mat4f SOY_mat4fRotationZ(real32 angleRad) {
  mat4f rotZ = SOY_mat4f(1.0f);
  rotZ.m[0][0] = (real32)cos(angleRad);
  rotZ.m[0][1] = -(real32)sin(angleRad);
  rotZ.m[1][0] = (real32)sin(angleRad);
  rotZ.m[1][1] = (real32)cos(angleRad);
  rotZ.m[2][2] = 1.0f;
  rotZ.m[3][3] = 1.0f;
  return rotZ;
}

#define SOY_MATH_TABLE_PERCISION 4
#define SOY_MATH_TABLE_SIZE (360 << SOY_MATH_TABLE_PERCISION)

real32 g_soyTableSin[SOY_MATH_TABLE_SIZE];
real32 g_soyTableCos[SOY_MATH_TABLE_SIZE];
real32 g_soyTableTan[SOY_MATH_TABLE_SIZE];
real32 g_soyTableAtan[SOY_MATH_TABLE_SIZE];

int32 SOY_generateMathTables(void) {
  uint32 i;
  real32 val;
  real32 norm;
  SOY_LOG("Generating math lookup tables\n");
  for(i = 0; i < SOY_MATH_TABLE_SIZE; i++) {
    norm = ((real32)i/(real32)SOY_MATH_TABLE_SIZE);
    val = (real32)sin(norm*(real32)SOY_PI);
    g_soyTableSin[i] = val;
    val = (real32)cos(norm*(real32)SOY_PI);
    g_soyTableCos[i] = val;
    val = (real32)tan(norm*(real32)SOY_PI);
    g_soyTableTan[i] = val;
    val = (real32)atan(norm*(real32)SOY_PI);
    g_soyTableAtan[i] = val;
  }
  return TRUE;
}

#define SOY_sinLookup(i) \
  (g_soyTableSin[((uint32)((i/(real32)SOY_PI)*SOY_MATH_TABLE_SIZE)) \
   %SOY_MATH_TABLE_SIZE])
#define SOY_cosLookup(i) \
  (g_soyTableCos[((uint32)((i/(real32)SOY_PI)*SOY_MATH_TABLE_SIZE)) \
   %SOY_MATH_TABLE_SIZE])
#define SOY_tanLookup(i) \
  (g_soyTableTan[((uint32)((i/(real32)SOY_PI)*SOY_MATH_TABLE_SIZE)) \
   %SOY_MATH_TABLE_SIZE])
#define SOY_atanLookup(i) \
  (g_soyTableAtan[((uint32)((i/(real32)SOY_PI)*SOY_MATH_TABLE_SIZE)) \
   %SOY_MATH_TABLE_SIZE])

int32 SOY_vec2iEqual(vec2i a, vec2i b) {
	int32 ret = 0;
	ret += ((a.x == b.x));
	ret += ((a.y == b.y));
	return (ret == 2);
}

int32 SOY_vec2fEqual(vec2f a, vec2f b) {
	int32 ret = 0;
	ret += ((a.x == b.x));
	ret += ((a.y == b.y));
	return (ret == 2);
}

vec2i SOY_vec2iAdd(vec2i a, vec2i b) {
	vec2i ret;
	ret.x = (a.x + b.x);
	ret.y = (a.y + b.y);
	return ret;
}

vec2f SOY_vec2fAdd(vec2f a, vec2f b) {
	vec2f ret;
	ret.x = (a.x + b.x);
	ret.y = (a.y + b.y);
	return ret;
}

vec2i SOY_vec2iSubtract(vec2i a, vec2i b) {
	vec2i ret;
	ret.x = (a.x - b.x);
	ret.y = (a.y - b.y);
	return ret;
}

vec2f SOY_vec2fSubtract(vec2f a, vec2f b) {
	vec2f ret;
	ret.x = (a.x - b.x);
	ret.y = (a.y - b.y);
	return ret;
}

vec2i SOY_vec2iMultiply(vec2i a, vec2i b) {
	vec2i ret;
	ret.x = (a.x * b.x);
	ret.y = (a.y * b.y);
	return ret;
}

vec2f SOY_vec2fMultiply(vec2f a, vec2f b) {
	vec2f ret;
	ret.x = (a.x * b.x);
	ret.y = (a.y * b.y);
	return ret;
}

vec2i SOY_vec2iDivide(vec2i a, vec2i b) {
	vec2i ret;
	ret.x = (a.x / b.x);
	ret.y = (a.y / b.y);
	return ret;
}

vec2f SOY_vec2fDivide(vec2f a, vec2f b) {
	vec2f ret;
	ret.x = (a.x / b.x);
	ret.y = (a.y / b.y);
	return ret;
}

vec2f SOY_vec2fMultiplyScalar(vec2f v, real32 scalar) {
  vec2f res;
  res.x = v.x * scalar; res.y = v.y * scalar;;
  return res;
}

vec2f SOY_vec2fDivideScalar(vec2f v1, real32 scalar) {
  vec2f res = SOY_vec2f(0.0f, 0.0f);
  if(scalar != 0) {
    res.x = v1.x / scalar; res.y = v1.y / scalar;
  }
  return res;
}

vec2f SOY_vec2fInvert(vec2f v) {
  vec2f res;
  res.x = v.x*-1.0f; res.y = v.y*-1.0f;
  return res;
}

real32 SOY_vec2fDot(vec2f v1, vec2f v2) {
  return (v1.x*v2.x+v1.y*v2.y);
}

real32 SOY_vec2fLength(vec2f v) {
  return (real32)sqrt(SOY_vec2fDot(v, v));
}

vec2f SOY_vec2fNormalize(vec2f v) {
  vec2f res;
  real32 len = SOY_vec2fLength(v);
  res.x = v.x / len; res.y = v.y / len;
  return res;
}

int32 SOY_vec3fEqual(vec3f a, vec3f b) {
	int32 ret = 0;
	ret += ((a.x == b.x));
	ret += ((a.y == b.y));
	ret += ((a.z == b.z));
	return (ret == 3);
}

vec3f SOY_vec3fAdd(vec3f a, vec3f b) {
	vec3f ret;
	ret.x = (a.x + b.x);
	ret.y = (a.y + b.y);
	ret.z = (a.z + b.z);
	return ret;
}

vec3f SOY_vec3fSubtract(vec3f a, vec3f b) {
	vec3f ret;
	ret.x = (a.x - b.x);
	ret.y = (a.y - b.y);
	ret.z = (a.z - b.z);
	return ret;
}

vec3f SOY_vec3fMultiply(vec3f a, vec3f b) {
	vec3f ret;
	ret.x = (a.x * b.x);
	ret.y = (a.y * b.y);
	ret.z = (a.z * b.z);
	return ret;
}

vec3f SOY_vec3fDivide(vec3f a, vec3f b) {
	vec3f ret;
	ret.x = (a.x / b.x);
	ret.y = (a.y / b.y);
	ret.z = (a.z / b.z);
	return ret;
}

vec3f SOY_vec3fMultiplyScalar(vec3f v, real32 scalar) {
  vec3f res;
  res.x = v.x * scalar; res.y = v.y * scalar; res.z = v.z * scalar;
  return res;
}

vec3f SOY_vec3fDivideScalar(vec3f v1, real32 scalar) {
  vec3f res = SOY_vec3f(0.0f, 0.0f, 0.0f);
  if(scalar != 0) {
    res.x = v1.x / scalar; res.y = v1.y / scalar; res.z = v1.z / scalar;
  }
  return res;
}

vec3f SOY_vec3fInvert(vec3f v) {
  vec3f res;
  res.x = v.x*-1.0f; res.y = v.y*-1.0f; res.z = v.z*-1.0f;
  return res;
}

real32 SOY_vec3fDot(vec3f v1, vec3f v2) {
  return (v1.x*v2.x+v1.y*v2.y+v1.z*v2.z);
}

real32 SOY_vec3fLength(vec3f v) {
  return (real32)sqrt(SOY_vec3fDot(v, v));
}

vec3f SOY_vec3fNormalize(vec3f v) {
  vec3f res;
  real32 len = SOY_vec3fLength(v);
  res.x = v.x / len;
  res.y = v.y / len;
  res.z = v.z / len;
  return res;
}

vec3f SOY_vec3fCross(vec3f v1, vec3f v2) {
  vec3f res;
  res.x = v1.y * v2.z - v1.z * v2.y;
  res.y = v1.z * v2.x - v1.x * v2.z;
  res.z = v1.x * v2.y - v1.y * v2.x;
  return res;
}

vec3f SOY_vec3fMod(vec3f a, vec3f mod) {
  return SOY_vec3f(
      (real32)fmod(a.x, mod.x),
      (real32)fmod(a.y, mod.y),
      (real32)fmod(a.z, mod.z));
}

int32 SOY_vec4iEqual(vec4i a, vec4i b) {
	int32 ret = 0;
	ret += ((a.x == b.x));
	ret += ((a.y == b.y));
	ret += ((a.z == b.z));
	return (ret == 4);
}

vec4i SOY_vec4iAdd(vec4i a, vec4i b) {
	vec4i ret;
	ret.x = (a.x + b.x);
	ret.y = (a.y + b.y);
	ret.z = (a.z + b.z);
	return ret;
}

vec4i SOY_vec4iSubtract(vec4i a, vec4i b) {
	vec4i ret;
	ret.x = (a.x - b.x);
	ret.y = (a.y - b.y);
	ret.z = (a.z - b.z);
	return ret;
}

vec4i SOY_vec4iMultiply(vec4i a, vec4i b) {
	vec4i ret;
	ret.x = (a.x * b.x);
	ret.y = (a.y * b.y);
	ret.z = (a.z * b.z);
	return ret;
}

vec4i SOY_vec4iDivide(vec4i a, vec4i b) {
	vec4i ret;
	ret.x = (a.x / b.x);
	ret.y = (a.y / b.y);
	ret.z = (a.z / b.z);
	return ret;
}

int32 SOY_vec4fEqual(vec4f a, vec4f b) {
	int32 ret = 0;
	ret += ((a.x == b.x));
	ret += ((a.y == b.y));
	ret += ((a.z == b.z));
	return (ret == 4);
}

vec4f SOY_vec4fAdd(vec4f a, vec4f b) {
	vec4f ret;
	ret.x = (a.x + b.x);
	ret.y = (a.y + b.y);
	ret.z = (a.z + b.z);
	return ret;
}

vec4f SOY_vec4fSubtract(vec4f a, vec4f b) {
	vec4f ret;
	ret.x = (a.x - b.x);
	ret.y = (a.y - b.y);
	ret.z = (a.z - b.z);
	return ret;
}

vec4f SOY_vec4fMultiply(vec4f a, vec4f b) {
	vec4f ret;
	ret.x = (a.x * b.x);
	ret.y = (a.y * b.y);
	ret.z = (a.z * b.z);
	return ret;
}

vec4f SOY_vec4fDivide(vec4f a, vec4f b) {
	vec4f ret;
	ret.x = (a.x / b.x);
	ret.y = (a.y / b.y);
	ret.z = (a.z / b.z);
	return ret;
}

vec4f SOY_vec4fMod(vec4f a, vec4f mod) {
  return SOY_vec4f(
      (real32)fmod(a.x, mod.x),
      (real32)fmod(a.y, mod.y),
      (real32)fmod(a.z, mod.z),
      (real32)fmod(a.w, mod.w));
}

vec4f SOY_vec4fMultiplyScalar(vec4f v, real32 scalar) {
  vec4f res;
  res.x = v.x * scalar;
  res.y = v.y * scalar;
  res.z = v.z * scalar;
  res.w = v.w * scalar;
  return res;
}

vec4f SOY_vec4fDivideScalar(vec4f v1, real32 scalar) {
  vec4f res = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
  if(scalar != 0) {
    res.x = v1.x / scalar;
    res.y = v1.y / scalar;
    res.z = v1.z / scalar;
    res.w = v1.w / scalar;
  }
  return res;
}

vec4f SOY_vec4fCross(vec4f v1, vec4f v2) {
  vec4f res;
  res.x = v1.y * v2.z - v1.z * v2.y;
  res.y = v1.z * v2.x - v1.x * v2.z;
  res.z = v1.x * v2.y - v1.y * v2.x;
  return res;
}

vec4f SOY_vec4fInvert(vec4f v) {
  vec4f res;
  res.x = v.x*-1.0f; res.y = v.y*-1.0f; res.z = v.z*-1.0f;
  return res;
}

#if 0
real32 SOY_vec4fDot(vec4f v1, vec4f v2) {
  return ((v1.x)*(v2.x)+(v1.y)*(v2.y)+(v1.z)*(v2.z));
}
#else
#define SOY_vec4fDot(v1, v2) \
  ((v1.x)*(v2.x)+(v1.y)*(v2.y)+(v1.z)*(v2.z))
#endif

#define SOY_TOFLOAT(i) *(real32*)&(i)

#define SOY_TOINT(i) *(int32*)&(i)

#define FLOAT_ONE_AS_INT 0x3F800000

#define SOY_vec4fLength(v) (real32)sqrt(SOY_vec4fDot(v, v))

#if 0
vec4f SOY_vec4fNormalize(vec4f v) {
  vec4f res;
  real32 len = SOY_vec4fLength(v);
  res.x = v.x / len; res.y = v.y / len; res.z = v.z / len;
  return res;
}
#else
vec4f SOY_vec4fNormalize(vec4f v) {
  real32 len = 1.0f / (real32)sqrt(SOY_vec4fDot(v, v));
  return SOY_vec4f(v.x*len, v.y*len, v.z*len, 0.0f);
}
#endif

vec4f SOY_vec4fLerp(vec4f start, vec4f end, real32 t) {
	vec4f res;
	res.x = SOY_lerp(start.x, end.x, t);
	res.y = SOY_lerp(start.y, end.y, t);
	res.z = SOY_lerp(start.z, end.z, t);
	return res;
}

vec4f SOY_vec4fAlphaBlend(vec4f fg, vec4f bg) {
    return SOY_vec4f(
        ((fg.w * fg.x + (1.0f - fg.w) * bg.x)),
        ((fg.w * fg.y + (1.0f - fg.w) * bg.y)),
        ((fg.w * fg.z + (1.0f - fg.w) * bg.z)),
        (fg.w+bg.w)/2.0f);
}

#define SOY_vec2fPerp(v) SOY_vec2f((-v.y), (v.x))

real32 SOY_vec2fInner(vec2f a, vec2f b) {
  return (a.x*b.x + a.y*b.y);
}

#if 1
#define v4(x, y, z, w) SOY_vec4f(x, y, z, w)
#define v4S(x) SOY_vec4f(x, x, x, x)
#define v4Cmp(a, b) SOY_vec4fEqual(a, b)
#define v4Add(a, b) SOY_vec4fAdd(a, b)
#define v4Sub(a, b) SOY_vec4fSubtract(a, b)
#define v4Mul(a, b) SOY_vec4fMultiply(a, b)
#define v4Div(a, b) SOY_vec4fDivide(a, b)
#define v4MulS(a, s) SOY_vec4fMultiplyScalar(a, s)
#define v4DivS(a, s) SOY_vec4fDivideScalar(a, s)
#define v4Cross(a, b) SOY_vec4fCross(a, b)
#define v4Len(a) SOY_vec4fLength(a)
#define v4Dot(a, b) SOY_vec4fDot(a, b)
#define v4Norm(a) SOY_vec4fNormalize(a)
#define v4Lerp(a, b, t) SOY_vec4fLerp(a, b, t)
#define v4Inv(a) SOY_vec4fInvert(a)

#define v3(x, y, z, w) SOY_vec3f(x, y, z, w)
#define v3S(x) SOY_vec3f(x, x, x, x)
#define v3Cmp(a, b) SOY_vec3fEqual(a, b)
#define v3Add(a, b) SOY_vec3fAdd(a, b)
#define v3Sub(a, b) SOY_vec3fSubtract(a, b)
#define v3Mul(a, b) SOY_vec3fMultiply(a, b)
#define v3Div(a, b) SOY_vec3fDivide(a, b)
#define v3MulS(a, s) SOY_vec3fMultiplyScalar(a, s)
#define v3DivS(a, s) SOY_vec3fDivideScalar(a, s)
#define v3Cross(a, b) SOY_vec3fCross(a, b)
#define v3Len(a) SOY_vec3fLength(a)
#define v3Dot(a, b) SOY_vec3fDot(a, b)
#define v3Norm(a) SOY_vec3fNormalize(a)
#define v3Lerp(a, b, t) SOY_vec3fLerp(a, b, t)
#define v3Inv(a) SOY_vec3fInvert(a)

#define v2(x, y, z, w) SOY_vec2f(x, y, z, w)
#define v2S(x) SOY_vec2f(x, x, x, x)
#define v2Cmp(a, b) SOY_vec2fEqual(a, b)
#define v2Add(a, b) SOY_vec2fAdd(a, b)
#define v2Sub(a, b) SOY_vec2fSubtract(a, b)
#define v2Mul(a, b) SOY_vec2fMultiply(a, b)
#define v2Div(a, b) SOY_vec2fDivide(a, b)
#define v2MulS(a, s) SOY_vec2fMultiplyScalar(a, s)
#define v2DivS(a, s) SOY_vec2fDivideScalar(a, )
#define v2Cross(a, b) SOY_vec2fCross(a, b)
#define v2Len(a) SOY_vec2fLength(a)
#define v2Dot(a, b) SOY_vec2fDot(a, b)
#define v2Norm(a) SOY_vec2fNormalize(a)
#define v2Lerp(a, b, t) SOY_vec2fLerp(a, b, t)
#define v2Inv(a) SOY_vec2fInvert(a)

#define v2Perp(v) SOY_vec2fPerp(v)
#define v2Inner(a, b) SOY_vec2fInner(a, b)
#endif

#define SOY_quaternion(x, y, z, w) SOY_vec4f(x, y, z, w)

soyQuaternion SOY_quaternionNormalize(soyQuaternion q) {
  real32 mag = 1.0f / sqrt(q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z);
  return SOY_quaternion(q.x*mag, q.y*mag, q.z*mag, q.w*mag);
}

soyQuaternion SOY_quaternionMultiply(soyQuaternion a, soyQuaternion b) {
  soyQuaternion ret;
  ret.w = (a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z);
  ret.x = (a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y);
  ret.y = (a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x);
  ret.z = (a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w);
  return ret;
}

typedef struct tag_soyEntity {
  vec4f rotation;
  vec4f position;
  vec4f up;
  vec4f front;
} soyEntity;

typedef struct tag_soyCamera {
  int32 width;
  int32 height;
  real32 fieldOfView;
  real32 aspectRatio;
  real32 nearClip;
  real32 farClip;
} soyCamera;

typedef enum enum_soyProjectionType {
  SOY_PERSPECTIVE,
  SOY_ORTHOGRAPHIC
} soyProjectionType;

vec4f SOY_vec4fRotate(real32 yaw, real32 pitch, real32 roll) {
  SOY_UNUSED(roll);
  return v4Norm(
      SOY_vec4f(
        cos(yaw)*cos(pitch),
        sin(pitch),
        sin(yaw)*cos(pitch), 1.0f
        )
      );
}

soyEntity SOY_entity(
    real32 px, real32 py, real32 pz,
    real32 yaw, real32 pitch, real32 roll) {
  soyEntity ret;
  ret.up = SOY_vec4f(0.0f, 1.0f, 0.0f, 0.0f);
  ret.position = SOY_vec4f(px, py, pz, 0.0f);
  ret.rotation = SOY_vec4f(yaw - SOY_PI/2, pitch, roll, 0.0f);
  ret.front =
    SOY_vec4fRotate(ret.rotation.x, ret.rotation.y, ret.rotation.z);
  return ret;
}

soyCamera SOY_camera(
    int32 width, int32 height, real32 fov, soyProjectionType projection) {
  soyCamera ret;
  ret.nearClip = 0.1f;
  ret.farClip = 1000.0f;
  ret.fieldOfView = fov;
  ret.width = width;
  ret.height = height;
  ret.aspectRatio = (real32)height/(real32)width;
  SOY_UNUSED(projection);
  return ret;
}

int32 SOY_entityRotate(soyEntity* ent,
    real32 yaw, real32 pitch, real32 roll) {
  ent->rotation.x += yaw;
  ent->rotation.y += pitch;
  ent->rotation.z += roll;
  ent->front =
    SOY_vec4fRotate(ent->rotation.x, ent->rotation.y, ent->rotation.z);
  return TRUE;
}

real32 SOY_entityMove(soyEntity* ent,
    real32 front, real32 side, real32 speed) {
  ent->position = v4Sub(ent->position, v4MulS(ent->front, speed*front));
  ent->position = v4Add(ent->position,
      v4MulS(v4Norm(v4Cross(ent->front, ent->up)), speed*side));
  return TRUE;
}

#if 0
vec4f SOY_vec4fMultiplyMat4f(vec4f i, mat4f m) {
  COUNT_PROC("vec4 mat4 multiply", 0);
    __m128 ret =_mm_add_ps(
        _mm_add_ps(
          _mm_mul_ps(_mm_set1_ps(i.x), *(__m128*)m.m[0]),
          _mm_mul_ps(_mm_set1_ps(i.y), *(__m128*)m.m[1])),
        _mm_add_ps(
          _mm_mul_ps(_mm_set1_ps(i.z), *(__m128*)m.m[2]),
        _mm_mul_ps(_mm_set1_ps(1.0f), *(__m128*)m.m[3])));
  return *(vec4f*)&ret;
}
#else
#define SOY_vec4fMultiplyMat4f(i, t) \
SOY_vec4f( \
(i.x)*(t.m)[0][0] + (i.y) * (t.m)[1][0] + (i.z) * (t.m)[2][0] + (t.m)[3][0],\
(i.x)*(t.m)[0][1] + (i.y) * (t.m)[1][1] + (i.z) * (t.m)[2][1] + (t.m)[3][1],\
(i.x)*(t.m)[0][2] + (i.y) * (t.m)[1][2] + (i.z) * (t.m)[2][2] + (t.m)[3][2],\
(i.x)*(t.m)[0][3] + (i.y) * (t.m)[1][3] + (i.z) * (t.m)[2][3] + (t.m)[3][3])
#endif

mat4f SOY_mat4fMultiply(mat4f m1, mat4f m2) {
  int32 i;
  int32 j;
  mat4f res = SOY_mat4f(1.0f);
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      res.m[j][i] = m1.m[j][0] * m2.m[0][i] + m1.m[j][1] * m2.m[1][i] +
                     m1.m[j][2] * m2.m[2][i] + m1.m[j][3] * m2.m[3][i];
    }
  }
  return res;
}

mat4f SOY_mat4fRotation(real32 x, real32 y, real32 z) {
  mat4f temp = SOY_mat4fMultiply(
      SOY_mat4fRotationX(x),
      SOY_mat4fRotationY(y));
  return SOY_mat4fMultiply(temp, SOY_mat4fRotationZ(z));
}

mat4f SOY_mat4fSet(real32 px, real32 py, real32 pz,
    real32 rx, real32 ry, real32 rz, real32 sx, real32 sy, real32 sz) {
  mat4f scale = SOY_mat4fScaling(sx, sy, sz);
  mat4f rot = SOY_mat4fRotation(rx, ry, rz);
  mat4f trans = SOY_mat4fTranslation(px, py, pz);
  mat4f scaleRot = SOY_mat4fMultiply(scale, rot);
  return SOY_mat4fMultiply(scaleRot, trans);
}

int32 SOY_mat4fTranslate(mat4f* m, real32 x, real32 y, real32 z) {
  *m = SOY_mat4fMultiply(*m, SOY_mat4fTranslation(x, y, z));
  return TRUE;
}

int32 SOY_mat4fScale(mat4f* m, real32 x, real32 y, real32 z) {
  *m = SOY_mat4fMultiply(*m, SOY_mat4fScaling(x, y, z));
  return TRUE;
}

int32 SOY_mat4fRotate(mat4f* mat, real32 angle, real32 x, real32 y, real32 z) {
  real32 a = angle;
  real32 c = cos(a);
  real32 s = sin(a);
  real32 omc = 1.0f - c;
  vec4f axis = SOY_vec4fNormalize(SOY_vec4f(x, y, z, 1.0f));
  vec4f temp = SOY_vec4fMultiply(SOY_vec4f(omc, omc, omc, 1.0f), axis);
  mat4f r = SOY_mat4f(0.0f);
  mat4f i = *mat;
  r.m[0][0] = c + temp.x * axis.x;
  r.m[0][1] = 0 + temp.x * axis.y + s * axis.z;
  r.m[0][2] = 0 + temp.x * axis.z - s * axis.y;

  r.m[1][0] = 0 + temp.y * axis.x - s * axis.z;
  r.m[1][1] = c + temp.y * axis.y;
  r.m[1][2] = 0 + temp.y * axis.z + s * axis.x;

  r.m[2][0] = 0 + temp.z * axis.x + s * axis.y;
  r.m[2][1] = 0 + temp.z * axis.y - s * axis.x;
  r.m[2][2] = c + temp.z * axis.z;

  mat->m[0][0] = i.m[0][0]*r.m[0][0]+i.m[1][0]*r.m[0][1]+i.m[2][0]*r.m[0][2];
  mat->m[0][1] = i.m[0][1]*r.m[0][0]+i.m[1][1]*r.m[0][1]+i.m[2][1]*r.m[0][2];
  mat->m[0][2] = i.m[0][2]*r.m[0][0]+i.m[1][2]*r.m[0][1]+i.m[2][2]*r.m[0][2];
  mat->m[0][3] = i.m[0][3]*r.m[0][0]+i.m[1][3]*r.m[0][1]+i.m[2][3]*r.m[0][2];

  mat->m[1][0] = i.m[0][0]*r.m[1][0]+i.m[1][0]*r.m[1][1]+i.m[2][0]*r.m[1][2];
  mat->m[1][1] = i.m[0][1]*r.m[1][0]+i.m[1][1]*r.m[1][1]+i.m[2][1]*r.m[1][2];
  mat->m[1][2] = i.m[0][2]*r.m[1][0]+i.m[1][2]*r.m[1][1]+i.m[2][2]*r.m[1][2];
  mat->m[1][3] = i.m[0][3]*r.m[1][0]+i.m[1][3]*r.m[1][1]+i.m[2][3]*r.m[1][2];

  mat->m[2][0] = i.m[0][0]*r.m[2][0]+i.m[1][0]*r.m[2][1]+i.m[2][0]*r.m[2][2];
  mat->m[2][1] = i.m[0][1]*r.m[2][0]+i.m[1][1]*r.m[2][1]+i.m[2][1]*r.m[2][2];
  mat->m[2][2] = i.m[0][2]*r.m[2][0]+i.m[1][2]*r.m[2][1]+i.m[2][2]*r.m[2][2];
  mat->m[2][3] = i.m[0][3]*r.m[2][0]+i.m[1][3]*r.m[2][1]+i.m[2][3]*r.m[2][2];
  return TRUE;
}

vec4f debug_vecX;
vec4f debug_vecY;
vec4f debug_vecZ;

mat4f SOY_mat4fPointAt(vec4f position, vec4f target, vec4f worldUp) {
  vec4f zAxis = v4Norm(v4Sub(position, target));
  vec4f xAxis = v4Norm(v4Cross(v4Norm(worldUp), zAxis));
  vec4f yAxis = v4Cross(zAxis, xAxis);
  mat4f translation = SOY_mat4f(1.0f);
  mat4f rotation = SOY_mat4f(1.0f);
  debug_vecX = xAxis;
  debug_vecY = yAxis;
  debug_vecZ = zAxis;

  translation.m[3][0] = -position.x;
  translation.m[3][1] = -position.y;
  translation.m[3][2] = -position.z;

  rotation.m[0][0] = xAxis.x;
  rotation.m[1][0] = xAxis.y;
  rotation.m[2][0] = xAxis.z;

  rotation.m[0][1] = yAxis.x;
  rotation.m[1][1] = yAxis.y;
  rotation.m[2][1] = yAxis.z;

  rotation.m[0][2] = zAxis.x;
  rotation.m[1][2] = zAxis.y;
  rotation.m[2][2] = zAxis.z;
  return SOY_mat4fMultiply(translation, rotation);
}

mat4f SOY_mat4fQuickInverse(mat4f m) {
  mat4f matrix;
  matrix.m[0][0] = m.m[0][0];
  matrix.m[0][1] = m.m[1][0];
  matrix.m[0][2] = m.m[2][0];
  matrix.m[0][3] = 0.0f;
  matrix.m[1][0] = m.m[0][1];
  matrix.m[1][1] = m.m[1][1];
  matrix.m[1][2] = m.m[2][1];
  matrix.m[1][3] = 0.0f;
  matrix.m[2][0] = m.m[0][2];
  matrix.m[2][1] = m.m[1][2];
  matrix.m[2][2] = m.m[2][2];
  matrix.m[2][3] = 0.0f;
  matrix.m[3][0] = -(m.m[3][0] * matrix.m[0][0] + m.m[3][1] *
      matrix.m[1][0] + m.m[3][2] * matrix.m[2][0]);
  matrix.m[3][1] = -(m.m[3][0] * matrix.m[0][1] + m.m[3][1] *
      matrix.m[1][1] + m.m[3][2] * matrix.m[2][1]);
  matrix.m[3][2] = -(m.m[3][0] * matrix.m[0][2] + m.m[3][1] *
      matrix.m[1][2] + m.m[3][2] * matrix.m[2][2]);
  matrix.m[3][3] = 1.0f;
  return matrix;
}

vec4f SOY_projectToScreen(
    vec4f vProj, int32 width, int32 height) {
  vec4f res = vProj;
  vec4f offset = SOY_vec4f(1.0f, 1.0f, 0.0f, 0.0f);
  res.x *= -1.0f;
  res.y *= -1.0f;
  res = SOY_vec4fAdd(res, offset);
  res.x *= (real32)(width/2);
  res.y *= (real32)(height/2);
  return res;
}

vec4f SOY_vec4fIntersectPlane(
    vec4f point, vec4f normal, vec4f lineStart, vec4f lineEnd, real32* t) {
  vec4f line, intersect;
  real32 tf = *t;
  vec4f pNorm = SOY_vec4fNormalize(normal);
  real32 planeDp = -SOY_vec4fDot(pNorm, point);
  real32 ad = SOY_vec4fDot(lineStart, pNorm);
  real32 bd = SOY_vec4fDot(lineEnd, pNorm);
  tf = (-planeDp - ad) / (bd - ad);
  *t = tf;
  line = SOY_vec4fSubtract(lineEnd, lineStart);
  intersect = SOY_vec4fMultiplyScalar(line, tf);
  return SOY_vec4fAdd(lineStart, intersect);
}

real32 SOY_vec4fDistanceToPlane(
    vec4f pNormal, vec4f pPoint, vec4f p) {
  return (pNormal.x * p.x +
          pNormal.y * p.y +
          pNormal.z * p.z - SOY_vec4fDot(pNormal, pPoint));
}

/*
* o-------------------------------------------o
* | @math:misc                                |
* o-------------------------------------------o
*/

real32 SOY_viewRad(real32 d, real32 cw) { return d*1.7f + cw; }

int32 SOY_pointfInFrustum(
    vec3f ro, vec3f rd, real32 x, real32 y, real32 z, real32 width) {
    real32 cw = width;
    real32 hw = width/2.0f;
    vec3f point = SOY_vec3f((x*cw + hw), (y*cw + hw), (z*cw + hw));
    vec3f nPos = SOY_vec3f(ro.x - rd.x*cw, ro.z - rd.z*cw, ro.y - rd.y*cw);
    vec3f nDir = SOY_vec3f(rd.x, rd.z, rd.y);
    vec3f obj = v3Sub(point, nPos);
    real32 dist = SOY_vec3fDot(obj, nDir);
    if(dist < 0.0f) return FALSE;
    return v3Len(v3Cross(obj, nDir)) <= SOY_viewRad(dist, cw);
}

real32 SOY_triArea(real32 a, real32 b, real32 c) {
  real32 s = (a + b + c)/2.0f;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

float SOY_dist(real32 x0, real32 y0, real32 x1, real32 y1) {
  float a = x1 - x0;
  float b = y1 - y0;
  return sqrt(a*a + b*b);
}

int32 SOY_barycentric(
    real32 x0, real32 y0,
    real32 x1, real32 y1,
    real32 x2, real32 y2,
    real32 vx, real32 vy,
    real32* u, real32* v, real32* w) {
  real32 a = SOY_dist(x0, y0, x1, y1);
  real32 b = SOY_dist(x1, y1, x2, y2);
  real32 c = SOY_dist(x2, y2, x0, y0);
  real32 totalarea = SOY_triArea(a, b, c);
  real32 length0 = SOY_dist(x0, y0, vx, vy);
  real32 length1 = SOY_dist(x1, y1, vx, vy);
  real32 length2 = SOY_dist(x2, y2, vx, vy);
  *u = SOY_triArea(b, length1, length2)/totalarea;
  *v = SOY_triArea(c, length0, length2)/totalarea;
  *w = SOY_triArea(a, length0, length1)/totalarea;
  return TRUE;
}

vec3f SOY_getNormal(vec3f triangle[3]) {
  vec3f n;
  vec3f u = v3Sub(triangle[1], triangle[0]);
  vec3f v = v3Sub(triangle[2], triangle[0]);
  n.x = (u.y * v.z) - (u.z * v.y);
  n.y = (u.z * v.x) - (u.x * v.z);
  n.z = (u.x * v.y) - (u.y * v.x);
  return n;
}

vec3f SOY_lookAt(vec3f dir) {
  vec3f ret;
  ret.x = cos(dir.x) * sin(dir.y);
  ret.y = sin(-dir.x);
  ret.z = cos(dir.x) * cos(dir.y);
  return ret;
}

int32 SOY_lineTriangleIntersect(vec3f ro, vec3f rd, vec3f a, vec3f b, vec3f c,
    real32* t, real32* u, real32* v, vec3f* n) {
  real32 rmax = 999999.0f;
  vec3f e1 = v3Sub(b, a);
  vec3f e2 = v3Sub(c, a);
  vec3f nor = v3Cross(e1, e2);
  real32 det = -v3Dot(rd, nor);
  real32 invDet = 1.0 / det;
  vec3f ao = v3Sub(ro, a);
  vec3f dao = v3Cross(ao, rd);
  float iu =  v3Dot(e2, dao) * invDet;
  float iv = -v3Dot(e1, dao) * invDet;
  float it =  v3Dot(ao, nor) * invDet;
  int32 ret = 
    det >= rmax && 
     it >= 0.0f && 
     iu >= 0.0f && 
     iv >= 0.0f && 
     (iu+iv) <= 1.0f;
  if(t) { *t = it; }
  if(u) { *u = iu; }
  if(v) { *v = iv; }
  if(n) { *n = nor; }
  return ret;
}

/*
* o-------------------------------------------o
* | @math:transform                           |
* o-------------------------------------------o
*/

typedef struct tag_soyTransform {
  vec3f position;
  vec3f direction;
  vec3f lookAt;
} soyTransform;

int32 SOY_transformInit(soyTransform* t, real32 x, real32 y, real32 z) {
  t->position = SOY_vec3f(x, y, z);
  t->direction = SOY_vec3f(0.0f, 0.0f, 0.0f);
  t->lookAt = SOY_lookAt(t->direction);
  return TRUE;
}

int32 SOY_transformMoveFree(soyTransform* t,
    real32 force, real32 sideForce, real32 up, real32 dt) {
  real32 sx = sin(t->direction.y - SOY_PI/2);
  real32 sz = cos(t->direction.y - SOY_PI/2);
  t->position.x += t->lookAt.x*force + sx*sideForce;
  t->position.y += t->lookAt.y*force + up;
  t->position.z += t->lookAt.z*force + sz*sideForce;
  SOY_UNUSED(dt);
  return TRUE;
}

int32 SOY_transformMoveGround(soyTransform* t,
    real32 force, real32 sideForce, real32 up, real32 dt) {
  real32 sx = sin(t->direction.y - SOY_PI/2);
  real32 sz = cos(t->direction.y - SOY_PI/2);
  t->position.x += t->lookAt.x*force + sx*sideForce;
  t->position.z += t->lookAt.z*force + sz*sideForce;
  t->position.y += up;
  SOY_UNUSED(dt);
  return TRUE;
}

int32 SOY_transformApplyGravity(soyTransform* t,
    real32 gravity, real32 dt) {
  t->position.y -= gravity*dt;
  SOY_UNUSED(dt);
  return TRUE;
}

int32 SOY_transformRotate(soyTransform* t,
    real32 pitch, real32 yaw, real32 dt) {
  t->direction.y += pitch*dt*0.5f;
  t->direction.x += yaw*dt*0.5f;
  t->lookAt = SOY_lookAt(t->direction);
  return TRUE;
}

mat4f SOY_transformViewMatrix(soyTransform* t) {
  mat4f ret = SOY_mat4f(1.0f);
  mat4f rotY = SOY_mat4fRotationY(-t->direction.y);
  mat4f rotX = SOY_mat4fRotationX(-t->direction.x);
  mat4f trans = SOY_mat4fTranslation(
      -t->position.x,
      -t->position.y,
      -t->position.z);
  ret = SOY_mat4fMultiply(ret, trans);
  ret = SOY_mat4fMultiply(ret, rotY);
  ret = SOY_mat4fMultiply(ret, rotX);
  return ret;
}

int32 SOY_transformUpdateFree(soyTransform* t,
    real32 forward, real32 side, real32 up,
    real32 mx, real32 my, real32 dt) {
  SOY_transformRotate(t, mx, my, dt);
  SOY_transformMoveFree(t, forward, side, up, dt);
  return TRUE;
}

int32 SOY_transformUpdateGround(soyTransform* t,
    real32 forward, real32 side, real32 up,
    real32 mx, real32 my, real32 dt) {
  SOY_transformRotate(t, mx, my, dt);
  SOY_transformMoveGround(t, forward, side, up, dt);
  return TRUE;
}

int32 SOY_transformClipToTerrain(soyTransform* t,
    real32 height, real32 dt) {
  t->position.y = SOY_MIN(SOY_MAX(t->position.y, height), 1024.0f);
  SOY_UNUSED(dt);
  return TRUE;
}

/*
* o-------------------------------------------o
* | @math:glsl spec                           |
* o-------------------------------------------o
*/

real64 SOY_glslLength(real64 x, real64 y) {
  return (real32)sqrt(x*x + y*y);
}

real64 SOY_glslClamp(real64 x, real64 min, real64 max) {
  return SOY_MIN(SOY_MAX(x, min), max);
}

real64 SOY_glslSmoothstep(real64 e0, real64 e1, real64 x) {
  real64 t = SOY_glslClamp((x - e0) / (e1 - e0), 0.0f, 1.0f);
  return (t*t*(3.0f - 2.0f * t));
}

/*
* o-------------------------------------------o
* | @math:3D                                  |
* o-------------------------------------------o
*/

typedef struct tag_soyRawMesh {
  vec4f* verts;
  vec4f* normals;
  vec4i* vertIndices;
  vec4i* normalIndices;
  vec4i* UVIndices;
  vec4f* UVs;
  int32 vertCount;
  int32 uvCount;
  int32 normalCount;
  int32 triangleCount;
} soyRawMesh;

typedef struct tag_soyMesh {
  soyTriangle* triangles;
  int32 triangleCount;
  int32 vertexCount;
  int32 normalCount;
  int32 uvCount;
} soyMesh;

/* Attributes format: vX|vY|vZ|uvX|uvY|nX|nY|nZ cR|cG|cB*/
/* Indices format: indexX|indexY|indexZ */

int32 SOY_meshCreateCustom(soyMemorySector* memory, soyMesh* mesh,
    real32* verts, real32* uvs, uint32* vertIndices, uint32* uvIndices,
    int32 triangleCount) {
  int32 i;
  SOY_ASSERT(triangleCount);
  if((size_t)triangleCount*sizeof(soyTriangle) + memory->offset <
      (size_t)memory->size) {
    mesh->triangles = (soyTriangle*)(memory->base + memory->offset);
    memory->offset += triangleCount*sizeof(soyTriangle);
  } else {
    SOY_LOG("Insufficient memory for mesh\n");
    return FALSE;
  }
  mesh->triangleCount = triangleCount;
  mesh->vertexCount = !!verts * triangleCount;
  mesh->uvCount = !!uvs * triangleCount;
  for(i = 0; i < triangleCount; i++) {
    if(verts) {
      mesh->triangles[i].v1.x = verts[vertIndices[i*3+0]*3 + 0];
      mesh->triangles[i].v1.y = verts[vertIndices[i*3+0]*3 + 1];
      mesh->triangles[i].v1.z = verts[vertIndices[i*3+0]*3 + 2];

      mesh->triangles[i].v2.x = verts[vertIndices[i*3+1]*3 + 0];
      mesh->triangles[i].v2.y = verts[vertIndices[i*3+1]*3 + 1];
      mesh->triangles[i].v2.z = verts[vertIndices[i*3+1]*3 + 2];

      mesh->triangles[i].v3.x = verts[vertIndices[i*3+2]*3 + 0];
      mesh->triangles[i].v3.y = verts[vertIndices[i*3+2]*3 + 1];
      mesh->triangles[i].v3.z = verts[vertIndices[i*3+2]*3 + 2];
    } else {
      SOY_LOG("Error. Mesh must have at least a vertex array\n");
      return FALSE;
    }
    if(uvs) {
      mesh->triangles[i].t1.x = 1.0f - uvs[uvIndices[i*3+0]*2 + 0];
      mesh->triangles[i].t1.y = 1.0f - uvs[uvIndices[i*3+0]*2 + 1];

      mesh->triangles[i].t2.x = 1.0f - uvs[uvIndices[i*3+1]*2 + 0];
      mesh->triangles[i].t2.y = 1.0f - uvs[uvIndices[i*3+1]*2 + 1];

      mesh->triangles[i].t3.x = 1.0f - uvs[uvIndices[i*3+2]*2 + 0];
      mesh->triangles[i].t3.y = 1.0f - uvs[uvIndices[i*3+2]*2 + 1];
    } else {
      mesh->triangles[i].t1 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
      mesh->triangles[i].t2 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
      mesh->triangles[i].t3 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
    }
    mesh->triangles[i].n1 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
    mesh->triangles[i].n2 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
    mesh->triangles[i].n3 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
    mesh->triangles[i].colour = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
  }
  return TRUE;
}

int32 SOY_meshCreate(soyMemorySector* memory, soyMesh* mesh,
    vec4f* verts, vec4f* normals, vec4f* UVs,
    vec4i* vertIndices, vec4i* normalIndices, vec4i* uvIndices,
    int32 triangleCount) {
  int32 i;
  vec4f one = SOY_vec4f(1.0f, 1.0f, 1.0f, 0.0f);
  SOY_ASSERT(verts);
  if((size_t)triangleCount*sizeof(soyTriangle) + memory->offset <
      (size_t)memory->size) {
    mesh->triangles = (soyTriangle*)(memory->base + memory->offset);
    memory->offset += triangleCount*sizeof(soyTriangle);
  } else {
    SOY_LOG("Insufficient memory for mesh\n");
    return FALSE;
  }
  mesh->triangleCount = triangleCount;
  mesh->vertexCount = triangleCount*3;
  mesh->normalCount = (normals == NULL) ? 0 : triangleCount*3;
  mesh->uvCount = (UVs == NULL) ? 0 : triangleCount*3;
  for(i = 0; i < triangleCount; i++) {
    mesh->triangles[i].v1 = verts[vertIndices[i].x-1];
    mesh->triangles[i].v2 = verts[vertIndices[i].y-1];
    mesh->triangles[i].v3 = verts[vertIndices[i].z-1];
    mesh->triangles[i].colour = SOY_vec4f(255, 0, 0, 255);
    if(normals) {
      mesh->triangles[i].n1 = normals[normalIndices[i].x-1];
      mesh->triangles[i].n2 = normals[normalIndices[i].y-1];
      mesh->triangles[i].n3 = normals[normalIndices[i].z-1];
    } else {
      mesh->triangles[i].n1 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
      mesh->triangles[i].n2 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
      mesh->triangles[i].n3 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
    }
    if(UVs) {
      mesh->triangles[i].t1 = v4Sub(one, UVs[uvIndices[i].x-1]);
      mesh->triangles[i].t2 = v4Sub(one, UVs[uvIndices[i].y-1]);
      mesh->triangles[i].t3 = v4Sub(one, UVs[uvIndices[i].z-1]);
    } else {
      mesh->triangles[i].t1 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
      mesh->triangles[i].t2 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
      mesh->triangles[i].t3 = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
    }
  }
  return TRUE;
}

real32 g_soyTriangleVerts[] = {
  0.0f, 0.0f, 0.0f,
  -1.0f, 1.0f, 0.0f,
  1.0f, 1.0f, 0.0f,
};

real32 g_soyTriangleUVs[] = {
  0.0f, 0.0f,
  1.0f, 0.0f,
  0.5f, 1.0f
};

uint32 g_soyTriangleIndices[3] = {
  0, 1, 2
};

uint32 g_soyTriangleUVIndices[3] = {
  0, 1, 2
};

real32 g_soyQuadVerts[] = {
  -1.0f, 0.0f, 1.0f,
  1.0f, 0.0f, 1.0f,
  -1.0f, 0.0f, -1.0f,
  1.0f, 0.0f, -1.0f
};

real32 g_soyQuadUVs[] = {
  0.0f, 1.0f,
  1.0f, 0.0f,
  1.0f, 1.0f,
  0.0f, 0.0f
};

real32 g_soyQuadVU[4*5] = {
  -1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
  1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
  -1.0f, 0.0f, -1.0f, 1.0f, 1.0f,
  1.0f, 0.0f, -1.0f, 0.0f, 0.0f
};

uint32 g_soyQuadIndices[6] = {
  1, 2, 0, 1, 3, 2
};

uint32 g_soyQuadUVIndices[6] = {
  2, 3, 0, 2, 1, 3
};

real32 g_soyPyramidVerts[] = {
  1.0f, -1.0f, -1.0f,
  1.0f, -1.0f, 1.0f,
  0.0f, 1.0f, 0.0f,
  -1.0f, -1.0f, -1.0f,
  -1.0f, -1.0f, 1.0f
};

real32 g_soyPyramidUVs[] = {
  1.0f, 0.0f,
  0.5f, 1.0f,
  0.0f, 0.0f,
  1.0f, 1.0f,
  0.0f, 1.0f
};

uint32 g_soyPyramidIndices[6*3] = {
  1, 2, 4,
  4, 2, 3,
  0, 4, 3,
  0, 2, 1,
  3, 2, 0,
  0, 1, 4
};

uint32 g_soyPyramidUVIndices[6*3] = {
  0, 1, 2,
  2, 1, 0,
  3, 2, 4,
  0, 1, 2,
  2, 1, 0,
  3, 0, 2
};

real32 g_soyCubeVerts[8*3] = {
  -1.0f, -1.0f, -1.0f,
  -1.0f, 1.0f, -1.0f,
  1.0f, -1.0f, -1.0f,
  1.0f, 1.0f, -1.0f,
  -1.0f, -1.0f, 1.0f,
  -1.0f, 1.0f, 1.0f,
  1.0f, -1.0f, 1.0f,
  1.0f, 1.0f, 1.0f
};

real32 g_soyCubeUVs[8*2] = {
  0.0f, 0.0f,
  0.0f, 1.0f,
  1.0f, 0.0f,
  1.0f, 1.0f,
  0.0f, 0.0f,
  0.0f, 1.0f,
  1.0f, 0.0f,
  1.0f, 1.0f
};

real32 g_soyCubeVU[8*5] = {
  -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
  -0.5f, 0.5f, -0.5f, 0.0f, 0.5f,
  0.5f, -0.5f, -0.5f, 0.5f, 0.0f,
  0.5f, 0.5f, -0.5f, 0.5f, 0.5f,
  -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
  -0.5f, 0.5f, 0.5f, 0.0f, 0.5f,
  0.5f, -0.5f, 0.5f, 0.5f, 0.0f,
  0.5f, 0.5f, 0.5f, 0.5f, 0.5f
};

uint32 g_soyCubeIndices[12*3] = {
  0, 1, 2, 2, 1, 3,
  1, 5, 3, 3, 5, 7,
  5, 4, 7, 7, 4, 6,
  4, 0, 6, 6, 0, 2,
  4, 5, 0, 0, 5, 1,
  7, 2, 3, 7, 6, 2
};

uint32 g_soyCubeUVIndices[12*3] = {
  0, 1, 2, 2, 1, 3, /* FRONT */
  0, 1, 2, 2, 1, 3, /* TOP */
  3, 2, 1, 1, 2, 0, /* BACK */
  0, 1, 2, 2, 1, 3, /* BOTTOM */
  0, 1, 2, 2, 1, 3, /* RIGHT */
  3, 0, 1, 3, 2, 0 /* LEFT */
};

int32 SOY_meshCreateCube(soyMemorySector* mem, soyMesh* mesh) {
  return SOY_meshCreateCustom(mem, mesh,
      g_soyCubeVerts, g_soyCubeUVs,
      g_soyCubeIndices, g_soyCubeUVIndices, 12);
}

int32 SOY_meshCreatePyramid(soyMemorySector* mem, soyMesh* mesh) {
  return SOY_meshCreateCustom(mem, mesh,
      g_soyPyramidVerts, g_soyPyramidUVs,
      g_soyPyramidIndices, g_soyPyramidUVIndices, 6);
}

int32 SOY_meshCreateQuad(soyMemorySector* mem, soyMesh* mesh) {
  return SOY_meshCreateCustom(mem, mesh,
      g_soyQuadVerts, g_soyQuadUVs,
      g_soyQuadIndices, g_soyQuadUVIndices, 2);
}

int32 SOY_meshCreateTriangle(soyMemorySector* mem, soyMesh* mesh) {
  return SOY_meshCreateCustom(mem, mesh,
      g_soyTriangleVerts, g_soyTriangleUVs,
      g_soyTriangleIndices, g_soyTriangleUVIndices, 1);
}

int32 SOY_clipTriAgainstPlane(
    vec4f pPoint, vec4f pNormal, soyTriangle* inTri,
    soyTriangle* out1, soyTriangle* out2) {
  int32 insidePointCount = 0;
  int32 outsidePointCount = 0;
  int32 insideTexCount = 0;
  int32 outsideTexCount = 0;
  real32 d1, d2, d3;
  real32 t = 0;
  vec4f* insidePoints[3];
  vec4f* outsidePoints[3];
  vec4f* insideTex[3];
  vec4f* outsideTex[3];
  vec4f pNorm = SOY_vec4fNormalize(pNormal);
  *out1 = *inTri;
  *out2 = *inTri;
  d1 = SOY_vec4fDistanceToPlane(pNorm, pPoint, inTri->v1);
  d2 = SOY_vec4fDistanceToPlane(pNorm, pPoint, inTri->v2);
  d3 = SOY_vec4fDistanceToPlane(pNorm, pPoint, inTri->v3);
  if(d1 >= 0) {
    insidePoints[insidePointCount++] = &inTri->v1;
    insideTex[insideTexCount++] = &inTri->t1;
  } else {
    outsidePoints[outsidePointCount++] = &inTri->v1;
    outsideTex[outsideTexCount++] = &inTri->t1;
  }
  if(d2 >= 0) {
    insidePoints[insidePointCount++] = &inTri->v2;
    insideTex[insideTexCount++] = &inTri->t2;
  } else {
    outsidePoints[outsidePointCount++] = &inTri->v2;
    outsideTex[outsideTexCount++] = &inTri->t2;
  }

  if(d3 >= 0) {
    insidePoints[insidePointCount++] = &inTri->v3;
    insideTex[insideTexCount++] = &inTri->t3;
  } else {
    outsidePoints[outsidePointCount++] = &inTri->v3;
    outsideTex[outsideTexCount++] = &inTri->t3;
  }
  if(insidePointCount == 0) { return 0; }
  if(insidePointCount == 3) { *out1 = *inTri; return 1; }

  if(insidePointCount == 1 && outsidePointCount == 2) {
    *out1 = *inTri;
    out1->v1 = *insidePoints[0];
    out1->t1 = *insideTex[0];
    out1->v2 =
      SOY_vec4fIntersectPlane(
          pPoint, pNorm, *insidePoints[0], *outsidePoints[0], &t);
    out1->t2.x = t * (outsideTex[0]->x - insideTex[0]->x) + insideTex[0]->x;
    out1->t2.y = t * (outsideTex[0]->y - insideTex[0]->y) + insideTex[0]->y;
    out1->t2.z = t * (outsideTex[0]->z - insideTex[0]->z) + insideTex[0]->z;
    out1->v3 =
      SOY_vec4fIntersectPlane(
          pPoint, pNorm, *insidePoints[0], *outsidePoints[1], &t);
    out1->t3.x = t * (outsideTex[1]->x - insideTex[0]->x) + insideTex[0]->x;
    out1->t3.y = t * (outsideTex[1]->y - insideTex[0]->y) + insideTex[0]->y;
    out1->t3.z = t * (outsideTex[1]->z - insideTex[0]->z) + insideTex[0]->z;
    return 1;
  }
  if(insidePointCount == 2 && outsidePointCount == 1) {
    *out1 = *inTri;
    *out2 = *inTri;
    out1->v1 = *insidePoints[0];
    out1->v2 = *insidePoints[1];
    out1->t1 = *insideTex[0];
    out1->t2 = *insideTex[1];
    out1->v3 =
      SOY_vec4fIntersectPlane(
          pPoint, pNorm, *insidePoints[0], *outsidePoints[0], &t);
    out1->t3.x = t * (outsideTex[0]->x - insideTex[0]->x) + insideTex[0]->x;
    out1->t3.y = t * (outsideTex[0]->y - insideTex[0]->y) + insideTex[0]->y;
    out1->t3.z = t * (outsideTex[0]->z - insideTex[0]->z) + insideTex[0]->z;
    out2->v1 = *insidePoints[1];
    out2->t1 = *insideTex[1];
    out2->v2 = out1->v3;
    out2->t2 = out1->t3;
    out2->v3 = SOY_vec4fIntersectPlane(
        pPoint, pNorm, *insidePoints[1], *outsidePoints[0], &t);
    out2->t3.x = t * (outsideTex[0]->x - insideTex[1]->x) + insideTex[1]->x;
    out2->t3.y = t * (outsideTex[0]->y - insideTex[1]->y) + insideTex[1]->y;
    out2->t3.z = t * (outsideTex[0]->z - insideTex[1]->z) + insideTex[1]->z;
    return 2;
  }
  return 0;
}

int32 SOY_lineIntersectX(real32 x, vec4f p1, vec4f p2) {
  return ((x > p1.x && x < p2.x) || (x < p1.x && x > p2.x));
}

int32 SOY_lineIntersectY(real32 y, vec4f p1, vec4f p2) {
  return ((y > p1.y && y < p2.y) || (y < p1.y && y > p2.y));
}

int32 SOY_lineIntersectZ(real32 z, vec4f p1, vec4f p2) {
  return ((z > p1.y && z < p2.y) || (z < p1.y && z > p2.y));
}

#endif /* SOY_NO_MATH */

/*
* o-------------------------------------------o
* | @math:fft by Wang                         |
* o-------------------------------------------o
*/

typedef struct tag_soyComplex {
  real64 real;
  real64 imag;
} soyComplex;

void SOY_fft(soyComplex* v, int32 n, soyComplex* tmp) {
  if(n > 1) {
    int32 k,m;
    soyComplex z, w;
    soyComplex* vo;
    soyComplex* ve;
    ve = tmp;
    vo = tmp + n / 2;
    for(k = 0; k < n/2; k++) {
      ve[k] = v[2*k];
      vo[k] = v[2*k+1];
    }
    SOY_fft(ve, n/2, v);
    SOY_fft(vo, n/2, v);
    for(m = 0; m < n/2; m++) {
      w.real = cos(2.0*SOY_PI*m/(real64)n);
      w.imag = -sin(2.0*SOY_PI*m/(real64)n);
      z.real = w.real*vo[m].real - w.imag*vo[m].imag;
      z.imag = w.real*vo[m].imag + w.imag*vo[m].real;
      v[m].real = ve[m].real + z.real;
      v[m].imag = ve[m].imag + z.imag;
      v[m+n/2].real = ve[m].real - z.real;
      v[m+n/2].imag = ve[m].imag - z.imag;
    }
  }
  return;
}

/*
* o-------------------------------------------o
* | @sound                                    |
* o-------------------------------------------o
*/

typedef enum enum_soyNote {
  NOTE_Ab0, NOTE_A0, NOTE_Bb0, NOTE_B0,
  NOTE_C1, NOTE_Db1, NOTE_D1, NOTE_Eb1, NOTE_E1, NOTE_F1, NOTE_Gb1,
  NOTE_G1, NOTE_Ab1, NOTE_A1, NOTE_Bb1, NOTE_B1,
  NOTE_C2, NOTE_Db2, NOTE_D2, NOTE_Eb2, NOTE_E2, NOTE_F2, NOTE_Gb2,
  NOTE_G2, NOTE_Ab2, NOTE_A2, NOTE_Bb2, NOTE_B2,
  NOTE_C3, NOTE_Db3, NOTE_D3, NOTE_Eb3, NOTE_E3, NOTE_F3, NOTE_Gb3,
  NOTE_G3, NOTE_Ab3, NOTE_A3, NOTE_Bb3, NOTE_B3,
  NOTE_C4, NOTE_Db4, NOTE_D4, NOTE_Eb4, NOTE_E4, NOTE_F4, NOTE_Gb4,
  NOTE_G4, NOTE_Ab4, NOTE_A4, NOTE_Bb4, NOTE_B4,
  NOTE_C5, NOTE_Db5, NOTE_D5, NOTE_Eb5, NOTE_E5, NOTE_F5, NOTE_Gb5,
  NOTE_G5, NOTE_Ab5, NOTE_A5, NOTE_Bb5, NOTE_B5,
  NOTE_C6, NOTE_Db6, NOTE_D6, NOTE_Eb6, NOTE_E6, NOTE_F6, NOTE_Gb6,
  NOTE_G6, NOTE_Ab6, NOTE_A6, NOTE_Bb6, NOTE_B6,
  NOTE_C7, NOTE_Db7, NOTE_D7, NOTE_Eb7, NOTE_E7, NOTE_F7, NOTE_Gb7,
  NOTE_G7, NOTE_Ab7, NOTE_A7, NOTE_Bb7, NOTE_B7,
  NOTE_C8, NOTE_Db8, NOTE_D8, NOTE_Eb8, NOTE_E8, NOTE_F8, NOTE_Gb8,
  NOTE_G8, NOTE_Ab8, NOTE_A8, NOTE_Bb8, NOTE_B8,
  NOTE_C9, NOTE_Db9, NOTE_D9, NOTE_Eb9, NOTE_E9, NOTE_F9, NOTE_Gb9,
  NOTE_G9, NOTE_Ab9, NOTE_A9, NOTE_Bb9, NOTE_B9,
  EMPTY
} soyNote;

#define SOY_MAX_MIX_AMP 32767
#define SOY_MAX_MIXER_CHANNELS 0xFF

#if 0

typedef struct tag_soySample {
  int16* dataL;
  int16* dataR;
  uint32 cursor;
  size_t length;
  int32 channels;
  int32 bitRate;
  int32 sampleRate;
  int8 label[16];
} soySample;
#endif

typedef struct tag_soyAudio {
  int32 samplingRate;
  int32 bufferSize;
  int32 bitRate;
  int32 latency;
  uint64 cursorPosition;
  real64 timer;
  real64 toneHz;
  real64 tonePeriod;
} soyAudio;

#if 0
soySample SOY_audioSample(int8* label, int16* memL, int16* memR,
    int32 length, int32 channels, int32 bitrate, int32 samplerate) {
  soySample ret;
  int32 i = 0;
  ret.cursor = 0;
  ret.bitRate = bitrate;
  ret.channels = channels;
  ret.length = length;
  ret.sampleRate = samplerate;
  ret.dataL = memL;
  ret.dataR = memR;
  while(label[i] != '\0' && label[i] != '.' && i <= 15) {
    ret.label[i] = label[i];
    i++;
  }
  ret.label[i] = '\0';
  return ret;
}

int32 SOY_audioSampleRename(soySample* sample, int8* name) {
  snprintf(sample->label, 8, "%s", name);
  return TRUE;
}
#endif

int16 SOY_audioMix(int16 sampleA, int16 sampleB) {
  int32 mix = 0;
  int32 a = (int32)sampleA;
  int32 b = (int32)sampleB;
  /* clip signal */
  mix = a+b;
  mix /= 2;
  if(mix >= SOY_MAX_MIX_AMP - 1) { mix = SOY_MAX_MIX_AMP - 1; }
  if(mix <= -SOY_MAX_MIX_AMP + 1) { mix = -SOY_MAX_MIX_AMP + 1; }
  return (int16)(mix);
}

real64 SOY_audioPitch(int32 note) {
  return pow(2.0, (real64)(note-49)/12.0)*440.0;
}

/*
* o-------------------------------------------o
* | @noise                                    |
* o-------------------------------------------o
*/

SOY_GLOBAL int64 g_noisePerm2[512] = {
 151,160,137,91,90,15,
 131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
 190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
 88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
 77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
 102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
 135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
 5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
 223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
 129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
 251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
 49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
 138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180,
 151,160,137,91,90,15,
 131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
 190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
 88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
 77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
 102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
 135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
 5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
 223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
 129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
 251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
 49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
 138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
};

SOY_GLOBAL int64 g_noiseGrad3[12][3] = {
  {1,1,0},{-1,1,0},{1,-1,0},{-1,-1,0},
  {1,0,1},{-1,0,1},{1,0,-1},{-1,0,-1},
  {0,1,1},{0,-1,1},{0,1,-1},{0,-1,-1}
 };

SOY_GLOBAL uint32 g_randCounter = 0;

uint32 SOY_rand(uint32 range) {
	uint32 ret = g_noisePerm2[g_randCounter%512];
	g_randCounter += g_noisePerm2[ret%512];
	ret += g_noisePerm2[g_randCounter%512];
	g_randCounter += g_noisePerm2[ret%512];
	ret = g_noisePerm2[g_randCounter%512];
	g_randCounter += g_noisePerm2[ret%512];
	ret += g_noisePerm2[g_randCounter%512];
	g_randCounter += g_noisePerm2[ret%512];
	return ret%range;
}

typedef real64 (*PFNOISEPROC2D) (real64 x, real64 y);
typedef real64 (*PFNOISEPROC3D) (real64 x, real64 y, real64 z);

#define SOY_SQRT_3 1.732050807568877
#define SOY_SIMPLEX_F2 (0.5 * (SOY_SQRT_3 - 1.0))
#define SOY_SIMPLEX_G2 ((3.0 - SOY_SQRT_3) / 6.0)
#define SOY_SIMPLEX_F3 (1.0 / 3.0)
#define SOY_SIMPLEX_G3 (1.0 / 6.0)
#define SOY_SIMPLEX_G2x2 (SOY_SIMPLEX_G2*2.0)
#define SOY_SIMPLEX_G3x2 (SOY_SIMPLEX_G3*2.0)
#define SOY_SIMPLEX_G3x3 (SOY_SIMPLEX_G3*3.0)


real32 SOY_noiseSimplexNormalize(real64 n) {
    return (real32)((n * (1.0f / 0.34543f))*0.5f + 0.5f);
}

real64 SOY_noiseSimplex2D(real64 xin, real64 yin) {
  real64 n0, n1, n2, x1, y1, x2, y2, t0, t1, t2;
  int64 i1, j1, ii, jj, gi0, gi1, gi2;
  real64 s = (xin + yin) * SOY_SIMPLEX_F2;
  int64 i = SOY_FASTFLOOR(xin + s);
  int64 j = SOY_FASTFLOOR(yin + s);
  real64 t = (real64)(i + j) * SOY_SIMPLEX_G2;
  real64 xd0 = (real64)i - t;
  real64 yd0 = (real64)j - t;
  real64 x0 = xin - xd0;
  real64 y0 = yin - yd0;
  if(x0 > y0) { i1 = 1; j1 = 0; } else { i1 = 0; j1 = 1; }
  x1 = x0 - i1 + SOY_SIMPLEX_G2;
  y1 = y0 - j1 + SOY_SIMPLEX_G2;
  x2 = x0 - 1.0 + SOY_SIMPLEX_G2x2;
  y2 = y0 - 1.0 + SOY_SIMPLEX_G2x2;
  ii = i & 255;
  jj = j & 255;
  gi0 = g_noisePerm2[ii + g_noisePerm2[jj]] % 12;
  gi1 = g_noisePerm2[ii + i1 + g_noisePerm2[jj + j1]] % 12;
  gi2 = g_noisePerm2[ii + 1 + g_noisePerm2[jj + 1]] % 12;
  t0 = 0.5 - x0 * x0 - y0 * y0;
  t1 = 0.5 - x1 * x1 - y1 * y1;
  t2 = 0.5 - x2 * x2 - y2 * y2;
  if(t0 < 0.0) {
    n0 = 0.0;
  } else {
    t0 *= t0;
    n0 = t0 * t0 * SOY_dot2(g_noiseGrad3[gi0], x0, y0);
  }
  if(t1 < 0.0) {
    n1 = 0.0;
  } else {
    t1 *= t1;
    n1 = t1 * t1 * SOY_dot2(g_noiseGrad3[gi1], x1, y1);
  }
  if(t2 < 0) {
    n2 = 0.0;
  } else {
    t2 *= t2;
    n2 = t2 * t2 * SOY_dot2(g_noiseGrad3[gi2], x2, y2);
  }
  return SOY_MIN(SOY_MAX(
        ((35.0729517397) * (n0 + n1 + n2)), -0.5), 0.5);
}

real64 SOY_noiseSimplex3D(real64 xin, real64 yin, real64 zin) {
  real64 n0, n1, n2, n3, t0, t1, t2, t3;
  real64 x1, y1, z1, x2, y2, z2, x3, y3, z3;
  int64 i1, j1, k1;
  int64 i2, j2, k2;
  int64 ii, jj, kk, gi0, gi1, gi2, gi3;
  real64 xf = xin;
  real64 yf = yin;
  real64 zf = zin;
  real64 s = (real64)(xf + yf + zf)*SOY_SIMPLEX_F3;
  int64 i = SOY_FASTFLOOR(xf + s);
  int64 j = SOY_FASTFLOOR(yf + s);
  int64 k = SOY_FASTFLOOR(zf + s);
  real64 t = (real64)(i + j + k)*SOY_SIMPLEX_G3;
  real64 xd0 = (real64)i - t;
  real64 yd0 = (real64)j - t;
  real64 zd0 = (real64)k - t;
  real64 x0 = xf - xd0;
  real64 y0 = yf - yd0;
  real64 z0 = zf - zd0;
  if(x0 >= y0) {
    if(y0 >= z0) {
      i1 = 1; j1 = 0; k1 = 0; i2 = 1; j2 = 1; k2 = 0;
    } else if(x0 >= z0) {
      i1 = 1; j1 = 0; k1 = 0; i2 = 1; j2 = 0; k2 = 1;
    } else {
      i1 = 0; j1 = 0; k1 = 1; i2 = 1; j2 = 0; k2 = 1;
    }
  } else {
    if(y0 < z0) {
      i1 = 0; j1 = 0; k1 = 1; i2 = 0; j2 = 1; k2 = 1;
    } else if(x0 < z0) {
      i1 = 0; j1 = 1; k1 = 0; i2 = 0; j2 = 1; k2 = 1;
    } else {
      i1 = 0; j1 = 1; k1 = 0; i2 = 1; j2 = 1; k2 = 0;
    }
  }
  x1 = x0 - (real64)i1 + SOY_SIMPLEX_G3;
  y1 = y0 - (real64)j1 + SOY_SIMPLEX_G3;
  z1 = z0 - (real64)k1 + SOY_SIMPLEX_G3;
  x2 = x0 - (real64)i2 + SOY_SIMPLEX_G3x2;
  y2 = y0 - (real64)j2 + SOY_SIMPLEX_G3x2;
  z2 = z0 - (real64)k2 + SOY_SIMPLEX_G3x2;
  x3 = x0 - 1.0 + SOY_SIMPLEX_G3x3;
  y3 = y0 - 1.0 + SOY_SIMPLEX_G3x3;
  z3 = z0 - 1.0 + SOY_SIMPLEX_G3x3;
  ii = i & 255;
  jj = j & 255;
  kk = k & 255;
  gi0 = g_noisePerm2[
    ii + g_noisePerm2[jj + g_noisePerm2[kk]]] % 12;
  gi1 = g_noisePerm2[
    ii + i1 + g_noisePerm2[jj + j1 + g_noisePerm2[kk + k1]]] % 12;
  gi2 = g_noisePerm2[
    ii + i2 + g_noisePerm2[jj + j2 + g_noisePerm2[kk + k2]]] % 12;
  gi3 = g_noisePerm2[
    ii + 1 + g_noisePerm2[jj + 1 + g_noisePerm2[kk + 1]]] % 12;
  t0 = 0.5 - x0 * x0 - y0 * y0 - z0 * z0;
  if(t0 < 0.0) {
    n0 = 0.0;
  } else {
    t0 *= t0;
    n0 = t0 * t0 * SOY_dot3(g_noiseGrad3[gi0], x0, y0, z0);
  }
  t1 = 0.5 - x1 * x1 - y1 * y1 - z1 * z1;
  if(t1 < 0.0) {
    n1 = 0.0;
  } else {
    t1 *= t1;
    n1 = t1 * t1 * SOY_dot3(g_noiseGrad3[gi1], x1, y1, z1);
  }
  t2 = 0.5 - x2 * x2 - y2 * y2 - z2 * z2;
  if(t2 < 0.0) {
    n2 = 0.0;
  } else {
    t2 *= t2;
    n2 = t2 * t2 * SOY_dot3(g_noiseGrad3[gi2], x2, y2, z2);
  }
  t3 = 0.5 - x3 * x3 - y3 * y3 - z3 * z3;
  if(t3 < 0.0) {
    n3 = 0.0;
  } else {
    t3 *= t3;
    n3 = t3 * t3 * SOY_dot3(g_noiseGrad3[gi3], x3, y3, z3);
  }
  return SOY_MIN(SOY_MAX(((38.440839548) * (n0 + n1 + n2 + n3)),
        -0.5), 0.5);
}

#define M1 1597334677U /* 1719413*929 */
#define M2 3812015801U /* 140473*2467*11 */

real64 SOY_noiseHashFast(uint32 x, uint32 y) {
  x *= M1;
  y *= M2;
  return (real64)((x ^ y) * M1) * (1.0/(real64)0xffffffffU);
}

real64 SOY_noiseValue2D(real64 x, real64 y) {
  real64 ix = (real64)SOY_FASTFLOOR(x);
  real64 iy = (real64)SOY_FASTFLOOR(y);
  real64 fx = (x - ix);
  real64 fy = (y - iy);
  real64 a = SOY_noiseHashFast(ix, iy);
  real64 b = SOY_noiseHashFast(ix + 1.0, iy);
  real64 c = SOY_noiseHashFast(ix, iy + 1.0);
  real64 d = SOY_noiseHashFast(ix + 1.0, iy + 1.0);
  real64 ux = (fx * fx * (3.0 - 2.0*fx));
  real64 uy = (fy * fy * (3.0 - 2.0*fy));
  return SOY_lerp(a, b, ux) + (c - a) * uy * (1.0 - ux) + (d - b) * ux * uy;
}

real64 SOY_noiseOctave2D(PFNOISEPROC2D noiseProc,
    real64 x, real64 y, real64 scale, real64 persistance, int64 octaves) {
  real64 ret;
  real64 fx, fy;
  real64 freq = 1.0;
  real64 pers = 1.0;
  real64 acc = 0.0;
  int32 i;
  ret = 0.0;
  for(i = 0; i < octaves; i++) {
    fx = (x * scale) * freq;
    fy = (y * scale) * freq;
    ret += noiseProc(fx, fy) * pers;
    acc += pers;
    freq *= 2.0;
    pers *= persistance;
  }
  return ret / acc;
}

real32 SOY_noiseOctave3D(PFNOISEPROC3D noiseProc,
    real64 x, real64 y, real64 z,
    real64 scale, real64 persistance, int32 octaves) {
  real64 ret;
  real64 fx, fy, fz;
  real64 freq = 1.0;
  real64 pers = 1.0;
  real64 acc = 0.0;
  int32 i;
  ret = 0.0;
  for(i = 0; i < octaves; i++) {
    fx = (x * scale) * freq;
    fy = (y * scale) * freq;
    fz = (z * scale) * freq;
    ret += noiseProc(fx, fy, fz) * pers;
    acc += pers;
    freq *= 2.0;
    pers *= persistance;
  }
  return ret / acc;
}

real32 SOY_noiseDomainWarp2D(PFNOISEPROC2D proc,
    real32 x, real32 y, real32 dx, real32 dy,
    real32 warp, real32 scale, real32 pers,
    int32 noiseOctaves, int32 warpOctaves) {
  real64 dwx =
    SOY_noiseOctave2D(proc, x, y, scale, pers, warpOctaves);
  real64 dwy =
    SOY_noiseOctave2D(proc, x + dx, y + dy, scale, pers, warpOctaves);
  return (real32)
    SOY_noiseOctave2D(proc,
        x + warp*dwx, y + warp*dwy, scale, pers, noiseOctaves);
}

real32 SOY_noiseDomainWarp3D(PFNOISEPROC3D proc,
    real32 x, real32 y, real32 z, real32 dx, real32 dy, real32 dz,
    real32 warp, real32 scale, real32 pers, int32 octaves) {
  real64 dwx =
    SOY_noiseOctave3D(proc, x, y, z, scale, pers, octaves);
  real64 dwy =
    SOY_noiseOctave3D(proc, x + dx, y + dy, z, scale, pers, octaves);
  SOY_UNUSED(dz);
  return (real32)SOY_noiseOctave3D(proc,
      x + warp*dwx, y + warp*dwy, z, scale, pers, octaves);
}

/*
* o-------------------------------------------o
* | @draw                                     |
* o-------------------------------------------o
*/

typedef uint32 soyPixel;

typedef struct tag_soyPixelCanvas {
  int32 width;
  int32 height;
  size_t maxSizeInBytes;
  soyPixel* data;
  int32 clipRect[4];
  int32 clipRectPrev[4];
  soyPixel drawColour;
} soyPixelCanvas;

typedef struct tag_soyDepthCanvas {
  int32 width;
  int32 height;
  size_t maxSizeInBytes;
  real32* data;
  int32 clipRect[4];
  int32 clipRectPrev[4];
} soyDepthCanvas;

typedef union tag_soyCanvas {
  soyPixelCanvas rgba;
  soyDepthCanvas depth;
} soyCanvas;

typedef enum enum_soyRenderMode {
  SOY_RENDER_LINES = 1,
  SOY_RENDER_SOLID = 2,
  SOY_RENDER_TEXTURE_AFFINE = 4,
  SOY_RENDER_TEXTURE = 8
} soyRenderMode;

SOY_GLOBAL int32 g_soyHitTestRect[4] = { 22, 4, 20*3, 4 };

#define SOY_pixel(r, g, b, a) \
  (soyPixel)(((a) << 24) | ((r) << 16) | ((g) << 8) | ((b)))

#define SOY_boundsCheck(x, y, sx, sy, ex, ey) \
  ((x) >= (sx) && (x) < (ex) && (y) >= (sy) && (y) < (ey))

#define SOY_vec4fToPixel(v) \
    SOY_pixel((uint8)v.x, (uint8)v.y, (uint8)v.z, (uint8)v.w) \

#define SOY_pixelToVec4f(pix) \
  SOY_vec4f( \
      ((pix) >> 16) & 0xFF, ((pix) >> 8) & 0xFF, \
      ((pix)) & 0xFF, ((pix) >> 24) & 0xFF)

#define V4RGBA(x) SOY_vec4fToPixel(x)
#define RGBAV4(x) SOY_pixelToVec4f(x)

#define SOY_drawSetColour(hCanvas, colour) \
  hCanvas->rgba.drawColour = (colour)

#define SOY_drawSetAlpha(hCanvas, val) \
  hCanvas->rgba.drawColour = \
  (hCanvas->rgba.drawColour & 0x00FFFFFF) | ((val) << 24)

#define SOY_drawSetRed(hCanvas, val) \
  hCanvas->rgba.drawColour = \
  (hCanvas->rgba.drawColour & 0xFF00FFFF) | ((val) << 16)

#define SOY_drawSetGreen(hCanvas, val) \
  hCanvas->rgba.drawColour = \
  (hCanvas->rgba.drawColour & 0xFFFF00FF) | ((val) << 8)

#define SOY_drawSetBlue(hCanvas, val) \
  hCanvas->rgba.drawColour = \
  (hCanvas->rgba.drawColour & 0xFFFFFF00) | ((val))

#define SOY_drawSample(hCanvas, x, y) \
  ((hCanvas->rgba.data) \
  [(int32)(x) + (int32)(y) * (hCanvas->rgba.width)])

#define SOY_drawSampleDepth(canvas, x, y) \
  ((canvas->depth.data) \
  [(int32)(x) + (int32)(y) * (g_soyDepthbuffer->depth.width)])

vec4f SOY_drawSampleVec4(soyCanvas* hCanvas, real32 x, real32 y) {
  int32 i = SOY_MIN(SOY_MAX((int32)x, 0), hCanvas->rgba.width - 1);
  int32 j = SOY_MIN(SOY_MAX((int32)y, 0), hCanvas->rgba.height - 1);
  return RGBAV4(
        hCanvas->rgba.data[i + j * hCanvas->rgba.width]);
}

#define SOY_drawSampleUV(canvas, x, y) \
  ((canvas->rgba.data) \
  [(((int32)((fabs(x))*(canvas->rgba.width - 1) + 0.5f))\
    %canvas->rgba.width) + \
   (((int32)((fabs(y))*(canvas->rgba.height - 1) + 0.5f))\
    %canvas->rgba.height)* (canvas->rgba.width)])

#define SOY_drawSampleUVFast(canvas, x, y) \
  canvas->rgba.data \
  [( \
   (int32)(((x)*(canvas->rgba.width - 1) + 0.5f)) + \
   (int32)(((y)*(canvas->rgba.height - 1) + 0.5f))*(canvas->rgba.width))]

#define SOY_drawBoundsCheck(hCanvas, x, y) \
 SOY_ASSERT(x + y*hCanvas->rgba.width < \
      hCanvas->rgba.width* \
      hCanvas->rgba.height)

#define SOY_drawDepthBoundsCheck(hCanvas, x, y) \
 SOY_ASSERT(x + y*hCanvas->depth.width < \
      hCanvas->depth.width* \
      hCanvas->depth.height)

#ifdef SOY_DEBUG_BOUNDS
#define SOY_drawDepth(hCanvas, x, y, d) \
  SOY_drawDepthBoundsCheck(hCanvas, x, y); \
  (hCanvas->depth.data) \
  [(x) + (y) * (hCanvas->depth.width)] = (d)

#define SOY_drawPixel(hCanvas, x, y) \
  SOY_drawBoundsCheck(hCanvas, x, y); \
  (hCanvas->rgba.data) \
  [(x) + (y) * (hCanvas->rgba.width)] = \
  hCanvas->rgba.drawColour

#define SOY_drawPixelColour(hCanvas, x, y, colour) \
  SOY_drawBoundsCheck(hCanvas, x, y); \
  (hCanvas->rgba.data)[(x) + (y) * \
  hCanvas->rgba.width] = (colour)

#define SOY_drawPixelClipToRect(hCanvas, x, y, rect) \
  if(x >= rect[0] && x < rect[2] && y >= rect[1] && y < rect[3]) { \
    SOY_drawBoundsCheck(hCanvas, x, y); \
    (hCanvas->rgba.data) \
    [(x) + (y) * (hCanvas->rgba.width)] = \
    hCanvas->rgba.drawColour; }


#define SOY_drawPixelClip(hCanvas, x, y, cx1, cy1, cx2, cy2) \
  if(x >= cx1 && x < cx2 && y >= cy1 && y < cy2) { \
    SOY_drawBoundsCheck(hCanvas, x, y); \
    (hCanvas->rgba.data) \
    [(x) + (y) * (hCanvas->rgba.width)] = \
    hCanvas->rgba.drawColour; }

#define SOY_drawPixelBlend(hCanvas, x, y) \
    SOY_drawBoundsCheck(hCanvas, x, y); \
    hCanvas->rgba.data[(x)+(y)*hCanvas->rgba.width] = \
      SOY_alphaBlend( \
        hCanvas->rgba.data \
        [(x) + (y) *hCanvas->rgba.width], \
        hCanvas->rgba.drawColour)
#else
#define SOY_drawDepth(hCanvas, x, y, d) \
  (g_soyDepthbuffer->depth.data) \
  [(x) + (y) * (g_soyDepthbuffer->depth.width)] = (d)

#define SOY_drawPixel(hCanvas, x, y) \
  (hCanvas->rgba.data) \
  [(x) + (y) * (hCanvas->rgba.width)] = \
  hCanvas->rgba.drawColour

#define SOY_drawPixelColour(hCanvas, x, y, colour) \
  (hCanvas->rgba.data)[(x) + (y) * \
  hCanvas->rgba.width] = (colour)

#define SOY_drawPixelClip(hCanvas, x, y, cx1, cy1, cx2, cy2) \
  if(x >= cx1 && x < cx2 && y >= cy1 && y < cy2) { \
    (hCanvas->rgba.data) \
    [(x) + (y) * (hCanvas->rgba.width)] = \
    hCanvas->rgba.drawColour; }

#define SOY_drawPixelBlend(hCanvas, x, y) \
    hCanvas->rgba.data[(x)+(y)*hCanvas->rgba.width] = \
      SOY_alphaBlend( \
        hCanvas->rgba.data \
        [(x) + (y) *hCanvas->rgba.width], \
        hCanvas->rgba.drawColour)
#endif /* SOY_DEBUG */

typedef int32 (*PFDRAWINTERRUPT) (void);
PFDRAWINTERRUPT SOY_drawInterrupt = NULL;

int32 SOY_clipArea(soyCanvas* canvas) {
  return
    ((canvas->rgba.clipRect[2]) - 
    (canvas->rgba.clipRect[0])) *
    ((canvas->rgba.clipRect[3]) -
    (canvas->rgba.clipRect[1]));
}

int32 SOY_drawSetClipRect(soyCanvas* hCanvas,
    int32 x, int32 y, int32 w, int32 h) {
  SOY_ASSERT(x >= 0 && x <= hCanvas->rgba.width);
  SOY_ASSERT(y >= 0 && y <= hCanvas->rgba.height);
  SOY_ASSERT(w >= 0 && w <= hCanvas->rgba.width);
  SOY_ASSERT(h >= 0 && h <= hCanvas->rgba.height);
  hCanvas->rgba.clipRectPrev[0] = hCanvas->rgba.clipRect[0];
  hCanvas->rgba.clipRectPrev[1] = hCanvas->rgba.clipRect[1];
  hCanvas->rgba.clipRectPrev[2] = hCanvas->rgba.clipRect[2];
  hCanvas->rgba.clipRectPrev[3] = hCanvas->rgba.clipRect[3];
  hCanvas->rgba.clipRect[0] = x;
  hCanvas->rgba.clipRect[1] = y;
  hCanvas->rgba.clipRect[2] = x + w;
  hCanvas->rgba.clipRect[3] = y + h;

  return TRUE;
}

int32 SOY_drawResetClipRect(soyCanvas* hCanvas) {
  hCanvas->rgba.clipRect[0] = hCanvas->rgba.clipRectPrev[0];
  hCanvas->rgba.clipRect[1] = hCanvas->rgba.clipRectPrev[1];
  hCanvas->rgba.clipRect[2] = hCanvas->rgba.clipRectPrev[2];
  hCanvas->rgba.clipRect[3] = hCanvas->rgba.clipRectPrev[3];
  return TRUE;
}


uint8 SOY_pixelGetChannel(soyPixel pix, int8 channel) {
  switch(channel) {
    case('a'): { return (pix >> 24) & 0xFF; }
    case('r'): { return (pix >> 16) & 0xFF; }
    case('g'): { return (pix >> 8) & 0xFF; }
    case('b'): { return (pix >> 0) & 0xFF; }
  }
  return 0;
}

soyPixel SOY_pixelDivide(soyPixel pix, int8 value) {
  if(!value) { return SOY_pixel(0, 0, 0, 255); }
  return SOY_pixel(
      ((pix >> 16) & 0xFF)/value,
      ((pix >> 8 ) & 0xFF)/value,
      ((pix >> 0 ) & 0xFF)/value,
      ((pix >> 24) & 0xFF));
}

soyPixel SOY_pixelAdd(soyPixel pix, int8 value) {
  return SOY_pixel(
      SOY_MAX(SOY_MIN(((pix >> 16) & 0xFF) + value, 255), 0),
      SOY_MAX(SOY_MIN(((pix >> 8 ) & 0xFF) + value, 255), 0),
      SOY_MAX(SOY_MIN(((pix >> 0 ) & 0xFF) + value, 255), 0),
      ((pix >> 24) & 0xFF));
}

soyPixel SOY_pixelMul(soyPixel pix, int8 value) {
  return SOY_pixel(
      SOY_MIN(((pix >> 16) & 0xFF)*value, 255),
      SOY_MIN(((pix >> 8 ) & 0xFF)*value, 255),
      SOY_MIN(((pix >> 0 ) & 0xFF)*value, 255),
      ((pix >> 24) & 0xFF));
}

soyPixel SOY_colourLerp(soyPixel s, soyPixel e, real32 t) {
	vec4f start = SOY_pixelToVec4f(s);
	vec4f end = SOY_pixelToVec4f(e);
    return SOY_pixel(
        (uint8)(SOY_lerp((real32)start.x, (real32)end.x, t)),
	    (uint8)(SOY_lerp((real32)start.y, (real32)end.y, t)),
	    (uint8)(SOY_lerp((real32)start.z, (real32)end.z, t)),
	    (uint8)(SOY_lerp((real32)start.w, (real32)end.w, t)));
}

soyPixel SOY_pixelMix(soyPixel a, soyPixel b, real32 value) {
  return SOY_colourLerp(a, b, value);
}

int32 SOY_pixelSetChannel(soyPixel* pix, int32 val, int8 channel) {
  soyPixel ret = 0;
  int32 cval =  SOY_MIN(SOY_MAX(val, 0), 255);
  switch(channel) {
    case('a'): {
      ret = (*pix & 0x00FFFFFF);
      ret |= (cval << 24);
      break;
    }
    case('r'): {
      ret = (*pix & 0xFF00FFFF);
      ret |= (cval << 16);
      break;
    }
    case('g'): {
      ret = (*pix & 0xFFFF00FF);
      ret |= (cval << 8);
      break;
    }
    case('b'): {
      ret = (*pix & 0xFFFFFF00);
      ret |= (cval);
      break;
    }
  }
  *pix = ret;
  return TRUE;
}

soyPixel SOY_alphaBlendPremultiplied(soyPixel bg, soyPixel fg) {
  real32x4 bgp = SOY_MM_real32x4(
      (real32)((bg >> 24) & 0xFF),
      (real32)((bg >> 16) & 0xFF),
      (real32)((bg >> 8) & 0xFF),
      (real32)((bg) & 0xFF));
  real32x4 fgp = SOY_MM_real32x4(
      (real32)((fg >> 24) & 0xFF),
      (real32)((fg >> 16) & 0xFF),
      (real32)((fg >> 8) & 0xFF),
      (real32)((fg) & 0xFF));
  real32x4 bgpp = SOY_MM_divReal32x4(bgp, SOY_MM_real32x4Broad(255.0f));
  real32x4 fgpp = SOY_MM_divReal32x4(fgp, SOY_MM_real32x4Broad(255.0f));
  real32x4 invFg = SOY_MM_subReal32x4(
      SOY_MM_real32x4Broad(1.0f),
      SOY_MM_real32x4Broad((real32)(fg & 0xFF)/255.0f));
  real32x4 result = SOY_MM_addReal32x4(fgpp, SOY_MM_mulReal32x4(invFg, bgpp));
  uint8 r = (uint8)(SOY_MM_real32x4Index(result, 3)*255.0f);
  uint8 g = (uint8)(SOY_MM_real32x4Index(result, 2)*255.0f);
  uint8 b = (uint8)(SOY_MM_real32x4Index(result, 1)*255.0f);
  return SOY_pixel(r, g, b, 255);
}

soyPixel SOY_alphaBlend(soyPixel bg, soyPixel fg) {
  real32x4 bgp = SOY_MM_real32x4(
      (real32)((bg >> 16) & 0xFF),
      (real32)((bg >> 8) & 0xFF),
      (real32)((bg >> 0) & 0xFF),
      (real32)((bg >> 24) & 0xFF));
  real32x4 fgp = SOY_MM_real32x4(
      (real32)((fg >> 16) & 0xFF),
      (real32)((fg >> 8) & 0xFF),
      (real32)((fg >> 0) & 0xFF),
      (real32)((fg >> 24) & 0xFF));
  real32x4 bgpp = SOY_MM_divReal32x4(bgp, SOY_MM_real32x4Broad(255.0f));
  real32x4 fgpp = SOY_MM_divReal32x4(fgp, SOY_MM_real32x4Broad(255.0f));
  real32x4 tempAlphas = SOY_MM_real32x4Broad((real32)((fg>>24)&0xFF)/255.0f);
  real32x4 invFg = SOY_MM_subReal32x4(SOY_MM_real32x4Broad(1.0f), tempAlphas);
  real32x4 fgResult = SOY_MM_mulReal32x4(tempAlphas, fgpp);
  real32x4 bgResult = SOY_MM_mulReal32x4(invFg, bgpp);
  real32x4 result = SOY_MM_addReal32x4(fgResult, bgResult);
  uint8 r = (uint8)(SOY_MM_real32x4Index(result, 3)*255.0f);
  uint8 g = (uint8)(SOY_MM_real32x4Index(result, 2)*255.0f);
  uint8 b = (uint8)(SOY_MM_real32x4Index(result, 1)*255.0f);
  return SOY_pixel(r, g, b, 255);
}

int32 SOY_canvasCreate(soyMemorySector* memory, soyCanvas* canvas,
    int32 width, int32 height) {
  SOY_LOG3("Creating %dx%d canvas at [%p]\n", width, height, (void*)memory);
  if(memory) {
    SOY_ASSERT(
        (size_t)width*height*sizeof(soyPixel) + memory->offset <
        (size_t)memory->size);
    canvas->rgba.data = (soyPixel*)(memory->base + memory->offset);
  } else {
    SOY_LOG("Warning: memory for canvas is NULL!\n");
    return FALSE;
  }
  canvas->rgba.maxSizeInBytes = memory->size - memory->offset;
  canvas->rgba.width = width;
  canvas->rgba.height = height;
  canvas->rgba.drawColour = SOY_pixel(0, 0, 0, 255);
  SOY_memorySet(canvas->rgba.clipRectPrev, 0, 4*sizeof(int32));
  SOY_memorySet(canvas->rgba.clipRect, 0, 4*sizeof(int32));
  SOY_drawSetClipRect(canvas, 0, 0, canvas->rgba.width, canvas->rgba.height);
  memory->offset += width*height*sizeof(soyPixel);
  return TRUE;
}

int32 SOY_canvasCreateDepth(soyMemorySector* memory, soyCanvas* canvas,
    int32 width, int32 height) {
  SOY_LOG3("Creating %dx%d canvas at [%p]\n", width, height, (void*)memory);
  if(memory) {
    SOY_ASSERT(
        (size_t)width*height*sizeof(real32) + memory->offset <
        (size_t)memory->size);
    canvas->depth.data = (real32*)(memory->base + memory->offset);
  } else {
    SOY_LOG("Warning: memory for canvas is NULL!\n");
    return FALSE;
  }
  canvas->depth.maxSizeInBytes = memory->size - memory->offset;
  canvas->depth.width = width;
  canvas->depth.height = height;
  SOY_drawSetClipRect(canvas, 0, 0, canvas->rgba.width, canvas->rgba.height);
  memory->offset += width*height*sizeof(real32);
  return TRUE;
}

int32 SOY_canvasResize(soyCanvas* canvas,
    int32 width, int32 height) {
  SOY_ASSERT(
      (size_t)canvas->rgba.maxSizeInBytes >
      (size_t)width*height*sizeof(soyPixel));
  canvas->rgba.width = width;
  canvas->rgba.height = height;
  SOY_drawSetClipRect(canvas, 0, 0, canvas->rgba.width, canvas->rgba.height);
  return TRUE;
}

int32 SOY_canvasCopy(soyCanvas* dest, soyCanvas* src,
    int32 xPos, int32 yPos) {
  int32 y;
  int32 srcWidth = src->rgba.width;
  int32 srcHeight = src->rgba.height;
  int32 destWidth = dest->rgba.width;
  int32 destHeight = dest->rgba.height;
  int32 clipRectX1 = (xPos >= 0) ? 0 : SOY_MIN(SOY_abs(xPos), srcWidth);
  int32 clipRectX2 = (xPos + srcWidth < destWidth)
    ? srcWidth
    : srcWidth - ((xPos + srcWidth) - destWidth);
  int32 clipRectY1 = (yPos >= 0) ? 0 : SOY_MIN(SOY_abs(yPos), srcHeight);
  int32 clipRectY2 = (yPos + srcHeight < destHeight)
    ? srcHeight
    : srcHeight - ((yPos + srcHeight) - destHeight);
  if(xPos + srcWidth < 0 || xPos >= destWidth) { return FALSE; }
  if(yPos + srcHeight < 0 || yPos >= destHeight) { return FALSE; }
  xPos = SOY_MAX(0, xPos);
  yPos = SOY_MAX(0, yPos);
  for(y = 0; y < clipRectY2 - clipRectY1; y++) {
    SOY_memoryCopy(
        (uint8*)(dest->rgba.data + xPos + (yPos + y)*destWidth),
        (uint8*)(src->rgba.data + clipRectX1 +  (y + clipRectY1)*srcWidth),
        (clipRectX2 - clipRectX1)*sizeof(soyPixel));
  }
  return TRUE;
}

int32 SOY_canvasClipCopy(soyCanvas* dest, soyCanvas* src,
    int32 xPos, int32 yPos,
    int32 clipX1, int32 clipY1, int32 clipX2, int32 clipY2) {
  int32 x, y;
  int32 width = clipX2 - clipX1;
  int32 height = clipY2 - clipY1;
  for(y = 0; y < height; y++) {
    for(x = 0; x < width; x++) {
      SOY_drawSetColour(dest, SOY_drawSample(src, clipX1 + x, clipY1 + y));
      if(SOY_pixelGetChannel(dest->rgba.drawColour, 'a') == 255) {
        SOY_drawPixel(dest, xPos + x, yPos + y);
      }
    }
  }
  return TRUE;
}

int32 SOY_canvasStretch(soyCanvas* dest, soyCanvas* src,
    int32 xPos, int32 yPos, int32 width, int32 height) {
  int32 x, y;
  int32 nx, ny;
  soyPixel sample;
  int32 srcWidth = src->rgba.width;
  int32 srcHeight = src->rgba.height;
  int32 destWidth = dest->rgba.width;
  int32 destHeight = dest->rgba.height;
  int32 clipX = (xPos >= 0) ? 0 : SOY_MIN(SOY_abs(xPos), srcWidth);
  int32 clipY = (yPos >= 0) ? 0 : SOY_MIN(SOY_abs(yPos), srcHeight);
  if(xPos + width < 0 || xPos >= destWidth) { return FALSE; }
  if(yPos + height < 0 || yPos >= destHeight) { return FALSE; }
  for(y = clipY; y < height; y++) {
    ny = (int32)(((real32)(y) / (real32)height)*(real32)srcHeight);
    for(x = clipX; x < width; x++) {
      nx = (int32)(((real32)(x) / (real32)width)*(real32)srcWidth);
      sample = src->rgba.data[nx + ny*srcWidth];
      dest->rgba.data[x + xPos + (y + yPos)*destWidth] = sample;
    }
  }
  return TRUE;
}

int32 SOY_canvasBlit(soyWindow window, soyCanvas* canvas) {
  return SOY_windowBlit(window,
      (uint8*)canvas->rgba.data, canvas->rgba.width, canvas->rgba.height);
}

soyPixel SOY_drawGetColour(soyCanvas* hCanvas) {
  return hCanvas->rgba.drawColour;
}

int32 SOY_drawClear(soyCanvas* hCanvas) {
  int32 x, y;
  for(y = 0; y < hCanvas->rgba.height; y++) {
    for(x = 0; x < hCanvas->rgba.width; x++) {
    hCanvas->rgba.data[x+y*hCanvas->rgba.width] =
      hCanvas->rgba.drawColour;
    }
  }
  return TRUE;
}

int32 SOY_depthClear(soyCanvas* hCanvas) {
  int32 x, y;
  for(y = 0; y < hCanvas->depth.height; y++) {
    for(x = 0; x < hCanvas->depth.width; x++) {
      hCanvas->depth.data[x+y*hCanvas->depth.width] = 0.0f;
    }
  }
  return TRUE;
}

/*
* o-------------------------------------------o
* | @draw:text                                |
* o-------------------------------------------o
*/

#define SOY_MAX_FONT_MEMORY 32*32
#define SOY_MAX_DRAW_STRING 1024
#define SOY_MAX_FONT_GLYPHS 256

SOY_GLOBAL int8 g_soyDrawTextBuffer[SOY_MAX_DRAW_STRING];

typedef struct tag_soyFontFragment {
  uint8 x;
  uint8 y;
} soyFontFragment;

typedef struct tag_soyFontCharInfo {
  soyFontFragment fragments[SOY_MAX_FONT_MEMORY];
  int32 kerning;
  int32 fragCount;
} soyFontCharInfo;

typedef struct tag_soyFontData {
  int32 drawWidth;
  int32 drawHeight;
  int32 drawScale;
  int32 scaledDrawWidth;
  int32 scaledDrawHeight;
} soyFontData;

typedef struct tag_soyFont {
  int32 cellSize;
  soyFontData data;
  soyFontCharInfo glyphs[SOY_MAX_FONT_GLYPHS];
} soyFont;

int32 SOY_saveFont(soyFont* font, int8* filename) {
  int8 hdr[8] = { 'S', 'O', 'Y', 'F', 'O', 'N', 'T', '\n' };
  FILE* file = SOY_fileOpen(filename, "wb");
  if(file) {
    fwrite(hdr, sizeof(int8)*8, 1, file);
    fwrite(font, sizeof(font), 1, file);
    SOY_fileClose(file);
    return TRUE;
  } else {
    return FALSE;
  }
}

int32 SOY_loadFont(soyFont* font, int8* filename) {
  int8 hdr[8];
  FILE* file = SOY_fileOpen(filename, "rb");
  if(file) {
    fread(hdr, sizeof(int8)*8, 1, file);
    fread(font, sizeof(font), 1, file);
    SOY_fileClose(file);
    return TRUE;
  } else {
    return FALSE;
  }
}

uint16 testmemory[5000];

int32 SOY_packFont(uint16* memory,
    size_t memorySize, soyCanvas* fontBitmap,
    int32 tileSize, int32 rowCount, int32 columnCount) {
  int32 x, y;
  int32 ix, iy;
  int32 index = 0;
  uint32 bitArray = 0;
  uint32 bitIndex = 0;
  soyPixel curPixel;
  SOY_ASSERT(tileSize < 16);
  SOY_UNUSED(memorySize);
  for(iy = 0; iy < rowCount; iy++) {
    for(ix = 0; ix < columnCount; ix++) {
      for(y = iy*tileSize; y - iy*tileSize < tileSize; y++) {
        bitIndex = 0;
        bitArray = 0;
        for(x = ix*tileSize; x - ix*tileSize < tileSize; x++) {
          curPixel = fontBitmap->rgba.data[x+y*fontBitmap->rgba.width];
          if(curPixel == 0xFFFFFFFF) {
            bitArray = (bitArray | (1 << bitIndex));
          }
          bitIndex++;
        }
        memory[index] = bitArray;
        index++;
      }
    }
  }
  return 0;
}

int32 SOY_packFontToFile(soyCanvas* fontBitmap,
    int32 columnCount, int32 rowCount, int32 tileSize, int8* filename) {
  int32 x, y;
  int32 ix, iy;
  void* file;
  uint32 bitArray = 0;
  uint32 bitIndex = 0;
  soyPixel curPixel;
  SOY_ASSERT(tileSize < 32);
  SOY_LOG1("Packing font \"%s\" to file", filename);
  file = SOY_fileOpen(filename, "w");
  fprintf(file, "#define FONT_TILE_SIZE %d\n", tileSize);
  fprintf(file, "const unsigned int packedFont[%d] = {\n",
      columnCount*rowCount*tileSize);
  for(iy = 0; iy < rowCount; iy++) {
    for(ix = 0; ix < columnCount; ix++) {
      for(y = iy*tileSize; y - iy*tileSize < tileSize; y++) {
        bitIndex = 0;
        bitArray = 0;
        for(x = ix*tileSize; x - ix*tileSize < tileSize; x++) {
          curPixel = fontBitmap->rgba.data[x+y*fontBitmap->rgba.width];
          if(curPixel == 0xFFFFFFFF) {
            bitArray = (bitArray | (1 << bitIndex));
          }
          bitIndex++;
        }
        fprintf(file, "%d,", bitArray);
      }
      fprintf(file, "\n");
    }
  }
  fprintf(file, "};\n");
  SOY_LOG("Closing file\n");
  SOY_fileClose(file);
  return 0;
}

int32 SOY_unpackFont(soyFont* font,
    const uint16* elements, int32 glyphs, int32 cellSize) {
  int32 i, j, bitIndex;
  int32 curTestBit;
  int32 maxX = 0;
  for(i = 0; i < SOY_MAX_FONT_GLYPHS; i++) {
    maxX = 0;
    for(j = 0; j < cellSize; j++) {
      for(bitIndex = 0; bitIndex < cellSize; bitIndex++) {
        if(i < glyphs) {
          curTestBit = elements[j + i*cellSize] & (1 << bitIndex);
          if(curTestBit) {
            font->glyphs[i].fragments[font->glyphs[i].fragCount].x =
              bitIndex;
            font->glyphs[i].fragments[font->glyphs[i].fragCount].y = j;
            font->glyphs[i].fragCount++;
            if(bitIndex > maxX) {
              maxX = bitIndex;
            }
          }
        } else {
          font->glyphs[i].fragments[font->glyphs[i].fragCount].x = bitIndex;
          font->glyphs[i].fragments[font->glyphs[i].fragCount].y = j;
          font->glyphs[i].fragCount++;
        }
      }
    }
    if(i == ' ') {
      font->glyphs[i].kerning = cellSize/2;
    } else {
      font->glyphs[i].kerning = maxX + 1;
    }
  }
  font->data.drawWidth = cellSize;
  font->data.drawHeight = cellSize;
  font->data.drawScale = 1;
  font->data.scaledDrawWidth = cellSize;
  font->data.scaledDrawHeight = cellSize;
  font->cellSize = cellSize;
  return TRUE;
}

int32 SOY_drawSetFontData(soyFont* font,
    int32 width, int32 height, int32 scale) {
  font->data.drawScale = scale;
  font->data.drawWidth = width;
  font->data.drawHeight = height;
  font->data.scaledDrawWidth = width*scale;
  font->data.scaledDrawHeight = height*scale;
  return TRUE;
}

soyFontData SOY_drawGetFontData(soyFont* font) {
  return font->data;
}

int32 SOY_drawBitmask(soyCanvas* hCanvas, int32 x, int32 y,
    int32 width, int32 height, uint32* bitmask) {
  int32 ix, iy;
  int32 bmx = 0;
  int32 bmy = 0;
  for(iy = y; iy < y + height; iy++) {
    bmx = 0;
    for(ix = x; ix < x + width; ix++) {
      if(bitmask[bmy] & (1 << bmx)) {
        SOY_drawPixelClip(
            hCanvas,
            ix, iy,
            0, 0,
            hCanvas->rgba.width, hCanvas->rgba.height);
      }
      bmx++;
    }
    bmy++;
  }
  return TRUE;
}

int32 SOY_drawChar(soyCanvas* hCanvas, soyFont* font,
    int32 x, int32 y, int8 chr) {
  int32 w = 0;
  int32 h = 0;
  int32 sx, sy, scx, scy;
  int32 cw, ch;
  int32 cx, cy;
  int32 fx;
  soyPixel col = SOY_drawGetColour(hCanvas);
  int32 dw = hCanvas->rgba.width;
  int32 dh = hCanvas->rgba.height;
  int32* clip = hCanvas->rgba.clipRect;
  int8 curChar = chr;
  uint8 glyphIndex = (uint8)curChar;
  cw = font->data.drawWidth*font->data.drawScale;
  ch = font->data.drawHeight*font->data.drawScale;
  cx = w*cw;
  cy = h*ch;
  if(cx + cw >= 0 && cx <= dw && cy + ch >= 0 && cy <= dh) {
    glyphIndex = (uint8)curChar;
    for(fx = 0; fx < font->glyphs[(uint8)curChar].fragCount; fx++) {
      for(sy = 0; sy < font->data.drawScale; sy++) {
        for(sx = 0; sx < font->data.drawScale; sx++) {
          scx = x+sx+font->glyphs[glyphIndex].fragments[fx].x*
            font->data.drawScale+cx;
          scy = y+sy+font->glyphs[glyphIndex].fragments[fx].y*
            font->data.drawScale+cy;
          if(SOY_boundsCheck(scx, scy,
                clip[0], clip[1], clip[2], clip[3])) {
            if(col >> 24 == 255) {
              SOY_drawPixel(hCanvas, scx, scy);
            } else {
              SOY_drawPixelBlend(hCanvas, scx, scy);
            }
          }
        }
      }
    }
  }
  SOY_drawSetColour(hCanvas, col);
  return TRUE;
}

int32 SOY_drawTextMono(soyCanvas* hCanvas, soyFont* font,
    int32 x, int32 y, int8* text) {
  int32 i = 0;
  int32 h = 0;
  int32 sx, sy, scx, scy;
  int32 cw, ch;
  int32 cx, cy;
  int32 fx;
  soyPixel col = SOY_drawGetColour(hCanvas);
  int32 dw = hCanvas->rgba.width;
  int32 dh = hCanvas->rgba.height;
  int32* clip = hCanvas->rgba.clipRect;
  int8 curChar = text[0];
  uint8 glyphIndex = (uint8)curChar;
  cx = 0;
  cy = 0;
  while((curChar = text[i++])) {
    while(curChar == '\n' && curChar) {
      h++;
      cx = 0;
      curChar = text[i++];
    }
    ch = font->data.drawHeight*font->data.drawScale;
    cw = font->data.drawWidth*font->data.drawScale;
    cy = h*ch;
    if(cx + cw >= 0 && cx <= dw && cy + ch >= 0 && cy <= dh) {
      glyphIndex = (uint8)curChar;
      for(fx = 0; fx < font->glyphs[(uint8)curChar].fragCount; fx++) {
        for(sy = 0; sy < font->data.drawScale; sy++) {
          for(sx = 0; sx < font->data.drawScale; sx++) {
            scx = x+sx+font->glyphs[glyphIndex].fragments[fx].x*
              font->data.drawScale+cx;
            scy = y+sy+font->glyphs[glyphIndex].fragments[fx].y*
              font->data.drawScale+cy;
            if(SOY_boundsCheck(scx, scy,
                  clip[0], clip[1], clip[2], clip[3])) {
              if(col >> 24 == 255) {
                SOY_drawPixel(hCanvas, scx, scy);
              } else {
                SOY_drawPixelBlend(hCanvas, scx, scy);
              }
            }
          }
        }
      }
    }
    cx += cw;
  }
  SOY_drawSetColour(hCanvas, col);
  return TRUE;
}

int32 SOY_drawText(soyCanvas* hCanvas, soyFont* font,
    int32 x, int32 y, int8* text) {
  int32 i = 0;
  int32 h = 0;
  int32 sx, sy, scx, scy;
  int32 cw, ch;
  int32 cx, cy;
  int32 fx;
  int32 maxX = 0;
  soyPixel col = SOY_drawGetColour(hCanvas);
  int32 dw = hCanvas->rgba.width;
  int32 dh = hCanvas->rgba.height;
  int32* clip = hCanvas->rgba.clipRect;
  int8 curChar = text[0];
  uint8 glyphIndex = (uint8)curChar;
  cx = 0;
  cy = 0;
  while((curChar = text[i++])) {
    while(curChar == '\n' && curChar) {
      h++;
      cx = 0;
      curChar = text[i++];
    }
    cw = font->glyphs[(uint8)curChar].kerning*font->data.drawScale;
    ch = font->data.drawHeight*font->data.drawScale;
    cy = h*ch;
    if(cx + cw >= 0 && cx <= dw && cy + ch >= 0 && cy <= dh) {
      glyphIndex = (uint8)curChar;
      for(fx = 0; fx < font->glyphs[(uint8)curChar].fragCount; fx++) {
        for(sy = 0; sy < font->data.drawScale; sy++) {
          for(sx = 0; sx < font->data.drawScale; sx++) {
            scx = x+sx+font->glyphs[glyphIndex].fragments[fx].x*
              font->data.drawScale+cx;
            scy = y+sy+font->glyphs[glyphIndex].fragments[fx].y*
              font->data.drawScale+cy;
            if(SOY_boundsCheck(scx, scy,
                  clip[0], clip[1], clip[2], clip[3])) {
              if(col >> 24 == 255) {
                SOY_drawPixel(hCanvas, scx, scy);
              } else {
                SOY_drawPixelBlend(hCanvas, scx, scy);
              }
            }
          }
        }
      }
    }
    if(cx > maxX) { maxX = cx; }
    cx += cw;
  }
  SOY_drawSetColour(hCanvas, col);
  return maxX;
}

int32 SOY_drawTextWidth(soyFont* font, int8* text) {
  int32 i = 0;
  int32 h = 0;
  int32 cw;
  int32 cx;
  int32 maxX = 0;
  int8 curChar = text[0];
  cx = 0;
  while((curChar = text[i++])) {
    while(curChar == '\n' && curChar) {
      h++;
      cx = 0;
      curChar = text[i++];
    }
    cw = font->glyphs[(uint8)curChar].kerning*font->data.drawScale;
    cx += cw;
    if(cx > maxX) { maxX = cx; }
  }
  return maxX;
}

int32 SOY_drawTextWidthMono(soyFont* font, int8* text) {
  int32 i = 0;
  while(i < 512 && text[i]) {
    if(text[i] == '\n') { break; }
    i++;
  }
  return i*font->data.scaledDrawWidth;
}

uint32 SOY_drawTextFlush() {
  SOY_memorySet(g_soyDrawTextBuffer, 0, sizeof(g_soyDrawTextBuffer));
  return TRUE;
}

int32 SOY_drawTextFormat(soyCanvas* hCanvas, soyFont* font,
    int32 x, int32 y, int8* format, ...) {
  va_list args;
  SOY_drawTextFlush();
  va_start(args, format);
  vsnprintf(g_soyDrawTextBuffer, SOY_MAX_DRAW_STRING, format, args);
  va_end(args);
  SOY_drawText(hCanvas, font, x, y, g_soyDrawTextBuffer);
  return TRUE;
}

int32 SOY_drawTextMonoFormat(soyCanvas* hCanvas, soyFont* font,
    int32 x, int32 y, int8* format, ...) {
  va_list args;
  SOY_drawTextFlush();
  va_start(args, format);
  vsnprintf(g_soyDrawTextBuffer, SOY_MAX_DRAW_STRING, format, args);
  va_end(args);
  SOY_drawTextMono(hCanvas, font, x, y, g_soyDrawTextBuffer);
  return TRUE;
}

int32 SOY_drawTextBold(soyCanvas* hCanvas, soyFont* font,
    int32 x, int32 y, int8* text) {
  SOY_drawText(hCanvas, font, x, y, text);
  SOY_drawText(hCanvas, font, x + 1, y, text);
  return TRUE;
}

int32 SOY_drawTextMonoFormatBold(soyCanvas* hCanvas, soyFont* font,
    int32 x, int32 y, int8* format, ...) {
  va_list args;
  va_start(args, format);
  vsnprintf(g_soyDrawTextBuffer, SOY_MAX_DRAW_STRING, format, args);
  va_end(args);
  SOY_drawTextMono(hCanvas, font, x, y, g_soyDrawTextBuffer);
  SOY_drawTextMono(hCanvas, font, x+1, y, g_soyDrawTextBuffer);
  return TRUE;
}

int32 SOY_drawTextFormatBold(soyCanvas* hCanvas, soyFont* font,
    int32 x, int32 y, int8* format, ...) {
  va_list args;
  va_start(args, format);
  vsnprintf(g_soyDrawTextBuffer, SOY_MAX_DRAW_STRING, format, args);
  va_end(args);
  SOY_drawText(hCanvas, font, x, y, g_soyDrawTextBuffer);
  SOY_drawText(hCanvas, font, x+1, y, g_soyDrawTextBuffer);
  return TRUE;
}

/*
* o-------------------------------------------o
* | @draw:pixel                               |
* o-------------------------------------------o
*/

#ifndef SOY_NO_MATH

typedef vec4f (*PFCANVASFILL)
  (real32 u, real32 v);

  int32 SOY_canvasMap(soyCanvas* canvas, PFCANVASFILL fillProc) {
  int32 x, y;
  real32 w = 1.0f / (real32)canvas->rgba.width;
  real32 h = 1.0f / (real32)canvas->rgba.height;
  real32 rx = 0.0f;
  real32 ry = 0.0f;
  vec4f res;
  if(!fillProc) { return FALSE; }
  for(y = 0; y < canvas->rgba.width; y++) {
    for(x = 0; x < canvas->rgba.height; x++) {
      rx = ((real32)(x)) * w;
      ry = ((real32)(y)) * h;
      res = fillProc(rx, ry);
      res = v4MulS(res, 255.0f);
      canvas->rgba.data[x + y*canvas->rgba.width] = V4RGBA(res);
    }
  }
  return TRUE;
}

int32 SOY_drawOverlay(soyCanvas* canvas, PFCANVASFILL fillProc) {
  int32 x, y;
  real32 w = 1.0f / (real32)canvas->rgba.width;
  real32 h = 1.0f / (real32)canvas->rgba.height;
  real32 rx = 0.0f;
  real32 ry = 0.0f;
  vec4f res;
  if(!fillProc) { return FALSE; }
  for(y = 0; y < canvas->rgba.height; y++) {
    for(x = 0; x < canvas->rgba.width; x++) {
      rx = ((real32)(x)) * w;
      ry = ((real32)(y)) * h;
      res = fillProc(rx, ry);
      res = v4MulS(res, 255.0f);
      canvas->rgba.data[x + y*canvas->rgba.width] = V4RGBA(res);
    }
  }
  return TRUE;
}

#endif /* SOY_NO_MATH */

int32 SOY_drawFade(soyCanvas* canvas,
    int32 x1, int32 y1, int32 x2, int32 y2) {
  int32 x, y;
  for(y = y1; y < y2; y++) {
    for(x = x1; x < x2; x++) {
      SOY_drawPixelBlend(canvas, x, y);
    }
  }
  return TRUE;
}

int32 SOY_drawDepthbuffer(soyCanvas* canvas, soyCanvas* depthbuffer) {
  int32 x, y;
  soyPixel curPixel;
  int32 width = depthbuffer->depth.width;
  int32 height = depthbuffer->depth.height;
  for(y = 0; y < height; y++) {
    for(x = 0; x < width; x++) {
      curPixel = SOY_pixel(
          (uint8)(depthbuffer->depth.data[x + y*width]*255.0f),
          (uint8)(depthbuffer->depth.data[x + y*width]*255.0f),
          (uint8)(depthbuffer->depth.data[x + y*width]*255.0f),
          255
          );
      SOY_drawSetColour(canvas, curPixel);
      SOY_drawPixel(canvas, x, y);
    }
  }
  return TRUE;
}

int32 SOY_drawLine(soyCanvas* canvas,
    real32 x1, real32 y1, real32 x2, real32 y2) {
  real32 dx, dy, dax, day, x, y, step;
  int32 i;
  soyPixel fg = SOY_drawGetColour(canvas);
  int32* clip = canvas->rgba.clipRect;
  soyPixel drawCol = SOY_drawGetColour(canvas);
  int32 canvWidth = canvas->rgba.width;
  int32 canvHeight = canvas->rgba.height;
  if(SOY_pixelGetChannel(drawCol, 'a') == 0) { return FALSE; }
  if(x1 < 0 && x2 < 0) { return FALSE; }
  else if(x1 >= canvWidth && x2 > canvWidth) { return FALSE; }
  if(y1 < 0 && y2 < 0) { return FALSE; }
  else if(y1 >= canvHeight && y2 >= canvHeight) { return FALSE; }
  dx = (x2 - x1);
  dy = (y2 - y1);
  dax = SOY_fabs(dx);
  day = SOY_fabs(dy);
  step = ((dax >= day) ? dax : day);
  dx /= step;
  dy /= step;
  x = x1;
  y = y1;
  i = 0;
  if(SOY_pixelGetChannel(drawCol, 'a') == 255) {
    while(i <= (int32)step) {
      SOY_drawPixelClip(canvas, (int32)(x + 0.5f),(int32)(y + 0.5f),
          clip[0], clip[1], clip[2], clip[3]);
      if(x < canvWidth - 1) { x += dx; }
      if(y < canvHeight - 1) { y += dy; }
      i += 1;
    }
  } else {
    fg = drawCol;
    while(i <= (int32)step) {
      if(SOY_boundsCheck((int32)x, (int32)y,
            clip[0], clip[1], clip[2], clip[3])) {
        SOY_drawSetColour(canvas, fg);
        SOY_drawPixelBlend(canvas, (int32)(x + 0.5f), (int32)(y + 0.5f));
      }
      if(x < canvWidth - 1) { x += dx; }
      if(y < canvHeight - 1) { y += dy; }
      i += 1;
    }
  }
  return TRUE;
}

/* no line overlap, like in standard Bresenham */
#define SOY_LINE_OVERLAP_NONE 0 
/* overlap - first go major then minor direction.
 * pixel is drawn as extension after actual line
 */
#define SOY_LINE_OVERLAP_MAJOR 0x01 
/* overlap - first go minor then major direction.
 * pixel is drawn as extension before next line
 */
#define SOY_LINE_OVERLAP_MINOR 0x02 
/* overlap - both */
#define SOY_LINE_OVERLAP_BOTH 0x03  

/* start point is on the line at center of the thick line */
#define SOY_LINE_THICKNESS_MIDDLE 0 
/* start point is on the counter clockwise border line */
#define SOY_LINE_THICKNESS_DRAW_CLOCKWISE 1
/* start point is on the clockwise border line */
#define SOY_LINE_THICKNESS_DRAW_COUNTERCLOCKWISE 2

int32 SOY_drawLineOverlap(soyCanvas* canvas,
    uint32 x1, uint32 y1, uint32 x2, uint32 y2,
    uint32 overlap) {
  int32 dx, dy, dx2, dy2, err, tStepX, tStepY;
  int32* clipRect = canvas->rgba.clipRect;
  dx = x2 - x1;
  dy = y2 - y1;
  if (dx < 0) {
    dx = -dx;
    tStepX = -1;
  } else {
    tStepX = +1;
  }
  if (dy < 0) {
    dy = -dy;
    tStepY = -1;
  } else {
    tStepY = +1;
  }
  dx2 = dx << 1;
  dy2 = dy << 1;
  SOY_drawPixelClipToRect(canvas, x1, y1, clipRect);
  if (dx > dy) {
    err = dy2 - dx;
    while (x1 != x2) {
      x1 += tStepX;
      if (err >= 0) {
        if (overlap & SOY_LINE_OVERLAP_MAJOR) {
          SOY_drawPixelClipToRect(canvas, x1, y1, clipRect);
        }
        y1 += tStepY;
        if (overlap & SOY_LINE_OVERLAP_MINOR) {
          SOY_drawPixelClipToRect(canvas, x1 - tStepX, y1, clipRect);
        }
        err -= dx2;
      }
      err += dy2;
      SOY_drawPixelClipToRect(canvas, x1, y1, clipRect);
    }
  } else {
    err = dx2 - dy;
    while (y1 != y2) {
      y1 += tStepY;
      if (err >= 0) {
        if (overlap & SOY_LINE_OVERLAP_MAJOR) {
          SOY_drawPixel(canvas, x1, y1);
        }
        x1 += tStepX;
        if (overlap & SOY_LINE_OVERLAP_MINOR) {
          SOY_drawPixelClipToRect(canvas, x1, y1 - tStepY, clipRect);
        }
        err -= dy2;
      }
      err += dx2;
      SOY_drawPixelClipToRect(canvas, x1, y1, clipRect);
    }
  }
  return TRUE;
}

uint32 SOY_drawLineThick(soyCanvas* canvas,
  uint32 x1, uint32 y1, uint32 x2, uint32 y2,
  uint32 thickness, uint8 mode) {
  int32 overlap;
  int32 i, dx, dy, dx2, dy2, err, stepX, stepY;
  int32 canvWidth = canvas->rgba.width;
  int32 canvHeight = canvas->rgba.height;
  int32 swap = TRUE;
  int32 drawStartCount = thickness / 2;
  if(thickness <= 1) {
    return SOY_drawLine(canvas, x1, y1, x2, y2);
  }
  if(x1 < 0 && x2 < 0) { return FALSE; }
  else if(x1 >= canvWidth && x2 > canvWidth) { return FALSE; }
  if(y1 < 0 && y2 < 0) { return FALSE; }
  else if(y1 >= canvHeight && y2 >= canvHeight) { return FALSE; }
  dx = y2 - y1;
  dy = x2 - x1;
  if(dx < 0) {
    dx = -dx;
    stepX = - 1;
    swap = !swap;
  } else {
    stepX = 1;
  }
  if(dy < 0) {
    dy = -dy;
    stepY = - 1;
    swap = !swap;
  } else {
    stepY = 1;
  }
  dx2 = dx << 1;
  dy2 = dy << 1;
  if(mode == SOY_LINE_THICKNESS_DRAW_COUNTERCLOCKWISE) {
    drawStartCount = thickness - 1;
  } else if(mode == SOY_LINE_THICKNESS_DRAW_CLOCKWISE) {
    drawStartCount = 0;
  }
  if(dx >= dy) {
    if(swap) {
      drawStartCount = (thickness - 1) - drawStartCount;
      stepY = -stepY;
    } else {
      stepX = -stepX;
    }
    err = dy2 - dx;
    for(i = drawStartCount; i > 0; i--) {
      x1 -= stepX;
      x2 -= stepX;
      if(err >= 0) {
        y1 -= stepY;
        y2 -= stepY;
        err -= dx2;
      }
      err += dy2;
    }
    SOY_drawLineOverlap(canvas, x1, y1, x2, y2, 0);
    err = dy2 - dx;
    for(i = thickness; i > 1; i--) {
      x1 += stepX;
      x2 += stepX;
      overlap = SOY_LINE_OVERLAP_NONE;
      if(err >= 0) {
        y1 += stepY;
        y2 += stepY;
        err -= dx2;
        overlap = SOY_LINE_OVERLAP_MAJOR;
      }
      err += dy2;
      SOY_drawLineOverlap(canvas, x1, y1, x2, y2, overlap);
    }
  } else {
    if(swap) {
      stepX = -stepX;
    } else {
      drawStartCount = (thickness - 1) - drawStartCount;
      stepY = -stepY;
    }
    err = dx2 - dy;
    for(i = drawStartCount; i > 0; i--) {
      y1 -= stepY;
      y2 -= stepY;
      if(err >= 0) {
        x1 -= stepX;
        x2 -= stepX;
        err -= dy2;
      }
      err += dx2;
    }
    SOY_drawLineOverlap(canvas, x1, y1, x2, y2, 0);
    err = dx2 - dy;
    for(i = thickness; i > 1; i--) {
      y1 += stepY;
      y2 += stepY;
      overlap = SOY_LINE_OVERLAP_NONE;
      if(err >= 0) {
        x1 += stepX;
        x2 += stepX;
        err -= dy2;
        overlap = SOY_LINE_OVERLAP_MAJOR;
      }
      err += dx2;
      SOY_drawLineOverlap(canvas, x1, y1, x2, y2, overlap);
    }
  }
  return TRUE;
}

int32 SOY_drawLineGradient(soyCanvas* canvas,
    real32 x1, real32 y1, real32 x2, real32 y2,
    soyPixel colA, soyPixel colB) {
  real32 dx, dy, dax, day, x, y, step;
  real32 t;
  int32 i;
  int32* clip = canvas->rgba.clipRect;
  soyPixel drawCol = SOY_drawGetColour(canvas);
  int32 canvWidth = canvas->rgba.width;
  int32 canvHeight = canvas->rgba.height;
  if(SOY_pixelGetChannel(drawCol, 'a') == 0) { return FALSE; }
  if(x1 < 0 && x2 < 0) { return FALSE; }
  else if(x1 > canvWidth && x2 > canvWidth) { return FALSE; }
  if(y1 < 0 && y2 < 0) { return FALSE; }
  else if(y1 > canvHeight && y2 > canvHeight) { return FALSE; }
  dx = (x2 - x1);
  dy = (y2 - y1);
  dax = SOY_fabs(dx);
  day = SOY_fabs(dy);
  step = ((dax >= day) ? dax : day);
  dx /= step;
  dy /= step;
  x = x1;
  y = y1;
  i = 0;
  if(SOY_pixelGetChannel(drawCol, 'a') == 255) {
    while(i <= (int32)step) {
      t = (real32)i / (real32)step;
      SOY_drawSetColour(canvas, SOY_colourLerp(colA, colB, t));
      SOY_drawPixelClip(canvas, (int32)(x + 0.5f),(int32)(y + 0.5f),
          clip[0], clip[1], clip[2], clip[3]);
      x += dx;
      y += dy;
      i += 1;
    }
  } else {
    while(i <= (int32)step) {
      t = (real32)i / (real32)step;
      if(SOY_boundsCheck((int32)x, (int32)y,
            clip[0], clip[1], clip[2], clip[3])) {
        SOY_drawSetColour(canvas, SOY_colourLerp(colA, colB, t));
        SOY_drawPixelBlend(canvas, (int32)(x + 0.5f), (int32)(y + 0.5f));
      }
      x += dx;
      y += dy;
      i += 1;
    }
  }
  return TRUE;
}

int32 SOY_drawLineDotted(soyCanvas* canvas,
    real32 x1, real32 y1, real32 x2, real32 y2) {
  real32 dx, dy, dax, day, x, y, step;
  int32 i;
  soyPixel fg = SOY_drawGetColour(canvas);
  int32* clip = canvas->rgba.clipRect;
  soyPixel drawCol = SOY_drawGetColour(canvas);
  int32 canvWidth = canvas->rgba.width;
  int32 canvHeight = canvas->rgba.height;
  if(SOY_pixelGetChannel(drawCol, 'a') == 0) { return FALSE; }
  if(x1 < 0 && x2 < 0) { return FALSE; }
  else if(x1 > canvWidth && x2 > canvWidth) { return FALSE; }
  if(y1 < 0 && y2 < 0) { return FALSE; }
  else if(y1 > canvHeight && y2 > canvHeight) { return FALSE; }
  dx = (x2 - x1);
  dy = (y2 - y1);
  dax = SOY_fabs(dx);
  day = SOY_fabs(dy);
  step = ((dax >= day) ? dax : day);
  dx /= step;
  dy /= step;
  x = x1;
  y = y1;
  i = 0;
  if(SOY_pixelGetChannel(drawCol, 'a') == 255) {
    while(i <= (int32)step) {
      if(i % 2 == 0) {
        SOY_drawPixelClip(canvas, (int32)(x + 0.5f),(int32)(y + 0.5f),
            clip[0], clip[1], clip[2], clip[3]);
      }
      x += dx;
      y += dy;
      i += 1;
    }
  } else {
    fg = drawCol;
    while(i <= (int32)step) {
      if(i % 2 == 0) {
        if(SOY_boundsCheck((int32)x, (int32)y,
              clip[0], clip[1], clip[2], clip[3])) {
          SOY_drawSetColour(canvas, fg);
          SOY_drawPixelBlend(canvas, (int32)(x + 0.5f), (int32)(y + 0.5f));
        }
      }
      x += dx;
      y += dy;
      i += 1;
    }
  }
  return TRUE;
}

int32 SOY_drawEllipse(soyCanvas* canvas,
    int32 xm, int32 ym, int32 a, int32 b) {
  int32 x = -a;
  int32 y = 0;
  int64 e2 = (int64)b*b;
  int64 err = x*(2*e2+x)+e2;
  int32* clip = canvas->rgba.clipRect;
  soyPixel fg, bg;
  soyPixel drawCol = SOY_drawGetColour(canvas);
  fg = drawCol;
  if(SOY_pixelGetChannel(drawCol, 'a') == 0) { return FALSE; }
  if(SOY_pixelGetChannel(drawCol, 'a') == 255) {
    do {
      SOY_drawPixelClip(canvas,
          xm-x, ym+y, clip[0], clip[1], clip[2], clip[3]);
      SOY_drawPixelClip(canvas,
          xm+x, ym+y, clip[0], clip[1], clip[2], clip[3]);
      SOY_drawPixelClip(canvas,
          xm+x, ym-y, clip[0], clip[1], clip[2], clip[3]);
      SOY_drawPixelClip(canvas,
          xm-x, ym-y, clip[0], clip[1], clip[2], clip[3]);
      e2 = 2*err;
      if(e2 >= (x*2+1)*(int64)b*b) {
        err+= (++x*2+1)*(int64)b*b;
      }
      if(e2 <= (y*2+1)*(int64)a*a) {
        err += (++y*2+1)*(int64)a*a;
      }
    } while (x <= 0);
    while(y++ < b) {
      SOY_drawPixelClip(canvas,
          xm, ym+y, clip[0], clip[1], clip[2], clip[3]);
      SOY_drawPixelClip(canvas,
          xm, ym-y, clip[0], clip[1], clip[2], clip[3]);
    }
  } else {
    do {
      bg = SOY_drawSample(canvas, xm - x, ym + y);
      SOY_drawSetColour(canvas, SOY_alphaBlend(bg, fg));
      SOY_drawPixelClip(canvas,
          xm-x, ym+y, clip[0], clip[1], clip[2], clip[3]);
      bg = SOY_drawSample(canvas,
          xm + x, ym + y);
      SOY_drawSetColour(canvas,
          SOY_alphaBlend(bg, fg));
      SOY_drawPixelClip(canvas,
          xm+x, ym+y, clip[0], clip[1], clip[2], clip[3]);
      bg = SOY_drawSample(canvas,
          xm + x, ym - y);
      SOY_drawSetColour(canvas,
          SOY_alphaBlend(bg, fg));
      SOY_drawPixelClip(canvas,
          xm+x, ym-y, clip[0], clip[1], clip[2], clip[3]);
      bg = SOY_drawSample(canvas,
          xm - x, ym - y);
      SOY_drawSetColour(canvas,
          SOY_alphaBlend(bg, fg));
      SOY_drawPixelClip(canvas,
          xm-x, ym-y, clip[0], clip[1], clip[2], clip[3]);
      e2 = 2*err;
      if(e2 >= (x*2+1)*(int64)b*b) {
        err+= (++x*2+1)*(int64)b*b;
      }
      if(e2 <= (y*2+1)*(int64)a*a) {
        err += (++y*2+1)*(int64)a*a;
      }
    } while (x <= 0);
    while(y++ < b) {
      bg = SOY_drawSample(canvas, xm, ym + y);
      SOY_drawSetColour(canvas, SOY_alphaBlend(bg, fg));
      SOY_drawPixelClip(canvas,
          xm, ym+y, clip[0], clip[1], clip[2], clip[3]);
      bg = SOY_drawSample(canvas, xm, ym - y);
      SOY_drawSetColour(canvas, SOY_alphaBlend(bg, fg));
      SOY_drawPixelClip(canvas,
          xm, ym-y, clip[0], clip[1], clip[2], clip[3]);
    }
  }
  return TRUE;
}

int32 SOY_drawCircle(soyCanvas* canvas,
    int32 xm, int32 ym, int32 r) {
  return SOY_drawEllipse(canvas, xm, ym, r, r);
}

int32 SOY_drawCircleFill(soyCanvas* canvas,
    int32 xm, int32 ym, int32 r) {
  int32 x;
  int32 y;
  soyPixel fg, bg;
  soyPixel drawCol = SOY_drawGetColour(canvas);
  int32* clip = canvas->rgba.clipRect;
  fg = drawCol;
  if(SOY_pixelGetChannel(drawCol, 'a') == 0) { return FALSE; }
  if(SOY_pixelGetChannel(drawCol, 'a') == 255) {
    for(y = 0; y < r*2; y++) {
      for(x = 0; x < r*2; x++) {
        if(SOY_distance(
              (real32)xm,
              (real32)ym,
              (real32)xm+(x-r),
              (real32)ym+(y-r)) < (real32)r) {
          SOY_drawPixelClip(canvas, xm-r+x, ym-r+y,
              clip[0], clip[1], clip[2], clip[3]);
        }
      }
    }
  } else {
    for(y = 0; y < r*2; y++) {
      for(x = 0; x < r*2; x++) {
        if(SOY_distance(
              (real32)xm,
              (real32)ym,
              (real32)xm+(x-r),
              (real32)ym+(y-r)) < (real32)r) {
          bg = SOY_drawSample(canvas, xm - r + x, ym - r + y);
          SOY_drawSetColour(canvas, SOY_alphaBlend(bg, fg));
          SOY_drawPixelClip(canvas, xm-r+x, ym-r+y,
              clip[0], clip[1], clip[2], clip[3]);
        }
      }
    }
  }
  return TRUE;
}

int32 SOY_drawRect(soyCanvas* canvas,
    real32 x1, real32 y1, real32 x2, real32 y2, int32 thickness) {
  real32 temp;
  if(x1 > x2) { SOY_SWAP(x1, x2, temp); }
  if(y1 > y2) { SOY_SWAP(y1, y2, temp); }
  if(!thickness) { return TRUE; }
  SOY_drawLine(canvas, x1, y1, x2, y1);
  SOY_drawLine(canvas, x1, y2, x2, y2);
  SOY_drawLine(canvas, x1, y1, x1, y2 - 1);
  SOY_drawLine(canvas, x2, y1, x2, y2);
  x1++;
  y1++;
  x2--;
  y2--;
  SOY_drawRect(canvas, x1, y1, x2, y2, thickness-1);
  return TRUE;
}

int32 SOY_drawRectFill(soyCanvas* canvas,
    int32 x1, int32 y1, int32 x2, int32 y2) {
  int32 i, j, k, sx, sy;
  soyPixel fg, bg;
  soyPixel drawCol = SOY_drawGetColour(canvas);
  int32 canvWidth = canvas->rgba.width;
  int32 canvHeight = canvas->rgba.height;
  if(SOY_pixelGetChannel(drawCol, 'a') == 0) { return FALSE; }
  x2--; y2--;
  x1 = SOY_MIN(SOY_MAX(0, x1), canvWidth-1);
  x2 = SOY_MIN(SOY_MAX(0, x2), canvWidth-1);
  y1 = SOY_MIN(SOY_MAX(0, y1), canvHeight-1);
  y2 = SOY_MIN(SOY_MAX(0, y2), canvHeight-1);
  if(SOY_pixelGetChannel(drawCol, 'a') == 255) {
    for(j = x1; j <= x2; j++) {
      SOY_drawPixel(canvas, j, y1);
    }
    k = 0;
    for(i = y1 + 1; i <= y2; i++) {
      k++;
      SOY_memoryCopy(
          (uint8*)(canvas->rgba.data + x1 + (y1 + k) * canvWidth),
          (uint8*)(canvas->rgba.data + x1 + y1 * canvWidth),
          (x2 - x1 + 1) * sizeof(soyPixel)
          );
    }
  } else {
    fg = drawCol;
    for(sy = 0; sy <= y2 - y1; sy++) {
      for(sx = 0; sx <= x2 - x1; sx++) {
        bg = canvas->rgba.data[sx + x1 + (sy + y1) * canvWidth];
        canvas->rgba.data[sx + x1 + (sy + y1) * canvWidth] =
          SOY_alphaBlend(bg, fg);
      }
    }
  }
  return TRUE;
}

int32 SOY_drawCanvas(soyCanvas* dest, soyCanvas* src,
    int32 x, int32 y, int32 width, int32 height) {
  SOY_canvasStretch(dest, src, x, y, width, height);
  return TRUE;
}

int32 SOY_drawGradientH(soyCanvas* canvas,
    int32 x1, int32 y1, int32 x2, int32 y2, soyPixel colA, soyPixel colB) {
  int32 i, j;
  int32 temp;
  real32 t = 0;
  if(y1 > y2) {
    temp = y1;
    y1 = y2;
    y2 = temp;
  }
  for(i = y1; i <= y2; i++) {
    t = 0.0f;
    for(j = x1; j <= x2; j++) {
      SOY_drawSetColour(canvas, SOY_colourLerp(colA, colB, t));
      SOY_drawPixelClip(canvas, j, i, 0, 0,
          canvas->rgba.width, canvas->rgba.height);
      t = (real32)(j-x1)/(real32)(x2-x1);
    }
  }
  return TRUE;
}

int32 SOY_drawGradientV(soyCanvas* canvas,
    int32 x1, int32 y1, int32 x2, int32 y2, soyPixel colA, soyPixel colB) {
  int32 i, j;
  int32 temp;
  real32 t = 0;
  if(y1 > y2) {
    temp = y1;
    y1 = y2;
    y2 = temp;
  }
  for(i = y1; i < y2; i++) {
    SOY_drawSetColour(canvas, SOY_colourLerp(colA, colB, t));
    for(j = x1; j < x2; j++) {
      SOY_drawPixelClip(canvas, j, i, 0, 0,
          canvas->rgba.width, canvas->rgba.height);
    }
    t = (real32)(i-y1)/(real32)(y2-y1);
  }
  return TRUE;
}

#ifndef SOY_NO_MATH

int32 SOY_drawGradientC(soyCanvas* canvas,
    int32 x1, int32 y1, int32 x2, int32 y2, soyPixel colA, soyPixel colB) {
  int32 i, j;
  int32 temp;
  real32 t = 0;
  if(y1 > y2) {
    temp = y1;
    y1 = y2;
    y2 = temp;
  }
  for(i = y1; i < y2; i++) {
    for(j = x1; j < x2; j++) {
      SOY_drawSetColour(canvas, SOY_colourLerp(colA, colB, t));
      SOY_drawPixelClip(canvas, j, i, 0, 0,
          canvas->rgba.width, canvas->rgba.height);
      t = (SOY_vec4fLength(SOY_vec4f(
              (real32)(i-y1)/(y2-y1)-0.5f,
              (real32)(j-x1)/(x2-x1)-0.5f, 0, 0)));
    }
  }
  return TRUE;
}

int32 SOY_drawGradient(soyCanvas* canvas,
    int32 x1, int32 y1, int32 x2, int32 y2,
    soyPixel colA, soyPixel colB, int8 type) {
  switch(type) {
    case('v'): {
      SOY_drawGradientV(canvas, x1, y1, x2, y2, colA, colB); break; }
    case('h'): {
      SOY_drawGradientH(canvas, x1, y1, x2, y2, colA, colB); break; }
    case('c'): {
      SOY_drawGradientC(canvas, x1, y1, x2, y2, colA, colB); break; }
    default: { break; }
  }
  return TRUE;
}

#endif /* SOY_NO_MATH */

int32 SOY_drawSprite(soyCanvas* dest, soyCanvas* src,
    int32 xPos, int32 yPos, int32 width, int32 height) {
  int32 x, y;
  int32 nx, ny;
  soyPixel sample;
  soyPixel back;
  soyPixel blend;
  soyPixel drawCol = SOY_drawGetColour(dest);
  int32 srcWidth = src->rgba.width;
  int32 srcHeight = src->rgba.height;
  int32 destWidth = dest->rgba.width;
  int32 destHeight = dest->rgba.height;
  int32 clipX = (xPos >= 0) ? 0 : SOY_MIN(SOY_abs(xPos), srcWidth);
  int32 clipY = (yPos >= 0) ? 0 : SOY_MIN(SOY_abs(yPos), srcHeight);
  if(xPos + width < 0 || xPos >= destWidth) { return FALSE; }
  if(yPos + height < 0 || yPos >= destHeight) { return FALSE; }
  for(y = clipY; y < height; y++) {
    ny = (int32)(((real32)(y) / (real32)height)*(real32)srcHeight);
    for(x = clipX; x < width; x++) {
      nx = (int32)(((real32)(x) / (real32)width)*(real32)srcWidth);
      back = dest->rgba.data[x + xPos + (y + yPos)*destWidth];
      sample = src->rgba.data[nx + ny*srcWidth];
      SOY_pixelSetChannel(&sample, SOY_pixelGetChannel(drawCol, 'a'), 'a');
      blend = SOY_alphaBlend(back, sample);
      dest->rgba.data[x + xPos + (y + yPos)*destWidth] = blend;
    }
  }
  return TRUE;
}

int32 SOY_drawTriangle(soyCanvas* canvas,
    real32 x1, real32 y1, real32 x2, real32 y2, real32 x3, real32 y3) {
  SOY_drawLine(canvas, x1, y1, x2, y2);
  SOY_drawLine(canvas, x2, y2, x3, y3);
  SOY_drawLine(canvas, x3, y3, x1, y1);
  return TRUE;
}

int32 SOY_drawTriangleFill(soyCanvas* canvas,
    real32 x1, real32 y1, real32 x2, real32 y2, real32 x3, real32 y3) {
  real32 px1, px2;
  real32 stepX1, stepX2, stepX3, stepX4, stepX5;
  real32 dx1, dy1, dx2, dy2, dx3, dy3;
  real32 midX;
  real32 swapTemp;
  int32 midY, botY, topY;
  int32 i;
  int32* clip = canvas->rgba.clipRect;
  int32 spanX1, spanX2;
  int32 leftBend = FALSE;
  soyPixel fg, bg;
  soyPixel drawCol = SOY_drawGetColour(canvas);
  if(SOY_pixelGetChannel(drawCol, 'a') == 0) { return FALSE; }
  fg = drawCol;
  /* order verts by y coord first */
  if(y1 > y2)
  { SOY_SWAP(y1, y2, swapTemp); SOY_SWAP(x1, x2, swapTemp); }
  if(y1 > y3)
  { SOY_SWAP(y1, y3, swapTemp); SOY_SWAP(x1, x3, swapTemp); }
  if(y2 > y3)
  { SOY_SWAP(y2, y3, swapTemp); SOY_SWAP(x2, x3, swapTemp); }
  topY = (int32)y1;
  midY = (int32)y2;
  botY = (int32)y3;
  midX = (x1 + ((real32)(y2 - y1) / (real32)(y3 - y1)) * (x3 - x1));
  if(x2 > midX) { leftBend = TRUE; }
  /* order verts by x coord second */
  if(leftBend) { SOY_SWAP(x2, x3, swapTemp); SOY_SWAP(y2, y3, swapTemp); }
  /* calculate slopes */
  dx1 = (x2 - x1); dy1 = (y2 - y1);
  dx2 = (x3 - x1); dy2 = (y3 - y1);
  dx3 = (x3 - x2); dy3 = (y3 - y2);
  stepX1 = dx1/dy1;
  stepX2 = dx2/dy2;
  stepX3 = dx3/dy3;
  /* draw top part */
  if(y2 >= y3) { stepX4 = stepX1; stepX5 = stepX3;
  } else { stepX4 = stepX3; stepX5 = stepX2; }
  px1 = x1;
  px2 = x1;
  i = topY;
  if(SOY_pixelGetChannel(drawCol, 'a') == 255) {
    while(i < midY) {
      spanX1 = (int32)px1;
      spanX2 = (int32)px2;
      while(spanX1 < spanX2) {
        SOY_drawPixelClip(
            canvas, spanX1, i, clip[0], clip[1], clip[2], clip[3]);
        spanX1++;
      }
      px1 += stepX1;
      px2 += stepX2;
      i++;
    }
  } else {
    while(i < midY) {
      spanX1 = (int32)px1;
      spanX2 = (int32)px2;
      while(spanX1 < spanX2) {
        bg = SOY_drawSample(canvas, spanX1, i);
        SOY_drawSetColour(canvas, SOY_alphaBlend(bg, fg));
        SOY_drawPixelClip(
            canvas, spanX1, i, clip[0], clip[1], clip[2], clip[3]);
        spanX1++;
      }
      px1 += stepX1;
      px2 += stepX2;
      i++;
    }
  }
  /* draw bottom part */
  if(y2 >= y3) {
    px2 = x3;
  }  else {
    px1 = x2;
  }
  i = midY;
  if(SOY_pixelGetChannel(drawCol, 'a') == 255) {
    while(i < botY) {
      spanX1 = (int32)px1;
      spanX2 = (int32)px2;
      while(spanX1 < spanX2) {
        SOY_drawPixelClip(
            canvas, spanX1, i, clip[0], clip[1], clip[2], clip[3]);
        spanX1++;
      }
      px1 += stepX4;
      px2 += stepX5;
      i++;
    }
  } else {
    while(i < botY) {
      spanX1 = (int32)px1;
      spanX2 = (int32)px2;
      while(spanX1 < spanX2) {
        bg = SOY_drawSample(canvas, spanX1, i);
        SOY_drawSetColour(canvas, SOY_alphaBlend(bg, fg));
        SOY_drawPixelClip(
            canvas, spanX1, i, clip[0], clip[1], clip[2], clip[3]);
        spanX1++;
      }
      px1 += stepX4;
      px2 += stepX5;
      i++;
    }
  }
  return TRUE;
}

/*
* o-------------------------------------------o
* | @draw:world space                         |
* o-------------------------------------------o
*/

#ifndef SOY_NO_MATH

typedef struct tag_soyWorldSpace {
  vec2f origin;
  vec2f scale;
  vec2f axisX;
  vec2f axisY;
} soyWorldSpace;

soyWorldSpace SOY_worldSpace(
    real32 oX, real32 oY, real32 sX, real32 sY, real32 rXY) {
  soyWorldSpace ret;
  ret.origin = SOY_vec2f(oX, oY);
  ret.scale = SOY_vec2f(sX, sY);
  ret.axisX = SOY_vec2f(
      ret.scale.x*(real32)cos(rXY),
      ret.scale.x*(real32)sin(rXY));
  ret.axisY = SOY_vec2f(
      -ret.scale.y*(real32)sin(rXY),
      ret.scale.y*(real32)cos(rXY));
  return ret;
}

int32 SOY_drawWorldSpace(soyCanvas* canvas, soyWorldSpace wS) {
  int32 x, y;
  vec2f pA, pB, pC;
  vec2f pAX, pAY;
  for(y = -10; y <= 10; y++) {
    for(x = -10; x <= 10; x++) {
      pAX = SOY_vec2f(0.1f*x, 0.1f*y);
      pA = v2Add(wS.origin,
            v2Add(v2MulS(wS.axisX, pAX.x),
                  v2MulS(wS.axisY, pAX.y)));
      SOY_drawCircleFill(canvas, (int32)pA.x, (int32)pA.y, 2);
    }
  }
  pAX = SOY_vec2f(1.0f, 1.0f);
  pAY = SOY_vec2f(1.0f, 1.0f);
  pA = v2Add(wS.origin,v2Mul(pAX, wS.axisX));
  pB = v2Add(wS.origin,v2Mul(pAY, wS.axisY));
  pC = wS.origin;
  SOY_drawLine(canvas, pC.x, pC.y, pA.x, pA.y);
  SOY_drawLine(canvas, pC.x, pC.y, pB.x, pB.y);

  return TRUE;
}

vec2f SOY_worldPoint(soyWorldSpace* wS, real32 pX, real32 pY) {
  return
    v2Add(wS->origin, v2Add(v2MulS(wS->axisX, pX), v2MulS(wS->axisY, pY)));
}

int32 SOY_drawWorldRect(soyCanvas* canvas, soyWorldSpace wS,
    real32 pX, real32 pY, real32 sX, real32 sY) {
  vec2f pA = SOY_worldPoint(&wS, pX, pY);
  vec2f pB = SOY_worldPoint(&wS, pX+sX, pY);
  vec2f pC = SOY_worldPoint(&wS, pX, pY+sY);
  vec2f pD = SOY_worldPoint(&wS, pX+sX, pY+sY);
  SOY_drawLine(canvas, pA.x, pA.y, pB.x, pB.y);
  SOY_drawLine(canvas, pA.x, pA.y, pC.x, pC.y);
  SOY_drawLine(canvas, pC.x, pC.y, pD.x, pD.y);
  SOY_drawLine(canvas, pD.x, pD.y, pB.x, pB.y);
  return TRUE;
}

vec4i SOY_boundingBox(vec2f pA, vec2f pB, vec2f pC, vec2f pD) {
  vec4i ret;
  ret.x = (int32)SOY_MIN(SOY_MIN(SOY_MIN(pA.x, pB.x), pC.x), pD.x);
  ret.y = (int32)SOY_MIN(SOY_MIN(SOY_MIN(pA.y, pB.y), pC.y), pD.y);
  ret.z = (int32)SOY_MAX(SOY_MAX(SOY_MAX(pA.x, pB.x), pC.x), pD.x);
  ret.w = (int32)SOY_MAX(SOY_MAX(SOY_MAX(pA.y, pB.y), pC.y), pD.y);
  return ret;
}

real32 SOY_halfSpace(vec2f p, vec2f pA, vec2f axis) {
  return v2Inner(v2Sub(p, pA), v2Perp(axis));
}

int32 SOY_pointInRectangle(soyWorldSpace* wS,
    vec2f p, vec2f pA, vec2f pB, vec2f pC, vec2f pD) {
  real32 a = SOY_halfSpace(p, pA, wS->axisX);
  real32 b = SOY_halfSpace(p, pB, wS->axisY);
  real32 c = SOY_halfSpace(p, pC, v2MulS(wS->axisY, -1.0f));
  real32 d = SOY_halfSpace(p, pD, v2MulS(wS->axisX, -1.0f));
  return (a < 0.0f) && (b < 0.0f) && (c < 0.0f) && (d < 0.0f);
  return FALSE;
}

int32 SOY_drawWorldRectFill(soyCanvas* canvas, soyWorldSpace wS,
    real32 pX, real32 pY, real32 sX, real32 sY) {
  int32 x, y;
  vec2f p;
  real32 eA, eB, eC, eD;
  int32* clip = canvas->rgba.clipRect;
  soyPixel col = SOY_drawGetColour(canvas);
  real32 flip = ((wS.scale.y > 0.0f) ^ (wS.scale.x > 0.0f)) ? -1.0f : 1.0f;
  vec2f pA = SOY_worldPoint(&wS, pX, pY);
  vec2f pB = SOY_worldPoint(&wS, pX+sX, pY);
  vec2f pC = SOY_worldPoint(&wS, pX, pY+sY);
  vec2f pD = SOY_worldPoint(&wS, pX+sX, pY+sY);
  vec4i bound = SOY_boundingBox(pA, pB, pC, pD);
  for(y = bound.y; y < bound.w; y++) {
    for(x = bound.x; x < bound.z; x++) {
      p = SOY_vec2f((real32)x - pA.x, (real32)y - pA.y);
      eA =
        flip*v2Inner(p, v2MulS(v2Perp(wS.axisX), -1.0f));
      eB =
        flip*v2Inner(v2Sub(p, wS.axisX), v2MulS(v2Perp(wS.axisY), -1.0f));
      eC =
        flip*v2Inner(v2Sub(v2Sub(p, wS.axisX), wS.axisY), v2Perp(wS.axisX));
      eD =
        flip*v2Inner(v2Sub(p, wS.axisY), v2Perp(wS.axisY));
      if((eA < 0.0f) && (eB < 0.0f) && (eC < 0.0f) && (eD < 0.0f)) {
        if(SOY_boundsCheck(x, y, clip[0], clip[1], clip[2], clip[3])) {
          if(SOY_pixelGetChannel(col, 'a') == 255) {
            SOY_drawPixel(canvas, x, y);
          } else {
            SOY_drawPixelBlend(canvas, x, y);
          }
        }
      }
    }
  }
  return TRUE;
}

int32 SOY_drawWorldPoint(soyCanvas* canvas, soyWorldSpace wS,
    real32 pX, real32 pY, real32 sXY) {
  vec2f pA = SOY_worldPoint(&wS, pX, pY);
  SOY_drawCircleFill(canvas, pA.x, pA.y, sXY);
  return TRUE;
}

int32 SOY_drawWorldSprite(soyCanvas* canvas,
    soyWorldSpace wS, soyCanvas* texture,
    real32 pX, real32 pY, real32 sX, real32 sY) {
  int32 x, y;
  soyPixel col;
  vec2f p;
  real32 eA, eB, eC, eD;
  int32* clip = canvas->rgba.clipRect;
  real32 axisDX = 1.0f / v2Inner(wS.axisX, wS.axisX);
  real32 axisDY = 1.0f / v2Inner(wS.axisY, wS.axisY);
  real32 u = 0.0f;
  real32 v = 0.0f;
  int32 tU = 0;
  int32 tV = 0;
  real32 flip = ((wS.scale.y > 0.0f) ^ (wS.scale.x > 0.0f)) ? -1.0f : 1.0f;
  vec2f pA = SOY_worldPoint(&wS, pX, pY);
  vec2f pB = SOY_worldPoint(&wS, pX+sX, pY);
  vec2f pC = SOY_worldPoint(&wS, pX, pY+sY);
  vec2f pD = SOY_worldPoint(&wS, pX+sX, pY+sY);
  vec4i bound = SOY_boundingBox(pA, pB, pC, pD);
  for(y = bound.y; y < bound.w; y++) {
    for(x = bound.x; x < bound.z; x++) {
      p = SOY_vec2f((real32)x - pA.x, (real32)y - pA.y);
      eA =
        flip*v2Inner(p, v2MulS(v2Perp(wS.axisX), -1.0f));
      eB =
        flip*v2Inner(v2Sub(p, wS.axisX), v2MulS(v2Perp(wS.axisY), -1.0f));
      eC =
        flip*v2Inner(v2Sub(v2Sub(p, wS.axisX), wS.axisY), v2Perp(wS.axisX));
      eD =
        flip*v2Inner(v2Sub(p, wS.axisY), v2Perp(wS.axisY));
      if((eA < 0.0f) && (eB < 0.0f) && (eC < 0.0f) && (eD < 0.0f)) {
        if(SOY_boundsCheck(x, y, clip[0], clip[1], clip[2], clip[3])) {
          u = axisDX*v2Inner(p, wS.axisX);
          v = 1.0f - axisDY*v2Inner(p, wS.axisY);
          tU = (int32)(u*((real32)texture->rgba.width - 1.0f) + 0.5f);
          tV = (int32)(v*((real32)texture->rgba.height - 1.0f) + 0.5f);
#if 1
          SOY_ASSERT(tU >= 0 && tU <= texture->rgba.width);
          SOY_ASSERT(tV >= 0 && tV <= texture->rgba.height);
#endif
#if 1
          col = texture->rgba.data[tU + tV*texture->rgba.width];
          SOY_drawSetColour(canvas, col);
          if(SOY_pixelGetChannel(col, 'a') == 255) {
            SOY_drawPixel(canvas, x, y);
          } else {
            SOY_drawPixelBlend(canvas, x, y);
          }
#endif
        }
      }
    }
  }
  return TRUE;
}

/*
* o-------------------------------------------o
* | @draw:filters                             |
* o-------------------------------------------o
*/

int32 SOY_drawFilterBlur(soyCanvas* canvas,
    int32 minX, int32 minY, int32 maxX, int32 maxY, int32 iterations) {
  int32 x, y;
  int32 i;
  int32 iter = iterations;
  real32 rx, ry;
  soyPixel col = SOY_drawGetColour(canvas);
  vec4f frg;
  vec4f sum;
  real32 o = 1.0f;
  for(i = 0; i < iter; i++) {
    for(y= minY; y < maxY; y++) {
      for(x = minX; x < maxX; x++) {
        rx = (real32)(x);
        ry = (real32)(y);
        sum = SOY_drawSampleVec4(canvas, rx, ry);
        sum = v4Add(sum, SOY_drawSampleVec4(canvas, rx - o, ry));
        sum = v4Add(sum, SOY_drawSampleVec4(canvas, rx + o, ry));
        frg = v4DivS(sum, 3.0f);
        SOY_drawPixelColour(canvas, x, y, V4RGBA(frg));
      }
    }
    for(y= minY; y < maxY; y++) {
      for(x = minX; x < maxX; x++) {
        rx = (real32)(x);
        ry = (real32)(y);
        sum = SOY_drawSampleVec4(canvas, rx, ry);
        sum = v4Add(sum, SOY_drawSampleVec4(canvas, rx, ry - o));
        sum = v4Add(sum, SOY_drawSampleVec4(canvas, rx, ry + o));
        frg = v4DivS(sum, 3.0f);
        SOY_drawPixelColour(canvas, x, y, V4RGBA(frg));
      }
    }
    o += 0.5f;
  }
  SOY_drawSetColour(canvas, col);
  return TRUE;
}

#endif /* SOY_NO_MATH */

#define DRAW_SLEEP(canvas, window, t) \
      SOY_pollEvents(window); \
      SOY_canvasBlit(window, canvas); \
      Sleep(t)

/*
* o-------------------------------------------o
* | @draw:3d                                  |
* o-------------------------------------------o
*/

#ifndef SOY_NO_3D

#define DRAW_PAUSE \
      SOY_pollEvents(g_soyActiveWindowHandle); \
      SOY_canvasBlit(g_soyActiveWindowHandle, hCanvas)

int32 SOY_draw3DTriangleSpanSolid(soyCanvas* canvas, soyCanvas* depthbuffer,
    int32 row, real32 sx, real32 ex,
    real32 texSW, real32 texEW, soyPixel col) {
  int32 i;
  int32 indexStart = (int32)(sx) + 1;
  int32 indexEnd = (int32)(ex) + 1;
  real32 delta = (ex - sx);
  real32 preStep =  (real32)((real32)indexStart - sx);
  real32 texStepW = (texEW - texSW) / (delta);
  real32 texW = texSW + preStep * texStepW;
  soyPixel* pixel = canvas->rgba.data + indexStart +
    row*canvas->rgba.width;
  real32* depth = depthbuffer->depth.data + indexStart +
    row*depthbuffer->depth.width;
  for(i = indexStart; i < indexEnd; i++) {
    if(texW > *depth) {
      *pixel = col;
      *depth = texW;
    }
    depth++;
    pixel++;
    texW += texStepW;
  }
  return TRUE;
}

int32 SOY_draw3DTriangleSpanTextureAffine(
    soyCanvas* canvas, soyCanvas* depthbuffer,
    int32 row, real32 sx, real32 ex,
    real32 texSU, real32 texSV, real32 texSW,
    real32 texEU, real32 texEV, real32 texEW,
    real32 lightValue, soyCanvas* texture) {
  int32 i;
  int32 tx, ty;
  int32 indexStart = (int32)(sx) + 1;
  int32 indexEnd = (int32)(ex) + 1;
  real32 delta = (ex - sx);
  real32 preStep =  (real32)((real32)indexStart - sx);
  real32 texStepW = (texEW - texSW) / (delta);
  real32 texStepX = (texEU - texSU) / (delta);
  real32 texStepY = (texEV - texSV) / (delta);
  real32 texU = texSU + preStep * texStepX;
  real32 texV = texSV + preStep * texStepY;
  real32 texW = texSW + preStep * texStepW;
  real32 texWidth = (real32)(texture->rgba.width - 1);
  real32 texHeight = (real32)(texture->rgba.height - 1);
  uint8* texBytes;
  uint8* pixelBytes;
  soyPixel* pixel = canvas->rgba.data + indexStart +
    row*canvas->rgba.width;
  real32* depth = depthbuffer->depth.data + indexStart +
    row*depthbuffer->depth.width;
  for(i = indexStart; i < indexEnd; i++) {
    if(texW > *depth) {
      tx = (int32)(texU * texWidth + 0.5f);
      ty = (int32)(texV * texHeight + 0.5f);
      texBytes = (uint8*)&texture->rgba.data[tx + ty*texture->rgba.width];
      pixelBytes = (uint8*)pixel;
      *(pixelBytes++) = (uint8)(((real32)*(texBytes+0))*lightValue);
      *(pixelBytes++) = (uint8)(((real32)*(texBytes+1))*lightValue);
      *(pixelBytes++) = (uint8)(((real32)*(texBytes+2))*lightValue);
      *depth = texW;
    }
    depth++;
    pixel++;
    texU += texStepX;
    texV += texStepY;
    texW += texStepW;
  }
  return TRUE;
}

int32 SOY_draw3DTriangleSpanTexture(
    soyCanvas* canvas, soyCanvas* depthbuffer,
    int32 row, real32 sx, real32 ex,
    real32 texSU, real32 texSV, real32 texSW,
    real32 texEU, real32 texEV, real32 texEW,
    real32 lightValue, soyCanvas* texture
    ) {
#if 0
  SOY_TIMING_BEGIN("triangle span", 2);
#endif
  int32 i;
  int32 tx, ty;
  int32 indexStart = (int32)(sx) + 1;
  int32 indexEnd = (int32)(ex) + 1;
  real32 delta = 1.0f / (ex - sx);
  real32 preStep =  (real32)((real32)indexStart - sx);
  real32 texStepW = (texEW - texSW) * (delta);
  real32 texStepX = (texEU - texSU) * (delta);
  real32 texStepY = (texEV - texSV) * (delta);
  real32 texU = texSU + preStep * texStepX;
  real32 texV = texSV + preStep * texStepY;
  real32 texW = texSW + preStep * texStepW;
  real32 invW = 0.0f;
  real32 texWidth = (real32)(texture->rgba.width - 1);
  real32 texHeight = (real32)(texture->rgba.height - 1);
  uint8* texBytes;
  uint8* pixelBytes;
  soyPixel* pixel = canvas->rgba.data + indexStart +
    row*canvas->rgba.width;
  real32* depth = depthbuffer->depth.data + indexStart +
    row*depthbuffer->depth.width;
  for(i = indexStart; i < indexEnd; i++) {
    if(texW > *depth) {
      invW = 1.0 / texW;
      tx = (int32)(texU * invW * texWidth + 0.5f);
      ty = (int32)(texV * invW * texHeight + 0.5f);
      texBytes = (uint8*)&texture->rgba.data[tx + ty*texture->rgba.width];
      pixelBytes = (uint8*)pixel;
      *(pixelBytes++) = (uint8)(((real32)*(texBytes+0))*lightValue);
      *(pixelBytes++) = (uint8)(((real32)*(texBytes+1))*lightValue);
      *(pixelBytes++) = (uint8)(((real32)*(texBytes+2))*lightValue);
      *depth = texW;
    }
    depth++;
    pixel++;
    texU += texStepX;
    texV += texStepY;
    texW += texStepW;
  }
#if 0
  SOY_TIMING_END(2);
#endif
  return TRUE;
}

int32 SOY_draw3DTriangleSolid(
    soyCanvas* canvas, soyCanvas* depthbuffer,
    soyPixel col,
    real32 x1, real32 y1,
    real32 x2, real32 y2,
    real32 x3, real32 y3,
    real32 w1, real32 w2, real32 w3) {
  real32 absDy1, absDy2;
  real32 dx1, dy1, dw1;
  real32 dx2, dy2, dw2;
  real32 swapTemp;
  real32 sx, ex;
  int32 i;
  real32 imy1;
  real32 imy2;
  int32 iy1, iy2, iy3;
  real32 texSW = 0.0f;
  real32 texEW = 0.0f;
  real32 stepDAX = 0, stepDBX = 0;
  real32 stepDW1 = 0, stepDW2 = 0;
  x1 += 0.5f; x2 += 0.5f; x3 += 0.5f;
  y1 += 0.5f; y2 += 0.5f; y3 += 0.5f;
  if(y2 < y1) {
    SOY_SWAP(x1, x2, swapTemp); SOY_SWAP(y1, y2, swapTemp);
    SOY_SWAP(w1, w2, swapTemp);
  }
  if(y3 < y1) {
    SOY_SWAP(x1, x3, swapTemp); SOY_SWAP(y1, y3, swapTemp);
    SOY_SWAP(w1, w3, swapTemp);
  }
  if(y3 < y2) {
    SOY_SWAP(x2, x3, swapTemp); SOY_SWAP(y2, y3, swapTemp);
    SOY_SWAP(w2, w3, swapTemp);
  }
  iy1 = (int32)(y1);
  iy2 = (int32)(y2);
  iy3 = (int32)(y3);
  dx1 = x2 - x1; dy1 = y2 - y1; dw1 = w2 - w1;
  dx2 = x3 - x1; dy2 = y3 - y1; dw2 = w3 - w1;
  absDy1 = 1.0f / SOY_fabs(dy1);
  absDy2 = 1.0f / SOY_fabs(dy2);
  if(dy1) {
    stepDAX = dx1 * absDy1;
    stepDW1 = dw1 * absDy1;
  }
  if(dy2) {
    stepDBX = dx2 * absDy2; stepDW2 = dw2 * absDy2;
  }
  if(dy1) {
    for(i = iy1 + 1; i <= y2; i++) {
      imy1 = (real32)(i) - y1;
      sx = (x1 + imy1 * stepDAX);
      ex = (x1 + imy1 * stepDBX);
      texSW = w1 + imy1 * stepDW1;
      texEW = w1 + imy1 * stepDW2;
      if(sx > ex) {
        SOY_SWAP(sx, ex, swapTemp);
        SOY_SWAP(texSW, texEW, swapTemp);
      }
      SOY_draw3DTriangleSpanSolid(
          canvas, depthbuffer, i - 1, sx, ex, texSW, texEW, col);
#if 0
      DRAW_PAUSE;
#endif
    }
  }
  dx1 = x3 - x2; dy1 = y3 - y2; dw1 = w3 - w2;
  absDy1 = 1.0f / SOY_fabs(dy1);
  absDy2 = 1.0f / SOY_fabs(dy2);
  if(dy1) {
    stepDAX = dx1 * absDy1; stepDW1 = dw1 * absDy1;
  }
  if(dy2) {
    stepDBX = dx2 * absDy2;
  }
  if(dy1) {
    for(i = iy2 + 1; i <= iy3; i++) {
      imy1 = (real32)(i) - y1;
      imy2 = (real32)(i) - y2;
      sx = (x2 + imy2 * stepDAX);
      ex = (x1 + imy1 * stepDBX);
      texSW = w2 + imy2 * stepDW1;
      texEW = w1 + imy1 * stepDW2;
      if(sx > ex) {
        SOY_SWAP(sx, ex, swapTemp);
        SOY_SWAP(texSW, texEW, swapTemp);
      }
      SOY_draw3DTriangleSpanSolid(
          canvas, depthbuffer, i - 1, sx, ex, texSW, texEW, col);
#if 0
      DRAW_PAUSE;
#endif
    }
  }
  return TRUE;
}

int32 SOY_draw3DTriangleTextured(
    soyCanvas* canvas, soyCanvas* depthbuffer,
    soyCanvas* texture, int32 perspectiveCorrect, real32 lightness,
    real32 x1, real32 y1, real32 x2, real32 y2, real32 x3, real32 y3,
    real32 u1, real32 v1, real32 w1,
    real32 u2, real32 v2, real32 w2,
    real32 u3, real32 v3, real32 w3) {
  real32 absDy1, absDy2;
  real32 dx1, dy1, du1, dv1, dw1;
  real32 dx2, dy2, du2, dv2, dw2;
  real32 swapTemp;
  real32 sx, ex;
  int32 i;
  real32 imy1;
  real32 imy2;
  int32 iy1, iy2, iy3;
  real32 texSU = 0.0f, texSV = 0.0f, texSW = 0.0f;
  real32 texEU = 0.0f, texEV = 0.0f, texEW = 0.0f;
  real32 stepDAX = 0, stepDBX = 0, stepDU1 = 0;
  real32 stepDV1 = 0, stepDW1 = 0, stepDU2 = 0, stepDV2 = 0, stepDW2 = 0;
  x1 += 0.5f; x2 += 0.5f; x3 += 0.5f;
  y1 += 0.5f; y2 += 0.5f; y3 += 0.5f;
  if(y2 < y1) {
    SOY_SWAP(x1, x2, swapTemp); SOY_SWAP(y1, y2, swapTemp);
    SOY_SWAP(u1, u2, swapTemp); SOY_SWAP(v1, v2, swapTemp);
    SOY_SWAP(w1, w2, swapTemp);
  }
  if(y3 < y1) {
    SOY_SWAP(x1, x3, swapTemp); SOY_SWAP(y1, y3, swapTemp);
    SOY_SWAP(u1, u3, swapTemp); SOY_SWAP(v1, v3, swapTemp);
    SOY_SWAP(w1, w3, swapTemp);
  }
  if(y3 < y2) {
    SOY_SWAP(x2, x3, swapTemp); SOY_SWAP(y2, y3, swapTemp);
    SOY_SWAP(u2, u3, swapTemp); SOY_SWAP(v2, v3, swapTemp);
    SOY_SWAP(w2, w3, swapTemp);
  }
  iy1 = (int32)(y1);
  iy2 = (int32)(y2);
  iy3 = (int32)(y3);
  dx1 = x2 - x1; dy1 = y2 - y1; dv1 = v2 - v1;
  du1 = u2 - u1; dw1 = w2 - w1;
  dx2 = x3 - x1; dy2 = y3 - y1; dv2 = v3 - v1;
  du2 = u3 - u1; dw2 = w3 - w1;
  absDy1 = 1.0f / SOY_fabs(dy1);
  absDy2 = 1.0f / SOY_fabs(dy2);
  if(dy1) {
    stepDAX = dx1 * absDy1; stepDU1 = du1 * absDy1;
    stepDV1 = dv1 * absDy1; stepDW1 = dw1 * absDy1;
  }
  if(dy2) {
    stepDBX = dx2 * absDy2; stepDU2 = du2 * absDy2;
    stepDV2 = dv2 * absDy2; stepDW2 = dw2 * absDy2;
  }
  if(dy1) {
    for(i = iy1 + 1; i <= y2; i++) {
      imy1 = (real32)(i) - y1;
      sx = (x1 + imy1 * stepDAX);
      ex = (x1 + imy1 * stepDBX);
      if(texture) {
        texSU = u1 + imy1 * stepDU1;
        texSV = v1 + imy1 * stepDV1;
        texEU = u1 + imy1 * stepDU2;
        texEV = v1 + imy1 * stepDV2;
      }
      texSW = w1 + imy1 * stepDW1;
      texEW = w1 + imy1 * stepDW2;

      if(sx > ex) {
        SOY_SWAP(sx, ex, swapTemp);
        SOY_SWAP(texSU, texEU, swapTemp);
        SOY_SWAP(texSV, texEV, swapTemp);
        SOY_SWAP(texSW, texEW, swapTemp);
      }
      if(perspectiveCorrect) {
        SOY_draw3DTriangleSpanTexture(
          canvas, depthbuffer, i - 1, sx, ex,
          texSU, texSV, texSW,
          texEU, texEV, texEW, lightness, texture);
      } else {
        SOY_draw3DTriangleSpanTextureAffine(
          canvas, depthbuffer, i - 1, sx, ex,
          texSU, texSV, texSW,
          texEU, texEV, texEW, lightness, texture);
      }
#if 0
      DRAW_PAUSE;
#endif
    }
  }
  stepDU1 = 0; stepDV1 = 0;
  dx1 = x3 - x2; dy1 = y3 - y2; dv1 = v3 - v2;
  du1 = u3 - u2; dw1 = w3 - w2;
  absDy1 = 1.0f / SOY_fabs(dy1);
  absDy2 = 1.0f / SOY_fabs(dy2);
  if(dy1) {
    stepDAX = dx1 * absDy1; stepDU1 = du1 * absDy1;
    stepDV1 = dv1 * absDy1; stepDW1 = dw1 * absDy1;
  }
  if(dy2) {
    stepDBX = dx2 * absDy2;
  }
  if(dy1) {
    for(i = iy2 + 1; i <= iy3; i++) {
      imy1 = (real32)(i) - y1;
      imy2 = (real32)(i) - y2;
      sx = (x2 + imy2 * stepDAX);
      ex = (x1 + imy1 * stepDBX);
      if(texture) {
        texSU = u2 + imy2 * stepDU1;
        texSV = v2 + imy2 * stepDV1;
        texEU = u1 + imy1 * stepDU2;
        texEV = v1 + imy1 * stepDV2;
      }
      texSW = w2 + imy2 * stepDW1;
      texEW = w1 + imy1 * stepDW2;
      if(sx > ex) {
        SOY_SWAP(sx, ex, swapTemp);
        SOY_SWAP(texSU, texEU, swapTemp);
        SOY_SWAP(texSV, texEV, swapTemp);
        SOY_SWAP(texSW, texEW, swapTemp);
      }
      if(perspectiveCorrect) {
        SOY_draw3DTriangleSpanTexture(
            canvas, depthbuffer, i - 1, sx, ex,
            texSU, texSV, texSW,
            texEU, texEV, texEW, lightness, texture);
      } else {
        SOY_draw3DTriangleSpanTextureAffine(
            canvas, depthbuffer, i - 1, sx, ex,
            texSU, texSV, texSW,
            texEU, texEV, texEW, lightness, texture);
      }
#if 0
      DRAW_PAUSE;
#endif
    }
  }
  return TRUE;
}

int32 SOY_draw3DTriangle(
    soyCanvas* canvas, soyCanvas* depthbuffer,
    soyCanvas* texture,
    soyTriangle tri,
    soyRenderMode renderMode) {
  soyPixel col;
  vec4f ambient = SOY_vec4f(0.2f, 0.1f, 0.3f, 0.0f);
  vec4f lightCol = SOY_vec4f(1.0f, 0.5f, 0.2f, 1.0f);
  vec4f diff = SOY_vec4f(tri.colour.w, tri.colour.w, tri.colour.w, 1.0f);
  vec4f diffuse = v4Mul(diff, lightCol);
  vec4f result = v4Mul(v4Add(ambient, diffuse), tri.colour);
  result.x = SOY_MIN(result.x, 1.0f);
  result.y = SOY_MIN(result.y, 1.0f);
  result.z = SOY_MIN(result.z, 1.0f);
  col = SOY_pixel(
      (uint8)(result.x*255.0f),
      (uint8)(result.y*255.0f),
      (uint8)(result.z*255.0f),
      255);
  if(texture != NULL) {
    if(renderMode & SOY_RENDER_TEXTURE) {
      SOY_draw3DTriangleTextured(
        canvas, depthbuffer, texture, TRUE, tri.colour.w,
        tri.v1.x, tri.v1.y, tri.v2.x,
        tri.v2.y, tri.v3.x, tri.v3.y,
        tri.t1.x, tri.t1.y, tri.t1.z,
        tri.t2.x, tri.t2.y, tri.t2.z,
        tri.t3.x, tri.t3.y, tri.t3.z);
    } else if(renderMode & SOY_RENDER_TEXTURE_AFFINE) {
      SOY_draw3DTriangleTextured(
        canvas, depthbuffer, texture, FALSE, tri.colour.w,
        tri.v1.x, tri.v1.y, tri.v2.x,
        tri.v2.y, tri.v3.x, tri.v3.y,
        tri.t1.x, tri.t1.y, tri.t1.z,
        tri.t2.x, tri.t2.y, tri.t2.z,
        tri.t3.x, tri.t3.y, tri.t3.z);
    } else if(renderMode & SOY_RENDER_SOLID) {
      SOY_draw3DTriangleSolid(
        canvas, depthbuffer, col,
        tri.v1.x, tri.v1.y, tri.v2.x,
        tri.v2.y, tri.v3.x, tri.v3.y,
        tri.t1.z,
        tri.t2.z,
        tri.t3.z);
    }

  } else {
    if(!(renderMode & SOY_RENDER_LINES)) {
      SOY_draw3DTriangleSolid(
        canvas, depthbuffer, col,
        tri.v1.x, tri.v1.y, tri.v2.x,
        tri.v2.y, tri.v3.x, tri.v3.y,
        tri.t1.z,
        tri.t2.z,
        tri.t3.z);
    }
  }
  if(renderMode & SOY_RENDER_LINES) {
      SOY_drawSetColour(canvas, col);
      SOY_drawLine(canvas, tri.v1.x, tri.v1.y, tri.v2.x, tri.v2.y);
      SOY_drawLine(canvas, tri.v2.x, tri.v2.y, tri.v3.x, tri.v3.y);
      SOY_drawLine(canvas, tri.v3.x, tri.v3.y, tri.v1.x, tri.v1.y);
    }
  return TRUE;
}

#if 1
#define SOY_MAX_TRIANGLES 4096
#define SOY_MAX_QUEUE_TRIANGLES 32
SOY_GLOBAL soyTriangle g_soyTriangleBuffer[SOY_MAX_TRIANGLES];
SOY_GLOBAL soyTriangle g_soyTriangleQueue[SOY_MAX_QUEUE_TRIANGLES];
SOY_GLOBAL int32 g_triangleDrawCount = 0;
SOY_GLOBAL int32 g_triangleProcessCount = 0;
SOY_GLOBAL real32 g_sunDir[4] = { 0.0f, 1.0f, 0.0f, 0.0f };

int32 SOY_drawSetSunDirection(real32 x, real32 y, real32 z) {
  g_sunDir[0] = x;
  g_sunDir[1] = y;
  g_sunDir[2] = z;
  return TRUE;
}

/* experimental gpu simulation */
#if 0
#define SOY_MAX_VERTS 1024

SOY_GLOBAL vec4f g_soyVertexBuffer[SOY_MAX_VERTS];
SOY_GLOBAL vec4f g_soyTriBuffer[SOY_MAX_VERTS][3];


#define SOY_MAX_VERTEX_DATA 32

typedef struct tag_soyVertexAttribute {
  uint8 types[SOY_MAX_VERTEX_DATA];
  uint8 elements;
} soyVertexAttribute, soyVertexAttrib, soyVA;

soyVA SOY_vertexAttribute() {
  soyVA ret;
  ret.elements = 0;
  SOY_memorySet(ret.types, 0, SOY_MAX_VERTEX_DATA);
  return ret;
}

typedef enum enum_soyAttributeType {
  SOY_BYTE,
  SOY_INT,
  SOY_FLOAT
} soyAttributeType;

int32 SOY_vertexAttributePush(soyVA* va, int32 count, soyAttributeType type) {
  int32 i;
  switch(type) {
    case(SOY_FLOAT): {
      SOY_ASSERT(va->elements + count < SOY_MAX_VERTEX_DATA);
      for(i = 0; i < count; i++) {
        va->types[va->elements++] = type;
      }
      break;
    }
    case(SOY_INT): {
      SOY_ASSERT(va->elements + count < SOY_MAX_VERTEX_DATA);
      for(i = 0; i < count; i++) {
        va->types[va->elements++] = type;
      }
      break;
    }
    case(SOY_BYTE): {
      SOY_ASSERT(va->elements + count < SOY_MAX_VERTEX_DATA);
      for(i = 0; i < count; i++) {
        va->types[va->elements++] = type;
      }
      break;
    }
    default: { break; }
  }
  return TRUE;
};

int32 SOY_projectVertices(
    soyVertexAttribute va,
    real32* dest, real32* vertices, int32 count,
    mat4f model, mat4f view, mat4f projection,
    int32 viewWidth, int32 viewHeight) {
  int32 i;
  vec4f vertex;
  mat4f modelView = SOY_mat4fMultiply(model, view);
  real32 tempZ;
  for(i = 0; i < count; i++) {
    vertex = SOY_vec4f(
        vertices[i*3 + 0],
        vertices[i*3 + 1],
        vertices[i*3 + 2], 1.0f);
    vertex = SOY_vec4fMultiplyMat4f(vertex, modelView);


    vertex = SOY_vec4fMultiplyMat4f(vertex, projection);
    tempZ = 1.0f / vertex.w;
    vertex = v4MulS(vertex, tempZ);
    vertex = SOY_projectToScreen(vertex, viewWidth, viewHeight);
    dest[i*3 + 0] = vertex.x;
    dest[i*3 + 1] = vertex.y;
    dest[i*3 + 2] = vertex.z;
  }
  return TRUE;
}

int32 SOY_triangulateVertices(
    vec4f* dest, real32* vertices, int32* indices, int32 count) {
  int32 i;
  for(i = 0; i < count; i++) {
    dest[i].x = vertices[indices[i]*3 + 0];
    dest[i].y = vertices[indices[i]*3 + 1];
    dest[i].z = vertices[indices[i]*3 + 2];
    dest[i].w = 1.0f;
  }
  return TRUE;
}

int32 SOY_drawTriangles(vec4f* triangles, int32 count) {
  int32 i;
  vec4f vert0, vert1, vert2;
  int32 n = count/3;
  for(i = 0; i < n; i++) {

    vert0 = triangles[i*3 + 0];
    vert1 = triangles[i*3 + 1];
    vert2 = triangles[i*3 + 2];

    SOY_draw3DTriangleSolid(
        0xFFFFFFFF,
        vert0.x, vert0.y,
        vert1.x, vert1.y,
        vert2.x, vert2.y,
        vert0.z, vert1.z, vert2.z
        );
  }
  return TRUE;
}
#endif

int32 SOY_draw3DMesh(
    soyCanvas* canvas, soyCanvas* depthbuffer,
    soyMesh* mesh, soyCanvas* texture,
    soyCamera cam, mat4f model, mat4f view,
    soyRenderMode renderMode, int32 backfaceCull, int32 flipNormals) {
  int32 i, j, k, l;
  vec4f line1, line2;
  mat4f worldMatrix;
  vec4f normal;
  vec4f vCamRay;
  vec4f lightNormal;
  soyTriangle testTri, origTri, worldTri, projTri, finalTri, viewTri;
  mat4f projectionMatrix;
  real32 sunDP = 0;
  int32 clippedTris = 0;
  soyTriangle clipped[2];
  int32* clipRect = canvas->rgba.clipRect;
  int32 culled = 0;
  int32 origTriCount = 0;
  int32 clipTriCount = 0;
  int32 newTriCount = 0;
  int32 addTriCount = 0;
  int32 triQueueBack = 0;
  int32 triQueueFront = 0;

  vec4f vCam = SOY_vec4f(0.0f, 0.0f, 0.0f, 0.0f);
  vec4f vSun = SOY_vec4f(g_sunDir[0], g_sunDir[1], g_sunDir[2], g_sunDir[3]);

  soyPixel origCol = SOY_drawGetColour(canvas);
  real32 origColR = (real32)SOY_pixelGetChannel(origCol, 'r')/255.0f;
  real32 origColG = (real32)SOY_pixelGetChannel(origCol, 'g')/255.0f;
  real32 origColB = (real32)SOY_pixelGetChannel(origCol, 'b')/255.0f;

  /* get world matrix from transform parameter */
  worldMatrix = SOY_mat4fMultiply(model, view);

  projectionMatrix =
    SOY_mat4fProjection(
        cam.nearClip, cam.farClip,
        cam.fieldOfView, cam.aspectRatio);

  /* get projection matrix from camera parameter */

  /* number of all triangles in mesh */
  origTriCount = mesh->triangleCount;

  /* project and transform triangles in mesh */
  for(i = 0; i < origTriCount; i++ ) {
    g_triangleProcessCount++;
    origTri = mesh->triangles[i];
    worldTri = origTri;
    /* place vertices into world space */

    worldTri.v1 = SOY_vec4fMultiplyMat4f(origTri.v1, worldMatrix);
    worldTri.v2 = SOY_vec4fMultiplyMat4f(origTri.v2, worldMatrix);
    worldTri.v3 = SOY_vec4fMultiplyMat4f(origTri.v3, worldMatrix);

    viewTri = origTri;

    viewTri.v1 = SOY_vec4fMultiplyMat4f(origTri.v1, model);
    viewTri.v2 = SOY_vec4fMultiplyMat4f(origTri.v2, model);
    viewTri.v3 = SOY_vec4fMultiplyMat4f(origTri.v3, model);

    /* get normal vector of triangles */
#if 1
    line1 = SOY_vec4fSubtract(worldTri.v2, worldTri.v1);
    line2 = SOY_vec4fSubtract(worldTri.v3, worldTri.v1);
    normal = SOY_vec4fCross(line1, line2);
    normal = SOY_vec4fNormalize(normal);
    vCamRay = SOY_vec4fSubtract(worldTri.v1, vCam);
    vSun = SOY_vec4fNormalize(vSun);
#endif

#if 1
    /* get light normal vector of triangles */
    line1 = SOY_vec4fSubtract(viewTri.v2, viewTri.v1);
    line2 = SOY_vec4fSubtract(viewTri.v3, viewTri.v1);
    lightNormal = SOY_vec4fCross(line1, line2);
    lightNormal = SOY_vec4fNormalize(lightNormal);
#else
    lightNormal = viewTri.n1;
#endif

    if(backfaceCull) {
      /* cull triangles turned in the opposite direction */
      if(flipNormals) {
        culled = SOY_vec4fDot(normal, vCamRay) < 0.0f;
      } else {
        culled = SOY_vec4fDot(normal, vCamRay) > 0.0f;
      }
    } else {
      backfaceCull = 0.0f;
    }
    if(!culled) {
      sunDP = SOY_MAX(0.0f, SOY_vec4fDot(vSun, lightNormal));
      worldTri.colour = SOY_vec4f(origColR, origColG, origColB, sunDP);
      /* clip triangles that are too close */
      clippedTris = SOY_clipTriAgainstPlane(
          SOY_vec4f(0.0f, 0.0f, cam.nearClip, 0.0f),
          SOY_vec4f(0.0f, 0.0f, 1.0f, 0.0f),
          &worldTri, &clipped[0], &clipped[1]);

      /* multiply world space triangles with projection matrix */
      for(k = 0; k < clippedTris; k++) {
        projTri = clipped[k];
        projTri.v1 = SOY_vec4fMultiplyMat4f(projTri.v1, projectionMatrix);
        projTri.v2 = SOY_vec4fMultiplyMat4f(projTri.v2, projectionMatrix);
        projTri.v3 = SOY_vec4fMultiplyMat4f(projTri.v3, projectionMatrix);

        /* project uv coordiantes */
        projTri.t1.z = 1.0f / projTri.v1.w;
        projTri.t2.z = 1.0f / projTri.v2.w;
        projTri.t3.z = 1.0f / projTri.v3.w;

#if 1
        if(renderMode != SOY_RENDER_TEXTURE_AFFINE) {
          /* perspective-correct uv coordinates */
          projTri.t1.x *= projTri.t1.z;
          projTri.t2.x *= projTri.t2.z;
          projTri.t3.x *= projTri.t3.z;
          projTri.t1.y *= projTri.t1.z;
          projTri.t2.y *= projTri.t2.z;
          projTri.t3.y *= projTri.t3.z;
        }
#endif
        /* project vertices to normalized space */
        projTri.v1 =
          SOY_vec4fMultiplyScalar(projTri.v1, projTri.t1.z);
        projTri.v2 =
          SOY_vec4fMultiplyScalar(projTri.v2, projTri.t2.z);
        projTri.v3 =
          SOY_vec4fMultiplyScalar(projTri.v3, projTri.t3.z);

        /* expand normalized space to screen space */
        projTri.v1 = SOY_projectToScreen(projTri.v1, cam.width, cam.height);
        projTri.v2 = SOY_projectToScreen(projTri.v2, cam.width, cam.height);
        projTri.v3 = SOY_projectToScreen(projTri.v3, cam.width, cam.height);

        if(clipTriCount < SOY_MAX_TRIANGLES) {
          g_soyTriangleBuffer[clipTriCount] = projTri;
        } else {
          SOY_LOG("Error tri cache memory exceeded!\n");
        }
        /* store the final projected, clipped triangle in the cache */
        clipTriCount++;
      }
    }
  }
  /* end projection stage */
#if 0
  for(i = 1; i < clipTriCount; i++) {
    k = i;
    while(SOY_MIN(SOY_MIN(g_soyTriangleBuffer[k].t1.z,
          g_soyTriangleBuffer[k].t2.z), g_soyTriangleBuffer[k].t3.z) >
          SOY_MIN(SOY_MIN(g_soyTriangleBuffer[k-1].t1.z,
          g_soyTriangleBuffer[k-1].t2.z), g_soyTriangleBuffer[k-1].t3.z) &&
          k > 1) {
      origTri = g_soyTriangleBuffer[k];
      g_soyTriangleBuffer[k] = g_soyTriangleBuffer[k-1];
      g_soyTriangleBuffer[k-1] = origTri;
      k--;
    }
  }
#endif
  /* clip to the bounds and rasterize the projected triangles */
  for(i = 0; i < clipTriCount; i++) {
    /* initialize the queue used for caching clipped triangles */
    triQueueBack = 0;
    triQueueFront = 0;
    g_soyTriangleQueue[triQueueBack++] = g_soyTriangleBuffer[i];
    testTri = g_soyTriangleBuffer[i];
    newTriCount = 1;
#if 1
    /* loop for every corner of the bounding rect */
    for(k = 0; k < 4; k++) {
      addTriCount = 0;
      while(newTriCount > 0) {
        if(triQueueFront < triQueueBack) {
          testTri = g_soyTriangleQueue[triQueueFront++];
        } else {
          SOY_LOG("Error in triangle queue\n");
        }
        newTriCount--;
        switch(k) {
          case(0): {
              addTriCount = SOY_clipTriAgainstPlane(
                  SOY_vec4f(0.0f, (real32)clipRect[1], 0.0f, 0.0f),
                  SOY_vec4f(0.0f, 1.0f, 0.0f, 0.0f),
                  &testTri, &clipped[0], &clipped[1]);
              break;
          }
          case(1): {
              addTriCount = SOY_clipTriAgainstPlane(
                  SOY_vec4f(
                    0.0f,
                    (real32)clipRect[3],
                    0.0f,
                    0.0f),
                  SOY_vec4f(0.0f, -1.0f, 0.0f, 0.0f),
                  &testTri, &clipped[0], &clipped[1]);
              break;
          }
          case(2): {
              addTriCount = SOY_clipTriAgainstPlane(
                  SOY_vec4f(-1.0f, 0.0f, 0.0f, 0.0f),
                  SOY_vec4f(1.0f, 0.0f, 0.0f, 0.0f),
                  &testTri, &clipped[0], &clipped[1]);
              break;
          }
          case(3): {
              addTriCount = SOY_clipTriAgainstPlane(
                  SOY_vec4f(
                    (real32)clipRect[2]-1.0f,
                    0.0f,
                    0.0f,
                    0.0f),
                  SOY_vec4f(-1.0f, 0.0f, 0.0f, 0.0f),
                  &testTri, &clipped[0], &clipped[1]);
              break;
          }
        }
        /* enqueue the neccesary amount of new triangles for next loop */
        for(j = 0; j < addTriCount; j++) {
          if(triQueueBack >= SOY_MAX_QUEUE_TRIANGLES) {
            SOY_LOG("Out of tri queue memory\n");
          } else {
            g_soyTriangleQueue[triQueueBack++] = clipped[j];
          }
        }
      }
      newTriCount = triQueueBack - triQueueFront;
    }
#endif
    /* rasterize the final triangles */
#if 1
    for(l = 0; l < newTriCount; l++) {
      if(triQueueFront < triQueueBack) {
        finalTri = g_soyTriangleQueue[triQueueFront++];
        SOY_draw3DTriangle(canvas, depthbuffer,
            texture, finalTri, renderMode);
        g_triangleDrawCount++;
        #if 0
          SOY_sleep(10);
          DRAW_PAUSE;
        #endif
      } else {
        SOY_LOG("Error in triangle queue\n");
      }
    }
#endif
  }
  /* get projection matrix from camera parameter */
  return TRUE;
}
#endif

#endif /* SOY_NO_3D */

/*
* o-------------------------------------------o
* | @draw:filter                              |
* o-------------------------------------------o
*/

#define SOY_MAX_DISPLACEMENT_SIZE 2048*2048

SOY_GLOBAL soyPixel g_soyDispBuffer[SOY_MAX_DISPLACEMENT_SIZE];

int32 SOY_drawDisplace(
    soyCanvas* dest,
    soyCanvas* map, soyCanvas* src, real32 amt,
    int32 x1, int32 y1, int32 x2, int32 y2) {
  int32 x, y;
  int32 w, h;
  int32 dx1, dy1, dx2, dy2, dw, dh;
  real32 dx, dy;
  int32 sx, sy, px, py;
  real32 dispSample;
  int32 disp;
  soyPixel sample = SOY_pixel(0, 0, 0, 0);
  dx1 = 0;
  dy1 = 0;
  dx2 = map->depth.width;
  dy2 = map->depth.height;
  dw = dx2 - dx1;
  dh = dy2 - dy1;
  w = x2 - x1;
  h = y2 - y1;
  SOY_ASSERT(w*h < SOY_MAX_DISPLACEMENT_SIZE);
  SOY_memoryCopy(
      g_soyDispBuffer, src->rgba.data, w*h*sizeof(soyPixel));
  for(y = y1; y < y2; y++) {
    for(x = x1; x < x2; x++) {
      dx = (real32)(x / (real32)(x2 - x1))*(real32)(dw);
      dy = (real32)(y / (real32)(y2 - y1))*(real32)(dh);
      dispSample = map->depth.data[(int32)dx + (int32)dy * (dw)];
      disp = (int32)((dispSample*(real32)(w))*amt);
      sx = SOY_MIN(SOY_MAX((x + disp), 1), w - 1);
      sy = SOY_MIN(SOY_MAX((y + disp), 1), h - 1);
      sample = g_soyDispBuffer[(sx) + (sy) * w];
      px = x;
      py = y;
      if(px >= 0 && px < w && py >= 0 && py < h) {
          SOY_drawPixelColour(dest, px, py, sample);
      }
    }
  }
  return TRUE;
}

/*
* o-------------------------------------------o
* | @commands                                 |
* o-------------------------------------------o
*/

#define SOY_COMMAND_MAX_KEYS 16

typedef struct tag_soyCommand soyCommand;
typedef int32 (*PFSOYCOMMAND) (soyCommand* command, void* args);

struct tag_soyCommand {
  int8* name;
  uint8 keys[SOY_COMMAND_MAX_KEYS];
  int32 keyCount;
  int32 enabled;
  int32 toggle;
  int32 lock;
  int32 pressCount;
  real32 repeatDelay;
  real32 repeatSpeed;
  real32 timer;
  PFSOYCOMMAND action;
  void* actionArgs;
};

#define SOY_MAX_COMMANDS 128

SOY_GLOBAL soyCommand g_soyCommandMemory[128];
SOY_GLOBAL soyCommand g_soyCommandMemoryShift[128];
SOY_GLOBAL soyCommand g_soyCommandMemoryControl[128];
SOY_GLOBAL int32 g_soyCommandCount = 0;
SOY_GLOBAL int32 g_soyCommandCountShift = 0;
SOY_GLOBAL int32 g_soyCommandCountControl = 0;

soyCommand SOY_command(int8* name, PFSOYCOMMAND action, void* args,
    int32 repeat, int32 keyCount, ...) {
  soyCommand ret;
  va_list argList;
  real32 repeatDelay = 0.2f;
  real32 repeatSpeed = 0.05f;
  int32 keyIndex = 0;
  soyKeyCode keyToAdd = 0;
  SOY_ASSERT(keyCount < SOY_COMMAND_MAX_KEYS);
  SOY_ASSERT(action);
  va_start(argList, keyCount);
  ret.name = name;
  ret.keyCount = keyCount;
  ret.action = action;
  ret.actionArgs = args;
  ret.timer = repeat ? repeatDelay : 0.0f;
  ret.repeatDelay = repeat ? repeatDelay : 0.0f;
  ret.repeatSpeed = repeat ? repeatSpeed : 0.0f;
  ret.toggle = TRUE;
  ret.enabled = TRUE;
  ret.lock = FALSE;
  ret.pressCount = 0;
  while(keyCount--) {
    keyToAdd = va_arg(argList, int);
    ret.keys[keyIndex++] = keyToAdd;
  }
  va_end(argList);
  return ret;
}

soyCommand SOY_commandPushBase(int8* name, PFSOYCOMMAND action, void* args,
    int32 repeat, int32 key) {
  soyCommand ret;
  real32 repeatDelay = 0.2f;
  real32 repeatSpeed = 0.05f;
  int32 keyIndex = 0;
  SOY_ASSERT(action);
  ret.name = name;
  ret.keyCount = key == 0 ? 0 : 1;
  ret.action = action;
  ret.actionArgs = args;
  ret.repeatDelay = repeat ? repeatDelay : 0.0f;
  ret.repeatSpeed = repeat ? repeatSpeed : 0.0f;
  ret.timer = repeat ? repeatDelay : 0.0f;
  ret.toggle = FALSE;
  ret.enabled = TRUE;
  ret.lock = FALSE;
  ret.pressCount = 0;
  ret.keys[keyIndex++] = key;
  return ret;
}

int32 SOY_commandPush(int8* name, PFSOYCOMMAND action, void* args,
    int32 repeat, int32 key) {
  if(g_soyCommandCount < SOY_MAX_COMMANDS) {
    g_soyCommandMemory[g_soyCommandCount++] =
      SOY_commandPushBase(name, action, args, repeat, key);
  } else {
    SOY_LOG("Max command count reached\n");
  }
  return TRUE;
}

int32 SOY_commandPushShift(int8* name, PFSOYCOMMAND action, void* args,
    int32 repeat, int32 key) {
  if(g_soyCommandCountShift < SOY_MAX_COMMANDS) {
    g_soyCommandMemoryShift[g_soyCommandCountShift++] =
      SOY_commandPushBase(name, action, args, repeat, key);
  } else {
    SOY_LOG("Max command count reached\n");
  }
  return TRUE;
}

int32 SOY_commandPushControl(int8* name, PFSOYCOMMAND action, void* args,
    int32 repeat, int32 key) {
  if(g_soyCommandCountControl < SOY_MAX_COMMANDS) {
    g_soyCommandMemoryControl[g_soyCommandCountControl++] =
      SOY_commandPushBase(name, action, args, repeat, key);
  } else {
    SOY_LOG("Max command count reached\n");
  }
  return TRUE;
}

int32 SOY_commandUpdate(soyCommand* command,
    soyWindow* window, int32 forceUpdate, int32 enable, real32 delta) {
  int32 i;
  int32 keysPressed = 0;

  if((!command->keyCount || !command->action) && !forceUpdate) {
    return FALSE;
  }

  if(forceUpdate) {
    command->action(command, command->actionArgs);
    command->pressCount++;
    return TRUE;
  }

  if(!window) { return FALSE; }
  for(i = 0; i < command->keyCount; i++) {
    if(SOY_getKeyState(window, command->keys[i])) {
      keysPressed++;
    }
  }
  if(command->repeatDelay > 0.0f) {
    command->timer -= delta;
    if(command->timer < 0.0f) {
      command->timer = command->repeatSpeed;
      command->lock = FALSE;
    }
  }

  if(keysPressed == command->keyCount && command->keyCount) {
    if(!command->lock) {
      if(enable) {
        command->action(command, command->actionArgs);
      }
      command->pressCount++;
      command->lock = TRUE;
    }
  } else {
    command->lock = FALSE;
    command->timer = command->repeatDelay;
  }
  return TRUE;
}

int32 SOY_commandUpdateAll(soyWindow* window, real32 delta) {
  int32 i;
  int32 s = SOY_getKeyState(window, SOY_SHIFT);
  int32 c = SOY_getKeyState(window, SOY_CONTROL);
  int32 fl = s || c;
  for(i = 0; i < g_soyCommandCount; i++) {
    SOY_commandUpdate(&g_soyCommandMemory[i], window, 0, !fl, delta);
    SOY_commandUpdate(&g_soyCommandMemoryShift[i], window, 0, s, delta);
    SOY_commandUpdate(&g_soyCommandMemoryControl[i], window, 0, c, delta);
  }
  return TRUE;
}

soyCommand* SOY_commandFind(int8* name) {
  int32 i;
  for(i = 0; i < g_soyCommandCount; i++) {
    if(SOY_stringCompare(g_soyCommandMemory[i].name, name)) {
      return &g_soyCommandMemory[i];
    }
  }
  for(i = 0; i < g_soyCommandCountShift; i++) {
    if(SOY_stringCompare(g_soyCommandMemoryShift[i].name, name)) {
      return &g_soyCommandMemoryShift[i];
    }
  }
  for(i = 0; i < g_soyCommandCountControl; i++) {
    if(SOY_stringCompare(g_soyCommandMemoryControl[i].name, name)) {
      return &g_soyCommandMemoryControl[i];
    }
  }
  return NULL;
}

/*
* o-------------------------------------------o
* | @gui                                      |
* o-------------------------------------------o
*/

SOY_GLOBAL soyPixel g_soyGUIPalette[32] = {
  0xFFFFFFFF, /* LIGHTEST */
  0xFFD4D0C8, /* LIGHT */
  0xFF808080, /* DARK */
  0xFF404040, /* DARKEST */

  0xFF000000, /* BLACK */
  0xFFFFFFFF, /* BACKGROUND */
  0xFF000000, /* TEXT A */
  0xFF808080,  /* TEXT B */

  0xFFA4CCF4, /* GRAD A */
  0xFF050668, /* GRAD B */
  0xFF808080, /* GRAD C */
  0xFFC0C0C0  /* GRAD D */
};

SOY_GLOBAL soyPixel SOY_DEFAULT_PALETTE[32] = {
  0xFFFFFFFF, /* LIGHTEST */
  0xFFD4D0C8, /* LIGHT */
  0xFF808080, /* DARK */
  0xFF404040, /* DARKEST */
  0xFF000000, /* BLACK */
  0xFFFFFFFF, /* BACKGROUND */
  0xFFFFFFFF, /* TEXT A */
  0xFFD4D0C8, /* TEXT B */
  0xFF050668, /* GRAD A */
  0xFFA4CCF4, /* GRAD B */
  0xFF808080, /* GRAD C */
  0xFFC0C0C0, /* GRAD D */
  0xFF000000,
  0xFF505050,
  0xFF000000,
  0xFFA4CCF4,
  0xFF050668,
  0xFFD4D0C8,
  0xFF808080,
  0xFF202020,
  0xFFEEEEEE,
  0xFFE1DDD4,
  0xFF202020,
  0xFF808080,
  0xFF000000,
  0xFF000000,
  0xFF00DD00
};

soyPixel SOY_indexColour(uint8 index) {
  return g_soyGUIPalette[index];
}

int32 SOY_makePalette(int32 num, soyPixel* colours) {
  int32 i;
  for(i = 0; i < SOY_MIN(32, num); i++) {
    g_soyGUIPalette[i] = colours[i];
  }
  return TRUE;
}

typedef enum enum_soyGUIFlags {
  GUI_INVERT = 1,
  GUI_FILL = 2,
  GUI_COLOUR = 4,
  GUI_PRESS = 8,
  GUI_HOVER = 16,
  GUI_DARK = 32
} soyGUIFlags;

int32 SOY_drawUIRect(soyCanvas* canvas,
    int32 x1, int32 y1, int32 x2, int32 y2, int32 flags) {
  int32 dir = flags & GUI_INVERT;
  int32 dark = (flags & GUI_DARK) ? 3 : 2;
  soyPixel origCol = SOY_drawGetColour(canvas);
  x2--;
  y2--;
  SOY_drawSetColour(canvas, g_soyGUIPalette[dir*(dark)]);
  SOY_drawSetAlpha(canvas, SOY_pixelGetChannel(origCol, 'a'));
  SOY_drawLine(canvas, x1, y1, x2 - 1, y1);
  SOY_drawLine(canvas, x1, y1, x1, y2 - 1);
  SOY_drawSetColour(canvas, g_soyGUIPalette[(!dir)*(dark)]);
  SOY_drawSetAlpha(canvas, SOY_pixelGetChannel(origCol, 'a'));
  SOY_drawLine(canvas, x1, y2, x2, y2);
  SOY_drawLine(canvas, x2, y1, x2, y2);
  SOY_drawSetColour(canvas, origCol);
  if(flags & GUI_FILL) {
    x1++; y1++;
    if(!(flags & GUI_COLOUR)) {
      SOY_drawSetColour(canvas, g_soyGUIPalette[1]);
    }
    SOY_drawSetAlpha(canvas, SOY_pixelGetChannel(origCol, 'a'));
    SOY_drawRectFill(canvas, x1, y1, x2, y2);
  }
  SOY_drawSetColour(canvas, origCol);
  return TRUE;
}

int32 SOY_drawUILine(soyCanvas* canvas,
    int32 x1, int32 y1, int32 x2, int32 y2, int32 flags) {
  int32 ly = (y1 == y2) ? 1 : 0;
  int32 lx = (x1 == x2) ? 1 : 0;
  int32 inv = flags & GUI_INVERT;
  soyPixel origCol = SOY_drawGetColour(canvas);
  SOY_drawSetColour(canvas, g_soyGUIPalette[inv ? 2 : 0]);
  SOY_drawSetAlpha(canvas, SOY_pixelGetChannel(origCol, 'a'));
  SOY_drawLine(canvas, x1, y1, x2, y2);
  SOY_drawSetColour(canvas, g_soyGUIPalette[inv ? 0 : 2]);
  SOY_drawSetAlpha(canvas, SOY_pixelGetChannel(origCol, 'a'));
  SOY_drawLine(canvas, x1 + lx, y1 + ly, x2 + lx, y2 + ly);
  SOY_drawSetColour(canvas, origCol);
  return TRUE;
}

int32 SOY_drawUIRectThick(soyCanvas* canvas,
    int32 x1, int32 y1, int32 x2, int32 y2, int32 flags) {
  soyPixel origCol = SOY_drawGetColour(canvas);
  int32 dir = !(flags & GUI_INVERT);
  int32 col0 = dir ? 1 : 2;
  int32 col1 = dir ? 3 : 0;
  int32 col2 = dir ? 0 : 3;
  int32 col3 = dir ? 2 : 1;
  x2--;
  y2--;
  SOY_drawSetColour(canvas, g_soyGUIPalette[col0]);
  SOY_drawSetAlpha(canvas, SOY_pixelGetChannel(origCol, 'a'));
  SOY_drawLine(canvas, x1, y1, x2 - 1, y1);
  SOY_drawLine(canvas, x1, y1, x1, y2 - 1);
  SOY_drawSetColour(canvas, g_soyGUIPalette[col1]);
  SOY_drawSetAlpha(canvas, SOY_pixelGetChannel(origCol, 'a'));
  SOY_drawLine(canvas, x1, y2, x2, y2);
  SOY_drawLine(canvas, x2, y1, x2, y2);
  x1++; y1++; x2--; y2--;
  SOY_drawSetColour(canvas, g_soyGUIPalette[col2]);
  SOY_drawSetAlpha(canvas, SOY_pixelGetChannel(origCol, 'a'));
  SOY_drawLine(canvas, x1, y1, x2 - 1, y1);
  SOY_drawLine(canvas, x1, y1, x1, y2 - 1);
  SOY_drawSetColour(canvas, g_soyGUIPalette[col3]);
  SOY_drawSetAlpha(canvas, SOY_pixelGetChannel(origCol, 'a'));
  SOY_drawLine(canvas, x1, y2, x2, y2);
  SOY_drawLine(canvas, x2, y1, x2, y2);
  SOY_drawSetColour(canvas, origCol);
  SOY_drawSetAlpha(canvas, SOY_pixelGetChannel(origCol, 'a'));
  if(flags & GUI_FILL) {
    x1++; y1++;
    if(!(flags & GUI_COLOUR)) {
      SOY_drawSetColour(canvas, g_soyGUIPalette[1]);
    }
    SOY_drawSetAlpha(canvas, SOY_pixelGetChannel(origCol, 'a'));
    SOY_drawRectFill(canvas, x1, y1, x2, y2);
  }
  SOY_drawSetColour(canvas, origCol);
  return TRUE;
}

int32 SOY_drawUIButton(soyCanvas* canvas,
    soyFont* font,
    int32 x1, int32 y1, int32 x2, int32 y2,
    int32 flags, int8* text) {
  soyPixel origCol = SOY_drawGetColour(canvas);
  int32 h = y2 - y1;
  int32 ox = x1;
  int32 oy = y1;
  int32 dir = !(flags & GUI_INVERT);
  int32 col0 = dir ? 0 : 3;
  int32 col1 = dir ? 3 : 0;
  int32 col2 = dir ? 1 : 2;
  int32 col3 = dir ? 2 : 1;
  x2--;
  y2--;
  SOY_drawSetColour(canvas, g_soyGUIPalette[col0]);
  SOY_drawLine(canvas, x1, y1, x2 - 1, y1);
  SOY_drawLine(canvas, x1, y1, x1, y2 - 1);
  SOY_drawSetColour(canvas, g_soyGUIPalette[col1]);
  SOY_drawLine(canvas, x1, y2, x2, y2);
  SOY_drawLine(canvas, x2, y1, x2, y2);
  x1++; y1++; x2--; y2--;
  SOY_drawSetColour(canvas, g_soyGUIPalette[col2]);
  SOY_drawLine(canvas, x1, y1, x2 - 1, y1);
  SOY_drawLine(canvas, x1, y1, x1, y2 - 1);
  SOY_drawSetColour(canvas, g_soyGUIPalette[col3]);
  SOY_drawLine(canvas, x1, y2, x2, y2);
  SOY_drawLine(canvas, x2, y1, x2, y2);
  SOY_drawSetColour(canvas, origCol);
  if(flags & GUI_FILL) {
    x1++; y1++;
    if(!(flags & GUI_COLOUR)) {
      SOY_drawSetColour(canvas, g_soyGUIPalette[1]);
    }
    SOY_drawRectFill(canvas, x1, y1, x2, y2);
  }
  SOY_drawSetColour(canvas, g_soyGUIPalette[6]);
  SOY_drawText(canvas, font,
      (ox) + (flags & GUI_INVERT) + 2,
      (oy) + h/2 -
      SOY_drawGetFontData(font).scaledDrawHeight/2 +
      (flags & GUI_INVERT), text);

  SOY_drawSetColour(canvas, origCol);
  return TRUE;
}

/*
* o-------------------------------------------o
* | @rect                                     |
* o-------------------------------------------o
*/

typedef struct tag_soyRect soyRect;

typedef int32 (*PFRECTACTION) (void* args);

typedef enum enum_soyRectState {
  RECT_IDLE             = 0,
  RECT_PRESSED          = 1 << 0,
  RECT_HELD             = 1 << 1,
  RECT_RELEASED         = 1 << 2,
  RECT_HOVER            = 1 << 3,
  RECT_ENABLE_TOGGLE    = 1 << 4,
  RECT_TOGGLED          = 1 << 5,
  RECT_HELD_OUTSIDE     = 1 << 6,
  RECT_HELD_INSIDE      = 1 << 7,
  RECT_RESIZED          = 1 << 8,
  RECT_ENABLED          = 1 << 9,
  RECT_DISABLED         = 1 << 10
} soyRectState;

struct tag_soyRect {
  int8* label;
  int32 labelLen;
  int32 x1;
  int32 y1;
  int32 x2;
  int32 y2;
  int32 width;
  int32 height;
  int32 pickX;
  int32 pickY;
  soyRectState state;
  int16 actionSpeed;
  int16 actionDelay;
  real32 actionTimer;
  PFRECTACTION action;
  void* args;
};

soyRect SOY_rect(int32 x1, int32 y1, int32 x2, int32 y2) {
  soyRect ret;
  ret.pickX = 0;
  ret.pickY = 0;
  ret.state = RECT_IDLE | RECT_RESIZED;
  ret.label = NULL;
  ret.labelLen = 0;
  ret.actionDelay = 200;
  ret.actionSpeed = 50;
  ret.actionTimer = 0.5f;
  ret.x1 = x1;
  ret.y1 = y1;
  ret.x2 = x2;
  ret.y2 = y2;
  ret.width = x2 - x1;
  ret.height = y2 - y1;
  ret.action = NULL;
  ret.args = NULL;
  return ret;
}

#define SOY_FLAG_SET(a, f) (a) |= (f)
#define SOY_FLAG_CLEAR(a, f) (a) &= ~(f)
#define SOY_FLAG_TOGGLE(a, f) (a) ^= (f)

soyRect SOY_rectZero() { return SOY_rect(0, 0, 0, 0); }

soyRect SOY_rectAction(int8* label, PFRECTACTION action, void* args) {
  soyRect ret = SOY_rect(0, 0, 0, 0);
  ret.action = action;
  ret.args = args;
  ret.label = label;
  ret.labelLen = SOY_stringLen(label);
  return ret;
}

soyRect SOY_rectFlag(int8* label, soyRectState flags) {
  soyRect ret = SOY_rect(0, 0, 0, 0);
  ret.label = label;
  ret.labelLen = SOY_stringLen(label);
  ret.state = flags;
  return ret;
}

soyRect SOY_rectActionToggle(int8* label,
    PFRECTACTION action, void* args, int32 initialState) {
  soyRect ret = SOY_rect(0, 0, 0, 0);
  ret.action = action;
  ret.args = args;
  ret.label = label;
  ret.state |= RECT_TOGGLED*initialState | RECT_ENABLE_TOGGLE;
  ret.labelLen = SOY_stringLen(label);
  if(action && initialState) {
    if(action(args)) {
      SOY_FLAG_SET(ret.state, RECT_TOGGLED);
    } else {
      SOY_FLAG_CLEAR(ret.state, RECT_TOGGLED);
    }
  }
  return ret;
}

soyRect SOY_rectBase(int8* label) {
  soyRect ret = SOY_rect(0, 0, 0, 0);
  ret.label = label;
  return ret;
}

int32 SOY_rectResize(soyRect* rect, int32 x1, int32 y1, int32 x2, int32 y2) {
  if(x1 == rect->x1 && y1 == rect->y1 && x2 == rect->x2 && y2 == rect->y2) {
    SOY_FLAG_CLEAR(rect->state, RECT_RESIZED);
  } else {
    SOY_FLAG_SET(rect->state, RECT_RESIZED);
  }
  rect->x1 = x1;
  rect->y1 = y1;
  rect->x2 = x2;
  rect->y2 = y2;
  rect->width = x2 - x1;
  rect->height = y2 - y1;
  return TRUE;
}

int32 SOY_rectUpdateBase(soyRect* btn, int32 mx, int32 my, int32 ms) {
  if(btn->state & RECT_DISABLED) { return TRUE; }
  SOY_FLAG_CLEAR(btn->state, RECT_HOVER | RECT_PRESSED | RECT_RELEASED);
  if(SOY_boundsCheck(mx, my, btn->x1, btn->y1, btn->x2, btn->y2)) {
    SOY_FLAG_SET(btn->state, RECT_HOVER);
  }
  if((btn->state & RECT_HOVER) && !(btn->state & RECT_HELD_OUTSIDE)) {
    if(ms) {
      SOY_FLAG_SET(btn->state, RECT_HELD_INSIDE);
      if(!(btn->state & RECT_HELD)) {
        SOY_FLAG_SET(btn->state, RECT_PRESSED);
        btn->pickX = mx - btn->x1;
        btn->pickY = my - btn->y1;
      }
      SOY_FLAG_SET(btn->state, RECT_HELD);
    } else {
      SOY_FLAG_CLEAR(btn->state, RECT_HELD_INSIDE);
      if(btn->state & RECT_HELD) {
        SOY_FLAG_SET(btn->state, RECT_RELEASED);
        SOY_FLAG_CLEAR(btn->state, RECT_HELD);
        if(btn->state & RECT_ENABLE_TOGGLE) {
          SOY_FLAG_TOGGLE(btn->state, RECT_TOGGLED);
        }
        if(btn->action) {
          if(!btn->action(btn->args)) {
            SOY_FLAG_CLEAR(btn->state, RECT_TOGGLED);
          }
        }
      }
    }
  } else {
    if(!ms) {
      SOY_FLAG_CLEAR(btn->state,
          RECT_HELD | RECT_HELD_INSIDE | RECT_HELD_OUTSIDE);
    } else {
      if(!(btn->state & RECT_HELD_INSIDE)) {
        SOY_FLAG_SET(btn->state, RECT_HELD_OUTSIDE);
      }
    }
  }
  return TRUE;
}

int32 SOY_rectUpdateRepeat(soyRect* btn, int32 mx, int32 my, int32 ms,
    real32 delta) {
  SOY_FLAG_CLEAR(btn->state, RECT_HOVER | RECT_PRESSED | RECT_RELEASED);
  if(SOY_boundsCheck(mx, my, btn->x1, btn->y1, btn->x2, btn->y2)) {
    SOY_FLAG_SET(btn->state, RECT_HOVER);
  }
  if((btn->state & RECT_HOVER) && !(btn->state & RECT_HELD_OUTSIDE)) {
    if(ms) {
      if(btn->actionTimer <= 0.0f || !(btn->state & RECT_HELD)) {
        if(!(btn->state & RECT_HELD) && (btn->state & RECT_ENABLE_TOGGLE)) {
          SOY_FLAG_TOGGLE(btn->state, RECT_TOGGLED);
        }
        if(btn->state & RECT_ENABLE_TOGGLE) {
          if(!(btn->state & RECT_HELD) && btn->action) {
            if(!btn->action(btn->args)) {
              SOY_FLAG_CLEAR(btn->state, RECT_TOGGLED);
            }
          }
        } else {
          if(btn->action) {
            btn->action(btn->args);
          }
        }
        if(btn->state & RECT_HELD) {
            btn->actionTimer = ((real32)btn->actionSpeed * 0.001f);
        }
      } else {
        btn->actionTimer -= delta;
      }
      SOY_FLAG_SET(btn->state, RECT_HELD_INSIDE);
      if(!(btn->state & RECT_HELD)) {
        SOY_FLAG_SET(btn->state, RECT_PRESSED);
      }
      SOY_FLAG_SET(btn->state, RECT_HELD);
    } else {
      SOY_FLAG_CLEAR(btn->state, RECT_HELD_INSIDE);
      if(btn->state & RECT_HELD) {
        SOY_FLAG_SET(btn->state, RECT_RELEASED);
        SOY_FLAG_CLEAR(btn->state, RECT_HELD);
      }
    }
  } else {
    if(!ms) {
      SOY_FLAG_CLEAR(btn->state,
          RECT_HELD | RECT_HELD_INSIDE | RECT_HELD_OUTSIDE);
    } else {
      SOY_FLAG_SET(btn->state, RECT_HELD_OUTSIDE);
    }
  }
  if(!ms) { btn->actionTimer = ((real32)btn->actionDelay * 0.001f); }
  return TRUE;
}

int32 SOY_drawButton(soyCanvas* canvas, soyFont* font, soyRect* rect) {
  int32 textOffset;
  int32 textWidth;
  int32 textPos;
  int8* text = rect->label;
  soyPixel origCol = canvas->rgba.drawColour;
  if((rect->state & RECT_HELD) || (rect->state & RECT_TOGGLED)) {
    SOY_drawUIRect(canvas,
      rect->x1, rect->y1, rect->x2, rect->y2, GUI_INVERT);
    textOffset = 1;
  } else {
    SOY_drawUIRect(canvas,
      rect->x1, rect->y1, rect->x2, rect->y2, GUI_DARK);
    textOffset = 0;
  }
  SOY_drawSetColour(canvas, origCol);
  if(text) {
    textWidth = SOY_drawTextWidth(font, text);
    textPos = (rect->x2 - rect->x1) / 2 - textWidth / 2 - 2;
    SOY_drawText(canvas, font,
        rect->x1 + textPos + textOffset, rect->y1 + 1 + textOffset, text);
  }
  return TRUE;
}

int32 SOY_drawButtonToggled(soyCanvas* canvas, soyFont* font, soyRect* rect) {
  int32 textWidth;
  int32 textPos;
  int32 textOffset = 1;
  int8* text = rect->label;
  soyPixel origCol = canvas->rgba.drawColour;
  SOY_drawUIRect(canvas,
    rect->x1, rect->y1, rect->x2, rect->y2, GUI_INVERT);
  if(text) {
    SOY_drawSetColour(canvas, origCol);
    textWidth = SOY_drawTextWidth(font, text);
    textPos = (rect->x2 - rect->x1) / 2 - textWidth / 2 - 2;
    SOY_drawText(canvas, font,
        rect->x1 + textPos + textOffset, rect->y1 + 1 + textOffset, text);
  }
  return TRUE;
}

int32 SOY_drawButtonBitmask(soyCanvas* canvas, soyFont* font,
    soyRect* rect, uint32* bitmask) {
  int32 btnFlag = GUI_FILL;
  soyPixel origCol = SOY_drawGetColour(canvas);
  if(rect->state & RECT_HOVER) { btnFlag |= GUI_HOVER; }
  if(rect->state & RECT_HELD) {
    btnFlag |= GUI_INVERT; btnFlag |= GUI_PRESS; }
  SOY_drawUIButton(canvas, font,
      rect->x1, rect->y1,
      rect->x2, rect->y2, btnFlag, ((rect->label) ? rect->label : " "));
  SOY_drawSetColour(canvas, origCol);
  if(bitmask) {
    SOY_drawBitmask(canvas,
      rect->x1 + (rect->state & RECT_HELD),
      rect->y1 + (rect->state & RECT_HELD),
      rect->x2 - rect->x1,
      rect->y2 - rect->y1, bitmask);
  }
  return TRUE;
}

int32 SOY_rectCheck(soyRect* rect, int32 flag) {
  return rect->state & flag;
}

int32 SOY_rectPressed(soyRect* rect) {
  return rect->state & RECT_PRESSED;
}

int32 SOY_rectReleased(soyRect* rect) {
  return rect->state & RECT_RELEASED;
}

int32 SOY_rectHeld(soyRect* rect) {
  return rect->state & RECT_HELD;
}

int32 SOY_rectHover(soyRect* rect) {
  return rect->state & RECT_HOVER;
}

int32 SOY_rectHeldOutside(soyRect* rect) {
  return rect->state & RECT_HELD_OUTSIDE;
}

int32 SOY_rectHeldInside(soyRect* rect) {
  return rect->state & RECT_HELD_INSIDE;
}

/*
* o-------------------------------------------o
* | @graphical interface                      |
* o-------------------------------------------o
*/

/*
* o-------------------------------------------o
* | @loaders                                  |
* o-------------------------------------------o
*/

int32 SOY_genMissingTexture(soyCanvas* canvas, soyFont* font,
    int32 width, int32 height, int8* text) {
  soyPixel gradA = SOY_pixel(255, 128, 255, 255);
  soyPixel gradB = SOY_pixel(128, 0, 128, 255);
  int32 x, y;
  int8* soyLib = "soy.lib";
  int32 txtSize = 1;
  if(width >= 256) {
    txtSize = 2;
  }
  SOY_drawSetFontData(font, 7, 14, txtSize);
  SOY_drawGradientV(canvas, 0, 0, width, height, gradA, gradB);
  SOY_drawGradientV(canvas, 2, 2, width - 2, height - 2, gradB, gradA);

  SOY_drawSetColour(canvas, 0xFF000000);
  SOY_drawText(canvas, font,3, height-4-14*txtSize, soyLib);
  SOY_drawText(canvas, font, 4, height-4-14*txtSize, soyLib);
  SOY_drawTextFormat(canvas, font, 3, 6 + 14*txtSize, "%s", text);
  SOY_drawTextFormat(canvas, font, 3, 6, "[%dx%d]", width, height);

#ifndef SOY_NO_MATH
  SOY_drawFilterBlur(canvas, 0, 0, width, width, 2 + txtSize/2);
#endif

  SOY_drawSetColour(canvas, 0x22FFFFFF);
  for(y = 2; y < height - 2; y++) {
    for(x = 2; x < width - 2; x++) {
      if(((x/16) + (y/16))%2 == 0) {
        SOY_drawPixelBlend(canvas, x, y);
      }
    }
  }

  SOY_drawSetColour(canvas, 0xFFFFFFFF);
  SOY_drawText(canvas, font, 3, height-4-14*txtSize, soyLib);
  SOY_drawText(canvas, font, 4, height-4-14*txtSize, soyLib);
  SOY_drawTextFormat(canvas, font, 3, 6 + 14*txtSize, "%s", text);
  SOY_drawTextFormat(canvas, font, 3, 6, "[%dx%d]", width, height);
  SOY_drawSetFontData(font, 7, 14, 1);
  return TRUE;
}

#pragma pack(push, 1)
typedef struct tag_soyBMPFormat {
  uint16 magicNum;
  uint32 fileSize;
  uint16 reserved1;
  uint16 reserved2;
  uint32 dataOffset;
  uint32 infoSize;
  int32 imageWidth;
  int32 imageHeight;
  uint16 bitPlanes;
  uint16 bitCount;
  uint32 compressionType;
  uint32 imageDataSize;
  int32 numPelsX;
  int32 numPelsY;
  uint32 coloursUsed;
  uint32 coloursImportant;
} soyBMPFormat;
#pragma pack(pop)

int32 SOY_loadBMP(soyMemorySector* loadMem,
    soyMemorySector* storeMem, soyCanvas* canvas,
    soyFont* font, int8* filename,
    int32 flipHorizontal, int32 flipVertical) {
  soyBMPFormat* bmp;
  uint8 col[8];
  real32 nA, nR, nG, nB;
  uint8 iA, iR, iG, iB;
  int32 canvX, canvY;
  int32 x, y, z;
  int32 padding;
  int32 imgFinalSize;
  int32 numBytes;
  int32 loadRet;
  uint8* loadBytes;
  SOY_ASSERT(storeMem->base);
  SOY_memorySectorReset(loadMem);
  loadRet = SOY_fileToMemory(loadMem, filename);
  bmp = (soyBMPFormat*)(loadMem->base);
  SOY_LOG4("Loading BMP image: \"%s\" %dx%d %dbit\n",
      filename, bmp->imageWidth, bmp->imageHeight, bmp->bitCount);
  SOY_LOG("BMP data:\n");
  SOY_LOG1("width: %d\n", bmp->imageWidth);
  SOY_LOG1("height: %d\n", bmp->imageHeight);
  SOY_LOG1("bit count: %d\n", bmp->bitCount);
  SOY_LOG1("bit planes: %d\n", bmp->bitPlanes);
  SOY_LOG1("colours used: %d\n", bmp->coloursUsed);
  SOY_LOG1("colours important: %d\n", bmp->coloursImportant);
  SOY_LOG1("compression type: %d\n", bmp->compressionType);
  SOY_LOG1("data offset: %d\n", bmp->dataOffset);
  SOY_LOG1("file size: %d\n", bmp->fileSize);
  SOY_LOG1("image data size: %d\n", bmp->imageDataSize);
  SOY_LOG1("info size: %d\n", bmp->infoSize);
  SOY_LOG1("num pels x: %d\n", bmp->numPelsX);
  SOY_LOG1("num pels y: %d\n", bmp->numPelsY);
  SOY_LOG1("magicNum: %d\n", bmp->magicNum);
  imgFinalSize = bmp->imageWidth*bmp->imageHeight*sizeof(soyPixel);
  SOY_ASSERT(imgFinalSize + storeMem->offset < storeMem->size);
  loadBytes = (loadMem->base + bmp->dataOffset);
  numBytes = bmp->bitCount/8;
  padding = bmp->imageWidth%2;
  if(!loadRet) {
    SOY_LOG1("Failed to load image: %s. Creating placeholder\n", filename);
    SOY_canvasCreate(storeMem, canvas, 128, 128);
    SOY_genMissingTexture(canvas, font, 128, 128, filename);
    return TRUE;
  }
  SOY_canvasCreate(storeMem, canvas, bmp->imageWidth, bmp->imageHeight);
  for(y = 0; y < (int32)SOY_abs(bmp->imageHeight); y++) {
    for(x = 0; x < (int32)SOY_abs(bmp->imageWidth); x++) {
      for(z = 0; z < (int32)sizeof(soyPixel); z++) {
        if(z < numBytes) {
          if(!flipVertical) {
            if(numBytes == 4) {
              col[z] = loadBytes[numBytes - 1 - (z+1)%4];
            } else {
              col[z] = loadBytes[numBytes - 1 - z];
            }
          } else {
            if(numBytes == 4) {
              col[z] = loadBytes[numBytes - 1 - (z+1)%4];
            } else {
              col[z] = loadBytes[z];
            }
          }
        } else {
          col[z] = 255;
        }
      }
      nA = (real32)col[3]/255.0f;
      nR = ((real32)col[0]/255.0f)*nA;
      nG = ((real32)col[1]/255.0f)*nA;
      nB = ((real32)col[2]/255.0f)*nA;
      iA = (uint8)(nA*255.0f);
      iR = (uint8)(nR*255.0f);
      iG = (uint8)(nG*255.0f);
      iB = (uint8)(nB*255.0f);
      canvX = (!flipHorizontal) ? x : bmp->imageWidth - 1 - x;
      canvY = (flipVertical) ? y : bmp->imageHeight - 1 - y;
      canvas->rgba.data[canvX+canvY*bmp->imageWidth] =
        SOY_pixel(iR, iG, iB, iA);
      loadBytes += numBytes;
    }
    loadBytes += (bmp->imageWidth%4) - padding;
  }
  return TRUE;
}

int32 SOY_saveBMP(soyCanvas* canvas, int8* filename) {
  soyBMPFormat bmp;
  uint8 curPixel[3];
  soyPixel curSample;
  int32 x, y;
  int32 w = canvas->rgba.width;
  int32 h = canvas->rgba.height;
  FILE* file = SOY_fileOpen(filename, "wb");
  SOY_LOG1("Saving BMP: %s\n", filename);
  bmp.bitCount = 24;
  bmp.bitPlanes = 1;
  bmp.coloursUsed = 0;
  bmp.coloursImportant = 0;
  bmp.compressionType = 0;
  bmp.dataOffset = 54;
  bmp.imageDataSize = 3*canvas->rgba.width*canvas->rgba.height;
  bmp.fileSize = bmp.imageDataSize+bmp.dataOffset;
  bmp.infoSize = 40;
  bmp.numPelsX = 2834;
  bmp.numPelsY = 2834;
  bmp.magicNum = 19778;
  fwrite(&bmp, sizeof(soyBMPFormat), 1, file);
  for(y = 0; y < h; y++) {
    for(x = 0; x < w; x++) {
      curSample = canvas->rgba.data[x + y*w];
      curPixel[0] = SOY_pixelGetChannel(curSample, 'r');
      curPixel[1] = SOY_pixelGetChannel(curSample, 'g');
      curPixel[2] = SOY_pixelGetChannel(curSample, 'b');
      fwrite(&curPixel, sizeof(curPixel), 1, file);
    }
  }
  SOY_fileClose(file);
  return TRUE;
}

typedef struct tag_soyOBJFormat {
  uint32 magicNum;
  uint32 fileSize;
  uint32 dataOffset;
  uint32 numVerts;
  uint32 numNormals;
  uint32 numUVs;
  uint32 numTris;
  uint32 offsetVerts;
  uint32 offsetNormals;
  uint32 offsetUVs;
  uint32 offsetVertIndices;
  uint32 offsetNormalIndices;
  uint32 offsetUVIndices;
} soyOBJFormat;

#ifndef SOY_NO_3D

soyRawMesh SOY_rawMesh(
    vec4f* verts, vec4i* vertIndices, int32 vertCount,
    vec4f* normals, vec4i* normalIndices, int32 normalCount,
    vec4f* UVs, vec4i* uvIndices, int32 uvCount,
    int32 triangleCount) {
  soyRawMesh ret;
  ret.verts = verts;
  ret.normals = normals;
  ret.UVs = UVs;
  ret.vertIndices = vertIndices;
  ret.normalIndices = normalIndices;
  ret.UVIndices = uvIndices;
  ret.vertCount = vertCount;
  ret.normalCount = normalCount;
  ret.uvCount = uvCount;
  ret.triangleCount = triangleCount;
  return ret;
}

int32 SOY_loadOBJ(soyMemorySector* loadMem,
    soyMemorySector* storeMem, soyMesh* mesh, char* filename) {
  soyRawMesh rawMesh =
    SOY_rawMesh(NULL, NULL, 0, NULL, NULL, 0, NULL, NULL, 0, 0);
  void* file = NULL;
  uint8* loadBase;
  int32 loadOffset = 0;
  size_t finalSize = 0;
  int8 lineHeader[512];
  file = SOY_fileOpen(filename, "r");
  SOY_LOG1("Loading OBJ mesh: \"%s\"\n", filename);
  if(file == NULL) {
    SOY_LOG1("Couldn't find file %s. Creating placeholder\n", filename);
    SOY_meshCreateCube(storeMem, mesh);
    return TRUE;
  }
  SOY_memorySectorReset(loadMem);
  loadBase = loadMem->base;
  while(fscanf(file, "%s", lineHeader) != EOF) {
    if(strcmp(lineHeader, "v") == 0) {
      rawMesh.vertCount++;
    } else if(strcmp(lineHeader, "vt") == 0) {
      rawMesh.uvCount++;
    } else if(strcmp(lineHeader, "vn") == 0) {
      rawMesh.normalCount++;
    } else if(strcmp(lineHeader, "f") == 0) {
      rawMesh.triangleCount++;
    }
  }
  rewind(file);
  finalSize = rawMesh.triangleCount*sizeof(vec4i)*3 +
    rawMesh.vertCount*sizeof(vec4f) +
    rawMesh.normalCount*sizeof(vec4f) +
    rawMesh.uvCount*sizeof(vec4f);
  if((size_t)finalSize + loadMem->offset >= (size_t)loadMem->size) {
    SOY_LOG("Not enough memory to load model\n");
    return FALSE;
  }
  loadMem->offset += finalSize;
  SOY_LOG2("Loading OBJ mesh: \"%s\" %d triangles\n",
      filename, rawMesh.triangleCount);
  loadOffset = 0;
  rawMesh.verts = (vec4f*)(loadBase + loadOffset);
  loadOffset += sizeof(vec4f)*rawMesh.vertCount;
  rawMesh.vertIndices = (vec4i*)(loadBase + loadOffset);
  loadOffset += sizeof(vec4i)*rawMesh.triangleCount;
  rawMesh.normals = (vec4f*)(loadBase + loadOffset);
  loadOffset += sizeof(vec4f)*rawMesh.normalCount;
  rawMesh.normalIndices = (vec4i*)(loadBase + loadOffset);
  loadOffset += sizeof(vec4i)*rawMesh.triangleCount;
  rawMesh.UVs = (vec4f*)(loadBase + loadOffset);
  loadOffset += sizeof(vec4f)*rawMesh.uvCount;
  rawMesh.UVIndices = (vec4i*)(loadBase + loadOffset);
  loadOffset += sizeof(vec4i)*rawMesh.triangleCount;
  rawMesh.vertCount = 0;
  rawMesh.uvCount = 0;
  rawMesh.normalCount = 0;
  rawMesh.triangleCount = 0;
  while(fscanf(file, "%s", lineHeader) != EOF) {
    if(strcmp(lineHeader, "v") == 0) {
      fscanf(file, "%f %f %f\n",
          &rawMesh.verts[rawMesh.vertCount].x,
          &rawMesh.verts[rawMesh.vertCount].y,
          &rawMesh.verts[rawMesh.vertCount].z);
      rawMesh.vertCount++;
    } else if(strcmp(lineHeader, "vt") == 0) {
      fscanf(file, "%f %f\n",
          &rawMesh.UVs[rawMesh.uvCount].x,
          &rawMesh.UVs[rawMesh.uvCount].y);
      rawMesh.uvCount++;
    } else if(strcmp(lineHeader, "vn") == 0) {
      fscanf(file, "%f %f %f\n",
          &rawMesh.normals[rawMesh.normalCount].x,
          &rawMesh.normals[rawMesh.normalCount].y,
          &rawMesh.normals[rawMesh.normalCount].z);
      rawMesh.normalCount++;
    } else if(strcmp(lineHeader, "f") == 0) {
      if(rawMesh.uvCount > 0 && rawMesh.normalCount > 0) {
        fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
          &rawMesh.vertIndices[rawMesh.triangleCount].x,
          &rawMesh.UVIndices[rawMesh.triangleCount].x,
          &rawMesh.normalIndices[rawMesh.triangleCount].x,
          &rawMesh.vertIndices[rawMesh.triangleCount].y,
          &rawMesh.UVIndices[rawMesh.triangleCount].y,
          &rawMesh.normalIndices[rawMesh.triangleCount].y,
          &rawMesh.vertIndices[rawMesh.triangleCount].z,
          &rawMesh.UVIndices[rawMesh.triangleCount].z,
          &rawMesh.normalIndices[rawMesh.triangleCount].z
          );
      } else if(rawMesh.uvCount == 0 && rawMesh.normalCount > 0) {
        fscanf(file, "%d//%d %d//%d %d//%d\n",
          &rawMesh.vertIndices[rawMesh.triangleCount].x,
          &rawMesh.normalIndices[rawMesh.triangleCount].x,
          &rawMesh.vertIndices[rawMesh.triangleCount].y,
          &rawMesh.normalIndices[rawMesh.triangleCount].y,
          &rawMesh.vertIndices[rawMesh.triangleCount].z,
          &rawMesh.normalIndices[rawMesh.triangleCount].z
          );
      } else if(rawMesh.uvCount > 0 && rawMesh.normalCount == 0) {
         fscanf(file, "%d/%d %d/%d %d/%d\n",
          &rawMesh.vertIndices[rawMesh.triangleCount].x,
          &rawMesh.UVIndices[rawMesh.triangleCount].x,
          &rawMesh.vertIndices[rawMesh.triangleCount].y,
          &rawMesh.UVIndices[rawMesh.triangleCount].y,
          &rawMesh.vertIndices[rawMesh.triangleCount].z,
          &rawMesh.UVIndices[rawMesh.triangleCount].z
          );
      } else if(rawMesh.uvCount == 0 && rawMesh.normalCount == 0) {
         fscanf(file, "%d %d %d\n",
          &rawMesh.vertIndices[rawMesh.triangleCount].x,
          &rawMesh.vertIndices[rawMesh.triangleCount].y,
          &rawMesh.vertIndices[rawMesh.triangleCount].z
          );
      }
      rawMesh.triangleCount++;
    }
  }
  SOY_fileClose(file);
  if(rawMesh.uvCount == 0) {
    rawMesh.UVs = NULL;
    rawMesh.UVIndices = NULL;
  }

  if(rawMesh.normalCount == 0) {
    rawMesh.normals = NULL;
    rawMesh.normalIndices = NULL;
  }

  if(rawMesh.vertCount == 0) {
    rawMesh.verts = NULL;
    rawMesh.vertIndices = NULL;
  }

  SOY_meshCreate(storeMem, mesh,
      rawMesh.verts,
      rawMesh.normals,
      rawMesh.UVs,
      rawMesh.vertIndices,
      rawMesh.normalIndices,
      rawMesh.UVIndices,
      rawMesh.triangleCount);
  return TRUE;
}

#endif /* SOY_NO_3D */

#if 0
int32 SOY_loadAudioRAW(soyMemorySector* loadMem,
    soyMemorySector* storeMem, soySample* sample, int8* filename,
    int32 bitrate, int32 samplingRate, int32 channels) {
  size_t fLen;
  int32 stride = bitrate/8;
  int32 padding = storeMem->offset % ((sizeof(int16)*4));
  *sample = SOY_audioSample(filename, NULL, 0, 0, 0, 0, 0);
  SOY_memorySectorReset(loadMem);
  fLen = SOY_fileToMemory(loadMem, filename);
  SOY_ASSERT(channels == 1);
  SOY_ASSERT(bitrate == 16);
  SOY_ASSERT(samplingRate == 48000);
  SOY_LOG1("Loading RAW audio: %s\n", filename);
  if(storeMem->offset + fLen*2 + padding >= storeMem->size) {
    SOY_LOG1("File too large: %s", filename);
    return FALSE;
  }

  sample->dataL = (int16*)(storeMem->base + storeMem->offset);
  sample->dataR = (int16*)(storeMem->base + storeMem->offset + fLen);


  SOY_memoryCopy(storeMem->base+storeMem->offset, loadMem->base, fLen);
  SOY_memoryCopy(storeMem->base+storeMem->offset+fLen, loadMem->base, fLen);

  storeMem->offset += fLen*2 + padding;

  sample->channels = 2;
  sample->length = fLen/stride;
  sample->bitRate = bitrate;
  sample->sampleRate = samplingRate;
  return TRUE;
}
#endif

/*
* o-------------------------------------------o
* | @writing                                  |
* o-------------------------------------------o
*/

#define SOY_BMP_BYTES_PER_PIXEL 3
#define SOY_BMP_FILE_HEADER_SIZE 14
#define SOY_BMP_INFO_HEADER_SIZE 40

SOY_GLOBAL int64 g_soyWriteCounter = 0;

SOY_GLOBAL int8 g_dateStringBuffer[32];
SOY_GLOBAL int8 g_timeStringBuffer[32];

int8* SOY_getDateString() {
  time_t now = time(NULL);
  struct tm* t = localtime(&now);
  int8 day[4];
  int8 month[4];
  int8 year[4];
  snprintf(day, sizeof(day),  "%02d", t->tm_mday);
  snprintf(month, sizeof(month),  "%02d", t->tm_mon + 1);
  snprintf(year, sizeof(year),  "%02d", t->tm_year + 1900);
  snprintf(g_dateStringBuffer, 32, "%s%s%s", day, month, year);
  return g_dateStringBuffer;
}

int8* SOY_getTimeString() {
  time_t now = time(NULL);
  struct tm* t = localtime(&now);
  int8 hour[3];
  int8 min[3];
  snprintf(hour, sizeof(hour),  "%02d", t->tm_hour);
  snprintf(min, sizeof(min),  "%02d", t->tm_min);
  snprintf(g_timeStringBuffer, 32, "%s%s", hour, min);
  return g_timeStringBuffer;
}

int32 SOY_getRandomFilename(int8* buffer,
    int32 buffersize, int8* prefix, int8* postfix) {
  uint32 wc = (SOY_wallClock() & 0xFFFF) + g_soyWriteCounter++;
  snprintf(buffer, buffersize, "%s%04X%s", prefix, wc, postfix);
  return TRUE;
}

uint8* SOY_genBitmapFileHeader (int height, int stride) {
    int fileSize =
      SOY_BMP_FILE_HEADER_SIZE +
      SOY_BMP_INFO_HEADER_SIZE + (stride * height);
    SOY_GLOBAL uint8 fileHeader[] = {
        0,0,0,0,0,0,0,
        0,0,0,0,0,0,0
    };
    fileHeader[0] = (uint8)('B');
    fileHeader[1] = (uint8)('M');
    fileHeader[2] = (uint8)(fileSize);
    fileHeader[3] = (uint8)(fileSize >> 8);
    fileHeader[4] = (uint8)(fileSize >> 16);
    fileHeader[5] = (uint8)(fileSize >> 24);
    fileHeader[10] =
      (uint8)(SOY_BMP_FILE_HEADER_SIZE + SOY_BMP_INFO_HEADER_SIZE);

    return fileHeader;
}

uint8* SOY_genBitmapInfoHeader (int height, int width) {
    SOY_GLOBAL uint8 infoHeader[] = {
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
    };
    infoHeader[0] = (uint8)(SOY_BMP_INFO_HEADER_SIZE);
    infoHeader[4] = (uint8)(width);
    infoHeader[5] = (uint8)(width >> 8);
    infoHeader[6] = (uint8)(width >> 16);
    infoHeader[7] = (uint8)(width >> 24);
    infoHeader[8] = (uint8)(height);
    infoHeader[9] = (uint8)(height >> 8);
    infoHeader[10] = (uint8)(height >> 16);
    infoHeader[11] = (uint8)(height >> 24);
    infoHeader[12] = (uint8)(1);
    infoHeader[14] = (uint8)(SOY_BMP_BYTES_PER_PIXEL*8);
    return infoHeader;
}

int32 SOY_writeBMP(soyCanvas* canvas, uint8* writeMemory, int8* filename) {
  soyMemorySector mem;
  soyPixel sample;
  FILE* file;
  int32 i, j;
  int8 titleBuffer[64];
  int32 height = canvas->rgba.height;
  int32 width = canvas->rgba.width;
  int32 widthInBytes = width * SOY_BMP_BYTES_PER_PIXEL;
  uint8 padding[3] = {0, 0, 0};
  int32 paddingSize = (4 - (widthInBytes) % 4) % 4;
  int32 stride = (widthInBytes) + paddingSize;
  uint8* fileHeader = SOY_genBitmapFileHeader(height, stride);
  uint8* infoHeader = SOY_genBitmapInfoHeader(height, width);
  uint8* bmpConvertMemory = NULL;
  if(!writeMemory) {
    SOY_memorySectorCreate("write mem", &mem, width*3*height*3);
    bmpConvertMemory = mem.base;
  } else {
    bmpConvertMemory = writeMemory;
  }
  for(i = 0; i < height; i++) {
    for(j = 0; j < width; j++) {
      sample = canvas->rgba.data[j + i*width];
      bmpConvertMemory[j*3 + (height - i)*(width*3) + 2] =
        (uint8)SOY_pixelGetChannel(sample, 'r');
      bmpConvertMemory[j*3 + (height - i)*(width*3) + 1] =
        (uint8)SOY_pixelGetChannel(sample, 'g');
      bmpConvertMemory[j*3 + (height - i)*(width*3) + 0] =
        (uint8)SOY_pixelGetChannel(sample, 'b');
    }
  }
  if(filename == NULL) {
    snprintf(titleBuffer, 64, "%02X_%s_%s.BMP",
        (uint32)(g_soyWriteCounter++),
        SOY_getDateString(), SOY_getTimeString());
    SOY_LOG1("%s\n", titleBuffer);
    file = SOY_fileOpen(titleBuffer, "wb");
  } else {
    file = SOY_fileOpen(filename, "wb");
  }
  fwrite(fileHeader, 1, SOY_BMP_FILE_HEADER_SIZE, file);
  fwrite(infoHeader, 1, SOY_BMP_INFO_HEADER_SIZE, file);
  for (i = 0; i < height; i++) {
    fwrite(bmpConvertMemory + (i*widthInBytes),
        SOY_BMP_BYTES_PER_PIXEL, width, file);
    fwrite(padding, 1, paddingSize, file);
  }
  SOY_fileClose(file);
  if(!writeMemory) {
    SOY_memorySectorFree(&mem);
  }
  return TRUE;
}

/*
* o-------------------------------------------o
* | @player input                             |
* o-------------------------------------------o
*/

typedef enum enum_soyKeyState {
  SOY_KEY_INACTIVE,
  SOY_KEY_PRESSED,
  SOY_KEY_HELD,
  SOY_KEY_RELEASED
} soyKeyState;

#define SOY_INPUT_KEY_COUNT 256
#define SOY_INPUT_MOUSE_KEY_COUNT 8

typedef struct tag_soyInput {
  uint8 keyState[SOY_INPUT_KEY_COUNT];
  uint8 mouseState[SOY_INPUT_MOUSE_KEY_COUNT];
  int32 anyKeyPressed;
  int32 lastKey;
  int32 mouseScroll;
  int32 mouseX;
  int32 mouseY;
  int32 mouseDX;
  int32 mouseDY;
} soyInput;

int32 SOY_inputInit(soyInput* input) {
  int32 i;
  for(i = 0; i < SOY_INPUT_KEY_COUNT; i++) {
    input->keyState[i] = 0;
  }
  for(i = 0; i < SOY_INPUT_MOUSE_KEY_COUNT; i++) {
    input->mouseState[i] = 0;
  }
  input->anyKeyPressed = FALSE;
  input->lastKey = -1;
  input->mouseX = 0;
  input->mouseY = 0;
  input->mouseDX = 0;
  input->mouseDY = 0;
  input->mouseScroll = 0;
  return TRUE;
}

int32 SOY_inputUpdateKey(soyInput* input, int32 index, int32 isPressed) {
  uint8* key;
  SOY_ASSERT(index < (int32)SOY_INPUT_KEY_COUNT);
  key = &input->keyState[index];
  SOY_BITCLEAR(*key, SOY_KEY_RELEASED);
  SOY_BITCLEAR(*key, SOY_KEY_PRESSED);
  if(isPressed) {
    if(!SOY_BITCHECK(*key, SOY_KEY_HELD)) {
      SOY_BITSET(*key, SOY_KEY_PRESSED);
    }
    SOY_BITSET(*key, SOY_KEY_HELD);
  } else {
    if(SOY_BITCHECK(*key, SOY_KEY_HELD)) {
      SOY_BITSET(*key, SOY_KEY_RELEASED);
    }
    SOY_BITCLEAR(*key, SOY_KEY_HELD);
  }
  return TRUE;
}

int32 SOY_inputUpdate(soyInput* input) {
  int32 i;
  input->anyKeyPressed = FALSE;
  input->mouseScroll = 0;
  for(i = 0; i < SOY_INPUT_KEY_COUNT; i++) {
    SOY_BITCLEAR(input->keyState[i], SOY_KEY_PRESSED);
    SOY_BITCLEAR(input->keyState[i], SOY_KEY_RELEASED);
  }
  for(i = 0; i < SOY_INPUT_MOUSE_KEY_COUNT; i++) {
    SOY_BITCLEAR(input->mouseState[i], SOY_KEY_PRESSED);
    SOY_BITCLEAR(input->mouseState[i], SOY_KEY_RELEASED);
  }
  return TRUE;
}

int32 SOY_inputUpdateMouseKey(soyInput* input,
    int32 index, int32 isPressed) {
  uint8* key;
  SOY_ASSERT(index < (int32)SOY_INPUT_KEY_COUNT);
  key = &input->mouseState[index];
  SOY_BITCLEAR(*key, SOY_KEY_RELEASED);
  SOY_BITCLEAR(*key, SOY_KEY_PRESSED);
  if(isPressed) {
    if(!SOY_BITCHECK(*key, SOY_KEY_HELD)) {
      SOY_BITSET(*key, SOY_KEY_PRESSED);
    }
    SOY_BITSET(*key, SOY_KEY_HELD);
  } else {
    if(SOY_BITCHECK(*key, SOY_KEY_HELD)) {
      SOY_BITSET(*key, SOY_KEY_RELEASED);
    }
    SOY_BITCLEAR(*key, SOY_KEY_PRESSED);
    SOY_BITCLEAR(*key, SOY_KEY_HELD);
  }
  return TRUE;
}

int32 SOY_inputUpdateMousePosition(soyInput* input, int32 x, int32 y) {
  input->mouseX = x;
  input->mouseY = y;
  return TRUE;
}

int32 SOY_inputUpdateMouseScroll(soyInput* input, int32 scroll) {
  input->mouseScroll = scroll;
  return TRUE;
}

/*=========================================================================*/
/* HIGH LEVEL API                                                          */
/*=========================================================================*/

#ifndef SOY_NO_HARDWARE

/*
* o-------------------------------------------o
* | @GL helpers                               |
* o-------------------------------------------o
*/

SOY_GLOBAL real32 g_soyQuadVUAlt[] = {
     1.0f,  1.0f, 0.0f, 1.0f, 0.0f,
     1.0f, -1.0f, 0.0f, 1.0f, 1.0f,
    -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
    -1.0f,  1.0f, 0.0f, 0.0f, 0.0f
};

SOY_GLOBAL uint32 g_soyQuadIndicesAlt[] = {
  0, 1, 3,
  1, 2, 3
};

typedef struct tag_soyModel {
  SOY_VAO vao;
  SOY_VBO vbo;
  SOY_EBO ebo;
  uint32 instanceBuffer;
  size_t numVertices;
  size_t numIndices;
} soyModel;

int32 SOY_modelInitIndexed(soyModel* model,
    real32* data, int32 dataSize, uint32* indices, int32 indicesSize) {
  SOY_glGenVertexArrays(1, &model->vao);
  SOY_glGenBuffers(1, &model->vbo);
  SOY_glGenBuffers(1, &model->ebo);
  SOY_glBindVertexArray(model->vao);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, model->vbo);
  SOY_glBufferData(GL_ARRAY_BUFFER, dataSize, data);
  SOY_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->ebo);
  SOY_glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices);
  SOY_glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
      5 * sizeof(real32), (void*)0);
  SOY_glVertexAttribEnable(0);
  SOY_glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
      5 * sizeof(real32), (void*)(3 * sizeof(real32)));
  SOY_glVertexAttribEnable(1);
  model->numVertices = dataSize/(sizeof(real32)*5);
  model->numIndices = indicesSize/sizeof(uint32);
  return TRUE;
}

int32 SOY_modelInit(soyModel* model, real32* data, int32 dataSize) {
  SOY_glGenVertexArrays(1, &model->vao);
  SOY_glGenBuffers(1, &model->vbo);
  SOY_glBindVertexArray(model->vao);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, model->vbo);
  SOY_glBufferData(GL_ARRAY_BUFFER, dataSize, data);
  SOY_glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
      5 * sizeof(real32), (void*)0);
  SOY_glVertexAttribEnable(0);
  SOY_glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
      5 * sizeof(real32), (void*)(3 * sizeof(real32)));
  SOY_glVertexAttribEnable(1);
  model->numVertices = dataSize/(sizeof(real32)*5);
  return TRUE;
}

int32 SOY_modelInitQuad(soyModel* model) {
  SOY_modelInitIndexed(model,
      g_soyQuadVUAlt, sizeof(g_soyQuadVUAlt),
      g_soyQuadIndicesAlt, sizeof(g_soyQuadIndicesAlt));
  return TRUE;
}

int32 SOY_modelInitCube(soyModel* model) {
  SOY_modelInitIndexed(model,
      g_soyCubeVU, sizeof(g_soyCubeVU),
      g_soyCubeIndices, sizeof(g_soyCubeIndices));
  return TRUE;
}

int32 SOY_modelMakeInstanced(soyModel* model,
    mat4f* transforms, int32 amt) {
  SOY_glGenBuffers(1, &model->instanceBuffer);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, model->instanceBuffer);
  SOY_glBufferData(GL_ARRAY_BUFFER, amt*sizeof(mat4f), &transforms[0]);
  SOY_glBindVertexArray(model->vao);
  SOY_glVertexAttribEnable(2);
  SOY_glVertexAttribPointer(2,
      4, GL_FLOAT, GL_FALSE, sizeof(mat4f), (void*)0);
  SOY_glVertexAttribEnable(3);
  SOY_glVertexAttribPointer(3,
      4, GL_FLOAT, GL_FALSE, sizeof(mat4f), (void*)(sizeof(vec4f)));
  SOY_glVertexAttribEnable(4);
  SOY_glVertexAttribPointer(4,
      4, GL_FLOAT, GL_FALSE, sizeof(mat4f), (void*)(2 * sizeof(vec4f)));
  SOY_glVertexAttribEnable(5);
  SOY_glVertexAttribPointer(5,
      4, GL_FLOAT, GL_FALSE, sizeof(mat4f), (void*)(3 * sizeof(vec4f)));

  SOY_glVertexAttribDivisor(2, 1);
  SOY_glVertexAttribDivisor(3, 1);
  SOY_glVertexAttribDivisor(4, 1);
  SOY_glVertexAttribDivisor(5, 1);

  SOY_glBindBuffer(GL_ARRAY_BUFFER,0);
  return TRUE;
}

int32 SOY_modelMakeInstancedInt(soyModel* model, uint32* ids, int32 amt) {
  SOY_glGenBuffers(1, &model->instanceBuffer);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, model->instanceBuffer);
  SOY_glBufferData(GL_ARRAY_BUFFER, (amt)*sizeof(uint32), ids);
  SOY_glBindVertexArray(model->vao);
  SOY_glVertexAttribEnable(2);
  SOY_glVertexAttribIPointer(2, 1,
      GL_UNSIGNED_INT, 0, (void*)0);
  SOY_glVertexAttribDivisor(2, 1);
  SOY_glBindBuffer(GL_ARRAY_BUFFER,0);
  return TRUE;
}

int32 SOY_modelMakeInstancedShort(soyModel* model, uint16* ids, int32 amt) {
  SOY_glGenBuffers(1, &model->instanceBuffer);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, model->instanceBuffer);
  SOY_glBufferData(GL_ARRAY_BUFFER, (amt)*sizeof(uint16), ids);
  SOY_glBindVertexArray(model->vao);
  SOY_glVertexAttribEnable(2);
  SOY_glVertexAttribIPointer(2, 1,
      GL_UNSIGNED_SHORT, 0, (void*)0);
  SOY_glVertexAttribDivisor(2, 1);
  SOY_glBindBuffer(GL_ARRAY_BUFFER,0);
  return TRUE;
}

int32 SOY_modelMakeInstancedVec4(soyModel* model, vec4f* ids, int32 amt) {
  SOY_glGenBuffers(1, &model->instanceBuffer);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, model->instanceBuffer);
  SOY_glBufferData(GL_ARRAY_BUFFER, amt*sizeof(vec4f), &ids[0]);
  SOY_glBindVertexArray(model->vao);
  SOY_glVertexAttribEnable(2);
  SOY_glVertexAttribPointer(2,
      4, GL_FLOAT, GL_FALSE, sizeof(vec4f), (void*)0);
  SOY_glVertexAttribDivisor(2, 1);
  SOY_glBindBuffer(GL_ARRAY_BUFFER,0);
  return TRUE;
}

int32 SOY_modelMakeInstancedVec3(soyModel* model, vec3f* ids, int32 amt) {
  SOY_glGenBuffers(1, &model->instanceBuffer);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, model->instanceBuffer);
  SOY_glBufferData(GL_ARRAY_BUFFER, amt*sizeof(vec3f), &ids[0]);
  SOY_glBindVertexArray(model->vao);
  SOY_glVertexAttribEnable(2);
  SOY_glVertexAttribPointer(2,
      3, GL_FLOAT, GL_FALSE, sizeof(vec3f), (void*)0);
  SOY_glVertexAttribDivisor(2, 1);
  SOY_glBindBuffer(GL_ARRAY_BUFFER,0);
  return TRUE;
}

int32 SOY_createShader(soyGLShader* shader, int8* pathVert, int8* pathFrag) {
  SOY_glShaderCreate(pathVert, pathFrag, shader);
  return TRUE;
}

int32 SOY_updateGLTexture(soyGLTexture* texture,
    int32 width, int32 height, uint8* data) {
  SOY_glBindTexture(GL_TEXTURE_2D, texture->id);
  SOY_glTexImage2D(
    GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
    GL_UNSIGNED_BYTE, data);
  SOY_glGenMipmap(GL_TEXTURE_2D);
  return TRUE;
}

int32 SOY_genGLTexture(soyGLTexture* texture,
    int32 width, int32 height, uint8* data) {
  SOY_glSetImageParams(FALSE);
  SOY_glGenTextures(1, &texture->id);
  SOY_glBindTexture(GL_TEXTURE_2D, texture->id);
  texture->data = data;
  SOY_glTexImage2D(
      GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
      GL_UNSIGNED_BYTE, texture->data);
  SOY_glGenMipmap(GL_TEXTURE_2D);
  SOY_glBindTexture(GL_TEXTURE_2D, 0);
  return TRUE;
}

int32 SOY_useShader(soyShader* shader) {
  return SOY_glUseProgram(shader);
}

int32 SOY_renderModel(soyModel* model) {
  SOY_glBindVertexArray(model->vao);
  SOY_glDrawElements(GL_TRIANGLES, model->numIndices, GL_UNSIGNED_INT, 0);
  SOY_glBindVertexArray(0);
  return TRUE;
}

int32 SOY_renderModelWireframe(soyModel* model) {
  SOY_glBindVertexArray(model->vao);
  SOY_glDrawElements(GL_LINES, model->numIndices, GL_UNSIGNED_INT, 0);
  SOY_glBindVertexArray(0);
  return TRUE;
}

int32 SOY_renderModelInstanced(soyModel* model, int32 amt) {
  SOY_glBindVertexArray(model->vao);
  SOY_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->ebo);
  SOY_glDrawElementsInstanced(GL_TRIANGLES,
      model->numIndices, GL_UNSIGNED_INT, 0, amt);
  SOY_glBindVertexArray(0);
  return TRUE;
}

mat4f SOY_viewMatrix(vec3f pos, vec3f dir) {
  mat4f rotY = SOY_mat4fRotationY(-dir.y);
  mat4f rotX = SOY_mat4fRotationX(-dir.x);
  mat4f trans = SOY_mat4fTranslation(-pos.x, -pos.y, -pos.z);
  mat4f ret = SOY_mat4f(1.0f);
  ret = SOY_mat4fMultiply(ret, trans);
  ret = SOY_mat4fMultiply(ret, rotY);
  ret = SOY_mat4fMultiply(ret, rotX);
  return ret;
}

int32 SOY_setMVP(soyShader* shader, mat4f* model, mat4f* view, mat4f* proj) {
  SOY_glSetUniformMat4(shader,
      "model", 1, GL_FALSE, &model->m[0][0]);
  SOY_glSetUniformMat4(shader,
      "view", 1, GL_FALSE, &view->m[0][0]);
  SOY_glSetUniformMat4(shader,
      "projection", 1, GL_FALSE, &proj->m[0][0]);
  return TRUE;
}

#endif

#ifndef SOY_NO_MATH

#ifndef SOY_NO_HARDWARE

/*
* o-------------------------------------------o
* | @player controller                        |
* o-------------------------------------------o
*/


typedef struct tag_soyPlayerCamera {
  mat4f view;
  mat4f model;
  mat4f perspective;
} soyPlayerCamera;

typedef struct tag_soyPlayerController {
  vec3f dir;
  vec3f pos;
} soyPlayerController;

soyPlayerCamera SOY_playerCamera(
    real32 n, real32 f, real32 fov, real32 aspect) {
  soyPlayerCamera ret;
  ret.view = SOY_mat4f(1.0);
  ret.model = SOY_mat4f(1.0);
  ret.perspective = SOY_mat4fProjection(n, f, fov, aspect);
  return ret;
}

int32 SOY_playerCameraAlign(
    soyPlayerCamera* camera, soyPlayerController* pc) {
  mat4f rotY = SOY_mat4fRotationY(-pc->dir.y);
  mat4f rotX = SOY_mat4fRotationX(-pc->dir.x);
  mat4f trans = SOY_mat4fTranslation(-pc->pos.x, -pc->pos.y, -pc->pos.z);
  camera->view = SOY_mat4f(1.0);
  camera->view = SOY_mat4fMultiply(rotX, camera->view);
  camera->view = SOY_mat4fMultiply(rotY, camera->view);
  camera->view = SOY_mat4fMultiply(trans, camera->view);
  return TRUE;
}

int32 SOY_glPlayerCameraActive(
    soyGLShader* shader, soyPlayerCamera* camera) {
  SOY_glSetUniformMat4(shader,
      "model", 1, GL_FALSE, &camera->model.m[0][0]);
  SOY_glSetUniformMat4(shader,
      "view", 1, GL_FALSE, &camera->view.m[0][0]);
  SOY_glSetUniformMat4(shader,
      "projection", 1, GL_FALSE, &camera->perspective.m[0][0]);
  return TRUE;
}

int32 SOY_playerControllerInit(soyPlayerController* pc,
    vec3f pos, vec3f dir) {
  pc->pos = pos;
  pc->dir = dir;
  return TRUE;
}

int32 SOY_playerControllerMove(soyPlayerController* pc, real32 force) {
  pc->pos.x += cos(pc->dir.x)*sin(pc->dir.y)*force;
  pc->pos.y += sin(-pc->dir.x)*force;
  pc->pos.z += cos(pc->dir.x)*cos(pc->dir.y)*force;
#if 0
  if(SOY_fabs(SOY_distance(0.0f, 0.0f, pc->pos.x, pc->pos.z)) > 10.0f) {
    pc->orig.x += pc->pos.x;
    pc->orig.y += pc->pos.y;
    pc->pos.x = 0.0f;
    pc->pos.z = 0.0f;
  }
#endif
  return TRUE;
}
#endif

#endif /* SOY_NO_HARDWARE */

/*
* o-------------------------------------------o
* | @application                              |
* o-------------------------------------------o
*/

typedef int32 (*PFUSERCHARCALLBACK) (soyApp* app, int32 key, int32 state);
typedef int32 (*PFUSERKEYCALLBACK) (soyApp* app, int32 key, int32 state);
typedef int32 (*PFUSERMOUSECALLBACK) (soyApp* app, int32 butt, int32 state);
typedef int32 (*PFUSERMOUSEMOVECALLBACK) (soyApp* app, int32 x, int32 y);
typedef int32 (*PFUSERAUDIO) (soyApp* app, int16* left, int16* right);
typedef int32 (*PFUSERAUDIOCAPTURE) (soyApp* app, int16 left, int16 right);

typedef struct tag_soyAppMemory {
  soyMemorySector base;
  soyMemorySector loadMemory;
  soyMemorySector imageMemory;
  soyMemorySector meshMemory;
  soyMemorySector audioMemory;
  soyMemorySector fontMemory;

  soyMemorySector depthbufferMemory;
  soyMemorySector framebufferMemory;

  soyMemorySector userMemory;
} soyAppMemory;

struct tag_soyApp {
  soyAppMemory memory;

  soyPlatformData platform;

  soyTimingData timing;

  soyCanvas* framebuffer;
  soyCanvas* depthbuffer;

  soyFont* fontRegular;
  soyFont* fontBold;
  soyFont* fontSmall;

  soyInput input;
  soyAudio audio;
  real64 timestep;

  int8* title;

  int32 mouseInRect;
  int32 anyKeyPressed;
  int32 windowResolution;
  int32 isRunning;
  int32 resized;
  int32 enableDecorations;
  int32 drawDecorations;
  int32 captureMouse;
  int32 lockTiming;
  int32 windowX;
  int32 windowY;
  int32 windowWidth;
  int32 windowHeight;
  int32 windowFocused;
  int64 preResizeTime;
  PFUSERCHARCALLBACK userCharCallback;
  PFUSERKEYCALLBACK userKeyCallback;
  PFUSERKEYCALLBACK userMouseCallback;
  PFUSERKEYCALLBACK userMouseMoveCallback;
  PFUSERAUDIO userAudioCallback;
  PFUSERAUDIOCAPTURE userAudioCaptureCallback;
  soyDeviceContext dc;
  soyWindow windowHandle;
};

SOY_GLOBAL soyApp* g_callbackHandle = NULL;

int32 SOY_registerCharCallback(soyApp* app, PFUSERCHARCALLBACK callback) {
  app->userCharCallback = callback;
  return TRUE;
}

int32 SOY_registerKeyCallback(soyApp* app, PFUSERKEYCALLBACK callback) {
  app->userKeyCallback = callback;
  return TRUE;
}

int32 SOY_registerMouseCallback(soyApp* app, PFUSERMOUSECALLBACK callback) {
  app->userMouseCallback = callback;
  return TRUE;
}

int32 SOY_registerMouseMoveCallback(soyApp* app,
    PFUSERMOUSEMOVECALLBACK callback) {
  app->userMouseMoveCallback = callback;
  return TRUE;
}

int32 SOY_registerAudioCallback(soyApp* app, PFUSERAUDIO callback) {
  app->userAudioCallback = callback;
  return TRUE;
}

int32 SOY_registerAudioCaptureCallback(soyApp* app,
    PFUSERAUDIOCAPTURE callback) {
  app->userAudioCaptureCallback = callback;
  return TRUE;
}

int32 SOY_appInit(soyApp* app, int8* title) {
  SOY_LOG("Initializing app structure\n");
  g_callbackHandle = app;
  app->resized = TRUE;
  app->windowFocused = TRUE;
  app->preResizeTime = SOY_wallClock();
  app->mouseInRect = FALSE;
  app->isRunning = FALSE;
  app->timestep = 60.0;
  app->windowResolution = 1;
  app->lockTiming = TRUE;
  app->enableDecorations = TRUE;
  app->drawDecorations = TRUE;
  app->captureMouse = FALSE;
  app->title = title;
  app->userCharCallback = NULL;
  app->userKeyCallback = NULL;
  app->userMouseCallback = NULL;
  app->userMouseMoveCallback = NULL;
  app->userAudioCallback = NULL;
  app->userAudioCaptureCallback = NULL;
  SOY_initPlatformData(&app->platform);
  SOY_initTimingData(&app->timing, &app->platform);
  return TRUE;
}


int32 SOY_resetInput(soyApp* app) {
  int32 i;
  for(i = 0; i < 256; i++) {
    app->input.keyState[i] = 0;
  }
  return TRUE;
}

int32 SOY_keyPressed(soyApp* app, soyKeyCode key) {
  return SOY_BITCHECK(app->input.keyState[key], SOY_KEY_PRESSED);
}

int32 SOY_keyHeld(soyApp* app, soyKeyCode key) {
  return SOY_BITCHECK(app->input.keyState[key], SOY_KEY_HELD);
}

int32 SOY_keyReleased(soyApp* app, soyKeyCode key) {
  return SOY_BITCHECK(app->input.keyState[key], SOY_KEY_RELEASED);
}

int32 SOY_mousePressed(soyApp* app, soyMouseCode key) {
  return SOY_BITCHECK(app->input.mouseState[key], SOY_KEY_PRESSED);
}

int32 SOY_mouseInWindow(soyApp* app) {
  return app->mouseInRect;
}

int32 SOY_mouseDeltaX(soyApp* app) {
  return app->input.mouseDX;
}

int32 SOY_mouseDeltaY(soyApp* app) {
  return app->input.mouseDY;
}

int32 SOY_mouseHeld(soyApp* app, soyMouseCode key) {
  return SOY_BITCHECK(app->input.mouseState[key], SOY_KEY_HELD);
}

int32 SOY_mouseReleased(soyApp* app, soyMouseCode key) {
  return SOY_BITCHECK(app->input.mouseState[key], SOY_KEY_RELEASED);
}

int32 SOY_keyPressedAny(soyApp* app) {
  return app->input.anyKeyPressed;
}

int32 SOY_keyLast(soyApp* app) {
  return app->input.lastKey;
}

int32 SOY_keyState(soyApp* app, int32 key) {
  return SOY_getKeyState(app->windowHandle, key);
}

int32 SOY_mouseX(soyApp* app) {
  return
    (SOY_getMouseScreenX() - SOY_windowX(app->windowHandle)) /
    app->windowResolution;
}

int32 SOY_mouseY(soyApp* app) {
  return
    (SOY_getMouseScreenY() - SOY_windowY(app->windowHandle)) /
    app->windowResolution;
}

int32 SOY_mouseScroll(soyApp* app) {
  return app->input.mouseScroll;
}

int32 SOY_isFullscreen(soyApp* app) {
  return SOY_windowIsMaximized(app->windowHandle);
}

int32 SOY_isMinimized(soyApp* app) {
  return SOY_windowIsMinimized(app->windowHandle);
}

int32 SOY_isFocused(soyApp* app) {
  return app->windowFocused;
}

#ifndef SOY_NO_3D
int32 SOY_loadMesh(soyApp* app, soyMesh* mesh, int8* filename) {
  return SOY_loadOBJ(
      &app->memory.loadMemory,
      &app->memory.meshMemory,
      mesh, filename);
}
#endif /* SOY_NO_3D */

int32 SOY_loadImage(soyApp* app, soyCanvas* canvas, int8* filename) {
  return SOY_loadBMP(
      &app->memory.loadMemory,
      &app->memory.imageMemory,
      canvas, app->fontRegular, filename, 0, 0);
}

#if 0
int32 SOY_loadSample(soyApp* app, soySample* sample, int8* filename) {
  return SOY_loadAudioRAW(
      &app->memory.loadMemory,
      &app->memory.imageMemory,
      sample, filename, 16, 48000, 1);
}
#endif

int32 SOY_width(soyApp* app) {
  return app->framebuffer->rgba.width;
}

int32 SOY_height(soyApp* app) {
  return app->framebuffer->rgba.height;
}

int32 SOY_drawWidth(soyCanvas* canvas) {
  return canvas->rgba.width;
}

int32 SOY_drawHeight(soyCanvas* canvas) {
  return canvas->rgba.height;
}

uint32* SOY_drawBuffer(soyCanvas* canvas) {
  return canvas->rgba.data;
}

int32 SOY_setTimestep(soyApp* app, real64 t) {
  app->timestep = t;
  return 0;
}

int32 SOY_quit(soyApp* app) {
  app->isRunning = FALSE;
  return 0;
}

int32 SOY_windowClose(soyApp* app) {
  SOY_quit(app);
  return TRUE;
}

soyCanvas* SOY_getFramebuffer(soyApp* app) {
  return app->framebuffer;
}

soyCanvas* SOY_getDepthbuffer(soyApp* app) {
  return app->depthbuffer;
}

int32 SOY_newCanvas(soyApp* app,
    soyCanvas* canvas, int32 width, int32 height) {
  SOY_canvasCreate(&app->memory.userMemory, canvas, width, height);
  return TRUE;
}

int32 SOY_newDepthCanvas(soyApp* app,
    soyCanvas* canvas, int32 width, int32 height) {
  SOY_canvasCreateDepth(&app->memory.userMemory, canvas, width, height);
  return TRUE;
}

int32 SOY_enableDecorations(soyApp* app) {
  app->enableDecorations = TRUE;
  return TRUE;
}

int32 SOY_disableDecorations(soyApp* app) {
  app->enableDecorations = FALSE;
  return TRUE;
}

int32 SOY_setDrawDecorations(soyApp* app, int32 v) {
  app->drawDecorations = v;
  return TRUE;
}

int32 SOY_setResolution(soyApp* app, int32 res) {
  int32 origW = app->windowWidth;
  int32 origH = app->windowHeight;
  app->windowResolution = res;
  SOY_canvasResize(app->framebuffer,
    origW/app->windowResolution, origH/app->windowResolution);
  SOY_canvasResize(app->depthbuffer,
    origW/app->windowResolution, origH/app->windowResolution);
  return TRUE;
}

#ifndef SOY_NO_MATH

vec4f SOY_proceduralFill(real32 x, real32 y) {
  real32 ret;
#if 0
  ret = SOY_noiseOctave2D(x, y, 1.0f, 0.5f, 10);
#else
  ret = SOY_noiseSimplex3D(x*10.0f, y*10.0f, 0.0f);
#endif
  ret += 0.5f;
  return v4(ret, ret, ret, 1.0f);
}

#endif /* SOY_NO_MATH */

#if 0
soyCanvas g_fontCanvas;
soyMemorySector g_fontCanvasMemory;
#endif

int32 SOY_generateProceduralAssets(soyApp* app) {
#if 0
  SOY_memorySectorCreate("font canvas", &g_fontCanvasMemory, Megabytes(16));
  SOY_canvasCreate(&g_fontCanvasMemory, &g_fontCanvas, 228, 228);
  SOY_loadImage(app, &g_fontCanvas, "MS_14_SMALL.bmp");
  SOY_packFontToFile(&g_fontCanvas, 16, 8, 14, "smallfont.h");
#endif
  SOY_unpackFont(app->fontRegular, g_packedFont0, 128, 14);
  SOY_unpackFont(app->fontBold, g_packedFont1, 128, 14);
  SOY_unpackFont(app->fontSmall, g_packedFont2, 128, 14);
  SOY_drawSetFontData(app->fontRegular, 7, 14, 1);
  SOY_drawSetFontData(app->fontBold, 7, 14, 1);
  SOY_drawSetFontData(app->fontSmall, 5, 10, 1);
  return 0;
}

int32 SOY_drawWindowBorder(soyApp* app) {
  return SOY_drawUIRectThick(app->framebuffer,
      0, g_soyHitTestRect[0] + 1,
      app->framebuffer->rgba.width,
      app->framebuffer->rgba.height, 0);
}

SOY_GLOBAL uint32 g_soyBitmaskExit[14] = {
  0x000,
  0x000,
  0x000,
  0xC30,
  0x660,
  0x3C0,
  0x180,
  0x3C0,
  0x660,
  0xC30,
  0x000,
  0x000,
  0x000,
  0x000
};

SOY_GLOBAL uint32 g_soyBitmaskMax[14] = {
  0x0000,
  0x0000,
  0x1FF0 >> 1,
  0x1FF0 >> 1,
  0x1010 >> 1,
  0x1010 >> 1,
  0x1010 >> 1,
  0x1010 >> 1,
  0x1010 >> 1,
  0x1010 >> 1,
  0x1FF0 >> 1,
  0x000,
  0x000,
  0x000
};

SOY_GLOBAL uint32 g_soyBitmaskMin[14] = {
  0x000,
  0x000,
  0x000,
  0x000,
  0x000,
  0x000,
  0x000,
  0x000,
  0x000,
  0xFC0 >> 2,
  0xFC0 >> 2,
  0x000,
  0x000,
  0x000
};

SOY_GLOBAL soyRect g_soyRectMax;
SOY_GLOBAL soyRect g_soyRectMin;
SOY_GLOBAL soyRect g_soyRectExit;
SOY_GLOBAL int32 g_soyRectsResolutonPrev = 0;
SOY_GLOBAL int32 g_soyRectsInitialized = FALSE;

int32 SOY_drawWindowCaption(soyApp* app) {
  int32 mx = SOY_mouseX(app);
  int32 my = SOY_mouseY(app);
  int32 ms = SOY_mouseHeld(app, SOY_MOUSE_LEFT);
  int32 btnX1 = app->framebuffer->rgba.width - 4 - 17*3;
  soyPixel origCol = SOY_drawGetColour(app->framebuffer);
  if(g_soyRectsResolutonPrev != app->windowResolution) {
    g_soyRectsInitialized = FALSE;
  }
  if(!g_soyRectsInitialized) {
    g_soyRectsResolutonPrev = app->windowResolution;
    g_soyRectMin =
      SOY_rect(btnX1, 5, btnX1 + 16, 5 + 14);
    g_soyRectMax =
      SOY_rect(btnX1 + 16, 5, btnX1 + 16*2, 5 + 14);
    g_soyRectExit =
      SOY_rect(btnX1 + 2 + 16*2, 5, btnX1 + 2 + 16*3, 5 + 14);
    g_soyRectsInitialized = TRUE;
  }
  SOY_rectUpdateBase(&g_soyRectMax, mx, my, ms);
  SOY_rectUpdateBase(&g_soyRectMin, mx, my, ms);
  SOY_rectUpdateBase(&g_soyRectExit, mx, my, ms);
  SOY_drawSetColour(app->framebuffer, g_soyGUIPalette[1]);
  SOY_drawUIRectThick(app->framebuffer, 0, 0,
      app->framebuffer->rgba.width,
      2 + g_soyHitTestRect[0], GUI_FILL);
  if(app->windowFocused) {
   SOY_drawGradientH(app->framebuffer, 3, 3,
      app->framebuffer->rgba.width - 4,
      g_soyHitTestRect[0] - 2,
      g_soyGUIPalette[8],
      g_soyGUIPalette[9]);

   SOY_drawSetColour(app->framebuffer, g_soyGUIPalette[6]);
    SOY_drawTextBold(app->framebuffer, app->fontRegular, 4,
        g_soyHitTestRect[0]/2-SOY_drawGetFontData(
          app->fontRegular).scaledDrawHeight/2 + 1,
        app->title);
  } else {
    SOY_drawGradientH(app->framebuffer, 3, 3,
      app->framebuffer->rgba.width - 4,
      g_soyHitTestRect[0] - 2,
      g_soyGUIPalette[10],
      g_soyGUIPalette[11]);
    SOY_drawSetColour(app->framebuffer, g_soyGUIPalette[7]);
    SOY_drawTextBold(app->framebuffer, app->fontRegular, 4,
        g_soyHitTestRect[0]/2-SOY_drawGetFontData(
          app->fontRegular).scaledDrawHeight/2 + 1,
        app->title);
  }

  SOY_drawSetColour(app->framebuffer, g_soyGUIPalette[4]);
  SOY_drawButtonBitmask(
      app->framebuffer, app->fontBold, &g_soyRectMax, g_soyBitmaskMax);
  SOY_drawButtonBitmask(
      app->framebuffer, app->fontBold, &g_soyRectMin, g_soyBitmaskMin);
  SOY_drawButtonBitmask(
      app->framebuffer, app->fontBold, &g_soyRectExit, g_soyBitmaskExit);

  if(g_soyRectMax.state & RECT_RELEASED) {
    if(SOY_windowIsMaximized(app->windowHandle)) {
      SOY_windowRestore(app->windowHandle);
    } else {
      SOY_windowMaximize(app->windowHandle);
    }
  }

  if(g_soyRectMin.state & RECT_RELEASED) {
    SOY_windowMinimize(app->windowHandle);
  }

  if(g_soyRectExit.state & RECT_RELEASED) {
    if(SOY_dialogBox(app->windowHandle, "Really quit?", ":(")) {
      SOY_quit(app);
    }
  }
  SOY_drawSetColour(app->framebuffer, origCol);
  return TRUE;
}

int32 SOY_setMouseCapture(soyApp* app, int32 value) {
  app->captureMouse = value;
  SOY_showMouseCursor(!value);
  return TRUE;
}

SOY_GLOBAL int32 g_audioRecording = FALSE;
SOY_GLOBAL int32 g_audioPlaying = FALSE;

int32 SOY_audioStart(soyApp* app) {
  g_audioPlaying = TRUE;
  return SOY_audioBufferPlay(&app->platform);
}

int32 SOY_audioStop(soyApp* app) {
  g_audioPlaying = FALSE;
  return SOY_audioBufferStop(&app->platform);
}

int32 SOY_audioStartCapture(soyApp* app) {
  g_audioRecording = TRUE;
  return SOY_audioBufferCaptureStart(&app->platform);
}

int32 SOY_audioStopCapture(soyApp* app) {
  g_audioRecording = FALSE;
  return SOY_audioBufferCaptureStop(&app->platform);
}

int32 SOY_audioUpdate(soyApp* app, PFAUDIOSAMPLE proc) {
  if(!proc) { return FALSE; }
  SOY_audioUpdateBuffer(
      &app->platform,
      (sizeof(int16)*2),
      app->audio.bufferSize,
      proc, app);
  return TRUE;
}

int32 SOY_audioUpdateCapture(soyApp* app, PFAUDIOCAPTURE proc) {
  if(!proc) { return FALSE; }
  SOY_audioUpdateCaptureBuffer(
      &app->platform,
      (sizeof(int16)*2),
      app->audio.bufferSize,
      proc, app);
  return TRUE;
}

soySampleResult SOY_initialAudioUpdate(void* args) {
  soySampleResult sr;
  soyApp* app = (soyApp*)args;
  real32 toneValue = (real32)sin(app->audio.timer);
  real32 sampleValue = (int16)(toneValue * (real32)8000.0f);
  app->audio.cursorPosition = app->platform.soundBufferIndex;
  sr.left = sampleValue;
  sr.right = sampleValue;
  app->audio.tonePeriod =
    (real64)app->audio.samplingRate / app->audio.toneHz;
  app->audio.timer += SOY_2PI*(1.0/app->audio.tonePeriod);
  return sr;
}

int32 SOY_audioInit(soyApp* app,
    int32 sampleRate, int32 bitRate,
    int32 bufferSize, int32 latencySamples) {
  int32 bytesPerSample = (bitRate/8)*2;
  SOY_audioCreateFullDuplex(app->windowHandle,
      &app->platform, sampleRate, bitRate, bufferSize);
  app->platform.soundLatencySamples = latencySamples;
  app->platform.soundBufferIndex = 0;
  app->audio.cursorPosition = 0;
  app->audio.latency = latencySamples;
  app->audio.bufferSize = bufferSize;
  app->audio.samplingRate = sampleRate;
  app->audio.bitRate = bitRate;
  app->audio.timer = 0.0;
  app->audio.toneHz = 440.0;
  app->audio.tonePeriod = (real64)sampleRate / app->audio.toneHz;
  SOY_audioFillBuffer(&app->platform,
      bytesPerSample, 0, bufferSize, SOY_initialAudioUpdate, app);
  SOY_audioStart(app);
  app->platform.audioCaptureValid = TRUE;
  app->platform.audioValid = TRUE;
  return TRUE;
}

int32 SOY_userStart(soyApp* app);
int32 SOY_userUpdate(soyApp* app, real64 deltaT);
int32 SOY_userRender(soyApp* app, real64 deltaT);
int32 SOY_userStop(soyApp* app);

#ifdef SOY_DYNAMIC_LIB
int32 SOY_userStart(soyApp* app) { return TRUE; }
int32 SOY_userUpdate(soyApp* app, real64 dt) { return TRUE; }
int32 SOY_userRender(soyApp* app, real64 dt) { return TRUE; }
int32 SOY_userStop(soyApp* app) { return TRUE; }
#endif

SOY_GLOBAL int32 g_internalAudioFrames = 0;
SOY_GLOBAL int32 g_internalAudioCaptureFrames = 0;

soySampleResult SOY_userAudioInternal(void* args) {
  soyApp* app = (soyApp*)args;
  soySampleResult sr;
  app->audio.cursorPosition = app->platform.soundBufferIndex;
  sr.left = 0;
  sr.right = 0;
  app->userAudioCallback((soyApp*)args, &sr.left, &sr.right);
  app->audio.tonePeriod =
    (real64)app->audio.samplingRate / app->audio.toneHz;

  app->audio.timer += (SOY_2PI*(1.0/app->audio.tonePeriod));
#if 0
  if(app->audio.timer > SOY_2PI) {
    app->audio.timer = 0.0f;
  }
#endif
  g_internalAudioFrames++;
  return sr;
}

int32 SOY_userAudioCaptureInternal(void* args, int16 l, int16 r) {
  soyApp* app = (soyApp*)args;
  app->audio.cursorPosition = app->platform.soundCaptureBufferIndex;
  app->userAudioCaptureCallback((soyApp*)args, l, r);
  g_internalAudioCaptureFrames++;
  return TRUE;
}

int32 SOY_create(soyApp* app, int8* title, int32 width, int32 height) {
  int64 curTime = 0;
  int64 curUserTime = 0;
  int64 prevTime = 0;
  int64 prevUserTime = 0;
  int64 curUserCycles = 0;
  int64 prevUserCycles = 0;
  real64 userDeltaCycles = 0.0;
  real64 deltaTime = 0.0;
  real64 userDeltaTime = 0.0;
  real64 secondTimer = 0.0;
  int32 seconds = 0;
  int32 frames = 0;
  soyCanvas framebuffer;
  soyCanvas depthbuffer;
  if(!app) { SOY_LOG("ERROR: App handle can't be NULL\n"); return FALSE; }
  SOY_appInit(app, title);

  /* allocate main memory sector */
  SOY_memorySectorCreate("app", &app->memory.base, Megabytes(128));

  /* partition main memory to sub sectors */
  SOY_memorySectorPartition("LOAD", &app->memory.base,
      &app->memory.loadMemory, Megabytes(4));
  SOY_memorySectorPartition("MESH", &app->memory.base,
      &app->memory.meshMemory, Megabytes(4));
  SOY_memorySectorPartition("IMAGE", &app->memory.base,
      &app->memory.imageMemory, Megabytes(4));
  SOY_memorySectorPartition("FONT", &app->memory.base,
      &app->memory.fontMemory, Megabytes(8));
  SOY_memorySectorPartition("AUDIO", &app->memory.base,
      &app->memory.audioMemory, Megabytes(16));
  SOY_memorySectorPartition("USER", &app->memory.base,
      &app->memory.userMemory, Megabytes(16));
  SOY_memorySectorPartition("FBUF", &app->memory.base,
      &app->memory.framebufferMemory, Megabytes(32));
  SOY_memorySectorPartition("ZBUF", &app->memory.base,
      &app->memory.depthbufferMemory, Megabytes(32));

  app->fontRegular =
    (soyFont*)(app->memory.fontMemory.base);
  app->fontBold =
    (soyFont*)(app->memory.fontMemory.base + sizeof(soyFont));
  app->fontSmall =
    (soyFont*)(app->memory.fontMemory.base + (sizeof(soyFont) << 1));

 /* create framebuffer and depthbuffer */
  SOY_canvasCreate(&app->memory.framebufferMemory,
      &framebuffer, width, height);
  SOY_canvasCreateDepth(&app->memory.depthbufferMemory,
      &depthbuffer, width, height);

  app->framebuffer = &framebuffer;
  app->depthbuffer = &depthbuffer;

   /* generate fonts, textures, models... */
  SOY_generateProceduralAssets(app);

  /* initialize timing related stuff such as setting scheduler frequency */
  /* must remember to reset scheduler before program quits! */
  SOY_timingInit(&app->timing, &app->platform);

  /* initialize input structure */
  SOY_inputInit(&app->input);

  /* fetch current time to initialize timers */
  prevTime = SOY_wallClock();
  curTime = SOY_wallClock();

  /* create the application window */
  /* only one window supported in this implementation */
  app->windowX = SOY_screenWidth()/2 - width / 2;
  app->windowY = SOY_screenHeight()/2 - height / 2;
  app->windowWidth = width;
  app->windowHeight = height;

#ifdef SOY_HARDWARE_ENABLE
  app->windowHandle = SOY_createWindowGL(title,
      app->windowX,
      app->windowY,
      app->windowWidth,
      app->windowHeight);
  app->dc = SOY_getDeviceContext(app->windowHandle);
#else
  app->windowHandle = SOY_createWindow(title,
      app->windowX,
      app->windowY,
      app->windowWidth,
      app->windowHeight);
#endif
  SOY_canvasResize(app->framebuffer,
      width/app->windowResolution,
      height/app->windowResolution);
  SOY_canvasResize(app->depthbuffer,
      width/app->windowResolution,
      height/app->windowResolution);

  SOY_audioInit(app, 48000, 16, 5*48000*sizeof(int16)*2, 48000/8);
#if 1
  SOY_audioStop(app);
#endif

  SOY_makePalette(32, SOY_DEFAULT_PALETTE);

  SOY_LOG2("Created application: [%s][%p]\n", title, (void*)app);

  /* call the user start callback */
  SOY_userStart(app);

  app->lockTiming = FALSE;

  /* main loop will run until isRunning flag is set to false */
  /* either by the user or a platform callback */
  app->isRunning = TRUE;

  while(app->isRunning) {
    /* compute time difference between last frame and current */
    curTime = SOY_wallClock();
    deltaTime = SOY_wallClockDelta(prevTime, curTime);
	prevTime = curTime;

    /* Power saving */
    if(deltaTime < app->timestep) {
    }
#if 1
    SOY_sleep(8);
#endif
    /* update internal input structure */
    SOY_inputUpdate(&app->input);

    if(SOY_boundsCheck(
          SOY_getMouseScreenX(), SOY_getMouseScreenY(),
          app->windowX, app->windowY,
          app->windowX + app->windowWidth,
          app->windowY + app->windowHeight)) {
      app->mouseInRect = TRUE;
    } else {
      app->mouseInRect = FALSE;
    }

    /* poll the OS window for events */
    SOY_pollEvents(app->windowHandle);

    /* if app is still considered running after polling, do rest of loop */
    if(app->isRunning) {

      /* try to keep updates at a defined frequency if lockTiming is set */
      /* this calls Sleep() internally to reduce power consumption */
      /* but this might not be optimal because we have to call */
      /* timeBeginPeriod for an accurate sleep and that is evil */
      if(app->lockTiming) {
        SOY_timingLock(&app->timing, app->timestep, TRUE);
      }

      /* fetch clock and cycles before user callback */
      prevUserTime = SOY_wallClock();
      prevUserCycles = SOY_cycleCount();

      SOY_paintCallback(app->windowHandle);

      /* compute time and cycles difference of user code */
      curUserTime = SOY_wallClock();
      curUserCycles = SOY_cycleCount();
      userDeltaTime = SOY_wallClockDelta(prevUserTime, curUserTime);
      userDeltaCycles = SOY_cyclesDelta(prevUserCycles, curUserCycles);
      app->timing.userCyclesDelta = userDeltaCycles;
      /* log basic performance info to the console every second */
      if(secondTimer >= 1.0) {
        SOY_LOG7( "[%03x] f:[%d] dt:[%.6f] "
                "adt:[%.6f] udt:[%.6f] "
                "c:[%.2f/%.2f]\n",
          seconds, frames, app->timing.globalDeltaMs,
          secondTimer/(real64)frames, userDeltaTime,
          userDeltaCycles, app->timing.cyclesDelta);
        if(app->timing.missedFramesCounter) {
          SOY_LOG1("Missed frames: [%d]\n", app->timing.missedFramesCounter);
          app->timing.missedFramesCounter = 0;
        }
        frames = 0;
        secondTimer = 0.0;
        seconds++;
      }

      /* advance counters, end current frame */
      frames++;
      secondTimer += deltaTime;
    }
  }

  if(app->platform.audioValid) {
    SOY_audioStop(app);
  }

  /* call the user quit callback */
  SOY_userStop(app);

  /* finalite timing related things such as reseting scheduler frequency */
  SOY_timingFinalize(&app->timing, &app->platform);

  /* destroy the window */
  /* NOTE: window could already have been destroyed so this may be a bug */
  SOY_destroyWindow(app->windowHandle);

  /* free any memory allocated by the application */
  /* NOTE: this does not free user allocated memory */
  SOY_memorySectorFree(&app->memory.base);

  /* exit process */
  SOY_LOG1("Quitting application: \"%s\"\n", title);
  return 0;
}

/*
* o-------------------------------------------o
* | @callbacks                                |
* o-------------------------------------------o
*/

/* NOTE: low level API needs to implement all these callbacks! */

int32 SOY_charCallback(soyWindow window, uint8 key) {
  SOY_UNUSED(window);
  SOY_UNUSED(key);
  if(g_callbackHandle->userCharCallback) {
    g_callbackHandle->userCharCallback(g_callbackHandle, key, 1);
  }
  return 0;
}

int32 SOY_keyCallback(soyWindow window, int32 key, int32 code, int32 st) {
  SOY_UNUSED(window);
  SOY_UNUSED(code);
  SOY_inputUpdateKey(&g_callbackHandle->input, key, st);
  g_callbackHandle->input.lastKey = key;
  g_callbackHandle->input.anyKeyPressed = TRUE;
  if(g_callbackHandle->userKeyCallback) {
    g_callbackHandle->userKeyCallback(g_callbackHandle, key, st);
  }

  if(SOY_keyPressed(g_callbackHandle, SOY_F11)) {
    if(SOY_windowIsMaximized(window)) {
      SOY_windowRestore(window);
    } else {
      SOY_windowMaximize(window);
    }
  }
  return 0;
}

SOY_GLOBAL int32 g_mousePressedInClientArea = FALSE;

int32 SOY_mouseCallback(soyWindow window, int32 button, int32 state) {
  int32 mx = SOY_getMouseScreenX();
  int32 my = SOY_getMouseScreenY();
  int32 x1 = SOY_windowX(window) +
    g_soyHitTestRect[0]*g_callbackHandle->windowResolution;
  int32 y1 = SOY_windowY(window) +
    g_soyHitTestRect[1]*g_callbackHandle->windowResolution;
  int32 x2 = SOY_windowX(window) + SOY_windowWidth(window) -
    g_soyHitTestRect[0]*g_callbackHandle->windowResolution;
  int32 y2 = SOY_windowY(window) + SOY_windowHeight(window) -
    g_soyHitTestRect[3]*g_callbackHandle->windowResolution;
  SOY_inputUpdateMouseKey(&g_callbackHandle->input, button, state);
  if(g_callbackHandle->userMouseCallback) {
    g_callbackHandle->userMouseCallback(g_callbackHandle, button, state);
  }
  if(state && mx > x1 && mx < x2 && my > y1 && my < y2) {
    g_mousePressedInClientArea = TRUE;
  }
  if(!state) {
    g_mousePressedInClientArea = FALSE;
  }
  return 0;
}

int32 g_mousePrevX;
int32 g_mousePrevY;

int32 SOY_mouseMoveCallback(soyWindow window, int32 x, int32 y) {
  SOY_UNUSED(window);
  SOY_inputUpdateMousePosition(&g_callbackHandle->input, x, y);
  g_callbackHandle->input.mouseDX = 0;
  g_callbackHandle->input.mouseDY = 0;
  if(g_callbackHandle->captureMouse && SOY_windowIsFocused(window)) {
    g_callbackHandle->input.mouseDX = x - g_callbackHandle->windowWidth/2;
    g_callbackHandle->input.mouseDY = y - g_callbackHandle->windowHeight/2;
    SOY_setMouseCursor(
        g_callbackHandle->windowX + g_callbackHandle->windowWidth/2,
        g_callbackHandle->windowY + g_callbackHandle->windowHeight/2);
    g_mousePrevX = x;
    g_mousePrevY = y;
  }
  if(g_callbackHandle->userMouseMoveCallback) {
    g_callbackHandle->userMouseMoveCallback(g_callbackHandle, x, y);
  }
  return 0;
}

int32 SOY_mouseScrollCallback(soyWindow window, int32 scroll) {
  SOY_UNUSED(window);
  SOY_inputUpdateMouseScroll(&g_callbackHandle->input, scroll);
  return 0;
}

int32 SOY_focusCallback(soyWindow window, int32 state) {
  SOY_UNUSED(window);
  g_callbackHandle->windowFocused = state;
  return 0;
}

int32 SOY_renderCallback(soyWindow window) {
  SOY_UNUSED(window);
  return 0;
}

int32 SOY_repaintCallback(soyWindow window) {
  SOY_UNUSED(window);
  return 0;
}

int64 g_prevPaintTime = 0;
int64 g_fpf = 0;
int64 g_fps = 0;
real32 timer = 0.0f;

int32 SOY_paintCallback(soyWindow window) {
  real64 delta;
  soyApp* app = g_callbackHandle;

  delta = SOY_wallClockDelta(g_prevPaintTime, SOY_wallClock());
  g_prevPaintTime = SOY_wallClock();
  if(app == NULL) { return FALSE; }
  if(!app->isRunning) { return FALSE; }
  if(!SOY_windowIsMaximized(window)) {
    SOY_canvasResize(app->framebuffer,
        app->windowWidth/app->windowResolution,
        app->windowHeight/app->windowResolution);
    SOY_canvasResize(app->depthbuffer,
        app->windowWidth/app->windowResolution,
        app->windowHeight/app->windowResolution);
  }

  /* call the user callback and blit framebuffer to the window */
  SOY_userUpdate(app, delta);
  if(!SOY_windowIsMinimized(window)) {
    SOY_userRender(app, delta);
    SOY_drawResetClipRect(app->framebuffer);
  }
  if(app->enableDecorations && !SOY_windowIsMaximized(window) &&
      app->drawDecorations) {
    SOY_drawWindowBorder(app);
    SOY_drawWindowCaption(app);
  }
  if(app->userAudioCallback && app->platform.audioValid) {
    if(g_audioPlaying) {
      SOY_audioUpdate(app, SOY_userAudioInternal);
    }
  }
  if(app->userAudioCaptureCallback && app->platform.audioCaptureValid) {
    if(g_audioRecording) {
      SOY_audioUpdateCapture(app, SOY_userAudioCaptureInternal);
    }
  }
  app->resized = FALSE;
  if(app->isRunning && !SOY_windowIsMinimized(window)) {
#ifdef SOY_HARDWARE_ENABLE

#else
    SOY_canvasBlit(window, app->framebuffer);
#endif
  }


  timer += delta;
  if(timer >= 1.0) {
    timer -= 1.0;
    g_fps = g_fpf;
    g_fpf = 0;
  }
  g_fpf++;
  return 0;
}

int32 SOY_updateCallback(real32 delta) {
  SOY_UNUSED(delta);
  return 0;
}

int32 SOY_quitCallback(int32 state) {
  SOY_UNUSED(state);
  return 0;
}

int32 SOY_minMaxCallback(soyWindow window, int32* w, int32* h) {
  SOY_UNUSED(window);
  *w = SOY_MIN_WINDOW_X*g_callbackHandle->windowResolution;
  *h = SOY_MIN_WINDOW_Y*g_callbackHandle->windowResolution;
  return TRUE;
}

int32 SOY_hitTestCallback(soyWindow window,
    int32* scaledTitle, int32* scaledBorder, int32* scaledPad) {
  if(g_mousePressedInClientArea) { return FALSE; }
  if(g_callbackHandle->enableDecorations && !SOY_windowIsMaximized(window)) {
    *scaledTitle = g_soyHitTestRect[0]*g_callbackHandle->windowResolution;
    *scaledBorder = g_soyHitTestRect[1]*g_callbackHandle->windowResolution;
    *scaledPad = g_soyHitTestRect[2]*g_callbackHandle->windowResolution;
  } else {
    return FALSE;
  }
  return TRUE;
}

int32 SOY_resizeCallback(soyWindow window,
    int32 x, int32 y, int32 width, int32 height) {
  soyApp* app = g_callbackHandle;
  SOY_UNUSED(window);
  g_soyRectsInitialized = FALSE;
  app->windowWidth = width;
  app->windowHeight = height;
  app->windowX = x;
  app->windowY = y;
  SOY_canvasResize(app->framebuffer,
      width/app->windowResolution,
      height/app->windowResolution);
  SOY_canvasResize(app->depthbuffer,
      width/app->windowResolution,
      height/app->windowResolution);
  app->resized = TRUE;
#ifdef SOY_HARDWARE_ENABLE
  SOY_glViewport(0, 0, SOY_width(app), SOY_height(app));
#endif
  return TRUE;
}

int32 SOY_windowCreateCallback(soyWindow window) {
  SOY_UNUSED(window);
  return 0;
}

int32 SOY_windowCloseCallback(soyWindow window) {
  SOY_UNUSED(window);
  SOY_quit(g_callbackHandle);
  return 0;
}

int32 SOY_initCallback(int32 state) {
  SOY_UNUSED(state);
  return 0;
}

#endif /* SOY_LIB_LEAN */

#endif /* SOY_LIB_H */
