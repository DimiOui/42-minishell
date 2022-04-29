# Minishell

**Minishell project done with [Jeremy][https://github.com/thePush/].**

## Mindmap
![mind_map](https://user-images.githubusercontent.com/72572726/165236587-71f689d4-18a7-4286-a8f2-a02aed6792f1.png)


## Execution
Run
```
valgrind --suppressions=ignoreleak --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --verbose ./minishell
```
with the ignoreleak file in root folder to avoid readline and addhistory leaks.

## Features

======================== DONE =========================

-	echo $USE/////R (expand vars)                    [OK]
-	SHLVL = 999 to SHLVL = 1 (environnement handler) [OK]
-	echo -nnnnnnnnnnnnnnnnnnnnnnnnn lol (ft_echo)    [OK]
-	unset/export 1+++a==-- (builtins_env + libft)    [OK]
-	check relinking Makefile                         [OK]
-	export a+=b                                      [OK]
-	echo "$USER" (init_substr)                       [OK]
-	export $USER=xxx                                 [OK]
-	l$a                                              [OK]
-	echo l$USER/R      (expanders)                   [OK]
-	expand in heredoc                                [OK]
-	check all leaks (still reacheables)              [OK]
