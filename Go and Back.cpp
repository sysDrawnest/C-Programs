#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0
#define WINDOW_SIZE 4

struct packet {
    int sequence_number;
    char data[20];
};

void send_packet(struct packet *p) {
    printf("Sending packet %d: %s\n", p->sequence_number, p->data);
}

void receive_ack(int ack) {
    printf("Received ACK %d\n", ack);
}

int main() {
    int next_seq_num = 0; 
    int base_seq_num = 0; 
    int expected_ack = 0; 
    bool timer_running = false; 
    int timer = 0; 
    struct packet packets[10];
    for (int i = 0; i < 10; i++) {
        packets[i].sequence_number = i;
        sprintf(packets[i].data, "Packet %d", i);
    }
    while (base_seq_num < 10) {
        for (int i = base_seq_num; i < base_seq_num + WINDOW_SIZE && i < 10; i++) {
            if (i < next_seq_num) {
                continue;
            }
            send_packet(&packets[i]);
            if (!timer_running) {
                timer_running = true;
                timer = 0;
            }
            next_seq_num++;
        }
        int ack;
        if (scanf("%d", &ack) != EOF) {
            receive_ack(ack);

            if (ack >= base_seq_num) {
                base_seq_num = ack + 1;
                if (base_seq_num == next_seq_num) {
                    timer_running = false;
                }
            }
        }

        if (timer_running) {
            timer++;
            if (timer == 3) {
                printf("Timer expired, resending packets %d to %d\n", base_seq_num, next_seq_num - 1);
                next_seq_num = base_seq_num;
                timer_running = false;
            }
        }
    }

    printf("All packets sent successfully\n");
    return 0;
}

