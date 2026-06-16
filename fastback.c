/* fastback
 * escrito por juligar en vim btw */

#include <stdlib.h>
#include <raylib.h>
#include "include/fastback.h"

int main(void) {
	FastbackTool tool = CreateFastbackTool(0, 0, 0, 0);
	InitWindow(500, 500, "fastback");
	SetTargetFPS(60);
	while (!WindowShouldClose() && tool.scene < 3) {
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
				Texture2D* textures = MemAlloc(sizeof(Texture2D) * tool.texturesNu);
				if (textures == NULL) {
					return 1;
				}
				LoadTextures(&tool, (const char*[]){"resources/sprites/title/title-1.png",
				"resources/sprites/title/title-2.png"}, textures);
				tool.buttonsNu = 2;
				Button* buttons = MemAlloc(sizeof(Button) * tool.buttonsNu);
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
				tool.scene = 3;
			break;
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
