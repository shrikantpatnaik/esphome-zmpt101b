#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/voltage_sampler/voltage_sampler.h"

namespace esphome {
namespace zmpt101b {

#define ADC_SCALE 32677
#define VREF 5

class ZMPT101BSensor : public sensor::Sensor, public Component {
 public:
  void set_adc_sensor(voltage_sampler::VoltageSampler *sensor) { adc_sensor_ = sensor; }
  void set_frequency(uint16_t freq) { period_ = 1000000UL / freq; }
  void set_sensitivity(float sens) { sensitivity_ = sens; }
  void set_loop_count(float sens) { loop_count_ = sens; }

  void setup() override {}
  void loop() override;

 protected:
  voltage_sampler::VoltageSampler *adc_sensor_;
  uint32_t period_;
  float sensitivity_;
  int loop_count_;

  int getZeroPoint_();
};

}  // namespace zmpt101b
}  // namespace esphome
