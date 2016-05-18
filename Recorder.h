#ifndef RECORDER_H
#define RECORDER_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <exception>
#include <QtCore>
#include <QtWidgets>
#include <opencv2/core/core.hpp>

class Recorder: public QDialog {
    Q_OBJECT
public:
    Recorder(const QString& fileNameToSave);
    ~Recorder();

    QString fileName;

public slots:
    void record();

private:
    QPushButton *recordButton;
    QPushButton *okButton;
};

#endif


