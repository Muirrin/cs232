#include <stdio.h>

int tag[8];
int mru[8] = {7,6,5,4,3,2,1,0};

void mruUpdate(int index)
{
    int i;
    // find index in mru
    for (i = 0; i < 8; i++)
        if (mru[i] == index)
            break;
    // move earlier refs one later
    while (i > 0) {
        mru[i] = mru[i-1];
        i--;
    }
    mru[0] = index;
}

int main( )
{
    int addr;
    int i;
    int hits, accesses;
    FILE *fp;
    
    fp = fopen("trace.txt", "r");
    hits = 0;
    accesses = 0;
    while (fscanf(fp, "%x", &addr) > 0) {
        /* simulate fully associative cache with 8 words */
        accesses += 1;
        printf("%3d: 0x%08x ", accesses, addr);
        for (i = 0; i < 8; i++) {
            if (tag[i] == addr) {
                hits += 1;
                printf("Hit%d ", i);
                mruUpdate(i);
                break;
            }
        }
        if (i == 8) {
            /* allocate entry */
            printf("Miss ");
            i = mru[7];
            tag[i] = addr;
            mruUpdate(i);
        }
        for (i = 0; i < 8; i++)
            printf("0x%08x ", tag[i]);
        for (i = 0; i < 8; i++)
            printf("%d ", mru[i]);
        printf("\n");
    }
    printf("Hits = %d, Accesses = %d, Hit ratio = %f\n", hits, accesses, ((float)hits)/accesses);
    fclose(fp);
}
