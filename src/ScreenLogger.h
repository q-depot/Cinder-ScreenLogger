 /*
*  ScreenLogger.h
*
*  Created by Andrea Cuius
*  The MIT License (MIT)
*  Copyright (c) 2015 Nocte Studio Ltd.
*
*  www.nocte.co.uk
*  andrea@nocte.co.uk
*/

#pragma once

#include "cinder/gl/Texture.h"
#include "cinder/Text.h"
#include <boost/circular_buffer.hpp>

class ScreenLogger {

public:

    static void init( uint8_t bufferSize = 40, ci::Font font = ci::Font( "Arial", 16 ) );

    static void log( std::string msg ) { mBuffer.push_back( msg ); }

    static void render( ci::Vec2f pos = ci::Vec2f(0) );

private:

    static boost::circular_buffer<std::string>  mBuffer;
    static ci::Font                             mFont;
    static ci::gl::TextureRef                   mTexture;

};

