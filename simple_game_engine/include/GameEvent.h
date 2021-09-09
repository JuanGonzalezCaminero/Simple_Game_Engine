//
// Created by Juan on 16/08/2021.
//

#ifndef SDL_INPUTHANDLING_GAMEEVENT_H
#define SDL_INPUTHANDLING_GAMEEVENT_H

#include "GameEventType.h"

class GameEvent {
    private:
        int x;
        int y;
        GameEventType type;
    public:
        GameEvent();
        GameEvent(GameEventType type);

        int get_x() const;
        void set_x(int x);
        int get_y() const;
        void set_y(int y);
        GameEventType get_type() const;
        void set_type(GameEventType type);
};

#endif
