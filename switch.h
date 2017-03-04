//
// Created by Ross on 3/2/2017.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "net.h"
#include "packet.h"
#include "main.h"


struct route {
    bool valid;
    int client_id;
    struct net_port *client_port;
};



enum switch_job_type {
    JOB_SEND_PKT_ALL_PORT,
    JOB_SEND_PKT_ROUTED

};

struct switch_job {
    enum switch_job_type type;
    struct packet *packet;
    int src;
    int dst;
    struct net_port *dstport;
    struct switch_job *next;
};

struct switch_queue {
    struct switch_job *head;
    struct switch_job *tail;
    int occ;
};

void switch_main(int switch_id);

struct net_port * isRouteable(int dstnode, struct route *table, int tablesize);
struct switch_job *job_q_switch_remove(struct switch_queue *j_q);
void job_q_switch_init(struct switch_queue *j_q);
void job_q_switch_add(struct switch_queue *j_q, struct switch_job *j);
int job_q_switch_num(struct switch_queue *j_q);
struct switch_job *job_q_switch_remove(struct switch_queue *j_q);