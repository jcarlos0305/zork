#include "map.h"

Map::Map() {

}

Map::~Map(){

}

void Map::AddArea(Area * area) {
	areas.push_back(area);
}
