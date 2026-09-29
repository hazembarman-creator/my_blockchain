#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <stddef.h>

typedef struct s_block {
    char                *bid;
    struct s_block      *next;
}               t_block;

typedef struct s_node {
    int                 nid;
    t_block             *blocks;
    struct s_node       *next;
}               t_node;

typedef struct s_chain {
    t_node  *nodes;
}               t_chain;

/* core */
void    chain_init(t_chain *c);
void    chain_free(t_chain *c);

/* commands */
int     cmd_add_node(t_chain *c, const char *nid_str);
int     cmd_rm_node(t_chain *c, char **nids, int count);
int     cmd_add_block(t_chain *c, const char *bid, char **nids, int count);
int     cmd_rm_block(t_chain *c, const char *bid, char **nids, int count);
void    cmd_ls(t_chain *c, int long_format);
int     cmd_sync(t_chain *c);

/* state */
int     chain_node_count(t_chain *c);
int     chain_is_synced(t_chain *c);

/* backup */
int     load_backup(t_chain *c, const char *path);
int     save_backup(t_chain *c, const char *path);

/* errors */
void    print_ok(void);
void    print_nok(int code);

/* utils */
int     str_is_int(const char *s);

#endif
