#pragma once
#include"Chracter.h"
#include"SDL.h"
#include<string>
using namespace std;

class Word
{
private:
	Character* chars;
	int word_size;
	float starting;
public:
	Word();
	Word(LTexture* font_image, float x, float y, string text);
	~Word();
	void Render(SDL_Renderer* gRenderer);
};

