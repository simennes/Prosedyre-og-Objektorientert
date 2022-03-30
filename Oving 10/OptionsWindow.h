#pragma once
#include "AnimationWindow.h"
#include "Tile.h"
#include "MinesweeperWindow.h"

class OptionsWindow : public AnimationWindow{
    private:
        static constexpr int butW = 90;
        static constexpr int butH = 60;

        int nTiles = 0;
        int nMines = 0;

        Fl_Button smallButton;
        Fl_Button mediumButton;
        Fl_Button largeButton;

        Fl_Button easyButton;
        Fl_Button okButton;
        Fl_Button hardButton;

        Fl_Button startButton;

        static void cb_start(Fl_Widget*, void* pw){
            OptionsWindow* opw = static_cast<OptionsWindow*>(pw);
            opw->hide();
            opw->startGame();
        }

        static void cb_small(Fl_Widget*, void* pw){
            OptionsWindow* opw = static_cast<OptionsWindow*>(pw);
            opw->nTiles = 10;
        }
        static void cb_medium(Fl_Widget*, void* pw){
            OptionsWindow* opw = static_cast<OptionsWindow*>(pw);
            opw->nTiles = 20;
        }
        static void cb_large(Fl_Widget*, void* pw){
            OptionsWindow* opw = static_cast<OptionsWindow*>(pw);
            opw->nTiles = 30;
        }

        static void cb_easy(Fl_Widget*, void* pw){
            OptionsWindow* opw = static_cast<OptionsWindow*>(pw);
            opw->nMines = (int)(pow(opw->nTiles,2)/20);
        }
        static void cb_ok(Fl_Widget*, void* pw){
            OptionsWindow* opw = static_cast<OptionsWindow*>(pw);
            opw->nMines = 2*(int)(pow(opw->nTiles,2)/20);
        }
        static void cb_hard(Fl_Widget*, void* pw){
            OptionsWindow* opw = static_cast<OptionsWindow*>(pw);
            opw->nMines = 3*(int)(pow(opw->nTiles,2)/20);
        }
        void startGame(){
            MinesweeperWindow mw{200, 300,nTiles ,nTiles ,nMines , "Minesweeper" };
            gui_main();
        }
    public:
        OptionsWindow(int x, int y, int width, int height, const string& title);
};