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


#include "ScreenLogger.h"
boost::circular_buffer<std::string>  ScreenLogger::mBuffer;
ci::Font                             ScreenLogger::mFont;
ci::gl::TextureRef                   ScreenLogger::mTexture;


void ScreenLogger::init( uint8_t bufferSize, ci::Font font )
{
    mFont = font;
    mBuffer.set_capacity( bufferSize );
}


void ScreenLogger::render( glm::vec2 pos )
{
    ci::gl::color( ci::Color::white() );

    std::string text = "";

    for( int k=0; k < mBuffer.size(); k++ )
        text += mBuffer[k] + "\n";

    ci::TextBox tbox = ci::TextBox().font( mFont ).size( glm::ivec2( ci::TextBox::GROW, ci::TextBox::GROW ) ).text( text );
    tbox.setBackgroundColor( ci::ColorA( 0.0f, 0.0f, 0.0f, 0.6f ) );

    mTexture = ci::gl::Texture2d::create( tbox.render() );
    ci::gl::draw( mTexture, pos );

}
