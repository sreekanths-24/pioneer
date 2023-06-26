sender program

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TIMEOUT 3
#define ACK 1
#define NACK 0
int main() {
    srand(time(NULL));
    int sequence_number = 0;
    int expected_ack_number = 0;
    int received_ack_number = -1;
    int timeout = 0;
    clock_t start_time;
    while (1) {
        printf("Sending packet %d\n", sequence_number);
        start_time = clock();
        timeout = 0;
        while (1) {
            if (clock() - start_time >= TIMEOUT  {
                printf("Timeout occurred for packet %d\n", sequence_number);
                timeout = 1;
                break;
            }
            if (received_ack_number == sequence_number) {
                printf("Acknowledgement received for packet %d\n", sequence_number);
                expected_ack_number = sequence_number + 1;
                break;
            }
        }
        if (timeout) {
            continue;
        }
        int corrupt = rand() % 2;
        if (corrupt) {
            printf("Sending NACK for packet %d\n", sequence_number);
            received_ack_number = -1;
        } else {
            printf("Sending ACK for packet %d\n", sequence_number);
            received_ack_number = sequence_number;
            sequence_number++;
        }
        if (sequence_number == 10) {
            break;
        }
    }
    return 0;
}

receiver program---------------------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TIMEOUT 3 
#define ACK 1
#define NACK 0
int main() {
srand(time(NULL));
int expected_sequence_number = 0;
int received_sequence_number = -1; 
    int timeout = 0; 
    clock_t start_time; 
    while (1) {
        start_time = clock();
        timeout = 0;
        while (1) {
            if (clock() - start_time >= TIMEOUT ) {
            printf("Timeout occurred  %d\n", expected_sequence_number);
                timeout = 1;
                break;
            }
            int receive = rand() % 2;
            if (receive) {
                received_sequence_number = rand() % 10;
                break;
            }
        }
        if (timeout) {
            continue;
        }
        if (received_sequence_number == expected_sequence_number) {
            printf("Packet %d received\n", expected_sequence_number);
            expected_sequence_number++;
        }
        int corrupt = rand() % 2;
        if (corrupt) {
            printf("Sending NACK for packet %d\n", received_sequence_number);
        } else {
            printf("Sending ACK for packet %d\n", received_sequence_number);
        }
        if (expected_sequence_number == 10) {
            break;
        }
    }
    return 0;
}
