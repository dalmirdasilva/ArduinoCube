/*
 * Code to controll an 8x8x8 ledcube using avr
 * http://www.instructables.com/id/Led-Cube-8x8x8/
 * See lisence.txt for lisence.
 */

#ifndef GOL_H
#define GOL_H

void gol_play (int iterations, uint16_t delay);
unsigned char gol_count_neighbors (int x, int y, int z);
void gol_nextgen (void);
int gol_count_changes (void);

#endif
