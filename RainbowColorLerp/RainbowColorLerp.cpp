#include "RainbowColorLerp.h"


RainbowColorLerp::RainbowColorLerp()
        : lerpTime{ 1.0F }, useWhiteAndBlack{ true }, useReverseMode{ false } {
    initTime = ofGetElapsedTimef();

    if (useReverseMode) {
        colorToLerp = AvailableColors::Violet;
        setReverseColors();
    } else {
        colorToLerp = AvailableColors::Red;
        setColors();
    }
}


RainbowColorLerp::~RainbowColorLerp() {  }


void RainbowColorLerp::updateColor() {
    auto endTime = initTime + lerpTime;
    auto now     = ofGetElapsedTimef();

    float sHue, sSat, sBri;
    float eHue, eSat, eBri;
    startColorOF.getHsb(sHue, sSat, sBri);
    endColorOF.getHsb(eHue, eSat, eBri);
    auto hue = ofxeasing::map_clamp(now, initTime, endTime, sHue, eHue, &ofxeasing::linear::easeIn);
    auto sat = ofxeasing::map_clamp(now, initTime, endTime, sSat, eSat, &ofxeasing::linear::easeIn);
    auto bri = ofxeasing::map_clamp(now, initTime, endTime, sBri, eBri, &ofxeasing::linear::easeIn);
    currentColorOF.setHsb(hue, sat, bri);

    if (now >= endTime) {
        initTime = now;
        if (!useReverseMode)
            setColors();
        else
            setReverseColors();
    }
}


void RainbowColorLerp::setColors() {
    switch (colorToLerp) {
        case AvailableColors::Red :
            colorToLerp = AvailableColors::Orange;
            currentColorOF.set(255, 0, 0);
            startColorOF.set(255, 0, 0);
            endColorOF.set(255, 127, 0);
        break;

        case AvailableColors::Orange:
            colorToLerp = AvailableColors::Yellow;
            currentColorOF.set(255, 127, 0);
            startColorOF.set(255, 127, 0);
            endColorOF.set(255, 255, 0);
        break;

        case AvailableColors::Yellow:
            colorToLerp = AvailableColors::Green;
            currentColorOF.set(255, 255, 0);
            startColorOF.set(255, 255, 0);
            endColorOF.set(0, 255, 0);
        break;

        case AvailableColors::Green:
            colorToLerp = AvailableColors::Blue;
            currentColorOF.set(0, 255, 0);
            startColorOF.set(0, 255, 0);
            endColorOF.set(0, 0, 255);
        break;

        case AvailableColors::Blue:
            colorToLerp = AvailableColors::Indigo;
            currentColorOF.set(0, 0, 255);
            startColorOF.set(0, 0, 255);
            endColorOF.set(75, 0, 130);
        break;

        case AvailableColors::Indigo:
            colorToLerp = AvailableColors::Violet;
            currentColorOF.set(75, 0, 130);
            startColorOF.set(75, 0, 130);
            endColorOF.set(238, 130, 238);
        break;

        case AvailableColors::Violet:
            currentColorOF.set(238, 130, 238);
            startColorOF.set(238, 130, 238);
            if (useWhiteAndBlack) {
                colorToLerp = AvailableColors::White;
                endColorOF.set(255, 255, 255);
            } else {
                colorToLerp = AvailableColors::Red;
                endColorOF.set(255, 0, 0);
            }
        break;

        case AvailableColors::White:
            colorToLerp = AvailableColors::Black;
            currentColorOF.set(255, 255, 255);
            startColorOF.set(255, 255, 255);
            endColorOF.set(0, 0, 0);
        break;

        case AvailableColors::Black:
            colorToLerp = AvailableColors::Red;
            currentColorOF.set(0, 0, 0);
            startColorOF.set(0, 0, 0);
            endColorOF.set(255, 0, 0);
        break;

    }
}

void RainbowColorLerp::setReverseColors() {
    switch (colorToLerp) {
        case AvailableColors::Violet:
            colorToLerp = AvailableColors::Indigo;
            currentColorOF.set(238, 130, 238);
            startColorOF.set(238, 130, 238);
            endColorOF.set(75, 0, 130);
        break;

        case AvailableColors::Indigo:
            colorToLerp = AvailableColors::Blue;
            currentColorOF.set(75, 0, 130);
            startColorOF.set(75, 0, 130);
            endColorOF.set(0, 0, 255);
        break;

        case AvailableColors::Blue:
            colorToLerp = AvailableColors::Green;
            currentColorOF.set(0, 0, 255);
            startColorOF.set(0, 0, 255);
            endColorOF.set(0, 255, 0);
        break;

        case AvailableColors::Green:
            colorToLerp = AvailableColors::Yellow;
            currentColorOF.set(0, 255, 0);
            startColorOF.set(0, 255, 0);
            endColorOF.set(255, 255, 0);
        break;

        case AvailableColors::Yellow:
            colorToLerp = AvailableColors::Orange;
            currentColorOF.set(255, 255, 0);
            startColorOF.set(255, 255, 0);
            endColorOF.set(255, 127, 0);
        break;

        case AvailableColors::Orange:
            colorToLerp = AvailableColors::Red;
            currentColorOF.set(255, 127, 0);
            startColorOF.set(255, 127, 0);
            endColorOF.set(255, 0, 0);
        break;

        case AvailableColors::Red :
            currentColorOF.set(255, 0, 0);
            startColorOF.set(255, 0, 0);
            if (useWhiteAndBlack) {
                colorToLerp = AvailableColors::White;
                endColorOF.set(255, 255, 255);
            } else {
                colorToLerp = AvailableColors::Violet;
                endColorOF.set(238, 130, 238);
            }

        break;

        case AvailableColors::White:
            colorToLerp = AvailableColors::Black;
            currentColorOF.set(255, 255, 255);
            startColorOF.set(255, 255, 255);
            endColorOF.set(0, 0, 0);
        break;

        case AvailableColors::Black:
            colorToLerp = AvailableColors::Violet;
            currentColorOF.set(0, 0, 0);
            startColorOF.set(0, 0, 0);
            endColorOF.set(238, 130, 238);
        break;

    }
}
