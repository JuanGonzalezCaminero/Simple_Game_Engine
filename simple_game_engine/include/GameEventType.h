//
// Created by Juan on 16/08/2021.
//

#ifndef SDL_INPUTHANDLING_GAMEEVENTTYPE_H
#define SDL_INPUTHANDLING_GAMEEVENTTYPE_H

enum class GameEventType {
    RightPressed,
    LeftPressed,
    DownPressed,
    UpPressed,
    RightReleased,
    LeftReleased,
    DownReleased,
    UpReleased,
    MouseLeftPressed,
    MouseMove,
    Pause,
    Unpause,
    Click,
    Quit
};

#endif

