#include "gameplay/player.h"

Player::Player(const char* player_name, Vector2 position, int health){
    this->player_name = new char[sizeof(player_name)];
    this->position = position;
    this->health = health;
}

void Player::Draw(Texture2D *sprite_atlas, float x, float y){

}