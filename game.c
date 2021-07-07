#include <gbalib.h>
int love;
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
void option_textbox(char * text1, char * text2) {
    Color  lightblue = createColor(204, 255, 255);
    Position rectPos = {20, 100};
    Size rectSize = {200, 50};

    Position text_pos1 = {30, 105};
    Position text_pos2 = {30, 127};
    Color black = createColor(0,0,0);
    Color white = createColor(255,255,255);
    Size textSize = {180, 17};

    Size sprite_size = {16,16};
    Sprite tomato_sprite = createSprite("tomato", sprite_size);
    Position cursor_origin = {210,105};
    updatePosition(tomato_sprite, cursor_origin);
    hideSprite(tomato_sprite);

    while (true) {
        bool buttonAWasPressed = wasButtonPressed(A);
        if (buttonAWasPressed == true) {
            drawFilledRectangle(lightblue, rectPos, rectSize);
            drawFilledRectangle(white, text_pos1, textSize);
            drawBlockText(text1,black, text_pos1, textSize);
            drawFilledRectangle(white, text_pos2, textSize);
            drawBlockText(text2,black,text_pos2,textSize);
            showSprite(tomato_sprite);  

            updateScreen();
            buttonAWasPressed = false;
            break;
        }
        updateScreen();
    }

    while (true) {
        bool buttonUIsPressed = wasButtonPressed(UP);
        bool buttonDIsPressed = wasButtonPressed(DOWN);
        Position sprite_position = getPosition(tomato_sprite);
        
        if (buttonUIsPressed == true && sprite_position.y == 122) {
          Position sprite_position = getPosition(tomato_sprite);
          sprite_position.y -=17;
          updatePosition(tomato_sprite, sprite_position);
        }
        if (buttonDIsPressed == true && sprite_position.y == 105) {
          Position sprite_position = getPosition(tomato_sprite);
          sprite_position.y += 17;
          updatePosition(tomato_sprite, sprite_position);  
        }  
        updateScreen();

        bool buttonAWasPressed = wasButtonPressed(A);
        if (buttonAWasPressed == true) {
            hideSprite(tomato_sprite);
            return;
        }
    }
}


int main() {
    // Add code here!
    love = 0;
    Size rectSize = {80, 53};
    Size textSize = {100, 100};
    Size fullscreen = {240, 160};
    Color grey = createColor (250, 250, 250);
    Color white = createColor(255,255,255);
    Color black = createColor(0,0,0);
    Position center = {100,80};
    Position R1 = {0,0};
    Position R2 = {80,0};
    Position R3 = {160,0};
    Position R4 = {0,53};
    Position R5 = {80,53};
    Position R6 = {160, 53};
    Position R7 = {0, 106};
    Position R8 = {80, 106};
    Position R9 = {160, 106};
    Background kitchen_background = createBackground("kitchen");
    Position bg_pos = {0,0};

    Position text_pos1 = {60, 120};

    Sound music = createSound("maintheme");

    Background burger_background = createBackground("kitchenburger");

    drawBackground (kitchen_background, bg_pos);
    

    option_textbox("hi","hi");
    drawText("Press A to Start Game",white, text_pos1);




    playSound(music, true);
    wait(0.3);

    bool Xwaspressed = false;
    while (Xwaspressed == false) {
      Xwaspressed= wasButtonPressed(A);
        if (Xwaspressed ==true) {
          drawFilledRectangle(black,R1,fullscreen);
          animateTextFast ("Feastopolis is a city that never sleeps, every night a feast of foods dancing. Back in my hometown of Tomatoville, everyone was a tomato or at least related to tomatoes: pizzas, calzones, pico de gallo, and even pasta. But here in Feastopolis, I have met food I never knew even existed. From dumplings to fried chicken, the world was a lot bigger than I had ever imagined.",white, R1,fullscreen);
        }
        updateScreen ();
      }
    Xwaspressed = false;
      while (Xwaspressed == false) {
        Xwaspressed = wasButtonPressed(A);
        if (Xwaspressed ==true) {
          drawBlockText("HEY WAKE UP",black,R5 ,textSize);
          animateTextFast	("WAKE UP",white,R5,textSize);
        }
        updateScreen ();
      }   
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
