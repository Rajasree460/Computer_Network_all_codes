/*go back N ARQ*/
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void sendFrames(int frames[], int start, int end);
void receiveAcknowledgments(bool ack[], int start, int end);

int main() {
    int num_frames, window_size;
    
    printf("Enter window size: ");
    scanf("%d", &window_size);

    printf("Enter number of frames to transmit: ");
    scanf("%d", &num_frames);

    int frames[num_frames];
    bool ack[num_frames];

    printf("Enter %d frames: ", num_frames);
    for (int i = 0; i < num_frames; i++)
        scanf("%d", &frames[i]);

    printf("\nWith Go-Back-N ARQ, the frames will be sent in the following manner (assuming no corruption of frames)\n\n");

    for (int i = 0; i < num_frames; i += window_size) {
        printf("Sending frames from %d to %d\n", i, i + window_size - 1);
        sendFrames(frames, i, i + window_size);

        printf("Waiting for acknowledgments...\n");
        // Simulating acknowledgment for frames within the window
        for (int j = i; j < i + window_size; j++) {
            // Simulating some frames being lost or corrupted
            if (j % 2 == 0) {
                ack[j] = true; // Assume acknowledgment received
            }
        }
        receiveAcknowledgments(ack, i, i + window_size);
    }

    printf("\nAll frames transmitted and acknowledged successfully.\n");

    return 0;
}

// Function to simulate the sending of frames
void sendFrames(int frames[], int start, int end) {
    for (int i = start; i < end; i++) {
        printf("Sending frame %d\n", frames[i]);
    }
}

// Function to simulate the receiving of acknowledgments
void receiveAcknowledgments(bool ack[], int start, int end) {
    for (int i = start; i < end; i++) {
        if (ack[i]) {
            printf("Acknowledgment received for frame %d\n", i);
        } else {
            printf("Timeout: Resending frame %d\n", i);
        }
    }
}

