#include "Word.h"

Word::Word()
{
	// initializing all the variables
	chars = NULL;
	word_size = 0;
	starting = 0;
}

Word::Word(LTexture* image, float x, float y, string text)
{

	word_size = text.length(); // calculating input string length
	chars = new Character[word_size]; // initiating array of word size

	if (word_size % 2 == 0)
	{
		starting = x;
		// storing character clip in array
		for (int i = 0; i < word_size; i++)
		{
			chars[i] = Character(image, starting + i * 44, y, text[i]);
			starting++;
		}
	}
	else
	{
		starting = x - 22; // for center allignment
		// storing character clip in array
		for (int i = 0; i < word_size; i++)
		{
			chars[i] = Character(image, starting + i * 44, y, text[i]);
			starting++;
		}
	}
}

Word::~Word()
{
	// deleting array of characters
	delete[] chars;
}
void Word::Render(SDL_Renderer* gRenderer)
{

	// drawing all the charaters in array
	for (int i = 0; i< word_size; i++)
	{
		chars[i].Render(gRenderer);
	}
}


