/* fastback
 * escrito por juligar en vim btw */

#include <stdlib.h>
#include <raylib.h>
#include "include/fastback.h"

int main(void) {
	FastbackTool tool = CreateFastbackTool(0, 0, 0, 0, 0, 0);
	Texture2D* textures = NULL;
	Button* buttons = NULL;
	Player* player = NULL;
	InitWindow(500, 500, "fastback");
	SetTargetFPS(60);
	while (!WindowShouldClose() && tool.scene != 9) {
		// timer simple
		if (tool.timer >= 1) {
			tool.timer = 0;
		}
		else {
			tool.timer += GetFrameTime();
		}
		BeginDrawing();
		ClearBackground(WHITE);
		switch (tool.scene) {
			case 0:
				tool.texturesNu = 2;
				textures = MemAlloc(sizeof(Texture2D) * tool.texturesNu);
				if (textures == NULL) {
					return 1;
				}
				LoadTextures(&tool, (const char*[]){"resources/sprites/title/title-1.png",
				"resources/sprites/title/title-2.png"}, textures);
				tool.buttonsNu = 2;
				buttons = MemAlloc(sizeof(Button) * tool.buttonsNu);
				if (buttons == NULL) {
					return 1;
				}
				LoadButtons(&tool, (Rectangle[]){
				{85, 220, 330, 120}, {85, 340, 330, 120}
				}, (const char*[]){
				"resources/sprites/buttons/jugar-1.png", "resources/sprites/buttons/jugar-2.png",
				"resources/sprites/buttons/salir-1.png", "resources/sprites/buttons/salir-2.png"
				}, (float[]){0, 0}, (float[]){1, 1}, buttons);
				tool.scene = 1;
			break;
			case 1:
				RenderScene1(&tool, textures, buttons);
			break;
			case 2:
				UnloadTextures(&tool, textures);
				MemFree(textures);
				textures = NULL;
				UnloadButtons(&tool, buttons);
				MemFree(buttons);
				buttons = NULL;
				tool.scene = tool.nextscene;
			break;
			case 3:
				tool.texturesNu = 14;
				textures = MemAlloc(sizeof(Texture2D) * tool.texturesNu);
				if (textures == NULL) {
					return 1;
				}
				LoadTextures(&tool, (const char*[]){"resources/sprites/talk/talk-1.png",
				"resources/sprites/talk/talk-2.png", "resources/sprites/talk/player-sleep-1.png",
				"resources/sprites/talk/player-sleep-2.png", "resources/sprites/talk/text-1.png",
				"resources/sprites/talk/text-2.png", "resources/sprites/talk/player-awake-1.png",
				"resources/sprites/talk/player-awake-2.png", "resources/sprites/talk/text-3.png",
				"resources/sprites/talk/text-4.png", "resources/sprites/talk/player-talking-1.png",
				"resources/sprites/talk/player-talking-2.png", "resources/sprites/talk/text-5.png",
				"resources/sprites/talk/text-6.png"}, textures);
				tool.scene = 4;
			break;
			case 4:
				RenderScene2(&tool, textures);
			break;
			case 5:
				UnloadTextures(&tool, textures);
				MemFree(textures);
				textures = NULL;
				tool.scene = tool.nextscene;
			break;
			case 6:
				player = MemAlloc(sizeof(Player));
				LoadPlayer((Rectangle){0, 0, 0, 0}, (const char*[]){"resources/sprites/player/player-1.png",
				"resources/sprites/player/player-2.png"}, 0, 1, player);
				tool.scene = 7;
			break;
			case 7:
				RenderScene3(&tool, player);
			break;
			case 8:
				UnloadPlayer(player);
				MemFree(player);
				player = NULL;
				tool.scene = tool.nextscene;
			break;
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
