#include "background.h"
#include "background_data.h"

// This is cursed. I apologize

#define NUM_BACKGROUNDS 9

static Background backgrounds[NUM_BACKGROUNDS];
static int curr_image = 0;

static void addImage(u32 width, u32 height, char *image_name) {
    Size size = {width, height};
    backgrounds[curr_image].size = size;
    backgrounds[curr_image].image_name = image_name;

    curr_image++;
}

static void addImageData(const u16 *background_data) {
    backgrounds[curr_image].background_data = background_data;
    curr_image++;
}

void populateBackgrounds() {
     addImage(STARTSCREEN_WIDTH, STARTSCREEN_HEIGHT, "STARTSCREEN");
  addImage(NORMALBURGER_WIDTH, NORMALBURGER_HEIGHT, "NORMALBURGER");
  addImage(SKYLINE_WIDTH, SKYLINE_HEIGHT, "SKYLINE");
  addImage(KITCHEN_WIDTH, KITCHEN_HEIGHT, "KITCHEN");
  addImage(SPECIALBURGER_WIDTH, SPECIALBURGER_HEIGHT, "SPECIALBURGER");
  addImage(SADBURGER_WIDTH, SADBURGER_HEIGHT, "SADBURGER");
  addImage(WORRIEDBURGER_WIDTH, WORRIEDBURGER_HEIGHT, "WORRIEDBURGER");
  addImage(MADBURGER_WIDTH, MADBURGER_HEIGHT, "MADBURGER");
  addImage(KITCHENBURGER_WIDTH, KITCHENBURGER_HEIGHT, "KITCHENBURGER");

    curr_image = 0;
     addImageData(startscreen);
  addImageData(normalburger);
  addImageData(skyline);
  addImageData(kitchen);
  addImageData(specialburger);
  addImageData(sadburger);
  addImageData(worriedburger);
  addImageData(madburger);
  addImageData(kitchenburger);

}

Background getBackground(char *image_name) {
    int len = strlen(image_name);
    char upper_img_name[len + 1];
    for (int i = 0; i < len; i++) {
        upper_img_name[i] = toupper(image_name[i]);
    }
    upper_img_name[len] = '\0';
    for (int i = 0; i < NUM_BACKGROUNDS; i++) {
        if (!strcmp(backgrounds[i].image_name, upper_img_name)) {
            return backgrounds[i];
        }
    }
    //TODO: exit angrily
    return backgrounds[1];
}