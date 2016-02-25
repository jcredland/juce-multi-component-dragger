/*
 ==============================================================================

 jcf_multi_selection_demo.h
 Created: 25 Feb 2016 9:00:56am
 Author:  Jim Credland

 ==============================================================================
 */

#ifndef JCF_MULTI_SELECTION_DEMO_H_INCLUDED
#define JCF_MULTI_SELECTION_DEMO_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "jcf_multi_component_dragger.h"

class MultiComponentDraggerDemo : public Component
{
public:
    MultiComponentDraggerDemo()
    {
        dragger.setShiftConstrainsDirection(true);
        dragger.setConstrainBoundsToParent(true, {0, 0, 10, 10} /* amount permitted offscreen. */);

        Random random;

        for (int i = 0; i < 10; ++i)
        {
            auto c = new ExampleComponent(dragger);
            c->setBounds(random.nextInt(570), random.nextInt(370), 30, 30);
            addAndMakeVisible(c);
        }
    }

    ~MultiComponentDraggerDemo()
    {
        deleteAllChildren();
    }

    class ExampleComponent : public Component
    {
    public:
        ExampleComponent(MultiComponentDragger & dragger_)
        :
        dragger(dragger_)
        {
            Random random;
            colour = Colours::red.withHue(random.nextFloat());
        }

        void paint(Graphics & g) override
        {
            g.fillAll(colour.withSaturation(0.5f).withMultipliedBrightness(0.5f));

            if (dragger.isSelected(this))
            {
                g.setColour(colour);
                g.drawRect(getLocalBounds(), 4.0f);
            }
        }

        void mouseDown(const MouseEvent & e) override
        {
            dragger.handleMouseDown(this, e);
        }

        void mouseUp(const MouseEvent & e) override
        {
            dragger.handleMouseUp(this, e);
        }

        void mouseDrag(const MouseEvent & e) override
        {
            dragger.handleMouseDrag(e);
        }

        MultiComponentDragger & dragger;
        Colour colour;
    };
    
    void mouseUp(const MouseEvent & e)
    {
        dragger.deselectAll();
    }
    
private:
    MultiComponentDragger dragger;
    
};

#endif  // JCF_MULTI_SELECTION_DEMO_H_INCLUDED
