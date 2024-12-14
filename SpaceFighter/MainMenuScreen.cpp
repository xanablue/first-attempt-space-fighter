
#include "MainMenuScreen.h"
#include "GameplayScreen.h"
#include "PlayerShip.h"
#include "Level.h"


MainMenuScreen::MainMenuScreen()
{
	// when the screen is removed, quit the game
	SetOnRemove([this](){ GetGame()->Quit(); });

	SetTransitionInTime(1);
	SetTransitionOutTime(0.5f);

	Show();
}

// Xana - Method that resets player health
void MainMenuScreen::ResetPlayer()
{
	Level::ResetLevel(m_pPlayerShip);
}

void MainMenuScreen::LoadContent(ResourceManager& resourceManager)
{
	// Xana - Initialize ship
	m_pPlayerShip = new PlayerShip();
	
	// Logo
	m_pTexture = resourceManager.Load<Texture>("Textures\\Logo.png");
	m_texturePosition = Game::GetScreenCenter() - Vector2::UNIT_Y * 150;

	// Create the menu items
	const int COUNT = 2;
	MenuItem *pItem;
	Font::SetLoadSize(20, true);
	Font *pFont = resourceManager.Load<Font>("Fonts\\arial.ttf");

	SetDisplayCount(COUNT);

	enum Items { START_GAME, QUIT };
	std::string text[COUNT] = { "Start Game", "Quit" };

	for (int i = 0; i < COUNT; i++)
	{
		pItem = new MenuItem(text[i]);
		pItem->SetPosition(Vector2(100, 100 + 50 * i));
		pItem->SetFont(pFont);
		pItem->SetColor(Color::BLUE);
		pItem->SetSelected(i == 0);
		AddMenuItem(pItem);
	}

	// when "Start Game" is selected, replace the "SetRemoveCallback" delegate
	// so that it doesn't quit the game (originally set in the constructor)
	GetMenuItem(START_GAME)->SetOnSelect([this](){
		// Xana - Reset 
		ResetPlayer();

		SetOnRemove([this](){ AddScreen(new GameplayScreen()); });
		Exit();
	});

	// bind the Exit method to the quit menu item
	GetMenuItem(QUIT)->SetOnSelect(std::bind(&MainMenuScreen::Exit, this));
}

void MainMenuScreen::Update(const GameTime& gameTime)
{
	bool isSelected = false;
	float alpha = GetAlpha();
	float offset = sinf(gameTime.GetTotalTime() * 10) * 5 + 5;

	for (MenuItem* pItem : GetMenuItems())
	{
		pItem->SetAlpha(alpha);
		isSelected = pItem->IsSelected();
		pItem->SetColor(isSelected ? Color::WHITE : Color::BLUE);
		pItem->SetTextOffset(isSelected ? Vector2::UNIT_X * offset : Vector2::ZERO);
	}

	MenuScreen::Update(gameTime);
}

void MainMenuScreen::Draw(SpriteBatch& spriteBatch)
{
	spriteBatch.Begin();
	spriteBatch.Draw(m_pTexture, m_texturePosition, Color::WHITE * GetAlpha(), m_pTexture->GetCenter());
	MenuScreen::Draw(spriteBatch);
	spriteBatch.End();
}
