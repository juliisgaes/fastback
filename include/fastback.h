/* fastback
 * escrito por juligar en vim btw */

// definiendo structs para no complicarme la vida

// struct para encapsular herramientas útiles
typedef struct {
	int scene;
	int texturesNu;
	int buttonsNu;
	double timer;
} FastbackTool;
// struct para encapsular botones
typedef struct {
	Rectangle dimensions;
	Texture2D textures[2];
} Button;

// definiendo funciones para no complicarme la vida

// función para crear una colección de herramientas útiles
FastbackTool CreateFastbackTool(int scene, int texturesNu, int buttonsNu, double timer) {
	FastbackTool tool;
	tool.scene = scene;
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
void LoadButtons(FastbackTool* tool, Rectangle dimensions[], const char* texturespath[], Button* buttons) {
	// cargarndo dimensiones del botón
	for (int i = 0; i < tool->buttonsNu; i++) {
		buttons[i].dimensions = dimensions[i];
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
		DrawTexture(buttons[0].textures[1], buttons[0].dimensions.x, buttons[0].dimensions.y, WHITE);
//		DrawTexture(textures[1], 70, 20, WHITE);
	}
	else {
		DrawTexture(buttons[0].textures[0], buttons[0].dimensions.x, buttons[0].dimensions.y, WHITE);
//		DrawTexture(textures[0], 70, 20, WHITE);
	}
	// saliendo de la escena
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		tool->scene = 2;
	}
}
