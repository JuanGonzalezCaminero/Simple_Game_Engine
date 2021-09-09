//
// Created by Juan on 16/08/2021.
//

#include "../include/GameEvent.h"

GameEvent::GameEvent(GameEventType type) {
    this -> type = type;
}

int GameEvent::get_x() const {
    return x;
}

void GameEvent::set_x(int x) {
    GameEvent::x = x;
}

int GameEvent::get_y() const {
    return y;
}

void GameEvent::set_y(int y) {
    GameEvent::y = y;
}

GameEvent::GameEvent() {}

GameEventType GameEvent::get_type() const {
    return type;
}

void GameEvent::set_type(GameEventType type) {
    GameEvent::type = type;
}
