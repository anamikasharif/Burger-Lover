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
void cherrybox(char * text) {
    Color  lightpink = createColor(255, 212, 230);
    Position rectPos = {20, 100};
    Size rectSize = {200, 50};

    Size sprite_size = {16,16};
    Sprite tomato_sprite = createSprite("tomato", sprite_size);

    Position text_pos = {30, 105};
    Color black = createColor(0,0,0);
    Size textSize = {180, 45};
    while (true) {
        bool buttonAWasPressed = wasButtonPressed(A);
        if (buttonAWasPressed == true) {
            drawFilledRectangle(lightpink, rectPos, rectSize);
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
            updateScreen();
            break;
        }
      updateScreen();
    }
}
void exposition(char * text, Background background) {
  Color white = createColor(255,255,255);
  Color black = createColor(0,0,0);
  Position R1 = {0,0};
  Position R4 = {13,53};
  Size fullscreen = {240, 160};
   bool exposcreen1 = true;
    while (exposcreen1 == true) {
      bool Xwaspressed = wasButtonPressed (A);
        if (Xwaspressed ==true) {
          drawBackground(background, R1);
          animateTextFast (text, white, R4, fullscreen );
          exposcreen1 = false;
          break;
      }
      updateScreen();
    }
 }
 //need to add all meters with if statement for all based on value of love
void update_meter() {
  Size meter_sprite = {32,32};
  Position meter_pos = {160,20};
  Sprite emptymeter = createSprite("emptymeter", meter_sprite);
  Sprite meter1 = createSprite("meter1", meter_sprite);
  Sprite meter2 = createSprite("meter2", meter_sprite);
  Sprite meter3 = createSprite("meter3", meter_sprite);
  Sprite fullmeter = createSprite("fullmeter", meter_sprite);

  if (love == 0) {
    updatePosition(emptymeter, meter_pos);
    showSprite(emptymeter);
    updateScreen();
  }
  if (love > 0) {
    updatePosition(meter1, meter_pos);
    showSprite(meter1);
    updateScreen();
  }
  if (love > 3) {
    updatePosition(meter2, meter_pos);
    showSprite(meter2);
    updateScreen();
  }
  updateScreen();
}

