#include "../inc/private_irc.h"

int server_bindaddr(char *port){
    int fd;
    struct addrinfo* head;
    struct addrinfo* runner;
    
    head = server_getaddrinfo(port);
    runner = head;
    while (runner != NULL){
        fd = socket(runner->ai_family,runner->ai_socktype,runner->ai_protocol);
        ft_printf("fd: = %d\n",fd);
        if (fd == -1){
            runner = runner->ai_next;
            continue;
        }
        ft_printf("addr = %s\nlen = %d\n", runner->ai_addr, runner->ai_addrlen);
        if (bind(fd, runner->ai_addr, runner->ai_addrlen) == 0)
            break;
        close(fd);
        runner = runner->ai_next;
    }
    freeaddrinfo(head);
    if (runner == NULL){
        ft_printf("Could not bind socket!\n");
        return -1;
    } else
        return fd;
}