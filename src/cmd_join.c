#include "../inc/private_irc_server.h"

void cmd_join(t_env_s *e, t_client *client, char *msg){
    t_client *run;
    char *tmp;

    assert(e && e->clients && client);
    if ((ft_strequ(client->nick, ANON_NICK))){
        s_status_send(client, "Please change your NICK first.\n");
        return ;
    }
    if (ft_strlen(msg) > 0 ){
        run = e->clients;
        tmp = ft_strjoin(client->nick, " left the channel.\n");
        while (run){
            if (run->channel == client->channel && run != client){
                s_status_send(run, tmp);
            }
            run = run->next;
        }
        ft_strdel(&tmp);
        client->channel = ft_atoi(msg);
        run = e->clients;
        tmp = ft_strjoin(client->nick, " joined the channel.\n");
        while (run){
            if (run->channel == client->channel){
                s_status_send(run, tmp);
            }
            run = run->next;
        }
        ft_strdel(&tmp);
        return ;
    }
    s_status_send(client, "Channel change failed, please try again.\n");
}