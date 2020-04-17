#include "Button.h"

Button::Button()
{
	width = 0;
	height = 0;
	word_size = 0;
	button_length = 0;
	select = NULL;
	spriteSheetTexture = NULL;
}

Button::~Button()
{
	delete select;
}

Button::Button(LTexture* image, float x, float y, string word)
{
	spriteSheetTexture = image;

	// assigning picture clip for start button
	starting_button.w = 30;
	starting_button.h = 52;
	starting_button.x = 0;
	starting_button.y = 444;

	// assigning picture clip for button end
	end_button.w = 30;
	end_button.h = 52;
	end_button.x = 123;
	end_button.y = 444;

	// assigning picture clip for the center of button
	mid_button.w = 44;
	mid_button.h = 52;
	mid_button.x = 30;
	mid_button.y = 444;

	word_size = word.length();

	// settign the position
	this->height = mid_button.h;
	this->width = mid_button.w;
	this->pos.x = x;
	this->pos.y = y;


	// writing word on screen
	select = new Word(image, pos.x + starting_button.w, pos.y, word);
}

void Button::Render(SDL_Renderer* gRenderer)
{
	if (word_size % 2 == 0) // checking length of word to center allign the button
	{
		// drawing start of button
		spriteSheetTexture->Render(pos.x, pos.y-5, &starting_button, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		for (int i = 0; i < word_size; i++)
		{
			// drawing center of button according to the length of word
			spriteSheetTexture->Render((pos.x + starting_button.w) + i*width, pos.y-5, &mid_button, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		}
		// drawing end of button
		spriteSheetTexture->Render(pos.x + starting_button.w + (word_size*width), pos.y-5, &end_button, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		select->Render(gRenderer);
	}
	else
	{
		spriteSheetTexture->Render(pos.x - 22, pos.y-5, &starting_button, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		for (int i = 0; i < word_size; i++)
		{
			spriteSheetTexture->Render((pos.x + starting_button.w - 22 + (i*width)), pos.y-5, &mid_button, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		}
		spriteSheetTexture->Render(((pos.x - 22) + starting_button.w + (word_size*width)), pos.y-5, &end_button, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
		select->Render(gRenderer);
	}
}

int Button::get_length(string word)
{
	button_length = word.length() * 44 + 60;
	return button_length;
}
