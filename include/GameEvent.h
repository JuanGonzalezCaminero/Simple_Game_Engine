//
// Created by Juan on 16/08/2021.
//

#ifndef SDL_INPUTHANDLING_GAMEEVENT_H
#define SDL_INPUTHANDLING_GAMEEVENT_H

#include "GameEventType.h"

class GameEvent {
    public:
        GameEvent(GameEventType type);
        GameEventType type;
};

#endif
