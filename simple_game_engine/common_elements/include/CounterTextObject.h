//
// Created by Juan on 05/09/2021.
//

#ifndef SDL_INPUTHANDLING_COUNTERTEXTOBJECT_H
#define SDL_INPUTHANDLING_COUNTERTEXTOBJECT_H

#include "TextObject.h"
#include "iostream"

template<class N>
class CounterTextObject : public TextObject{
    private:
        N number;
    public:
        CounterTextObject(int x, int y, int height, int width, struct UnitType unit_type, N number, TTF_Font *font,
                          SDL_Color *textColor, SDL_Renderer *renderer, bool adapt_to_text) :
                TextObject(x, y, width, height, unit_type, std::to_string(number),
                           font, textColor, renderer, adapt_to_text), number(number){};
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
