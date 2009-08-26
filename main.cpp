/*
Author: Christian Pehle
*/


#include "game.h"


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT){
#else
int main(int argc, char **argv){
#endif

	Ogre::Root *ogre=initOgre();

	      		
	Ogre::SceneManager* sceneMgr = ogre->createSceneManager(Ogre::ST_GENERIC);

	Game *game = Game::getSingletonPtr();
	game->startGame();

	delete game;
	delete ogre;
	return 0;
}

