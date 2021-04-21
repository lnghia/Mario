#pragma once
#include <d3d9.h>
#include <iostream>
#include <vector>
#include "Textures.h"
#include "Game.h"

using namespace std;

class MapDrawer
{
private:
	LPDIRECT3DTEXTURE9 tileSetTexture;
	vector<vector<int>> map;
	int tileWidth, tileHeight, spaceBetweenTiles = 1, tilesPerRowInTileSet, tilesPerColumnInTileSet;
	int width, height;
public:
	MapDrawer(LPCWSTR _tileSetPath, string _matrixIdsPath, string _mapInfoPath, char _seperatorOfMatrixIds, D3DCOLOR _transcolor);
	MapDrawer(string& _matrixIdsPath, int mapHeight, int mapWidth, int tileHeight, int tileWidth, int textureId);
	//~MapDrawer();

	// Getter
	int getTileSize();
	int getWidth();
	int getHeight();

	void Update(int _dt);
	vector<int> GetTilesOnCam();
	void Draw();

	void mapInfoReader(string& _mapInfoPath);
};

