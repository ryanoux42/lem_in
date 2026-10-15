/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** library
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <stdbool.h>

#ifndef libmy
    #define libmy

void pass(void);
void back(void);
void space(void);
void my_putchar(char c);
void my_put_nbr(int nb);
void free_tab(char **tab);
void my_putstr(char const *str);
void my_put_float(double nb, int p, int z);
void my_put_tab(char **buff, char *separator);
int my_isint(char c);
int my_nbrlen(int nb);
int my_isalpha(char c);
int my_str2int(char *str);
int my_tablen(char **tab);
int my_isintstr(char *str);
int my_isalphastr(char *str);
int my_wordscount(char *str);
int my_isalphanum(char *str);
int my_longestlen(char **tab);
int my_strlen(char const *str);
int my_int2bin(unsigned long nb);
int my_put_error(const char *msg);
int my_charocc(char *str, char c);
int my_strocc(char *str, char *sub);
int my_tabcontains(char **tab, char *str);
int my_strcontains(char *str, char *chars);
int my_onlycontains(char *str, char *chars);
int my_isoneof(char c, char *chars, int len);
int my_strcmp(char const *s1, char const *s2);
int my_tabcontainstimes(char **tab, char *str);
int my_skipline(char *str, int index, char *chars);
int my_intextract(char *str, int index, char delim);
int my_strnlen(char const *str, int index, char delim);
int my_strncmp(const char* s1, const char* s2, size_t n);
char *my_stdinstr(void);
char *my_int2str(int nb);
char *my_revstr(char *str);
char *my_strsort(char *str);
char *my_strtrim(char *str);
char *my_strdup(const char *src);
char *my_strdel(char *str, char c);
char *my_strndup(const char *src, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_isolatechars(char *line, char *chars);
char *my_strfuse(char *src1, char const *src2);
char *my_strsub(char* str, int index, char end);
char *my_tab2str(char **strings, char separator);
char *my_strncpy(char* dest, const char* src, int n);
char **my_getwords(char *str);
char **my_tabdup(char **input);
char **my_tabswap(char **tab, int i, int j);
char **my_tabsplit(char **tab, int begin, int end);
char **my_str2tab(char *str, int index, char delim, int end);
char **my_str_to_word_array(char const *str, char del);

typedef struct room {
    char *name;
    bool is_full;
    bool visited;
    int dist_to_end;
    struct room **neighbors;
} room;

typedef struct queue {
    room **items;
    int front;
    int rear;
    int size;
} queue;

typedef struct lemin {
    char **data;
    int nb_ants;
    char **order;
    char **rooms_pos;
    int nb_rooms;
    char **tunnels;
    int nb_tunnels;
    room *current;
} lemin;
int my_isnum(char const letter);
int my_isalnum(char const letter);

int check(int ac, char **av, lemin *l);
int check_room(lemin *l, int i, int *has);
int check_tunnels(lemin *l, int i);
int check_end_room(char const *str);

void get_rooms(lemin *l);
void get_tunnel(lemin *l, int *i);
int find_nb_link(char *name, char **tunnels);
void get_rooms_pos(lemin *l, int *i);
void make_order_room(lemin *l, int ind);
room* init_room(lemin *l);
room** make_link(room** neighbors, char *name, lemin *l, room** nodes);
char *cp_part(char *src, int *j);

void print_moves(room **path, lemin *l);

void algorithm(lemin *l);
int algo_bfs(lemin *l, queue *q, int weight, bool null);

queue* create_queue(int size);
int q_is_full(queue* q);
int q_is_empty(queue* q);
void q_enqueue(queue* q, room *room);
room *q_dequeue(queue* q);

void add_distance(lemin *l);
void find_end_room(lemin *l);

void step_one(int i, lemin *l, room **path);
void step_two(int i, int len_path, lemin *l, room **path);
void step_three(int i, int len_path, lemin *l, room **path);
void step_by_step(room **path, lemin* l, int i, int len_path);

#endif
