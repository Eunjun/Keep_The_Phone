#pragma once

/**
 * \brief Resource Container
 */
class ResContainer
{
	std::unordered_map<std::string, sf::Texture> _textures;
	std::unordered_map<std::string, sf::Music> _musics;

public:
	sf::Texture* GetTexture(std::string type)
	{
		return &_textures[type];
	}

	sf::Music* GetMusic(std::string type)
	{
		return &_musics[type];
	}

	void Init()
	{
		_textures["BackgroundMenu"].loadFromFile("../Resource/Image/BackgroundMenu.png");
		_textures["BackgroundGame"].loadFromFile("../Resource/Image/BackgroundGame.png");
		_textures["BackgroundGameOver"].loadFromFile("../Resource/Image/BackgroundGameOver.png");
		_textures["BackgroundCredit"].loadFromFile("../Resource/Image/BackgroundCredit.png");
		_textures["BackgroundTutorial"].loadFromFile("../Resource/Image/BackgroundTutorial.png");
		_textures["TeacherD"].loadFromFile("../Resource/Image/DJ_K.png");
		_textures["TeacherH"].loadFromFile("../Resource/Image/MSH.png");
		_textures["student1"].loadFromFile("../Resource/Image/student1.png");
		_textures["student2"].loadFromFile("../Resource/Image/student2.png");
		_textures["student3"].loadFromFile("../Resource/Image/student3.png");
		_textures["student4"].loadFromFile("../Resource/Image/student4.png");
		_textures["student5"].loadFromFile("../Resource/Image/student5.png");
		_textures["student6"].loadFromFile("../Resource/Image/student6.png");
		_textures["Phone"].loadFromFile("../Resource/Image/Phone.png");
		_textures["DJ_KLaser"].loadFromFile("../Resource/Image/DJ_KLaser.png");
		_textures["MSHLaser"].loadFromFile("../Resource/Image/MSHLaser.png");

		_musics["MenuBgm"].openFromFile("../Resource/Sound/MenuBgm.ogg");
		_musics["GameBgm"].openFromFile("../Resource/Sound/GameBgm.ogg");
		_musics["GameOver"].openFromFile("../Resource/Sound/Gameover.ogg");
		_musics["KeyEffect"].openFromFile("../Resource/Sound/KeyEffect.ogg");
		_musics["Laser"].openFromFile("../Resource/Sound/Laser.ogg");
	}

	void Release()
	{
	}
};
