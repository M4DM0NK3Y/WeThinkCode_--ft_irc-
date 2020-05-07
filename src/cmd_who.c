#include "../inc/private_irc.h"

void cmd_who(t_env *e, t_client *client){
    t_client    *run;
    char        *msg;
    char        *tmp;
    int         len;

    assert(e && client);
    msg = ft_strnew(1);
    run = e->clients;
    while (run){
        if (run->channel == client->channel){
            tmp = msg;
            if (ft_strlen(msg) > 0){
                msg = ft_strjoin(msg, ", ");
                ft_strdel(&tmp);
            }
            msg = ft_strjoin(msg, client->nick);
            ft_strdel(&tmp);
        }
        run = run->next;
    }
    if ((len = ft_strlen(msg)) > 0){
        s_status_send(client, msg);
        ft_strdel(&msg);
    }
}