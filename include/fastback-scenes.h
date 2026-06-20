/* fastback
 * escrito por juligar en vim btw */

// definiendo funciones para dibujar las escenas
void RenderScene1(FastbackTool* tool, Texture2D* textures, Button* buttons) {
	// dibujando sprites animados
	if (tool->timer >= 0.5) {
		DrawTextureEx(buttons[0].textures[1], (Vector2){buttons[0].dimensions.x,
		buttons[0].dimensions.y}, buttons[0].rotation, buttons[0].scale, WHITE);
		DrawTextureEx(buttons[1].textures[1], (Vector2){buttons[1].dimensions.x,
		buttons[1].dimensions.y}, buttons[1].rotation, buttons[1].scale, WHITE);
		DrawTexture(textures[1], 70, 40, WHITE);
	}
	else {
		DrawTextureEx(buttons[0].textures[0], (Vector2){buttons[0].dimensions.x,
		buttons[0].dimensions.y}, buttons[0].rotation, buttons[0].scale, WHITE);
		DrawTextureEx(buttons[1].textures[0], (Vector2){buttons[1].dimensions.x,
		buttons[1].dimensions.y}, buttons[1].rotation, buttons[1].scale, WHITE);
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
		DrawTexture(textures[0], 12, 245, WHITE);
		switch (tool->misccounter) {
			case 0:
				DrawTexture(textures[2], 65, 350, WHITE);
				DrawTexture(textures[4], 200, 350, WHITE);
			break;
			case 1:
				DrawTexture(textures[6], 65, 350, WHITE);
				DrawTexture(textures[8], 240, 395, WHITE);
			break;
			case 2:
				DrawTexture(textures[10], 65, 355, WHITE);
				DrawTexture(textures[12], 185, 380, WHITE);
			break;
		}
	}
	else {
		DrawTexture(textures[1], 12, 245, WHITE);
		switch (tool->misccounter) {
			case 0:
				DrawTexture(textures[3], 65, 350, WHITE);
				DrawTexture(textures[5], 200, 350, WHITE);
			break;
			case 1:
				DrawTexture(textures[7], 65, 350, WHITE);
				DrawTexture(textures[9], 240, 395, WHITE);
			break;
			case 2:
				DrawTexture(textures[11], 65, 355, WHITE);
				DrawTexture(textures[13], 185, 380, WHITE);
			break;
		}
	}
	if (IsKeyPressed(KEY_SPACE)) {
		tool->misccounter += 1;
		if (tool->misccounter >= 3) {
			tool->scene = 5;
			tool->nextscene = 6;
		}
	}
}
void RenderScene3(FastbackTool* tool, Texture2D textures[], Player* player) {
	BeginMode2D((Camera2D){{208, 203}, {player->dimensions.x, player->dimensions.y}, 0, 1});
	// dibujando lo incluido en camara
	if (tool->timer >= 0.5) {
		DrawTextureEx(textures[1], (Vector2){-208, -203}, 0, 2, WHITE);
		DrawTextureEx(player->textures[1], (Vector2){player->dimensions.x,
		player->dimensions.y}, player->rotation, player->scale, WHITE);
	}
	else {
		DrawTextureEx(textures[0], (Vector2){-208, -203}, 0, 2, WHITE);
		DrawTextureEx(player->textures[0], (Vector2){player->dimensions.x,
		player->dimensions.y}, player->rotation, player->scale, WHITE);

	}
	EndMode2D();
	// dibujando lo no incluido en camara
	if (tool->timer >= 0.5) {
		DrawTexture(textures[3], 290, 330, WHITE);
	}
	else {
		DrawTexture(textures[2], 290, 330, WHITE);
	}
	// definiendo movimiento del jugador
	player->direction = (Vector2){0, 0};
	if (IsKeyDown(KEY_W)) {
		player->direction.y -= 1;
	}
	if (IsKeyDown(KEY_D)) {
		player->direction.x += 1;
	}
	if (IsKeyDown(KEY_S)) {
		player->direction.y += 1;
	}
	if (IsKeyDown(KEY_A)) {
		player->direction.x -= 1;
	}
	if (Vector2Length(player->direction) > 0) {
		player->direction = Vector2Normalize(player->direction);
	}
	if (player->direction.x != 0) {
		player->speed.x += player->direction.x * 300 * GetFrameTime();
		if (player->speed.x > 300) {
			player->speed.x = 300;
		}
		if (player->speed.x < -300) {
			player->speed.x = -300;
		}
	}
	else {
		if (player->speed.x > 0) {
			player->speed.x -= 300 * GetFrameTime();
			if (player->speed.x < 0) {
				player->speed.x = 0;
			}
		}
		else if (player->speed.x < 0) {
			player->speed.x += 300 * GetFrameTime();
			if (player->speed.x > 0) {
				player->speed.x = 0;
			}
		}
	}
	if (player->direction.y != 0) {
		player->speed.y += player->direction.y * 300 * GetFrameTime();
		if (player->speed.y > 300) {
			player->speed.y = 300;
		}
		if (player->speed.y < -300) {
			player->speed.y = -300;
		}
	}
	else {
		if (player->speed.y > 0) {
			player->speed.y -= 300 * GetFrameTime();
			if (player->speed.y < 0) {
				player->speed.y = 0;
			}
		}
		else if (player->speed.y < 0) {
			player->speed.y += 300 * GetFrameTime();
			if (player->speed.y > 0) {
				player->speed.y = 0;
			}
		}
	}
	player->dimensions.y += player->speed.y * GetFrameTime();
	player->dimensions.x += player->speed.x * GetFrameTime();
	// saliendo
	if (IsKeyPressed(KEY_SPACE)) {
		tool->scene = 8;
		tool->nextscene = 0;
	}
}
