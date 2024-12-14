
/*
     ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC
			    http://www.shurikenstudios.com
*/

#include "KatanaEngine.h"

namespace KatanaEngine
{
	Screen::Screen()
	{
		m_isExiting = false;
		m_needsToBeRemoved = false;

		m_transitionInTime = 0.0;
		m_transitionOutTime = 0.0;

		m_pScreenManager = nullptr;

		m_transition = ScreenTransition::None;

		m_pRenderTarget = nullptr;

		m_transitionValue = 0.0f;

		m_onExit = nullptr;
		m_onRemove = nullptr;
	}

	void Screen::UpdateTransition(const GameTime& gameTime)
	{
		if (m_transition != ScreenTransition::None)
		{
			m_transitionTime -= gameTime.GetElapsedTime();

			if (m_transition == ScreenTransition::In)
			{
				if (m_transitionInTime > 0)
				{
					m_transitionValue = 1 - (float)m_transitionTime / (float)m_transitionInTime;
				}
				else
				{
					m_transitionValue = 1;
				}
			}

			if (m_transition == ScreenTransition::Out)
			{
				if (m_transitionOutTime > 0)
				{
					m_transitionValue = (float)m_transitionTime / (float)m_transitionOutTime;
				}
				else
				{
					m_transitionValue = 0;
				}
			}

			if (m_transitionValue < 0) m_transitionValue = 0;
			if (m_transitionValue > 1) m_transitionValue = 1;

			if (m_transitionTime <= 0)
			{
				m_transitionTime = 0;
				m_transition = ScreenTransition::None;

				if (m_isExiting)
				{
					m_needsToBeRemoved = true;
				}
			}
		}
	}

	void Screen::SetScreenManager(ScreenManager& screenManager)
	{
		m_pScreenManager = &screenManager;
	}

	void Screen::AddScreen(Screen* pScreen) const
	{
		m_pScreenManager->AddScreen(pScreen);
	}

	void Screen::Show()
	{
		TransitionIn();
	}

	void Screen::Exit()
	{
		m_isExiting = true;

		TransitionOut();

		if (m_onExit) ((OnExit)m_onExit)();
	}

	void Screen::TransitionIn()
	{
		if (m_transition == ScreenTransition::None)
		{
			m_transitionTime = m_transitionInTime;
			m_transition = ScreenTransition::In;
		}
	}

	void Screen::TransitionOut()
	{
		if (m_transition == ScreenTransition::None)
		{
			m_transitionTime = m_transitionOutTime;
			m_transition = ScreenTransition::Out;
		}
	}

	Game *Screen::GetGame() const
	{
		return m_pScreenManager->GetGame();
	}

	void Screen::UseRenderTarget()
	{
		m_pRenderTarget = new RenderTarget(Game::GetScreenWidth(), Game::GetScreenHeight());
	}
}