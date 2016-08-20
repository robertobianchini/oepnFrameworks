#ifndef COLORLERP_H_
#define COLORLERP_H_


/**
 * This class requires ofxEasing addon https://github.com/arturoc/ofxEasing
 */

#include "ofMain.h"
#include "ofxEasing.h"


enum class AvailableColors { Black, White, Red, Orange, Yellow, Green, Blue, Indigo, Violet };

class RainbowColorLerp {
public:
    RainbowColorLerp();

    virtual ~RainbowColorLerp();

    virtual void updateColor();

    inline void setCurrentColor() const { ofSetColor(currentColorOF); }

    inline void setLerpTime(float time) { lerpTime = time; };

    inline void setWhiteAndBlack(bool value) { useWhiteAndBlack = value; }

    inline void setReverseMode(bool value) {
        useReverseMode = value;
        if (useReverseMode) {
            colorToLerp = AvailableColors::Violet;
            setReverseColors();
        } else {
            colorToLerp = AvailableColors::Red;
            setColors();
        }
    }

protected:
    virtual void setColors();
    virtual void setReverseColors();

    AvailableColors colorToLerp;
    ofColor         currentColorOF;
    ofColor         startColorOF;
    ofColor         endColorOF;
    float           initTime;
    float           lerpTime;
    bool            useWhiteAndBlack;
    bool            useReverseMode;
};

#endif

