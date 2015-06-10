You may only modify the Barbarian class in this source code.  
The map files are in  the bin\maps directory
map file 				properties file
map01.txt  				map01_properties.txt
map02.txt				map02_properties.txt
map03.txt				map03_properties.txt
map04.txt				map04_properties.txt
Example of map file:
8 8
0 0 0 0 2 0 0 0
0 0 0 0 0 0 0 0
0 0 1 0 0 0 4 0
0 0 0 0 0 0 0 0 
0 0 0 0 1 0 0 0
0 0 5 0 0 0 -1 0
0 0 -1 0 6 0 3 0
0 0 0 0 0 0 0 -1
-The first line contains the size of the map (in number of tiles) (x size , y size)
-The next lines are the data. Each map cell is a number 
-1  - Hole
0 	- Empty Tile
1	- Red Item
2	- Green Item
3	- Yellow Item
4	-Blue Item
5	-Monster
6	-Barbarian
Example of properties file:
Alina
Health 12
Mana	2
Armor 	4
Damage	1
Schanppi 
Health 50
Mana	10
Armor 	10
Damage	50

(it contains the start up information for Alina and Schanppi )

->You will be using a predefined platform so you can see your code in-game. The map loading code is already written (TileMapLoader/TileMap.cpp(h))
If  you want to load a particular map you need to go to the Main.cpp file and modify the ENGINE->LoadTileMap("maps/map03.txt"); line with your map name
If  you want to load a particular properties map you need to go to the TileMap.cpp file and modify the CreateSceneObjects()
line 155. (Example: LoadAttributesFromFile("maps/map01") loads the file map01_properties.txt).
->You have all the object types in ObjectTypes.h.
If you want to modify  the Barbarian you need to modify Barbarian.cpp(h) from the Barbarian filter. ( The update function is the most important, it already contains an example of linear interpolation between points).
You may modify the structure as you please, but it is encouraged that you focus on creating new functionalities for the task. 
If you want to move the camera:
W-forward
S-backward
A-left
D-right
R- up
F- down
(For mouse look-around keep the left button pressed)

Evaluation:
The most important factor in your evaluation is the way you write code and design your own structure. 
So you should focus on that. The solving algorithm is also important.
50% - code style
50% - algorithm


