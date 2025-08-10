/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:22:58 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/16 14:54:29 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// INCLUDES //

# include "libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

// COLORS //

# define YELLOW "\001\033[33m\002"
# define RED "\001\033[31m\002"
# define GREY "\001\033[90m\002"
# define RESET "\001\033[0m\002"

// GLOBAL VAR FOR SIGNALS! //

extern volatile sig_atomic_t	g_signal;

// STRUCTS //

typedef struct s_quotes
{
	int							quote;
	int							quote_start;
	int							quote_end;
	int							closed;
}								t_quotes;

typedef struct s_token
{
	char						*str;
	int							greater_than;
	int							double_greater;
	int							less_than;
	int							double_less;
	int							pipe;
	t_quotes					*quotes;
	int							quote_count;
}								t_token;

typedef struct s_token_data
{
	char						*str;
	char						c;
	int							i;
	int							j;
	int							str_i;
	int							size_token;
	t_token						*token;
}								t_token_data;

typedef struct s_ind
{
	int							i;
	int							j;
	int							k;
	int							size;
}								t_ind;

typedef struct s_quote_tracker
{
	int							open_pos;
	int							current_len;
	int							active;
}								t_quote_tracker;

typedef struct s_comand_data
{
	char						**comand;
	char						**in_file;
	char						**out_file;
	int							*heredoc_fd;
	int							n_heredocs;
	t_quotes					**quote;
	t_quotes					**quote_in;
	t_quotes					**quote_out;
	int							*quote_count;
	int							*quote_in_count;
	int							*quote_out_count;
	int							in_count;
	int							out_count;
	int							num_comands;
}								t_comand_data;

typedef struct s_token_state
{
	int							in_single;
	int							in_double;
	int							in_token;
}								t_token_state;

typedef struct s_expan
{
	char						*new_str;
	int							i;
	int							j;
	int							start;
}								t_expan;

typedef struct s_fork_data
{
	int							i;
	int							pipefd[2];
	int							prev_fd;
	pid_t						pid;
	pid_t						*pids;
	int							cmd_count;
}								t_fork_data;

typedef struct s_env
{
	char						*name;
	char						*value;
	struct s_env				*next;
}								t_env;

typedef struct s_shell
{
	t_env						*env;
	t_comand_data				*commands;
	int							num_commands;
	pid_t						*pids;
	int							exit_status;
}								t_shell;

typedef struct s_heredoc
{
	char						*helper;
	char						*line;
	int							num_brackets;
}								t_heredoc;

typedef struct s_num_malloc
{
	int							*com;
	int							*in;
	int							*out;
}								t_num_malloc;

// signals.c //

void							handle_sigint_main(int sig);
void							shell_signals(void);
void							heredoc_parent_signals(void);
void							execution_signals(void);

// child_signals.c //

void							heredoc_sigint_handler(int sig);
void							heredoc_child_signals(void);
void							child_execution_signals(void);

// ex_child.c //

void							free_args(char **args);
char							*find_path_index(t_env *envp);
char							*find_path_access(char **all_path, char **cmd);
void							execute_command(char **cmd, t_shell *shell);

// token.c //

int								process_outside_quotes(t_token_data *data,
									char *rl);
int								handle_quotes(t_token_data *data,
									t_quote_tracker *qt);
void							token(char *rl, t_shell *shell);

//  shell.c //

t_shell							*shell_init(char **envp);
void							cleanup_shell(t_shell **shell);

//	execution.c //

int								execution(char *str, t_token **token,
									int size_token, t_shell *shell);
void							free_comand(t_comand_data *comand,
									int num_comands);

//  token_utils.c //

int								ft_isspace(char c);
void							token_operator(t_token *token, char c,
									char next);
void							init_token(t_token *token, int size,
									int num_quotes);
void							free_token(t_token **token, int size);
int								init_all(t_token_data *data, char *rl);

//  token_utils_2.c //

int								count_comands(t_token *token, int size_token);
void							init_others(t_comand_data *comand, int j,
									int size);
void							init_comand(t_comand_data *comand, int size);
void							in_out_file(char **file, char *str);
char							*init_str(char *c, t_token *token, int i,
									int size_token);

//  token_utils_3.c //

void							init_int_out(t_comand_data *comand, int size_in,
									int size_out);
int								check_in_out(int size_token, t_token *token);
void							in_out_size(t_comand_data *comand, t_ind ind,
									int size_token, t_token *token);
// int		chek_token(t_token *token);
int								chek_double(char a, char b, int *i);

//  token_utils_4.c //

void							free_t(char *str, t_token **token, int size);
void							init_quote_tracker(t_quote_tracker *qt);
int								finalize_token(t_token_data *data);
void							process_token_loop(t_token_data *data,
									t_quote_tracker *qt, char *rl);
void							handle_final_token(t_token_data *data,
									t_shell *shell);

//  token_utils_5.c //

void							start_quote(t_token_data *data,
									t_quote_tracker *qt, t_token *curr_token);
void							end_quote(t_token_data *data,
									t_quote_tracker *qt, t_token *curr_token);
int								check_unclosed_quotes(t_token_data *data,
									int token_count);
char							*ft_strjoin_free(char *s1, char *s2);
int								is_in_single_quote(int i, t_quotes *quotes);

//  token_utils_6.c //

int								count_quotes(char *str, int i, int q,
									int in_quote);
void							copy_quotes(t_quotes *dst, t_quotes *src,
									int count);
void							alloc_and_copy1(t_comand_data *cmd,
									t_token *token, t_ind *ind, int k);
void							register_unclosed_quote(t_token_data *data,
									t_quote_tracker *qt);

// count_tokens.c //

int								count_tokens(char *rl);

// prepare_to_execute.c //

