	/* fastback
	 * escrito por juligar en vim btw */

	// definiendo structs para no complicarme la vida

	// struct para encapsular herramientas útiles
	typedef struct {
		int scene;
		int nextscene;
		int texturesNu;
		int buttonsNu;
		double timer;
	} FastbackTool;
	// struct para encapsular botones
	typedef struct {
		Rectangle dimensions;
		Texture2D textures[2];
		float rotation;
		float scale;
	} Button;

	// definiendo funciones para no complicarme la vida

	// función para crear una colección de herramientas útiles
	FastbackTool CreateFastbackTool(int scene, int nextscene, int texturesNu, int buttonsNu, double timer) {
		FastbackTool tool;
		tool.scene = scene;
		tool.nextscene = nextscene;
		tool.texturesNu = texturesNu;
		tool.buttonsNu = buttonsNu;
		tool.timer = timer;
		return tool;
	}
	// función para cargar texturas y regresar un array de las mismas
	void LoadTextures(FastbackTool* tool, const char* texturespath[], Texture2D* textures) {
		for (int i = 0; i < tool->texturesNu; i++) {
			textures[i] = LoadTexture(texturespath[i]);
		}
	}
	// función para descargar texturas
	void UnloadTextures(FastbackTool* tool, Texture2D* textures) {
		for (int i = 0; i < tool->texturesNu; i++) {
			UnloadTexture(textures[i]);
		}
	}
	// función para cargar botones y regresar un array de los mismos
	void LoadButtons(FastbackTool* tool, Rectangle dimensions[], const char* texturespath[],
	float rotation[], float scale[], Button* buttons) {
		// cargarndo dimensiones del botón
		for (int i = 0; i < tool->buttonsNu; i++) {
			buttons[i].dimensions = dimensions[i];
			buttons[i].rotation = rotation[i];
			buttons[i].scale = scale[i];
			for (int j = 0; j < 2; j++) {
				buttons[i].textures[j] = LoadTexture(texturespath[(i * 2) + j]);
			}
		}
	}
	// función para descargar botones
	void UnloadButtons(FastbackTool* tool, Button* buttons) {
		for (int i = 0; i < tool->buttonsNu; i++) {
			for (int j = 0; j < 2; j++) {
				UnloadTexture(buttons[i].textures[j]);
			}
		}
	}


	// definiendo funciones para dibujar las escenas
	void RenderScene1(FastbackTool* tool, Texture2D* textures, Button* buttons) {
		// dibujando sprites animados
		if (tool->timer >= 0.5) {
			DrawTextureEx(buttons[0].textures[1], (Vector2){buttons[0].dimensions.x,
			buttons[0].dimensions.y},
			buttons[0].rotation, buttons[0].scale, WHITE);
			DrawTextureEx(buttons[1].textures[1], (Vector2){buttons[1].dimensions.x,
			buttons[1].dimensions.y},
			buttons[1].rotation, buttons[1].scale, WHITE);
			DrawTexture(textures[1], 70, 40, WHITE);
		}
		else {
			DrawTextureEx(buttons[0].textures[0], (Vector2){buttons[0].dimensions.x,
			buttons[0].dimensions.y},
			buttons[0].rotation, buttons[0].scale, WHITE);
			DrawTextureEx(buttons[1].textures[0], (Vector2){buttons[1].dimensions.x,
			buttons[1].dimensions.y},
			buttons[1].rotation, buttons[1].scale, WHITE);
			DrawTexture(textures[0], 70, 40, WHITE);
		}
		// definiendo el comportamiento del botón jugar
		if (CheckCollisionPointRec(GetMousePosition(), buttons[0].dimensions)) {
			if (buttons[0].scale < 1.05) {
				buttons[0].scale += GetFrameTime();
				buttons[0].dimensions.x -= 173.25 * GetFrameTime();
				buttons[0].dimensions.y -= 63 * GetFrameTime();
			}
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				tool->scene = 2;
				tool->nextscene = 3;
			}
		}
		else {
			if (buttons[0].scale > 1) {
				buttons[0].scale -= GetFrameTime();
				buttons[0].dimensions.x += 173.25 * GetFrameTime();
				buttons[0].dimensions.y += 63 * GetFrameTime();
			}
		}
		// definiendo el comportamiento del botón salir
		if (CheckCollisionPointRec(GetMousePosition(), buttons[1].dimensions)) {
			if (buttons[1].scale < 1.05) {
				buttons[1].scale += GetFrameTime();
				buttons[1].dimensions.x -= 173.25 * GetFrameTime();
				buttons[1].dimensions.y -= 63 * GetFrameTime();
			}
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				tool->scene = 2;
				tool->nextscene = 7;
			}
		}
		else {
			if (buttons[1].scale > 1) {
				buttons[1].scale -= GetFrameTime();
				buttons[1].dimensions.x += 173.25 * GetFrameTime();
				buttons[1].dimensions.y += 63 * GetFrameTime();
			}
		}
	}
	void RenderScene2(FastbackTool* tool, Texture2D* textures) {
		if (tool->timer >= 0.5) {
		DrawTexture(textures[0], 0, 230, WHITE);
		DrawTexture(textures[2], 55, 340, WHITE);
		DrawTexture(textures[4], 195, 340, WHITE);
	}
	else {
		DrawTexture(textures[1], 0, 230, WHITE);
		DrawTexture(textures[3], 55, 340, WHITE);
		DrawTexture(textures[5], 195, 340, WHITE);
	}
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			tool->scene = 5;
			tool->nextscene = 7;
		}
}
