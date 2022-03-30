#pragma once
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow& win) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji{

    protected:
        int radius;
        Point center;
        void draw(AnimationWindow& win) override = 0;

    public:
        Face(int r, Point c) : radius{r}, center{c} {};

};

class EmptyFace : public Face{

    protected:
        Point eye1 = {center.x - static_cast<int>(radius/3.3), center.y - radius/3};
        Point eye2 = {2*center.x - eye1.x, eye1.y};
        int eyeRadius = radius/7;

    public:
        EmptyFace(int radius,  Point center):Face{radius, center}{};
        void draw(AnimationWindow& win) override;
};

class SmilingFace : public EmptyFace{
    
    protected:
        Point arc_center = {center.x, center.y + radius/5};
        int width = radius;
        int height = static_cast<int>(radius/1.7);
        int start_degree = 200;
        int end_degree = 340;
    public:
    SmilingFace(int radius, Point center):EmptyFace(radius, center){};
    void draw(AnimationWindow& win) override;
};

class SadFace : public EmptyFace{
    
    protected:
        Point arc_center = {center.x, center.y + radius/2};
        int width = radius;
        int height = static_cast<int>(radius/1.7);
        int start_degree = 20;
        int end_degree = 160;
    
    public:
        SadFace(int radius, Point center):EmptyFace(radius, center){};
        void draw(AnimationWindow& win) override;

};

class AngryFace : public SadFace{

    protected:
        Point eyeBrowStart1 = {center.x - radius/10, center.y - radius/2};
        Point eyeBrowEnd1 = {center.x - static_cast<int>(radius/2.5), center.y - static_cast<int>(radius/1.5)};
        Point eyeBrowStart2 = {2*center.x -eyeBrowStart1.x, eyeBrowStart1.y};
        Point eyeBrowEnd2 = {2*center.x - eyeBrowEnd1.x, eyeBrowEnd1.y};

    public:
        AngryFace(int radius, Point center):SadFace(radius, center){};
        void draw(AnimationWindow& win) override;
};

class WinkingFace : public SmilingFace{

    protected:
        Point winkContact = {eye2.x - eyeRadius, eye1.y};
        Point winkUpperEnd = {eye2.x + eyeRadius, eye1.y - static_cast<int>(eyeRadius/1.5)};
        Point winkLowerEnd = {eye2.x + eyeRadius, eye1.y + eyeRadius/2};

    public:
    WinkingFace(int radius, Point center):SmilingFace(radius, center){};
    void draw(AnimationWindow& win) override;

};

class SurprisedFace : public EmptyFace{

    protected:
        Point mouthCenter = {center.x, center.y + radius/2};
        int mouthRadius = radius/3;

    public:
        SurprisedFace(int radius, Point center):EmptyFace(radius, center){};
        void draw(AnimationWindow& win) override;
};