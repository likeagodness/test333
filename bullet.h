#pragma once
#include <SFML/Graphics.hpp>

class map; //����� �����, ���������� ��� ������� �������������� � ������

class bullet //����� ���� 
{
private:
	float b_x, b_y, b_dx, b_dy; //���������� ����, ���������� ���������� �� ���� � ������
	
	enum BDIR //������������ ����������� �������� ����
	{ 
		left = 0, 
		right = 1, 
		up = 2, 
		down = 3 
	} b_dir;

	sf::Texture b_Texture; //�������� ����

public:
	bool present;	//��������� ���������� - �������� �� �������� � �����������,
	char owner;		//��������� ���������� - �������� �� �������� ����, ��� � ������ - �����, ��� ����

	sf::Sprite b_Sprite; //������ ����

	bullet(const float x, const float y, const char owner, const int bdir); //���������� ������������ � ����������� - ������������ ����, 
																													//� ��������� � � ������������
	~bullet();		//���������� ����������� ����

	void shoot()	//������� �������� ����
	{ 
		present = true; //��������� - ������ ���� ������������
	}

	void move(const sf::Int64 time); //���������� �������-����������� ����

	void update(map& map, const sf::Int64 time, float x, const float y, const int dir);  //���������� �������-���������� �������-���� �� ����� ���� �� �����

	void map_interaction(map& map); //���������� �������-�������������� ���� � ������
};
