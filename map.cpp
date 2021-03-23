#include <iostream>
#include <map.h>

map::map() //определение конструктора
{
	TileMap = new sf::String[HEIGHT_MAP] //создаем объект карты тайлов - каждый символ отвечает за различный элемент карты
	{
		"wwwwwwwwwwwwwwwwwww",
		"w   111     111   w",
		"w    11     11    w",
		"w2    1  0  1    2w",
		"w22             22w",
		"w22 0   333   0 22w",
		"w2  00       00  2w",
		"w      3   3      w",
		"w      3   3      w",
		"w 1             1 w",
		"w 11 1  333  1 11 w",
		"w    1       1    w",
		"w  0 1  222  1 0  w",
		"w  0   22222   0  w",
		"wwwwwwwwwwwwwwwwwww",
	};

	mTexture.loadFromFile("Textures/tileset.png"); //загружаем текстуру-тайлсет дл€ карты
	mSprite.setTexture(mTexture); //устанавливаем спрайт из текстуры
}

map::~map() //определение деструктора
{
	std::cout << "Map destroyed\n"; //проверка удалени€ объекта класса - печать в консоль
}

void map::break_wall(const int i, const int j) //определение функции разрушени€ стены - передаем в качестве еЄ аргументов еЄ координаты
{
	TileMap[i][j] = ' '; //устанавливаем текущий тайл-стену на пробел - пустой блок заднего фона
}

void map::draw(sf::RenderWindow& window) //объ€вление функции отрисовки карты
{
	for (int i = 0; i < HEIGHT_MAP; i++) //идем по строчкам
		for (int j = 0; j < WIDTH_MAP; j++) //идем по столбикам
		{
			switch (TileMap[i][j]) //в зависимости от текущего символа-тайла устанавливаем:
			{
			case ' ':
				mSprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); //задний фон
				break;

			case '0':
				mSprite.setTextureRect(sf::IntRect(1 * 64, 0, 64, 64));
				break;

			case '1':
				mSprite.setTextureRect(sf::IntRect(2 * 64, 0, 64, 64));
				break;

			case '2':
				mSprite.setTextureRect(sf::IntRect(3 * 64, 0, 64, 64));
				break;

			case '3':
				mSprite.setTextureRect(sf::IntRect(4 * 64, 0, 64, 64));
				break;

			case 'w': //стена
				mSprite.setTextureRect(sf::IntRect(5 * 64, 0, 64, 64));
				break;
			}

			mSprite.setPosition(j * 64, i * 64); //устанавливаем местоположение спрайта таким образом, потому что спрайт тайла размером 64X64
			window.draw(mSprite); //рисуем тайл
		}
}
