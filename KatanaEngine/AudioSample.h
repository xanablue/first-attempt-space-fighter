
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

#pragma once

namespace KatanaEngine
{
	/** @brief Represents a 2D grid of texels. */
	class AudioSample : public Resource
	{

	public:

		/** @brief Instantiates a new audio sample. */
		AudioSample();
		virtual ~AudioSample();

		/** @brief Reserves a number of sample instances, attaching them to the default mixer.
			@param count The number of samples to reserve. */
		static void ReserveSamples(const int count) { al_reserve_samples(count); }

		/** @brief Load the desired sample into memory.
			@param path The path to the desired sample.
			@param pManager A pointer to the ResourceManager that will manage the sample.
			@return Returns true if the sample was loaded, false otherwise. */
		virtual bool Load(const std::string& path, ResourceManager* pManager);

		/** @brief Used to determine if the sample is cloneable.
			@return Returns true if the sample is clonable, false otherwise.
			@remark Audio samples should usually not be cloneable. */
		virtual bool IsCloneable() const { return true; }


		/** @brief Starts or resumes the sample.
			@return Returns true if the sample can be played, false otherwise. */
		virtual bool Play();

		/** @brief Sets whether the sample should loop. */
		virtual void SetLooping(const bool loop = true);

		/** @brief Sets the volume of the sample.
			@remark 1.0 is normal volume. */
		virtual void SetVolume(const float volume);


	protected:

		/** @brief Sets the underlaying allegro sample. */
		virtual void SetSample(ALLEGRO_SAMPLE* pSample) { m_pSample = pSample; }


	private:

		static bool s_alAddonInitialized;

		ALLEGRO_SAMPLE* m_pSample = nullptr;
		ALLEGRO_PLAYMODE m_playMode = ALLEGRO_PLAYMODE_ONCE;

		float m_volume = 1;
	};

}