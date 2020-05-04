#include <stdio.h>

// 2 rows by 4 columns
int tag[2][4];
// mru picks most recently updated of both lines for each column
int mru[4] = {1,1,1,1};

int main()
{
    int addr;
    int hits, accesses;
    FILE *fp;

    fp = fopen("trace.txt", "r");
    hits = 0;
    accesses = 0;
    int i, temp, index;

    //while the number of addresses > 0
    while(fscanf(fp, "%x", &addr) > 0)
    {
        /********* YOUR CODE HERE ************/
        //shifts the bits of the address 2 places and compares using & operator
        index = (addr >> 2) & 3;
        //increments accesses
        accesses++;
        //for loop searches for the tag, goes through the rows
        for(i = 0;i < 2;i++)
        {
            if(tag[index][i] == addr)
            {
                //prints hits
                printf("Hit");
                mru[index] = i;
                hits++;
                break;
            }
        }
        //prints miss
        if(i == 2)
        {
            printf("Miss");
            temp = (mru[index] + 1)%2;
            tag[index][temp] = addr;
            mru[index] = temp;
        }
        //prints the  2x4 array
        for(int i = 0;i < 4;i++)
        {
            printf(" 0x%08x 0x%08x\n",tag[i][0], tag[i][1]);
        }
        //prints the mru array
        for(int i = 0;i < 4;i++){
            printf("%d ", mru[i]);
          }
        printf("\n");

    }
    printf("Hits = %d, Accesses = %d, Hit ratio = %f\n", hits, accesses, ((float)hits)/accesses);
    fclose(fp);
}
