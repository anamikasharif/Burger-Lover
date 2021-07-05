#include <gbalib.h>
void textbox(char * text) {
    Color  rectanglecolor = createColor(204, 255, 255);
    Position rectPos = {20, 110};
    Size rectSize = {200, 40};

    Position text_pos = {40, 120};
    Color text_color = createColor(12,12,12);
    Size textSize = {180, 30};
    while (true) {
        bool buttonAWasPressed = wasButtonPressed(A);
        if (buttonAWasPressed == true) {
            drawFilledRectangle(rectanglecolor, rectPos, rectSize);
            animateTextFast(text,text_color, text_pos, textSize);
            updateScreen();
            break;
        }
    updateScreen();
    }
}

int main() {
    // Add code here!
    Background background = createBackground("kitchen");
    Position bg_pos = {0,0};
    drawBackground (background, bg_pos);

    Position text_pos1 = {60, 120};
    Color text_color1 = createColor(255,255,255);
    drawText("Start Game",text_color1, text_pos1);



    Sound music = createSound("maintheme");
    playSound(music, true);
    wait(0.3);

    Background background1 = createBackground("kitchenburger");
    while (true) {
        bool buttonAWasPressed = wasButtonPressed(A);
        if (buttonAWasPressed == true) {
            drawBackground (background1, bg_pos);
            updateScreen();
            break;
        }
        updateScreen();
    }
    
    textbox("Welcome to my restaurant");
    textbox("Where you make sandwiches!");
    textbox("And help me beat my rival!");
    
}