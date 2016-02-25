/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include <map>


//==============================================================================
MainContentComponent::MainContentComponent()
{
    addAndMakeVisible(demo);
    setSize (600, 400);
}

MainContentComponent::~MainContentComponent()
{

}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));

}

void MainContentComponent::resized()
{
    demo.setBounds(getLocalBounds());
}
