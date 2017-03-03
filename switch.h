//
// Created by Ross on 3/2/2017.
//

#include <stdbool.h>

#ifndef ILUVEE367_SWITCH_H
#define ILUVEE367_SWITCH_H

#endif //ILUVEE367_SWITCH_H

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
struct net_port * isRouteable(int dstnode, struct route **table, int tablesize);
void job_q_switch_switch_add(struct switch_queue *j_q, struct switch_job *j);
struct switch_job *job_q_switch_switch_remove(struct switch_queue *j_q);
void job_q_switch_switch_init(struct switch_queue *j_q);
