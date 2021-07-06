#include <gbalib.h>
void textbox(char * text) {
    Color  lightblue = createColor(204, 255, 255);
    Position rectPos = {20, 110};
    Size rectSize = {200, 40};

    Position text_pos = {40, 120};
    Color black = createColor(0,0,0);
    Size textSize = {180, 30};
    while (true) {
        bool buttonAWasPressed = wasButtonPressed(A);
        if (buttonAWasPressed == true) {
            drawFilledRectangle(lightblue, rectPos, rectSize);
            animateTextFast(text,black, text_pos, textSize);
            updateScreen();
            break;
        }
    updateScreen();
    }
}

int main() {
    // Add code here!
    Background kitchen_background = createBackground("kitchen");
    Position bg_pos = {0,0};

    Position text_pos1 = {60, 120};
    Color white = createColor(255,255,255);

    Sound music = createSound("maintheme");

    Background burger_background = createBackground("kitchenburger");

    drawBackground (kitchen_background, bg_pos);


    drawText("Press A to Start Game",white, text_pos1);




    playSound(music, true);
    wait(0.3);


    while (true) {
        bool buttonAWasPressed = wasButtonPressed(A);
        if (buttonAWasPressed == true) {
            drawBackground (burger_background, bg_pos);
            updateScreen();
            break;
        }
        updateScreen();
    }
    
    textbox("Feastopolis is one of those cities that never sleeps with foods dancing and buzzing around the town plate.");
    textbox("Where you make sandwiches!");
    textbox("And help me beat my rival!");
    
}