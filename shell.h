extern char **environ;

/* Shell functions */
char *read_line(void);
char **split_line(char *line);
int execute(char **args, char **env);
char *find_path(char *command, char **env);
void print_env(void);
void print_error(char *command);
int change_dir(char **args);
void handle_signal(int sig);

/* String utils */
int _strlen(const char *s);
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
int _strcmpi(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);

/* Memory management */
void free_args(char **args);

#endif /* SHELL_H */
