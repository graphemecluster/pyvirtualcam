#pragma once
#include <stdio.h>
#include <Windows.h>
#include <vector>
#include "../native_shared/image_formats.h"
#include "shared.inl"
class ARGBCamera {
  private:
    uint32_t _width;
    uint32_t _height;
    uint32_t _fourcc;
    std::vector<uint8_t> _output;
    SharedImageMemory* _sender;
  public:
    ARGBCamera(uint32_t width, uint32_t height, double fps, uint32_t fourcc, std::optional<std::string> device) {
        _sender = new SharedImageMemory(0);
        _width = width;
        _height = height;
        _fourcc = libyuv::CanonicalFourCC(fourcc);
        _output.resize(argb_frame_size(width, height));
    }
    void stop() {}
    void send(const uint8_t *frame) {
        if (!_sender->SendIsReady()) return;
        uint8_t* out;
        switch (_fourcc) {
            case libyuv::FOURCC_RAW:
                out = _output.data();
                rgb_to_argb(frame, out, _width, _height);
                break;
            case libyuv::FOURCC_24BG:
                out = _output.data();
                bgr_to_argb(frame, out, _width, _height);
                break;
            case libyuv::FOURCC_J400:
                out = _output.data();
                gray_to_argb(frame, out, _width, _height);
                break;
            case libyuv::FOURCC_ARGB:
                out = const_cast<uint8_t*>(frame);
                break;
            default:
                throw std::logic_error("Not Implemented");
        }
        _sender->Send(_width, _height, _width, _width * _height * 4, SharedImageMemory::FORMAT_UINT8, SharedImageMemory::RESIZEMODE_DISABLED, SharedImageMemory::MIRRORMODE_DISABLED, 100000000, out);
    }
    std::string device() {
        return "ARGB Camera";
    }
    uint32_t native_fourcc() {
        return libyuv::FOURCC_ARGB;
    }
};