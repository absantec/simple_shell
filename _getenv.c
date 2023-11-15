#include "shell.h"
/**
 * getallenv - get all the environment
 * Return: environment
 *
 */
char **getallenv()
{
	char **environ = *(getenviron());
	char **envcopy;
	size_t len = 0;

	envcopy = environ;
	while (envcopy[len] != NULL)
		len++;
#ifdef DEBUGMODE
	printf("Got length of env lines %d\nNow copying\n", len);
#endif
	envcopy = malloc(sizeof(char **) * (len + 1));
	if (envcopy == NULL)
		return (NULL);
	while (len > 0)
	{
		envcopy[len] = environ[len];
		len--;
	}
	envcopy[len] = environ[len];
	return (envcopy);
}
/**
 * setallenv - this set whole environment for new value
 * @envin: the environment
 * @newval: new value to be added
 * Return: 0 if success, -1 if failed
 */
/* add should be null for first init to not free passed array */
int setallenv(char **envin, char *newval)
{
	char ***environ = getenviron();
	size_t len = 0;

#ifdef DEBUGMODE
	printf("In setallenv, newval:%s\n", newval);
#endif
	while (envin[len] != NULL)
		len++;
	if (newval != NULL)
		len++;
	*environ = malloc(sizeof(char **) * (len + 1));
	if (*environ == NULL)
		return (-1);
	for (len = 0; envin[len] != NULL; len++)
		if (newval == NULL)
		{
			(*environ)[len] = _strdup(envin[len]);
		}
		else
			(*environ)[len] = envin[len];
	if (newval != NULL)
	{
#ifdef DEBUGMODE
		printf("Adding newval:%s\n", newval);
#endif
		(*environ)[len] = newval;
		len++;
	}
	(*environ)[len] = NULL;
#ifdef DEBUGMODE
	printf("At end. Free old environ if adding a string\n");
#endif
	if (newval != NULL)
		free(envin);
	return (0);
}
/**
 * _getenv - get local a environment
 * @name: the environment variable
 * Return: the string of local environment
 */
char *_getenv(char *name)
{
	char **environ = *(getenviron());
	int i, j;
	char *s;

#ifdef DEBUGMODE
	printf("In getenv, name:%s\n", name);
#endif
	i = 0;
	while (environ[i] != NULL)
	{
		s = environ[i];
		j = 0;
#ifdef DEBUGSVARS
		printf("Checking against:%s\n", environ[i]);
#endif
		while (s[j] == name[j])
		{
			j++;
			if (name[j] == 0 && s[j] == '=')
				return (_strdup(s + j + 1));
		}
		i++;
	}
	return (name);
}
/**
 * _setenv - this set environment for new value
 * @name: the name of variable
 * @val: the value of variable
 * Return: 0 or setallenv if success, -1 if failed
 */
int _setenv(char *name, char *val)
{
	char ***environroot = getenviron();
	char **environ = *environroot;
	int i, j, namel, vall;
	char *s, *ptr;

#ifdef DEBUGMODE
	printf("In setenv, name:%s:val:%s\n", name, val);
#endif
	if (name == NULL || val == NULL)
		return (0);
	namel = _strlen(name);
	vall = _strlen(val);
	ptr = malloc(sizeof(char) * (namel + vall + 2));
	if (ptr == NULL)
		return (-1);
	s = ptr;
	_strcpy(s, name);
	s += namel;
	_strcpy(s++, "=");
	_strcpy(s, val);
	s += vall;
	*s = 0;
#ifdef DEBUGMODE
	printf("Ptr mallocd:%s\n", ptr);
#endif
	i = 0;
	while (environ[i] != NULL)
	{
		s = environ[i];
		j = 0;
		while (s[j] == name[j])
		{
			j++;
			if (name[j] == 0 && s[j] == '=')
			{
				free(environ[i]);
				environ[i] = ptr;
				return (0);
			}
		}
		i++;
	}
	return (setallenv(*environroot, ptr));
}
/**
 * _unsetenv - unset environment
 * @name: name of variable to unset
 * Return: 0 if success
 *
 * testing functionality  copy environ, if hits skip over, realloc
 */
int _unsetenv(char *name)
{
	char **environ = *getenviron();
	int a, b;
	int check = 0;
	char *s;
	char **env;

#ifdef DEBUGMODE
	printf("In unsetenv, name:%s\n", name);
#endif
	if (name == NULL)
		return (0);

	a = 0;
	while (environ[a] != NULL)
	{
		s = environ[a];
		b = 0;
		while (s[b] == name[b])
		{
			b++;
			if (s[b] == '=' && name[b] == '\0')
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
			break;
		a++;
	}
	free(environ[a]);
	while (environ[a] != NULL)
	{
		environ[a] = environ[a + 1];
		a++;
	}
	environ[a] = NULL;
	env = environ;
	setallenv(env, NULL);
	a = 0;
	while (env[a])
	{
		free(env[a]);
		a++;
	}
	free(env);
	return (0);
}
