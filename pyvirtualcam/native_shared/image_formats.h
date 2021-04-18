#pragma once

#include <libyuv.h>

// copy
static void gray_to_argb(const uint8_t *gray, uint8_t* argb, int32_t width, int32_t height) {
    libyuv::J400ToARGB(
        gray, width,
        argb, width * 4,
        width, height);
}

// copy
static void rgb_to_argb(const uint8_t *rgb, uint8_t* argb, int32_t width, int32_t height) {
    libyuv::RAWToARGB(
        rgb, width * 3,
        argb, width * 4,
        width, height);
}

// copy
static void argb_to_argb(const uint8_t *src, uint8_t* dist, int32_t width, int32_t height) {
    libyuv::ARGBCopy(
        src, width * 4,
        dist, width * 4,
        width, height);
}

// horizontal and vertical subsampling and yuv conversion
static void rgb_to_i420(const uint8_t *rgb, uint8_t* i420, int32_t width, int32_t height) {
    int32_t half_width = width / 2;
    int32_t half_height = height / 2;

    libyuv::RAWToI420(
        rgb, width * 3,
        i420, width,
        i420 + width * height, half_width,
        i420 + width * height + half_width * half_height, half_width,
        width, height);
}

// copy
static void bgr_to_argb(const uint8_t *bgr, uint8_t* argb, int32_t width, int32_t height) {
    libyuv::RGB24ToARGB(
        bgr, width * 3,
        argb, width * 4,
        width, height);
}

// horizontal and vertical subsampling and yuv conversion
static void bgr_to_i420(const uint8_t *bgr, uint8_t* i420, int32_t width, int32_t height) {
    int32_t half_width = width / 2;
    int32_t half_height = height / 2;

    libyuv::RGB24ToI420(
        bgr, width * 3,
        i420, width,
        i420 + width * height, half_width,
        i420 + width * height + half_width * half_height, half_width,
        width, height);
}

// horizontal and vertical subsampling and yuv conversion
static void argb_to_nv12(const uint8_t *argb, uint8_t* nv12, int32_t width, int32_t height) {
    libyuv::ARGBToNV12(
        argb, width * 4,
        nv12, width,
        nv12 + width * height, width,
        width, height);
}

// horizontal subsampling and yuv conversion
static void argb_to_uyvy(const uint8_t *argb, uint8_t* uyvy, int32_t width, int32_t height) {
    libyuv::ARGBToUYVY(
        argb, width * 4,
        uyvy, width * 2,
        width, height);
}

// copy
static void i420_to_nv12(const uint8_t *i420, uint8_t* nv12, int32_t width, int32_t height) {
    int32_t half_width = width / 2;
    int32_t half_height = height / 2;

    libyuv::I420ToNV12(
        i420, width,
        i420 + width * height, half_width,
        i420 + width * height + half_width * half_height, half_width,
        nv12, width,
        nv12 + width * height, width,
        width, height);
}

// copy
static void i420_to_argb(const uint8_t *i420, uint8_t* argb, int32_t width, int32_t height) {
    int32_t half_width = width / 2;
    int32_t half_height = height / 2;

    libyuv::I420ToARGB(
        i420, width,
        i420 + width * height, half_width,
        i420 + width * height + half_width * half_height, half_width,
        argb, width * 4,
        width, height);
}

// copy
static void nv12_to_i420(const uint8_t *nv12, uint8_t* i420, int32_t width, int32_t height) {
    int32_t half_width = width / 2;
    int32_t half_height = height / 2;

    libyuv::NV12ToI420(
        nv12, width,
        nv12 + width * height, width,
        i420, width,
        i420 + width * height, half_width,
        i420 + width * height + half_width * half_height, half_width,
        width, height);
}

// copy
static void nv12_to_argb(const uint8_t *nv12, uint8_t* argb, int32_t width, int32_t height) {
    libyuv::NV12ToARGB(
        nv12, width,
        nv12 + width * height, width,
        argb, width * 4,
        width, height);
}

// vertical upsampling
static void i420_to_uyvy(const uint8_t *i420, uint8_t* uyvy, int32_t width, int32_t height) {
    int32_t half_width = width / 2;
    int32_t half_height = height / 2;

    libyuv::I420ToUYVY(
        i420, width,
        i420 + width * height, half_width,
        i420 + width * height + half_width * half_height, half_width,
        uyvy, width * 2,
        width, height);
}

// vertical subsampling
static void yuyv_to_nv12(const uint8_t *yuyv, uint8_t* nv12, int32_t width, int32_t height) {
    libyuv::YUY2ToNV12(
        yuyv, width * 2,
        nv12, width,
        nv12 + width * height, width,
        width, height);
}

// vertical subsampling
static void yuyv_to_i420(const uint8_t *yuyv, uint8_t* i420, int32_t width, int32_t height) {
    int32_t half_width = width / 2;
    int32_t half_height = height / 2;

    libyuv::YUY2ToI420(
        yuyv, width * 2,
        i420, width,
        i420 + width * height, half_width,
        i420 + width * height + half_width * half_height, half_width,
        width, height);
}

// copy
static void yuyv_to_i422(const uint8_t *yuyv, uint8_t* i422, int32_t width, int32_t height) {
    int32_t half_width = width / 2;

    libyuv::YUY2ToI422(
        yuyv, width * 2,
        i422, width,
        i422 + width * height, half_width,
        i422 + width * height + half_width * height, half_width,
        width, height);
}

// copy
static void yuyv_to_argb(const uint8_t *yuyv, uint8_t* argb, int32_t width, int32_t height) {
    libyuv::YUY2ToARGB(
        yuyv, width * 2,
        argb, width * 4,
        width, height);
}

// vertical subsampling
static void uyvy_to_nv12(const uint8_t *uyvy, uint8_t* nv12, int32_t width, int32_t height) {
    libyuv::UYVYToNV12(
        uyvy, width * 2,
        nv12, width,
        nv12 + width * height, width,
        width, height);
}

// copy
static void i422_to_uyvy(const uint8_t *i422, uint8_t* uyvy, int32_t width, int32_t height) {
    int32_t half_width = width / 2;

    libyuv::I422ToUYVY(
        i422, width,
        i422 + width * height, half_width,
        i422 + width * height + half_width * height, half_width,
        uyvy, width * 2,
        width, height);
}

// copy
static void uyvy_to_argb(const uint8_t *uyvy, uint8_t* argb, int32_t width, int32_t height) {
    libyuv::UYVYToARGB(
        uyvy, width * 2,
        argb, width * 4,
        width, height);
}

static int32_t argb_frame_size(int32_t width, int32_t height) {
    return width * height * 4;
}

static int32_t gray_frame_size(int32_t width, int32_t height) {
    return width * height;
}

static int32_t i420_frame_size(int32_t width, int32_t height) {
    return width * height * 3 / 2;
}

static int32_t i422_frame_size(int32_t width, int32_t height) {
    return width * height * 2;
}

#define nv12_frame_size i420_frame_size
#define uyvy_frame_size i422_frame_size
#define yuyv_frame_size i422_frame_size