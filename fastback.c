/* fastback
 * escrito por juligar en vim btw */
#include <raylib.h>
#include <fastback.h>

void main(void) {
	FastbackTool tool = CreateFastbackTool(0, 0, 0);
	InitWindow(500, 500, "fastback");
	while (!WindowShouldClose() && tool.scene < 3) {
		BeginDrawing();
		ClearBackground(WHITE);
		switch (tool.scene) {
			case 0:
				tool.texturesNu = 2;
				Texture2D* textures = MemAlloc(sizeof(Texture2D) * tool.texturesNu);
				LoadTextures(&tool, (const char*[]){"resources/sprites/title/title-1.png", "resources/sprites/title/title-2.png"}, textures);
			break;
			case 1:
				RenderScene1(&tool, textures);
			break;
			case 2:
				UnloadTextures(&tool, textures);
				MemFree(textures);
			break;
		}
		EndDrawing();
	}
	CloseWindow();
}
