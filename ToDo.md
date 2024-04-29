To implement:

1)  
Adjust col height in calculate_col_height() in world_calculate.c

2)  
Fix info on which side of the wall is visible

3)  
Use buffer image when drawing world

4)  
Check for memleaks with 'top' cmd in second shell terminal

5)  
Fix aspect ratio 1280 vs 1170

--------------


Bug:

1)  
undefined-behavior quand premier chiffre de RGB dans le fichier cub est grand

2)  
Fix check if map enclosed


--------------

Crash:

1)  
Quand pas de joueur dans la carte (pas de symbole: N S E W)

2)  
Quand une ligne de la carte se termine par un espace