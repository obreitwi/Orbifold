/*
 *  play_state.cpp
 *  Prototyp
 *
 *  Created by Christian Pehle on 26.08.09.
 *  Copyright 2009 Universität Heidelberg. All rights reserved.
 *
 */

#include "play_state.h"
#include <OgreTextureUnitState.h>

PlayState* PlayState::mPlayState;

void PlayState::enter(Ogre::RenderWindow* window) {
	mGame = Game::getSingeltonPtr();
	mRoot = Ogre::Root::getSingletonPtr();
	mOverlayManager = Ogre::OverlayManager::getSingletonPtr();
	mRenderWindow = window;
	mSceneManager = mRoot->getSceneManager("ST_GENERIC");
	
	mCamera = this->createCamera(mSceneManager, mRenderWindow);	
	this->createOverlays();
	
}


void PlayState::exit() {
	this->hideOverlays();
	mSceneManager->clearScene();
	mSceneManager->destroyAllCameras();
	mRenderWindow->removeAllViewPorts();
}

// A lot of stubs.
void PlayState::pause() {}
void PlayState::resume() {}


void PlayState::update() {
	
}

void PlayState::keyPressed(const OIS::KeyEvent &evt) {}
void PlayState::keyReleased(const OIS::KeyEvent &evt) {
	if (evt.key == OIS::KC_SPACE) {
		mGame->requestStateChange(PAUSE);
	} else if(evt.key == OIS::KC_ESCAPE) {
		mGame->requestStateChange(SHUTDOWN);		
	}
}

void PlayState::mouseMoved(const OIS::MouseEvent &evt) {
	const OIS::MouseState &mouseState = evt.state;
	// Update Mousepointer on Screen.
	mMousePointer->setTop(mouseState.abY);
	mMousePointer->setLeft(mouseState.abX);
}

void PlayState::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id) {}
void PlayState::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id) {}



void createOverlays() {}
void hideOverlays() {}

Ogre::Camera* PlayState::createCamera(Ogre::SceneManager *sceneMgr, Ogre::RenderWindow *window) {
	Ogre::Camera* cam = sceneMgr->createCamera("SimpleCamera");
	cam->setPosition(Ogre::Vector3(0.0f,0.0f,500.0f));
	cam->lookAt(Ogre::Vector3(0.0f,0.0f,0.0f));
	cam->setNearClipDistance(5.0f);
	cam->setFarClipDistance(5000.0f);
	
	Ogre::Viewport* v = window->addViewport(cam);
	v->setBackgroundColour(Ogre::ColourValue(0.5,0.5,0.5));
	
	cam->setAspectRatio(Ogre::Real(v->getActualWidth())/v->getActualHeight());
	
	return cam;
}


}
