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
				Button* buttons = MemAlloc(sizeof(Button) * tool.buttonsNu);
				if (buttons == NULL) {
					return 1;
				}
				tool.buttonsNu = 1;
				LoadButtons(&tool, (Rectangle[]){{0.0, 0.0, 360, 100}}, (const char*[]){"resources/sprites/title/title-1.png",
				"resources/sprites/title/title-2.png"}, buttons);
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
		if (tool.timer >= 1) {
			tool.timer = 0;
		}
		else {
			tool.timer += GetFrameTime();
		}
	}

	CloseWindow();
	return 0;
}
