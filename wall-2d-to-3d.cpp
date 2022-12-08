#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
using namespace std;

#include <stdio.h>
#include <Windows.h>

int nScreenWidth = 120;			// Console Screen Size X (columns)
int nScreenHeight = 40;			// Console Screen Size Y (rows)
int nMapWidth = 16;				// World Dimensions
int nMapHeight = 16;

float fPlayerX = 14.7f;			// Player Start Position
float fPlayerY = 5.09f;
float fPlayerA = 0.0f;			// Player Start Rotation  ����������� ������
float fFOV = 3.14159f / 4.0f;	// Field of View
float fDepth = 16.0f;			// Maximum rendering distance
float fSpeed = 5.0f;			// Walking Speed

int main()
{
	// Create Screen Buffer
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight + 1]; // ������ ��� ������ � �����
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); // ����� ������
	SetConsoleActiveScreenBuffer(hConsole); // ��������� �������
	DWORD dwBytesWritten = 0; // ��� ������

	// Create Map of world space # = wall block, . = space
	wstring map;
	map += L"#########.......";
	map += L"#...............";
	map += L"#.......########";
	map += L"#..............#";
	map += L"#......##......#";
	map += L"#......##......#";
	map += L"#..............#";
	map += L"###............#";
	map += L"##.............#";
	map += L"#......####..###";
	map += L"#......#.......#";
	map += L"#......#.......#";
	map += L"#..............#";
	map += L"#......#########";
	map += L"#..............#";
	map += L"################";

	auto tp1 = chrono::system_clock::now();
	auto tp2 = chrono::system_clock::now();

	while (1) // ������� ����
	{
		tp2 = chrono::system_clock::now();
		chrono::duration <float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float fElapsedTime = elapsedTime.count();

		if (GetAsyncKeyState((unsigned short)'A') & 0x8000)
			fPlayerA -= (1.5f) * fElapsedTime; // �������� "A" ������������ �� ������� �������

		if (GetAsyncKeyState((unsigned short)'D') & 0x8000)
			fPlayerA += (1.5f) * fElapsedTime; // �������� "D" ������������ ������ ������� �������

		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) // �������� "W" ��� �����
		{
			fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
			fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;

			if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') { // ���� ����������� �� ������, �� ���������� ���
				fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;
			}
		}

		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) // �������� "S" ��� �����
		{
			fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
			fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;
			if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') { // ���� ����������� �� ������, �� ���������� ���
				fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
				fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;
			}
		}

		for (int x = 0; x < nScreenWidth; x++) // �������� �� ���� X
		{
			float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV; // ����������� ����
			// ������� ���������� �� ������ � ����������� fRayAngle 

			float fDistanceToWall = 0.0f; // ���������� �� ����������� � ����������� fRayAngle
			bool bHitWall = false; // ��������� �� ��� ������

			float fEyeX = sinf(fRayAngle); // ���������� ���������� ������� fRayAngle
			float fEyeY = cosf(fRayAngle);

			while (!bHitWall && fDistanceToWall < fDepth) // ���� �� ����������� �� ������
			{                                           // ��� �� ����� �� ������ ���������
				fDistanceToWall += 0.1f;

				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall); // ����� �� ������� ����
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall); // � ������� ����� ���

				if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
				{ // ���� �� ����� �� ����
					bHitWall = true;
					fDistanceToWall = fDepth;
				}
				else if (map[nTestY * nMapWidth + nTestX] == '#')
					bHitWall = true;

				//��������� ���������� ������ � ����� ������ �� �������� (1) � (2)
				int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
				int nFloor = nScreenHeight - nCeiling;

				short nShade;

				if (fDistanceToWall <= fDepth / 3.0f)        nShade = 0x2588; // ���� ������ ������, �� ������ 
				else if (fDistanceToWall < fDepth / 2.0f)    nShade = 0x2593; // ������� �������
				else if (fDistanceToWall < fDepth / 1.5f)    nShade = 0x2592; // ��� ��������� �������� 
				else if (fDistanceToWall < fDepth)           nShade = 0x2591; // ������ ����� ������
				else                                         nShade = ' ';

				for (int y = 0; y < nScreenHeight; y++) // ��� �������� X �������� �� ���� Y
				{
					// � ���� ����� �������� ������������ �������
					if (y <= nCeiling)
						screen[y * nScreenWidth + x] = ' ';
					else if (y > nCeiling && y <= nFloor)
						screen[y * nScreenWidth + x] = nShade;
					else
					{
						// �� �� ����� � ����� - ����� ������� ����� ������ ����� ��������� ���������
						float b = 1.0f - ((float)y - nScreenHeight / 2.0) / ((float)nScreenHeight / 2.0);
						if (b < 0.25)        nShade = '#';
						else if (b < 0.5)    nShade = 'x';
						else if (b < 0.75)   nShade = '~';
						else if (b < 0.9)    nShade = '-';
						else                 nShade = ' ';

						screen[y * nScreenWidth + x] = nShade;
					}
				}
			}
			// ������������� ��������
		}

		// Display Stats
		swprintf_s(screen, 40, L"X=%3.2f, Y=%3.2f, A=%3.2f FPS=%3.2f ", fPlayerX, fPlayerY, fPlayerA, 1.0f / fElapsedTime);

		// Display Map
		for (int nx = 0; nx < nMapWidth; nx++)
			for (int ny = 0; ny < nMapWidth; ny++)
			{
				screen[(ny + 1) * nScreenWidth + nx] = map[ny * nMapWidth + nx];
			}
		screen[((int)fPlayerX + 1) * nScreenWidth + (int)fPlayerY] = 'P';

		screen[nScreenWidth * nScreenHeight] = '\0';  // ��������� ������ - ��������� ������
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten); // ������ � �����

	}
}
