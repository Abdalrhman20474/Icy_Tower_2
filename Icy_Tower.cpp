#include <iostream>
#include<vector>
#include<fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"game.h"
using namespace std;
using namespace sf;
int main() {
	RenderWindow window(VideoMode(1800, 1100), "Game");
	game icy(4200, 2720);
	Texture bg;
	bg.loadFromFile("icy_tower.png");
	Sprite back_ground;
	back_ground.setTexture(bg);
	back_ground.setScale(2.3 , 1.9);
	back_ground.setPosition(Vector2f(0, 0));

	Texture p;
	p.loadFromFile("icy_tower_sheet.png");
	Sprite player;
	player.setTexture(p);
	player.setTextureRect(IntRect(0, 0, 42, 65));
	player.setPosition(500, 500);
	player.setScale(1.5, 1.5);
	Texture BG;
	BG.loadFromFile("icy_tower_background.png");
	Sprite bg2;
	bg2.setTexture(BG);
	bg2.setScale(2.3, 1.9);
	bool play = 0;
	int player_ctr = 3;

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed) {
				if (Keyboard::isKeyPressed(Keyboard::Up)) {
					icy.Move_up();
				}
			}
			if (event.type == Event::KeyPressed) {
				if (Keyboard::isKeyPressed(Keyboard::Down)) {
					icy.Move_down();
				}
			}
			if (event.type == Event::KeyPressed) {
				if (Keyboard::isKeyPressed(Keyboard::Enter) && icy.Selected() == 3) {
					window.close();
				}
			}
			if (event.type == Event::KeyPressed) {
				if (Keyboard::isKeyPressed(Keyboard::Enter) && icy.Selected() == 0) {
					play = true;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				player.move(1, 0);
				player.setTextureRect(IntRect(39*player_ctr, 0, 30, 65));
				player_ctr++;
				if (player_ctr % 6==0) {
					player_ctr = 3;
				}
				
			}
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				player.move(-1, 0);
				player.setTextureRect(IntRect(37 * player_ctr + 45, 0, -40, 65));
				player_ctr++;
				if (player_ctr % 6==0) {
					player_ctr = 3;
				}

			}

		}
		window.clear();
		if (play) {
			window.draw(bg2);
			window.draw(player);
		}
		else {
			window.draw(back_ground);
			icy.Draw(window);
		}
		//window.draw(back_ground);
		//icy.Draw(window);
		window.display();
		//icy.Draw(window);
	}
}

		


	
	
