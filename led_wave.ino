#include "Adafruit_NeoPixel.h"

#define PIN 6
#define NUM_LEDS 60
#define BRIGHTNESS 52

#define BASE_COLOR 64
#define COLOR_OFFSET 8

#define DELAY 100

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  uint32_t middlePixel = NUM_LEDS / 2;
  uint32_t startingColor = strip.Color(BASE_COLOR, BASE_COLOR, BASE_COLOR);

  strip.setPixelColor(middlePixel, startingColor);
  strip.show();

  expandColors(middlePixel);
  shrinkColors();

}


void expandColors(uint32_t middlePixel ) {
  uint32_t i = 0;

  while (i <= middlePixel) {
    uint32_t prev = middlePixel - i;
    uint32_t next = middlePixel + i;

    uint32_t color = strip.Color(BASE_COLOR + i * COLOR_OFFSET, BASE_COLOR, BASE_COLOR);

    strip.setPixelColor(prev, color);
    strip.setPixelColor(next, color);

    strip.show();

    delay(DELAY);
    i++;
  }

  //strip.clear();
}

void shrinkColors() {
  for (int i = 0; i <= NUM_LEDS / 2; i++) {
    uint32_t empty = strip.Color(0, 0, 0);

    strip.setPixelColor(i, empty);
    strip.setPixelColor(strip.numPixels() - 1 - i, empty);

    strip.show();

    delay(DELAY);
  }
}
