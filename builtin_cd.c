#include "shell.h"

/**
* change_dir - Change the current directory
@args: Array of argument (args[1] is the target directory)
*
*Return: 0 on success, 1 on failure
*/
int change_dir(char **args);
{
  char	*dir =args[1];
  char	*home = getenv("HOME");
  char	*oldpwd = getenv("OLDPWD");
  char	cwd[BUFSIZ];

  if	(!dir || _strlen(dir, "~") == 0)
    {

        dir = home;
    }

  else if (_strlen(dir, "-") == 0)
  {
      dir = oldpwd;
      write(STDOUT_FILENO, dir, _strlen(dir));
      write(STDOUT_FILENO, "\n", 1);
  }

  if (!dir)
  {
    perror("cd");
    return 1;
  }

  if (getcwd(cwd, sizeof(cwd)) != NULL)
  {
    perror("getcwd");
    return 1;
  }

  if (chdir(dir) != 0)
  {
    perror("cd");
    return 1;

  }

  setenv("OLDPWD", cwd, 1);
  setenv("PWD", dir, 1);

  return 0;
}
