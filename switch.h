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

