//
// Created by Juan on 05/09/2021.
//

#ifndef SDL_INPUTHANDLING_COUNTERTEXTOBJECT_H
#define SDL_INPUTHANDLING_COUNTERTEXTOBJECT_H

#include "TextObject.h"

template<class N>
class CounterTextObject : public TextObject{
    private:
        N number;
    public:
        CounterTextObject(int posX, int posY, int width, int height, N number, TTF_Font *font, SDL_Color *textColor,
                          SDL_Renderer *renderer, bool adapt_to_text) :
                          TextObject(posX, posY, width, height, std::to_string(number), font, textColor, renderer, adapt_to_text), number(number){};
        void add(N n) {
            number+=n;
            set_text(std::to_string(number));
        }
        void sub(N n) {
            number-=n;
            set_text(std::to_string(number));
        }
        void set_count(N n) {
            number=n;
            set_text(std::to_string(number));
        }
        N get_count() const {
            return number;
        }
};

#endif //SDL_INPUTHANDLING_COUNTERTEXTOBJECT_H
