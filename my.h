/*
** EPITECH PROJECT, 2022
** MY_H
** File description:
** contain the prototype of all function in libmy
*/


#ifndef MY_H_
    #define MY_H_
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <curses.h>
    #include <signal.h>
    #include <string.h>
    #include <sys/wait.h>
    #include <errno.h>

typedef struct terminal{
    char *path;
    char **env;
    size_t size_path;
} term;

struct global{
    pid_t opponent_pid;
    int nb_x;
    int nb_y;
    int end;
    int touch;
};

extern struct global global;

typedef struct bato{
    char **map;
    char **map_op;
} bato;

typedef struct list_t{
    int data;
    char *str;
    struct list_t *next;
    struct list_t *prev;
} list_t;

typedef struct all{
    int lena;
    int lenb;
    list_t *listA;
    list_t *listB;
} all;

typedef struct check{
    int R;
    int r;
    int l;
    int t;
    int d;
    int a;
}*check;

int check_all(term *term,char **array, int which);
int not_valid_env(char *str);
int check_exist(term *term, char **array);
void replace_that(int i, term *term, char **array);
int my_execve(char *tmp, char **array, term *term);
term *other_termin(char *line ,term *term, char **array);
int not_valid(char *line);
int the_fork(pid_t pid, char *line, term *term, char **array);
int crash(int status);
int builtin(char *tmp, char **array, term *term);
term *valid_cd(char **array, term *term, int a);
int other_command(term *term, char **array);
term *home(term *term);
term *my_cd(term *term, char **array);
int my_unsetenv(term *term, char *str);
void my_env(term *term);
int my_setenv(term *term, char **array);
int my_exit(void);
void hit_miss(int tmp2,int tmp,bato *ship);
void victory(bato *ship);
void defeat(bato *ship);
int check_end(bato *ship);
int check_end_opponent(bato *ship);
void showmap(bato *ship);
int check_map(char **map);
int gameplay(int argc, char **argv, bato *ship);
int valid_pid(char *pid);
int is_valid2(char *line);
void help(void);
int is_valid(char *str);
int replace(char *line,bato *ship);
bato *create_map(char *pos,bato *ship);
void global_zero(void);
void receive_attack(bato *ship);
bato *initmap_opponent(bato *ship);
bato *initship(void);
void signal_pid(int sig, siginfo_t *info, void *context);
void signal_touch(int signum);
void signal_count(int signum);
int player2(char *pid, char *pos, bato *ship);
int turn_p2(bato *ship);
int player1(char *pos, bato *ship);
int turn_p1(bato *ship);
int attack_valid(char *line,bato *ship);
void sendhit(int j, int i);
bato *attack(bato *ship);
bato *is_hit(bato *ship, int j , int i);
int my_isinside_html(char *str,int nb);
void compil_html(char *buffer);
void antman_html(char *file);
void antman_img(char *file);
void compil_img(char *buffer, struct stat info);
int my_isinside_img(char *str,int nb);
list_t *add(list_t *chained, char *str,int nb, int i);
int my_isinside(char *str,int nb);
list_t *create_chained(list_t *chained);
void antman_text(char *file);
void whatprint(list_t *chained);
void compil(char *buffer);
void my_putchar(char c);
void firstpart(all *listAB);
void secondpart(all *listAB);
void swap_a(list_t *listA);
void swap_b(list_t *listB);
void swap_ab(list_t *listB, list_t *listA);
void push_a(all *listAB);
void push_b(all *listAB);
void rotate_a(all *listAB);
void rotate_b(all *listAB);
void rotate_ra(all *listAB);
void rotate_rb(all *listAB);
void rotate_rab(all *listAB);
void rotate_ab(all *listAB);
int flags(int argc,char **argv, struct check *flag);
struct check *checkd(char *str,struct check *flag);
struct check *checkt(char *str,struct check *flag);
struct check *checkrev(char *str, struct check *flag);
void sa(list_t *listA);
int *my_intcpy(int *dest, int const *src);
bool str_isnbr(char *str);
int my_intlen(int const *str);
int *my_intdup(int const *src);
int my_put_int(int const *str);
int comparenbr(int *intmap,int nb);
int *searchhighest(int **intmap,int *poshighest);
int bsq(int argc,char *file, struct stat info, char *buffer);
int minint(int a, int b, int c);
int **isdot(int **tmpmap, int i, int j);
int **searchsquare(int **map);
int createpint(char *buffer, int i);
int **createintmap(int **intmap, char *buffer);
char **replacemap(char **map, int *pos);
char **createmap(char **map,char *buffer);
struct check *checkrec(char *str, struct check *flag);
struct check *checka(char *str,struct check *flag);
struct check *checkl(char *str, struct check *flag);
void flagd(int argc,char **argv,struct check *flag);
void writeperm1(int tmp,struct dirent *ls);
char *writeperm2(char perm[],int i,int a);
void writedir(DIR *dirs,struct check *flag,char *tmp);
int dirorfile(char *tmp,struct stat buf);
int writethatdir(char *tmp,int nb, int u, struct check *flag);
int checkfiles(int argc, char **argv,struct check *flag);
int countnb(int argc, struct stat buf,char **argv);
void thedflag(int argc, char **argv);
int nofile(int argc,char **argv);
int isdir(char *str);
void writeinfo(struct dirent *ls,struct check *flag);
int checkifparam(char *str);
int checkcurrent(int argc,char **argv);
long my_octal(long nb);
int isnbr(char c);
int my_compute_power_rec(int nb, int p);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
int my_chr_isalphanum(char c);
char *my_strdup(char const *src);
int error_char(char *buffer);
int error_size(char *buffer);

#endif //MY_H_
