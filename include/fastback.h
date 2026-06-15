/* fastback
 * escrito por juligar en vim btw */

// definiendo structs para no complicarme la vida

// struct para encapsular herramientas útiles
typedef struct {
	int scene;
	int texturesNu;
	double timer;
} FastbackTool;

// definiendo funciones para no complicarme la vida

// función para crear una colección de herramientas útiles
FastbackTool CreateFastbackTool(int scene, int texturesNu, double timer) {
	FastbackTool tool;
	tool.scene = scene;
	tool.texturesNu = texturesNu;
	tool.timer = timer;
	return tool;
}
// función para cargar texturas y regresar un array de las mismas
void LoadTextures(FastbackTool* tool, const char* texturespath[], Texture2D* textures) {
	for (int i = 0; i < tool->texturesNu; i++) {
		textures[i] = LoadTexture(texturespath[i]);
	}
	tool->scene = 1;
}
// función para descargar texturas
void UnloadTextures(FastbackTool* tool, Texture2D* textures) {
	for (int i = 0; i < tool->texturesNu; i++) {
		UnloadTexture(textures[i]);
	}
	tool->scene = 3;
}

// definiendo funciones para dibujar las escenas
void RenderScene1(FastbackTool* tool, Texture2D* textures) {
	DrawTexture(textures[0], 0, 0, WHITE);
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		tool->scene = 3;
	}
}
