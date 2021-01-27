#pragma once

#include <stdint.h>

bool virtual_output_start(int width, int height, double fps, int delay);
void virtual_output_stop();
void virtual_video(uint8_t **data);
bool virtual_output_is_running();