#include "PlayGround.h"
#include "GeometryUtils.h"

void PlayGround::addShape(FlatShape *shape) {
	shapes.push_front(shape);
}

void PlayGround::draw() {
	for(list<FlatShape*>::iterator it = shapes.begin(); it != shapes.end();){
		(*it)->moveDown();
		if((*it)->getBottommostCoordinate() <= GeometryUtils::BORDER_BOTTOM) {
			delete *it;
			it = shapes.erase(it);
		} else {
			(*it)->draw();
			it++;
		}
	}
}

int PlayGround::shoot(float x, float y) {
	int score = 0;
	for(list<FlatShape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
		if((*it)->covers(x, y)) {
			score = (*it)->getScore();
			delete *it;
			shapes.erase(it);
			break;
		}
	}
	return score;
}

float PlayGround::getZOffset() {
	return shapes.size() == 0 ? GeometryUtils::BORDER_FAR + GeometryUtils::Z_OFFSET
		: shapes.front()->getZ();
}