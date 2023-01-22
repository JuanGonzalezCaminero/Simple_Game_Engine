//
// Created by Juan on 20/06/2022.
//

#include <gtest/gtest.h>
#include "GameObject.h"

class ConcreteGameObject : public GameObject {
    public:
        ConcreteGameObject(int x, int y, int width, int height) : GameObject(x, y, width, height) {};
        void update(std::chrono::duration<double> delta) override {}
        void render() override {}
};

class TestGameObject : public ::testing::Test {
protected:
    void SetUp() override {
        game_object = new ConcreteGameObject(0, 0, 0, 0);
    }
    GameObject *game_object;
};

TEST(TestGameObject, Creation) {
    GameObject *game_object;
    EXPECT_NO_THROW(game_object = new ConcreteGameObject(0, 0, 0, 0));
}

TEST_F(TestGameObject, SetInput) {
    //InputComponent input_component();
    //game_object->add_input(&input_component);
    EXPECT_NO_THROW(game_object = new ConcreteGameObject(0, 0, 0, 0));
}


















