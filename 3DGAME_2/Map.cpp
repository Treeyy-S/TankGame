#include"Map.h"

Map::Map()
{
	Initialize();
}
Map::~Map()
{

}
void Map::Initialize()
{
	groundHandle = MV1LoadModel("data/model/ground/ground.mv1");
	townHandle = MV1LoadModel("data/model/town/town.mv1");

	MV1SetPosition(townHandle, TOWN_MODEL_POSITION_VECTOR);
	MV1SetScale(townHandle, TOWN_MODEL_SCALE_VECTOR);

	MV1SetPosition(groundHandle, GROUND_MODEL_POSITION_VECTOR);
	MV1SetScale(groundHandle, GROUND_MODEL_SCALE_VECTOR);
}
void Map::Draw()
{
	MV1DrawModel(groundHandle);
	MV1DrawModel(townHandle);
}