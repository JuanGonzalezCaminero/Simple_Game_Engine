//
// Created by Juan on 10/09/2021.
//

#include "../../include/snake/ExitButtonInputComponent.h"
#include "GameObject.h"
#include "iostream"

ExitButtonInputComponent::ExitButtonInputComponent() : InputComponent() {}

int ExitButtonInputComponent::process(GameEvent e) {
    switch(e.get_type())
    {
        case(GameEventType::MouseMove):
            if(!mouse_over)
            {
                if(check_mouse_over(e.get_x(), e.get_y()))
                {
                    //Actions taken when the mouse enters the button area would go here
                    std::cout << "Mouse in!" << std::endl;
                }
            }
            else
            {
                if(!check_mouse_over(e.get_x(), e.get_y()))
                {
                    //Actions taken when the mouse exits the button area would go here
                    std::cout << "Mouse out!" << std::endl;
                }
            }

            //In this case I will not consume this event, so it will be passed to other components
            return 0;
        case(GameEventType::MouseLeftPressed):
            if(mouse_over)
            {
                std::cout << "Exit Button Clicked!" << std::endl;
            }
            return 1;
        default:
            break;
    }
    if(e.get_type() == GameEventType::MouseMove)
    {
        //std::cout << "Hey!" << std::endl;

    }


    return 0;
}
