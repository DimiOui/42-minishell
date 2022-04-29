# Minishell

**Minishell project done with [Jeremy](https://github.com/thePush/).**

## Mindmap
click image for a much better resolution.
<img src="https://user-images.githubusercontent.com/72572726/165954653-bf3cff78-a225-402e-9837-51a58132dd87.png" width="2000"  height="1000">
## Execution
Run
```
valgrind --suppressions=ignoreleak --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --verbose ./minishell
```
with the ignoreleak file in root folder to avoid readline and addhistory leaks.

## Features
![image](https://user-images.githubusercontent.com/72572726/165951390-b2748103-1933-4bbb-893d-a392f78cf6c9.png)

## Other features
-	echo $USE/////R                                  [OK]
-	SHLVL = 999 to SHLVL = 1                         [OK]
-	echo -nnnnnnnnnnnnnnnnnnnnnnnnn hi               [OK]
-	unset/export 1+++a==--                           [OK]
-	export a+=b                                      [OK]
-	echo l$USER/R                                    [OK]
