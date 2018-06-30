#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(77, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  strip.begin();
  strip.show(); 
} 

void loop() {
  simpleWave(0.03, 20, 20);
}
void simpleWave(float rate, int cycles, int wait) {
  float pos = 0.0;
  for (int x = 0; x < (strip.numPixels()*cycles); x++)
  {
    pos = pos + rate;
    for (int i = 0; i < strip.numPixels(); i++) {
      float sinWave = sin(i + pos) * 127 + 128;
      float cosWave = cos(i + pos) * 127 + 128;
      if (i <= 25) {
        strip.setPixelColor(i,0,(int)cosWave/2,(int)sinWave);
      } else if (i <= 51) {
        strip.setPixelColor(i,(int)cosWave/2,0,(int)sinWave);
      } else if(i <= 60) { 
        strip.setPixelColor(i, (int)cosWSave, (int)sinWave, (int)cosWave / 2);
    } else { 
      strip.setPixelColor(i, 255, 255, 255); 
    }
    strip.show();
    delay(wait);
  }
}
