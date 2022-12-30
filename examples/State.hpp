#pragma once
#include "flixel++/FlxState.hpp"
#include "flixel++/FlxSprite.hpp"
#include "flixel++/FlxSound.hpp"
#include "flixel++/FlxNet.hpp"
#include "flixel++/FlxG.hpp"
#include "flixel++/FlxText.hpp"
#include "flixel++/FlxMacros.hpp"

class PlayState : public Flx::State
{
    public:
    PlayState(){};
    ~PlayState(){};
    Flx::Sprite* sprite;
    float time = 0.0f;
    float offsetX = 0.0f, offsetY = 0.0f;
    void create(){
        sprite = new Flx::Sprite(0,0);
        sprite->loadGraphic("assets/logo.png");
        sprite->setGraphicSize(240,240);
        sprite->screenCenter();
        add(sprite);

        Flx::Text* text = new Flx::Text(0,100, "i am a piece of text!");
        text->screenCenter();
        text->setText("i am a piece of new text!");
        add(text);

    };
    virtual void update(){
        sprite->x += cos(time) + offsetX;
        sprite->y += sin(time) + offsetY;
        

        time += 0.05f;
        Flx::State::update();
    }
};