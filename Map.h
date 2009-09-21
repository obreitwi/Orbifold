/*
 *  Map.h
 *  Prototyp
 *
 *  Created by Oliver Breitwieser on 07.09.09.
 *  Copyright 2009 Universitšt Heidelberg. All rights reserved.
 *
 */
 
#ifndef MAP_H
#define MAP_H

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
#include <Carbon/Carbon.h>
#endif

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

namespace Orbifold {

class Map {
private:
	// Chart* chart; // not implemented yet
	Ogre::SceneManager* scenemanager;

protected:

public:

};
}

#endif