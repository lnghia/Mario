#include "MapDrawer.h"
#include <fstream>
#include "Textures.h"
#include "Utils.h"
#include <string>

void MapDrawer::mapInfoReader(string& _mapInfoPath) {
	ifstream reader(_mapInfoPath);
	string line = "";

	while (getline(reader, line)) {
		vector<int> tmp = stringToVectorOfInt(line);
		map.push_back(stringToVectorOfInt(line));
	}

	reader.close();
}

MapDrawer::MapDrawer(LPCWSTR _tileSetPath, string _matrixIdsPath, string _mapInfoPath, char _seperatorOfMatrixIds, D3DCOLOR _transcolor)
{

	//CTextures::GetInstance()->Add()
}

MapDrawer::MapDrawer(string& _matrixIdsPath, int mapHeight, int mapWidth, int tileHeight, int tileWidth, int textureId)
{
	tileSetTexture = CTextures::GetInstance()->Get(textureId);
	height = mapHeight;
	width = mapWidth;
	this->tileHeight = tileHeight;
	this->tileWidth = tileWidth;

	tilesPerRowInTileSet = 16;
	tilesPerColumnInTileSet = 8;

	mapInfoReader(_matrixIdsPath);
}

int MapDrawer::getTileSize()
{
	return 0;
}

int MapDrawer::getWidth() {
	return width;
}

int MapDrawer::getHeight()
{
	return height;
}

void MapDrawer::Update(int _dt)
{
}

vector<int> MapDrawer::GetTilesOnCam()
{
	CGame* instance = CGame::GetInstance();

	int left = instance->GetCamX() / tileWidth;
	int right = (instance->GetCamX() + instance->GetScreenWidth()) / tileWidth;
	int top = instance->GetCamY() / tileHeight;
	int bottom = (instance->GetCamY() + instance->GetScreenHeight()) / tileHeight;

	return vector<int>{ left, right, top, bottom };
}

void MapDrawer::Draw()
{
	vector<int> tilesOnCam = GetTilesOnCam();

	for (int row = tilesOnCam[2]; row <= tilesOnCam[3]; ++row) {
		for (int col = tilesOnCam[0]; col <= tilesOnCam[1]; ++col) {
			int tmp = map[row][col];

			int _r = map[row][col] / tilesPerRowInTileSet;
			int _c = map[row][col] % tilesPerRowInTileSet;

			int left = _c * tileWidth + _c * spaceBetweenTiles;
			int right = left + tileWidth;
			int top = _r * tileHeight + _r * spaceBetweenTiles;
			int bottom = top + tileHeight;

			CGame::GetInstance()->Draw(row * tileHeight, col * tileWidth, tileSetTexture, left, top, right, bottom);
		}
	}
}
