#ifndef SDLGRAPHICSPROGRAM_HPP
#define SDLGRAPHICSPROGRAM_HPP

// ==================== Libraries ==================
// Depending on the operating system we use
// The paths to SDL are actually different.
// The #define statement should be passed in
// when compiling using the -D argument.
// This gives an example of how a programmer
// may support multiple platforms with different
// dependencies.
#if defined(LINUX) || defined(MINGW)
    #include <SDL2/SDL.h>
#else // This works for Mac
    #include <SDL.h>
#endif

// Include the 'Renderer.hpp' which deteremines what
// the graphics API is going to be for OpenGL
#include "Renderer.hpp"
#include "Camera.hpp"
#include "Terrain.hpp"
#include "Perlin.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>


// Purpose:
// This class sets up a full graphics program using SDL
//
//
//
class SDLGraphicsProgram{
public:

    // Constructor
    SDLGraphicsProgram(int w, int h);
    // Destructor
    ~SDLGraphicsProgram();
    // Setup OpenGL
    bool InitGL();
    // Loop that runs forever
    void Loop();
    // Get Pointer to Window
    SDL_Window* GetSDLWindow();
    // Helper Function to Query OpenGL information.
    void GetOpenGLVersionInfo();

    // A helper function to load in terrain and do things as add bushes to that terrain
    // Used on start and on new terrain loading
    void terrainHelper();

    // Generates a new perlin map to use in our terrain generation
    void generateRandomMap();

    // The node, the parent node for the entire scene, of the terrain
    SceneNode* terrainNode;

    // Our terrain object that holds the data of the current terrain
    Terrain* myTerrain;

    // Our object we reference when creating bushes
    Object* bushQuad;

    // A boolean to facilitate switching between render modes
    bool fractal;

private:
	// The Renderer responsible for drawing objects
	// in OpenGL (Or whatever Renderer you choose!)
	Renderer* m_renderer;
    // The window we'll be rendering to
    SDL_Window* m_window ;
    // OpenGL context
    SDL_GLContext m_openGLContext;

    float g_uOffset=-2.0f;
    
    float g_uRotate=0.0f;
};

#endif
