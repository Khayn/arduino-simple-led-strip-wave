#include "Adafruit_NeoPixel.h"

#define PIN 6
#define NUM_LEDS 60
#define BRIGHTNESS 52

#define HALF_POINT NUM_LEDS/2

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
  uint32_t startingColor = strip.Color(BASE_COLOR, BASE_COLOR, BASE_COLOR);

  strip.setPixelColor(HALF_POINT, startingColor);
  strip.show();

  expandColors();
  shrinkColors();

}


void expandColors() {
  uint32_t currentPixel = 0;

  while (currentPixel < HALF_POINT) {
    uint32_t prev = HALF_POINT - currentPixel;
    uint32_t next = HALF_POINT + currentPixel;

    uint32_t color = strip.Color(BASE_COLOR + (currentPixel * COLOR_OFFSET), BASE_COLOR, BASE_COLOR);

    strip.setPixelColor(prev, color);
    strip.setPixelColor(next, color);

    strip.show();

    delay(DELAY);
    currentPixel++;
  }

}

void shrinkColors() {
  uint32_t currentPixel = 0;

  while (currentPixel < HALF_POINT) {
    uint32_t empty = strip.Color(0, 0, 0);

    strip.setPixelColor(currentPixel, empty);
    strip.setPixelColor(strip.numPixels() - 1 - currentPixel, empty);

    strip.show();

    delay(DELAY);
    currentPixel++;
  }

}
