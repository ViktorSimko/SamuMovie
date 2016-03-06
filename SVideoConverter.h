#ifndef SVC_H
#define SVC_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>
#include <exception>
#include <iomanip>
#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QPushButton>
#include <QGridLayout>

class SVideoConverter : public QDialog
{
	Q_OBJECT
public:
	// The constructor for the video converter 
	// takes the name os the video file, 
	// the width and height of Samu's lattice in cells
	SVideoConverter(size_t w_w, size_t w_h);

	// For storing the bool data of the frames for Samu
	std::vector< std::vector< std::vector<bool> > > m_lattices;

public slots:
	void Convert();

private:
	// The name of the video file
	QString m_file_name;

	// The video capture for the movie
	cv::VideoCapture m_cap;

	// This method is called for every frame of the movie
	void ConvertFrameToGS(cv::Mat& frame);

	// The width and height of Samu's grid in cells
	size_t m_ww, m_wh;

	// The width and height of the actual movie in pixels
	size_t m_mw, m_mh;

	// The width and height of Samu's cells in the movie
	size_t m_cw, m_ch;
	
	QPushButton *b_convert;
	QPushButton *b_launch_samu;
};

#endif