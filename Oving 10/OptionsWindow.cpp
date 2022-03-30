#include "OptionsWindow.h"

OptionsWindow::OptionsWindow(int x, int y, int width, int height, const string& title) : 
    AnimationWindow{x, y, width, height, title},
    startButton{width - butW - 3, height - butH - 3, butW, butH, "Start"},

    smallButton{butW, butH, butW, butH, "Small"},
    mediumButton{(int)(2.5*butW), butH, butW, butH, "Medium"},
    largeButton{4*butW, butH, butW, butH, "Large"},

    easyButton{butW, 3*butH, butW, butH, "Easy"},
    okButton{(int)(2.5*butW), 3*butH, butW, butH, "Medium"},
    hardButton{4*butW, 3*butH, butW, butH, "Hard"}
    {
        add(startButton);
        add(smallButton);
        add(mediumButton);
        add(largeButton);
        add(easyButton);
        add(okButton);
        add(hardButton);

        startButton.callback(cb_start, this);

        smallButton.callback(cb_small, this);
        mediumButton.callback(cb_medium, this);
        largeButton.callback(cb_large, this);

        easyButton.callback(cb_easy, this);
        okButton.callback(cb_ok, this);
        hardButton.callback(cb_hard, this);
    }