void option_textbox(char * text1, char * text2, int option) {
    Color  lightpink = createColor(255, 212, 230);
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
            drawFilledRectangle(lightpink, rectPos, rectSize);
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
    Background skyline = createBackground("skyline");
    Background burgershack = createBackground("burgershack");
    Position bg_pos = {0,0};

    Position text_pos1 = {60, 120};

    Sound music = createSound("maintheme");
    Sound lovetheme = createSound("burgertheme");
    Sound badending = createSound("badending");
    Sound happyending = createSound("happyending");

    Background flushedburger = createBackground("kitchenburger");
    Background normalburger = createBackground("normalburger");
    Background madburger = createBackground("madburger");
    Background specialburger = createBackground("specialburger");
    Background worriedburger = createBackground("worriedburger");
    Background sadburger = createBackground("sadburger");
    Background flushedburger2 = createBackground("flushedburger2");
    Background normalburger2 = createBackground("normalburger2");
    Background partyburger = createBackground("partyburger");
    Background flushedburger3 = createBackground("flushedburger3");
    Background normalburger3 = createBackground("normalburger3");
    Background sadburger3 = createBackground("sadburger3");


    drawBackground (startscreen, bg_pos);
    playSound(music, true);
    drawText("Press A to Start Game",white, text_pos1);
    wait(0.3);
    exposition ("Feastopolis is a city that never sleeps, every night a feast of foods dancing.", skyline);
    exposition ("Back in my hometown of Tomatoville, everyone was a tomato or at least related to tomatoes.", skyline);
    exposition ("But here in Feastopolis, I have met food I never knew even existed.", skyline);
    exposition ("From dumplings to fried chicken, the world was a lot bigger than I had ever imagined.", skyline);
    exposition ("Papa always dreamed of starting his own restaurant in Feastopolis.", skyline);
    exposition ("That never happened though because he and Mama had my sister and me young.", skyline);
    exposition ("However, Papa was never sad about that. He would always say 'Cherry sweetheart, sometimes reality is a whole lot sweeter than a dream.'", skyline);
    exposition ("In a way, his dream became my dream. Maybe one day I will run a restaurant myself...", skyline);
    change_background(burgershack);

    while (true) {
        bool buttonAWasPressed = wasButtonPressed(A);
        if (buttonAWasPressed == true) {
            drawBackground (normalburger, bg_pos);
            updateScreen();
            break;
        }
        updateScreen();
       }
    update_meter();
    textbox("So you must be the new hire. Cherry, right?"); 
    option_textbox("That's me!","Yeah! Nice to meet you! And your name is?", 0 );
    textbox ("I'm Bill! I'm actually the manager here. I know BurgerShack isn't much, but it has a lot of heart.");
    option_textbox("It's a bit of a fixer upper but that's why I'm here!", "I bet so. I can already tell by the smell that the food is amazing", 0 );
    textbox ("I'm glad to hear that! Competition is really tight here especially with TastySandwhich next door.");
    textbox ("But I love this resturant and I hope you learn to love it too!");
    textbox ("Well let's not waste any more time and dive into your first day!");
    textbox ("What do you want to do first?");
    option_textbox ("Mop the floors", "Dump ketchup on Bill", 1);
    update_meter();
    textbox ("What do you want to do next?");
    option_textbox ("Take a 'bathroom' break", "Take orders", 2);
    update_meter();

    if (love <= 1) {
      change_background(madburger);
    }

    textbox ("A customer is angry about their order. What do you do?");
    option_textbox ("Apologize and redo the order", "Tell them their beard is ugly", 1);

    if (love >= 2) {
      change_background(flushedburger);
      textbox ("Congratulations on your first day at BurgerShack!");
      textbox ("I really admire your hardwork and skill with the customers.");
      textbox ("Im really glad I hired you! Lets celebrate your first day here with some drinks.");
    }
    if (love < 2) {
      change_background (worriedburger);
      textbox ("Hey, how was your first day?");
      textbox ("It seems like you were having a bit of a rough time. Thats okay, first days can be hard. ");
      change_background (sadburger);
      textbox ("I remember my first day here, I accidently set the kitchen on fire.");
      change_background (normalburger);
      textbox ("But thats unimportant... lets celebrate you surviving your first day!");
    }
    update_meter();

  stopSound(music);
  playSound(lovetheme, true);


  textbox ("So Cherry, what brings you to Feastopolis?");
  cherrybox ("Cherry: This might sound lame, but ever since I was young I dreamed about living here");
  textbox ("really why so?");
  cherrybox ("A combination of things really. The culture...the food..the atmosphere...");
  cherrybox ("um...");
  change_background (worriedburger);
  textbox ("Hey whats wrong you look sad");
  cherrybox ("oh...its nothing");
  textbox ("Are you feeling a bit homesick?");
  cherrybox ("It's the opposite actually. It's just...");
  cherrybox ("my dad would take me and my sister to Feastopolis when we were young. And I just really miss him.");
  change_background (normalburger);
  if (love >= 2) {
    textbox ("Well I bet your dad would be very proud of you. He raised a rock star.");
  }
  textbox ("Where would you and your family visit when you would come to Feastopolis?");
  option_textbox("Bobbys Burger", "Patricks Potluck", 1);
  textbox ("Really! Your dad has taste.");
  cherrybox ("Well that is enough about me.");
  cherrybox ("How about you? What brings you to Feastopolis Bill?");
  textbox ("I grew up in Bugersolvia but I came here to follow my dream of starting a world class restaurant.");
  option_textbox ("Really? You are doing a really bad job", "Wow! Really I also dreamed of starting a restaurant as well.", 2);
  cherrybox ("Actually Bill you remind me of my dad.");
  change_background (flushedburger);
  textbox ("Really?");
  option_textbox ("Yeah, you match his ambition.", "Yeah, you will never reach your dreams like him.", 1);
  if (love >= 3) {
    textbox ("Well thank you for being here at BurgerShack Cherry. I'll see you tommorow!");
    textbox ("Good night!");
  }
  if (love < 3) {
    textbox ("Um, well then. It is getting really late, so I will see you tommorrow.");
  } 

  change_background (skyline);
  cherrybox ("DAY 2");
  if (love >= 3) {
   change_background(flushedburger);
   textbox ("Hey, Cherry, can I speak with you?");
   option_textbox("Yes! Of course!", "Is there something wrong", 0);
   textbox("You have been a great employer so far. I really appreciate all your hard work");
   option_textbox("Thank you so much! You have been a wonderful boss", "I believe I deserve a promotion. I have been doing all the work.", 1);
   change_background(normalburger);
   textbox("It has been a rough time getting this restaurant started");
   textbox ("I didnt really have much support from my family. I didnt have much money either");
   textbox ("but I dont know despite all of that. I just had a dream.");
   textbox("A dream where all different foods come together and enjoy my cuisine");
   textbox ("I know its kinda stupid. But my best memories as a kid were the dinners with my family.");
   textbox ("It was a short moment of warmth in a life that was so chaotic and cold...");
   textbox ("It made me feel at home...");
   textbox ("And I just want to bring that warm feeling to foods all around Feastopolis");
   change_background(worriedburger);
   textbox("um...");
   cherrybox ("Whats wrong Bill");
   textbox ("Sorry talking about my dream is a little painful.");
   cherrybox ("Why?");
   change_background (sadburger);
   textbox ("My family wasnt the best if Im being honest");
   textbox ("It was rough growing up. It was like I was stuck…");
   textbox ("I felt so small, stupid and powerless...");
   textbox ("so I left. And I wanted to become my own burger. Pursue my dream");
   change_background (specialburger);
   textbox ("In a way it was freeing, but in other ways it felt all those dark thoughts were following me like ghosts.");
   option_textbox("Sounds rough, buddy", "I am so sorry to hear about this", 2);
   change_background (normalburger);
   textbox("Sorry that was a lot. I know you came here for a similar reason");
   option_textbox("Um sorry I cant relate.", "Not really but food reminds me of home too.", 2);
   option_textbox ("Your dream is really beautiful Bill, I believe it can come true.", "Hey Im always here to help.", 1);
   change_background(flushedburger);
   textbox("Anyways, keep up the good work.");
   option_textbox("Well, I better work hard if we can both pursue our dreams", "I need to earn some more cash anyway", 1);
}
 




    

  wait (2);
  drawFilledRectangle (black, R1, fullscreen);
  if (love > 5) {
    stopSound(lovetheme);
    playSound(happyending, true);
    drawFilledRectangle (green, R5, rectSize);
    drawText ("good ending", white, textcenter);

  }
  if (love <= 5) {
    stopSound(lovetheme);
    playSound(badending, true);
    drawFilledRectangle (red, R5, rectSize);
    drawText ("bad ending", black, textcenter);
  }
  updateScreen ();
  }
