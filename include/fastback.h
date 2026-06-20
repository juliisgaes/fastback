/* fastback
 * escrito por juligar en vim btw */

// definiendo structs para no complicarme la vida
// struct para encapsular herramientas útiles
typedef struct {
	int scene;
	int nextscene;
	int texturesNu;
	int buttonsNu;
	int misccounter;
	double timer;
} FastbackTool;
// struct para encapsular botones
typedef struct {
	Rectangle dimensions;
	Texture2D textures[2];
	float rotation;
	float scale;
} Button;
// struct para encapsular al jugador
typedef struct {
	Rectangle dimensions;
	Texture2D textures[2];
	float rotation;
	float scale;
	Vector2 speed;
	Vector2 direction;
} Player;
// definiendo funciones para no complicarme la vida
// funcion para encapsular un conjunto de herramientas
FastbackTool CreateFastbackTool(int scene, int nextscene, int texturesNu, int buttonsNu,
int misccounter, float timer) {
	FastbackTool tool;
	tool.scene = scene;
	tool.nextscene = nextscene;
	tool.texturesNu = texturesNu;
	tool.buttonsNu = buttonsNu;
	tool.misccounter = misccounter;
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
// función para cargar jugador
void LoadPlayer(Rectangle dimensions, const char* texturespath[],
float rotation, float scale, Vector2 speed, Vector2 direction,
Player* player) {
	// cargarndo dimensiones del botón
	player->dimensions = dimensions;
	player->rotation = rotation;
	player->scale = scale;
	player->speed = speed;
	player->direction = direction;
	for (int i = 0; i < 2; i++) {
		player->textures[i] = LoadTexture(texturespath[i]);
	}
}
// función para descargar jugador
void UnloadPlayer(Player* player) {
	for (int i = 0; i < 2; i++) {
		UnloadTexture(player->textures[i]);
	}
}
