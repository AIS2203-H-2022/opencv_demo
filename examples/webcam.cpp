#include "detect_face.hpp"

#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;


void loadCascades(std::optional<CascadeClassifier> &cascade, std::optional<CascadeClassifier> &nestedCascade) {
    const std::string cascadeName("../cascades/haarcascades/haarcascade_frontalface_alt.xml");
    const std::string nestedCascadeName("../cascades/haarcascades/haarcascade_eye_tree_eyeglasses.xml");

    CascadeClassifier cascade_, nestedCascade_;
    if (!cascade_.load(cascadeName)) {
        std::cerr << "Warning: Could not load classifier cascade" << std::endl;
    } else {
        cascade = cascade_;
    }


    if (!nestedCascade_.load(nestedCascadeName)) {
        std::cerr << "Warning: Could not load classifier cascade for nested objects" << std::endl;
    } else {
        nestedCascade = nestedCascade_;
    }
}

int main() {
    try {

        VideoCapture capture(0);
        if (!capture.isOpened()) {
            std::cerr << "Unable to open camera.." << std::endl;
            return 1;
        }

        const std::string windowTitle{"Display image"};
        namedWindow(windowTitle, WINDOW_AUTOSIZE);

        std::optional<CascadeClassifier> cascade, nestedCascade;
        loadCascades(cascade, nestedCascade);

        Mat image;
        bool stop{false};
        while (!stop) {
            capture >> image;

            if (cascade) {
                detect_face(image, *cascade, nestedCascade);
            }

            imshow("Display Image", image);
            int key = waitKey(1);
            if (key == 'q') {
                stop = true;
            }
        }

    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
}