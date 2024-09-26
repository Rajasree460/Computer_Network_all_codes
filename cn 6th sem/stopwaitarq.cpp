/*stop & wait ARQ*/
#include <stdio.h>

int main() {
    int i, f, frames[50];

    printf("Enter number of frames to transmit: ");
    scanf("%d", &f);

    printf("\nEnter %d frames: ", f);

    for (i = 0; i < f; i++)
        scanf("%d", &frames[i]);

    printf("\nWith Stop-and-Wait ARQ, the frames will be sent and acknowledged as follows:\n\n");

    for (i = 0; i < f; i++) {
        printf("Sending frame %d\n", frames[i]);
        printf("Waiting for acknowledgement...\n");

        // Simulating acknowledgement (assuming it takes 1 unit of time)
        printf("Acknowledgement received for frame %d\n\n", frames[i]);
    }

    printf("All frames successfully transmitted and acknowledged.\n");

    return 0;
}

