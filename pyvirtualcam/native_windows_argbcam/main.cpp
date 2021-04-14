#include <stdexcept>
#include <optional>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include "argb_camera.h"

namespace py = pybind11;

class CameraARGB {
  private:
    ARGBCamera argb_camera;

  public:
    CameraARGB(uint32_t width, uint32_t height, double fps, uint32_t fourcc, std::optional<std::string> device_) : argb_camera {width, height, fps, fourcc, device_} {
    }

    void close() {
        argb_camera.stop();
    }

    std::string device() {
        return argb_camera.device();
    }

    uint32_t native_fourcc() {
        return argb_camera.native_fourcc();
    }

    void send(py::array_t<uint8_t, py::array::c_style> frame) {
        py::buffer_info buf = frame.request();
        argb_camera.send(static_cast<uint8_t*>(buf.ptr));
    }
};

PYBIND11_MODULE(_native_windows_argbcam, n) {
    py::class_<CameraARGB>(n, "CameraARGB")
        .def(py::init<uint32_t, uint32_t, double, uint32_t, std::optional<std::string>>(),
             py::kw_only(),
             py::arg("width"), py::arg("height"), py::arg("fps"),
             py::arg("fourcc"), py::arg("device"))
        .def("close", &CameraARGB::close)
        .def("send", &CameraARGB::send)
        .def("device", &CameraARGB::device)
        .def("native_fourcc", &CameraARGB::native_fourcc);
}