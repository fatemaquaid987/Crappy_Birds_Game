
#include"Chracter.h"
#include"Point.h"

Character::Character()
{
	starting = 0;
	spriteSheetTexture = NULL;
}

Character::Character(LTexture* image, float x, float y, int character)
{

	spriteSheetTexture = image;

	spriteClips.w = 44;
	spriteClips.h = 48;

	if (character == 32)// checking for the order of space
	{
		// assingning picture clip
		spriteClips.x = spriteClips.w * 5;
		spriteClips.y = spriteClips.h * 8;
	}
	else if ((character >= 48) && (character <= 57)) // checking for the order of numbers
	{
		starting = (character - 48);

		if (starting <= 2) // for line changing
		{
			// assinging picture clip '0 - 2'
			spriteClips.x = starting*spriteClips.w + (spriteClips.w * 8);
			spriteClips.y = spriteClips.h * 4;
		}
		else if (starting >= 3 && starting <= 10) // for line changing
		{
			// assinging picture clip '3 - 9'
			spriteClips.x = (starting - 3)*spriteClips.w;
			spriteClips.y = spriteClips.h * 5;
		}
	}
	else if ((character >= 65) && (character <= 90)) // checking for the order of capital letter
	{
		starting = (character - 65);

		if (starting <= 10) // for line changing
		{
			// assigning picture clip 'A - K'
			spriteClips.x = starting*spriteClips.w;
			spriteClips.y = 0;
		}
		else if ((starting >= 11) && (starting <= 21)) // for line changing
		{
			// assigning picture clip 'L - V'
			spriteClips.x = (starting - 11)*spriteClips.w;
			spriteClips.y = spriteClips.h;
		}
		else if ((starting >= 22) && (starting <= 26)) // for line changing
		{
			// assigning picture clip'W - Z'
			spriteClips.x = (starting - 22)*spriteClips.w;
			spriteClips.y = spriteClips.h * 2;
		}
	}
	else if ((character >= 97) && (character <= 122))// checking for the order of small letter
	{
		starting = (character - 97);

		if (starting <= 6) // for line changing
		{
			// assigning picture clip'a - g'
			spriteClips.x = starting*spriteClips.w + (spriteClips.w * 4);
			spriteClips.y = spriteClips.h * 2;
		}
		else if ((starting >= 7) && (starting <= 17)) // for line changing
		{
			// assinging picture clip 'h - r'
			spriteClips.x = (starting - 7)*spriteClips.w;
			spriteClips.y = spriteClips.h * 3;
		}
		else if ((starting >= 18) && (starting <= 26)) // for line changing
		{
			// assinging picute clip 's - z'
			spriteClips.x = (starting - 18)*spriteClips.w;
			spriteClips.y = spriteClips.h * 4;
		}
	}

	this->pos.x = x;
	this->pos.y = y;
}

Character::~Character()
{
	spriteSheetTexture = NULL;
}

void Character::Render(SDL_Renderer* gRenderer)
{
	spriteSheetTexture->Render(pos.x, pos.y, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer);
}
