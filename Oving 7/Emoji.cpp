#include "Emoji.h"
#include "AnimationWindow.h"


void Face::draw(AnimationWindow& win){
    win.draw_circle(center, radius, Color::yellow);
}

void EmptyFace::draw(AnimationWindow& win){
    Face::draw(win);
    win.draw_circle(eye1, eyeRadius, Color::dark_yellow);
    win.draw_circle(eye2, eyeRadius, Color::dark_yellow);
}

void SmilingFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(arc_center, width, height, start_degree, end_degree, Color::black);
}

void SadFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(arc_center, width, height, start_degree, end_degree, Color::black);
}

void AngryFace::draw(AnimationWindow& win){
    SadFace::draw(win);
    win.draw_line(eyeBrowStart1, eyeBrowEnd1, Color::black);
    win.draw_line(eyeBrowStart2, eyeBrowEnd2, Color::black);
}

void WinkingFace::draw(AnimationWindow& win){
    Face::draw(win);
    win.draw_circle(eye1, eyeRadius, Color::dark_yellow);
    win.draw_arc(arc_center, width, height, start_degree, end_degree, Color::black);
    win.draw_line(winkContact, winkUpperEnd, Color::black);
    win.draw_line(winkContact, winkLowerEnd, Color::black);
}

void SurprisedFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_circle(mouthCenter, mouthRadius, Color::dark_red);
}