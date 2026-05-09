// #include "raylib.h"
// int main() {
//     InitWindow(800, 600, "Tile Map");
//     SetTargetFPS(60);
    
//     int map[5][5] = {
//         {1,1,1,1,1},
//         {1,0,0,0,1},
//         {1,0,1,0,1},
//         {1,0,0,0,1},
//         {1,1,1,1,1}
//     };

//     int tileSize = 32;

//     while (!WindowShouldClose()) {
//         BeginDrawing();
//         ClearBackground(BLACK);

//         for (int y = 0; y < 5; y++) {
//             for (int x = 0; x < 5; x++) {
//                 Color color = (map[y][x] == 1) ? GRAY : DARKGRAY;
//                 DrawRectangle(x * tileSize + 100, y * tileSize + 100, tileSize, tileSize, color);
//             }
//         }


//         // DrawText("Raylib works!", 300, 280, 20, BLACK);
//         EndDrawing();
//     }
    
//     CloseWindow();
//     return 0;
// }
