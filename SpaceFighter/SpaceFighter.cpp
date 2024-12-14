
#include "KatanaEngine.h"
#include "SpaceFighter.h"
#include "MainMenuScreen.h"
#include "Projectile.h"
#include "Explosion.h"

using namespace KatanaEngine;


SpaceFighter::SpaceFighter()
{
	SetScreenResolution(1600, 900);
	SetFullScreen(false);

	InitializeScreenManager();

	SetResourceDirectory("..\\SpaceFighter\\Content\\");

	// Font for displaying the frame rate
	Font::SetLoadSize(18, true);
	Font *pFont = GetResourceManager()->Load<Font>("Fonts\\Arialbd.ttf", false);
	SetFrameCounterFont(pFont);
}


void SpaceFighter::LoadContent(ResourceManager& resourceManager) 
{
	// Load static resources
	// Note: Every level will have these resources, so let's just load them once.
	Projectile::SetTexture(resourceManager.Load<Texture>("Textures\\Bullet.png"));

	GetScreenManager()->AddScreen(new MainMenuScreen());

	ResetGameTime();
}


void SpaceFighter::Draw(SpriteBatch& spriteBatch)
{
	Game::Draw(spriteBatch);

	DisplayFrameRate();
}