//
// Created by Larry Peng on 4/18/21.
//
#include <iostream>
#include <game/game_engine.h>
// Using format to run cinder app from gas simulation and naive bayes

using finalproject::game::GameEngine;

// Same method as previous cinder projects to ensure window is not resizable
void prepareSettings(GameEngine::Settings* settings) {
  settings->setResizable(false);
}

CINDER_APP(GameEngine, ci::app::RendererGl, prepareSettings);