int								prepare_to_execute(t_comand_data **comand,
									t_token *token, int size_token);

// the_files.c //

int								the_files(t_ind *ind, int size_token,
									t_token *token, t_comand_data **comand);

// execute_pipeline.c //

void							execute_pipeline(t_comand_data *cmd,
									int cmd_count, t_shell *shell);

// Aux functions that can be on another .c

char							*return_error_child(char *cmd);
void							handle_pipe(int pipefd[2]);
void							handle_fork(pid_t *pid);
void							set_exit_status(t_shell *shell, int status);
int								check_single_builtin(t_comand_data *cmd,
									int cmd_count, t_shell *shell);
void							free_heredoc_fail(pid_t *pids, t_shell *shell);
void							start_fork(t_fork_data *data,
									t_comand_data *cmd, t_shell *shell,
									pid_t *pids);
void							wait_children(pid_t *pids, int cmd_count,
									t_shell *shell);
void							if_pid_0(t_fork_data *data, t_comand_data *cmd);
void							else_pid_0(int *prev_fd, int *pipefd, int i,
									int cmd_count);

// handle_redirections.c //

int								handle_redirections(t_comand_data *cmd);

// handle_redirections_utils.c //

int								out_red(char *file);
int								append(char *file);
int								in_red(char *file);

// expansion_var.c //

void							expancion_var(t_comand_data *cmd,
									t_shell *shell);

// expansion_var_utils.c //

void							index_value(t_quotes *quote, t_expan *ex);

// cd.c //

void							ft_cd(t_shell *shell, char *dest);

// cd_utils.c //

char							*get_oldpwd(t_shell *shell);
void							update_oldpwd_env(t_shell *shell, \
									char *old_path);
char							*go_home(t_shell *shell);

// echo.c //

void							ft_echo(t_shell *shell, char **cmd);

// pwd.c //

void							ft_pwd(t_shell *shell);

// export_utils.c //

t_env							*env_lstnew(char *name, char *val);
t_env							*env_lstlast(t_env *env);
void							env_lstadd_back(t_env **env, t_env *newenv);
char							**free_split(char **result, size_t i);
t_env							*create_env_list(char **envp);

// export_utils2.c //

int								update_or_create_var(t_env **envlist,
									char *name, char *value);
t_env							*create_basic_env(void);
t_env							*find_env_var(t_env *envlist, char *name);
int								count_env_nodes(t_env *envlist);
void							clear_env_list(t_env **envlist);

// export_utils3.c

int								handle_no_val_export(t_shell *shell, char *arg);

// export.c //

void							swap_env_content(t_env *a, t_env *b);
void							sort_env_list(t_env *envlist);
int								process_export(char *arg, char ***splitd,
									t_env *env_var, int is_env);
int								ft_export(t_shell *shell, char **args);

// utils.c //

int								is_valid_name(char *name);
int								is_valid_number(char *str);
char							*ft_strstr(const char *haystack,
									const char *needle);
char							**list_to_matrix(t_env *env);
int								malloc_test(void *str);

// the_files_utils.c //

void							process_output_redirection(t_comand_data *cmd,
									t_token *tk, int *idx, char *str);
void							process_input_redirection(t_comand_data *cmd,
									t_token *tk, int *idx, char *str);

// env.c //

t_env							*clone_env_list(t_env *envlist);
void							ft_show_env(t_env *envlist, int is_env);
void							ft_env(t_shell *shell, char **args);

// split_first.c //

void							*ft_free(char **strings, int count);
char							**split_first(char const *s, char c);

// unset.c //

int								ft_unset(t_env **envlist, char **names);

// exit.c //

void							ft_exit_no_print(t_shell **shell,
									int exit_code);
void							ft_exit_no_full_init(t_shell **shell,
									int exit_code);
void							ft_exit(t_shell **shell, int exit_code);

// heredoc.c //

t_list							*handle_heredoc(char *delimiter,
									t_shell **shell, int expand);
t_list							*ft_heredoc(char **input, int brackets,
									t_shell **shell, int expand);

// heredoc_helper.c //

t_list							*ft_hdc_helper(char **split, int brackets,
									t_shell **shell, int expand);

// heredoc_utils.c //

char							*ft_replace(const char *str);
void							clean_heredoc(t_heredoc *vars);

// heredoc_utils2.c //

int								child_heredoc(t_shell *shell, char *delimiter,
									int pipe_fd, int expand);
int								process_line(t_shell **shell, char *line,
									char *delimiter, int pipe_fd);
void							sigint_handler(int sig);

// heredoc_utils3.c //

char							*read_line_pipe(int fd);
t_list							*read_heredoc_pipe(int fd);
t_list							*parent_process_heredoc(int pipe_fd[2],
									pid_t pid, t_shell **shell);

// heredoc_utils4.c //

int								init_all_heredocs(t_comand_data *cmd,
									int cmd_count, t_shell **shell);

// heredoc_utils4helper.c //

int								open_hd_pipe(char *delimiter, t_shell **shell,
									int expand);
int								count_heredocs(char **in_file, int in_count);
void							cleanup_heredocs(t_comand_data *cmd,
									int cmd_count);

// heredoc_expansion.c //

char							*heredoc_expansion(char *str, t_shell **shell);
char							*ft_strjoin_doblefree(char *s1, char *s2);

// builtins.c //

int								builtins(t_shell *shell, char **cmd);

// ft_putmult_fd.c //

void							multend_fd(char *s1, char *s2, char *s3,
									int fd);
void							mult_fd(char *s1, char *s2, char *s3, int fd);

// errors.c //

void							printerror(char *err_type, char *name);
void							control_d_error(char *delimiter);
void							print_comands(t_comand_data *comand,
									int num_comands);
void							print_token_array(t_token *tokens, int size);

#endif
