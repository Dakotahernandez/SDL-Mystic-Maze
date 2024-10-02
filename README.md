# SDL-Mystic-Maze

## Textures:
1. Draw whatever you want here, 25x25 works best:
   [Draw on Pixilart](https://www.pixilart.com/draw)
2. If you need to resize it, do that here:
   [Resize Pixel](https://www.resizepixel.com/)
3. Lastly, convert it to a text file of RGB values using this (RTF):
   [Convert PNG to RGB](https://onlinepngtools.com/convert-png-to-rgb-values)

## Naming Conventions:
- **Constants** are all uppercase, e.g., `THIS_IS_CONSTANT`.
- **Classes** are capitalized, e.g., `class Object {};`.
- **Components** are lowercase, e.g., `int number;`.
- **Pointers** passed around have `_ptr` at the end for clarity.
- **Immutable variables** should be marked `const` just in case.
- **typedef** belongs in CONSTANTS.h

## Display Rules:
- Characters and entities are displayed **on top of** empty containers. This will make adding cosmetics later easier.
- The `Maze` object is a `char**`, which is just a visual representation of a 2D array of containers.

## Stuff to Do:
(Delete if it's already done)
- Font and menu (Briel)
- Character Object Implementation & collision checking (currently Jonathan and Cam)
- Textures (Jonathan)
- Storyline/Script (Griffin)
- Interactive objects in the maze (BEN)
- Remove color parameters from emptycontainer draw() and make it match other draw functions
- Add sound effects including 1) Menu Music 2) Individual Maze music 3) Collision sounds 4) Interaction sounds both with menu and objects.
- Add unique maze puzzels including manipulating environment (REQUIREMENT)
- Unique environment objects per maze (REQUIREMENT)

## Current Maze Hierarchy:
- `Maze` (char**)
- `Container` (pure Abstract)
- `EmptyContainer` (occupied = false)
- `Wall` (occupied = true)
- `DesertWall` (overrides Draw())

Other mazes like `DesertMaze` override `Maze` but have the same core functionality.

## CITATIONS:
- Mouse click sound: created by Cameron Hardin
- Game soundtrack: sourced from ""
  
- Forest Textures
   - Background: https://www.freepik.com/free-ai-image/8-bit-graphics-pixels-scene-with-forest_137496531.htm#fromView=search&page=1&position=15&uuid=8aa93a6c-4f80-41fd-a3a6-a62c197b9559">Image by freepik</a>
   - EmptyContainer: https://www.freepik.com/free-vector/green-background-         
design_1148336.htm#query=light%20green%20texture&position=2&from_view=keyword&track=ais&uuid=18a18956-98c0-4602-b312-78b95d0c4fef
   - Wall: https://www.deviantart.com/cpthelios/art/Tree-Bark-Tiles-For-Wall-or-Background-          961974154
   - Enemy: https://pngtree.com/freepng/spider-silhouette_5731322.html

- Desert Textures
   - Background:  https://www.seaart.ai/explore/detail/80e49422d8bf95ae14aff69e02f99671
   - EmptyContainer: https://opengameart.org/content/sand-desert-dune-tile
   - Wall: https://pin.it/1vx21SM8d
   - Enemy: https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.freepik.com%2Fpremium-vector%2Fpixel-art-illustration-crab-pixelated-sea-crab-sea-crab-pixelated-game_80978293.htm&psig=AOvVaw3fKtZpVWByW-Y6hjFi6KMl&ust=1714249274663000&source=images&cd=vfe&opi=89978449&ved=0CBQQjhxqFwoTCJi_5Kza4IUDFQAAAAAdAAAAABAE

- Underwater Textures
   - Background:https://www.google.com/url?sa=i&url=https%3A%2F%2Fplayground.com%2Fsearch%3Fq%3DTiny%2Bunderwater%2Bcomplete&psig=AOvVaw3HvoQb6IdR4dK55eazktwT&ust=1714093341850000&source=images&cd=vfe&opi=89978449&ved=0CBQQjhxqFwoTCPj34biV3IUDFQAAAAAdAAAAABAm
   - EmptyContainer:https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.reddit.com%2Fr%2FPixelArt%2Fcomments%2F91bpxj%2Fccbasic_water_texture_32x32%2F&psig=AOvVaw3_KPYGQ5S33HrNzz2J6bEH&ust=1714094257418000&source=images&cd=vfe&opi=89978449&ved=0CBQQjhxqFwoTCIilg_yY3IUDFQAAAAAdAAAAABA7
   - Wall:  https://www.freepik.com/free-vector/realistic-sea-sand-wave-background_13153629.htm#from_view=detail_alsolike">Image by macrovector on Freepik</a> (Credits to macrovector)
   - Enemy: Drawn by Dakota Hernandez

- Miscellaneous Textures
   - Knight: https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.cleanpng.com%2Fpng-knight-pixel-art-cartoon-pixilart-knightpixelart-b-6249506%2F&psig=AOvVaw1_PADopRIDtF-7J1cSkozO&ust=1714095873622000&source=images&cd=vfe&opi=89978449&ved=0CBQQjhxqFwoTCODz4PKe3IUDFQAAAAAdAAAAABAK
   - Key: https://www.vecteezy.com/vector-art/10463909-pixel-old-key-for-games">pixel old key for games Vectors by Vecteezy
   - Forest Night Overlay: https://www.spoonflower.com/en/fabric/16028484-vintage-indigo-solid-color-dark-blue-gray-solid-colour-plain-dusty-blue-solid-by-stacywarddesign




