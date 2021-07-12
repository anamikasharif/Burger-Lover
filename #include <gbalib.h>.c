#include <gbalib.h>
int love;
void textbox(char * text) {
    Color  lightblue = createColor(204, 255, 255);
    Position rectPos = {20, 100};
    Size rectSize = {200, 50};

    Position text_pos = {30, 105};
    Color black = createColor(0,0,0);
    Size textSize = {180, 45};
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
void change_background(Background background) {
    Position bg_pos = {0,0};
    while (true) {
        bool buttonAWasPressed = wasButtonPressed(A);
        if (buttonAWasPressed == true) {
            drawBackground(background, bg_pos);
            break;
        }
      updateScreen();
    }
}
void exposition(char * text) {
    Color white = createColor(255,255,255);
    Color black = createColor(0,0,0);
    Position R1 = {0,0};
    Position R4 = {0,53};
    Size fullscreen = {240, 160};
   bool exposcreen1 = true;
    while (exposcreen1 == true) {
      bool Xwaspressed = wasButtonPressed (A);
        if (Xwaspressed ==true) {
          drawFilledRectangle(black,R1,fullscreen);
          animateTextFast (text, white, R4, fullscreen );
          exposcreen1 = false;
          break;
      }
      updateScreen();
    }
 }

void option_textbox(char * text1, char * text2, int option) {
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
            if (sprite_position.y == 105 && option == 1) {
              love += 1;
            } 
            if (sprite_position.y == 122 && option == 2) {
              love += 1;
            }
          return;
        }
    }
}


int main() {
    love = 0;
    Size rectSize = {80, 53};
    Size textSize = {100, 100};
    Size fullscreen = {240, 160};
    Color red = createColor(255, 0, 0);
    Color green = createColor(0, 255, 0);
    Color blue = createColor(0,0, 255);
    Color torq = createColor (0, 250, 255);
    Color grey = createColor (250, 250, 250);
    Color white = createColor(255,255,255);
    Color black = createColor(0,0,0);
    Position center = {100,80};
    Position textcenter = {90, 75};
    Position R1 = {0,0};
    Position R2 = {80,0};
    Position R3 = {160,0};
    Position R4 = {0,53};
    Position R5 = {80,53};
    Position R6 = {160, 53};
    Position R7 = {0, 106};
    Position R8 = {80, 106};
    Position R9 = {160, 106};

    Background startscreen = createBackground("startscreen");
    Background kitchen_background = createBackground("kitchen");
    Position bg_pos = {0,0};

    Position text_pos1 = {60, 120};

    Sound music = createSound("maintheme");

    Background burger_background = createBackground("kitchenburger");

    drawBackground (startscreen, bg_pos);
    playSound(music, true);
    drawText("Press A to Start Game",white, text_pos1);


    wait(0.3);

    exposition ("my froggy");
    exposition ("hiii");

    while (true) {
        bool buttonAWasPressed = wasButtonPressed(A);
        if (buttonAWasPressed == true) {
            drawBackground (burger_background, bg_pos);
            updateScreen();
            break;
        }
        updateScreen();
       }
    
    textbox("So you must be the new hire. Cherry, right?"); 
    option_textbox("That's me!","Yeah! Nice to meet you! And your name is?", 0 );
    textbox ("I'm Bill! I'm actually the manager here. I know BurgerTown isn't much, but it has a lot of heart.");
    option_textbox("It's a bit of a fixer upper but that's why I'm here!", "I bet so. I can already tell by the smell that the food is amazing", 0 );
    textbox ("I'm glad to hear that! Competition is really tight here especially with De Bon Gout next door.");
    textbox ("But I love this resturant and I hope you learn to love it too!");
    textbox ("Well let's not waste any more time and dive into your first day!");
    textbox ("What do you want to do first?");
    option_textbox ("Mop the floors", "Dump ketchup on Bill", 1);
    textbox ("What do you want to do next?");
    option_textbox ( "Take a 'bathroom' break", "Take orders", 2);
    textbox ("A customer is angry about their order. What do you do?");
    option_textbox ("Apologize and redo the order", "Tell them their beard is ugly", 1);

  drawFilledRectangle (black, R1, fullscreen);
  if (love > 2) {
    drawFilledRectangle (green, R5, rectSize);
    drawText ("good ending", white, textcenter);
  }
  if (love <= 2) {
    drawFilledRectangle (red, R5, rectSize);
    drawText ("bad ending", black, textcenter);
  }
  updateScreen ();
  }
  
