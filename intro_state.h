/*
 *  intro_state.h
 *  Prototyp
 *
 *  Created by Christian Pehle on 26.08.09.
 *  Copyright 2009 Universität Heidelberg. All rights reserved.
 *
 */
#pragma once

#include "play_state.h"
#include "game_state.h"

class IntroState : public GameState {
public:
	~IntroState();
	
	void enter();
	void exit();
	
	void update();
	
	void keyPressed(const OIS::KeyEvent &evt);
	void keyReleased(const OIS::KeyEvent &evt);
	
	void mouseMoved(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	void mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	void mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	
	static IntroState* getSingletonPtr();
private:
	IntroState() {}
	
	Ogre::Root *mRoot;
	Ogre::Camera *mCamera;
	Ogre::SceneManager *mSceneManager;
	Ogre::RenderWindow *mRenderWindow;
	Ogre::Viewport *mViewport;
	Ogre::OverlayManager *mOverlayManager;
	Ogre::Overlay *mIntroOverlay;
	
	static IntroState *mIntroState;
};