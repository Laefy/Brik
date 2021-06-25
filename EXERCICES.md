# Task 1

## Bonus / Malus

Add one or several of the following behaviors when clicking on a specific key:

1. Increase or reduce the speed of the slider (`+` and `-` keys).

2. Increase or reduce the speed of the ball (`L` and `O` keys).

3. Increase or reduce the length of the slider (`M` and `P` keys).
Make sure the expansion or reduction is made relative to the center of the slider.

4. Spawn another ball (`B` key).
Make sure the balls that go out of scope or removed from the program.

5. The ball destroys the briks on its passage, without bouncing on them (`A` to activate and deactivate).

6. The slider can go through the walls (`Q` to activate and deactivate).
For instance, if you reach the left side of the screen, the slider starts to reappear on the right side.

7. The slider catches the ball every time it arrives on it.
The ball is released only when the player hit the `Space` bar.

8. The ball is invisible and reappear shortly when its bounces on something (`*` to activate and deactivate).

## Brik types

Add a way to specify different types of briks in the `map.brik` file.
Briks of different types should appear in a different color in the game.

## Levels

Add new `.brik` files in the `assets/` folder, named `map1.brik`, `map2.brik`, etc.\
When a level is completed, reset the game with the `map(n+1).brik` files, or close the game if no more exist.\
If a level is lost, reset the game with the `map(n).brik` file.

---

# Task 2

## Score

Add a score to the game, that increases for every broken brik.
The more briks removed on a single shot, the higher the points increased.\
Find a nice font on the web and use the SFML to display that score in the top-right corner of the game.

## End-game screen

Add an end-game screen to the game, showing when you lost that you have lost, and when you won that you have won.\
That screen should allow you to restart the game or to close it.

## Workspace independance

Right now, in order to read the files inside the `assets/` folder, the game must necessarily be launched with the `Brik/` folder as current workspace.
Ensure that the game can be launched from everywhere.

---

# Task 3

## Window-scaling

The game window's width currently contain exactly 10 briks.\
Find a way to make the rendering adapt to the actual number of briks present in the `.brik` file. 

## Power-ups (Task1 dependant)

Adapt the architecture of the program so that the bonuses and maluses developped in the Task1 are triggered every time a brik of a specific type is broken.
