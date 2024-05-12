To implement:

1)  
Empecher le joueur d'etre trop proche du mur. Ca cree des visuels bizarres si t'es sur le mur du bas et que tu regardes plein est ou ouest.

2) Refactor minimap_player.c or delete it and keep square player on minimap

--------------


Bug:

1) 
1111111111
1110000001
110000W001
1100000001
1111111111
                1
=> map should be invalid

2)  
Fix wrong color pixel color on wall corners (1 px colummn)

3)  
1px vertical line sometimes, see map small.cub

--------------

Crash:

1)  
==12582==ERROR: AddressSanitizer: SEGV on unknown address 0x000114efae04 (pc 0x0001071bdc5f bp 0x7ffee8a7de50 sp 0x7ffee8a7de50 T0)
==12582==The signal is caused by a WRITE memory access.
    #0 0x1071bdc5f in mlx_put_pixel+0xf (cub3D:x86_64+0x10003cc5f)
    #1 0x1071a7e49 in paint_column world_walls.c:32
    #2 0x1071a7722 in paint_walls world_walls.c:71
    #3 0x1071a4d74 in paint_world world.c:17
    #4 0x10718f550 in move_forward user_input_move.c:42
    #5 0x10718deb7 in player_input user_input.c:56
    #6 0x10718635f in render main.c:35
    #7 0x1071bdb65 in mlx_loop+0x125 (cub3D:x86_64+0x10003cb65)
    #8 0x10718630b in main main.c:58
    #9 0x7fff70e01cc8 in start+0x0 (libdyld.dylib:x86_64+0x1acc8)

==12582==Register values:
rax = 0x0000000114537800  rbx = 0x00007ffee8a7df00  rcx = 0x00000000ff663300  rdx = 0x0000000000270d81
rdi = 0x000060400008de10  rsi = 0x0000000000000001  rbp = 0x00007ffee8a7de50  rsp = 0x00007ffee8a7de50
 r8 = 0x000000000000005f   r9 = 0xffffe00022eb0434  r10 = 0x0000000000000060  r11 = 0x00001fffdd14fbdc
r12 = 0x00000001071d9798  r13 = 0x0000603000027010  r14 = 0x0000000000000001  r15 = 0x0000000000000000
AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV (cub3D:x86_64+0x10003cc5f) in mlx_put_pixel+0xf
==12582==ABORTING

