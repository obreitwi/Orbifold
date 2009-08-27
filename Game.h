/*
 *  Game.h
 *  Prototyp
 *
 *  Created by Christian Pehle on 24.08.09.
 *  Copyright 2009 Universität Heidelberg. All rights reserved.
 *
 */

#ifndef GAME_H
#define GAME_H

#if WIN32
#elif LINUX
#else
#include <Carbon/Carbon.h>
#endif

#include <OIS/OISMouse.h>
#include <OIS/OISKeyboard.h>

#include <OgreRoot.h>
#include <OgreConfigFile.h>
#include <OgreRenderWindow.h>

#include "Input.h"



class Game :
  public OIS::KeyListener,
  public OIS::MouseListener {
  
public:
  
  void static start(); 
  void static stop();
  
protected:
  
  static Game* instance;
	  
  bool running;
  
  Ogre::Root* ogre;
  Ogre::RenderWindow* window;
  InputHandler* input;
  //GameState* state;
  
  static Game* getSingleton();

  void initialise();
  void initOgreRoot();
  void initOgreResources();
  void initRenderWindow();
  void initInput();

  Ogre::Camera* Game::createCamera(Ogre::SceneManager *, Ogre::RenderWindow *);

private:
	Game();
	~Game();
	  
	bool mouseMoved(const OIS::MouseEvent &evt);
	bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);

	bool keyPressed(const OIS::KeyEvent &evt);
	bool keyReleased(const OIS::KeyEvent &evt);

	// are we shutting down?
	bool bShutdown;
	// time since last frame
	float flFrameTime;

	  /*
	bool requestStateChange(State state);
	bool lockState();
	bool unlockState();
	State getCurrentState();

	void setFrameTime(float ms);
	inline float getFrameTime() {return flFrameTime;};
*/
};
#endif
