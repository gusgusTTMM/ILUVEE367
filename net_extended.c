//
// Created by Ross on 3/2/2017.
//

#include "main.h"
#include "net.h"
#include <stddef.h>

struct net_node * getSwitch(){
    struct net_port *node_list;
    struct net_port *p_node;
    node_list = net_get_port_list(0);

    for (p_node = node_list; p_node != NULL; p_node = p_node->next) {
        if(p_node->type == SWITCH)
            return (struct net_node *) p_node;
        }
return NULL;
}

